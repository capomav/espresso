/*
 * Copyright (C) 2010-2019 The ESPResSo project
 * Copyright (C) 2002,2003,2004,2005,2006,2007,2008,2009,2010
 *   Max-Planck-Institute for Polymer Research, Theory Group
 *
 * This file is part of ESPResSo.
 *
 * ESPResSo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ESPResSo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/** \file
 *  Implementation of \ref thermostat.hpp.
 */
#include "thermostat.hpp"
#include "bonded_interactions/thermalized_bond.hpp"
#include "communication.hpp"
#include "dpd.hpp"
#include "grid_based_algorithms/lb_interface.hpp"
#include "npt.hpp"

#include "utils/u32_to_u64.hpp"
#include <boost/mpi.hpp>

#include <fstream>
#include <iostream>
#include <unistd.h>

int thermo_switch = THERMO_OFF;
double temperature = 0.0;
bool thermo_virtual = true;

using Thermostat::GammaType;

namespace {
/** @name Langevin parameters sentinels.
 *  These functions return the sentinel value for the Langevin
 *  parameters, indicating that they have not been set yet.
 */
/*@{*/
constexpr double sentinel(double) { return -1.0; }
Utils::Vector3d sentinel(Utils::Vector3d) { return {-1.0, -1.0, -1.0}; }
constexpr double set_nan(double) { return NAN; }
Utils::Vector3d set_nan(Utils::Vector3d) { return {NAN, NAN, NAN}; }
/*@}*/
} // namespace

GammaType langevin_gamma = sentinel(GammaType{});
GammaType langevin_gamma_rotation = sentinel(GammaType{});
GammaType langevin_pref1;
GammaType langevin_pref2;
GammaType langevin_pref2_rotation;
// Brownian position random walk standard deviation
GammaType brown_sigma_pos_inv = sentinel(GammaType{});
GammaType brown_sigma_pos_rotation_inv = sentinel(GammaType{});
GammaType brown_gammatype_nan = set_nan(GammaType{});
double brown_sigma_vel;
double brown_sigma_vel_rotation;

/* NPT ISOTROPIC THERMOSTAT */
double nptiso_gamma0 = 0.0;
double nptiso_gammav = 0.0;

/** @name Langevin buffers
 *  Buffers for the workaround for the correlated random values which cool the
 *  system, and require a magical heat up whenever reentering the integrator.
 */
/*@{*/
static GammaType langevin_pref2_buffer;
static GammaType langevin_pref2_rotation_buffer;
/*@}*/

#ifdef NPT
double nptiso_pref1;
double nptiso_pref2;
double nptiso_pref3;
double nptiso_pref4;
#endif

std::unique_ptr<Utils::Counter<uint64_t>> langevin_rng_counter;

void mpi_bcast_langevin_rng_counter_slave(const uint64_t counter) {
  langevin_rng_counter = std::make_unique<Utils::Counter<uint64_t>>(counter);
}

REGISTER_CALLBACK(mpi_bcast_langevin_rng_counter_slave)

void mpi_bcast_langevin_rng_counter(const uint64_t counter) {
  mpi_call(mpi_bcast_langevin_rng_counter_slave, counter);
}

void langevin_rng_counter_increment() {
  if (thermo_switch & (THERMO_LANGEVIN | THERMO_BROWNIAN))
    langevin_rng_counter->increment();
}

bool langevin_is_seed_required() {
  /* Seed is required if rng is not initialized */
  return langevin_rng_counter == nullptr;
}

void langevin_set_rng_state(const uint64_t counter) {
  mpi_bcast_langevin_rng_counter(counter);
  langevin_rng_counter = std::make_unique<Utils::Counter<uint64_t>>(counter);
}

uint64_t langevin_get_rng_state() { return langevin_rng_counter->value(); }

void thermo_init_langevin() {
  langevin_pref1 = -langevin_gamma;
  langevin_pref2 = sqrt(24.0 * temperature / time_step * langevin_gamma);

  /* If gamma_rotation is not set explicitly, use the linear one. */
  if (langevin_gamma_rotation < GammaType{}) {
    langevin_gamma_rotation = langevin_gamma;
  }

  langevin_pref2_rotation =
      sqrt(24.0 * temperature * langevin_gamma_rotation / time_step);
}

#ifdef NPT
void thermo_init_npt_isotropic() {
  if (nptiso.piston != 0.0) {
    nptiso_pref1 = -nptiso_gamma0 * 0.5 * time_step;

    nptiso_pref2 = sqrt(12.0 * temperature * nptiso_gamma0 * time_step);
    nptiso_pref3 = -nptiso_gammav * (1.0 / nptiso.piston) * 0.5 * time_step;
    nptiso_pref4 = sqrt(12.0 * temperature * nptiso_gammav * time_step);
  } else {
    thermo_switch = (thermo_switch ^ THERMO_NPT_ISO);
  }
}
#endif

/** Brownian thermostat initializer.
 *
 *  Default particle mass is assumed to be unitary in these global parameters.
 */
void thermo_init_brownian() {
  /** The heat velocity dispersion corresponds to the Gaussian noise only,
   *  which is only valid for the BD. Just a square root of kT, see (10.2.17)
   *  and comments in 2 paragraphs afterwards, @cite Pottier2010.
   */
  // Heat velocity dispersion:
  brown_sigma_vel = sqrt(temperature);
  /** The random walk position dispersion is defined by the second eq. (14.38)
   *  of @cite Schlick2010. Its time interval factor will be added in the
   *  Brownian Dynamics functions. Its square root is the standard deviation.
   */
  // A multiplicative inverse of the position standard deviation:
  if (temperature > 0.0) {
    brown_sigma_pos_inv = sqrt(langevin_gamma / (2.0 * temperature));
  } else {
    brown_sigma_pos_inv =
        brown_gammatype_nan; // just an indication of the infinity
  }
#ifdef ROTATION
  /** Note: the BD thermostat assigns the langevin viscous parameters as well.
   *  They correspond to the friction tensor Z from the eq. (14.31) of
   *  @cite Schlick2010.
   */
  /* If gamma_rotation is not set explicitly,
     we use the translational one. */
  if (langevin_gamma_rotation < GammaType{}) {
    langevin_gamma_rotation = langevin_gamma;
  }
  brown_sigma_vel_rotation = sqrt(temperature);
  // A multiplicative inverse of the position rotation standard deviation:
  if (temperature > 0.0) {
    brown_sigma_pos_rotation_inv = sqrt(langevin_gamma / (2.0 * temperature));
  } else {
    brown_sigma_pos_rotation_inv =
        brown_gammatype_nan; // just an indication of the infinity
  }
#endif // ROTATION
}

void thermo_init() {
  // Init thermalized bond despite of thermostat
  if (n_thermalized_bonds) {
    thermalized_bond_init();
  }
  if (thermo_switch == THERMO_OFF) {
    return;
  }
  if (thermo_switch & THERMO_LANGEVIN)
    thermo_init_langevin();
#ifdef DPD
  if (thermo_switch & THERMO_DPD)
    dpd_init();
#endif
#ifdef NPT
  if (thermo_switch & THERMO_NPT_ISO)
    thermo_init_npt_isotropic();
#endif
  if (thermo_switch & THERMO_BROWNIAN)
    thermo_init_brownian();
}

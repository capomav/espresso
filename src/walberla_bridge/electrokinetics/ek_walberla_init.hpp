/*
 * Copyright (C) 2022 The ESPResSo project
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

#ifndef ESPRESSO_SRC_WALBERLA_BRIDGE_ELECTROKINETICS_EK_WALBERLA_INIT_HPP
#define ESPRESSO_SRC_WALBERLA_BRIDGE_ELECTROKINETICS_EK_WALBERLA_INIT_HPP

#include "EKinWalberlaBase.hpp"

#include "LatticeWalberla.hpp"

std::shared_ptr<EKinWalberlaBase>
new_ek_walberla(std::shared_ptr<LatticeWalberla> const &lattice,
                double diffusion, double kT, double valency,
                Utils::Vector3d ext_efield, double density, bool advection,
                bool friction_coupling, bool single_precision);

#endif // ESPRESSO_SRC_WALBERLA_BRIDGE_ELECTROKINETICS_EK_WALBERLA_INIT_HPP

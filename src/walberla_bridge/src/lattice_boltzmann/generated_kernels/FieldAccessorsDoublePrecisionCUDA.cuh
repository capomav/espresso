/*
 * Copyright (C) 2023-2024 The ESPResSo project
 * Copyright (C) 2020 The waLBerla project
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

// kernel generated with pystencils v1.2, lbmpy v1.2,
// lbmpy_walberla/pystencils_walberla from waLBerla commit
// 0c8b4b926c6979288fd8a6846d02ec0870e1fe41

/**
 * @file
 * Lattice field accessors.
 * Adapted from the waLBerla source file
 * https://i10git.cs.fau.de/walberla/walberla/-/blob/a16141524c58ab88386e2a0f8fdd7c63c5edd704/python/lbmpy_walberla/templates/LatticeModel.tmpl.h
 */

#pragma once

#include <core/DataTypes.h>
#include <core/cell/Cell.h>
#include <core/cell/CellInterval.h>
#include <core/math/Matrix3.h>
#include <core/math/Vector3.h>

#include <gpu/GPUField.h>

#include <array>
#include <tuple>
#include <vector>

#ifdef WALBERLA_CXX_COMPILER_IS_GNU
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifdef WALBERLA_CXX_COMPILER_IS_CLANG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-parameter"
#endif

namespace walberla {
namespace lbm {
namespace accessor {

namespace Population {
/** @brief Get populations from a single cell. */
std::array<double, 19u> get(gpu::GPUField<double> const *pdf_field,
                            Cell const &cell);
/** @brief Set populations on a single cell. */
void set(gpu::GPUField<double> *pdf_field, std::array<double, 19u> const &pop,
         Cell const &cell);
/** @brief Initialize all cells with the same value. */
void initialize(gpu::GPUField<double> *pdf_field,
                std::array<double, 19u> const &pop);
/** @brief Get populations from a cell interval. */
std::vector<double> get(gpu::GPUField<double> const *pdf_field,
                        CellInterval const &ci);
/** @brief Set populations on a cell interval. */
void set(gpu::GPUField<double> *pdf_field, std::vector<double> const &values,
         CellInterval const &ci);
} // namespace Population

namespace Vector {
/** @brief Get value from a single cell. */
Vector3<double> get(gpu::GPUField<double> const *field, Cell const &cell);
/** @brief Set value on a single cell. */
void set(gpu::GPUField<double> *field, Vector3<double> const &vec,
         Cell const &cell);
/** @brief Add value to a single cell. */
void add(gpu::GPUField<double> *field, Vector3<double> const &vec,
         Cell const &cell);
/** @brief Initialize all cells with the same value. */
void initialize(gpu::GPUField<double> *field, Vector3<double> const &vec);
/** @brief Add value to all cells. */
void add_to_all(gpu::GPUField<double> *field, Vector3<double> const &vec);
/** @brief Get values from a cell interval. */
std::vector<double> get(gpu::GPUField<double> const *vec_field,
                        CellInterval const &ci);
/** @brief Set values on a cell interval. */
void set(gpu::GPUField<double> *vec_field, std::vector<double> const &values,
         CellInterval const &ci);

} // namespace Vector

namespace Interpolation {
std::vector<double> get(gpu::GPUField<double> const *vec_field,
                        std::vector<double> const &pos, uint gl);
void set(gpu::GPUField<double> const *vec_field, std::vector<double> const &pos,
         std::vector<double> const &forces, uint gl);
} // namespace Interpolation

namespace Density {
double get(gpu::GPUField<double> const *pdf_field, Cell const &cell);
void set(gpu::GPUField<double> *pdf_field, double const rho, Cell const &cell);
std::vector<double> get(gpu::GPUField<double> const *pdf_field,
                        CellInterval const &ci);
void set(gpu::GPUField<double> *pdf_field, std::vector<double> const &values,
         CellInterval const &ci);
} // namespace Density

namespace Velocity {
void set(gpu::GPUField<double> *pdf_field, gpu::GPUField<double> *force_field,
         Vector3<double> const &u, Cell const &cell);
} // namespace Velocity

namespace DensityAndVelocity {
std::tuple<double, Vector3<double>>
get(gpu::GPUField<double> const *pdf_field,
    gpu::GPUField<double> const *force_field, Cell const &cell);
void set(gpu::GPUField<double> *pdf_field, gpu::GPUField<double> *force_field,
         Vector3<double> const &u, double const rho, Cell const &cell);
} // namespace DensityAndVelocity

namespace DensityAndMomentumDensity {
std::tuple<double, Vector3<double>>
get(gpu::GPUField<double> const *pdf_field,
    gpu::GPUField<double> const *force_field, Cell const &cell);
} // namespace DensityAndMomentumDensity

namespace MomentumDensity {
Vector3<double> reduce(gpu::GPUField<double> const *pdf_field,
                       gpu::GPUField<double> const *force_field);
} // namespace MomentumDensity

namespace PressureTensor {
Matrix3<double> get(gpu::GPUField<double> const *pdf_field, Cell const &cell);
} // namespace PressureTensor

} // namespace accessor
} // namespace lbm
} // namespace walberla

#ifdef WALBERLA_CXX_COMPILER_IS_GNU
#pragma GCC diagnostic pop
#endif

#ifdef WALBERLA_CXX_COMPILER_IS_CLANG
#pragma clang diagnostic pop
#endif

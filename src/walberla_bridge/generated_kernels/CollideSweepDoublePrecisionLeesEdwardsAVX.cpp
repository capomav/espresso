// kernel generated with pystencils v0.4.3+4.g30da657, lbmpy v0.4.3+2.g0e17e61,
// lbmpy_walberla/pystencils_walberla from commit
// 88f85eb7a979f81d68e76009811aeed53ec3014e

//======================================================================================================================
//
//  This file is part of waLBerla. waLBerla is free software: you can
//  redistribute it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, either version 3 of
//  the License, or (at your option) any later version.
//
//  waLBerla is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//  for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with waLBerla (see COPYING.txt). If not, see <http://www.gnu.org/licenses/>.
//
//! \\file CollideSweepDoublePrecisionLeesEdwardsAVX.cpp
//! \\ingroup lbm
//! \\author lbmpy
//======================================================================================================================

#include <cmath>

#include "CollideSweepDoublePrecisionLeesEdwardsAVX.h"
#include "core/DataTypes.h"
#include "core/Macros.h"

#include <immintrin.h>

#define FUNC_PREFIX

#if (defined WALBERLA_CXX_COMPILER_IS_GNU) ||                                  \
    (defined WALBERLA_CXX_COMPILER_IS_CLANG)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#if (defined WALBERLA_CXX_COMPILER_IS_INTEL)
#pragma warning push
#pragma warning(disable : 1599)
#endif

using namespace std;

namespace walberla {
namespace pystencils {

namespace internal_f11a519921c681cbc9d0b2f51454c920 {
static FUNC_PREFIX void
collidesweepdoubleprecisionleesedwardsavx_collidesweepdoubleprecisionleesedwardsavx(
    double *RESTRICT const _data_force, double *RESTRICT _data_pdfs,
    double *RESTRICT const _data_velocity, int64_t const _size_force_0,
    int64_t const _size_force_1, int64_t const _size_force_2,
    int64_t const _stride_force_1, int64_t const _stride_force_2,
    int64_t const _stride_force_3, int64_t const _stride_pdfs_1,
    int64_t const _stride_pdfs_2, int64_t const _stride_pdfs_3,
    int64_t const _stride_velocity_1, int64_t const _stride_velocity_2,
    int64_t const _stride_velocity_3, double omega_shear) {
  for (int64_t ctr_2 = 0; ctr_2 < _size_force_2; ctr_2 += 1) {
    double *RESTRICT _data_pdfs_20_33 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 3 * _stride_pdfs_3;
    double *RESTRICT _data_force_20_31 =
        _data_force + _stride_force_2 * ctr_2 + _stride_force_3;
    double *RESTRICT _data_velocity_20_30 =
        _data_velocity + _stride_velocity_2 * ctr_2;
    double *RESTRICT _data_force_20_30 = _data_force + _stride_force_2 * ctr_2;
    double *RESTRICT _data_pdfs_20_35 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 5 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_314 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 14 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_318 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 18 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_38 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 8 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_313 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 13 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_316 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 16 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_315 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 15 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_312 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 12 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_317 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 17 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_32 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 2 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_36 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 6 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_39 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 9 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_37 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 7 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_311 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 11 * _stride_pdfs_3;
    double *RESTRICT _data_velocity_20_32 =
        _data_velocity + _stride_velocity_2 * ctr_2 + 2 * _stride_velocity_3;
    double *RESTRICT _data_pdfs_20_34 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 4 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_30 = _data_pdfs + _stride_pdfs_2 * ctr_2;
    double *RESTRICT _data_pdfs_20_310 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 10 * _stride_pdfs_3;
    double *RESTRICT _data_pdfs_20_31 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + _stride_pdfs_3;
    double *RESTRICT _data_force_20_32 =
        _data_force + _stride_force_2 * ctr_2 + 2 * _stride_force_3;
    double *RESTRICT _data_velocity_20_31 =
        _data_velocity + _stride_velocity_2 * ctr_2 + _stride_velocity_3;
    for (int64_t ctr_1 = 0; ctr_1 < _size_force_1; ctr_1 += 1) {
      double *RESTRICT _data_pdfs_20_33_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_33;
      double *RESTRICT _data_force_20_31_10 =
          _stride_force_1 * ctr_1 + _data_force_20_31;
      double *RESTRICT _data_velocity_20_30_10 =
          _stride_velocity_1 * ctr_1 + _data_velocity_20_30;
      double *RESTRICT _data_force_20_30_10 =
          _stride_force_1 * ctr_1 + _data_force_20_30;
      double *RESTRICT _data_pdfs_20_35_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_35;
      double *RESTRICT _data_pdfs_20_314_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_314;
      double *RESTRICT _data_pdfs_20_318_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_318;
      double *RESTRICT _data_pdfs_20_38_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_38;
      double *RESTRICT _data_pdfs_20_313_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_313;
      double *RESTRICT _data_pdfs_20_316_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_316;
      double *RESTRICT _data_pdfs_20_315_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_315;
      double *RESTRICT _data_pdfs_20_312_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_312;
      double *RESTRICT _data_pdfs_20_317_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_317;
      double *RESTRICT _data_pdfs_20_32_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_32;
      double *RESTRICT _data_pdfs_20_36_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_36;
      double *RESTRICT _data_pdfs_20_39_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_39;
      double *RESTRICT _data_pdfs_20_37_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_37;
      double *RESTRICT _data_pdfs_20_311_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_311;
      double *RESTRICT _data_velocity_20_32_10 =
          _stride_velocity_1 * ctr_1 + _data_velocity_20_32;
      double *RESTRICT _data_pdfs_20_34_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_34;
      double *RESTRICT _data_pdfs_20_30_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_30;
      double *RESTRICT _data_pdfs_20_310_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_310;
      double *RESTRICT _data_pdfs_20_31_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_31;
      double *RESTRICT _data_force_20_32_10 =
          _stride_force_1 * ctr_1 + _data_force_20_32;
      double *RESTRICT _data_velocity_20_31_10 =
          _stride_velocity_1 * ctr_1 + _data_velocity_20_31;
      {
        for (int64_t ctr_0 = 0; ctr_0 < (int64_t)((_size_force_0) / (4)) * (4);
             ctr_0 += 4) {
          const __m256d xi_26 = _mm256_load_pd(&_data_pdfs_20_33_10[ctr_0]);
          const __m256d xi_27 = _mm256_load_pd(&_data_force_20_31_10[ctr_0]);
          const __m256d xi_28 = _mm256_load_pd(&_data_velocity_20_30_10[ctr_0]);
          const __m256d xi_29 = _mm256_load_pd(&_data_force_20_30_10[ctr_0]);
          const __m256d xi_30 = _mm256_load_pd(&_data_pdfs_20_35_10[ctr_0]);
          const __m256d xi_31 = _mm256_load_pd(&_data_pdfs_20_314_10[ctr_0]);
          const __m256d xi_32 = _mm256_load_pd(&_data_pdfs_20_318_10[ctr_0]);
          const __m256d xi_33 = _mm256_load_pd(&_data_pdfs_20_38_10[ctr_0]);
          const __m256d xi_34 = _mm256_load_pd(&_data_pdfs_20_313_10[ctr_0]);
          const __m256d xi_35 = _mm256_load_pd(&_data_pdfs_20_316_10[ctr_0]);
          const __m256d xi_36 = _mm256_load_pd(&_data_pdfs_20_315_10[ctr_0]);
          const __m256d xi_37 = _mm256_load_pd(&_data_pdfs_20_312_10[ctr_0]);
          const __m256d xi_38 = _mm256_load_pd(&_data_pdfs_20_317_10[ctr_0]);
          const __m256d xi_39 = _mm256_load_pd(&_data_pdfs_20_32_10[ctr_0]);
          const __m256d xi_40 = _mm256_load_pd(&_data_pdfs_20_36_10[ctr_0]);
          const __m256d xi_41 = _mm256_load_pd(&_data_pdfs_20_39_10[ctr_0]);
          const __m256d xi_42 = _mm256_load_pd(&_data_pdfs_20_37_10[ctr_0]);
          const __m256d xi_43 = _mm256_load_pd(&_data_pdfs_20_311_10[ctr_0]);
          const __m256d xi_44 = _mm256_load_pd(&_data_velocity_20_32_10[ctr_0]);
          const __m256d xi_45 = _mm256_load_pd(&_data_pdfs_20_34_10[ctr_0]);
          const __m256d xi_46 = _mm256_load_pd(&_data_pdfs_20_30_10[ctr_0]);
          const __m256d xi_47 = _mm256_load_pd(&_data_pdfs_20_310_10[ctr_0]);
          const __m256d xi_48 = _mm256_load_pd(&_data_pdfs_20_31_10[ctr_0]);
          const __m256d xi_49 = _mm256_load_pd(&_data_force_20_32_10[ctr_0]);
          const __m256d xi_50 = _mm256_load_pd(&_data_velocity_20_31_10[ctr_0]);
          const __m256d xi_1 = xi_26;
          const __m256d xi_2 = xi_27;
          const __m256d xi_3 = xi_28;
          const __m256d xi_4 = xi_29;
          const __m256d xi_5 = xi_30;
          const __m256d xi_6 = xi_50;
          const __m256d xi_7 = xi_31;
          const __m256d xi_8 = xi_32;
          const __m256d xi_9 = xi_48;
          const __m256d xi_10 = xi_34;
          const __m256d xi_11 = xi_35;
          const __m256d xi_12 = xi_36;
          const __m256d xi_13 = xi_37;
          const __m256d xi_14 = xi_39;
          const __m256d xi_15 = xi_40;
          const __m256d xi_16 = xi_41;
          const __m256d xi_17 = xi_42;
          const __m256d xi_18 = xi_43;
          const __m256d xi_19 = xi_44;
          const __m256d xi_20 = xi_45;
          const __m256d xi_21 = xi_46;
          const __m256d xi_22 = xi_47;
          const __m256d xi_23 = xi_38;
          const __m256d xi_24 = xi_49;
          const __m256d xi_25 = xi_33;
          const __m256d rho = _mm256_add_pd(
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_add_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_add_pd(
                                                                      _mm256_add_pd(
                                                                          _mm256_add_pd(
                                                                              _mm256_add_pd(
                                                                                  xi_1,
                                                                                  xi_10),
                                                                              xi_11),
                                                                          xi_12),
                                                                      xi_13),
                                                                  xi_14),
                                                              xi_15),
                                                          xi_16),
                                                      xi_17),
                                                  xi_18),
                                              xi_20),
                                          xi_21),
                                      xi_22),
                                  xi_23),
                              xi_25),
                          xi_5),
                      xi_7),
                  xi_8),
              xi_9);
          const __m256d u1Pu2 = _mm256_add_pd(xi_19, xi_6);
          const __m256d u1Mu2 = _mm256_add_pd(
              _mm256_mul_pd(xi_19, _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)),
              xi_6);
          _mm256_store_pd(
              &_data_pdfs_20_30_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_19, xi_24),
                                      _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_2, xi_6),
                                      _mm256_set_pd(-1.0, -1.0, -1.0, -1.0))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_3, xi_4),
                                  _mm256_set_pd(-1.0, -1.0, -1.0, -1.0))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              _mm256_set_pd(0.333333333333333,
                                                            0.333333333333333,
                                                            0.333333333333333,
                                                            0.333333333333333)),
                                          _mm256_mul_pd(
                                              xi_21,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.333333333333333,
                                                        -0.333333333333333,
                                                        -0.333333333333333,
                                                        -0.333333333333333))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.333333333333333,
                                                    -0.333333333333333,
                                                    -0.333333333333333,
                                                    -0.333333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.333333333333333, -0.333333333333333,
                                      -0.333333333333333, -0.333333333333333))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_21));
          _mm256_store_pd(
              &_data_pdfs_20_31_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2, _mm256_add_pd(
                                                    _mm256_mul_pd(
                                                        xi_6, _mm256_set_pd(
                                                                  2.0, 2.0, 2.0,
                                                                  2.0)),
                                                    _mm256_set_pd(1.0, 1.0, 1.0,
                                                                  1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_19, xi_24),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_6, xi_6)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_6,
                                                              _mm256_set_pd(
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_9, _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_9));
          _mm256_store_pd(
              &_data_pdfs_20_32_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2, _mm256_add_pd(
                                                    _mm256_mul_pd(
                                                        xi_6, _mm256_set_pd(
                                                                  2.0, 2.0, 2.0,
                                                                  2.0)),
                                                    _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_19, xi_24),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_6, xi_6)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_6,
                                                              _mm256_set_pd(
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_14,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_14));
          _mm256_store_pd(
              &_data_pdfs_20_33_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4, _mm256_add_pd(
                                                    _mm256_mul_pd(
                                                        xi_3, _mm256_set_pd(
                                                                  2.0, 2.0, 2.0,
                                                                  2.0)),
                                                    _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_19, xi_24),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_2, xi_6),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_3, xi_3)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_1, _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_1));
          _mm256_store_pd(
              &_data_pdfs_20_34_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4, _mm256_add_pd(
                                                    _mm256_mul_pd(
                                                        xi_3, _mm256_set_pd(
                                                                  2.0, 2.0, 2.0,
                                                                  2.0)),
                                                    _mm256_set_pd(1.0, 1.0, 1.0,
                                                                  1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_19, xi_24),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_2, xi_6),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_3, xi_3)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_20,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_20));
          _mm256_store_pd(
              &_data_pdfs_20_35_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24, _mm256_add_pd(
                                                     _mm256_mul_pd(
                                                         xi_19, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0)),
                                                     _mm256_set_pd(1.0, 1.0,
                                                                   1.0, 1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_2, xi_6),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_3, xi_4),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_19,
                                                                  xi_19)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_19,
                                                              _mm256_set_pd(
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667,
                                                                  0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_5, _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_5));
          _mm256_store_pd(
              &_data_pdfs_20_36_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  xi_19,
                                                  _mm256_set_pd(2.0, 2.0, 2.0,
                                                                2.0)),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667,
                                                    0.166666666666667)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(xi_2, xi_6),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(_mm256_mul_pd(xi_3, xi_4),
                                            _mm256_set_pd(-0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667,
                                                          -0.166666666666667))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_mul_pd(
                                                              (_mm256_mul_pd(
                                                                  xi_19,
                                                                  xi_19)),
                                                              _mm256_set_pd(
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333,
                                                                  0.333333333333333)),
                                                          _mm256_mul_pd(
                                                              xi_19,
                                                              _mm256_set_pd(
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667,
                                                                  -0.166666666666667))),
                                                      _mm256_set_pd(
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111,
                                                          -0.111111111111111))),
                                              _mm256_mul_pd(
                                                  rho, _mm256_set_pd(
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667,
                                                           0.166666666666667))),
                                          _mm256_mul_pd(
                                              xi_15,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667,
                                                        -0.166666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667,
                                                    -0.166666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(
                                      -0.166666666666667, -0.166666666666667,
                                      -0.166666666666667, -0.166666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_15));
          _mm256_store_pd(&_data_pdfs_20_37_10[ctr_0],
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  _mm256_mul_pd(
                                                      xi_2,
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      xi_3,
                                                                      _mm256_set_pd(
                                                                          -3.0,
                                                                          -3.0,
                                                                          -3.0,
                                                                          -3.0)),
                                                                  _mm256_mul_pd(
                                                                      xi_6,
                                                                      _mm256_set_pd(
                                                                          2.0,
                                                                          2.0,
                                                                          2.0,
                                                                          2.0))),
                                                              _mm256_set_pd(
                                                                  ((ctr_1 <= 0)
                                                                       ? (1.0)
                                                                       : (0.0)) *
                                                                      -0.15000000000000002,
                                                                  ((ctr_1 <= 0)
                                                                       ? (1.0)
                                                                       : (0.0)) *
                                                                      -0.15000000000000002,
                                                                  ((ctr_1 <= 0)
                                                                       ? (1.0)
                                                                       : (0.0)) *
                                                                      -0.15000000000000002,
                                                                  ((ctr_1 <= 0)
                                                                       ? (1.0)
                                                                       : (0.0)) *
                                                                      -0.15000000000000002)),
                                                          _mm256_set_pd(
                                                              1.0, 1.0, 1.0,
                                                              1.0))),
                                                  _mm256_set_pd(
                                                      0.0833333333333333,
                                                      0.0833333333333333,
                                                      0.0833333333333333,
                                                      0.0833333333333333)),
                                              _mm256_mul_pd(
                                                  _mm256_mul_pd(
                                                      xi_4,
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      xi_3, _mm256_set_pd(-2.0, -2.0, -2.0, -2.0)),
                                                                  _mm256_mul_pd(
                                                                      xi_6, _mm256_set_pd(
                                                                                3.0,
                                                                                3.0,
                                                                                3.0,
                                                                                3.0))),
                                                              _mm256_set_pd(
                                                                  ((ctr_1 <= 0) ? (1.0)
                                                                                : (0.0)) *
                                                                      -0.10000000000000001,
                                                                  ((ctr_1 <= 0) ? (1.0)
                                                                                : (0.0)) *
                                                                      -0.10000000000000001,
                                                                  ((ctr_1 <= 0) ? (1.0)
                                                                                : (0.0)) *
                                                                      -0.10000000000000001,
                                                                  ((ctr_1 <= 0) ? (1.0)
                                                                                : (0.0)) *
                                                                      -0.10000000000000001)),
                                                          _mm256_set_pd(
                                                              1.0, 1.0, 1.0,
                                                              1.0))),
                                                  _mm256_set_pd(
                                                      -0.0833333333333333,
                                                      -0.0833333333333333,
                                                      -0.0833333333333333,
                                                      -0.0833333333333333))),
                                          _mm256_mul_pd(
                                              _mm256_mul_pd(xi_19, xi_24),
                                              _mm256_set_pd(
                                                  -0.0833333333333333,
                                                  -0.0833333333333333,
                                                  -0.0833333333333333,
                                                  -0.0833333333333333))),
                                      _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                                    omega_shear * -0.5 + 1.0,
                                                    omega_shear * -0.5 + 1.0,
                                                    omega_shear * -0.5 + 1.0)),
                                  _mm256_mul_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(_mm256_mul_pd(rho, _mm256_add_pd(_mm256_add_pd(_mm256_add_pd(_mm256_add_pd(_mm256_add_pd(
                                                                                                                                                   _mm256_mul_pd((_mm256_mul_pd(_mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(xi_6, _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)), xi_3), _mm256_set_pd(
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                                                   (
                                                                                                                                                                                                                                                                                       (ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003)),
                                                                                                                                                                                _mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(xi_6, _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)), xi_3), _mm256_set_pd(
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                                                   ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.050000000000000003, ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.050000000000000003)))),
                                                                                                                                                                 _mm256_set_pd(
                                                                                                                                                                     0.125,
                                                                                                                                                                     0.125,
                                                                                                                                                                     0.125,
                                                                                                                                                                     0.125)),
                                                                                                                                                   _mm256_mul_pd((_mm256_mul_pd(xi_19, xi_19)), _mm256_set_pd(
                                                                                                                                                                                                    0.0416666666666667,
                                                                                                                                                                                                    0.0416666666666667,
                                                                                                                                                                                                    0.0416666666666667,
                                                                                                                                                                                                    0.0416666666666667))),
                                                                                                                                               _mm256_mul_pd(
                                                                                                                                                   xi_3,
                                                                                                                                                   _mm256_set_pd(
                                                                                                                                                       -0.0833333333333333,
                                                                                                                                                       -0.0833333333333333,
                                                                                                                                                       -0.0833333333333333,
                                                                                                                                                       -0.0833333333333333))),
                                                                                                                                 _mm256_mul_pd(
                                                                                                                                     xi_6,
                                                                                                                                     _mm256_set_pd(
                                                                                                                                         0.0833333333333333, 0.0833333333333333, 0.0833333333333333, 0.0833333333333333))),
                                                                                                                   _mm256_set_pd(((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.0041666666666666666, ((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.0041666666666666666, ((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.0041666666666666666, ((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.0041666666666666666)),
                                                                                                     _mm256_set_pd(
                                                                                                         -0.0138888888888889,
                                                                                                         -0.0138888888888889,
                                                                                                         -0.0138888888888889,
                                                                                                         -0.0138888888888889))),
                                                                    _mm256_mul_pd(
                                                                        rho,
                                                                        _mm256_set_pd(
                                                                            0.0416666666666667,
                                                                            0.0416666666666667,
                                                                            0.0416666666666667,
                                                                            0.0416666666666667))),
                                                      _mm256_mul_pd(
                                                          xi_17,
                                                          _mm256_set_pd(
                                                              -1.0,
                                                              -1.0, -1.0, -1.0))),
                                                  _mm256_mul_pd(
                                                      _mm256_mul_pd(
                                                          rho,
                                                          (_mm256_mul_pd(
                                                              _mm256_add_pd(
                                                                  xi_3,
                                                                  _mm256_set_pd(
                                                                      ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                                                          0.050000000000000003,
                                                                      ((ctr_1 <= 0) ? (1.0)
                                                                                    : (0.0)) *
                                                                          0.050000000000000003,
                                                                      ((ctr_1 <= 0) ? (1.0)
                                                                                    : (0.0)) *
                                                                          0.050000000000000003,
                                                                      (
                                                                          (
                                                                              ctr_1 <=
                                                                              0)
                                                                              ? (1.0)
                                                                              : (0.0)) *
                                                                          0.050000000000000003)),
                                                              _mm256_add_pd(
                                                                  xi_3,
                                                                  _mm256_set_pd(
                                                                      ((ctr_1 <= 0) ? (1.0)
                                                                                    : (0.0)) *
                                                                          0.050000000000000003,
                                                                      (
                                                                          (ctr_1 <= 0)
                                                                              ? (1.0)
                                                                              : (0.0)) *
                                                                          0.050000000000000003,
                                                                      (
                                                                          (
                                                                              ctr_1 <=
                                                                              0)
                                                                              ? (1.0)
                                                                              : (0.0)) *
                                                                          0.050000000000000003,
                                                                      (
                                                                          (
                                                                              ctr_1 <=
                                                                              0)
                                                                              ? (1.0)
                                                                              : (0.0)) *
                                                                          0.050000000000000003))))),
                                                      _mm256_set_pd(
                                                          -0.0416666666666667,
                                                          -0.0416666666666667,
                                                          -0.0416666666666667,
                                                          -0.0416666666666667))),
                                              _mm256_mul_pd(
                                                  _mm256_mul_pd(
                                                      rho, (_mm256_mul_pd(
                                                               xi_19, xi_19))),
                                                  _mm256_set_pd(
                                                      -0.0416666666666667,
                                                      -0.0416666666666667,
                                                      -0.0416666666666667,
                                                      -0.0416666666666667))),
                                          _mm256_mul_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  (_mm256_mul_pd(xi_6, xi_6))),
                                              _mm256_set_pd(
                                                  -0.0416666666666667,
                                                  -0.0416666666666667,
                                                  -0.0416666666666667,
                                                  -0.0416666666666667))),
                                      _mm256_set_pd(omega_shear, omega_shear,
                                                    omega_shear, omega_shear))),
                              xi_17));
          _mm256_store_pd(
              &_data_pdfs_20_38_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0)),
                                                      _mm256_mul_pd(
                                                          xi_6, _mm256_set_pd(
                                                                    3.0, 3.0,
                                                                    3.0, 3.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.10000000000000001)),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    3.0, 3.0,
                                                                    3.0, 3.0)),
                                                      _mm256_mul_pd(
                                                          xi_6, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 <= 0) ? (1.0)
                                                                    : (0.0)) *
                                                          0.15000000000000002)),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_19, xi_24),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_add_pd(
                                                                      _mm256_mul_pd(
                                                                          (_mm256_mul_pd(
                                                                              _mm256_add_pd(
                                                                                  _mm256_add_pd(
                                                                                      xi_3,
                                                                                      xi_6),
                                                                                  _mm256_set_pd(
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003)),
                                                                              _mm256_add_pd(
                                                                                  _mm256_add_pd(
                                                                                      xi_3,
                                                                                      xi_6),
                                                                                  _mm256_set_pd(
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 <=
                                                                                        0)
                                                                                           ? (1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003)))),
                                                                          _mm256_set_pd(
                                                                              0.125,
                                                                              0.125,
                                                                              0.125,
                                                                              0.125)),
                                                                      _mm256_mul_pd(
                                                                          (_mm256_mul_pd(
                                                                              xi_19,
                                                                              xi_19)),
                                                                          _mm256_set_pd(
                                                                              0.0416666666666667,
                                                                              0.0416666666666667,
                                                                              0.0416666666666667,
                                                                              0.0416666666666667))),
                                                                  _mm256_mul_pd(
                                                                      xi_3,
                                                                      _mm256_set_pd(
                                                                          0.0833333333333333,
                                                                          0.0833333333333333,
                                                                          0.0833333333333333,
                                                                          0.0833333333333333))),
                                                              _mm256_mul_pd(
                                                                  xi_6,
                                                                  _mm256_set_pd(
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333))),
                                                          _mm256_set_pd(
                                                              ((ctr_1 <= 0)
                                                                   ? (1.0)
                                                                   : (0.0)) *
                                                                  0.0041666666666666666,
                                                              ((ctr_1 <= 0)
                                                                   ? (1.0)
                                                                   : (0.0)) *
                                                                  0.0041666666666666666,
                                                              ((ctr_1 <= 0)
                                                                   ? (1.0)
                                                                   : (0.0)) *
                                                                  0.0041666666666666666,
                                                              ((ctr_1 <= 0)
                                                                   ? (1.0)
                                                                   : (0.0)) *
                                                                  0.0041666666666666666)),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_25,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_25));
          _mm256_store_pd(
              &_data_pdfs_20_39_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0)),
                                                      _mm256_mul_pd(
                                                          xi_6, _mm256_set_pd(
                                                                    3.0, 3.0,
                                                                    3.0, 3.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001)),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    3.0, 3.0,
                                                                    3.0, 3.0)),
                                                      _mm256_mul_pd(
                                                          xi_6, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002)),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_19, xi_24),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_add_pd(
                                                                      _mm256_mul_pd(
                                                                          (_mm256_mul_pd(
                                                                              _mm256_add_pd(
                                                                                  _mm256_add_pd(
                                                                                      xi_3,
                                                                                      xi_6),
                                                                                  _mm256_set_pd(
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003)),
                                                                              _mm256_add_pd(
                                                                                  _mm256_add_pd(
                                                                                      xi_3,
                                                                                      xi_6),
                                                                                  _mm256_set_pd(
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003,
                                                                                      ((ctr_1 >=
                                                                                        63)
                                                                                           ? (-1.0)
                                                                                           : (0.0)) *
                                                                                          0.050000000000000003)))),
                                                                          _mm256_set_pd(
                                                                              0.125,
                                                                              0.125,
                                                                              0.125,
                                                                              0.125)),
                                                                      _mm256_mul_pd(
                                                                          (_mm256_mul_pd(
                                                                              xi_19,
                                                                              xi_19)),
                                                                          _mm256_set_pd(
                                                                              0.0416666666666667,
                                                                              0.0416666666666667,
                                                                              0.0416666666666667,
                                                                              0.0416666666666667))),
                                                                  _mm256_mul_pd(
                                                                      xi_3,
                                                                      _mm256_set_pd(
                                                                          -0.0833333333333333,
                                                                          -0.0833333333333333,
                                                                          -0.0833333333333333,
                                                                          -0.0833333333333333))),
                                                              _mm256_mul_pd(
                                                                  xi_6,
                                                                  _mm256_set_pd(
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333))),
                                                          _mm256_set_pd(
                                                              ((ctr_1 >= 63)
                                                                   ? (-1.0)
                                                                   : (0.0)) *
                                                                  -0.0041666666666666666,
                                                              ((ctr_1 >= 63)
                                                                   ? (-1.0)
                                                                   : (0.0)) *
                                                                  -0.0041666666666666666,
                                                              ((ctr_1 >= 63)
                                                                   ? (-1.0)
                                                                   : (0.0)) *
                                                                  -0.0041666666666666666,
                                                              ((ctr_1 >= 63)
                                                                   ? (-1.0)
                                                                   : (0.0)) *
                                                                  -0.0041666666666666666)),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_16,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_16));
          _mm256_store_pd(
              &_data_pdfs_20_310_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    2.0, 2.0,
                                                                    2.0, 2.0)),
                                                      _mm256_mul_pd(
                                                          xi_6,
                                                          _mm256_set_pd(
                                                              -3.0, -3.0, -3.0,
                                                              -3.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.10000000000000001)),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_add_pd(
                                                      _mm256_mul_pd(
                                                          xi_3, _mm256_set_pd(
                                                                    3.0, 3.0,
                                                                    3.0, 3.0)),
                                                      _mm256_mul_pd(
                                                          xi_6,
                                                          _mm256_set_pd(
                                                              -2.0, -2.0, -2.0,
                                                              -2.0))),
                                                  _mm256_set_pd(
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002,
                                                      ((ctr_1 >= 63) ? (-1.0)
                                                                     : (0.0)) *
                                                          0.15000000000000002)),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_19, xi_24),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho, _mm256_add_pd(
                                                           _mm256_add_pd(
                                                               _mm256_add_pd(_mm256_add_pd(_mm256_add_pd(_mm256_mul_pd((_mm256_mul_pd(_mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(xi_6, _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)), xi_3), _mm256_set_pd(((ctr_1 >= 63) ? (-1.0)
                                                                                                                                                                                                                                                                  : (0.0)) *
                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                   ((ctr_1 >= 63) ? (-1.0)
                                                                                                                                                                                                                                                                  : (0.0)) *
                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                   (
                                                                                                                                                                                                                                                       (
                                                                                                                                                                                                                                                           ctr_1 >=
                                                                                                                                                                                                                                                           63)
                                                                                                                                                                                                                                                           ? (-1.0)
                                                                                                                                                                                                                                                           : (0.0)) *
                                                                                                                                                                                                                                                       0.050000000000000003,
                                                                                                                                                                                                                                                   ((ctr_1 >= 63) ? (-1.0)
                                                                                                                                                                                                                                                                  : (0.0)) *
                                                                                                                                                                                                                                                       0.050000000000000003)),
                                                                                                                                      _mm256_add_pd(
                                                                                                                                          _mm256_add_pd(_mm256_mul_pd(xi_6, _mm256_set_pd(-1.0, -1.0, -1.0, -1.0)), xi_3), _mm256_set_pd(((ctr_1 >= 63)
                                                                                                                                                                                                                                              ? (-1.0)
                                                                                                                                                                                                                                              : (0.0)) *
                                                                                                                                                                                                                                             0.050000000000000003,
                                                                                                                                                                                                                                         (
                                                                                                                                                                                                                                             (
                                                                                                                                                                                                                                                 ctr_1 >=
                                                                                                                                                                                                                                                 63)
                                                                                                                                                                                                                                                 ? (
                                                                                                                                                                                                                                                       -1.0)
                                                                                                                                                                                                                                                 : (0.0)) *
                                                                                                                                                                                                                                             0.050000000000000003,
                                                                                                                                                                                                                                         (
                                                                                                                                                                                                                                             (ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                                                                                                                                                                                                                             0.050000000000000003,
                                                                                                                                                                                                                                         ((ctr_1 >= 63) ? (-1.0) : (0.0)) * 0.050000000000000003)))),
                                                                                                                       _mm256_set_pd(
                                                                                                                           0.125,
                                                                                                                           0.125,
                                                                                                                           0.125,
                                                                                                                           0.125)),
                                                                                                         _mm256_mul_pd(
                                                                                                             (_mm256_mul_pd(
                                                                                                                 xi_19,
                                                                                                                 xi_19)),
                                                                                                             _mm256_set_pd(
                                                                                                                 0.0416666666666667,
                                                                                                                 0.0416666666666667,
                                                                                                                 0.0416666666666667,
                                                                                                                 0.0416666666666667))),
                                                                                           _mm256_mul_pd(
                                                                                               xi_3,
                                                                                               _mm256_set_pd(
                                                                                                   0.0833333333333333,
                                                                                                   0.0833333333333333,
                                                                                                   0.0833333333333333,
                                                                                                   0.0833333333333333))),
                                                                             _mm256_mul_pd(
                                                                                 xi_6,
                                                                                 _mm256_set_pd(
                                                                                     -0.0833333333333333,
                                                                                     -0.0833333333333333,
                                                                                     -0.0833333333333333,
                                                                                     -0.0833333333333333))),
                                                               _mm256_set_pd(
                                                                   ((ctr_1 >=
                                                                     63)
                                                                        ? (-1.0)
                                                                        : (0.0)) *
                                                                       0.0041666666666666666,
                                                                   ((ctr_1 >=
                                                                     63)
                                                                        ? (-1.0)
                                                                        : (0.0)) *
                                                                       0.0041666666666666666,
                                                                   ((ctr_1 >=
                                                                     63)
                                                                        ? (-1.0)
                                                                        : (0.0)) *
                                                                       0.0041666666666666666,
                                                                   ((ctr_1 >=
                                                                     63)
                                                                        ? (-1.0)
                                                                        : (0.0)) *
                                                                       0.0041666666666666666)),
                                                           _mm256_set_pd(
                                                               -0.0138888888888889,
                                                               -0.0138888888888889,
                                                               -0.0138888888888889,
                                                               -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_22,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_22));
          _mm256_store_pd(
              &_data_pdfs_20_311_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_6,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(
                                      xi_2,
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  xi_19,
                                                  _mm256_set_pd(3.0, 3.0, 3.0,
                                                                3.0)),
                                              _mm256_mul_pd(
                                                  xi_6,
                                                  _mm256_set_pd(2.0, 2.0, 2.0,
                                                                2.0))),
                                          _mm256_set_pd(1.0, 1.0, 1.0, 1.0))),
                                  _mm256_set_pd(
                                      0.0833333333333333, 0.0833333333333333,
                                      0.0833333333333333, 0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)),
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)))),
                                                                  _mm256_set_pd(
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667)),
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      u1Pu2,
                                                                      u1Pu2)),
                                                                  _mm256_set_pd(
                                                                      0.125,
                                                                      0.125,
                                                                      0.125,
                                                                      0.125))),
                                                          _mm256_mul_pd(
                                                              u1Pu2,
                                                              _mm256_set_pd(
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_18,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_18));
          _mm256_store_pd(
              &_data_pdfs_20_312_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_6, _mm256_set_pd(
                                                                -3.0, -3.0,
                                                                -3.0, -3.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(
                                      xi_2,
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  xi_19,
                                                  _mm256_set_pd(3.0, 3.0, 3.0,
                                                                3.0)),
                                              _mm256_mul_pd(
                                                  xi_6,
                                                  _mm256_set_pd(-2.0, -2.0,
                                                                -2.0, -2.0))),
                                          _mm256_set_pd(1.0, 1.0, 1.0, 1.0))),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)),
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)))),
                                                                  _mm256_set_pd(
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667)),
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      u1Mu2,
                                                                      u1Mu2)),
                                                                  _mm256_set_pd(
                                                                      0.125,
                                                                      0.125,
                                                                      0.125,
                                                                      0.125))),
                                                          _mm256_mul_pd(
                                                              u1Mu2,
                                                              _mm256_set_pd(
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_13,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_13));
          _mm256_store_pd(
              &_data_pdfs_20_313_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_3, _mm256_set_pd(
                                                                -3.0, -3.0,
                                                                -3.0, -3.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0)),
                                                  _mm256_mul_pd(
                                                      xi_3, _mm256_set_pd(
                                                                -2.0, -2.0,
                                                                -2.0, -2.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_2, xi_6),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          _mm256_add_pd(
                                                                              _mm256_mul_pd(
                                                                                  xi_19,
                                                                                  _mm256_set_pd(
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0)),
                                                                              xi_3),
                                                                          _mm256_add_pd(
                                                                              _mm256_mul_pd(
                                                                                  xi_19,
                                                                                  _mm256_set_pd(
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0)),
                                                                              xi_3))),
                                                                      _mm256_set_pd(
                                                                          0.125,
                                                                          0.125,
                                                                          0.125,
                                                                          0.125)),
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          xi_6,
                                                                          xi_6)),
                                                                      _mm256_set_pd(
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667))),
                                                              _mm256_mul_pd(
                                                                  xi_19,
                                                                  _mm256_set_pd(
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333))),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_10,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_10));
          _mm256_store_pd(
              &_data_pdfs_20_314_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_2, xi_6),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          _mm256_add_pd(
                                                                              xi_19,
                                                                              xi_3),
                                                                          _mm256_add_pd(
                                                                              xi_19,
                                                                              xi_3))),
                                                                      _mm256_set_pd(
                                                                          0.125,
                                                                          0.125,
                                                                          0.125,
                                                                          0.125)),
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          xi_6,
                                                                          xi_6)),
                                                                      _mm256_set_pd(
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667))),
                                                              _mm256_mul_pd(
                                                                  xi_19,
                                                                  _mm256_set_pd(
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333,
                                                                      0.0833333333333333))),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_7, _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_7));
          _mm256_store_pd(
              &_data_pdfs_20_315_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 <= 0) ? (1.0)
                                                                : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_2,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19, _mm256_set_pd(
                                                                 -3.0, -3.0,
                                                                 -3.0, -3.0)),
                                                  _mm256_mul_pd(
                                                      xi_6,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(
                                      xi_24,
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  xi_19,
                                                  _mm256_set_pd(-2.0, -2.0,
                                                                -2.0, -2.0)),
                                              _mm256_mul_pd(
                                                  xi_6,
                                                  _mm256_set_pd(3.0, 3.0, 3.0,
                                                                3.0))),
                                          _mm256_set_pd(1.0, 1.0, 1.0, 1.0))),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)),
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 <=
                                                                                0)
                                                                                   ? (1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)))),
                                                                  _mm256_set_pd(
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667)),
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      u1Mu2,
                                                                      u1Mu2)),
                                                                  _mm256_set_pd(
                                                                      0.125,
                                                                      0.125,
                                                                      0.125,
                                                                      0.125))),
                                                          _mm256_mul_pd(
                                                              u1Mu2,
                                                              _mm256_set_pd(
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_12,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 <= 0)
                                                               ? (1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_12));
          _mm256_store_pd(
              &_data_pdfs_20_316_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              xi_3,
                                              _mm256_set_pd(
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003,
                                                  ((ctr_1 >= 63) ? (-1.0)
                                                                 : (0.0)) *
                                                      0.050000000000000003))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_6,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0))),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(
                                      xi_2, _mm256_add_pd(
                                                _mm256_add_pd(
                                                    _mm256_mul_pd(
                                                        xi_19, _mm256_set_pd(
                                                                   3.0, 3.0,
                                                                   3.0, 3.0)),
                                                    _mm256_mul_pd(
                                                        xi_6, _mm256_set_pd(
                                                                  2.0, 2.0, 2.0,
                                                                  2.0))),
                                                _mm256_set_pd(-1.0, -1.0, -1.0,
                                                              -1.0))),
                                  _mm256_set_pd(
                                      0.0833333333333333, 0.0833333333333333,
                                      0.0833333333333333, 0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)),
                                                                      _mm256_add_pd(
                                                                          xi_3,
                                                                          _mm256_set_pd(
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003,
                                                                              ((ctr_1 >=
                                                                                63)
                                                                                   ? (-1.0)
                                                                                   : (0.0)) *
                                                                                  0.050000000000000003)))),
                                                                  _mm256_set_pd(
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667,
                                                                      0.0416666666666667)),
                                                              _mm256_mul_pd(
                                                                  (_mm256_mul_pd(
                                                                      u1Pu2,
                                                                      u1Pu2)),
                                                                  _mm256_set_pd(
                                                                      0.125,
                                                                      0.125,
                                                                      0.125,
                                                                      0.125))),
                                                          _mm256_mul_pd(
                                                              u1Pu2,
                                                              _mm256_set_pd(
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_11,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003)),
                                                  _mm256_add_pd(
                                                      xi_3,
                                                      _mm256_set_pd(
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003,
                                                          ((ctr_1 >= 63)
                                                               ? (-1.0)
                                                               : (0.0)) *
                                                              0.050000000000000003))))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_19, xi_19))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_11));
          _mm256_store_pd(
              &_data_pdfs_20_317_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0))),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0))),
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_2, xi_6),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          _mm256_add_pd(
                                                                              xi_19,
                                                                              xi_3),
                                                                          _mm256_add_pd(
                                                                              xi_19,
                                                                              xi_3))),
                                                                      _mm256_set_pd(
                                                                          0.125,
                                                                          0.125,
                                                                          0.125,
                                                                          0.125)),
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          xi_6,
                                                                          xi_6)),
                                                                      _mm256_set_pd(
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667))),
                                                              _mm256_mul_pd(
                                                                  xi_19,
                                                                  _mm256_set_pd(
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333))),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333,
                                                                  -0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_23,
                                              _mm256_set_pd(-1.0, -1.0, -1.0,
                                                            -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_23));
          _mm256_store_pd(
              &_data_pdfs_20_318_10[ctr_0],
              _mm256_add_pd(
                  _mm256_add_pd(
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_4,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19, _mm256_set_pd(
                                                                 -3.0, -3.0,
                                                                 -3.0, -3.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(2.0, 2.0,
                                                                    2.0, 2.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333,
                                                    0.0833333333333333)),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          xi_24,
                                          _mm256_add_pd(
                                              _mm256_add_pd(
                                                  _mm256_mul_pd(
                                                      xi_19, _mm256_set_pd(
                                                                 -2.0, -2.0,
                                                                 -2.0, -2.0)),
                                                  _mm256_mul_pd(
                                                      xi_3,
                                                      _mm256_set_pd(3.0, 3.0,
                                                                    3.0, 3.0))),
                                              _mm256_set_pd(1.0, 1.0, 1.0,
                                                            1.0))),
                                      _mm256_set_pd(-0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333,
                                                    -0.0833333333333333))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(xi_2, xi_6),
                                  _mm256_set_pd(-0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333,
                                                -0.0833333333333333))),
                          _mm256_set_pd(omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0,
                                        omega_shear * -0.5 + 1.0)),
                      _mm256_mul_pd(
                          _mm256_add_pd(
                              _mm256_add_pd(
                                  _mm256_add_pd(
                                      _mm256_add_pd(
                                          _mm256_add_pd(
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_add_pd(
                                                      _mm256_add_pd(
                                                          _mm256_add_pd(
                                                              _mm256_add_pd(
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          _mm256_add_pd(
                                                                              _mm256_mul_pd(
                                                                                  xi_19,
                                                                                  _mm256_set_pd(
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0)),
                                                                              xi_3),
                                                                          _mm256_add_pd(
                                                                              _mm256_mul_pd(
                                                                                  xi_19,
                                                                                  _mm256_set_pd(
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0,
                                                                                      -1.0)),
                                                                              xi_3))),
                                                                      _mm256_set_pd(
                                                                          0.125,
                                                                          0.125,
                                                                          0.125,
                                                                          0.125)),
                                                                  _mm256_mul_pd(
                                                                      (_mm256_mul_pd(
                                                                          xi_6,
                                                                          xi_6)),
                                                                      _mm256_set_pd(
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667,
                                                                          0.0416666666666667))),
                                                              _mm256_mul_pd(
                                                                  xi_19,
                                                                  _mm256_set_pd(
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333,
                                                                      -0.0833333333333333))),
                                                          _mm256_mul_pd(
                                                              xi_3,
                                                              _mm256_set_pd(
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333,
                                                                  0.0833333333333333))),
                                                      _mm256_set_pd(
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889,
                                                          -0.0138888888888889))),
                                              _mm256_mul_pd(
                                                  rho,
                                                  _mm256_set_pd(
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667,
                                                      0.0416666666666667))),
                                          _mm256_mul_pd(
                                              xi_8, _mm256_set_pd(-1.0, -1.0,
                                                                  -1.0, -1.0))),
                                      _mm256_mul_pd(
                                          _mm256_mul_pd(
                                              rho,
                                              (_mm256_mul_pd(xi_19, xi_19))),
                                          _mm256_set_pd(-0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667,
                                                        -0.0416666666666667))),
                                  _mm256_mul_pd(
                                      _mm256_mul_pd(
                                          rho, (_mm256_mul_pd(xi_3, xi_3))),
                                      _mm256_set_pd(-0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667,
                                                    -0.0416666666666667))),
                              _mm256_mul_pd(
                                  _mm256_mul_pd(rho,
                                                (_mm256_mul_pd(xi_6, xi_6))),
                                  _mm256_set_pd(-0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667,
                                                -0.0416666666666667))),
                          _mm256_set_pd(omega_shear, omega_shear, omega_shear,
                                        omega_shear))),
                  xi_8));
        }
        for (int64_t ctr_0 = (int64_t)((_size_force_0) / (4)) * (4);
             ctr_0 < _size_force_0; ctr_0 += 1) {
          const double xi_26 = _data_pdfs_20_33_10[ctr_0];
          const double xi_27 = _data_force_20_31_10[ctr_0];
          const double xi_28 = _data_velocity_20_30_10[ctr_0];
          const double xi_29 = _data_force_20_30_10[ctr_0];
          const double xi_30 = _data_pdfs_20_35_10[ctr_0];
          const double xi_31 = _data_pdfs_20_314_10[ctr_0];
          const double xi_32 = _data_pdfs_20_318_10[ctr_0];
          const double xi_33 = _data_pdfs_20_38_10[ctr_0];
          const double xi_34 = _data_pdfs_20_313_10[ctr_0];
          const double xi_35 = _data_pdfs_20_316_10[ctr_0];
          const double xi_36 = _data_pdfs_20_315_10[ctr_0];
          const double xi_37 = _data_pdfs_20_312_10[ctr_0];
          const double xi_38 = _data_pdfs_20_317_10[ctr_0];
          const double xi_39 = _data_pdfs_20_32_10[ctr_0];
          const double xi_40 = _data_pdfs_20_36_10[ctr_0];
          const double xi_41 = _data_pdfs_20_39_10[ctr_0];
          const double xi_42 = _data_pdfs_20_37_10[ctr_0];
          const double xi_43 = _data_pdfs_20_311_10[ctr_0];
          const double xi_44 = _data_velocity_20_32_10[ctr_0];
          const double xi_45 = _data_pdfs_20_34_10[ctr_0];
          const double xi_46 = _data_pdfs_20_30_10[ctr_0];
          const double xi_47 = _data_pdfs_20_310_10[ctr_0];
          const double xi_48 = _data_pdfs_20_31_10[ctr_0];
          const double xi_49 = _data_force_20_32_10[ctr_0];
          const double xi_50 = _data_velocity_20_31_10[ctr_0];
          const double xi_1 = xi_26;
          const double xi_2 = xi_27;
          const double xi_3 = xi_28;
          const double xi_4 = xi_29;
          const double xi_5 = xi_30;
          const double xi_6 = xi_50;
          const double xi_7 = xi_31;
          const double xi_8 = xi_32;
          const double xi_9 = xi_48;
          const double xi_10 = xi_34;
          const double xi_11 = xi_35;
          const double xi_12 = xi_36;
          const double xi_13 = xi_37;
          const double xi_14 = xi_39;
          const double xi_15 = xi_40;
          const double xi_16 = xi_41;
          const double xi_17 = xi_42;
          const double xi_18 = xi_43;
          const double xi_19 = xi_44;
          const double xi_20 = xi_45;
          const double xi_21 = xi_46;
          const double xi_22 = xi_47;
          const double xi_23 = xi_38;
          const double xi_24 = xi_49;
          const double xi_25 = xi_33;
          const double rho = xi_1 + xi_10 + xi_11 + xi_12 + xi_13 + xi_14 +
                             xi_15 + xi_16 + xi_17 + xi_18 + xi_20 + xi_21 +
                             xi_22 + xi_23 + xi_25 + xi_5 + xi_7 + xi_8 + xi_9;
          const double u1Pu2 = xi_19 + xi_6;
          const double u1Mu2 = -xi_19 + xi_6;
          _data_pdfs_20_30_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.333333333333333 +
                             rho * (xi_3 * xi_3) * -0.333333333333333 +
                             rho * (xi_6 * xi_6) * -0.333333333333333 +
                             rho * 0.333333333333333 - xi_21) +
              xi_21 +
              (omega_shear * -0.5 + 1.0) *
                  (-xi_19 * xi_24 - xi_2 * xi_6 - xi_3 * xi_4);
          _data_pdfs_20_31_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho *
                       ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003) *
                        (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003)) *
                       -0.166666666666667 +
                   rho * ((xi_6 * xi_6) * 0.333333333333333 +
                          xi_6 * 0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_9) +
              xi_9 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.166666666666667 +
                   xi_2 * (xi_6 * 2.0 + 1.0) * 0.166666666666667 +
                   xi_4 *
                       (xi_3 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.050000000000000003) *
                       -0.166666666666667);
          _data_pdfs_20_32_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho *
                       ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                    0.050000000000000003) *
                        (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                    0.050000000000000003)) *
                       -0.166666666666667 +
                   rho * ((xi_6 * xi_6) * 0.333333333333333 +
                          xi_6 * -0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_14) +
              xi_14 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.166666666666667 +
                   xi_2 * (xi_6 * 2.0 - 1.0) * 0.166666666666667 +
                   xi_4 *
                       (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                   0.050000000000000003) *
                       -0.166666666666667);
          _data_pdfs_20_33_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_3 * xi_3) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho * ((xi_3 * xi_3) * 0.333333333333333 +
                          xi_3 * -0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_1) +
              xi_1 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.166666666666667 +
                   xi_2 * xi_6 * -0.166666666666667 +
                   xi_4 * (xi_3 * 2.0 - 1.0) * 0.166666666666667);
          _data_pdfs_20_34_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_3 * xi_3) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho * ((xi_3 * xi_3) * 0.333333333333333 +
                          xi_3 * 0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_20) +
              xi_20 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.166666666666667 +
                   xi_2 * xi_6 * -0.166666666666667 +
                   xi_4 * (xi_3 * 2.0 + 1.0) * 0.166666666666667);
          _data_pdfs_20_35_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_3 * xi_3) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho * ((xi_19 * xi_19) * 0.333333333333333 +
                          xi_19 * 0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_5) +
              xi_5 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.166666666666667 +
                   xi_24 * (xi_19 * 2.0 + 1.0) * 0.166666666666667 +
                   xi_3 * xi_4 * -0.166666666666667);
          _data_pdfs_20_36_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.166666666666667 +
                   rho * (xi_3 * xi_3) * -0.166666666666667 +
                   rho * (xi_6 * xi_6) * -0.166666666666667 +
                   rho * ((xi_19 * xi_19) * 0.333333333333333 +
                          xi_19 * -0.166666666666667 - 0.111111111111111) +
                   rho * 0.166666666666667 - xi_15) +
              xi_15 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.166666666666667 +
                   xi_24 * (xi_19 * 2.0 - 1.0) * 0.166666666666667 +
                   xi_3 * xi_4 * -0.166666666666667);
          _data_pdfs_20_37_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho *
                                 ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                              0.050000000000000003) *
                                  (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                              0.050000000000000003)) *
                                 -0.0416666666666667 +
                             rho * ((xi_19 * xi_19) * 0.0416666666666667 +
                                    xi_3 * -0.0833333333333333 +
                                    xi_6 * 0.0833333333333333 +
                                    ((xi_3 - xi_6 +
                                      ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                          0.050000000000000003) *
                                     (xi_3 - xi_6 +
                                      ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                          0.050000000000000003)) *
                                        0.125 +
                                    ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                        -0.0041666666666666666 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_17) +
              xi_17 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.0833333333333333 +
                   xi_2 *
                       (xi_3 * -3.0 + xi_6 * 2.0 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.15000000000000002 +
                        1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 * -2.0 + xi_6 * 3.0 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * -0.10000000000000001 +
                        1.0) *
                       -0.0833333333333333);
          _data_pdfs_20_38_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                   rho * (xi_6 * xi_6) * -0.0416666666666667 +
                   rho *
                       ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003) *
                        (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003)) *
                       -0.0416666666666667 +
                   rho *
                       ((xi_19 * xi_19) * 0.0416666666666667 +
                        xi_3 * 0.0833333333333333 + xi_6 * 0.0833333333333333 +
                        ((xi_3 + xi_6 +
                          ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                              0.050000000000000003) *
                         (xi_3 + xi_6 +
                          ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                              0.050000000000000003)) *
                            0.125 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.0041666666666666666 -
                        0.0138888888888889) +
                   rho * 0.0416666666666667 - xi_25) +
              xi_25 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.0833333333333333 +
                   xi_2 *
                       (xi_3 * 3.0 + xi_6 * 2.0 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.15000000000000002 +
                        1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 * 2.0 + xi_6 * 3.0 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.10000000000000001 +
                        1.0) *
                       0.0833333333333333);
          _data_pdfs_20_39_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho *
                                 ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003) *
                                  (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003)) *
                                 -0.0416666666666667 +
                             rho * ((xi_19 * xi_19) * 0.0416666666666667 +
                                    xi_3 * -0.0833333333333333 +
                                    xi_6 * -0.0833333333333333 +
                                    ((xi_3 + xi_6 +
                                      ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                          0.050000000000000003) *
                                     (xi_3 + xi_6 +
                                      ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                          0.050000000000000003)) *
                                        0.125 +
                                    ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                        -0.0041666666666666666 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_16) +
              xi_16 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.0833333333333333 +
                   xi_2 *
                       (xi_3 * 3.0 + xi_6 * 2.0 +
                        ((ctr_1 >= 63) ? (-1.0) : (0.0)) * 0.15000000000000002 -
                        1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 * 2.0 + xi_6 * 3.0 +
                        ((ctr_1 >= 63) ? (-1.0) : (0.0)) * 0.10000000000000001 -
                        1.0) *
                       0.0833333333333333);
          _data_pdfs_20_310_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho *
                                 ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003) *
                                  (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003)) *
                                 -0.0416666666666667 +
                             rho * ((xi_19 * xi_19) * 0.0416666666666667 +
                                    xi_3 * 0.0833333333333333 +
                                    xi_6 * -0.0833333333333333 +
                                    ((xi_3 - xi_6 +
                                      ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                          0.050000000000000003) *
                                     (xi_3 - xi_6 +
                                      ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                          0.050000000000000003)) *
                                        0.125 +
                                    ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                        0.0041666666666666666 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_22) +
              xi_22 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_19 * xi_24 * -0.0833333333333333 +
                   xi_2 *
                       (xi_3 * 3.0 + xi_6 * -2.0 +
                        ((ctr_1 >= 63) ? (-1.0) : (0.0)) * 0.15000000000000002 +
                        1.0) *
                       -0.0833333333333333 +
                   xi_4 *
                       (xi_3 * 2.0 + xi_6 * -3.0 +
                        ((ctr_1 >= 63) ? (-1.0) : (0.0)) * 0.10000000000000001 +
                        1.0) *
                       0.0833333333333333);
          _data_pdfs_20_311_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                   rho * (xi_6 * xi_6) * -0.0416666666666667 +
                   rho *
                       ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003) *
                        (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003)) *
                       -0.0416666666666667 +
                   rho * ((u1Pu2 * u1Pu2) * 0.125 + u1Pu2 * 0.0833333333333333 +
                          ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                       0.050000000000000003) *
                           (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                       0.050000000000000003)) *
                              0.0416666666666667 -
                          0.0138888888888889) +
                   rho * 0.0416666666666667 - xi_18) +
              xi_18 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * (xi_19 * 3.0 + xi_6 * 2.0 + 1.0) *
                       0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_6 * 3.0 + 1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.050000000000000003) *
                       -0.0833333333333333);
          _data_pdfs_20_312_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho *
                                 ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003) *
                                  (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003)) *
                                 -0.0416666666666667 +
                             rho * ((u1Mu2 * u1Mu2) * 0.125 +
                                    u1Mu2 * -0.0833333333333333 +
                                    ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                                 0.050000000000000003) *
                                     (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                                 0.050000000000000003)) *
                                        0.0416666666666667 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_13) +
              xi_13 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * (xi_19 * 3.0 + xi_6 * -2.0 + 1.0) *
                       -0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_6 * -3.0 + 1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                   0.050000000000000003) *
                       -0.0833333333333333);
          _data_pdfs_20_313_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                   rho * (xi_3 * xi_3) * -0.0416666666666667 +
                   rho * (xi_6 * xi_6) * -0.0416666666666667 +
                   rho * (xi_19 * 0.0833333333333333 +
                          xi_3 * -0.0833333333333333 +
                          (xi_6 * xi_6) * 0.0416666666666667 +
                          ((-xi_19 + xi_3) * (-xi_19 + xi_3)) * 0.125 -
                          0.0138888888888889) +
                   rho * 0.0416666666666667 - xi_10) +
              xi_10 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_3 * -3.0 + 1.0) *
                       0.0833333333333333 +
                   xi_4 * (xi_19 * 3.0 + xi_3 * -2.0 + 1.0) *
                       -0.0833333333333333);
          _data_pdfs_20_314_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_3 * xi_3) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho * (xi_19 * 0.0833333333333333 +
                                    xi_3 * 0.0833333333333333 +
                                    (xi_6 * xi_6) * 0.0416666666666667 +
                                    ((xi_19 + xi_3) * (xi_19 + xi_3)) * 0.125 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_7) +
              xi_7 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_3 * 3.0 + 1.0) *
                       0.0833333333333333 +
                   xi_4 * (xi_19 * 3.0 + xi_3 * 2.0 + 1.0) *
                       0.0833333333333333);
          _data_pdfs_20_315_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                   rho * (xi_6 * xi_6) * -0.0416666666666667 +
                   rho *
                       ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003) *
                        (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                    0.050000000000000003)) *
                       -0.0416666666666667 +
                   rho * ((u1Mu2 * u1Mu2) * 0.125 + u1Mu2 * 0.0833333333333333 +
                          ((xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                       0.050000000000000003) *
                           (xi_3 + ((ctr_1 <= 0) ? (1.0) : (0.0)) *
                                       0.050000000000000003)) *
                              0.0416666666666667 -
                          0.0138888888888889) +
                   rho * 0.0416666666666667 - xi_12) +
              xi_12 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * (xi_19 * -3.0 + xi_6 * 2.0 + 1.0) *
                       0.0833333333333333 +
                   xi_24 * (xi_19 * -2.0 + xi_6 * 3.0 + 1.0) *
                       -0.0833333333333333 +
                   xi_4 *
                       (xi_3 +
                        ((ctr_1 <= 0) ? (1.0) : (0.0)) * 0.050000000000000003) *
                       -0.0833333333333333);
          _data_pdfs_20_316_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho *
                                 ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003) *
                                  (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                              0.050000000000000003)) *
                                 -0.0416666666666667 +
                             rho * ((u1Pu2 * u1Pu2) * 0.125 +
                                    u1Pu2 * -0.0833333333333333 +
                                    ((xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                                 0.050000000000000003) *
                                     (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                                 0.050000000000000003)) *
                                        0.0416666666666667 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_11) +
              xi_11 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * (xi_19 * 3.0 + xi_6 * 2.0 - 1.0) *
                       0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_6 * 3.0 - 1.0) *
                       0.0833333333333333 +
                   xi_4 *
                       (xi_3 + ((ctr_1 >= 63) ? (-1.0) : (0.0)) *
                                   0.050000000000000003) *
                       -0.0833333333333333);
          _data_pdfs_20_317_10[ctr_0] =
              omega_shear * (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                             rho * (xi_3 * xi_3) * -0.0416666666666667 +
                             rho * (xi_6 * xi_6) * -0.0416666666666667 +
                             rho * (xi_19 * -0.0833333333333333 +
                                    xi_3 * -0.0833333333333333 +
                                    (xi_6 * xi_6) * 0.0416666666666667 +
                                    ((xi_19 + xi_3) * (xi_19 + xi_3)) * 0.125 -
                                    0.0138888888888889) +
                             rho * 0.0416666666666667 - xi_23) +
              xi_23 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.0833333333333333 +
                   xi_24 * (xi_19 * 2.0 + xi_3 * 3.0 - 1.0) *
                       0.0833333333333333 +
                   xi_4 * (xi_19 * 3.0 + xi_3 * 2.0 - 1.0) *
                       0.0833333333333333);
          _data_pdfs_20_318_10[ctr_0] =
              omega_shear *
                  (rho * (xi_19 * xi_19) * -0.0416666666666667 +
                   rho * (xi_3 * xi_3) * -0.0416666666666667 +
                   rho * (xi_6 * xi_6) * -0.0416666666666667 +
                   rho * (xi_19 * -0.0833333333333333 +
                          xi_3 * 0.0833333333333333 +
                          (xi_6 * xi_6) * 0.0416666666666667 +
                          ((-xi_19 + xi_3) * (-xi_19 + xi_3)) * 0.125 -
                          0.0138888888888889) +
                   rho * 0.0416666666666667 - xi_8) +
              xi_8 +
              (omega_shear * -0.5 + 1.0) *
                  (xi_2 * xi_6 * -0.0833333333333333 +
                   xi_24 * (xi_19 * -2.0 + xi_3 * 3.0 + 1.0) *
                       -0.0833333333333333 +
                   xi_4 * (xi_19 * -3.0 + xi_3 * 2.0 + 1.0) *
                       0.0833333333333333);
        }
      }
    }
  }
}
} // namespace internal_f11a519921c681cbc9d0b2f51454c920

void CollideSweepDoublePrecisionLeesEdwardsAVX::run(IBlock *block) {
  auto pdfs = block->getData<field::GhostLayerField<double, 19>>(pdfsID);
  auto velocity = block->getData<field::GhostLayerField<double, 3>>(velocityID);
  auto force = block->getData<field::GhostLayerField<double, 3>>(forceID);

  auto &omega_shear = this->omega_shear_;
  WALBERLA_ASSERT_GREATER_EQUAL(0, -int_c(force->nrOfGhostLayers()));
  double *RESTRICT const _data_force = force->dataAt(0, 0, 0, 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(0, -int_c(pdfs->nrOfGhostLayers()));
  double *RESTRICT _data_pdfs = pdfs->dataAt(0, 0, 0, 0);
  WALBERLA_ASSERT_EQUAL(pdfs->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(0, -int_c(velocity->nrOfGhostLayers()));
  double *RESTRICT const _data_velocity = velocity->dataAt(0, 0, 0, 0);
  WALBERLA_ASSERT_EQUAL(velocity->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->xSize()) + 0));
  const int64_t _size_force_0 = int64_t(cell_idx_c(force->xSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->ySize()) + 0));
  const int64_t _size_force_1 = int64_t(cell_idx_c(force->ySize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->zSize()) + 0));
  const int64_t _size_force_2 = int64_t(cell_idx_c(force->zSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  const int64_t _stride_force_1 = int64_t(force->yStride());
  const int64_t _stride_force_2 = int64_t(force->zStride());
  const int64_t _stride_force_3 = int64_t(1 * int64_t(force->fStride()));
  const int64_t _stride_pdfs_1 = int64_t(pdfs->yStride());
  const int64_t _stride_pdfs_2 = int64_t(pdfs->zStride());
  const int64_t _stride_pdfs_3 = int64_t(1 * int64_t(pdfs->fStride()));
  const int64_t _stride_velocity_1 = int64_t(velocity->yStride());
  const int64_t _stride_velocity_2 = int64_t(velocity->zStride());
  const int64_t _stride_velocity_3 = int64_t(1 * int64_t(velocity->fStride()));
  internal_f11a519921c681cbc9d0b2f51454c920::
      collidesweepdoubleprecisionleesedwardsavx_collidesweepdoubleprecisionleesedwardsavx(
          _data_force, _data_pdfs, _data_velocity, _size_force_0, _size_force_1,
          _size_force_2, _stride_force_1, _stride_force_2, _stride_force_3,
          _stride_pdfs_1, _stride_pdfs_2, _stride_pdfs_3, _stride_velocity_1,
          _stride_velocity_2, _stride_velocity_3, omega_shear);
}

void CollideSweepDoublePrecisionLeesEdwardsAVX::runOnCellInterval(
    const shared_ptr<StructuredBlockStorage> &blocks,
    const CellInterval &globalCellInterval, cell_idx_t ghostLayers,
    IBlock *block) {
  CellInterval ci = globalCellInterval;
  CellInterval blockBB = blocks->getBlockCellBB(*block);
  blockBB.expand(ghostLayers);
  ci.intersect(blockBB);
  blocks->transformGlobalToBlockLocalCellInterval(ci, *block);
  if (ci.empty())
    return;

  auto pdfs = block->getData<field::GhostLayerField<double, 19>>(pdfsID);
  auto velocity = block->getData<field::GhostLayerField<double, 3>>(velocityID);
  auto force = block->getData<field::GhostLayerField<double, 3>>(forceID);

  auto &omega_shear = this->omega_shear_;
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin(), -int_c(force->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin(), -int_c(force->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin(), -int_c(force->nrOfGhostLayers()));
  double *RESTRICT const _data_force =
      force->dataAt(ci.xMin(), ci.yMin(), ci.zMin(), 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin(), -int_c(pdfs->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin(), -int_c(pdfs->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin(), -int_c(pdfs->nrOfGhostLayers()));
  double *RESTRICT _data_pdfs =
      pdfs->dataAt(ci.xMin(), ci.yMin(), ci.zMin(), 0);
  WALBERLA_ASSERT_EQUAL(pdfs->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin(), -int_c(velocity->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin(), -int_c(velocity->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin(), -int_c(velocity->nrOfGhostLayers()));
  double *RESTRICT const _data_velocity =
      velocity->dataAt(ci.xMin(), ci.yMin(), ci.zMin(), 0);
  WALBERLA_ASSERT_EQUAL(velocity->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.xSize()) + 0));
  const int64_t _size_force_0 = int64_t(cell_idx_c(ci.xSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.ySize()) + 0));
  const int64_t _size_force_1 = int64_t(cell_idx_c(ci.ySize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_GREATER_EQUAL(force->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.zSize()) + 0));
  const int64_t _size_force_2 = int64_t(cell_idx_c(ci.zSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  const int64_t _stride_force_1 = int64_t(force->yStride());
  const int64_t _stride_force_2 = int64_t(force->zStride());
  const int64_t _stride_force_3 = int64_t(1 * int64_t(force->fStride()));
  const int64_t _stride_pdfs_1 = int64_t(pdfs->yStride());
  const int64_t _stride_pdfs_2 = int64_t(pdfs->zStride());
  const int64_t _stride_pdfs_3 = int64_t(1 * int64_t(pdfs->fStride()));
  const int64_t _stride_velocity_1 = int64_t(velocity->yStride());
  const int64_t _stride_velocity_2 = int64_t(velocity->zStride());
  const int64_t _stride_velocity_3 = int64_t(1 * int64_t(velocity->fStride()));
  internal_f11a519921c681cbc9d0b2f51454c920::
      collidesweepdoubleprecisionleesedwardsavx_collidesweepdoubleprecisionleesedwardsavx(
          _data_force, _data_pdfs, _data_velocity, _size_force_0, _size_force_1,
          _size_force_2, _stride_force_1, _stride_force_2, _stride_force_3,
          _stride_pdfs_1, _stride_pdfs_2, _stride_pdfs_3, _stride_velocity_1,
          _stride_velocity_2, _stride_velocity_3, omega_shear);
}

} // namespace pystencils
} // namespace walberla

#if (defined WALBERLA_CXX_COMPILER_IS_GNU) ||                                  \
    (defined WALBERLA_CXX_COMPILER_IS_CLANG)
#pragma GCC diagnostic pop
#endif

#if (defined WALBERLA_CXX_COMPILER_IS_INTEL)
#pragma warning pop
#endif
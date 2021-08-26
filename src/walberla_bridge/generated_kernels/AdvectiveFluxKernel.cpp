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
//! \\file AdvectiveFluxKernel.cpp
//! \\ingroup lbm
//! \\author lbmpy
//======================================================================================================================

#include <cmath>

#include "AdvectiveFluxKernel.h"
#include "core/DataTypes.h"
#include "core/Macros.h"

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

namespace internal_advectivefluxkernel_advectivefluxkernel {
static FUNC_PREFIX void advectivefluxkernel_advectivefluxkernel(
    double *RESTRICT _data_j, double *RESTRICT const _data_rho,
    double *RESTRICT const _data_u, int64_t const _size_j_0,
    int64_t const _size_j_1, int64_t const _size_j_2, int64_t const _stride_j_0,
    int64_t const _stride_j_1, int64_t const _stride_j_2,
    int64_t const _stride_j_3, int64_t const _stride_rho_0,
    int64_t const _stride_rho_1, int64_t const _stride_rho_2,
    int64_t const _stride_u_0, int64_t const _stride_u_1,
    int64_t const _stride_u_2, int64_t const _stride_u_3) {
#pragma omp parallel
  {
    {
      {
        {
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
            double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
            double *RESTRICT _data_rho_20_30 = _data_rho;
            double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
            double *RESTRICT _data_u_20_30 = _data_u;
            double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
            double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
            double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
            double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
            double *RESTRICT _data_rho_21_30_11 =
                _stride_rho_1 + _data_rho_21_30;
            double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
            double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
            double *RESTRICT _data_u_21_31 =
                _data_u + _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
            double *RESTRICT _data_u_21_32 =
                _data_u + _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
            _data_j_20_312_10[_stride_j_0] =
                -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                   0.0 < _data_u_20_31_10[_stride_u_0] &&
                   0.0 < _data_u_20_32_10[_stride_u_0])
                      ? (1.0)
                      : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0] *
                    _data_u_20_30_10[_stride_u_0] *
                    _data_u_20_31_10[_stride_u_0] *
                    _data_u_20_32_10[_stride_u_0] -
                ((0.0 > _data_u_21_31_11[0] && 0.0 > _data_u_21_32_11[0] &&
                  0.0 < _data_u_21_30_11[0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_21_30_11[0] * _data_u_21_30_11[0] *
                    _data_u_21_31_11[0] * _data_u_21_32_11[0] +
                _data_j_20_312_10[_stride_j_0];
          }
#pragma omp for schedule(static)
          for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
              double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
              double *RESTRICT _data_rho_20_30 = _data_rho;
              double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
              double *RESTRICT _data_u_20_30 = _data_u;
              double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
              double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
              double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
              double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
              double *RESTRICT _data_rho_21_30_11 =
                  _stride_rho_1 + _data_rho_21_30;
              double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
              double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
              double *RESTRICT _data_u_21_31 =
                  _data_u + _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
              double *RESTRICT _data_u_21_32 =
                  _data_u + _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
              _data_j_20_312_10[_stride_j_0 * ctr_0] =
                  -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                     0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                     0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                        ? (1.0)
                        : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_30_10[_stride_u_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] -
                  ((0.0 > _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 > _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 < _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_21_30_11[_stride_rho_0 * ctr_0 -
                                         _stride_rho_0] *
                      _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                  _data_j_20_312_10[_stride_j_0 * ctr_0];
            }
          }
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
            double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
            double *RESTRICT _data_rho_20_30 = _data_rho;
            double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
            double *RESTRICT _data_u_20_30 = _data_u;
            double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
            double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
            double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
            double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
            double *RESTRICT _data_rho_21_30_11 =
                _stride_rho_1 + _data_rho_21_30;
            double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
            double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
            double *RESTRICT _data_u_21_31 =
                _data_u + _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
            double *RESTRICT _data_u_21_32 =
                _data_u + _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
            _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)] =
                -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                   0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                   0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                      ? (1.0)
                      : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                    _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                ((0.0 > _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] &&
                  0.0 > _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] &&
                  0.0 < _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_21_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                       _stride_rho_0] *
                    _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                     _stride_u_0] *
                    _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                     _stride_u_0] *
                    _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                     _stride_u_0] +
                _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)];
          }
        }
#pragma omp for schedule(static)
        for (int64_t ctr_1 = 1; ctr_1 < _size_j_1 - 1; ctr_1 += 1) {
          {
            {
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_36 = _data_j + 6 * _stride_j_3;
                double *RESTRICT _data_j_20_36_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_36;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_31;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_36_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    (1.0 - fabs(_data_u_21_31_10[0])) *
                        ((0.0 > _data_u_21_32_10[0] &&
                          0.0 < _data_u_21_30_10[0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_10[0] * _data_u_21_30_10[0] *
                        _data_u_21_32_10[0] +
                    _data_j_20_36_10[_stride_j_0];
              }
              if (_size_j_0 > 2 && _size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_38 = _data_j + 8 * _stride_j_3;
                double *RESTRICT _data_j_20_38_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_38;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_38_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0])) *
                        ((0.0 > _data_u_21_32_1m1[_stride_u_0] &&
                          0.0 < _data_u_21_31_1m1[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0] *
                        _data_u_21_31_1m1[_stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0] +
                    _data_j_20_38_10[_stride_j_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                      0.0 > _data_u_20_31_10[_stride_u_0] &&
                      0.0 < _data_u_20_32_10[_stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    ((0.0 > _data_u_21_32_1m1[0] &&
                      0.0 < _data_u_21_30_1m1[0] && 0.0 < _data_u_21_31_1m1[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[0] * _data_u_21_30_1m1[0] *
                        _data_u_21_31_1m1[0] * _data_u_21_32_1m1[0] +
                    _data_j_20_310_10[_stride_j_0];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_312;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                       0.0 < _data_u_20_31_10[_stride_u_0] &&
                       0.0 < _data_u_20_32_10[_stride_u_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    ((0.0 > _data_u_21_31_11[0] && 0.0 > _data_u_21_32_11[0] &&
                      0.0 < _data_u_21_30_11[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[0] * _data_u_21_30_11[0] *
                        _data_u_21_31_11[0] * _data_u_21_32_11[0] +
                    _data_j_20_312_10[_stride_j_0];
              }
            }
            for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_36 = _data_j + 6 * _stride_j_3;
                double *RESTRICT _data_j_20_36_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_36;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_31;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_36_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    (1.0 -
                     fabs(
                         _data_u_21_31_10[_stride_u_0 * ctr_0 - _stride_u_0])) *
                        ((0.0 > _data_u_21_32_10[_stride_u_0 * ctr_0 -
                                                 _stride_u_0] &&
                          0.0 < _data_u_21_30_10[_stride_u_0 * ctr_0 -
                                                 _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_10[_stride_rho_0 * ctr_0 -
                                           _stride_rho_0] *
                        _data_u_21_30_10[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_32_10[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_36_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_0 - ctr_0 > 1) {
                double *RESTRICT _data_j_20_38 = _data_j + 8 * _stride_j_3;
                double *RESTRICT _data_j_20_38_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_38;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_38_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * ctr_0] *
                        _data_u_21_31_1m1[_stride_u_0 * ctr_0] *
                        _data_u_21_32_1m1[_stride_u_0 * ctr_0] +
                    _data_j_20_38_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0 * ctr_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                      0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                      0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_30_1m1[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 <
                          _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_21_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_310_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_312;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0 * ctr_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                       0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                       0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    ((0.0 >
                          _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                      0.0 >
                          _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                      0.0 < _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[_stride_rho_0 * ctr_0 -
                                           _stride_rho_0] *
                        _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_312_10[_stride_j_0 * ctr_0];
              }
            }
            {
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_36 = _data_j + 6 * _stride_j_3;
                double *RESTRICT _data_j_20_36_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_36;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_31;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_36_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -(1.0 -
                      fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])) *
                        ((0.0 >
                              _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                          0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                    (1.0 - fabs(_data_u_21_31_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])) *
                        ((0.0 > _data_u_21_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                          0.0 < _data_u_21_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_10[_stride_rho_0 * (_size_j_0 - 1) -
                                           _stride_rho_0] *
                        _data_u_21_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_21_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] +
                    _data_j_20_36_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                    ((0.0 > _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_312 = _data_j + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_312;
                double *RESTRICT _data_rho_20_30 = _data_rho;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 =
                    _data_u + _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                    ((0.0 > _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] &&
                      0.0 > _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] &&
                      0.0 < _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                           _stride_rho_0] *
                        _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] +
                    _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)];
              }
            }
          }
        }
        {
          {
            if (_size_j_0 > 2 && _size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_38 = _data_j + 8 * _stride_j_3;
              double *RESTRICT _data_j_20_38_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_38;
              double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
              double *RESTRICT _data_u_21_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
              double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
              double *RESTRICT _data_rho_21_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_21_30;
              double *RESTRICT _data_u_21_31 =
                  _data_u + _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_21_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
              double *RESTRICT _data_u_21_32 =
                  _data_u + _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_21_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
              double *RESTRICT _data_u_20_30 = _data_u;
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_rho_20_30 = _data_rho;
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              _data_j_20_38_10[_stride_j_0] =
                  -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                      ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                        0.0 < _data_u_20_32_10[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0] *
                      _data_u_20_31_10[_stride_u_0] *
                      _data_u_20_32_10[_stride_u_0] +
                  (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0])) *
                      ((0.0 > _data_u_21_32_1m1[_stride_u_0] &&
                        0.0 < _data_u_21_31_1m1[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_21_30_1m1[_stride_rho_0] *
                      _data_u_21_31_1m1[_stride_u_0] *
                      _data_u_21_32_1m1[_stride_u_0] +
                  _data_j_20_38_10[_stride_j_0];
            }
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
              double *RESTRICT _data_j_20_310_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
              double *RESTRICT _data_rho_20_30 = _data_rho;
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_30 = _data_u;
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
              double *RESTRICT _data_rho_21_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_21_30;
              double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
              double *RESTRICT _data_u_21_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
              double *RESTRICT _data_u_21_31 =
                  _data_u + _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_21_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
              double *RESTRICT _data_u_21_32 =
                  _data_u + _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_21_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
              _data_j_20_310_10[_stride_j_0] =
                  ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                    0.0 > _data_u_20_31_10[_stride_u_0] &&
                    0.0 < _data_u_20_32_10[_stride_u_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0] *
                      _data_u_20_30_10[_stride_u_0] *
                      _data_u_20_31_10[_stride_u_0] *
                      _data_u_20_32_10[_stride_u_0] +
                  ((0.0 > _data_u_21_32_1m1[0] && 0.0 < _data_u_21_30_1m1[0] &&
                    0.0 < _data_u_21_31_1m1[0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_21_30_1m1[0] * _data_u_21_30_1m1[0] *
                      _data_u_21_31_1m1[0] * _data_u_21_32_1m1[0] +
                  _data_j_20_310_10[_stride_j_0];
            }
          }
#pragma omp for schedule(static)
          for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
            if (_size_j_1 > 1 && _size_j_2 > 1 && _size_j_0 - ctr_0 > 1) {
              double *RESTRICT _data_j_20_38 = _data_j + 8 * _stride_j_3;
              double *RESTRICT _data_j_20_38_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_38;
              double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
              double *RESTRICT _data_u_21_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
              double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
              double *RESTRICT _data_rho_21_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_21_30;
              double *RESTRICT _data_u_21_31 =
                  _data_u + _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_21_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
              double *RESTRICT _data_u_21_32 =
                  _data_u + _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_21_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
              double *RESTRICT _data_u_20_30 = _data_u;
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_rho_20_30 = _data_rho;
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              _data_j_20_38_10[_stride_j_0 * ctr_0] =
                  -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                      ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                        0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] +
                  (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0 * ctr_0])) *
                      ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0] &&
                        0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_21_30_1m1[_stride_rho_0 * ctr_0] *
                      _data_u_21_31_1m1[_stride_u_0 * ctr_0] *
                      _data_u_21_32_1m1[_stride_u_0 * ctr_0] +
                  _data_j_20_38_10[_stride_j_0 * ctr_0];
            }
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
              double *RESTRICT _data_j_20_310_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
              double *RESTRICT _data_rho_20_30 = _data_rho;
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_30 = _data_u;
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
              double *RESTRICT _data_rho_21_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_21_30;
              double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
              double *RESTRICT _data_u_21_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
              double *RESTRICT _data_u_21_31 =
                  _data_u + _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_21_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
              double *RESTRICT _data_u_21_32 =
                  _data_u + _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_21_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
              _data_j_20_310_10[_stride_j_0 * ctr_0] =
                  ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                    0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                    0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_30_10[_stride_u_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] +
                  ((0.0 >
                        _data_u_21_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 <
                        _data_u_21_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_21_30_1m1[_stride_rho_0 * ctr_0 -
                                          _stride_rho_0] *
                      _data_u_21_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_21_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                  _data_j_20_310_10[_stride_j_0 * ctr_0];
            }
          }
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_310 = _data_j + 10 * _stride_j_3;
            double *RESTRICT _data_j_20_310_10 =
                _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
            double *RESTRICT _data_rho_20_30 = _data_rho;
            double *RESTRICT _data_rho_20_30_10 =
                _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
            double *RESTRICT _data_u_20_30 = _data_u;
            double *RESTRICT _data_u_20_30_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
            double *RESTRICT _data_u_20_31 = _data_u + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
            double *RESTRICT _data_u_20_32 = _data_u + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
            double *RESTRICT _data_rho_21_30 = _data_rho + _stride_rho_2;
            double *RESTRICT _data_rho_21_30_1m1 =
                _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                _data_rho_21_30;
            double *RESTRICT _data_u_21_30 = _data_u + _stride_u_2;
            double *RESTRICT _data_u_21_30_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
            double *RESTRICT _data_u_21_31 =
                _data_u + _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_21_31_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
            double *RESTRICT _data_u_21_32 =
                _data_u + _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_21_32_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
            _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)] =
                ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                  0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                  0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                    _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                ((0.0 > _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] &&
                  0.0 < _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] &&
                  0.0 < _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_21_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                        _stride_rho_0] *
                    _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] *
                    _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] *
                    _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] +
                _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)];
          }
        }
      }
#pragma omp for schedule(static)
      for (int64_t ctr_2 = 1; ctr_2 < _size_j_2 - 1; ctr_2 += 1) {
        {
          {
            {
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_34 =
                    _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                double *RESTRICT _data_j_20_34_10 = _data_j_20_34;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_11 = _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_11 =
                    _stride_rho_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_11 = _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_11 = _stride_u_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                _data_j_20_34_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                          0.0 < _data_u_20_31_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] +
                    (1.0 - fabs(_data_u_20_32_11[0])) *
                        ((0.0 > _data_u_20_31_11[0] &&
                          0.0 < _data_u_20_30_11[0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_11[0] * _data_u_20_30_11[0] *
                        _data_u_20_31_11[0] +
                    _data_j_20_34_10[_stride_j_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                _data_j_20_311_10[_stride_j_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                      0.0 > _data_u_20_32_10[_stride_u_0] &&
                      0.0 < _data_u_20_31_10[_stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    ((0.0 > _data_u_2m1_31_11[0] &&
                      0.0 < _data_u_2m1_30_11[0] && 0.0 < _data_u_2m1_32_11[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[0] * _data_u_2m1_30_11[0] *
                        _data_u_2m1_31_11[0] * _data_u_2m1_32_11[0] +
                    _data_j_20_311_10[_stride_j_0];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_312 =
                    _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                       0.0 < _data_u_20_31_10[_stride_u_0] &&
                       0.0 < _data_u_20_32_10[_stride_u_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    ((0.0 > _data_u_21_31_11[0] && 0.0 > _data_u_21_32_11[0] &&
                      0.0 < _data_u_21_30_11[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[0] * _data_u_21_30_11[0] *
                        _data_u_21_31_11[0] * _data_u_21_32_11[0] +
                    _data_j_20_312_10[_stride_j_0];
              }
            }
            for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_34 =
                    _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                double *RESTRICT _data_j_20_34_10 = _data_j_20_34;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_11 = _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_11 =
                    _stride_rho_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_11 = _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_11 = _stride_u_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                _data_j_20_34_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] +
                    (1.0 -
                     fabs(
                         _data_u_20_32_11[_stride_u_0 * ctr_0 - _stride_u_0])) *
                        ((0.0 > _data_u_20_31_11[_stride_u_0 * ctr_0 -
                                                 _stride_u_0] &&
                          0.0 < _data_u_20_30_11[_stride_u_0 * ctr_0 -
                                                 _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_11[_stride_rho_0 * ctr_0 -
                                           _stride_rho_0] *
                        _data_u_20_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_20_31_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_34_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                _data_j_20_311_10[_stride_j_0 * ctr_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                      0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0] &&
                      0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    ((0.0 > _data_u_2m1_31_11[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_30_11[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 <
                          _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_2m1_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_311_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_312 =
                    _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0 * ctr_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                       0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                       0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    ((0.0 >
                          _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                      0.0 >
                          _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                      0.0 < _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[_stride_rho_0 * ctr_0 -
                                           _stride_rho_0] *
                        _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_312_10[_stride_j_0 * ctr_0];
              }
            }
            {
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_34 =
                    _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                double *RESTRICT _data_j_20_34_10 = _data_j_20_34;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_11 = _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_11 =
                    _stride_rho_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_11 = _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_11 = _stride_u_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                _data_j_20_34_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -(1.0 -
                      fabs(_data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])) *
                        ((0.0 >
                              _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                          0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] +
                    (1.0 - fabs(_data_u_20_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])) *
                        ((0.0 > _data_u_20_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                          0.0 < _data_u_20_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                           _stride_rho_0] *
                        _data_u_20_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_20_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] +
                    _data_j_20_34_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                    ((0.0 > _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_312 =
                    _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                double *RESTRICT _data_j_20_312_10 = _data_j_20_312;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_11 =
                    _stride_rho_1 + _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_11 = _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_11 = _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_11 = _stride_u_1 + _data_u_21_32;
                _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                    ((0.0 > _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] &&
                      0.0 > _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] &&
                      0.0 < _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                           _stride_rho_0] *
                        _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] *
                        _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                         _stride_u_0] +
                    _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)];
              }
            }
          }
          for (int64_t ctr_1 = 1; ctr_1 < _size_j_1 - 1; ctr_1 += 1) {
            {
              {
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_30 =
                      _data_j + _stride_j_2 * ctr_2;
                  double *RESTRICT _data_j_20_30_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  _data_j_20_30_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_31_10[0])) *
                          (1.0 - fabs(_data_u_20_32_10[0])) *
                          ((0.0 < _data_u_20_30_10[0]) ? (1.0) : (0.0)) *
                          _data_rho_20_30_10[0] * _data_u_20_30_10[0] -
                      (1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0]) ? (1.0)
                                                                 : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] +
                      _data_j_20_30_10[_stride_j_0];
                }
                if (_size_j_0 > 2 && ctr_1 > 0 && ctr_2 > 0 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_31 =
                      _data_j + _stride_j_2 * ctr_2 + _stride_j_3;
                  double *RESTRICT _data_j_20_31_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_31;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_31;
                  _data_j_20_31_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0]) ? (1.0)
                                                                 : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_31_10[_stride_u_0] -
                      (1.0 - fabs(_data_u_20_30_1m1[_stride_u_0])) *
                          (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0])) *
                          ((0.0 < _data_u_20_31_1m1[_stride_u_0]) ? (1.0)
                                                                  : (0.0)) *
                          _data_rho_20_30_1m1[_stride_rho_0] *
                          _data_u_20_31_1m1[_stride_u_0] +
                      _data_j_20_31_10[_stride_j_0];
                }
                if (_size_j_0 > 2 && ctr_1 > 0 && ctr_2 > 0 &&
                    _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_32 =
                      _data_j + _stride_j_2 * ctr_2 + 2 * _stride_j_3;
                  double *RESTRICT _data_j_20_32_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_32;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_31;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_32;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_32_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                          (1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_32_10[_stride_u_0]) ? (1.0)
                                                                 : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_32_10[_stride_u_0] -
                      (1.0 - fabs(_data_u_2m1_30_10[_stride_u_0])) *
                          (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0])) *
                          ((0.0 < _data_u_2m1_32_10[_stride_u_0]) ? (1.0)
                                                                  : (0.0)) *
                          _data_rho_2m1_30_10[_stride_rho_0] *
                          _data_u_2m1_32_10[_stride_u_0] +
                      _data_j_20_32_10[_stride_j_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_33 =
                      _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                  double *RESTRICT _data_j_20_33_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_33;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_31;
                  _data_j_20_33_10[_stride_j_0] =
                      (1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                            0.0 > _data_u_20_31_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] -
                      (1.0 - fabs(_data_u_20_32_1m1[0])) *
                          ((0.0 < _data_u_20_30_1m1[0] &&
                            0.0 < _data_u_20_31_1m1[0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_1m1[0] * _data_u_20_30_1m1[0] *
                          _data_u_20_31_1m1[0] +
                      _data_j_20_33_10[_stride_j_0];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_34 =
                      _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                  double *RESTRICT _data_j_20_34_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_34;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  _data_j_20_34_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                            0.0 < _data_u_20_31_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] +
                      (1.0 - fabs(_data_u_20_32_11[0])) *
                          ((0.0 > _data_u_20_31_11[0] &&
                            0.0 < _data_u_20_30_11[0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_11[0] * _data_u_20_30_11[0] *
                          _data_u_20_31_11[0] +
                      _data_j_20_34_10[_stride_j_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_35 =
                      _data_j + _stride_j_2 * ctr_2 + 5 * _stride_j_3;
                  double *RESTRICT _data_j_20_35_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_35;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_31;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_32;
                  _data_j_20_35_10[_stride_j_0] =
                      (1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                            0.0 > _data_u_20_32_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] -
                      (1.0 - fabs(_data_u_2m1_31_10[0])) *
                          ((0.0 < _data_u_2m1_30_10[0] &&
                            0.0 < _data_u_2m1_32_10[0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_10[0] * _data_u_2m1_30_10[0] *
                          _data_u_2m1_32_10[0] +
                      _data_j_20_35_10[_stride_j_0];
                }
                if (ctr_1 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_36 =
                      _data_j + _stride_j_2 * ctr_2 + 6 * _stride_j_3;
                  double *RESTRICT _data_j_20_36_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_36;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_31;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_32;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_36_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                            0.0 < _data_u_20_32_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] +
                      (1.0 - fabs(_data_u_21_31_10[0])) *
                          ((0.0 > _data_u_21_32_10[0] &&
                            0.0 < _data_u_21_30_10[0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_21_30_10[0] * _data_u_21_30_10[0] *
                          _data_u_21_32_10[0] +
                      _data_j_20_36_10[_stride_j_0];
                }
                if (_size_j_0 > 2 && ctr_1 > 0 && ctr_2 > 0) {
                  double *RESTRICT _data_j_20_37 =
                      _data_j + _stride_j_2 * ctr_2 + 7 * _stride_j_3;
                  double *RESTRICT _data_j_20_37_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_37;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                  _data_j_20_37_10[_stride_j_0] =
                      (1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                            0.0 > _data_u_20_32_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] -
                      (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0])) *
                          ((0.0 < _data_u_2m1_31_1m1[_stride_u_0] &&
                            0.0 < _data_u_2m1_32_1m1[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_1m1[_stride_rho_0] *
                          _data_u_2m1_31_1m1[_stride_u_0] *
                          _data_u_2m1_32_1m1[_stride_u_0] +
                      _data_j_20_37_10[_stride_j_0];
                }
                if (_size_j_0 > 2 && ctr_1 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_38 =
                      _data_j + _stride_j_2 * ctr_2 + 8 * _stride_j_3;
                  double *RESTRICT _data_j_20_38_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_38;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_38_10[_stride_j_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                            0.0 < _data_u_20_32_10[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] +
                      (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0])) *
                          ((0.0 > _data_u_21_32_1m1[_stride_u_0] &&
                            0.0 < _data_u_21_31_1m1[_stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_21_30_1m1[_stride_rho_0] *
                          _data_u_21_31_1m1[_stride_u_0] *
                          _data_u_21_32_1m1[_stride_u_0] +
                      _data_j_20_38_10[_stride_j_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0) {
                  double *RESTRICT _data_j_20_39 =
                      _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                  double *RESTRICT _data_j_20_39_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_39;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_39_10[_stride_j_0] =
                      -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                         0.0 > _data_u_20_31_10[_stride_u_0] &&
                         0.0 > _data_u_20_32_10[_stride_u_0])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] -
                      ((0.0 < _data_u_2m1_30_1m1[0] &&
                        0.0 < _data_u_2m1_31_1m1[0] &&
                        0.0 < _data_u_2m1_32_1m1[0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_1m1[0] * _data_u_2m1_30_1m1[0] *
                          _data_u_2m1_31_1m1[0] * _data_u_2m1_32_1m1[0] +
                      _data_j_20_39_10[_stride_j_0];
                }
                if (ctr_1 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_310 =
                      _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                  double *RESTRICT _data_j_20_310_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_310;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                  _data_j_20_310_10[_stride_j_0] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                        0.0 > _data_u_20_31_10[_stride_u_0] &&
                        0.0 < _data_u_20_32_10[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] +
                      ((0.0 > _data_u_21_32_1m1[0] &&
                        0.0 < _data_u_21_30_1m1[0] &&
                        0.0 < _data_u_21_31_1m1[0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_1m1[0] * _data_u_21_30_1m1[0] *
                          _data_u_21_31_1m1[0] * _data_u_21_32_1m1[0] +
                      _data_j_20_310_10[_stride_j_0];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_311 =
                      _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                  double *RESTRICT _data_j_20_311_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_311;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_311_10[_stride_j_0] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                        0.0 > _data_u_20_32_10[_stride_u_0] &&
                        0.0 < _data_u_20_31_10[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] +
                      ((0.0 > _data_u_2m1_31_11[0] &&
                        0.0 < _data_u_2m1_30_11[0] &&
                        0.0 < _data_u_2m1_32_11[0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_11[0] * _data_u_2m1_30_11[0] *
                          _data_u_2m1_31_11[0] * _data_u_2m1_32_11[0] +
                      _data_j_20_311_10[_stride_j_0];
                }
                if (_size_j_1 - ctr_1 > 1 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_312 =
                      _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                  double *RESTRICT _data_j_20_312_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_312;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                  _data_j_20_312_10[_stride_j_0] =
                      -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                         0.0 < _data_u_20_31_10[_stride_u_0] &&
                         0.0 < _data_u_20_32_10[_stride_u_0])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0] *
                          _data_u_20_31_10[_stride_u_0] *
                          _data_u_20_32_10[_stride_u_0] -
                      ((0.0 > _data_u_21_31_11[0] &&
                        0.0 > _data_u_21_32_11[0] && 0.0 < _data_u_21_30_11[0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_11[0] * _data_u_21_30_11[0] *
                          _data_u_21_31_11[0] * _data_u_21_32_11[0] +
                      _data_j_20_312_10[_stride_j_0];
                }
              }
              for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_30 =
                      _data_j + _stride_j_2 * ctr_2;
                  double *RESTRICT _data_j_20_30_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  _data_j_20_30_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0 -
                                                    _stride_u_0])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0 -
                                                       _stride_u_0])) *
                          ((0.0 <
                            _data_u_20_30_10[_stride_u_0 * ctr_0 - _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0 - _stride_u_0] -
                      (1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] +
                      _data_j_20_30_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_0 - ctr_0 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_31 =
                      _data_j + _stride_j_2 * ctr_2 + _stride_j_3;
                  double *RESTRICT _data_j_20_31_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_31;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_31;
                  _data_j_20_31_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] -
                      (1.0 - fabs(_data_u_20_30_1m1[_stride_u_0 * ctr_0])) *
                          (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0 * ctr_0])) *
                          ((0.0 < _data_u_20_31_1m1[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_1m1[_stride_rho_0 * ctr_0] *
                          _data_u_20_31_1m1[_stride_u_0 * ctr_0] +
                      _data_j_20_31_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_0 - ctr_0 > 1 &&
                    _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_32 =
                      _data_j + _stride_j_2 * ctr_2 + 2 * _stride_j_3;
                  double *RESTRICT _data_j_20_32_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_32;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_31;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_32;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_32_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                          (1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] -
                      (1.0 - fabs(_data_u_2m1_30_10[_stride_u_0 * ctr_0])) *
                          (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0 * ctr_0])) *
                          ((0.0 < _data_u_2m1_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_2m1_32_10[_stride_u_0 * ctr_0] +
                      _data_j_20_32_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_33 =
                      _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                  double *RESTRICT _data_j_20_33_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_33;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_31;
                  _data_j_20_33_10[_stride_j_0 * ctr_0] =
                      (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                            0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] -
                      (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0 * ctr_0 -
                                                    _stride_u_0])) *
                          ((0.0 < _data_u_20_30_1m1[_stride_u_0 * ctr_0 -
                                                    _stride_u_0] &&
                            0.0 < _data_u_20_31_1m1[_stride_u_0 * ctr_0 -
                                                    _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_1m1[_stride_rho_0 * ctr_0 -
                                              _stride_rho_0] *
                          _data_u_20_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_20_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_33_10[_stride_j_0 * ctr_0];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_34 =
                      _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                  double *RESTRICT _data_j_20_34_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_34;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  _data_j_20_34_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                            0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] +
                      (1.0 - fabs(_data_u_20_32_11[_stride_u_0 * ctr_0 -
                                                   _stride_u_0])) *
                          ((0.0 > _data_u_20_31_11[_stride_u_0 * ctr_0 -
                                                   _stride_u_0] &&
                            0.0 < _data_u_20_30_11[_stride_u_0 * ctr_0 -
                                                   _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_11[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                          _data_u_20_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_20_31_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_34_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_35 =
                      _data_j + _stride_j_2 * ctr_2 + 5 * _stride_j_3;
                  double *RESTRICT _data_j_20_35_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_35;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_31;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_32;
                  _data_j_20_35_10[_stride_j_0 * ctr_0] =
                      (1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                            0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] -
                      (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0 * ctr_0 -
                                                    _stride_u_0])) *
                          ((0.0 < _data_u_2m1_30_10[_stride_u_0 * ctr_0 -
                                                    _stride_u_0] &&
                            0.0 < _data_u_2m1_32_10[_stride_u_0 * ctr_0 -
                                                    _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_10[_stride_rho_0 * ctr_0 -
                                              _stride_rho_0] *
                          _data_u_2m1_30_10[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_2m1_32_10[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_35_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_36 =
                      _data_j + _stride_j_2 * ctr_2 + 6 * _stride_j_3;
                  double *RESTRICT _data_j_20_36_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_36;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_31;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_32;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_36_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                            0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] +
                      (1.0 - fabs(_data_u_21_31_10[_stride_u_0 * ctr_0 -
                                                   _stride_u_0])) *
                          ((0.0 > _data_u_21_32_10[_stride_u_0 * ctr_0 -
                                                   _stride_u_0] &&
                            0.0 < _data_u_21_30_10[_stride_u_0 * ctr_0 -
                                                   _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_21_30_10[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                          _data_u_21_30_10[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_21_32_10[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_36_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_0 - ctr_0 > 1) {
                  double *RESTRICT _data_j_20_37 =
                      _data_j + _stride_j_2 * ctr_2 + 7 * _stride_j_3;
                  double *RESTRICT _data_j_20_37_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_37;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                  _data_j_20_37_10[_stride_j_0 * ctr_0] =
                      (1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                            0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] -
                      (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0 * ctr_0])) *
                          ((0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] &&
                            0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0] *
                          _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] *
                          _data_u_2m1_32_1m1[_stride_u_0 * ctr_0] +
                      _data_j_20_37_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && _size_j_0 - ctr_0 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_38 =
                      _data_j + _stride_j_2 * ctr_2 + 8 * _stride_j_3;
                  double *RESTRICT _data_j_20_38_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_38;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_38_10[_stride_j_0 * ctr_0] =
                      -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                            0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] +
                      (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0 * ctr_0])) *
                          ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0] &&
                            0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_21_30_1m1[_stride_rho_0 * ctr_0] *
                          _data_u_21_31_1m1[_stride_u_0 * ctr_0] *
                          _data_u_21_32_1m1[_stride_u_0 * ctr_0] +
                      _data_j_20_38_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && ctr_2 > 0) {
                  double *RESTRICT _data_j_20_39 =
                      _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                  double *RESTRICT _data_j_20_39_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_39;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_39_10[_stride_j_0 * ctr_0] =
                      -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                         0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                         0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] -
                      ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 -
                                                 _stride_u_0] &&
                        0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 -
                                                 _stride_u_0] &&
                        0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 -
                                                 _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0 -
                                               _stride_rho_0] *
                          _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 -
                                             _stride_u_0] *
                          _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 -
                                             _stride_u_0] *
                          _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 -
                                             _stride_u_0] +
                      _data_j_20_39_10[_stride_j_0 * ctr_0];
                }
                if (ctr_1 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_310 =
                      _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                  double *RESTRICT _data_j_20_310_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_310;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                  _data_j_20_310_10[_stride_j_0 * ctr_0] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                        0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                        0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] +
                      ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0 -
                                                _stride_u_0] &&
                        0.0 < _data_u_21_30_1m1[_stride_u_0 * ctr_0 -
                                                _stride_u_0] &&
                        0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0 -
                                                _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_1m1[_stride_rho_0 * ctr_0 -
                                              _stride_rho_0] *
                          _data_u_21_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_21_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_310_10[_stride_j_0 * ctr_0];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_311 =
                      _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                  double *RESTRICT _data_j_20_311_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_311;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_311_10[_stride_j_0 * ctr_0] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                        0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0] &&
                        0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] +
                      ((0.0 > _data_u_2m1_31_11[_stride_u_0 * ctr_0 -
                                                _stride_u_0] &&
                        0.0 < _data_u_2m1_30_11[_stride_u_0 * ctr_0 -
                                                _stride_u_0] &&
                        0.0 < _data_u_2m1_32_11[_stride_u_0 * ctr_0 -
                                                _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_11[_stride_rho_0 * ctr_0 -
                                              _stride_rho_0] *
                          _data_u_2m1_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_2m1_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_311_10[_stride_j_0 * ctr_0];
                }
                if (_size_j_1 - ctr_1 > 1 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_312 =
                      _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                  double *RESTRICT _data_j_20_312_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_312;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                  _data_j_20_312_10[_stride_j_0 * ctr_0] =
                      -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                         0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                         0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                          _data_u_20_30_10[_stride_u_0 * ctr_0] *
                          _data_u_20_31_10[_stride_u_0 * ctr_0] *
                          _data_u_20_32_10[_stride_u_0 * ctr_0] -
                      ((0.0 > _data_u_21_31_11[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                        0.0 > _data_u_21_32_11[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                        0.0 <
                            _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_11[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                          _data_u_21_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_21_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                          _data_u_21_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                      _data_j_20_312_10[_stride_j_0 * ctr_0];
                }
              }
              {
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_30 =
                      _data_j + _stride_j_2 * ctr_2;
                  double *RESTRICT _data_j_20_30_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  _data_j_20_30_10[_stride_j_0 * (_size_j_0 - 1)] =
                      -(1.0 -
                        fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])) *
                          (1.0 -
                           fabs(_data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])) *
                          ((0.0 <
                            _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] -
                      (1.0 -
                       fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])) *
                          (1.0 - fabs(_data_u_20_32_10[_stride_u_0 *
                                                       (_size_j_0 - 1)])) *
                          ((0.0 >
                            _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] +
                      _data_j_20_30_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_33 =
                      _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                  double *RESTRICT _data_j_20_33_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_33;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_20_31;
                  _data_j_20_33_10[_stride_j_0 * (_size_j_0 - 1)] =
                      (1.0 -
                       fabs(_data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 *
                                                   (_size_j_0 - 1)] &&
                            0.0 >
                                _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] -
                      (1.0 -
                       fabs(_data_u_20_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])) *
                          ((0.0 < _data_u_20_30_1m1[_stride_u_0 *
                                                        (_size_j_0 - 1) -
                                                    _stride_u_0] &&
                            0.0 < _data_u_20_31_1m1[_stride_u_0 *
                                                        (_size_j_0 - 1) -
                                                    _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                              _stride_rho_0] *
                          _data_u_20_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_20_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] +
                      _data_j_20_33_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_34 =
                      _data_j + _stride_j_2 * ctr_2 + 4 * _stride_j_3;
                  double *RESTRICT _data_j_20_34_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_34;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  _data_j_20_34_10[_stride_j_0 * (_size_j_0 - 1)] =
                      -(1.0 -
                        fabs(_data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 *
                                                   (_size_j_0 - 1)] &&
                            0.0 <
                                _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] +
                      (1.0 -
                       fabs(_data_u_20_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0])) *
                          ((0.0 >
                                _data_u_20_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                            0.0 <
                                _data_u_20_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                          _data_u_20_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                          _data_u_20_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] +
                      _data_j_20_34_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_1 > 0 && ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_35 =
                      _data_j + _stride_j_2 * ctr_2 + 5 * _stride_j_3;
                  double *RESTRICT _data_j_20_35_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_35;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_31;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_2m1_32;
                  _data_j_20_35_10[_stride_j_0 * (_size_j_0 - 1)] =
                      (1.0 -
                       fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 *
                                                   (_size_j_0 - 1)] &&
                            0.0 >
                                _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                      (1.0 -
                       fabs(_data_u_2m1_31_10[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])) *
                          ((0.0 < _data_u_2m1_30_10[_stride_u_0 *
                                                        (_size_j_0 - 1) -
                                                    _stride_u_0] &&
                            0.0 < _data_u_2m1_32_10[_stride_u_0 *
                                                        (_size_j_0 - 1) -
                                                    _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_2m1_30_10[_stride_rho_0 * (_size_j_0 - 1) -
                                              _stride_rho_0] *
                          _data_u_2m1_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_2m1_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] +
                      _data_j_20_35_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_1 > 0 && _size_j_1 - ctr_1 > 1 &&
                    _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_36 =
                      _data_j + _stride_j_2 * ctr_2 + 6 * _stride_j_3;
                  double *RESTRICT _data_j_20_36_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_36;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_31;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_21_32;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_36_10[_stride_j_0 * (_size_j_0 - 1)] =
                      -(1.0 -
                        fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])) *
                          ((0.0 > _data_u_20_30_10[_stride_u_0 *
                                                   (_size_j_0 - 1)] &&
                            0.0 <
                                _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                      (1.0 -
                       fabs(_data_u_21_31_10[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0])) *
                          ((0.0 >
                                _data_u_21_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                            0.0 <
                                _data_u_21_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])
                               ? (1.0)
                               : (0.0)) *
                          _data_rho_21_30_10[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                          _data_u_21_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                          _data_u_21_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] +
                      _data_j_20_36_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_1 > 0 && ctr_2 > 0) {
                  double *RESTRICT _data_j_20_39 =
                      _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                  double *RESTRICT _data_j_20_39_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_39;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)] =
                      -((0.0 >
                             _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                         0.0 >
                             _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                         0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                      ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                        0.0 < _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0] &&
                        0.0 < _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                 _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                               _stride_rho_0] *
                          _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] *
                          _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] *
                          _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                             _stride_u_0] +
                      _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_1 > 0 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_310 =
                      _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                  double *RESTRICT _data_j_20_310_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_310;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_1m1 =
                      _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_1m1 =
                      _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_21_32;
                  _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                        0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                        0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                      ((0.0 > _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                        0.0 < _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                        0.0 < _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                              _stride_rho_0] *
                          _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] +
                      _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (ctr_2 > 0 && _size_j_1 - ctr_1 > 1) {
                  double *RESTRICT _data_j_20_311 =
                      _data_j + _stride_j_2 * ctr_2 + 11 * _stride_j_3;
                  double *RESTRICT _data_j_20_311_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_311;
                  double *RESTRICT _data_rho_2m1_30 =
                      _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                  double *RESTRICT _data_rho_2m1_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                  double *RESTRICT _data_u_2m1_30 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                  double *RESTRICT _data_u_2m1_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                  double *RESTRICT _data_u_2m1_31 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_2m1_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                  double *RESTRICT _data_u_2m1_32 =
                      _data_u + _stride_u_2 * ctr_2 - _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_2m1_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)] =
                      ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                        0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] &&
                        0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                      ((0.0 > _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                        0.0 < _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                        0.0 < _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_2m1_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                              _stride_rho_0] *
                          _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] *
                          _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0] +
                      _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)];
                }
                if (_size_j_1 - ctr_1 > 1 && _size_j_2 - ctr_2 > 1) {
                  double *RESTRICT _data_j_20_312 =
                      _data_j + _stride_j_2 * ctr_2 + 12 * _stride_j_3;
                  double *RESTRICT _data_j_20_312_10 =
                      _stride_j_1 * ctr_1 + _data_j_20_312;
                  double *RESTRICT _data_rho_20_30 =
                      _data_rho + _stride_rho_2 * ctr_2;
                  double *RESTRICT _data_rho_20_30_10 =
                      _stride_rho_1 * ctr_1 + _data_rho_20_30;
                  double *RESTRICT _data_u_20_30 =
                      _data_u + _stride_u_2 * ctr_2;
                  double *RESTRICT _data_u_20_30_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_30;
                  double *RESTRICT _data_u_20_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                  double *RESTRICT _data_u_20_31_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_31;
                  double *RESTRICT _data_u_20_32 =
                      _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                  double *RESTRICT _data_u_20_32_10 =
                      _stride_u_1 * ctr_1 + _data_u_20_32;
                  double *RESTRICT _data_rho_21_30 =
                      _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                  double *RESTRICT _data_rho_21_30_11 =
                      _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_21_30;
                  double *RESTRICT _data_u_21_30 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                  double *RESTRICT _data_u_21_30_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_30;
                  double *RESTRICT _data_u_21_31 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                  double *RESTRICT _data_u_21_31_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_31;
                  double *RESTRICT _data_u_21_32 =
                      _data_u + _stride_u_2 * ctr_2 + _stride_u_2 +
                      2 * _stride_u_3;
                  double *RESTRICT _data_u_21_32_11 =
                      _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_21_32;
                  _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)] =
                      -((0.0 >
                             _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                         0.0 <
                             _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                         0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                            ? (1.0)
                            : (0.0)) *
                          _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                          _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                          _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                      ((0.0 > _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                        0.0 > _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                        0.0 < _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                          _data_rho_21_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                          _data_u_21_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                          _data_u_21_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                          _data_u_21_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] +
                      _data_j_20_312_10[_stride_j_0 * (_size_j_0 - 1)];
                }
              }
            }
          }
          {
            {
              if (_size_j_0 > 2 && _size_j_1 > 1 && ctr_2 > 0 &&
                  _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_31 =
                    _data_j + _stride_j_2 * ctr_2 + _stride_j_3;
                double *RESTRICT _data_j_20_31_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_31;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_20_30;
                double *RESTRICT _data_u_20_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_31;
                _data_j_20_31_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        (1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0]) ? (1.0)
                                                               : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_31_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_20_30_1m1[_stride_u_0])) *
                        (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0])) *
                        ((0.0 < _data_u_20_31_1m1[_stride_u_0]) ? (1.0)
                                                                : (0.0)) *
                        _data_rho_20_30_1m1[_stride_rho_0] *
                        _data_u_20_31_1m1[_stride_u_0] +
                    _data_j_20_31_10[_stride_j_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_33 =
                    _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                double *RESTRICT _data_j_20_33_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_33;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_20_30;
                double *RESTRICT _data_u_20_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_31;
                _data_j_20_33_10[_stride_j_0] =
                    (1.0 - fabs(_data_u_20_32_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                          0.0 > _data_u_20_31_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_20_32_1m1[0])) *
                        ((0.0 < _data_u_20_30_1m1[0] &&
                          0.0 < _data_u_20_31_1m1[0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_1m1[0] * _data_u_20_30_1m1[0] *
                        _data_u_20_31_1m1[0] +
                    _data_j_20_33_10[_stride_j_0];
              }
              if (_size_j_0 > 2 && _size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_37 =
                    _data_j + _stride_j_2 * ctr_2 + 7 * _stride_j_3;
                double *RESTRICT _data_j_20_37_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_37;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_30;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_32;
                _data_j_20_37_10[_stride_j_0] =
                    (1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0])) *
                        ((0.0 < _data_u_2m1_31_1m1[_stride_u_0] &&
                          0.0 < _data_u_2m1_32_1m1[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0] *
                        _data_u_2m1_31_1m1[_stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0] +
                    _data_j_20_37_10[_stride_j_0];
              }
              if (_size_j_0 > 2 && _size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_38 =
                    _data_j + _stride_j_2 * ctr_2 + 8 * _stride_j_3;
                double *RESTRICT _data_j_20_38_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_38;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                _data_j_20_38_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0])) *
                        ((0.0 > _data_u_21_32_1m1[_stride_u_0] &&
                          0.0 < _data_u_21_31_1m1[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0] *
                        _data_u_21_31_1m1[_stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0] +
                    _data_j_20_38_10[_stride_j_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                       0.0 > _data_u_20_31_10[_stride_u_0] &&
                       0.0 > _data_u_20_32_10[_stride_u_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    ((0.0 < _data_u_2m1_30_1m1[0] &&
                      0.0 < _data_u_2m1_31_1m1[0] &&
                      0.0 < _data_u_2m1_32_1m1[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[0] * _data_u_2m1_30_1m1[0] *
                        _data_u_2m1_31_1m1[0] * _data_u_2m1_32_1m1[0] +
                    _data_j_20_39_10[_stride_j_0];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_310 =
                    _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                      0.0 > _data_u_20_31_10[_stride_u_0] &&
                      0.0 < _data_u_20_32_10[_stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    ((0.0 > _data_u_21_32_1m1[0] &&
                      0.0 < _data_u_21_30_1m1[0] && 0.0 < _data_u_21_31_1m1[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[0] * _data_u_21_30_1m1[0] *
                        _data_u_21_31_1m1[0] * _data_u_21_32_1m1[0] +
                    _data_j_20_310_10[_stride_j_0];
              }
            }
            for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_0 - ctr_0 > 1 &&
                  _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_31 =
                    _data_j + _stride_j_2 * ctr_2 + _stride_j_3;
                double *RESTRICT _data_j_20_31_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_31;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_20_30;
                double *RESTRICT _data_u_20_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_31;
                _data_j_20_31_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_20_30_1m1[_stride_u_0 * ctr_0])) *
                        (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0 * ctr_0])) *
                        ((0.0 < _data_u_20_31_1m1[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_1m1[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_1m1[_stride_u_0 * ctr_0] +
                    _data_j_20_31_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_33 =
                    _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                double *RESTRICT _data_j_20_33_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_33;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_20_30;
                double *RESTRICT _data_u_20_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_31;
                _data_j_20_33_10[_stride_j_0 * ctr_0] =
                    (1.0 - fabs(_data_u_20_32_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                          0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_20_32_1m1[_stride_u_0 * ctr_0 -
                                                  _stride_u_0])) *
                        ((0.0 < _data_u_20_30_1m1[_stride_u_0 * ctr_0 -
                                                  _stride_u_0] &&
                          0.0 < _data_u_20_31_1m1[_stride_u_0 * ctr_0 -
                                                  _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_1m1[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_20_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_20_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_33_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_0 - ctr_0 > 1) {
                double *RESTRICT _data_j_20_37 =
                    _data_j + _stride_j_2 * ctr_2 + 7 * _stride_j_3;
                double *RESTRICT _data_j_20_37_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_37;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_30;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_32;
                _data_j_20_37_10[_stride_j_0 * ctr_0] =
                    (1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0 * ctr_0])) *
                        ((0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * ctr_0] +
                    _data_j_20_37_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && _size_j_0 - ctr_0 > 1 &&
                  _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_38 =
                    _data_j + _stride_j_2 * ctr_2 + 8 * _stride_j_3;
                double *RESTRICT _data_j_20_38_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_38;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                _data_j_20_38_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    (1.0 - fabs(_data_u_21_30_1m1[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_21_31_1m1[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * ctr_0] *
                        _data_u_21_31_1m1[_stride_u_0 * ctr_0] *
                        _data_u_21_32_1m1[_stride_u_0 * ctr_0] +
                    _data_j_20_38_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0 * ctr_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                       0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                       0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                      0.0 <
                          _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                        _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_39_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_310 =
                    _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0 * ctr_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                      0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                      0.0 < _data_u_20_32_10[_stride_u_0 * ctr_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    ((0.0 > _data_u_21_32_1m1[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_30_1m1[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 <
                          _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_21_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_310_10[_stride_j_0 * ctr_0];
              }
            }
            {
              if (_size_j_1 > 1 && ctr_2 > 0 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_33 =
                    _data_j + _stride_j_2 * ctr_2 + 3 * _stride_j_3;
                double *RESTRICT _data_j_20_33_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_33;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_32;
                double *RESTRICT _data_rho_20_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_20_30;
                double *RESTRICT _data_u_20_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_20_31;
                _data_j_20_33_10[_stride_j_0 * (_size_j_0 - 1)] =
                    (1.0 -
                     fabs(_data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])) *
                        ((0.0 >
                              _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                          0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] -
                    (1.0 -
                     fabs(_data_u_20_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0])) *
                        ((0.0 <
                              _data_u_20_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                          0.0 <
                              _data_u_20_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_20_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_20_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_33_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_1 > 1 && ctr_2 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * ctr_2 + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * ctr_2 - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * ctr_2 - _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 = _data_u +
                                                  _stride_u_2 * ctr_2 -
                                                  _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 +
                    _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                    ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                        _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] +
                    _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_1 > 1 && _size_j_2 - ctr_2 > 1) {
                double *RESTRICT _data_j_20_310 =
                    _data_j + _stride_j_2 * ctr_2 + 10 * _stride_j_3;
                double *RESTRICT _data_j_20_310_10 =
                    _stride_j_1 * (_size_j_1 - 1) + _data_j_20_310;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * ctr_2;
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 = _data_u + _stride_u_2 * ctr_2;
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * ctr_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
                double *RESTRICT _data_rho_21_30 =
                    _data_rho + _stride_rho_2 * ctr_2 + _stride_rho_2;
                double *RESTRICT _data_rho_21_30_1m1 =
                    _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                    _data_rho_21_30;
                double *RESTRICT _data_u_21_30 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2;
                double *RESTRICT _data_u_21_30_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_30;
                double *RESTRICT _data_u_21_31 =
                    _data_u + _stride_u_2 * ctr_2 + _stride_u_2 + _stride_u_3;
                double *RESTRICT _data_u_21_31_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_31;
                double *RESTRICT _data_u_21_32 = _data_u + _stride_u_2 * ctr_2 +
                                                 _stride_u_2 + 2 * _stride_u_3;
                double *RESTRICT _data_u_21_32_1m1 =
                    _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_21_32;
                _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 < _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                    ((0.0 > _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_21_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_21_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_21_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_21_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_310_10[_stride_j_0 * (_size_j_0 - 1)];
              }
            }
          }
        }
      }
      {
        {
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_311 =
                _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
            double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
            double *RESTRICT _data_rho_2m1_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
            double *RESTRICT _data_rho_2m1_30_11 =
                _stride_rho_1 + _data_rho_2m1_30;
            double *RESTRICT _data_u_2m1_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
            double *RESTRICT _data_u_2m1_30_11 = _stride_u_1 + _data_u_2m1_30;
            double *RESTRICT _data_u_2m1_31 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_2m1_31_11 = _stride_u_1 + _data_u_2m1_31;
            double *RESTRICT _data_u_2m1_32 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_2m1_32_11 = _stride_u_1 + _data_u_2m1_32;
            double *RESTRICT _data_rho_20_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1);
            double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
            double *RESTRICT _data_u_20_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1);
            double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
            double *RESTRICT _data_u_20_31 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
            double *RESTRICT _data_u_20_32 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
            _data_j_20_311_10[_stride_j_0] =
                ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                  0.0 > _data_u_20_32_10[_stride_u_0] &&
                  0.0 < _data_u_20_31_10[_stride_u_0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0] *
                    _data_u_20_30_10[_stride_u_0] *
                    _data_u_20_31_10[_stride_u_0] *
                    _data_u_20_32_10[_stride_u_0] +
                ((0.0 > _data_u_2m1_31_11[0] && 0.0 < _data_u_2m1_30_11[0] &&
                  0.0 < _data_u_2m1_32_11[0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_2m1_30_11[0] * _data_u_2m1_30_11[0] *
                    _data_u_2m1_31_11[0] * _data_u_2m1_32_11[0] +
                _data_j_20_311_10[_stride_j_0];
          }
#pragma omp for schedule(static)
          for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_311 =
                  _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
              double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
              double *RESTRICT _data_rho_2m1_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
              double *RESTRICT _data_rho_2m1_30_11 =
                  _stride_rho_1 + _data_rho_2m1_30;
              double *RESTRICT _data_u_2m1_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
              double *RESTRICT _data_u_2m1_30_11 = _stride_u_1 + _data_u_2m1_30;
              double *RESTRICT _data_u_2m1_31 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_2m1_31_11 = _stride_u_1 + _data_u_2m1_31;
              double *RESTRICT _data_u_2m1_32 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_2m1_32_11 = _stride_u_1 + _data_u_2m1_32;
              double *RESTRICT _data_rho_20_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1);
              double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
              double *RESTRICT _data_u_20_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1);
              double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
              double *RESTRICT _data_u_20_31 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
              double *RESTRICT _data_u_20_32 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
              _data_j_20_311_10[_stride_j_0 * ctr_0] =
                  ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                    0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0] &&
                    0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_30_10[_stride_u_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] +
                  ((0.0 >
                        _data_u_2m1_31_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 <
                        _data_u_2m1_30_11[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 < _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_2m1_30_11[_stride_rho_0 * ctr_0 -
                                          _stride_rho_0] *
                      _data_u_2m1_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_2m1_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                  _data_j_20_311_10[_stride_j_0 * ctr_0];
            }
          }
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_311 =
                _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
            double *RESTRICT _data_j_20_311_10 = _data_j_20_311;
            double *RESTRICT _data_rho_2m1_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
            double *RESTRICT _data_rho_2m1_30_11 =
                _stride_rho_1 + _data_rho_2m1_30;
            double *RESTRICT _data_u_2m1_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
            double *RESTRICT _data_u_2m1_30_11 = _stride_u_1 + _data_u_2m1_30;
            double *RESTRICT _data_u_2m1_31 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_2m1_31_11 = _stride_u_1 + _data_u_2m1_31;
            double *RESTRICT _data_u_2m1_32 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_2m1_32_11 = _stride_u_1 + _data_u_2m1_32;
            double *RESTRICT _data_rho_20_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1);
            double *RESTRICT _data_rho_20_30_10 = _data_rho_20_30;
            double *RESTRICT _data_u_20_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1);
            double *RESTRICT _data_u_20_30_10 = _data_u_20_30;
            double *RESTRICT _data_u_20_31 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 = _data_u_20_31;
            double *RESTRICT _data_u_20_32 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 = _data_u_20_32;
            _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)] =
                ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                  0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] &&
                  0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                    _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                ((0.0 > _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] &&
                  0.0 < _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] &&
                  0.0 < _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_2m1_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                        _stride_rho_0] *
                    _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] *
                    _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] *
                    _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                      _stride_u_0] +
                _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)];
          }
        }
#pragma omp for schedule(static)
        for (int64_t ctr_1 = 1; ctr_1 < _size_j_1 - 1; ctr_1 += 1) {
          {
            {
              if (_size_j_0 > 2 && _size_j_2 > 1 && ctr_1 > 0 &&
                  _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_32 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 2 * _stride_j_3;
                double *RESTRICT _data_j_20_32_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_31;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_32;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_32_10[_stride_j_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        (1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_32_10[_stride_u_0]) ? (1.0)
                                                               : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_2m1_30_10[_stride_u_0])) *
                        (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0])) *
                        ((0.0 < _data_u_2m1_32_10[_stride_u_0]) ? (1.0)
                                                                : (0.0)) *
                        _data_rho_2m1_30_10[_stride_rho_0] *
                        _data_u_2m1_32_10[_stride_u_0] +
                    _data_j_20_32_10[_stride_j_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_35 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 5 * _stride_j_3;
                double *RESTRICT _data_j_20_35_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_35;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_31;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_32;
                _data_j_20_35_10[_stride_j_0] =
                    (1.0 - fabs(_data_u_20_31_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_2m1_31_10[0])) *
                        ((0.0 < _data_u_2m1_30_10[0] &&
                          0.0 < _data_u_2m1_32_10[0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_10[0] * _data_u_2m1_30_10[0] *
                        _data_u_2m1_32_10[0] +
                    _data_j_20_35_10[_stride_j_0];
              }
              if (_size_j_0 > 2 && _size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_37 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 7 * _stride_j_3;
                double *RESTRICT _data_j_20_37_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_37;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                _data_j_20_37_10[_stride_j_0] =
                    (1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0])) *
                        ((0.0 < _data_u_2m1_31_1m1[_stride_u_0] &&
                          0.0 < _data_u_2m1_32_1m1[_stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0] *
                        _data_u_2m1_31_1m1[_stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0] +
                    _data_j_20_37_10[_stride_j_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                       0.0 > _data_u_20_31_10[_stride_u_0] &&
                       0.0 > _data_u_20_32_10[_stride_u_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] -
                    ((0.0 < _data_u_2m1_30_1m1[0] &&
                      0.0 < _data_u_2m1_31_1m1[0] &&
                      0.0 < _data_u_2m1_32_1m1[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[0] * _data_u_2m1_30_1m1[0] *
                        _data_u_2m1_31_1m1[0] * _data_u_2m1_32_1m1[0] +
                    _data_j_20_39_10[_stride_j_0];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_311_10[_stride_j_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0] &&
                      0.0 > _data_u_20_32_10[_stride_u_0] &&
                      0.0 < _data_u_20_31_10[_stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0] *
                        _data_u_20_30_10[_stride_u_0] *
                        _data_u_20_31_10[_stride_u_0] *
                        _data_u_20_32_10[_stride_u_0] +
                    ((0.0 > _data_u_2m1_31_11[0] &&
                      0.0 < _data_u_2m1_30_11[0] && 0.0 < _data_u_2m1_32_11[0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[0] * _data_u_2m1_30_11[0] *
                        _data_u_2m1_31_11[0] * _data_u_2m1_32_11[0] +
                    _data_j_20_311_10[_stride_j_0];
              }
            }
            for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_0 - ctr_0 > 1 &&
                  _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_32 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 2 * _stride_j_3;
                double *RESTRICT _data_j_20_32_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_31;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_32;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_32_10[_stride_j_0 * ctr_0] =
                    -(1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        (1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_2m1_30_10[_stride_u_0 * ctr_0])) *
                        (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0 * ctr_0])) *
                        ((0.0 < _data_u_2m1_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_2m1_32_10[_stride_u_0 * ctr_0] +
                    _data_j_20_32_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_35 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 5 * _stride_j_3;
                double *RESTRICT _data_j_20_35_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_35;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_31;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_32;
                _data_j_20_35_10[_stride_j_0 * ctr_0] =
                    (1.0 - fabs(_data_u_20_31_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_2m1_31_10[_stride_u_0 * ctr_0 -
                                                  _stride_u_0])) *
                        ((0.0 < _data_u_2m1_30_10[_stride_u_0 * ctr_0 -
                                                  _stride_u_0] &&
                          0.0 < _data_u_2m1_32_10[_stride_u_0 * ctr_0 -
                                                  _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_10[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_2m1_30_10[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_32_10[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_35_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_0 - ctr_0 > 1) {
                double *RESTRICT _data_j_20_37 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 7 * _stride_j_3;
                double *RESTRICT _data_j_20_37_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_37;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                _data_j_20_37_10[_stride_j_0 * ctr_0] =
                    (1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                        ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                          0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0 * ctr_0])) *
                        ((0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] &&
                          0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * ctr_0] +
                    _data_j_20_37_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0 * ctr_0] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                       0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                       0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] -
                    ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 -
                                               _stride_u_0] &&
                      0.0 <
                          _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0 -
                                             _stride_rho_0] *
                        _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_39_10[_stride_j_0 * ctr_0];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_311_10[_stride_j_0 * ctr_0] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                      0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0] &&
                      0.0 < _data_u_20_31_10[_stride_u_0 * ctr_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                        _data_u_20_30_10[_stride_u_0 * ctr_0] *
                        _data_u_20_31_10[_stride_u_0 * ctr_0] *
                        _data_u_20_32_10[_stride_u_0 * ctr_0] +
                    ((0.0 > _data_u_2m1_31_11[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_30_11[_stride_u_0 * ctr_0 -
                                              _stride_u_0] &&
                      0.0 <
                          _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[_stride_rho_0 * ctr_0 -
                                            _stride_rho_0] *
                        _data_u_2m1_30_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_31_11[_stride_u_0 * ctr_0 - _stride_u_0] *
                        _data_u_2m1_32_11[_stride_u_0 * ctr_0 - _stride_u_0] +
                    _data_j_20_311_10[_stride_j_0 * ctr_0];
              }
            }
            {
              if (_size_j_2 > 1 && ctr_1 > 0 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_35 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 5 * _stride_j_3;
                double *RESTRICT _data_j_20_35_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_35;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_31;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_2m1_32;
                _data_j_20_35_10[_stride_j_0 * (_size_j_0 - 1)] =
                    (1.0 -
                     fabs(_data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])) *
                        ((0.0 >
                              _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                          0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                    (1.0 -
                     fabs(_data_u_2m1_31_10[_stride_u_0 * (_size_j_0 - 1) -
                                            _stride_u_0])) *
                        ((0.0 <
                              _data_u_2m1_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0] &&
                          0.0 <
                              _data_u_2m1_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                                _stride_u_0])
                             ? (1.0)
                             : (0.0)) *
                        _data_rho_2m1_30_10[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_2m1_30_10[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_2m1_32_10[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_35_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_2 > 1 && ctr_1 > 0) {
                double *RESTRICT _data_j_20_39 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
                double *RESTRICT _data_j_20_39_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_39;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_1m1 =
                    _stride_rho_1 * ctr_1 - _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_1m1 =
                    _stride_u_1 * ctr_1 - _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)] =
                    -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                       0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                          ? (1.0)
                          : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                    ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0] &&
                      0.0 < _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                               _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                             _stride_rho_0] *
                        _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                        _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] *
                        _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] +
                    _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)];
              }
              if (_size_j_2 > 1 && _size_j_1 - ctr_1 > 1) {
                double *RESTRICT _data_j_20_311 =
                    _data_j + _stride_j_2 * (_size_j_2 - 1) + 11 * _stride_j_3;
                double *RESTRICT _data_j_20_311_10 =
                    _stride_j_1 * ctr_1 + _data_j_20_311;
                double *RESTRICT _data_rho_2m1_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
                double *RESTRICT _data_rho_2m1_30_11 =
                    _stride_rho_1 * ctr_1 + _stride_rho_1 + _data_rho_2m1_30;
                double *RESTRICT _data_u_2m1_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
                double *RESTRICT _data_u_2m1_30_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_30;
                double *RESTRICT _data_u_2m1_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    _stride_u_3;
                double *RESTRICT _data_u_2m1_31_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_31;
                double *RESTRICT _data_u_2m1_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2 +
                    2 * _stride_u_3;
                double *RESTRICT _data_u_2m1_32_11 =
                    _stride_u_1 * ctr_1 + _stride_u_1 + _data_u_2m1_32;
                double *RESTRICT _data_rho_20_30 =
                    _data_rho + _stride_rho_2 * (_size_j_2 - 1);
                double *RESTRICT _data_rho_20_30_10 =
                    _stride_rho_1 * ctr_1 + _data_rho_20_30;
                double *RESTRICT _data_u_20_30 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1);
                double *RESTRICT _data_u_20_30_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_30;
                double *RESTRICT _data_u_20_31 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
                double *RESTRICT _data_u_20_31_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_31;
                double *RESTRICT _data_u_20_32 =
                    _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
                double *RESTRICT _data_u_20_32_10 =
                    _stride_u_1 * ctr_1 + _data_u_20_32;
                _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)] =
                    ((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] &&
                      0.0 < _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                        _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                        _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] +
                    ((0.0 > _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0] &&
                      0.0 < _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                              _stride_u_0])
                         ? (1.0)
                         : (0.0)) *
                        _data_rho_2m1_30_11[_stride_rho_0 * (_size_j_0 - 1) -
                                            _stride_rho_0] *
                        _data_u_2m1_30_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_2m1_31_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] *
                        _data_u_2m1_32_11[_stride_u_0 * (_size_j_0 - 1) -
                                          _stride_u_0] +
                    _data_j_20_311_10[_stride_j_0 * (_size_j_0 - 1)];
              }
            }
          }
        }
        {
          {
            if (_size_j_0 > 2 && _size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_37 =
                  _data_j + _stride_j_2 * (_size_j_2 - 1) + 7 * _stride_j_3;
              double *RESTRICT _data_j_20_37_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_37;
              double *RESTRICT _data_u_20_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1);
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_rho_20_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1);
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_31 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              double *RESTRICT _data_u_2m1_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
              double *RESTRICT _data_u_2m1_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_30;
              double *RESTRICT _data_rho_2m1_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
              double *RESTRICT _data_rho_2m1_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_2m1_30;
              double *RESTRICT _data_u_2m1_31 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_2m1_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_31;
              double *RESTRICT _data_u_2m1_32 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_2m1_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_32;
              _data_j_20_37_10[_stride_j_0] =
                  (1.0 - fabs(_data_u_20_30_10[_stride_u_0])) *
                      ((0.0 > _data_u_20_31_10[_stride_u_0] &&
                        0.0 > _data_u_20_32_10[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0] *
                      _data_u_20_31_10[_stride_u_0] *
                      _data_u_20_32_10[_stride_u_0] -
                  (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0])) *
                      ((0.0 < _data_u_2m1_31_1m1[_stride_u_0] &&
                        0.0 < _data_u_2m1_32_1m1[_stride_u_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_2m1_30_1m1[_stride_rho_0] *
                      _data_u_2m1_31_1m1[_stride_u_0] *
                      _data_u_2m1_32_1m1[_stride_u_0] +
                  _data_j_20_37_10[_stride_j_0];
            }
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_39 =
                  _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
              double *RESTRICT _data_j_20_39_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
              double *RESTRICT _data_rho_2m1_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
              double *RESTRICT _data_rho_2m1_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_2m1_30;
              double *RESTRICT _data_u_2m1_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
              double *RESTRICT _data_u_2m1_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_30;
              double *RESTRICT _data_u_2m1_31 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_2m1_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_31;
              double *RESTRICT _data_u_2m1_32 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_2m1_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_32;
              double *RESTRICT _data_rho_20_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1);
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1);
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_u_20_31 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              _data_j_20_39_10[_stride_j_0] =
                  -((0.0 > _data_u_20_30_10[_stride_u_0] &&
                     0.0 > _data_u_20_31_10[_stride_u_0] &&
                     0.0 > _data_u_20_32_10[_stride_u_0])
                        ? (1.0)
                        : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0] *
                      _data_u_20_30_10[_stride_u_0] *
                      _data_u_20_31_10[_stride_u_0] *
                      _data_u_20_32_10[_stride_u_0] -
                  ((0.0 < _data_u_2m1_30_1m1[0] &&
                    0.0 < _data_u_2m1_31_1m1[0] && 0.0 < _data_u_2m1_32_1m1[0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_2m1_30_1m1[0] * _data_u_2m1_30_1m1[0] *
                      _data_u_2m1_31_1m1[0] * _data_u_2m1_32_1m1[0] +
                  _data_j_20_39_10[_stride_j_0];
            }
          }
#pragma omp for schedule(static)
          for (int64_t ctr_0 = 2; ctr_0 < _size_j_0 - 1; ctr_0 += 1) {
            if (_size_j_1 > 1 && _size_j_2 > 1 && _size_j_0 - ctr_0 > 1) {
              double *RESTRICT _data_j_20_37 =
                  _data_j + _stride_j_2 * (_size_j_2 - 1) + 7 * _stride_j_3;
              double *RESTRICT _data_j_20_37_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_37;
              double *RESTRICT _data_u_20_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1);
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_rho_20_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1);
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_31 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              double *RESTRICT _data_u_2m1_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
              double *RESTRICT _data_u_2m1_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_30;
              double *RESTRICT _data_rho_2m1_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
              double *RESTRICT _data_rho_2m1_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_2m1_30;
              double *RESTRICT _data_u_2m1_31 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_2m1_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_31;
              double *RESTRICT _data_u_2m1_32 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_2m1_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_32;
              _data_j_20_37_10[_stride_j_0 * ctr_0] =
                  (1.0 - fabs(_data_u_20_30_10[_stride_u_0 * ctr_0])) *
                      ((0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                        0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] -
                  (1.0 - fabs(_data_u_2m1_30_1m1[_stride_u_0 * ctr_0])) *
                      ((0.0 < _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] &&
                        0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0])
                           ? (1.0)
                           : (0.0)) *
                      _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0] *
                      _data_u_2m1_31_1m1[_stride_u_0 * ctr_0] *
                      _data_u_2m1_32_1m1[_stride_u_0 * ctr_0] +
                  _data_j_20_37_10[_stride_j_0 * ctr_0];
            }
            if (_size_j_1 > 1 && _size_j_2 > 1) {
              double *RESTRICT _data_j_20_39 =
                  _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
              double *RESTRICT _data_j_20_39_10 =
                  _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
              double *RESTRICT _data_rho_2m1_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
              double *RESTRICT _data_rho_2m1_30_1m1 =
                  _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                  _data_rho_2m1_30;
              double *RESTRICT _data_u_2m1_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
              double *RESTRICT _data_u_2m1_30_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_30;
              double *RESTRICT _data_u_2m1_31 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + _stride_u_3;
              double *RESTRICT _data_u_2m1_31_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_31;
              double *RESTRICT _data_u_2m1_32 = _data_u +
                                                _stride_u_2 * (_size_j_2 - 1) -
                                                _stride_u_2 + 2 * _stride_u_3;
              double *RESTRICT _data_u_2m1_32_1m1 =
                  _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_32;
              double *RESTRICT _data_rho_20_30 =
                  _data_rho + _stride_rho_2 * (_size_j_2 - 1);
              double *RESTRICT _data_rho_20_30_10 =
                  _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
              double *RESTRICT _data_u_20_30 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1);
              double *RESTRICT _data_u_20_30_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
              double *RESTRICT _data_u_20_31 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
              double *RESTRICT _data_u_20_31_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
              double *RESTRICT _data_u_20_32 =
                  _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
              double *RESTRICT _data_u_20_32_10 =
                  _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
              _data_j_20_39_10[_stride_j_0 * ctr_0] =
                  -((0.0 > _data_u_20_30_10[_stride_u_0 * ctr_0] &&
                     0.0 > _data_u_20_31_10[_stride_u_0 * ctr_0] &&
                     0.0 > _data_u_20_32_10[_stride_u_0 * ctr_0])
                        ? (1.0)
                        : (0.0)) *
                      _data_rho_20_30_10[_stride_rho_0 * ctr_0] *
                      _data_u_20_30_10[_stride_u_0 * ctr_0] *
                      _data_u_20_31_10[_stride_u_0 * ctr_0] *
                      _data_u_20_32_10[_stride_u_0 * ctr_0] -
                  ((0.0 <
                        _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 <
                        _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] &&
                    0.0 < _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0])
                       ? (1.0)
                       : (0.0)) *
                      _data_rho_2m1_30_1m1[_stride_rho_0 * ctr_0 -
                                           _stride_rho_0] *
                      _data_u_2m1_30_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_2m1_31_1m1[_stride_u_0 * ctr_0 - _stride_u_0] *
                      _data_u_2m1_32_1m1[_stride_u_0 * ctr_0 - _stride_u_0] +
                  _data_j_20_39_10[_stride_j_0 * ctr_0];
            }
          }
          if (_size_j_1 > 1 && _size_j_2 > 1) {
            double *RESTRICT _data_j_20_39 =
                _data_j + _stride_j_2 * (_size_j_2 - 1) + 9 * _stride_j_3;
            double *RESTRICT _data_j_20_39_10 =
                _stride_j_1 * (_size_j_1 - 1) + _data_j_20_39;
            double *RESTRICT _data_rho_2m1_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1) - _stride_rho_2;
            double *RESTRICT _data_rho_2m1_30_1m1 =
                _stride_rho_1 * (_size_j_1 - 1) - _stride_rho_1 +
                _data_rho_2m1_30;
            double *RESTRICT _data_u_2m1_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) - _stride_u_2;
            double *RESTRICT _data_u_2m1_30_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_30;
            double *RESTRICT _data_u_2m1_31 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + _stride_u_3;
            double *RESTRICT _data_u_2m1_31_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_31;
            double *RESTRICT _data_u_2m1_32 = _data_u +
                                              _stride_u_2 * (_size_j_2 - 1) -
                                              _stride_u_2 + 2 * _stride_u_3;
            double *RESTRICT _data_u_2m1_32_1m1 =
                _stride_u_1 * (_size_j_1 - 1) - _stride_u_1 + _data_u_2m1_32;
            double *RESTRICT _data_rho_20_30 =
                _data_rho + _stride_rho_2 * (_size_j_2 - 1);
            double *RESTRICT _data_rho_20_30_10 =
                _stride_rho_1 * (_size_j_1 - 1) + _data_rho_20_30;
            double *RESTRICT _data_u_20_30 =
                _data_u + _stride_u_2 * (_size_j_2 - 1);
            double *RESTRICT _data_u_20_30_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_30;
            double *RESTRICT _data_u_20_31 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + _stride_u_3;
            double *RESTRICT _data_u_20_31_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_31;
            double *RESTRICT _data_u_20_32 =
                _data_u + _stride_u_2 * (_size_j_2 - 1) + 2 * _stride_u_3;
            double *RESTRICT _data_u_20_32_10 =
                _stride_u_1 * (_size_j_1 - 1) + _data_u_20_32;
            _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)] =
                -((0.0 > _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] &&
                   0.0 > _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] &&
                   0.0 > _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)])
                      ? (1.0)
                      : (0.0)) *
                    _data_rho_20_30_10[_stride_rho_0 * (_size_j_0 - 1)] *
                    _data_u_20_30_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_31_10[_stride_u_0 * (_size_j_0 - 1)] *
                    _data_u_20_32_10[_stride_u_0 * (_size_j_0 - 1)] -
                ((0.0 < _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] &&
                  0.0 < _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0] &&
                  0.0 < _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                           _stride_u_0])
                     ? (1.0)
                     : (0.0)) *
                    _data_rho_2m1_30_1m1[_stride_rho_0 * (_size_j_0 - 1) -
                                         _stride_rho_0] *
                    _data_u_2m1_30_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                       _stride_u_0] *
                    _data_u_2m1_31_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                       _stride_u_0] *
                    _data_u_2m1_32_1m1[_stride_u_0 * (_size_j_0 - 1) -
                                       _stride_u_0] +
                _data_j_20_39_10[_stride_j_0 * (_size_j_0 - 1)];
          }
        }
      }
    }
  }
}
} // namespace internal_advectivefluxkernel_advectivefluxkernel

void AdvectiveFluxKernel::run(IBlock *block) {
  auto rho = block->getData<field::GhostLayerField<double, 1>>(rhoID);
  auto u = block->getData<field::GhostLayerField<double, 3>>(uID);
  auto j = block->getData<field::GhostLayerField<double, 13>>(jID);

  WALBERLA_ASSERT_GREATER_EQUAL(-1, -int_c(j->nrOfGhostLayers()));
  double *RESTRICT _data_j = j->dataAt(-1, -1, -1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(-1, -int_c(rho->nrOfGhostLayers()));
  double *RESTRICT const _data_rho = rho->dataAt(-1, -1, -1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(-1, -int_c(u->nrOfGhostLayers()));
  double *RESTRICT const _data_u = u->dataAt(-1, -1, -1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(j->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(j->xSize()) + 2));
  const int64_t _size_j_0 = int64_t(cell_idx_c(j->xSize()) + 2);
  WALBERLA_ASSERT_GREATER_EQUAL(j->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(j->ySize()) + 2));
  const int64_t _size_j_1 = int64_t(cell_idx_c(j->ySize()) + 2);
  WALBERLA_ASSERT_GREATER_EQUAL(j->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(j->zSize()) + 2));
  const int64_t _size_j_2 = int64_t(cell_idx_c(j->zSize()) + 2);
  const int64_t _stride_j_0 = int64_t(j->xStride());
  const int64_t _stride_j_1 = int64_t(j->yStride());
  const int64_t _stride_j_2 = int64_t(j->zStride());
  const int64_t _stride_j_3 = int64_t(1 * int64_t(j->fStride()));
  const int64_t _stride_rho_0 = int64_t(rho->xStride());
  const int64_t _stride_rho_1 = int64_t(rho->yStride());
  const int64_t _stride_rho_2 = int64_t(rho->zStride());
  const int64_t _stride_u_0 = int64_t(u->xStride());
  const int64_t _stride_u_1 = int64_t(u->yStride());
  const int64_t _stride_u_2 = int64_t(u->zStride());
  const int64_t _stride_u_3 = int64_t(1 * int64_t(u->fStride()));
  internal_advectivefluxkernel_advectivefluxkernel::
      advectivefluxkernel_advectivefluxkernel(
          _data_j, _data_rho, _data_u, _size_j_0, _size_j_1, _size_j_2,
          _stride_j_0, _stride_j_1, _stride_j_2, _stride_j_3, _stride_rho_0,
          _stride_rho_1, _stride_rho_2, _stride_u_0, _stride_u_1, _stride_u_2,
          _stride_u_3);
}

void AdvectiveFluxKernel::runOnCellInterval(
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

  auto rho = block->getData<field::GhostLayerField<double, 1>>(rhoID);
  auto u = block->getData<field::GhostLayerField<double, 3>>(uID);
  auto j = block->getData<field::GhostLayerField<double, 13>>(jID);

  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin() - 1, -int_c(j->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin() - 1, -int_c(j->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin() - 1, -int_c(j->nrOfGhostLayers()));
  double *RESTRICT _data_j =
      j->dataAt(ci.xMin() - 1, ci.yMin() - 1, ci.zMin() - 1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin() - 1, -int_c(rho->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin() - 1, -int_c(rho->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin() - 1, -int_c(rho->nrOfGhostLayers()));
  double *RESTRICT const _data_rho =
      rho->dataAt(ci.xMin() - 1, ci.yMin() - 1, ci.zMin() - 1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin() - 1, -int_c(u->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin() - 1, -int_c(u->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin() - 1, -int_c(u->nrOfGhostLayers()));
  double *RESTRICT const _data_u =
      u->dataAt(ci.xMin() - 1, ci.yMin() - 1, ci.zMin() - 1, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(j->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.xSize()) + 2));
  const int64_t _size_j_0 = int64_t(cell_idx_c(ci.xSize()) + 2);
  WALBERLA_ASSERT_GREATER_EQUAL(j->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.ySize()) + 2));
  const int64_t _size_j_1 = int64_t(cell_idx_c(ci.ySize()) + 2);
  WALBERLA_ASSERT_GREATER_EQUAL(j->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.zSize()) + 2));
  const int64_t _size_j_2 = int64_t(cell_idx_c(ci.zSize()) + 2);
  const int64_t _stride_j_0 = int64_t(j->xStride());
  const int64_t _stride_j_1 = int64_t(j->yStride());
  const int64_t _stride_j_2 = int64_t(j->zStride());
  const int64_t _stride_j_3 = int64_t(1 * int64_t(j->fStride()));
  const int64_t _stride_rho_0 = int64_t(rho->xStride());
  const int64_t _stride_rho_1 = int64_t(rho->yStride());
  const int64_t _stride_rho_2 = int64_t(rho->zStride());
  const int64_t _stride_u_0 = int64_t(u->xStride());
  const int64_t _stride_u_1 = int64_t(u->yStride());
  const int64_t _stride_u_2 = int64_t(u->zStride());
  const int64_t _stride_u_3 = int64_t(1 * int64_t(u->fStride()));
  internal_advectivefluxkernel_advectivefluxkernel::
      advectivefluxkernel_advectivefluxkernel(
          _data_j, _data_rho, _data_u, _size_j_0, _size_j_1, _size_j_2,
          _stride_j_0, _stride_j_1, _stride_j_2, _stride_j_3, _stride_rho_0,
          _stride_rho_1, _stride_rho_2, _stride_u_0, _stride_u_1, _stride_u_2,
          _stride_u_3);
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
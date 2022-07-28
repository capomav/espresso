// kernel generated with pystencils v1.0+12.g54b91e2, lbmpy v1.0+8.gac750b5,
// lbmpy_walberla/pystencils_walberla from commit
// e1fe2ad1dcbe8f31ea79d95e8a5a5cc0ee3691f3

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
//! \\file CollideSweepSinglePrecisionThermalizedAVX.cpp
//! \\ingroup lbm
//! \\author lbmpy
//======================================================================================================================

#include <cmath>

#include "CollideSweepSinglePrecisionThermalizedAVX.h"
#include "core/DataTypes.h"
#include "core/Macros.h"

#include "philox_rand.h"

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

namespace internal_48c9ee502281a70505dce0378c55abd5 {
static FUNC_PREFIX void
collidesweepsingleprecisionthermalizedavx_collidesweepsingleprecisionthermalizedavx(
    float *RESTRICT const _data_force, float *RESTRICT _data_pdfs,
    int64_t const _size_force_0, int64_t const _size_force_1,
    int64_t const _size_force_2, int64_t const _stride_force_1,
    int64_t const _stride_force_2, int64_t const _stride_force_3,
    int64_t const _stride_pdfs_1, int64_t const _stride_pdfs_2,
    int64_t const _stride_pdfs_3, uint32_t block_offset_0,
    uint32_t block_offset_1, uint32_t block_offset_2, float kT,
    float omega_bulk, float omega_even, float omega_odd, float omega_shear,
    float rho, uint32_t seed, uint32_t time_step) {
  const float xi_22 = omega_shear * -0.5f + 1.0f;
  const float xi_59 = kT * rho;
  const float xi_60 = powf(xi_59 * (-1.0f * ((omega_even * -1.0f + 1.0f) *
                                             (omega_even * -1.0f + 1.0f)) +
                                    1.0f),
                           0.5f);
  const float xi_63 = 2.4494897427831779f;
  const float xi_67 = powf(xi_59 * (-1.0f * ((omega_odd * -1.0f + 1.0f) *
                                             (omega_odd * -1.0f + 1.0f)) +
                                    1.0f),
                           0.5f);
  const float xi_68 = xi_67 * 1.4142135623730951f;
  const float xi_69 = xi_68 * 0.5f;
  const float xi_72 = xi_63 * xi_67;
  const float xi_73 = xi_72 * 0.16666666666666666f;
  const float xi_78 = powf(xi_59 * (-1.0f * ((omega_shear * -1.0f + 1.0f) *
                                             (omega_shear * -1.0f + 1.0f)) +
                                    1.0f),
                           0.5f);
  const float xi_79 = xi_78 * 0.5f;
  const float xi_107 = xi_72 * 0.083333333333333329f;
  const float xi_110 = xi_68 * 0.25f;
  for (int64_t ctr_2 = 0; ctr_2 < _size_force_2; ctr_2 += 1) {
    float *RESTRICT _data_pdfs_20_38 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 8 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_318 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 18 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_36 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 6 * _stride_pdfs_3;
    float *RESTRICT _data_force_20_32 =
        _data_force + _stride_force_2 * ctr_2 + 2 * _stride_force_3;
    float *RESTRICT _data_pdfs_20_31 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_313 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 13 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_310 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 10 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_34 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 4 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_32 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 2 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_314 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 14 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_311 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 11 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_33 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 3 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_317 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 17 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_315 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 15 * _stride_pdfs_3;
    float *RESTRICT _data_force_20_30 = _data_force + _stride_force_2 * ctr_2;
    float *RESTRICT _data_pdfs_20_39 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 9 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_37 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 7 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_316 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 16 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_35 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 5 * _stride_pdfs_3;
    float *RESTRICT _data_pdfs_20_30 = _data_pdfs + _stride_pdfs_2 * ctr_2;
    float *RESTRICT _data_force_20_31 =
        _data_force + _stride_force_2 * ctr_2 + _stride_force_3;
    float *RESTRICT _data_pdfs_20_312 =
        _data_pdfs + _stride_pdfs_2 * ctr_2 + 12 * _stride_pdfs_3;
    for (int64_t ctr_1 = 0; ctr_1 < _size_force_1; ctr_1 += 1) {
      float *RESTRICT _data_pdfs_20_38_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_38;
      float *RESTRICT _data_pdfs_20_318_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_318;
      float *RESTRICT _data_pdfs_20_36_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_36;
      float *RESTRICT _data_force_20_32_10 =
          _stride_force_1 * ctr_1 + _data_force_20_32;
      float *RESTRICT _data_pdfs_20_31_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_31;
      float *RESTRICT _data_pdfs_20_313_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_313;
      float *RESTRICT _data_pdfs_20_310_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_310;
      float *RESTRICT _data_pdfs_20_34_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_34;
      float *RESTRICT _data_pdfs_20_32_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_32;
      float *RESTRICT _data_pdfs_20_314_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_314;
      float *RESTRICT _data_pdfs_20_311_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_311;
      float *RESTRICT _data_pdfs_20_33_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_33;
      float *RESTRICT _data_pdfs_20_317_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_317;
      float *RESTRICT _data_pdfs_20_315_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_315;
      float *RESTRICT _data_force_20_30_10 =
          _stride_force_1 * ctr_1 + _data_force_20_30;
      float *RESTRICT _data_pdfs_20_39_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_39;
      float *RESTRICT _data_pdfs_20_37_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_37;
      float *RESTRICT _data_pdfs_20_316_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_316;
      float *RESTRICT _data_pdfs_20_35_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_35;
      float *RESTRICT _data_pdfs_20_30_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_30;
      float *RESTRICT _data_force_20_31_10 =
          _stride_force_1 * ctr_1 + _data_force_20_31;
      float *RESTRICT _data_pdfs_20_312_10 =
          _stride_pdfs_1 * ctr_1 + _data_pdfs_20_312;
      {
        for (int64_t ctr_0 = 0; ctr_0 < (int64_t)((_size_force_0) / (8)) * (8);
             ctr_0 += 8) {
          const __m256 xi_133 = _mm256_load_ps(&_data_pdfs_20_38_10[ctr_0]);
          const __m256 xi_134 = _mm256_load_ps(&_data_pdfs_20_318_10[ctr_0]);
          const __m256 xi_135 = _mm256_load_ps(&_data_pdfs_20_36_10[ctr_0]);
          const __m256 xi_136 = _mm256_load_ps(&_data_force_20_32_10[ctr_0]);
          const __m256 xi_137 = _mm256_load_ps(&_data_pdfs_20_31_10[ctr_0]);
          const __m256 xi_138 = _mm256_load_ps(&_data_pdfs_20_313_10[ctr_0]);
          const __m256 xi_139 = _mm256_load_ps(&_data_pdfs_20_310_10[ctr_0]);
          const __m256 xi_140 = _mm256_load_ps(&_data_pdfs_20_34_10[ctr_0]);
          const __m256 xi_141 = _mm256_load_ps(&_data_pdfs_20_32_10[ctr_0]);
          const __m256 xi_142 = _mm256_load_ps(&_data_pdfs_20_314_10[ctr_0]);
          const __m256 xi_143 = _mm256_load_ps(&_data_pdfs_20_311_10[ctr_0]);
          const __m256 xi_144 = _mm256_load_ps(&_data_pdfs_20_33_10[ctr_0]);
          const __m256 xi_145 = _mm256_load_ps(&_data_pdfs_20_317_10[ctr_0]);
          const __m256 xi_146 = _mm256_load_ps(&_data_pdfs_20_315_10[ctr_0]);
          const __m256 xi_147 = _mm256_load_ps(&_data_force_20_30_10[ctr_0]);
          const __m256 xi_148 = _mm256_load_ps(&_data_pdfs_20_39_10[ctr_0]);
          const __m256 xi_149 = _mm256_load_ps(&_data_pdfs_20_37_10[ctr_0]);
          const __m256 xi_150 = _mm256_load_ps(&_data_pdfs_20_316_10[ctr_0]);
          const __m256 xi_151 = _mm256_load_ps(&_data_pdfs_20_35_10[ctr_0]);
          const __m256 xi_152 = _mm256_load_ps(&_data_pdfs_20_30_10[ctr_0]);
          const __m256 xi_153 = _mm256_load_ps(&_data_force_20_31_10[ctr_0]);
          const __m256 xi_154 = _mm256_load_ps(&_data_pdfs_20_312_10[ctr_0]);

          __m256 random_3_0;
          __m256 random_3_1;
          __m256 random_3_2;
          __m256 random_3_3;
          philox_float4(
              time_step,
              _mm256_add_epi32(
                  _mm256_add_epi32(_mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0),
                                   _mm256_set_epi32(ctr_0, ctr_0, ctr_0, ctr_0,
                                                    ctr_0, ctr_0, ctr_0,
                                                    ctr_0)),
                  _mm256_set_epi32(
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)))),
              block_offset_1 + ctr_1, block_offset_2 + ctr_2, 3, seed,
              random_3_0, random_3_1, random_3_2, random_3_3);

          __m256 random_2_0;
          __m256 random_2_1;
          __m256 random_2_2;
          __m256 random_2_3;
          philox_float4(
              time_step,
              _mm256_add_epi32(
                  _mm256_add_epi32(_mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0),
                                   _mm256_set_epi32(ctr_0, ctr_0, ctr_0, ctr_0,
                                                    ctr_0, ctr_0, ctr_0,
                                                    ctr_0)),
                  _mm256_set_epi32(
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)))),
              block_offset_1 + ctr_1, block_offset_2 + ctr_2, 2, seed,
              random_2_0, random_2_1, random_2_2, random_2_3);

          __m256 random_1_0;
          __m256 random_1_1;
          __m256 random_1_2;
          __m256 random_1_3;
          philox_float4(
              time_step,
              _mm256_add_epi32(
                  _mm256_add_epi32(_mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0),
                                   _mm256_set_epi32(ctr_0, ctr_0, ctr_0, ctr_0,
                                                    ctr_0, ctr_0, ctr_0,
                                                    ctr_0)),
                  _mm256_set_epi32(
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)))),
              block_offset_1 + ctr_1, block_offset_2 + ctr_2, 1, seed,
              random_1_0, random_1_1, random_1_2, random_1_3);

          __m256 random_0_0;
          __m256 random_0_1;
          __m256 random_0_2;
          __m256 random_0_3;
          philox_float4(
              time_step,
              _mm256_add_epi32(
                  _mm256_add_epi32(_mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0),
                                   _mm256_set_epi32(ctr_0, ctr_0, ctr_0, ctr_0,
                                                    ctr_0, ctr_0, ctr_0,
                                                    ctr_0)),
                  _mm256_set_epi32(
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)), ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)),
                      ((int64_t)(block_offset_0)))),
              block_offset_1 + ctr_1, block_offset_2 + ctr_2, 0, seed,
              random_0_0, random_0_1, random_0_2, random_0_3);

          const __m256 xi_0 = _mm256_add_ps(xi_138, xi_145);
          const __m256 xi_1 = _mm256_add_ps(xi_148, xi_149);
          const __m256 xi_2 = _mm256_add_ps(xi_150, xi_154);
          const __m256 xi_3 = _mm256_add_ps(xi_135, xi_151);
          const __m256 xi_4 = _mm256_add_ps(xi_143, xi_146);
          const __m256 xi_6 = _mm256_add_ps(xi_134, xi_142);
          const __m256 xi_7 = _mm256_add_ps(xi_133, xi_139);
          const __m256 xi_61 = _mm256_mul_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f),
                                random_3_0),
                  _mm256_set_ps(3.7416573867739413f, 3.7416573867739413f,
                                3.7416573867739413f, 3.7416573867739413f,
                                3.7416573867739413f, 3.7416573867739413f,
                                3.7416573867739413f, 3.7416573867739413f)),
              _mm256_set_ps(xi_60, xi_60, xi_60, xi_60, xi_60, xi_60, xi_60,
                            xi_60));
          const __m256 xi_62 = _mm256_mul_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f),
                                random_3_2),
                  _mm256_set_ps(5.4772255750516612f, 5.4772255750516612f,
                                5.4772255750516612f, 5.4772255750516612f,
                                5.4772255750516612f, 5.4772255750516612f,
                                5.4772255750516612f, 5.4772255750516612f)),
              _mm256_set_ps(xi_60, xi_60, xi_60, xi_60, xi_60, xi_60, xi_60,
                            xi_60));
          const __m256 xi_64 = _mm256_mul_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f),
                                random_1_1),
                  _mm256_set_ps(xi_63, xi_63, xi_63, xi_63, xi_63, xi_63, xi_63,
                                xi_63)),
              _mm256_sqrt_ps(_mm256_mul_ps(
                  _mm256_set_ps(xi_59, xi_59, xi_59, xi_59, xi_59, xi_59, xi_59,
                                xi_59),
                  _mm256_add_ps(
                      _mm256_mul_ps(
                          _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                        -1.0f, -1.0f, -1.0f),
                          (_mm256_mul_ps(
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                    -1.0f, -1.0f, -1.0f, -1.0f),
                                      _mm256_set_ps(omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk)),
                                  _mm256_set_ps(1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f)),
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                    -1.0f, -1.0f, -1.0f, -1.0f),
                                      _mm256_set_ps(omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk,
                                                    omega_bulk, omega_bulk)),
                                  _mm256_set_ps(1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f))))),
                      _mm256_set_ps(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                    1.0f)))));
          const __m256 xi_65 = _mm256_mul_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f),
                                random_3_1),
                  _mm256_set_ps(8.3666002653407556f, 8.3666002653407556f,
                                8.3666002653407556f, 8.3666002653407556f,
                                8.3666002653407556f, 8.3666002653407556f,
                                8.3666002653407556f, 8.3666002653407556f)),
              _mm256_set_ps(xi_60, xi_60, xi_60, xi_60, xi_60, xi_60, xi_60,
                            xi_60));
          const __m256 xi_66 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_2_3);
          const __m256 xi_70 =
              _mm256_mul_ps(xi_66, _mm256_set_ps(xi_69, xi_69, xi_69, xi_69,
                                                 xi_69, xi_69, xi_69, xi_69));
          const __m256 xi_71 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_1_2);
          const __m256 xi_74 =
              _mm256_mul_ps(xi_71, _mm256_set_ps(xi_73, xi_73, xi_73, xi_73,
                                                 xi_73, xi_73, xi_73, xi_73));
          const __m256 xi_75 =
              _mm256_mul_ps(xi_74, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_76 = _mm256_mul_ps(
              xi_61,
              _mm256_set_ps(-0.11904761904761904f, -0.11904761904761904f,
                            -0.11904761904761904f, -0.11904761904761904f,
                            -0.11904761904761904f, -0.11904761904761904f,
                            -0.11904761904761904f, -0.11904761904761904f));
          const __m256 xi_77 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_0_1);
          const __m256 xi_80 =
              _mm256_mul_ps(xi_77, _mm256_set_ps(xi_79, xi_79, xi_79, xi_79,
                                                 xi_79, xi_79, xi_79, xi_79));
          const __m256 xi_81 = _mm256_mul_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f),
                                random_0_0),
                  _mm256_set_ps(1.7320508075688772f, 1.7320508075688772f,
                                1.7320508075688772f, 1.7320508075688772f,
                                1.7320508075688772f, 1.7320508075688772f,
                                1.7320508075688772f, 1.7320508075688772f)),
              _mm256_set_ps(xi_78, xi_78, xi_78, xi_78, xi_78, xi_78, xi_78,
                            xi_78));
          const __m256 xi_82 = _mm256_mul_ps(
              xi_81,
              _mm256_set_ps(-0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f));
          const __m256 xi_83 = _mm256_add_ps(
              _mm256_mul_ps(
                  xi_62,
                  _mm256_set_ps(-0.10000000000000001f, -0.10000000000000001f,
                                -0.10000000000000001f, -0.10000000000000001f,
                                -0.10000000000000001f, -0.10000000000000001f,
                                -0.10000000000000001f, -0.10000000000000001f)),
              xi_82);
          const __m256 xi_85 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_2_1);
          const __m256 xi_86 =
              _mm256_mul_ps(xi_85, _mm256_set_ps(xi_69, xi_69, xi_69, xi_69,
                                                 xi_69, xi_69, xi_69, xi_69));
          const __m256 xi_87 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_2_0);
          const __m256 xi_88 =
              _mm256_mul_ps(xi_87, _mm256_set_ps(xi_73, xi_73, xi_73, xi_73,
                                                 xi_73, xi_73, xi_73, xi_73));
          const __m256 xi_90 =
              _mm256_mul_ps(xi_88, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_91 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_2_2);
          const __m256 xi_92 =
              _mm256_mul_ps(xi_91, _mm256_set_ps(xi_69, xi_69, xi_69, xi_69,
                                                 xi_69, xi_69, xi_69, xi_69));
          const __m256 xi_93 =
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_1_3);
          const __m256 xi_94 =
              _mm256_mul_ps(xi_93, _mm256_set_ps(xi_73, xi_73, xi_73, xi_73,
                                                 xi_73, xi_73, xi_73, xi_73));
          const __m256 xi_95 =
              _mm256_mul_ps(xi_94, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_97 = _mm256_mul_ps(
              _mm256_mul_ps(xi_77, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f,
                                                 0.25f, 0.25f, 0.25f, 0.25f)),
              _mm256_set_ps(xi_78, xi_78, xi_78, xi_78, xi_78, xi_78, xi_78,
                            xi_78));
          const __m256 xi_98 = _mm256_mul_ps(
              xi_61,
              _mm256_set_ps(0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f));
          const __m256 xi_99 = _mm256_mul_ps(
              xi_64,
              _mm256_set_ps(0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f,
                            0.083333333333333329f, 0.083333333333333329f));
          const __m256 xi_100 = _mm256_add_ps(
              _mm256_mul_ps(
                  xi_81,
                  _mm256_set_ps(0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f)),
              xi_99);
          const __m256 xi_101 = _mm256_add_ps(
              _mm256_add_ps(_mm256_add_ps(xi_100, xi_74), xi_97), xi_98);
          const __m256 xi_102 = _mm256_mul_ps(
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_0_2),
              _mm256_set_ps(xi_79, xi_79, xi_79, xi_79, xi_79, xi_79, xi_79,
                            xi_79));
          const __m256 xi_105 = _mm256_add_ps(
              _mm256_add_ps(_mm256_add_ps(xi_100, xi_75), xi_97), xi_98);
          const __m256 xi_106 = _mm256_mul_ps(
              xi_61,
              _mm256_set_ps(-0.023809523809523808f, -0.023809523809523808f,
                            -0.023809523809523808f, -0.023809523809523808f,
                            -0.023809523809523808f, -0.023809523809523808f,
                            -0.023809523809523808f, -0.023809523809523808f));
          const __m256 xi_108 = _mm256_mul_ps(
              xi_93, _mm256_set_ps(xi_107, xi_107, xi_107, xi_107, xi_107,
                                   xi_107, xi_107, xi_107));
          const __m256 xi_109 = _mm256_mul_ps(
              xi_65,
              _mm256_set_ps(-0.014285714285714285f, -0.014285714285714285f,
                            -0.014285714285714285f, -0.014285714285714285f,
                            -0.014285714285714285f, -0.014285714285714285f,
                            -0.014285714285714285f, -0.014285714285714285f));
          const __m256 xi_111 = _mm256_mul_ps(
              xi_91, _mm256_set_ps(xi_110, xi_110, xi_110, xi_110, xi_110,
                                   xi_110, xi_110, xi_110));
          const __m256 xi_112 = _mm256_mul_ps(
              xi_62,
              _mm256_set_ps(0.050000000000000003f, 0.050000000000000003f,
                            0.050000000000000003f, 0.050000000000000003f,
                            0.050000000000000003f, 0.050000000000000003f,
                            0.050000000000000003f, 0.050000000000000003f));
          const __m256 xi_113 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      xi_108, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f)),
                                  xi_106),
                              xi_109),
                          xi_111),
                      xi_112),
                  xi_82),
              xi_99);
          const __m256 xi_114 = _mm256_mul_ps(
              xi_71, _mm256_set_ps(xi_107, xi_107, xi_107, xi_107, xi_107,
                                   xi_107, xi_107, xi_107));
          const __m256 xi_115 = _mm256_mul_ps(
              xi_66, _mm256_set_ps(xi_110, xi_110, xi_110, xi_110, xi_110,
                                   xi_110, xi_110, xi_110));
          const __m256 xi_116 = _mm256_add_ps(
              _mm256_mul_ps(xi_114, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_115);
          const __m256 xi_117 = _mm256_mul_ps(
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_1_0),
              _mm256_set_ps(xi_79, xi_79, xi_79, xi_79, xi_79, xi_79, xi_79,
                            xi_79));
          const __m256 xi_120 = _mm256_add_ps(
              _mm256_mul_ps(xi_115, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_114);
          const __m256 xi_121 =
              _mm256_mul_ps(xi_97, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_122 = _mm256_mul_ps(
              xi_65,
              _mm256_set_ps(0.035714285714285712f, 0.035714285714285712f,
                            0.035714285714285712f, 0.035714285714285712f,
                            0.035714285714285712f, 0.035714285714285712f,
                            0.035714285714285712f, 0.035714285714285712f));
          const __m256 xi_123 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(xi_100, xi_106), xi_121), xi_122),
              xi_94);
          const __m256 xi_124 = _mm256_mul_ps(
              xi_85, _mm256_set_ps(xi_110, xi_110, xi_110, xi_110, xi_110,
                                   xi_110, xi_110, xi_110));
          const __m256 xi_125 = _mm256_mul_ps(
              xi_87, _mm256_set_ps(xi_107, xi_107, xi_107, xi_107, xi_107,
                                   xi_107, xi_107, xi_107));
          const __m256 xi_126 = _mm256_add_ps(
              _mm256_mul_ps(xi_124, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_125);
          const __m256 xi_127 = _mm256_mul_ps(
              _mm256_add_ps(_mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f),
                            random_0_3),
              _mm256_set_ps(xi_79, xi_79, xi_79, xi_79, xi_79, xi_79, xi_79,
                            xi_79));
          const __m256 xi_130 = _mm256_add_ps(
              _mm256_mul_ps(xi_125, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_124);
          const __m256 xi_131 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      xi_111, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f)),
                                  xi_106),
                              xi_108),
                          xi_109),
                      xi_112),
                  xi_82),
              xi_99);
          const __m256 xi_132 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(xi_100, xi_106), xi_121), xi_122),
              xi_95);
          const __m256 partial_m_m1_0_e_0 = _mm256_add_ps(xi_0, xi_144);
          const __m256 partial_m_m1_e_0_0 =
              _mm256_add_ps(partial_m_m1_0_e_0, xi_1);
          const __m256 partial_m_0_m1_e_0 = _mm256_add_ps(xi_141, xi_2);
          const __m256 partial_m_0_0_e_0 = _mm256_add_ps(xi_152, xi_3);
          const __m256 partial_m_0_1_e_0 = _mm256_add_ps(xi_137, xi_4);
          const __m256 xi_5 =
              _mm256_add_ps(partial_m_0_1_e_0, partial_m_0_m1_e_0);
          const __m256 partial_m_0_e_0_0 =
              _mm256_add_ps(partial_m_0_0_e_0, xi_5);
          const __m256 partial_m_1_0_e_0 = _mm256_add_ps(xi_140, xi_6);
          const __m256 partial_m_1_e_0_0 =
              _mm256_add_ps(partial_m_1_0_e_0, xi_7);
          const __m256 xi_10 =
              _mm256_add_ps(partial_m_1_e_0_0, partial_m_m1_e_0_0);
          const __m256 partial_m_m1_e_1_0 = _mm256_add_ps(
              _mm256_mul_ps(xi_148, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_149);
          const __m256 partial_m_0_e_1_0 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_0_m1_e_0,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_0_1_e_0);
          const __m256 partial_m_1_e_1_0 = _mm256_add_ps(
              _mm256_mul_ps(xi_139, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_133);
          const __m256 xi_11 =
              _mm256_add_ps(partial_m_1_e_1_0, partial_m_m1_e_1_0);
          const __m256 partial_m_m1_0_e_1 = _mm256_add_ps(
              _mm256_mul_ps(xi_145, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_138);
          const __m256 partial_m_0_m1_e_1 = _mm256_add_ps(
              _mm256_mul_ps(xi_150, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_154);
          const __m256 partial_m_0_0_e_1 = _mm256_add_ps(
              _mm256_mul_ps(xi_135, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_151);
          const __m256 partial_m_0_1_e_1 = _mm256_add_ps(
              _mm256_mul_ps(xi_146, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_143);
          const __m256 xi_8 =
              _mm256_add_ps(partial_m_0_1_e_1, partial_m_0_m1_e_1);
          const __m256 partial_m_0_e_0_1 =
              _mm256_add_ps(partial_m_0_0_e_1, xi_8);
          const __m256 partial_m_1_0_e_1 = _mm256_add_ps(
              _mm256_mul_ps(xi_134, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_142);
          const __m256 xi_12 =
              _mm256_add_ps(partial_m_1_0_e_1, partial_m_m1_0_e_1);
          const __m256 partial_m_m1_e_2_0 = xi_1;
          const __m256 partial_m_0_e_2_0 = xi_5;
          const __m256 partial_m_1_e_2_0 = xi_7;
          const __m256 xi_13 =
              _mm256_add_ps(partial_m_1_e_2_0, partial_m_m1_e_2_0);
          const __m256 partial_m_m1_0_e_2 = xi_0;
          const __m256 partial_m_0_m1_e_2 = xi_2;
          const __m256 partial_m_0_0_e_2 = xi_3;
          const __m256 partial_m_0_1_e_2 = xi_4;
          const __m256 xi_9 =
              _mm256_add_ps(partial_m_0_1_e_2, partial_m_0_m1_e_2);
          const __m256 partial_m_0_e_0_2 =
              _mm256_add_ps(partial_m_0_0_e_2, xi_9);
          const __m256 partial_m_1_0_e_2 = xi_6;
          const __m256 xi_14 =
              _mm256_add_ps(partial_m_1_0_e_2, partial_m_m1_0_e_2);
          const __m256 partial_m_0_e_1_1 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_0_m1_e_1,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_0_1_e_1);
          const __m256 partial_m_0_e_2_1 = xi_8;
          const __m256 partial_m_0_e_1_2 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_0_m1_e_2,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_0_1_e_2);
          const __m256 partial_m_0_e_2_2 = xi_9;
          const __m256 m_000 = _mm256_add_ps(partial_m_0_e_0_0, xi_10);
          const __m256 m_100 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_m1_e_0_0,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_1_e_0_0);
          const __m256 xi_19 =
              _mm256_mul_ps(m_100, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 m_010 = _mm256_add_ps(partial_m_0_e_1_0, xi_11);
          const __m256 xi_17 =
              _mm256_mul_ps(m_010, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 m_001 = _mm256_add_ps(partial_m_0_e_0_1, xi_12);
          const __m256 xi_18 =
              _mm256_mul_ps(m_001, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 m_200 = xi_10;
          const __m256 xi_20 = _mm256_add_ps(
              _mm256_mul_ps(m_200, _mm256_set_ps(-6.0f, -6.0f, -6.0f, -6.0f,
                                                 -6.0f, -6.0f, -6.0f, -6.0f)),
              m_000);
          const __m256 m_020 = _mm256_add_ps(partial_m_0_e_2_0, xi_13);
          const __m256 m_002 = _mm256_add_ps(partial_m_0_e_0_2, xi_14);
          const __m256 xi_16 =
              _mm256_mul_ps(m_002, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 m_110 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_m1_e_1_0,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_1_e_1_0);
          const __m256 m_101 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_m1_0_e_1,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_1_0_e_1);
          const __m256 m_210 = xi_11;
          const __m256 m_201 = xi_12;
          const __m256 m_120 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_m1_e_2_0,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_1_e_2_0);
          const __m256 m_102 = _mm256_add_ps(
              _mm256_mul_ps(partial_m_m1_0_e_2,
                            _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                          -1.0f, -1.0f, -1.0f)),
              partial_m_1_0_e_2);
          const __m256 m_220 = xi_13;
          const __m256 xi_21 = _mm256_add_ps(
              _mm256_mul_ps(m_220, _mm256_set_ps(4.0f, 4.0f, 4.0f, 4.0f, 4.0f,
                                                 4.0f, 4.0f, 4.0f)),
              _mm256_mul_ps(m_002, _mm256_set_ps(-4.0f, -4.0f, -4.0f, -4.0f,
                                                 -4.0f, -4.0f, -4.0f, -4.0f)));
          const __m256 m_202 = xi_14;
          const __m256 sub_f_to_m_0 = _mm256_div_ps(
              _mm256_set_ps(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
              m_000);
          const __m256 xi_15 = _mm256_mul_ps(
              sub_f_to_m_0,
              _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f));
          const __m256 u_0 = _mm256_add_ps(_mm256_mul_ps(m_100, sub_f_to_m_0),
                                           _mm256_mul_ps(xi_147, xi_15));
          const __m256 xi_23 = _mm256_mul_ps(u_0, xi_147);
          const __m256 xi_27 = _mm256_mul_ps(m_000, (_mm256_mul_ps(u_0, u_0)));
          const __m256 xi_31 = _mm256_mul_ps(m_000, u_0);
          const __m256 u_1 = _mm256_add_ps(_mm256_mul_ps(m_010, sub_f_to_m_0),
                                           _mm256_mul_ps(xi_15, xi_153));
          const __m256 xi_24 = _mm256_mul_ps(
              _mm256_mul_ps(u_1, xi_153),
              _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f));
          const __m256 xi_28 = _mm256_mul_ps(m_000, (_mm256_mul_ps(u_1, u_1)));
          const __m256 u_2 = _mm256_add_ps(_mm256_mul_ps(m_001, sub_f_to_m_0),
                                           _mm256_mul_ps(xi_136, xi_15));
          const __m256 xi_25 = _mm256_mul_ps(
              _mm256_mul_ps(u_2, xi_136),
              _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f));
          const __m256 xi_26 =
              _mm256_mul_ps(xi_25, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_29 = _mm256_mul_ps(m_000, (_mm256_mul_ps(u_2, u_2)));
          const __m256 xi_30 =
              _mm256_mul_ps(xi_29, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f));
          const __m256 xi_32 = _mm256_mul_ps(
              xi_29, _mm256_set_ps(0.66666666666666663f, 0.66666666666666663f,
                                   0.66666666666666663f, 0.66666666666666663f,
                                   0.66666666666666663f, 0.66666666666666663f,
                                   0.66666666666666663f, 0.66666666666666663f));
          const __m256 M_4 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_020,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_mul_ps(m_200, _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f,
                                                     2.0f, 2.0f, 2.0f, 2.0f))),
              xi_16);
          const __m256 M_5 = _mm256_add_ps(m_020, xi_16);
          const __m256 M_9 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(m_000,
                                    _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
                      m_002),
                  m_020),
              m_200);
          const __m256 M_10 = _mm256_add_ps(
              _mm256_mul_ps(m_210, _mm256_set_ps(3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
                                                 3.0f, 3.0f, 3.0f)),
              xi_17);
          const __m256 M_11 = _mm256_add_ps(
              _mm256_mul_ps(m_201, _mm256_set_ps(3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
                                                 3.0f, 3.0f, 3.0f)),
              xi_18);
          const __m256 M_12 = _mm256_add_ps(
              _mm256_mul_ps(m_120, _mm256_set_ps(3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
                                                 3.0f, 3.0f, 3.0f)),
              xi_19);
          const __m256 M_13 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_102, _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f,
                                                     2.0f, 2.0f, 2.0f, 2.0f)),
                  m_120),
              xi_19);
          const __m256 M_14 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(partial_m_0_e_2_1,
                                _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f, 2.0f,
                                              2.0f, 2.0f, 2.0f)),
                  m_201),
              xi_18);
          const __m256 M_15 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(partial_m_0_e_1_2,
                                _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f, 2.0f,
                                              2.0f, 2.0f, 2.0f)),
                  m_210),
              xi_17);
          const __m256 M_16 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(m_002,
                                    _mm256_set_ps(3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
                                                  3.0f, 3.0f, 3.0f)),
                      _mm256_mul_ps(m_220,
                                    _mm256_set_ps(18.0f, 18.0f, 18.0f, 18.0f,
                                                  18.0f, 18.0f, 18.0f, 18.0f))),
                  _mm256_mul_ps(m_020,
                                _mm256_set_ps(-6.0f, -6.0f, -6.0f, -6.0f, -6.0f,
                                              -6.0f, -6.0f, -6.0f))),
              xi_20);
          const __m256 M_17 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(m_202,
                                    _mm256_set_ps(14.0f, 14.0f, 14.0f, 14.0f,
                                                  14.0f, 14.0f, 14.0f, 14.0f)),
                      m_020),
                  xi_20),
              xi_21);
          const __m256 M_18 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_mul_ps(m_200,
                                            _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f)),
                              _mm256_mul_ps(m_202,
                                            _mm256_set_ps(4.0f, 4.0f, 4.0f,
                                                          4.0f, 4.0f, 4.0f,
                                                          4.0f, 4.0f))),
                          _mm256_mul_ps(partial_m_0_e_2_2,
                                        _mm256_set_ps(10.0f, 10.0f, 10.0f,
                                                      10.0f, 10.0f, 10.0f,
                                                      10.0f, 10.0f))),
                      _mm256_mul_ps(m_020,
                                    _mm256_set_ps(-4.0f, -4.0f, -4.0f, -4.0f,
                                                  -4.0f, -4.0f, -4.0f, -4.0f))),
                  m_000),
              xi_21);
          const __m256 M_post_1 = _mm256_add_ps(m_100, xi_147);
          const __m256 xi_39 = _mm256_mul_ps(
              M_post_1,
              _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f));
          const __m256 M_post_2 = _mm256_add_ps(m_010, xi_153);
          const __m256 xi_37 = _mm256_mul_ps(
              M_post_2,
              _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f));
          const __m256 M_post_3 = _mm256_add_ps(m_001, xi_136);
          const __m256 xi_38 = _mm256_mul_ps(
              M_post_3,
              _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f,
                            0.33333333333333331f, 0.33333333333333331f));
          const __m256 M_post_4 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_mul_ps(xi_24,
                                            _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f)),
                              _mm256_mul_ps(xi_23,
                                            _mm256_set_ps(4.0f, 4.0f, 4.0f,
                                                          4.0f, 4.0f, 4.0f,
                                                          4.0f, 4.0f))),
                          xi_26),
                      _mm256_set_ps(xi_22, xi_22, xi_22, xi_22, xi_22, xi_22,
                                    xi_22, xi_22)),
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      M_4, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                         -1.0f, -1.0f, -1.0f,
                                                         -1.0f, -1.0f)),
                                  _mm256_mul_ps(
                                      xi_28, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                           -1.0f, -1.0f, -1.0f,
                                                           -1.0f, -1.0f))),
                              _mm256_mul_ps(xi_27,
                                            _mm256_set_ps(2.0f, 2.0f, 2.0f,
                                                          2.0f, 2.0f, 2.0f,
                                                          2.0f, 2.0f))),
                          xi_30),
                      _mm256_set_ps(omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear))),
              M_4);
          const __m256 xi_35 = _mm256_mul_ps(
              M_post_4,
              _mm256_set_ps(-0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f,
                            -0.16666666666666666f, -0.16666666666666666f));
          const __m256 M_post_5 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(_mm256_add_ps(xi_24, xi_26),
                                _mm256_set_ps(xi_22, xi_22, xi_22, xi_22, xi_22,
                                              xi_22, xi_22, xi_22)),
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_mul_ps(M_5,
                                            _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f)),
                              xi_28),
                          xi_30),
                      _mm256_set_ps(omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear))),
              M_5);
          const __m256 xi_34 =
              _mm256_mul_ps(M_post_5, _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f,
                                                    0.5f, 0.5f, 0.5f, 0.5f));
          const __m256 xi_40 = _mm256_mul_ps(
              M_post_5, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                      0.25f, 0.25f));
          const __m256 M_post_6 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              m_110, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                   -1.0f, -1.0f, -1.0f, -1.0f)),
                          _mm256_mul_ps(u_1, xi_31)),
                      _mm256_set_ps(omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear)),
                  _mm256_mul_ps(_mm256_add_ps(_mm256_mul_ps(u_0, xi_153),
                                              _mm256_mul_ps(u_1, xi_147)),
                                _mm256_set_ps(xi_22, xi_22, xi_22, xi_22, xi_22,
                                              xi_22, xi_22, xi_22))),
              m_110);
          const __m256 xi_47 = _mm256_mul_ps(
              M_post_6, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                      0.25f, 0.25f));
          const __m256 M_post_7 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              m_101, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                   -1.0f, -1.0f, -1.0f, -1.0f)),
                          _mm256_mul_ps(u_2, xi_31)),
                      _mm256_set_ps(omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear)),
                  _mm256_mul_ps(_mm256_add_ps(_mm256_mul_ps(u_0, xi_136),
                                              _mm256_mul_ps(u_2, xi_147)),
                                _mm256_set_ps(xi_22, xi_22, xi_22, xi_22, xi_22,
                                              xi_22, xi_22, xi_22))),
              m_101);
          const __m256 xi_55 = _mm256_mul_ps(
              M_post_7, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                      0.25f, 0.25f));
          const __m256 M_post_8 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(partial_m_0_e_1_1,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          _mm256_mul_ps(_mm256_mul_ps(m_000, u_1), u_2)),
                      _mm256_set_ps(omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear, omega_shear,
                                    omega_shear, omega_shear)),
                  _mm256_mul_ps(_mm256_add_ps(_mm256_mul_ps(u_1, xi_136),
                                              _mm256_mul_ps(u_2, xi_153)),
                                _mm256_set_ps(xi_22, xi_22, xi_22, xi_22, xi_22,
                                              xi_22, xi_22, xi_22))),
              partial_m_0_e_1_1);
          const __m256 xi_51 = _mm256_mul_ps(
              M_post_8, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                      0.25f, 0.25f));
          const __m256 M_post_9 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                            -0.5f, -0.5f, -0.5f),
                              _mm256_set_ps(omega_bulk, omega_bulk, omega_bulk,
                                            omega_bulk, omega_bulk, omega_bulk,
                                            omega_bulk, omega_bulk)),
                          _mm256_set_ps(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                        1.0f, 1.0f)),
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_mul_ps(
                                  xi_23, _mm256_set_ps(2.0f, 2.0f, 2.0f, 2.0f,
                                                       2.0f, 2.0f, 2.0f, 2.0f)),
                              xi_24),
                          xi_25)),
                  _mm256_mul_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_add_ps(
                                  _mm256_mul_ps(
                                      M_9, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                         -1.0f, -1.0f, -1.0f,
                                                         -1.0f, -1.0f)),
                                  xi_27),
                              xi_28),
                          xi_29),
                      _mm256_set_ps(omega_bulk, omega_bulk, omega_bulk,
                                    omega_bulk, omega_bulk, omega_bulk,
                                    omega_bulk, omega_bulk))),
              M_9);
          const __m256 xi_33 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_9,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)),
              _mm256_mul_ps(
                  m_000,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)));
          const __m256 xi_36 = _mm256_add_ps(xi_33, xi_35);
          const __m256 xi_41 = _mm256_add_ps(
              _mm256_mul_ps(
                  m_000,
                  _mm256_set_ps(0.1111111111111111f, 0.1111111111111111f,
                                0.1111111111111111f, 0.1111111111111111f,
                                0.1111111111111111f, 0.1111111111111111f,
                                0.1111111111111111f, 0.1111111111111111f)),
              _mm256_mul_ps(
                  M_post_9,
                  _mm256_set_ps(0.16666666666666666f, 0.16666666666666666f,
                                0.16666666666666666f, 0.16666666666666666f,
                                0.16666666666666666f, 0.16666666666666666f,
                                0.16666666666666666f, 0.16666666666666666f)));
          const __m256 xi_42 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_4,
                  _mm256_set_ps(0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f,
                                0.083333333333333329f, 0.083333333333333329f)),
              xi_41);
          const __m256 M_post_10 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_10,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_10);
          const __m256 M_post_11 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_11,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_11);
          const __m256 M_post_12 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_12,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_12);
          const __m256 M_post_13 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_13,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_13);
          const __m256 M_post_14 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_14,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_14);
          const __m256 M_post_15 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_mul_ps(M_15,
                                _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                              -1.0f, -1.0f, -1.0f)),
                  _mm256_set_ps(omega_odd, omega_odd, omega_odd, omega_odd,
                                omega_odd, omega_odd, omega_odd, omega_odd)),
              M_15);
          const __m256 M_post_16 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(M_16,
                                    _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
                      _mm256_mul_ps(xi_29,
                                    _mm256_set_ps(3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
                                                  3.0f, 3.0f, 3.0f))),
                  _mm256_set_ps(omega_even, omega_even, omega_even, omega_even,
                                omega_even, omega_even, omega_even,
                                omega_even)),
              M_16);
          const __m256 xi_43 = _mm256_mul_ps(
              M_post_16,
              _mm256_set_ps(-0.015873015873015872f, -0.015873015873015872f,
                            -0.015873015873015872f, -0.015873015873015872f,
                            -0.015873015873015872f, -0.015873015873015872f,
                            -0.015873015873015872f, -0.015873015873015872f));
          const __m256 M_post_17 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(M_17, _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f, -1.0f,
                                                            -1.0f, -1.0f)),
                          _mm256_mul_ps(
                              xi_28,
                              _mm256_set_ps(
                                  2.3333333333333335f, 2.3333333333333335f,
                                  2.3333333333333335f, 2.3333333333333335f,
                                  2.3333333333333335f, 2.3333333333333335f,
                                  2.3333333333333335f, 2.3333333333333335f))),
                      xi_32),
                  _mm256_set_ps(omega_even, omega_even, omega_even, omega_even,
                                omega_even, omega_even, omega_even,
                                omega_even)),
              M_17);
          const __m256 M_post_18 = _mm256_add_ps(
              _mm256_mul_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_mul_ps(M_18,
                                            _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f)),
                              _mm256_mul_ps(
                                  xi_28, _mm256_set_ps(0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f,
                                                       0.66666666666666663f))),
                          _mm256_mul_ps(
                              xi_27,
                              _mm256_set_ps(
                                  1.6666666666666667f, 1.6666666666666667f,
                                  1.6666666666666667f, 1.6666666666666667f,
                                  1.6666666666666667f, 1.6666666666666667f,
                                  1.6666666666666667f, 1.6666666666666667f))),
                      xi_32),
                  _mm256_set_ps(omega_even, omega_even, omega_even, omega_even,
                                omega_even, omega_even, omega_even,
                                omega_even)),
              M_18);
          const __m256 m_post_200 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_4,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)),
              xi_33);
          const __m256 m_post_020 = _mm256_add_ps(xi_34, xi_36);
          const __m256 m_post_002 = _mm256_add_ps(
              _mm256_mul_ps(xi_34, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_36);
          const __m256 m_post_210 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_10,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)),
              xi_37);
          const __m256 xi_50 = _mm256_mul_ps(
              m_post_210, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_201 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_11,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)),
              xi_38);
          const __m256 xi_58 = _mm256_mul_ps(
              m_post_201, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_120 = _mm256_add_ps(
              _mm256_mul_ps(
                  M_post_12,
                  _mm256_set_ps(0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f,
                                0.33333333333333331f, 0.33333333333333331f)),
              xi_39);
          const __m256 xi_49 = _mm256_mul_ps(
              m_post_120, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_102 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(M_post_13,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(
                      M_post_12,
                      _mm256_set_ps(
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f))),
              xi_39);
          const __m256 xi_57 = _mm256_mul_ps(
              m_post_102, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_021 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(M_post_14,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(
                      M_post_11,
                      _mm256_set_ps(
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f))),
              xi_38);
          const __m256 xi_54 = _mm256_mul_ps(
              m_post_021, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_012 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(M_post_15,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(
                      M_post_10,
                      _mm256_set_ps(
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f,
                          -0.16666666666666666f, -0.16666666666666666f))),
              xi_37);
          const __m256 xi_53 = _mm256_mul_ps(
              m_post_012, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_220 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(
                      M_post_16,
                      _mm256_set_ps(
                          0.055555555555555552f, 0.055555555555555552f,
                          0.055555555555555552f, 0.055555555555555552f,
                          0.055555555555555552f, 0.055555555555555552f,
                          0.055555555555555552f, 0.055555555555555552f)),
                  xi_40),
              xi_42);
          const __m256 xi_45 = _mm256_mul_ps(
              m_post_220, _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                        -0.5f, -0.5f, -0.5f));
          const __m256 xi_48 = _mm256_mul_ps(
              m_post_220, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_202 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(xi_40,
                                    _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
                      _mm256_mul_ps(
                          M_post_17,
                          _mm256_set_ps(
                              0.071428571428571425f, 0.071428571428571425f,
                              0.071428571428571425f, 0.071428571428571425f,
                              0.071428571428571425f, 0.071428571428571425f,
                              0.071428571428571425f, 0.071428571428571425f))),
                  xi_42),
              xi_43);
          const __m256 xi_46 = _mm256_mul_ps(
              m_post_202, _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                        -0.5f, -0.5f, -0.5f));
          const __m256 xi_56 = _mm256_mul_ps(
              m_post_202, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 m_post_022 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              M_post_18,
                              _mm256_set_ps(
                                  0.10000000000000001f, 0.10000000000000001f,
                                  0.10000000000000001f, 0.10000000000000001f,
                                  0.10000000000000001f, 0.10000000000000001f,
                                  0.10000000000000001f, 0.10000000000000001f)),
                          _mm256_mul_ps(M_post_17,
                                        _mm256_set_ps(-0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f,
                                                      -0.028571428571428571f))),
                      xi_35),
                  xi_41),
              xi_43);
          const __m256 xi_44 = _mm256_mul_ps(
              m_post_022, _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                        -0.5f, -0.5f, -0.5f));
          const __m256 xi_52 = _mm256_mul_ps(
              m_post_022, _mm256_set_ps(0.25f, 0.25f, 0.25f, 0.25f, 0.25f,
                                        0.25f, 0.25f, 0.25f));
          const __m256 sub_k_to_f_20 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_post_020,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  xi_44),
              xi_45);
          const __m256 xi_84 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              xi_65,
                              _mm256_set_ps(
                                  0.028571428571428571f, 0.028571428571428571f,
                                  0.028571428571428571f, 0.028571428571428571f,
                                  0.028571428571428571f, 0.028571428571428571f,
                                  0.028571428571428571f,
                                  0.028571428571428571f)),
                          sub_k_to_f_20),
                      xi_76),
                  xi_80),
              xi_83);
          const __m256 sub_k_to_f_21 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(M_post_2,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(m_post_012,
                                _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f))),
              _mm256_mul_ps(m_post_210,
                            _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f)));
          const __m256 sub_k_to_f_22 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_post_200,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  xi_45),
              xi_46);
          const __m256 xi_89 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_mul_ps(
                          xi_81,
                          _mm256_set_ps(
                              0.33333333333333331f, 0.33333333333333331f,
                              0.33333333333333331f, 0.33333333333333331f,
                              0.33333333333333331f, 0.33333333333333331f,
                              0.33333333333333331f, 0.33333333333333331f)),
                      _mm256_mul_ps(
                          xi_65,
                          _mm256_set_ps(
                              -0.071428571428571425f, -0.071428571428571425f,
                              -0.071428571428571425f, -0.071428571428571425f,
                              -0.071428571428571425f, -0.071428571428571425f,
                              -0.071428571428571425f, -0.071428571428571425f))),
                  sub_k_to_f_22),
              xi_76);
          const __m256 sub_k_to_f_23 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_post_102,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(m_post_120,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f))),
              _mm256_mul_ps(M_post_1,
                            _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f)));
          const __m256 sub_k_to_f_24 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(m_post_002,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  xi_44),
              xi_46);
          const __m256 xi_96 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              xi_80, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                   -1.0f, -1.0f, -1.0f, -1.0f)),
                          _mm256_mul_ps(
                              xi_61,
                              _mm256_set_ps(
                                  0.095238095238095233f, 0.095238095238095233f,
                                  0.095238095238095233f, 0.095238095238095233f,
                                  0.095238095238095233f, 0.095238095238095233f,
                                  0.095238095238095233f,
                                  0.095238095238095233f))),
                      _mm256_mul_ps(
                          xi_65,
                          _mm256_set_ps(
                              -0.042857142857142858f, -0.042857142857142858f,
                              -0.042857142857142858f, -0.042857142857142858f,
                              -0.042857142857142858f, -0.042857142857142858f,
                              -0.042857142857142858f, -0.042857142857142858f))),
                  sub_k_to_f_24),
              xi_83);
          const __m256 sub_k_to_f_25 = _mm256_add_ps(
              _mm256_add_ps(
                  _mm256_mul_ps(M_post_3,
                                _mm256_set_ps(0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                                              0.5f, 0.5f, 0.5f)),
                  _mm256_mul_ps(m_post_021,
                                _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                              -0.5f, -0.5f, -0.5f))),
              _mm256_mul_ps(m_post_201,
                            _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
                                          -0.5f, -0.5f, -0.5f)));
          const __m256 sub_k_to_f_26 = _mm256_add_ps(
              _mm256_mul_ps(xi_47, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_48);
          const __m256 xi_103 = _mm256_add_ps(
              _mm256_mul_ps(xi_102, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              sub_k_to_f_26);
          const __m256 sub_k_to_f_27 = _mm256_add_ps(
              _mm256_mul_ps(xi_49, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_50);
          const __m256 sub_k_to_f_28 = _mm256_add_ps(xi_47, xi_48);
          const __m256 xi_104 = _mm256_add_ps(sub_k_to_f_28, xi_102);
          const __m256 sub_k_to_f_29 = _mm256_add_ps(xi_49, xi_50);
          const __m256 sub_k_to_f_30 = _mm256_add_ps(xi_51, xi_52);
          const __m256 xi_118 = _mm256_add_ps(sub_k_to_f_30, xi_117);
          const __m256 sub_k_to_f_31 = _mm256_add_ps(xi_53, xi_54);
          const __m256 sub_k_to_f_32 = _mm256_add_ps(
              _mm256_mul_ps(xi_51, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_52);
          const __m256 xi_119 = _mm256_add_ps(
              _mm256_mul_ps(xi_117, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              sub_k_to_f_32);
          const __m256 sub_k_to_f_33 = _mm256_add_ps(
              _mm256_mul_ps(xi_53, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_54);
          const __m256 sub_k_to_f_34 = _mm256_add_ps(
              _mm256_mul_ps(xi_55, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_56);
          const __m256 xi_128 = _mm256_add_ps(
              _mm256_mul_ps(xi_127, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                  -1.0f, -1.0f, -1.0f, -1.0f)),
              sub_k_to_f_34);
          const __m256 sub_k_to_f_35 = _mm256_add_ps(
              _mm256_mul_ps(xi_57, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                 -1.0f, -1.0f, -1.0f, -1.0f)),
              xi_58);
          const __m256 sub_k_to_f_36 = _mm256_add_ps(xi_55, xi_56);
          const __m256 xi_129 = _mm256_add_ps(sub_k_to_f_36, xi_127);
          const __m256 sub_k_to_f_37 = _mm256_add_ps(xi_57, xi_58);
          _mm256_store_ps(
              &_data_pdfs_20_30_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_add_ps(
                              _mm256_add_ps(
                                  _mm256_add_ps(
                                      _mm256_add_ps(
                                          _mm256_add_ps(
                                              _mm256_add_ps(
                                                  _mm256_add_ps(
                                                      _mm256_mul_ps(
                                                          m_post_002,
                                                          _mm256_set_ps(
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f)),
                                                      _mm256_mul_ps(
                                                          m_post_020,
                                                          _mm256_set_ps(
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f,
                                                              -1.0f, -1.0f))),
                                                  _mm256_mul_ps(
                                                      m_post_200,
                                                      _mm256_set_ps(
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f, -1.0f,
                                                          -1.0f, -1.0f))),
                                              _mm256_mul_ps(
                                                  xi_64,
                                                  _mm256_set_ps(-1.0f, -1.0f,
                                                                -1.0f, -1.0f,
                                                                -1.0f, -1.0f,
                                                                -1.0f, -1.0f))),
                                          _mm256_mul_ps(
                                              xi_61,
                                              _mm256_set_ps(
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f,
                                                  0.14285714285714285f))),
                                      _mm256_mul_ps(
                                          xi_65, _mm256_set_ps(
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f,
                                                     0.085714285714285715f))),
                                  _mm256_mul_ps(
                                      xi_62,
                                      _mm256_set_ps(0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f,
                                                    0.20000000000000001f))),
                              m_000),
                          m_post_022),
                      m_post_202),
                  m_post_220));
          _mm256_store_ps(
              &_data_pdfs_20_31_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              xi_70, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                   -1.0f, -1.0f, -1.0f, -1.0f)),
                          sub_k_to_f_21),
                      xi_75),
                  xi_84));
          _mm256_store_ps(
              &_data_pdfs_20_32_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_21,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_70),
                      xi_74),
                  xi_84));
          _mm256_store_ps(
              &_data_pdfs_20_33_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_23, xi_86), xi_88),
                  xi_89));
          _mm256_store_ps(
              &_data_pdfs_20_34_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_23,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          _mm256_mul_ps(xi_86,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f))),
                      xi_89),
                  xi_90));
          _mm256_store_ps(
              &_data_pdfs_20_35_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(
                              xi_92, _mm256_set_ps(-1.0f, -1.0f, -1.0f, -1.0f,
                                                   -1.0f, -1.0f, -1.0f, -1.0f)),
                          sub_k_to_f_25),
                      xi_95),
                  xi_96));
          _mm256_store_ps(
              &_data_pdfs_20_36_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_25,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_92),
                      xi_94),
                  xi_96));
          _mm256_store_ps(
              &_data_pdfs_20_37_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_27, xi_101), xi_103),
                  xi_90));
          _mm256_store_ps(
              &_data_pdfs_20_38_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_29, xi_101), xi_104),
                  xi_88));
          _mm256_store_ps(
              &_data_pdfs_20_39_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_29,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_104),
                      xi_105),
                  xi_90));
          _mm256_store_ps(
              &_data_pdfs_20_310_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_27,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_103),
                      xi_105),
                  xi_88));
          _mm256_store_ps(
              &_data_pdfs_20_311_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_31, xi_113), xi_116),
                  xi_118));
          _mm256_store_ps(
              &_data_pdfs_20_312_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_33, xi_113), xi_119),
                  xi_120));
          _mm256_store_ps(
              &_data_pdfs_20_313_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_35, xi_123), xi_126),
                  xi_128));
          _mm256_store_ps(
              &_data_pdfs_20_314_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(_mm256_add_ps(sub_k_to_f_37, xi_123), xi_129),
                  xi_130));
          _mm256_store_ps(
              &_data_pdfs_20_315_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_33,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_116),
                      xi_119),
                  xi_131));
          _mm256_store_ps(
              &_data_pdfs_20_316_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_31,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_118),
                      xi_120),
                  xi_131));
          _mm256_store_ps(
              &_data_pdfs_20_317_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_37,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_126),
                      xi_129),
                  xi_132));
          _mm256_store_ps(
              &_data_pdfs_20_318_10[ctr_0],
              _mm256_add_ps(
                  _mm256_add_ps(
                      _mm256_add_ps(
                          _mm256_mul_ps(sub_k_to_f_35,
                                        _mm256_set_ps(-1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f, -1.0f,
                                                      -1.0f, -1.0f)),
                          xi_128),
                      xi_130),
                  xi_132));
        }
        for (int64_t ctr_0 = (int64_t)((_size_force_0) / (8)) * (8);
             ctr_0 < _size_force_0; ctr_0 += 1) {
          const float xi_133 = _data_pdfs_20_38_10[ctr_0];
          const float xi_134 = _data_pdfs_20_318_10[ctr_0];
          const float xi_135 = _data_pdfs_20_36_10[ctr_0];
          const float xi_136 = _data_force_20_32_10[ctr_0];
          const float xi_137 = _data_pdfs_20_31_10[ctr_0];
          const float xi_138 = _data_pdfs_20_313_10[ctr_0];
          const float xi_139 = _data_pdfs_20_310_10[ctr_0];
          const float xi_140 = _data_pdfs_20_34_10[ctr_0];
          const float xi_141 = _data_pdfs_20_32_10[ctr_0];
          const float xi_142 = _data_pdfs_20_314_10[ctr_0];
          const float xi_143 = _data_pdfs_20_311_10[ctr_0];
          const float xi_144 = _data_pdfs_20_33_10[ctr_0];
          const float xi_145 = _data_pdfs_20_317_10[ctr_0];
          const float xi_146 = _data_pdfs_20_315_10[ctr_0];
          const float xi_147 = _data_force_20_30_10[ctr_0];
          const float xi_148 = _data_pdfs_20_39_10[ctr_0];
          const float xi_149 = _data_pdfs_20_37_10[ctr_0];
          const float xi_150 = _data_pdfs_20_316_10[ctr_0];
          const float xi_151 = _data_pdfs_20_35_10[ctr_0];
          const float xi_152 = _data_pdfs_20_30_10[ctr_0];
          const float xi_153 = _data_force_20_31_10[ctr_0];
          const float xi_154 = _data_pdfs_20_312_10[ctr_0];

          float random_3_0;
          float random_3_1;
          float random_3_2;
          float random_3_3;
          philox_float4(time_step, block_offset_0 + ctr_0,
                        block_offset_1 + ctr_1, block_offset_2 + ctr_2, 3, seed,
                        random_3_0, random_3_1, random_3_2, random_3_3);

          float random_2_0;
          float random_2_1;
          float random_2_2;
          float random_2_3;
          philox_float4(time_step, block_offset_0 + ctr_0,
                        block_offset_1 + ctr_1, block_offset_2 + ctr_2, 2, seed,
                        random_2_0, random_2_1, random_2_2, random_2_3);

          float random_1_0;
          float random_1_1;
          float random_1_2;
          float random_1_3;
          philox_float4(time_step, block_offset_0 + ctr_0,
                        block_offset_1 + ctr_1, block_offset_2 + ctr_2, 1, seed,
                        random_1_0, random_1_1, random_1_2, random_1_3);

          float random_0_0;
          float random_0_1;
          float random_0_2;
          float random_0_3;
          philox_float4(time_step, block_offset_0 + ctr_0,
                        block_offset_1 + ctr_1, block_offset_2 + ctr_2, 0, seed,
                        random_0_0, random_0_1, random_0_2, random_0_3);

          const float xi_0 = xi_138 + xi_145;
          const float xi_1 = xi_148 + xi_149;
          const float xi_2 = xi_150 + xi_154;
          const float xi_3 = xi_135 + xi_151;
          const float xi_4 = xi_143 + xi_146;
          const float xi_6 = xi_134 + xi_142;
          const float xi_7 = xi_133 + xi_139;
          const float xi_61 = xi_60 * (random_3_0 - 0.5f) * 3.7416573867739413f;
          const float xi_62 = xi_60 * (random_3_2 - 0.5f) * 5.4772255750516612f;
          const float xi_64 =
              xi_63 * (random_1_1 - 0.5f) *
              powf(xi_59 * (-1.0f * ((omega_bulk * -1.0f + 1.0f) *
                                     (omega_bulk * -1.0f + 1.0f)) +
                            1.0f),
                   0.5f);
          const float xi_65 = xi_60 * (random_3_1 - 0.5f) * 8.3666002653407556f;
          const float xi_66 = random_2_3 - 0.5f;
          const float xi_70 = xi_66 * xi_69;
          const float xi_71 = random_1_2 - 0.5f;
          const float xi_74 = xi_71 * xi_73;
          const float xi_75 = xi_74 * -1.0f;
          const float xi_76 = xi_61 * -0.11904761904761904f;
          const float xi_77 = random_0_1 - 0.5f;
          const float xi_80 = xi_77 * xi_79;
          const float xi_81 = xi_78 * (random_0_0 - 0.5f) * 1.7320508075688772f;
          const float xi_82 = xi_81 * -0.16666666666666666f;
          const float xi_83 = xi_62 * -0.10000000000000001f + xi_82;
          const float xi_85 = random_2_1 - 0.5f;
          const float xi_86 = xi_69 * xi_85;
          const float xi_87 = random_2_0 - 0.5f;
          const float xi_88 = xi_73 * xi_87;
          const float xi_90 = xi_88 * -1.0f;
          const float xi_91 = random_2_2 - 0.5f;
          const float xi_92 = xi_69 * xi_91;
          const float xi_93 = random_1_3 - 0.5f;
          const float xi_94 = xi_73 * xi_93;
          const float xi_95 = xi_94 * -1.0f;
          const float xi_97 = xi_77 * xi_78 * 0.25f;
          const float xi_98 = xi_61 * 0.083333333333333329f;
          const float xi_99 = xi_64 * 0.083333333333333329f;
          const float xi_100 = xi_81 * 0.083333333333333329f + xi_99;
          const float xi_101 = xi_100 + xi_74 + xi_97 + xi_98;
          const float xi_102 = xi_79 * (random_0_2 - 0.5f);
          const float xi_105 = xi_100 + xi_75 + xi_97 + xi_98;
          const float xi_106 = xi_61 * -0.023809523809523808f;
          const float xi_108 = xi_107 * xi_93;
          const float xi_109 = xi_65 * -0.014285714285714285f;
          const float xi_111 = xi_110 * xi_91;
          const float xi_112 = xi_62 * 0.050000000000000003f;
          const float xi_113 = xi_106 + xi_108 * -1.0f + xi_109 + xi_111 +
                               xi_112 + xi_82 + xi_99;
          const float xi_114 = xi_107 * xi_71;
          const float xi_115 = xi_110 * xi_66;
          const float xi_116 = xi_114 * -1.0f + xi_115;
          const float xi_117 = xi_79 * (random_1_0 - 0.5f);
          const float xi_120 = xi_114 + xi_115 * -1.0f;
          const float xi_121 = xi_97 * -1.0f;
          const float xi_122 = xi_65 * 0.035714285714285712f;
          const float xi_123 = xi_100 + xi_106 + xi_121 + xi_122 + xi_94;
          const float xi_124 = xi_110 * xi_85;
          const float xi_125 = xi_107 * xi_87;
          const float xi_126 = xi_124 * -1.0f + xi_125;
          const float xi_127 = xi_79 * (random_0_3 - 0.5f);
          const float xi_130 = xi_124 + xi_125 * -1.0f;
          const float xi_131 = xi_106 + xi_108 + xi_109 + xi_111 * -1.0f +
                               xi_112 + xi_82 + xi_99;
          const float xi_132 = xi_100 + xi_106 + xi_121 + xi_122 + xi_95;
          const float partial_m_m1_0_e_0 = xi_0 + xi_144;
          const float partial_m_m1_e_0_0 = partial_m_m1_0_e_0 + xi_1;
          const float partial_m_0_m1_e_0 = xi_141 + xi_2;
          const float partial_m_0_0_e_0 = xi_152 + xi_3;
          const float partial_m_0_1_e_0 = xi_137 + xi_4;
          const float xi_5 = partial_m_0_1_e_0 + partial_m_0_m1_e_0;
          const float partial_m_0_e_0_0 = partial_m_0_0_e_0 + xi_5;
          const float partial_m_1_0_e_0 = xi_140 + xi_6;
          const float partial_m_1_e_0_0 = partial_m_1_0_e_0 + xi_7;
          const float xi_10 = partial_m_1_e_0_0 + partial_m_m1_e_0_0;
          const float partial_m_m1_e_1_0 = xi_148 * -1.0f + xi_149;
          const float partial_m_0_e_1_0 =
              partial_m_0_1_e_0 + partial_m_0_m1_e_0 * -1.0f;
          const float partial_m_1_e_1_0 = xi_133 + xi_139 * -1.0f;
          const float xi_11 = partial_m_1_e_1_0 + partial_m_m1_e_1_0;
          const float partial_m_m1_0_e_1 = xi_138 + xi_145 * -1.0f;
          const float partial_m_0_m1_e_1 = xi_150 * -1.0f + xi_154;
          const float partial_m_0_0_e_1 = xi_135 * -1.0f + xi_151;
          const float partial_m_0_1_e_1 = xi_143 + xi_146 * -1.0f;
          const float xi_8 = partial_m_0_1_e_1 + partial_m_0_m1_e_1;
          const float partial_m_0_e_0_1 = partial_m_0_0_e_1 + xi_8;
          const float partial_m_1_0_e_1 = xi_134 * -1.0f + xi_142;
          const float xi_12 = partial_m_1_0_e_1 + partial_m_m1_0_e_1;
          const float partial_m_m1_e_2_0 = xi_1;
          const float partial_m_0_e_2_0 = xi_5;
          const float partial_m_1_e_2_0 = xi_7;
          const float xi_13 = partial_m_1_e_2_0 + partial_m_m1_e_2_0;
          const float partial_m_m1_0_e_2 = xi_0;
          const float partial_m_0_m1_e_2 = xi_2;
          const float partial_m_0_0_e_2 = xi_3;
          const float partial_m_0_1_e_2 = xi_4;
          const float xi_9 = partial_m_0_1_e_2 + partial_m_0_m1_e_2;
          const float partial_m_0_e_0_2 = partial_m_0_0_e_2 + xi_9;
          const float partial_m_1_0_e_2 = xi_6;
          const float xi_14 = partial_m_1_0_e_2 + partial_m_m1_0_e_2;
          const float partial_m_0_e_1_1 =
              partial_m_0_1_e_1 + partial_m_0_m1_e_1 * -1.0f;
          const float partial_m_0_e_2_1 = xi_8;
          const float partial_m_0_e_1_2 =
              partial_m_0_1_e_2 + partial_m_0_m1_e_2 * -1.0f;
          const float partial_m_0_e_2_2 = xi_9;
          const float m_000 = partial_m_0_e_0_0 + xi_10;
          const float m_100 = partial_m_1_e_0_0 + partial_m_m1_e_0_0 * -1.0f;
          const float xi_19 = m_100 * -1.0f;
          const float m_010 = partial_m_0_e_1_0 + xi_11;
          const float xi_17 = m_010 * -1.0f;
          const float m_001 = partial_m_0_e_0_1 + xi_12;
          const float xi_18 = m_001 * -1.0f;
          const float m_200 = xi_10;
          const float xi_20 = m_000 + m_200 * -6.0f;
          const float m_020 = partial_m_0_e_2_0 + xi_13;
          const float m_002 = partial_m_0_e_0_2 + xi_14;
          const float xi_16 = m_002 * -1.0f;
          const float m_110 = partial_m_1_e_1_0 + partial_m_m1_e_1_0 * -1.0f;
          const float m_101 = partial_m_1_0_e_1 + partial_m_m1_0_e_1 * -1.0f;
          const float m_210 = xi_11;
          const float m_201 = xi_12;
          const float m_120 = partial_m_1_e_2_0 + partial_m_m1_e_2_0 * -1.0f;
          const float m_102 = partial_m_1_0_e_2 + partial_m_m1_0_e_2 * -1.0f;
          const float m_220 = xi_13;
          const float xi_21 = m_002 * -4.0f + m_220 * 4.0f;
          const float m_202 = xi_14;
          const float sub_f_to_m_0 = ((1.0f) / (m_000));
          const float xi_15 = sub_f_to_m_0 * 0.5f;
          const float u_0 = m_100 * sub_f_to_m_0 + xi_147 * xi_15;
          const float xi_23 = u_0 * xi_147;
          const float xi_27 = m_000 * (u_0 * u_0);
          const float xi_31 = m_000 * u_0;
          const float u_1 = m_010 * sub_f_to_m_0 + xi_15 * xi_153;
          const float xi_24 = u_1 * xi_153 * 2.0f;
          const float xi_28 = m_000 * (u_1 * u_1);
          const float u_2 = m_001 * sub_f_to_m_0 + xi_136 * xi_15;
          const float xi_25 = u_2 * xi_136 * 2.0f;
          const float xi_26 = xi_25 * -1.0f;
          const float xi_29 = m_000 * (u_2 * u_2);
          const float xi_30 = xi_29 * -1.0f;
          const float xi_32 = xi_29 * 0.66666666666666663f;
          const float M_4 = m_020 * -1.0f + m_200 * 2.0f + xi_16;
          const float M_5 = m_020 + xi_16;
          const float M_9 = m_000 * -1.0f + m_002 + m_020 + m_200;
          const float M_10 = m_210 * 3.0f + xi_17;
          const float M_11 = m_201 * 3.0f + xi_18;
          const float M_12 = m_120 * 3.0f + xi_19;
          const float M_13 = m_102 * 2.0f + m_120 + xi_19;
          const float M_14 = m_201 + partial_m_0_e_2_1 * 2.0f + xi_18;
          const float M_15 = m_210 + partial_m_0_e_1_2 * 2.0f + xi_17;
          const float M_16 =
              m_002 * 3.0f + m_020 * -6.0f + m_220 * 18.0f + xi_20;
          const float M_17 = m_020 + m_202 * 14.0f + xi_20 + xi_21;
          const float M_18 = m_000 + m_020 * -4.0f + m_200 * -1.0f +
                             m_202 * 4.0f + partial_m_0_e_2_2 * 10.0f + xi_21;
          const float M_post_1 = m_100 + xi_147;
          const float xi_39 = M_post_1 * 0.33333333333333331f;
          const float M_post_2 = m_010 + xi_153;
          const float xi_37 = M_post_2 * 0.33333333333333331f;
          const float M_post_3 = m_001 + xi_136;
          const float xi_38 = M_post_3 * 0.33333333333333331f;
          const float M_post_4 = M_4 +
                                 omega_shear * (M_4 * -1.0f + xi_27 * 2.0f +
                                                xi_28 * -1.0f + xi_30) +
                                 xi_22 * (xi_23 * 4.0f + xi_24 * -1.0f + xi_26);
          const float xi_35 = M_post_4 * -0.16666666666666666f;
          const float M_post_5 = M_5 +
                                 omega_shear * (M_5 * -1.0f + xi_28 + xi_30) +
                                 xi_22 * (xi_24 + xi_26);
          const float xi_34 = M_post_5 * 0.5f;
          const float xi_40 = M_post_5 * 0.25f;
          const float M_post_6 = m_110 +
                                 omega_shear * (m_110 * -1.0f + u_1 * xi_31) +
                                 xi_22 * (u_0 * xi_153 + u_1 * xi_147);
          const float xi_47 = M_post_6 * 0.25f;
          const float M_post_7 = m_101 +
                                 omega_shear * (m_101 * -1.0f + u_2 * xi_31) +
                                 xi_22 * (u_0 * xi_136 + u_2 * xi_147);
          const float xi_55 = M_post_7 * 0.25f;
          const float M_post_8 =
              omega_shear * (m_000 * u_1 * u_2 + partial_m_0_e_1_1 * -1.0f) +
              partial_m_0_e_1_1 + xi_22 * (u_1 * xi_136 + u_2 * xi_153);
          const float xi_51 = M_post_8 * 0.25f;
          const float M_post_9 =
              M_9 + omega_bulk * (M_9 * -1.0f + xi_27 + xi_28 + xi_29) +
              (omega_bulk * -0.5f + 1.0f) * (xi_23 * 2.0f + xi_24 + xi_25);
          const float xi_33 =
              M_post_9 * 0.33333333333333331f + m_000 * 0.33333333333333331f;
          const float xi_36 = xi_33 + xi_35;
          const float xi_41 =
              M_post_9 * 0.16666666666666666f + m_000 * 0.1111111111111111f;
          const float xi_42 = M_post_4 * 0.083333333333333329f + xi_41;
          const float M_post_10 = M_10 * omega_odd * -1.0f + M_10;
          const float M_post_11 = M_11 * omega_odd * -1.0f + M_11;
          const float M_post_12 = M_12 * omega_odd * -1.0f + M_12;
          const float M_post_13 = M_13 * omega_odd * -1.0f + M_13;
          const float M_post_14 = M_14 * omega_odd * -1.0f + M_14;
          const float M_post_15 = M_15 * omega_odd * -1.0f + M_15;
          const float M_post_16 =
              M_16 + omega_even * (M_16 * -1.0f + xi_29 * 3.0f);
          const float xi_43 = M_post_16 * -0.015873015873015872f;
          const float M_post_17 =
              M_17 +
              omega_even * (M_17 * -1.0f + xi_28 * 2.3333333333333335f + xi_32);
          const float M_post_18 =
              M_18 + omega_even * (M_18 * -1.0f + xi_27 * 1.6666666666666667f +
                                   xi_28 * 0.66666666666666663f + xi_32);
          const float m_post_200 = M_post_4 * 0.33333333333333331f + xi_33;
          const float m_post_020 = xi_34 + xi_36;
          const float m_post_002 = xi_34 * -1.0f + xi_36;
          const float m_post_210 = M_post_10 * 0.33333333333333331f + xi_37;
          const float xi_50 = m_post_210 * 0.25f;
          const float m_post_201 = M_post_11 * 0.33333333333333331f + xi_38;
          const float xi_58 = m_post_201 * 0.25f;
          const float m_post_120 = M_post_12 * 0.33333333333333331f + xi_39;
          const float xi_49 = m_post_120 * 0.25f;
          const float m_post_102 =
              M_post_12 * -0.16666666666666666f + M_post_13 * 0.5f + xi_39;
          const float xi_57 = m_post_102 * 0.25f;
          const float m_post_021 =
              M_post_11 * -0.16666666666666666f + M_post_14 * 0.5f + xi_38;
          const float xi_54 = m_post_021 * 0.25f;
          const float m_post_012 =
              M_post_10 * -0.16666666666666666f + M_post_15 * 0.5f + xi_37;
          const float xi_53 = m_post_012 * 0.25f;
          const float m_post_220 =
              M_post_16 * 0.055555555555555552f + xi_40 + xi_42;
          const float xi_45 = m_post_220 * -0.5f;
          const float xi_48 = m_post_220 * 0.25f;
          const float m_post_202 =
              M_post_17 * 0.071428571428571425f + xi_40 * -1.0f + xi_42 + xi_43;
          const float xi_46 = m_post_202 * -0.5f;
          const float xi_56 = m_post_202 * 0.25f;
          const float m_post_022 = M_post_17 * -0.028571428571428571f +
                                   M_post_18 * 0.10000000000000001f + xi_35 +
                                   xi_41 + xi_43;
          const float xi_44 = m_post_022 * -0.5f;
          const float xi_52 = m_post_022 * 0.25f;
          const float sub_k_to_f_20 = m_post_020 * 0.5f + xi_44 + xi_45;
          const float xi_84 = sub_k_to_f_20 + xi_65 * 0.028571428571428571f +
                              xi_76 + xi_80 + xi_83;
          const float sub_k_to_f_21 =
              M_post_2 * 0.5f + m_post_012 * -0.5f + m_post_210 * -0.5f;
          const float sub_k_to_f_22 = m_post_200 * 0.5f + xi_45 + xi_46;
          const float xi_89 = sub_k_to_f_22 + xi_65 * -0.071428571428571425f +
                              xi_76 + xi_81 * 0.33333333333333331f;
          const float sub_k_to_f_23 =
              M_post_1 * -0.5f + m_post_102 * 0.5f + m_post_120 * 0.5f;
          const float sub_k_to_f_24 = m_post_002 * 0.5f + xi_44 + xi_46;
          const float xi_96 = sub_k_to_f_24 + xi_61 * 0.095238095238095233f +
                              xi_65 * -0.042857142857142858f + xi_80 * -1.0f +
                              xi_83;
          const float sub_k_to_f_25 =
              M_post_3 * 0.5f + m_post_021 * -0.5f + m_post_201 * -0.5f;
          const float sub_k_to_f_26 = xi_47 * -1.0f + xi_48;
          const float xi_103 = sub_k_to_f_26 + xi_102 * -1.0f;
          const float sub_k_to_f_27 = xi_49 * -1.0f + xi_50;
          const float sub_k_to_f_28 = xi_47 + xi_48;
          const float xi_104 = sub_k_to_f_28 + xi_102;
          const float sub_k_to_f_29 = xi_49 + xi_50;
          const float sub_k_to_f_30 = xi_51 + xi_52;
          const float xi_118 = sub_k_to_f_30 + xi_117;
          const float sub_k_to_f_31 = xi_53 + xi_54;
          const float sub_k_to_f_32 = xi_51 * -1.0f + xi_52;
          const float xi_119 = sub_k_to_f_32 + xi_117 * -1.0f;
          const float sub_k_to_f_33 = xi_53 * -1.0f + xi_54;
          const float sub_k_to_f_34 = xi_55 * -1.0f + xi_56;
          const float xi_128 = sub_k_to_f_34 + xi_127 * -1.0f;
          const float sub_k_to_f_35 = xi_57 * -1.0f + xi_58;
          const float sub_k_to_f_36 = xi_55 + xi_56;
          const float xi_129 = sub_k_to_f_36 + xi_127;
          const float sub_k_to_f_37 = xi_57 + xi_58;
          _data_pdfs_20_30_10[ctr_0] =
              m_000 + m_post_002 * -1.0f + m_post_020 * -1.0f + m_post_022 +
              m_post_200 * -1.0f + m_post_202 + m_post_220 +
              xi_61 * 0.14285714285714285f + xi_62 * 0.20000000000000001f +
              xi_64 * -1.0f + xi_65 * 0.085714285714285715f;
          _data_pdfs_20_31_10[ctr_0] =
              sub_k_to_f_21 + xi_70 * -1.0f + xi_75 + xi_84;
          _data_pdfs_20_32_10[ctr_0] =
              sub_k_to_f_21 * -1.0f + xi_70 + xi_74 + xi_84;
          _data_pdfs_20_33_10[ctr_0] = sub_k_to_f_23 + xi_86 + xi_88 + xi_89;
          _data_pdfs_20_34_10[ctr_0] =
              sub_k_to_f_23 * -1.0f + xi_86 * -1.0f + xi_89 + xi_90;
          _data_pdfs_20_35_10[ctr_0] =
              sub_k_to_f_25 + xi_92 * -1.0f + xi_95 + xi_96;
          _data_pdfs_20_36_10[ctr_0] =
              sub_k_to_f_25 * -1.0f + xi_92 + xi_94 + xi_96;
          _data_pdfs_20_37_10[ctr_0] = sub_k_to_f_27 + xi_101 + xi_103 + xi_90;
          _data_pdfs_20_38_10[ctr_0] = sub_k_to_f_29 + xi_101 + xi_104 + xi_88;
          _data_pdfs_20_39_10[ctr_0] =
              sub_k_to_f_29 * -1.0f + xi_104 + xi_105 + xi_90;
          _data_pdfs_20_310_10[ctr_0] =
              sub_k_to_f_27 * -1.0f + xi_103 + xi_105 + xi_88;
          _data_pdfs_20_311_10[ctr_0] =
              sub_k_to_f_31 + xi_113 + xi_116 + xi_118;
          _data_pdfs_20_312_10[ctr_0] =
              sub_k_to_f_33 + xi_113 + xi_119 + xi_120;
          _data_pdfs_20_313_10[ctr_0] =
              sub_k_to_f_35 + xi_123 + xi_126 + xi_128;
          _data_pdfs_20_314_10[ctr_0] =
              sub_k_to_f_37 + xi_123 + xi_129 + xi_130;
          _data_pdfs_20_315_10[ctr_0] =
              sub_k_to_f_33 * -1.0f + xi_116 + xi_119 + xi_131;
          _data_pdfs_20_316_10[ctr_0] =
              sub_k_to_f_31 * -1.0f + xi_118 + xi_120 + xi_131;
          _data_pdfs_20_317_10[ctr_0] =
              sub_k_to_f_37 * -1.0f + xi_126 + xi_129 + xi_132;
          _data_pdfs_20_318_10[ctr_0] =
              sub_k_to_f_35 * -1.0f + xi_128 + xi_130 + xi_132;
        }
      }
    }
  }
}
} // namespace internal_48c9ee502281a70505dce0378c55abd5

void CollideSweepSinglePrecisionThermalizedAVX::run(IBlock *block) {
  auto force = block->getData<field::GhostLayerField<float, 3>>(forceID);
  auto pdfs = block->getData<field::GhostLayerField<float, 19>>(pdfsID);

  auto &seed = this->seed_;
  auto block_offset_1 = this->block_offset_1_;
  auto &omega_even = this->omega_even_;
  auto &kT = this->kT_;
  auto block_offset_2 = this->block_offset_2_;
  auto &omega_shear = this->omega_shear_;
  auto &time_step = this->time_step_;
  auto &omega_bulk = this->omega_bulk_;
  auto block_offset_0 = this->block_offset_0_;
  auto &omega_odd = this->omega_odd_;
  auto &rho = this->rho_;
  block_offset_generator(block, block_offset_0, block_offset_1, block_offset_2);
  WALBERLA_ASSERT_GREATER_EQUAL(0, -int_c(force->nrOfGhostLayers()));
  float *RESTRICT const _data_force = force->dataAt(0, 0, 0, 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(0, -int_c(pdfs->nrOfGhostLayers()));
  float *RESTRICT _data_pdfs = pdfs->dataAt(0, 0, 0, 0);
  WALBERLA_ASSERT_EQUAL(pdfs->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)pdfs->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->xSize()) + 0));
  const int64_t _size_force_0 = int64_t(cell_idx_c(force->xSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->ySize()) + 0));
  const int64_t _size_force_1 = int64_t(cell_idx_c(force->ySize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(force->zSize()) + 0));
  const int64_t _size_force_2 = int64_t(cell_idx_c(force->zSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  const int64_t _stride_force_1 = int64_t(force->yStride());
  const int64_t _stride_force_2 = int64_t(force->zStride());
  const int64_t _stride_force_3 = int64_t(1 * int64_t(force->fStride()));
  const int64_t _stride_pdfs_1 = int64_t(pdfs->yStride());
  const int64_t _stride_pdfs_2 = int64_t(pdfs->zStride());
  const int64_t _stride_pdfs_3 = int64_t(1 * int64_t(pdfs->fStride()));
  internal_48c9ee502281a70505dce0378c55abd5::
      collidesweepsingleprecisionthermalizedavx_collidesweepsingleprecisionthermalizedavx(
          _data_force, _data_pdfs, _size_force_0, _size_force_1, _size_force_2,
          _stride_force_1, _stride_force_2, _stride_force_3, _stride_pdfs_1,
          _stride_pdfs_2, _stride_pdfs_3, block_offset_0, block_offset_1,
          block_offset_2, kT, omega_bulk, omega_even, omega_odd, omega_shear,
          rho, seed, time_step);
}

void CollideSweepSinglePrecisionThermalizedAVX::runOnCellInterval(
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

  auto force = block->getData<field::GhostLayerField<float, 3>>(forceID);
  auto pdfs = block->getData<field::GhostLayerField<float, 19>>(pdfsID);

  auto &seed = this->seed_;
  auto block_offset_1 = this->block_offset_1_;
  auto &omega_even = this->omega_even_;
  auto &kT = this->kT_;
  auto block_offset_2 = this->block_offset_2_;
  auto &omega_shear = this->omega_shear_;
  auto &time_step = this->time_step_;
  auto &omega_bulk = this->omega_bulk_;
  auto block_offset_0 = this->block_offset_0_;
  auto &omega_odd = this->omega_odd_;
  auto &rho = this->rho_;
  block_offset_generator(block, block_offset_0, block_offset_1, block_offset_2);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin(), -int_c(force->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin(), -int_c(force->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin(), -int_c(force->nrOfGhostLayers()));
  float *RESTRICT const _data_force =
      force->dataAt(ci.xMin(), ci.yMin(), ci.zMin(), 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(ci.xMin(), -int_c(pdfs->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.yMin(), -int_c(pdfs->nrOfGhostLayers()));
  WALBERLA_ASSERT_GREATER_EQUAL(ci.zMin(), -int_c(pdfs->nrOfGhostLayers()));
  float *RESTRICT _data_pdfs = pdfs->dataAt(ci.xMin(), ci.yMin(), ci.zMin(), 0);
  WALBERLA_ASSERT_EQUAL(pdfs->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)pdfs->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->xSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.xSize()) + 0));
  const int64_t _size_force_0 = int64_t(cell_idx_c(ci.xSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->ySizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.ySize()) + 0));
  const int64_t _size_force_1 = int64_t(cell_idx_c(ci.ySize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  WALBERLA_ASSERT_GREATER_EQUAL(force->zSizeWithGhostLayer(),
                                int64_t(cell_idx_c(ci.zSize()) + 0));
  const int64_t _size_force_2 = int64_t(cell_idx_c(ci.zSize()) + 0);
  WALBERLA_ASSERT_EQUAL(force->layout(), field::fzyx);
  WALBERLA_ASSERT_EQUAL((uintptr_t)force->dataAt(0, 0, 0, 0) % 32, 0);
  const int64_t _stride_force_1 = int64_t(force->yStride());
  const int64_t _stride_force_2 = int64_t(force->zStride());
  const int64_t _stride_force_3 = int64_t(1 * int64_t(force->fStride()));
  const int64_t _stride_pdfs_1 = int64_t(pdfs->yStride());
  const int64_t _stride_pdfs_2 = int64_t(pdfs->zStride());
  const int64_t _stride_pdfs_3 = int64_t(1 * int64_t(pdfs->fStride()));
  internal_48c9ee502281a70505dce0378c55abd5::
      collidesweepsingleprecisionthermalizedavx_collidesweepsingleprecisionthermalizedavx(
          _data_force, _data_pdfs, _size_force_0, _size_force_1, _size_force_2,
          _stride_force_1, _stride_force_2, _stride_force_3, _stride_pdfs_1,
          _stride_pdfs_2, _stride_pdfs_3, block_offset_0, block_offset_1,
          block_offset_2, kT, omega_bulk, omega_even, omega_odd, omega_shear,
          rho, seed, time_step);
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
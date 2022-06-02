// kernel generated with pystencils v0.4.4+2.g825be1d, lbmpy v0.4.4, lbmpy_walberla/pystencils_walberla from commit 3c4ea5df560c4dfdd15076648fc59c830bd64a9d

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
//! \\file DiffusiveFluxKernelWithElectrostatic_single_precision.h
//! \\author pystencils
//======================================================================================================================

#pragma once
#include "core/DataTypes.h"

#include "field/GhostLayerField.h"
#include "field/SwapableCompare.h"
#include "domain_decomposition/BlockDataID.h"
#include "domain_decomposition/IBlock.h"
#include "domain_decomposition/StructuredBlockStorage.h"
#include <set>



#ifdef __GNUC__
#define RESTRICT __restrict__
#elif _MSC_VER
#define RESTRICT __restrict
#else
#define RESTRICT
#endif

#if ( defined WALBERLA_CXX_COMPILER_IS_GNU ) || ( defined WALBERLA_CXX_COMPILER_IS_CLANG )
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#   pragma GCC diagnostic ignored "-Wreorder"
#endif

namespace walberla {
namespace pystencils {


class DiffusiveFluxKernelWithElectrostatic_single_precision
{
public:
    DiffusiveFluxKernelWithElectrostatic_single_precision( float D, BlockDataID jID_, BlockDataID phiID_, BlockDataID rhoID_, float f_ext_0, float f_ext_1, float f_ext_2, float kT, float z )
        : D_(D), jID(jID_), phiID(phiID_), rhoID(rhoID_), f_ext_0_(f_ext_0), f_ext_1_(f_ext_1), f_ext_2_(f_ext_2), kT_(kT), z_(z)
    {};

    

    void run(IBlock * block);
    
    void runOnCellInterval(const shared_ptr<StructuredBlockStorage> & blocks, const CellInterval & globalCellInterval, cell_idx_t ghostLayers, IBlock * block);

    
    void operator() (IBlock * block)
    {
        run(block);
    }
    

    static std::function<void (IBlock *)> getSweep(const shared_ptr<DiffusiveFluxKernelWithElectrostatic_single_precision> & kernel)
    {
        return [kernel] 
               (IBlock * b) 
               { kernel->run(b); };
    }

    static std::function<void (IBlock*)> getSweepOnCellInterval(const shared_ptr<DiffusiveFluxKernelWithElectrostatic_single_precision> & kernel, const shared_ptr<StructuredBlockStorage> & blocks, const CellInterval & globalCellInterval, cell_idx_t ghostLayers=1)
    {
        return [kernel, blocks, globalCellInterval, ghostLayers]
               (IBlock * b) 
               { kernel->runOnCellInterval(blocks, globalCellInterval, ghostLayers, b); };
    }

    std::function<void (IBlock *)> getSweep()
    {
        return [this] 
               (IBlock * b) 
               { this->run(b); };
    }

    std::function<void (IBlock *)> getSweepOnCellInterval(const shared_ptr<StructuredBlockStorage> & blocks, const CellInterval & globalCellInterval, cell_idx_t ghostLayers=1)
    {
        return [this, blocks, globalCellInterval, ghostLayers]
               (IBlock * b) 
               { this->runOnCellInterval(blocks, globalCellInterval, ghostLayers, b); };
    }


    float D_;
    BlockDataID jID;
    BlockDataID phiID;
    BlockDataID rhoID;
    float f_ext_0_;
    float f_ext_1_;
    float f_ext_2_;
    float kT_;
    float z_;

};


} // namespace pystencils
} // namespace walberla


#if ( defined WALBERLA_CXX_COMPILER_IS_GNU ) || ( defined WALBERLA_CXX_COMPILER_IS_CLANG )
#   pragma GCC diagnostic pop
#endif
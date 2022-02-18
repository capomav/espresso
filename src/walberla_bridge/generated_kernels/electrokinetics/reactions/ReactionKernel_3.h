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
//! \\file ReactionKernel_3.h
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


class ReactionKernel_3
{
public:
    ReactionKernel_3( BlockDataID rho_0ID_, BlockDataID rho_1ID_, BlockDataID rho_2ID_, double order_0, double order_1, double order_2, double rate_coefficient, double stoech_0, double stoech_1, double stoech_2 )
        : rho_0ID(rho_0ID_), rho_1ID(rho_1ID_), rho_2ID(rho_2ID_), order_0_(order_0), order_1_(order_1), order_2_(order_2), rate_coefficient_(rate_coefficient), stoech_0_(stoech_0), stoech_1_(stoech_1), stoech_2_(stoech_2)
    {};

    

    void run(IBlock * block);
    
    void runOnCellInterval(const shared_ptr<StructuredBlockStorage> & blocks, const CellInterval & globalCellInterval, cell_idx_t ghostLayers, IBlock * block);

    
    void operator() (IBlock * block)
    {
        run(block);
    }
    

    static std::function<void (IBlock *)> getSweep(const shared_ptr<ReactionKernel_3> & kernel)
    {
        return [kernel] 
               (IBlock * b) 
               { kernel->run(b); };
    }

    static std::function<void (IBlock*)> getSweepOnCellInterval(const shared_ptr<ReactionKernel_3> & kernel, const shared_ptr<StructuredBlockStorage> & blocks, const CellInterval & globalCellInterval, cell_idx_t ghostLayers=1)
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


    BlockDataID rho_0ID;
    BlockDataID rho_1ID;
    BlockDataID rho_2ID;
    double order_0_;
    double order_1_;
    double order_2_;
    double rate_coefficient_;
    double stoech_0_;
    double stoech_1_;
    double stoech_2_;

};


} // namespace pystencils
} // namespace walberla


#if ( defined WALBERLA_CXX_COMPILER_IS_GNU ) || ( defined WALBERLA_CXX_COMPILER_IS_CLANG )
#   pragma GCC diagnostic pop
#endif
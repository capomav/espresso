// kernel generated with pystencils v0.4.3+4.g30da657, lbmpy v0.4.3+2.g0e17e61, lbmpy_walberla/pystencils_walberla from commit 88f85eb7a979f81d68e76009811aeed53ec3014e

#pragma once
#include "stencil/Directions.h"
#include "core/cell/CellInterval.h"
#include "core/DataTypes.h"
#include "field/GhostLayerField.h"
#include "domain_decomposition/IBlock.h"
#include "communication/UniformPackInfo.h"

#define FUNC_PREFIX

#ifdef __GNUC__
#define RESTRICT __restrict__
#elif _MSC_VER
#define RESTRICT __restrict
#else
#define RESTRICT
#endif

namespace walberla {
namespace lbm {


class PushPackInfoSinglePrecision : public ::walberla::communication::UniformPackInfo
{
public:
    PushPackInfoSinglePrecision( BlockDataID pdfsID_ )
        : pdfsID(pdfsID_)
    {};
    virtual ~PushPackInfoSinglePrecision() {}

   bool constantDataExchange() const { return true; }
   bool threadsafeReceiving()  const { return true; }

   void unpackData(IBlock * receiver, stencil::Direction dir, mpi::RecvBuffer & buffer) {
        const auto dataSize = size(dir, receiver);
        unpack(dir, buffer.skip(dataSize), receiver);
   }

   void communicateLocal(const IBlock * sender, IBlock * receiver, stencil::Direction dir) {
       //TODO: optimize by generating kernel for this case
       mpi::SendBuffer sBuffer;
       packData( sender, dir, sBuffer );
       mpi::RecvBuffer rBuffer( sBuffer );
       unpackData( receiver, stencil::inverseDir[dir], rBuffer );
   }

private:
   void packDataImpl(const IBlock * sender, stencil::Direction dir, mpi::SendBuffer & outBuffer) const {
        const auto dataSize = size(dir, sender);
        pack(dir, outBuffer.forward(dataSize), const_cast<IBlock*>(sender));
   }

   void pack  (stencil::Direction dir, unsigned char * buffer, IBlock * block) const;
   void unpack(stencil::Direction dir, unsigned char * buffer, IBlock * block) const;
   uint_t size  (stencil::Direction dir, const IBlock * block) const;

    BlockDataID pdfsID;
};


} // namespace lbm
} // namespace walberla
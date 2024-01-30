#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CPartition{
        private : friend class CWorld;
        
        private : std::uint32_t VLeftward;
        private : std::uint32_t VRightward;
        private : std::uint32_t VBackward;
        private : std::uint32_t VForward;
        private : std::uint32_t VDownward;
        private : std::uint32_t VUpward;

        private : CPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward);
        private : std::uint32_t FLeftward() const;
        private : std::uint32_t FRightward() const;
        private : std::uint32_t FBackward() const;
        private : std::uint32_t FForward() const;
        private : std::uint32_t FDownward() const;
        private : std::uint32_t FUpward() const;
        private : CPartition& FLeftward(std::uint32_t PTexture);
        private : CPartition& FRightward(std::uint32_t PTexture);
        private : CPartition& FBackward(std::uint32_t PTexture);
        private : CPartition& FForward(std::uint32_t PTexture);
        private : CPartition& FDownward(std::uint32_t PTexture);
        private : CPartition& FUpward(std::uint32_t PTexture);
        private : bool FEnclosed();
        private : const CPartition& FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const;
        private : bool FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const;
    };
}
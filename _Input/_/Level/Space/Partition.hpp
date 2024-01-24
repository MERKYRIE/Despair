#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NSpace{
    class CPartition{
        private : friend class CSpace;
        
        private : std::uint32_t VLeftward;
        private : std::uint32_t VRightward;
        private : std::uint32_t VBackward;
        private : std::uint32_t VForward;
        private : std::uint32_t VDownward;
        private : std::uint32_t VUpward;

        public : CPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward);
        public : const CPartition& FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const;
        public : const CPartition& FPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward);
        public : bool FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const;
    };
}
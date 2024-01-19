#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CSpace{
        private : friend class CLevel;

        private :
            struct SPartition{
                std::uint32_t VLeftward;
                std::uint32_t VRightward;
                std::uint32_t VBackward;
                std::uint32_t VForward;
                std::uint32_t VDownward;
                std::uint32_t VUpward;
            };

        private : std::array<std::array<std::array<SPartition , 5> , 5> , 5> VValue;

        private : void FInitialize();

        public : std::uintmax_t FWidth();
        public : std::uintmax_t FDepth();
        public : std::uintmax_t FHeight();
        public : const SPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    }
    GSpace;
}
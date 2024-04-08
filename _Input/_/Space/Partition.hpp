#pragma once

#include"Despair.hpp"

namespace NDespair::NSpace
{    
    class CPartition
    {
        private : std::uint32_t FTextureNegativeX;
        private : std::uint32_t FTexturePositiveX;
        private : std::uint32_t FTextureNegativeY;
        private : std::uint32_t FTexturePositiveY;
        private : std::uint32_t FTextureNegativeZ;
        private : std::uint32_t FTexturePositiveZ;

        public : CPartition();
        public : bool ACanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool AGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool ACanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool AGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : void ARender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool AIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
    };
}
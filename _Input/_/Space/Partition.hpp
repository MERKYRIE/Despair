#pragma once

#include"Blindness.hpp"

namespace NBlindness::NSpace
{    
    class CPartition
    {
        private : std::uint32_t FTextureNegativeX;
        private : std::uint32_t FTexturePositiveX;
        private : std::uint32_t FTextureNegativeY;
        private : std::uint32_t FTexturePositiveY;
        private : std::uint32_t FTextureNegativeZ;
        private : std::uint32_t FTexturePositiveZ;

        public : CPartition
        (
            std::uint32_t PTextureNegativeX ,
            std::uint32_t PTexturePositiveX ,
            std::uint32_t PTextureNegativeY ,
            std::uint32_t PTexturePositiveY ,
            std::uint32_t PTextureNegativeZ ,
            std::uint32_t PTexturePositiveZ
        );
        public : bool OCanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool OGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool OCanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool OGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : void ORender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool OIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
    };
}
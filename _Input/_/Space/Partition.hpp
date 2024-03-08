#pragma once

#include"Blindness.hpp"

namespace NBlindness::NSpace
{    
    class CPartition
    {
        friend class CSpace;
        
        private : std::uint32_t FTextureNegativeX;
        private : std::uint32_t FTexturePositiveX;
        private : std::uint32_t FTextureNegativeY;
        private : std::uint32_t FTexturePositiveY;
        private : std::uint32_t FTextureNegativeZ;
        private : std::uint32_t FTexturePositiveZ;

        private : CPartition();
        private : bool BCanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool BGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool BCanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool BGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : void BRender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool BIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
    };
}
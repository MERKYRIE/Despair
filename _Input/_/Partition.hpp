#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    class CPartition{
        private : std::uint32_t VTextureNegativeX;
        private : std::uint32_t VTexturePositiveX;
        private : std::uint32_t VTextureNegativeY;
        private : std::uint32_t VTexturePositiveY;
        private : std::uint32_t VTextureNegativeZ;
        private : std::uint32_t VTexturePositiveZ;

        public : CPartition(
            std::uint32_t PTextureNegativeX ,
            std::uint32_t PTexturePositiveX ,
            std::uint32_t PTextureNegativeY ,
            std::uint32_t PTexturePositiveY ,
            std::uint32_t PTextureNegativeZ ,
            std::uint32_t PTexturePositiveZ
        );
        public : bool FCanBeGenerated(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FGenerate(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : void FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FIsCollisionDetected(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    };
}
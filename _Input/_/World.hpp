#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    class CPartition;

    inline class CWorld{
        private : static constexpr std::uintmax_t VDistanceAlongX{100};
        private : static constexpr std::uintmax_t VDistanceAlongY{100};
        private : static constexpr std::uintmax_t VDistanceAlongZ{1};
        private : static constexpr std::array<float , 20> VVerticesNegativeX{
            0.0F , 0.0F , 0.0F , 0.0F , 1.0F ,
            0.0F , 0.0F , 1.0F , 0.0F , 0.0F ,
            0.0F , 1.0F , 1.0F , 1.0F , 0.0F ,
            0.0F , 1.0F , 0.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<float , 20> VVerticesPositiveX{
            1.0F , 1.0F , 0.0F , 0.0F , 1.0F ,
            1.0F , 1.0F , 1.0F , 0.0F , 0.0F ,
            1.0F , 0.0F , 1.0F , 1.0F , 0.0F ,
            1.0F , 0.0F , 0.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<float , 20> VVerticesNegativeY{
            1.0F , 0.0F , 0.0F , 0.0F , 1.0F ,
            1.0F , 0.0F , 1.0F , 0.0F , 0.0F ,
            0.0F , 0.0F , 1.0F , 1.0F , 0.0F ,
            0.0F , 0.0F , 0.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<float , 20> VVerticesPositiveY{
            0.0F , 1.0F , 0.0F , 0.0F , 1.0F ,
            0.0F , 1.0F , 1.0F , 0.0F , 0.0F ,
            1.0F , 1.0F , 1.0F , 1.0F , 0.0F ,
            1.0F , 1.0F , 0.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<float , 20> VVerticesNegativeZ{
            0.0F , 0.0F , 0.0F , 0.0F , 1.0F ,
            0.0F , 1.0F , 0.0F , 0.0F , 0.0F ,
            1.0F , 1.0F , 0.0F , 1.0F , 0.0F ,
            1.0F , 0.0F , 0.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<float , 20> VVerticesPositiveZ{
            0.0F , 1.0F , 1.0F , 0.0F , 1.0F ,
            0.0F , 0.0F , 1.0F , 0.0F , 0.0F ,
            1.0F , 0.0F , 1.0F , 1.0F , 0.0F ,
            1.0F , 1.0F , 1.0F , 1.0F , 1.0F
        };
        private : static constexpr std::array<std::uint32_t , 6> VElements{0 , 1 , 2 , 2 , 3 , 0};
        
        private : double VRotation;
        private : std::int8_t VDirectionBackwardX;
        private : std::int8_t VDirectionBackwardY;
        private : std::int8_t VDirectionForwardX;
        private : std::int8_t VDirectionForwardY;
        private : std::vector<std::vector<std::vector<std::shared_ptr<CPartition>>>> VSpace;
        private : double VTranslationRealX;
        private : double VTranslationRealY;
        private : double VTranslationRealZ;
        private : std::uintmax_t VTranslationIntegralX;
        private : std::uintmax_t VTranslationIntegralY;
        private : std::uintmax_t VTranslationIntegralZ;
        private : std::uint32_t VVertexArrayObjectNegativeX;
        private : std::uint32_t VVertexArrayObjectPositiveX;
        private : std::uint32_t VVertexArrayObjectNegativeY;
        private : std::uint32_t VVertexArrayObjectPositiveY;
        private : std::uint32_t VVertexArrayObjectNegativeZ;
        private : std::uint32_t VVertexArrayObjectPositiveZ;
        private : std::uint32_t VVertexBufferObjectNegativeX;
        private : std::uint32_t VVertexBufferObjectPositiveX;
        private : std::uint32_t VVertexBufferObjectNegativeY;
        private : std::uint32_t VVertexBufferObjectPositiveY;
        private : std::uint32_t VVertexBufferObjectNegativeZ;
        private : std::uint32_t VVertexBufferObjectPositiveZ;
        private : std::uint32_t VElementBufferObject;

        public : void FInitialize();
        public : void FUpdate();
        public : std::uintmax_t FDistanceAlongX();
        public : std::uintmax_t FDistanceAlongY();
        public : std::uintmax_t FDistanceAlongZ();
        public : std::uintmax_t FTranslationIntegralX();
        public : std::uintmax_t FTranslationIntegralY();
        public : std::uintmax_t FTranslationIntegralZ();
        public : CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : std::uint32_t FVertexArrayObjectNegativeX();
        public : std::uint32_t FVertexArrayObjectPositiveX();
        public : std::uint32_t FVertexArrayObjectNegativeY();
        public : std::uint32_t FVertexArrayObjectPositiveY();
        public : std::uint32_t FVertexArrayObjectNegativeZ();
        public : std::uint32_t FVertexArrayObjectPositiveZ();
        public : void FDeinitialize();
    }
    GWorld;
}
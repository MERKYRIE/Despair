#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    namespace NWorld{
        class CPartition;
        class CVertexArrayObject;
    }

    inline class CWorld{
        private : static constexpr std::uintmax_t VDistanceAlongX{100};
        private : static constexpr std::uintmax_t VDistanceAlongY{100};
        private : static constexpr std::uintmax_t VDistanceAlongZ{1};
        
        private : float VRotation;
        private : std::int8_t VDirectionBackwardX;
        private : std::int8_t VDirectionBackwardY;
        private : std::int8_t VDirectionForwardX;
        private : std::int8_t VDirectionForwardY;
        private : std::vector<std::vector<std::vector<std::shared_ptr<NWorld::CPartition>>>> VSpace;
        private : float VTranslationRealX;
        private : float VTranslationRealY;
        private : float VTranslationRealZ;
        private : std::uintmax_t VTranslationIntegralX;
        private : std::uintmax_t VTranslationIntegralY;
        private : std::uintmax_t VTranslationIntegralZ;

        public : void FInitialize();
        public : void FUpdate();
        public : std::uintmax_t FDistanceAlongX();
        public : std::uintmax_t FDistanceAlongY();
        public : std::uintmax_t FDistanceAlongZ();
        public : std::uintmax_t FTranslationIntegralX();
        public : std::uintmax_t FTranslationIntegralY();
        public : std::uintmax_t FTranslationIntegralZ();
        public : NWorld::CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : void FDeinitialize();
    }
    GWorld;
}
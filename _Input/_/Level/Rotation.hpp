#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : double VValue;

        private : void FInitialize();
        private : void FUpdate();

        public : double FRealBackwardX();
        public : double FRealBackwardY();
        public : double FRealForwardX();
        public : double FRealForwardY();
        public : std::int8_t FIntegerBackwardX();
        public : std::int8_t FIntegerBackwardY();
        public : std::int8_t FIntegerForwardX();
        public : std::int8_t FIntegerForwardY();
    }
    GRotation;
}
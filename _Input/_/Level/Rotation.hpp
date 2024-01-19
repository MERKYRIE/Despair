#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : double VValue;

        private : void FInitialize();
        private : void FUpdate();

        public : double FRealLeftwardX();
        public : double FRealLeftwardY();
        public : double FRealRightwardX();
        public : double FRealRightwardY();
        public : double FRealBackwardX();
        public : double FRealBackwardY();
        public : double FRealForwardX();
        public : double FRealForwardY();
        public : std::int8_t FIntegerLeftwardX();
        public : std::int8_t FIntegerLeftwardY();
        public : std::int8_t FIntegerRightwardX();
        public : std::int8_t FIntegerRightwardY();
        public : std::int8_t FIntegerBackwardX();
        public : std::int8_t FIntegerBackwardY();
        public : std::int8_t FIntegerForwardX();
        public : std::int8_t FIntegerForwardY();
    }
    GRotation;
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : float VAngle;

        private : void FInitialize();
        private : void FUpdate();

        public : float FLeftX();
        public : float FLeftY();
        public : float FRightX();
        public : float FRightY();
        public : float FBackwardX();
        public : float FBackwardY();
        public : float FForwardX();
        public : float FForwardY();
    }
    GRotation;
}
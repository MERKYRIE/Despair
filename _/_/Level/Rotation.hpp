#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : float VAngle;

        private : void FInitialize();
        private : void FUpdate();

        public : signed char FX();
        public : signed char FZ();
        public : void FLeft();
        public : void FRight();
    }
    GRotation;
}
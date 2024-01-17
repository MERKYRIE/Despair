#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        private : float VX;
        private : float VY;
        private : float VZ;

        private : void FInitialize();
        private : void FUpdate();
    }
    GTranslation;
}
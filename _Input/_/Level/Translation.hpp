#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        private : double VY;
        private : double VZ;

        private : void FInitialize();
        private : void FUpdate();

        public : std::uintmax_t FY();
        public : std::uintmax_t FZ();
    }
    GTranslation;
}
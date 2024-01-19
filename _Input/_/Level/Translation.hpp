#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        private : double VZ;

        private : void FInitialize();
        private : void FUpdate();

        public : std::uintmax_t FZ();
    }
    GTranslation;
}
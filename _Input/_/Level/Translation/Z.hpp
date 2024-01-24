#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NTranslation{
    inline class CZ{
        private : friend class CTranslation;

        private : double VValue;

        private : void FInitialize();
        private : void FUpdate();

        public : std::uintmax_t FInteger();
    }
    GZ;
}
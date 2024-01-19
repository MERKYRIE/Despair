#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NTranslation{
    inline class CX{
        private : friend class CTranslation;

        private : double VValue;

        private : void FInitialize();
        private : operator double();
        private : void operator+=(double PValue);

        public : std::uintmax_t FValue();
    }
    GX;
}
#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        private : double VX;
        private : double VY;
        private : double VZ;

        private : void FInitialize();
        private : void FUpdate();

        public : std::uintmax_t FX();
        public : std::uintmax_t FY();
        public : std::uintmax_t FZ();
    }
    GTranslation;
}
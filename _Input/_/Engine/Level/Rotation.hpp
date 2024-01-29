#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : double VValue;

        private : void FInitialize();
        private : void FUpdate();

        public : std::int8_t FBackwardX();
        public : std::int8_t FBackwardY();
        public : std::int8_t FForwardX();
        public : std::int8_t FForwardY();
    }
    GRotation;
}
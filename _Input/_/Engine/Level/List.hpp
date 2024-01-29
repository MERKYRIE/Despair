#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine::NLevel{
    inline class CList{
        private : friend class CLevel;

        private : std::uint32_t VValue;

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GList;
}
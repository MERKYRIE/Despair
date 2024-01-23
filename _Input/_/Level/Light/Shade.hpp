#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NLight{
    inline class CShade{
        private : friend class CLight;

        private : std::uint32_t VModel;

        private : void FInitialize();
    }
    GShade;
}
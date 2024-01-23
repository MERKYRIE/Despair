#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NLight{
    inline class CModel{
        private : friend class CLight;

        private : std::array<float , 4> VAmbient;
        private : std::array<float , 1> VColorControl;
        private : std::array<float , 1> VLocalViewer;
        private : std::array<float , 1> VTwoSide;
        
        private : void FInitialize();
    }
    GModel;
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CLight{
        private : friend class CLevel;

        private : std::array<float , 4> VAmbient;
        private : std::array<float , 4> VDiffuse;
        private : std::array<float , 4> VSpecular;
        private : std::array<float , 1> VExponent;
        private : std::array<float , 1> VCutoff;
        private : std::array<float , 1> VConstant;
        private : std::array<float , 1> VLinear;
        private : std::array<float , 1> VQuadratic;
        private : std::array<float , 4> VPosition;
        private : std::array<float , 3> VDirection;
        
        private : void FInitialize();
        private : void FUpdate();
    }
    GLight;
}
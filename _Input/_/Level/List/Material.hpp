#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel::NList{
    inline class CMaterial{
        private : friend class CList;

        private : std::array<float , 4> VAmbient;
        private : std::array<float , 4> VDiffuse;
        private : std::array<float , 4> VSpecular;
        private : std::array<float , 4> VEmission;
        private : std::array<float , 1> VShininess;

        private : void FInitialize();
    }
    GMaterial;
}
#pragma once

#include"Blindness.hpp"

#include"Level\\Coordinate.hpp"

namespace NBlindness::NLevel::NTranslation{
    inline class CZ : public CCoordinate{
        private : friend class CTranslation;

        private : void FInitialize();
        private : void FUpdate();
    }
    GZ;
}
#pragma once

#include"Blindness.hpp"

#include"Level\\Dimension.hpp"

namespace NBlindness::NLevel::NSpace{
    inline class CHeight : public CDimension{
        private : friend class CSpace;

        private : void FInitialize();
    }
    GHeight;
}
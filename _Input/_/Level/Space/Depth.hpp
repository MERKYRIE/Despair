#pragma once

#include"Blindness.hpp"

#include"Level\\Dimension.hpp"

namespace NBlindness::NLevel::NSpace{
    inline class CDepth : public CDimension{
        private : friend class CSpace;

        private : void FInitialize();
    }
    GDepth;
}
#pragma once

#include"Blindness.hpp"

#include"Level\\Space\\Side.hpp"

namespace NBlindness::NLevel::NSpace::NPartition{
    class CForward : public CSide{
        private : friend class CPartition;

        public : using CSide::CSide;
    };
}
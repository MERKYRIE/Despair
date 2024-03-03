#pragma once

#include"Blindness.hpp"

namespace NBlindness::NSpace
{
    class CElementBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CElementBufferObject(const std::array<std::uint32_t , 36>& PElements);
        public : ~CElementBufferObject();
    };
}
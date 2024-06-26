#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CElementBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CElementBufferObject(const std::array<std::uint32_t , 6>& PElements);
        public : ~CElementBufferObject();
    };
}
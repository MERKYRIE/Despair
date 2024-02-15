#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld::NVertexArrayObject{
    class CElementBufferObject{
        private : std::uint32_t VIdentifier;

        public : CElementBufferObject(const std::array<std::uint32_t , 36>& PElements);
        public : ~CElementBufferObject();
    };
}
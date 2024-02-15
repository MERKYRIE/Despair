#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld::NVertexArrayObject{
    class CVertexBufferObject{
        private : std::uint32_t VIdentifier;

        public : CVertexBufferObject(const std::array<float , 120>& PVertices);
        public : ~CVertexBufferObject();
    };
}
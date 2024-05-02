#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CVertexBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CVertexBufferObject(const std::array<float , 20>& PVertices);
        public : ~CVertexBufferObject();
    };
}
#pragma once

#include"Core.hpp"

namespace NDespair::NVideo
{
    class CVertexBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CVertexBufferObject(const std::array<float , 120>& PVertices);
        public : ~CVertexBufferObject();
    };
}
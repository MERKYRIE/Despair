#pragma once

#include"Blindness.hpp"

namespace NBlindness::NSpace
{
    class CVertexBufferObject;
    class CElementBufferObject;

    class CVertexArrayObject
    {
        private : std::uint32_t FIdentifier;
        private : std::shared_ptr<CVertexBufferObject> FVertexBufferObject;
        private : std::shared_ptr<CElementBufferObject> FElementBufferObject;

        public : CVertexArrayObject(const std::array<float , 120>& PVertices , const std::array<std::uint32_t , 36>& PElements);
        public : std::uint32_t OIdentifier();
        public : ~CVertexArrayObject();
    };
}
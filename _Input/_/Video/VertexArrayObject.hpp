#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CVertexArrayObject
    {
        private : std::uint32_t FIdentifier;
        private : std::shared_ptr<CVertexBufferObject> FVertexBufferObject;
        private : std::shared_ptr<CElementBufferObject> FElementBufferObject;

        public : CVertexArrayObject(const std::array<float , 20>& PVertices , const std::array<std::uint32_t , 6>& PElements);
        public : std::uint32_t AIdentifier();
        public : CVertexArrayObject* ABind();
        public : ~CVertexArrayObject();
    };
}
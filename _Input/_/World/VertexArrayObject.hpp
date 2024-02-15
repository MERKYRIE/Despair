#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld{
    namespace NVertexArrayObject{
        class CVertexBufferObject;
        class CElementBufferObject;
    }

    class CVertexArrayObject{
        private : std::uint32_t VIdentifier;
        private : std::shared_ptr<NVertexArrayObject::CVertexBufferObject> VVertexBufferObject;
        private : std::shared_ptr<NVertexArrayObject::CElementBufferObject> VElementBufferObject;

        public : CVertexArrayObject(const std::array<float , 120>& PVertices , const std::array<std::uint32_t , 36>& PElements);
        public : std::uint32_t FIdentifier();
        public : ~CVertexArrayObject();
    };
}
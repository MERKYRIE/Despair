#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NBlindness::NSpace
{
    CVertexBufferObject::CVertexBufferObject(const std::array<float , 120>& PVertices)
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , FIdentifier);
        glBufferData(GL_ARRAY_BUFFER , sizeof(PVertices) , PVertices.data() , GL_STATIC_DRAW);
        GDebug.OOpenGraphicsLibraryError();
    }
    CVertexBufferObject::~CVertexBufferObject()
    {
        glDeleteBuffers(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}
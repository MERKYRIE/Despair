#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NDespair::NSpace
{
    CVertexBufferObject::CVertexBufferObject(const std::array<float , 120>& PVertices)
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , FIdentifier);
        glBufferData(GL_ARRAY_BUFFER , sizeof(PVertices) , PVertices.data() , GL_STATIC_DRAW);
        GDebug.AOpenGraphicsLibraryError();
    }
    CVertexBufferObject::~CVertexBufferObject()
    {
        glDeleteBuffers(1 , &FIdentifier);
        GDebug.AOpenGraphicsLibraryError();
    }
}
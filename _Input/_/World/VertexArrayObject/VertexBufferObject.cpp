#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NBlindness::NWorld::NVertexArrayObject{
    CVertexBufferObject::CVertexBufferObject(const std::array<float , 120>& PVertices){
        glGenBuffers(1 , &VIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , VIdentifier);
        glBufferData(GL_ARRAY_BUFFER , sizeof(PVertices) , PVertices.data() , GL_STATIC_DRAW);
        GDebug.FOpenGraphicsLibraryError();
    }

    CVertexBufferObject::~CVertexBufferObject(){
        glDeleteBuffers(1 , &VIdentifier);
        GDebug.FOpenGraphicsLibraryError();
    }
}
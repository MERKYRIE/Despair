#include"ElementBufferObject.hpp"

#include"Debug.hpp"

namespace NBlindness::NWorld::NVertexArrayObject{
    CElementBufferObject::CElementBufferObject(const std::array<std::uint32_t , 36>& PElements){
        glGenBuffers(1 , &VIdentifier);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VIdentifier);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(PElements) , PElements.data() , GL_STATIC_DRAW);
        GDebug.FOpenGraphicsLibraryError();
    }

    CElementBufferObject::~CElementBufferObject(){
        glDeleteBuffers(1 , &VIdentifier);
        GDebug.FOpenGraphicsLibraryError();
    }
}
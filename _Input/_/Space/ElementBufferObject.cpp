#include"ElementBufferObject.hpp"

#include"Debug.hpp"

namespace NBlindness::NSpace
{
    CElementBufferObject::CElementBufferObject(const std::array<std::uint32_t , 36>& PElements)
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , FIdentifier);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(PElements) , PElements.data() , GL_STATIC_DRAW);
        GDebug.OOpenGraphicsLibraryError();
    }
    CElementBufferObject::~CElementBufferObject()
    {
        glDeleteBuffers(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}
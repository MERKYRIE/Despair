#include"VertexArrayObject.hpp"

#include"ElementBufferObject.hpp"
#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NBlindness::NSpace
{
    CVertexArrayObject::CVertexArrayObject(const std::array<float , 120>& PVertices , const std::array<std::uint32_t , 36>& PElements)
    {
        glGenVertexArrays(1 , &FIdentifier);
        glBindVertexArray(FIdentifier);
        FVertexBufferObject.reset(new CVertexBufferObject{PVertices});
        FElementBufferObject.reset(new CElementBufferObject{PElements});
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        GDebug.OOpenGraphicsLibraryError();
    }
    std::uint32_t CVertexArrayObject::OIdentifier()
    {
        return(FIdentifier);
    }
    CVertexArrayObject::~CVertexArrayObject()
    {
        FElementBufferObject.reset();
        FVertexBufferObject.reset();
        glDeleteVertexArrays(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}
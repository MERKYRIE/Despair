#include"VertexArrayObject.hpp"

#include"VertexArrayObject\\ElementBufferObject.hpp"
#include"VertexArrayObject\\VertexBufferObject.hpp"

#include"Debug.hpp"
#include"World.hpp"

namespace NBlindness::NWorld{
    CVertexArrayObject::CVertexArrayObject(const std::array<float , 120>& PVertices , const std::array<std::uint32_t , 36>& PElements){
        glGenVertexArrays(1 , &VIdentifier);
        glBindVertexArray(VIdentifier);
        VVertexBufferObject.reset(new NVertexArrayObject::CVertexBufferObject{PVertices});
        VElementBufferObject.reset(new NVertexArrayObject::CElementBufferObject{PElements});
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        GDebug.FOpenGraphicsLibraryError();
    }

    std::uint32_t CVertexArrayObject::FIdentifier(){
        return VIdentifier;
    }

    CVertexArrayObject::~CVertexArrayObject(){
        VElementBufferObject.reset();
        VVertexBufferObject.reset();
        glDeleteVertexArrays(1 , &VIdentifier);
        GDebug.FOpenGraphicsLibraryError();
    }
}
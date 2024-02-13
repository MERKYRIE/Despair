#include"Partition.hpp"

#include"Debug.hpp"
#include"World.hpp"

namespace NBlindness{
    CPartition::CPartition(
        std::uint32_t PTextureNegativeX ,
        std::uint32_t PTexturePositiveX ,
        std::uint32_t PTextureNegativeY ,
        std::uint32_t PTexturePositiveY ,
        std::uint32_t PTextureNegativeZ ,
        std::uint32_t PTexturePositiveZ
    ){
        VTextureNegativeX = PTextureNegativeX;
        VTexturePositiveX = PTexturePositiveX;
        VTextureNegativeY = PTextureNegativeY;
        VTexturePositiveY = PTexturePositiveY;
        VTextureNegativeZ = PTextureNegativeZ;
        VTexturePositiveZ = PTexturePositiveZ;
    }
    
    bool CPartition::FCanBeGenerated(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return(
            PX == std::clamp<std::uintmax_t>(PX , 0 , GWorld.FDistanceAlongX() - 1) &&
            PY == std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDistanceAlongY() - 1) &&
            PZ == std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FDistanceAlongZ() - 1)
        );
    }

    bool CPartition::FGenerate(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        switch(PX - GWorld.FTranslationIntegralX()){
            case -1:
                if(!VTextureNegativeX && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX){
                    return false;
                }
                VTextureNegativeX = 0;
                GWorld.FPartition(PX , PY , PZ).VTexturePositiveX = 0;
            return true;
            case +1:
                if(!VTexturePositiveX && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX){
                    return false;
                }
                VTexturePositiveX = 0;
                GWorld.FPartition(PX , PY , PZ).VTextureNegativeX = 0;
            return true;
        }
        switch(PY - GWorld.FTranslationIntegralY()){
            case -1:
                if(!VTextureNegativeY && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveY){
                    return false;
                }
                VTextureNegativeY = 0;
                GWorld.FPartition(PX , PY , PZ).VTexturePositiveY = 0;
            return true;
            case +1:
                if(!VTexturePositiveY && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY){
                    return false;
                }
                VTexturePositiveY = 0;
                GWorld.FPartition(PX , PY , PZ).VTextureNegativeY = 0;
            return true;
        }
        GDebug.FError();
        return false;
    }

    void CPartition::FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(VTextureNegativeX){
            glBindVertexArray(GWorld.FVertexArrayObjectNegativeX());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveX){
            glBindVertexArray(GWorld.FVertexArrayObjectPositiveX());
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTextureNegativeY){
            glBindVertexArray(GWorld.FVertexArrayObjectNegativeY());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveY){
            glBindVertexArray(GWorld.FVertexArrayObjectPositiveY());
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTextureNegativeZ){
            glBindVertexArray(GWorld.FVertexArrayObjectNegativeZ());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveZ){
            glBindVertexArray(GWorld.FVertexArrayObjectPositiveZ());
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
    }

    bool CPartition::FIsCollisionDetected(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , GWorld.FDistanceAlongX() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDistanceAlongY() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FDistanceAlongZ() - 1)
        ){
            return false;
        }
        switch(PX - GWorld.FTranslationIntegralX()){
            case -1:
                return !VTextureNegativeX && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX;
            break;
            case +1:
                return !VTexturePositiveX && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX;
            break;
        }
        switch(PY - GWorld.FTranslationIntegralY()){
            case -1:
                return !VTextureNegativeY && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveY;
            break;
            case +1:
                return !VTexturePositiveY && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY;
            break;
        }
        return false;
    }
}
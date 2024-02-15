#include"Partition.hpp"

#include"VertexArrayObject.hpp"

#include"Debug.hpp"
#include"World.hpp"

namespace NBlindness::NWorld{
    CPartition::CPartition(
        std::uintmax_t PX ,
        std::uintmax_t PY ,
        std::uintmax_t PZ ,
        std::uint32_t PTextureNegativeX ,
        std::uint32_t PTexturePositiveX ,
        std::uint32_t PTextureNegativeY ,
        std::uint32_t PTexturePositiveY ,
        std::uint32_t PTextureNegativeZ ,
        std::uint32_t PTexturePositiveZ
    ){
        VVertexArrayObjectNegativeX.reset(new NWorld::CVertexArrayObject{{
            PX + 0.0F , PY + 0.0F , PZ + 0.0F , 0.0F , 1.0F ,
            PX + 0.0F , PY + 0.0F , PZ + 1.0F , 0.0F , 0.0F ,
            PX + 0.0F , PY + 1.0F , PZ + 1.0F , 1.0F , 0.0F ,
            PX + 0.0F , PY + 1.0F , PZ + 0.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VVertexArrayObjectPositiveX.reset(new NWorld::CVertexArrayObject{{
            PX + 1.0F , PY + 1.0F , PZ + 0.0F , 0.0F , 1.0F ,
            PX + 1.0F , PY + 1.0F , PZ + 1.0F , 0.0F , 0.0F ,
            PX + 1.0F , PY + 0.0F , PZ + 1.0F , 1.0F , 0.0F ,
            PX + 1.0F , PY + 0.0F , PZ + 0.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VVertexArrayObjectNegativeY.reset(new NWorld::CVertexArrayObject{{
            PX + 1.0F , PY + 0.0F , PZ + 0.0F , 0.0F , 1.0F ,
            PX + 1.0F , PY + 0.0F , PZ + 1.0F , 0.0F , 0.0F ,
            PX + 0.0F , PY + 0.0F , PZ + 1.0F , 1.0F , 0.0F ,
            PX + 0.0F , PY + 0.0F , PZ + 0.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VVertexArrayObjectPositiveY.reset(new NWorld::CVertexArrayObject{{
            PX + 0.0F , PY + 1.0F , PZ + 0.0F , 0.0F , 1.0F ,
            PX + 0.0F , PY + 1.0F , PZ + 1.0F , 0.0F , 0.0F ,
            PX + 1.0F , PY + 1.0F , PZ + 1.0F , 1.0F , 0.0F ,
            PX + 1.0F , PY + 1.0F , PZ + 0.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VVertexArrayObjectNegativeZ.reset(new NWorld::CVertexArrayObject{{
            PX + 0.0F , PY + 0.0F , PZ + 0.0F , 0.0F , 1.0F ,
            PX + 0.0F , PY + 1.0F , PZ + 0.0F , 0.0F , 0.0F ,
            PX + 1.0F , PY + 1.0F , PZ + 0.0F , 1.0F , 0.0F ,
            PX + 1.0F , PY + 0.0F , PZ + 0.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VVertexArrayObjectPositiveZ.reset(new NWorld::CVertexArrayObject{{
            PX + 0.0F , PY + 1.0F , PZ + 1.0F , 0.0F , 1.0F ,
            PX + 0.0F , PY + 0.0F , PZ + 1.0F , 0.0F , 0.0F ,
            PX + 1.0F , PY + 0.0F , PZ + 1.0F , 1.0F , 0.0F ,
            PX + 1.0F , PY + 1.0F , PZ + 1.0F , 1.0F , 1.0F
        }
        , {0 , 1 , 2 , 2 , 3 , 0}});
        VTextureNegativeX = PTextureNegativeX;
        VTexturePositiveX = PTexturePositiveX;
        VTextureNegativeY = PTextureNegativeY;
        VTexturePositiveY = PTexturePositiveY;
        VTextureNegativeZ = PTextureNegativeZ;
        VTexturePositiveZ = PTexturePositiveZ;
    }
    
    bool CPartition::FCanGenerateTransition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return PX == std::clamp<std::uintmax_t>(PX , 0 , GWorld.FDistanceAlongX() - 1) &&
            PY == std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDistanceAlongY() - 1) &&
            PZ == std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FDistanceAlongZ() - 1);
    }

    bool CPartition::FGenerateNewTransition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
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

    bool CPartition::FCanGenerateShaft(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return (!VTextureNegativeX || !VTexturePositiveX || !VTextureNegativeY || !VTexturePositiveX) && (
            !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX ||
            !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX ||
            !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY ||
            !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX
        );
    }

    bool CPartition::FGenerateNewShaft(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        switch(PZ - GWorld.FTranslationIntegralZ()){
            case -1:
                if(!VTextureNegativeZ && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveZ){
                    return false;
                }
                VTextureNegativeZ = 0;
                GWorld.FPartition(PX , PY , PZ).VTexturePositiveZ = 0;
            return true;
            case +1:
                if(!VTexturePositiveZ && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeZ){
                    return false;
                }
                VTexturePositiveZ = 0;
                GWorld.FPartition(PX , PY , PZ).VTextureNegativeZ = 0;
            return true;
        }
        GDebug.FError();
        return false;
    }

    void CPartition::FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(VTextureNegativeX){
            glBindVertexArray(VVertexArrayObjectNegativeX->FIdentifier());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveX){
            glBindVertexArray(VVertexArrayObjectPositiveX->FIdentifier());
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTextureNegativeY){
            glBindVertexArray(VVertexArrayObjectNegativeY->FIdentifier());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveY){
            glBindVertexArray(VVertexArrayObjectPositiveY->FIdentifier());
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTextureNegativeZ){
            glBindVertexArray(VVertexArrayObjectNegativeZ->FIdentifier());
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(VTexturePositiveZ){
            glBindVertexArray(VVertexArrayObjectPositiveZ->FIdentifier());
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
            return true;
        }
        switch(PX - GWorld.FTranslationIntegralX()){
            case -1:
                return !(!VTextureNegativeX && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX);
            break;
            case +1:
                return !(!VTexturePositiveX && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX);
            break;
        }
        switch(PY - GWorld.FTranslationIntegralY()){
            case -1:
                return !(!VTextureNegativeY && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveY);
            break;
            case +1:
                return !(!VTexturePositiveY && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY);
            break;
        }
        switch(PZ - GWorld.FTranslationIntegralZ()){
            case -1:
                return !(!VTextureNegativeZ && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveZ);
            break;
            case +1:
                return !(!VTexturePositiveZ && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeZ);
            break;
        }
        return true;
    }

    CPartition::~CPartition(){
        VVertexArrayObjectNegativeX.reset();
        VVertexArrayObjectPositiveX.reset();
        VVertexArrayObjectNegativeY.reset();
        VVertexArrayObjectPositiveY.reset();
        VVertexArrayObjectNegativeZ.reset();
        VVertexArrayObjectPositiveZ.reset();
    }
}
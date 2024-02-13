#include"Partition.hpp"

#include"Debug.hpp"
#include"World.hpp"

namespace NBlindness::NWorld::NCube{
    bool FCanBeGenerated(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return(
            PX == std::clamp<std::uintmax_t>(PX , 0 , GWorld.FDistanceAlongX() - 1) &&
            PY == std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDistanceAlongY() - 1) &&
            PZ == std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FDistanceAlongZ() - 1)
        );
    }

    bool FGenerate(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        switch(PX - GWorld.FTranslationIntegralX()){
            case -1:
                if(!GCube->VTextureNegativeX && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX){
                    return false;
                }
                GCube->VTextureNegativeX = 0;
                GWorld.FPartition(PX , PY , PZ).VTexturePositiveX = 0;
            return true;
            case +1:
                if(!GCube->VTexturePositiveX && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX){
                    return false;
                }
                GCube->VTexturePositiveX = 0;
                GWorld.FPartition(PX , PY , PZ).VTextureNegativeX = 0;
            return true;
        }
        switch(PY - GWorld.FTranslationIntegralY()){
            case -1:
                if(!GCube->VTextureNegativeY && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveY){
                    return false;
                }
                GCube->VTextureNegativeY = 0;
                GWorld.FPartition(PX , PY , PZ).VTexturePositiveY = 0;
            return true;
            case +1:
                if(!GCube->VTexturePositiveY && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY){
                    return false;
                }
                GCube->VTexturePositiveY = 0;
                GWorld.FPartition(PX , PY , PZ).VTextureNegativeY = 0;
            return true;
        }
        GDebug.FError();
        return false;
    }

    void FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        /*
        if(VTextureNegativeX){
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeX);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 0.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 0.0);
            glEnd();
        }
        if(VTexturePositiveX){
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveX);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 0.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 0.0);
            glEnd();
        }
        if(VTextureNegativeY){
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeY);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 0.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 0.0);
            glEnd();
        }
        if(VTexturePositiveY){
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveY);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 0.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 0.0);
            glEnd();
        }
        if(VTextureNegativeZ){
            glBindTexture(GL_TEXTURE_2D , VTextureNegativeZ);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 0.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 0.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 0.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 0.0);
            glEnd();
        }
        if(VTexturePositiveZ){
            glBindTexture(GL_TEXTURE_2D , VTexturePositiveZ);
            glBegin(GL_QUADS);
                glTexCoord2d(0.0 , 1.0);
                glVertex3d(PX + 0.0 , PY + 1.0 , PZ + 1.0);
                glTexCoord2d(0.0 , 0.0);
                glVertex3d(PX + 0.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 0.0);
                glVertex3d(PX + 1.0 , PY + 0.0 , PZ + 1.0);
                glTexCoord2d(1.0 , 1.0);
                glVertex3d(PX + 1.0 , PY + 1.0 , PZ + 1.0);
            glEnd();
        }
        */
    }

    bool FIsCollisionDetected(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , GWorld.FDistanceAlongX() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDistanceAlongY() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FDistanceAlongZ() - 1)
        ){
            return false;
        }
        switch(PX - GWorld.FTranslationIntegralX()){
            case -1:
                return !GCube->VTextureNegativeX && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveX;
            break;
            case +1:
                return !GCube->VTexturePositiveX && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeX;
            break;
        }
        switch(PY - GWorld.FTranslationIntegralY()){
            case -1:
                return !GCube->VTextureNegativeY && !GWorld.FPartition(PX , PY , PZ).VTexturePositiveY;
            break;
            case +1:
                return !GCube->VTexturePositiveY && !GWorld.FPartition(PX , PY , PZ).VTextureNegativeY;
            break;
        }
        return false;
    }
}
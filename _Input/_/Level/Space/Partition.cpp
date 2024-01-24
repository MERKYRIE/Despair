#include"Partition.hpp"

#include"Level\\Space.hpp"
#include"Level\\Translation.hpp"
#include"Video\\Atlas.hpp"

namespace NBlindness::NLevel::NSpace{
    CPartition::CPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward){
        VLeftward = PLeftward;
        VRightward = PRightward;
        VBackward = PBackward;
        VForward = PForward;
        VDownward = PDownward;
        VUpward = PUpward;
    }

    const CPartition& CPartition::FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const{
        if(VLeftward){
            glBindTexture(GL_TEXTURE_2D , VLeftward);
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
        if(VRightward){
            glBindTexture(GL_TEXTURE_2D , VRightward);
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
        if(VBackward){
            glBindTexture(GL_TEXTURE_2D , VBackward);
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
        if(VForward){
            glBindTexture(GL_TEXTURE_2D , VForward);
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
        if(VDownward){
            glBindTexture(GL_TEXTURE_2D , VDownward);
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
        if(VUpward){
            glBindTexture(GL_TEXTURE_2D , VUpward);
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
        return *this;
    }

    const CPartition& CPartition::FPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward){
        VLeftward = PLeftward;
        VRightward = PRightward;
        VBackward = PBackward;
        VForward = PForward;
        VDownward = PDownward;
        VUpward = PUpward;
        return *this;
    }

    bool CPartition::FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const{
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , GSpace.FWidth() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , GSpace.FDepth() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , GSpace.FHeight() - 1)
        ){
            return false;
        }
        if(PX - GTranslation.FX()){
            switch(PX - GTranslation.FX()){
                case -1:
                    return !VLeftward && !GSpace.FPartition(PX , PY , PZ).VRightward;
                break;
                case +1:
                    return !VRightward && !GSpace.FPartition(PX , PY , PZ).VLeftward;
                break;
            }
        }
        if(PY - GTranslation.FY()){
            switch(PY - GTranslation.FY()){
                case -1:
                    return !VBackward && !GSpace.FPartition(PX , PY , PZ).VForward;
                break;
                case +1:
                    return !VForward && !GSpace.FPartition(PX , PY , PZ).VBackward;
                break;
            }
        }
        return false;
    }
}
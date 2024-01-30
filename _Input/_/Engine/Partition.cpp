#include"Partition.hpp"

#include"World.hpp"

namespace NBlindness::NEngine{
    CPartition::CPartition(std::uint32_t PLeftward , std::uint32_t PRightward , std::uint32_t PBackward , std::uint32_t PForward , std::uint32_t PDownward , std::uint32_t PUpward){
        VLeftward = PLeftward;
        VRightward = PRightward;
        VBackward = PBackward;
        VForward = PForward;
        VDownward = PDownward;
        VUpward = PUpward;
    }
    
    std::uint32_t CPartition::FLeftward() const{
        return VLeftward;
    }

    std::uint32_t CPartition::FRightward() const{
        return VRightward;
    }

    std::uint32_t CPartition::FBackward() const{
        return VBackward;
    }

    std::uint32_t CPartition::FForward() const{
        return VForward;
    }

    std::uint32_t CPartition::FDownward() const{
        return VDownward;
    }

    std::uint32_t CPartition::FUpward() const{
        return VUpward;
    }
    
    CPartition& CPartition::FLeftward(std::uint32_t PTexture){
        VLeftward = PTexture;
        return *this;
    }

    CPartition& CPartition::FRightward(std::uint32_t PTexture){
        VRightward = PTexture;
        return *this;
    }

    CPartition& CPartition::FBackward(std::uint32_t PTexture){
        VBackward = PTexture;
        return *this;
    }

    CPartition& CPartition::FForward(std::uint32_t PTexture){
        VForward = PTexture;
        return *this;
    }

    CPartition& CPartition::FDownward(std::uint32_t PTexture){
        VDownward = PTexture;
        return *this;
    }

    CPartition& CPartition::FUpward(std::uint32_t PTexture){
        VUpward = PTexture;
        return *this;
    }

    bool CPartition::FEnclosed(){
        return VRightward && VForward && VLeftward && VBackward;
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

    bool CPartition::FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ) const{
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , GWorld.FWidth() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , GWorld.FDepth() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , GWorld.FHeight() - 1)
        ){
            return false;
        }
        if(PX - GWorld.FX()){
            switch(PX - GWorld.FX()){
                case -1:
                    return !VLeftward && !GWorld.FPartition(PX , PY , PZ).VRightward;
                break;
                case +1:
                    return !VRightward && !GWorld.FPartition(PX , PY , PZ).VLeftward;
                break;
            }
        }
        if(PY - GWorld.FY()){
            switch(PY - GWorld.FY()){
                case -1:
                    return !VBackward && !GWorld.FPartition(PX , PY , PZ).VForward;
                break;
                case +1:
                    return !VForward && !GWorld.FPartition(PX , PY , PZ).VBackward;
                break;
            }
        }
        return false;
    }
}
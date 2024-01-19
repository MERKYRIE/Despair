#include"List.hpp"

#include"Space.hpp"

namespace NBlindness::NLevel{
    void CList::FInitialize(){
        VValue = glGenLists(1);
        glNewList(VValue , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < GSpace.FWidth() ; LX++){
            for(std::uintmax_t LY{0} ; LY < GSpace.FDepth() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < GSpace.FHeight() ; LZ++){
                    glColor4ub(255 , 255 , 255 , 255);
                    if(GSpace.FPartition(LX , LY , LZ).VLeftward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VLeftward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 0.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 0.0);
                        glEnd();
                    }
                    if(GSpace.FPartition(LX , LY , LZ).VRightward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VRightward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 0.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 0.0);
                        glEnd();
                    }
                    if(GSpace.FPartition(LX , LY , LZ).VBackward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VBackward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 0.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 0.0);
                        glEnd();
                    }
                    if(GSpace.FPartition(LX , LY , LZ).VForward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VForward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 0.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 0.0);
                        glEnd();
                    }
                    if(GSpace.FPartition(LX , LY , LZ).VDownward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VDownward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 0.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 0.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 0.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 0.0);
                        glEnd();
                    }
                    if(GSpace.FPartition(LX , LY , LZ).VUpward){
                        glBindTexture(GL_TEXTURE_2D , GSpace.FPartition(LX , LY , LZ).VUpward);
                        glBegin(GL_QUADS);
                            glTexCoord2d(0.0 , 1.0);
                            glVertex3d(LX + 0.0 , LY + 1.0 , LZ + 1.0);
                            glTexCoord2d(0.0 , 0.0);
                            glVertex3d(LX + 0.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 0.0);
                            glVertex3d(LX + 1.0 , LY + 0.0 , LZ + 1.0);
                            glTexCoord2d(1.0 , 1.0);
                            glVertex3d(LX + 1.0 , LY + 1.0 , LZ + 1.0);
                        glEnd();
                    }
                }
            }
        }
        glEndList();
    }

    void CList::FUpdate(){
        glCallList(VValue);
    }

    void CList::FDeinitialize(){
        glDeleteLists(VValue , 1);
    }
}
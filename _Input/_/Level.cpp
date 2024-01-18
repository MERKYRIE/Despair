#include"Level.hpp"

#include"Level\\Rotation.hpp"
#include"Level\\Translation.hpp"

#include"Video.hpp"
#include"Video\\Atlas.hpp"

namespace NBlindness{
    void CLevel::FInitialize(){
        NLevel::GRotation.FInitialize();
        NLevel::GTranslation.FInitialize();
        std::uint32_t LFloor{NVideo::GAtlas.FTexture("\\sfloor4_5.png")};
        std::uint32_t LWall000{NVideo::GAtlas.FTexture("\\twall2_3.png")};
        std::uint32_t LWall010{NVideo::GAtlas.FTexture("\\twall2_5.png")};
        std::uint32_t LWall020{NVideo::GAtlas.FTexture("\\twall2_6.png")};
        std::uint32_t LWall110{NVideo::GAtlas.FTexture("\\twall5_3.png")};
        std::uint32_t LWall210{NVideo::GAtlas.FTexture("\\uwall1_2.png")};
        std::uint32_t LCeiling{NVideo::GAtlas.FTexture("\\plat_top1.png")};
        for(std::uintmax_t LX{0} ; LX < VSpace.size() ; LX++){
            for(std::uintmax_t LY{0} ; LY < VSpace[0].size() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VSpace[0][0].size() ; LZ++){
                    VSpace[LX][LY][LZ].VLeftward = LWall000;
                    VSpace[LX][LY][LZ].VRightward = LWall000;
                    VSpace[LX][LY][LZ].VBackward = LWall000;
                    VSpace[LX][LY][LZ].VForward = LWall000;
                    VSpace[LX][LY][LZ].VDownward = LFloor;
                    VSpace[LX][LY][LZ].VUpward = LCeiling;
                }
            }
        }
        VSpace[0][2][0].VForward = LWall020;
        VSpace[0][2][0].VLeftward = LWall020;
        VSpace[0][2][0].VRightward = LWall020;
        VSpace[0][2][0].VBackward = 0;

        VSpace[0][1][0].VForward = 0;         VSpace[1][1][0].VForward = LWall110;  VSpace[2][1][0].VForward = LWall210;
        VSpace[0][1][0].VLeftward = LWall010; VSpace[1][1][0].VLeftward = 0;        VSpace[2][1][0].VLeftward = 0;
        VSpace[0][1][0].VRightward = 0;       VSpace[1][1][0].VRightward = 0;       VSpace[2][1][0].VRightward = LWall210;
                                              VSpace[1][1][0].VBackward = LWall110; VSpace[2][1][0].VBackward = LWall210;
        VSpace[0][1][0].VBackward = 0;        

        VSpace[0][0][0].VForward = 0;
        VSpace[0][0][0].VLeftward = LWall000;
        VSpace[0][0][0].VRightward = LWall000;
        VSpace[0][0][0].VBackward = LWall000;
        VList = glGenLists(1);
        glNewList(VList , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < VSpace.size() ; LX++){
            for(std::uintmax_t LY{0} ; LY < VSpace[0].size() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VSpace[0][0].size() ; LZ++){
                    glColor4ub(255 , 255 , 255 , 255);
                    if(VSpace[LX][LY][LZ].VLeftward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VLeftward);
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
                    if(VSpace[LX][LY][LZ].VRightward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VRightward);
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
                    if(VSpace[LX][LY][LZ].VBackward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VBackward);
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
                    if(VSpace[LX][LY][LZ].VForward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VForward);
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
                    if(VSpace[LX][LY][LZ].VDownward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VDownward);
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
                    if(VSpace[LX][LY][LZ].VUpward){
                        glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VUpward);
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

    void CLevel::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0 , GVideo.FRatio() , 0.25 , 1'000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        NLevel::GRotation.FUpdate();
        NLevel::GTranslation.FUpdate();
        glCallList(VList);
    }

    void CLevel::FDeinitialize(){
        glDeleteLists(VList , 1);
    }

    bool CLevel::FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , VSpace.size() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , VSpace[0].size() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , VSpace[0][0].size() - 1)
        ){
            return false;
        }
        if(PX - NLevel::GTranslation.FX()){
            switch(PX - NLevel::GTranslation.FX()){
                case -1:
                    return !VSpace[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VLeftward && !VSpace[PX][PY][PZ].VRightward;
                break;
                case +1:
                    return !VSpace[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VRightward && !VSpace[PX][PY][PZ].VLeftward;
                break;
            }
        }
        if(PY - NLevel::GTranslation.FY()){
            switch(PY - NLevel::GTranslation.FY()){
                case -1:
                    return !VSpace[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VBackward && !VSpace[PX][PY][PZ].VForward;
                break;
                case +1:
                    return !VSpace[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VForward && !VSpace[PX][PY][PZ].VBackward;
                break;
            }
        }
        return false;
    }
}
#include"Level.hpp"

#include"Level\\Rotation.hpp"
#include"Level\\Translation.hpp"

#include"Debug\\Assert\\Error.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"
#include"Video.hpp"

namespace NBlindness{
    void CLevel::FInitialize(){
        NLevel::GRotation.FInitialize();
        NLevel::GTranslation.FInitialize();
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FFlags(IMG_Init(IMG_INIT_PNG));
        SDL_Surface* LSurface{IMG_Load("Textures\\edoor01_1.png")};
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(LSurface);
        std::uint32_t LTexture;
        glGenTextures(1 , &LTexture);
        glBindTexture(GL_TEXTURE_2D , LTexture);
        glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , LSurface->w , LSurface->h , 0 , GL_RGB , GL_UNSIGNED_BYTE , LSurface->pixels);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
        NDebug::NAssert::GError.FOpenGraphicsLibrary();
        SDL_FreeSurface(LSurface);
        for(std::uintmax_t LX{0} ; LX < VSpace.size() ; LX++){
            for(std::uintmax_t LY{0} ; LY < VSpace[0].size() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VSpace[0][0].size() ; LZ++){
                    VSpace[LX][LY][LZ].VLeftward = LTexture;
                    VSpace[LX][LY][LZ].VRightward = LTexture;
                    VSpace[LX][LY][LZ].VBackward = LTexture;
                    VSpace[LX][LY][LZ].VForward = LTexture;
                    VSpace[LX][LY][LZ].VDownward = LTexture;
                    VSpace[LX][LY][LZ].VUpward = LTexture;
                }
            }
        }
        VSpace[0][2][0].VBackward = 0;

        VSpace[0][1][0].VForward = 0;
        VSpace[0][1][0].VRightward = 0; VSpace[1][1][0].VLeftward = 0; VSpace[1][1][0].VRightward = 0; VSpace[2][1][0].VLeftward = 0;
        VSpace[0][1][0].VBackward = 0;

        VSpace[0][0][0].VForward = 0;
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
        IMG_Quit();
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
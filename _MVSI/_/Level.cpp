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
        VList = glGenLists(1);
        glNewList(VList , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < VSpace.size() ; LX++){
            for(std::uintmax_t LY{0} ; LY < VSpace[0].size() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VSpace[0][0].size() ; LZ++){
                    glColor4ub(255 , 255 , 255 , 255);
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VLeftward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 0.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 0.0F);
                    glEnd();
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VRightward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 0.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 0.0F);
                    glEnd();
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VBackward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 0.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 0.0F);
                    glEnd();
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VForward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 0.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 0.0F);
                    glEnd();
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VDownward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 0.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 0.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 0.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 0.0F);
                    glEnd();
                    glBindTexture(GL_TEXTURE_2D , VSpace[LX][LY][LZ].VUpward);
                    glBegin(GL_QUADS);
                        glTexCoord2f(0.0F , 1.0F);
                        glVertex3f(LX + 0.0F , LY + 0.0F , LZ + 1.0F);
                        glTexCoord2f(0.0F , 0.0F);
                        glVertex3f(LX + 0.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 0.0F);
                        glVertex3f(LX + 1.0F , LY + 1.0F , LZ + 1.0F);
                        glTexCoord2f(1.0F , 1.0F);
                        glVertex3f(LX + 1.0F , LY + 0.0F , LZ + 1.0F);
                    glEnd();
                }
            }
        }
        glEndList();
    }

    void CLevel::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0F , GVideo.FRatio() , 0.25F , 1'000.0F);
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
}
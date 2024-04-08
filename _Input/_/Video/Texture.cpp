#include"Texture.hpp"

#include"Debug.hpp"

namespace NDespair::NVideo
{
    CTexture::CTexture(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        SDL_Surface* LSurface{IMG_Load(PPath.c_str())};
        GDebug.ASimpleDirectMediaLayerHandleError(LSurface);
        SDL_Surface* LConverted{SDL_ConvertSurfaceFormat(LSurface , SDL_PIXELFORMAT_RGBA32 , 0)};
        GDebug.ASimpleDirectMediaLayerHandleError(LConverted);
        glGenTextures(1 , &FIdentifier);
        glBindTexture(GL_TEXTURE_2D , FIdentifier);
        glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LConverted->w , LConverted->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LConverted->pixels);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
        GDebug.AOpenGraphicsLibraryError();
        SDL_FreeSurface(LConverted);
        SDL_FreeSurface(LSurface);
    }
    bool CTexture::AEqual(const std::string& PPath)
    {
        return(FPath == PPath);
    }
    std::uint32_t CTexture::AIdentifier()
    {
        return(FIdentifier);
    }
    CTexture::~CTexture()
    {
        glDeleteTextures(1 , &FIdentifier);
        GDebug.AOpenGraphicsLibraryError();
    }
}
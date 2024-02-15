#include"Texture.hpp"

#include"Debug.hpp"

namespace NBlindness::NVideo{
    bool CTexture::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CTexture::CTexture(const std::string& PPath){
        VPath = PPath.substr(PPath.find('\\'));
        SDL_Surface* LSurface{IMG_Load(PPath.c_str())};
        GDebug.FSimpleDirectMediaLayerHandleError(LSurface);
        SDL_Surface* LConverted{SDL_ConvertSurfaceFormat(LSurface , SDL_PIXELFORMAT_RGBA32 , 0)};
        GDebug.FSimpleDirectMediaLayerHandleError(LConverted);
        glGenTextures(1 , &VIdentifier);
        glBindTexture(GL_TEXTURE_2D , VIdentifier);
        glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LConverted->w , LConverted->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LConverted->pixels);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
        GDebug.FOpenGraphicsLibraryError();
        SDL_FreeSurface(LConverted);
        SDL_FreeSurface(LSurface);
    }

    std::uint32_t CTexture::FIdentifier() const{
        return VIdentifier;
    }

    CTexture::~CTexture(){
        glDeleteTextures(1 , &VIdentifier);
        GDebug.FOpenGraphicsLibraryError();
    }
}
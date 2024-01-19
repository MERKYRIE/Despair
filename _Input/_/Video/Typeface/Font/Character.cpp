#include"Character.hpp"

#include"Debug\\Assert\\Error.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NVideo::NTypeface::NFont{
    CCharacter::CCharacter(TTF_Font* PFont , char PCode){
        SDL_Surface* LSurface{TTF_RenderText_Blended(PFont , std::string{PCode}.c_str() , SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}})};
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(LSurface);
        SDL_Surface* LConverted{SDL_ConvertSurfaceFormat(LSurface , SDL_PIXELFORMAT_RGBA32 , 0)};
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(LConverted);
        glGenTextures(1 , &VIdentifier);
        glBindTexture(GL_TEXTURE_2D , VIdentifier);
        glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LConverted->w , LConverted->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LConverted->pixels);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
        NDebug::NAssert::GError.FOpenGraphicsLibrary();
        SDL_FreeSurface(LConverted);
        SDL_FreeSurface(LSurface);
    }

    std::uint32_t CCharacter::FIdentifier() const{
        return VIdentifier;
    }

    CCharacter::~CCharacter(){
        glDeleteTextures(1 , &VIdentifier);
        NDebug::NAssert::GError.FOpenGraphicsLibrary();
    }
}
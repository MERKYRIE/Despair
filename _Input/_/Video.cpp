#include"Video.hpp"

#include"Video\\Atlas.hpp"
#include"Video\\Typeface.hpp"

#include"Debug\\Assert\\Error.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness{
    void CVideo::FInitialize(){
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 2));
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 1));
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(VWindow = SDL_CreateWindow("Blindness" , 0 , 0 , 1600 , 900 , SDL_WINDOW_OPENGL));
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(VContext = SDL_GL_CreateContext(VWindow));
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_GL_SetSwapInterval(0));
        SDL_DisplayMode LMode;
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_GetWindowDisplayMode(VWindow , &LMode));
        VRatio = static_cast<float>(LMode.w) / static_cast<float>(LMode.h);
        VInversedRatio = static_cast<float>(LMode.h) / static_cast<float>(LMode.w);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        NDebug::NAssert::GError.FOpenGraphicsLibrary();
        NVideo::GAtlas.FInitialize();
        NVideo::GTypeface.FInitialize();
    }

    void CVideo::FPreupdate(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void CVideo::FPostupdate(){
        SDL_GL_SwapWindow(VWindow);
    }

    void CVideo::FDeinitialize(){
        NVideo::GTypeface.FDeinitialize();
        NVideo::GAtlas.FDeinitialize();
        SDL_GL_DeleteContext(VContext);
        SDL_DestroyWindow(VWindow);
    }

    float CVideo::FRatio(){
        return VRatio;
    }

    float CVideo::FInversedRatio(){
        return VInversedRatio;
    }
}
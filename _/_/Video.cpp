#include "Video.hpp"

#include "Debug\\Assert\\Error.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"

namespace NMRKOGL
{
    void CVideo::FInitialize()
    {
        NDebug::NAssert::NError::GSDL.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 2));
        NDebug::NAssert::NError::GSDL.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 1));
        NDebug::NAssert::NError::GSDL.FHandle(VWindow = SDL_CreateWindow("MRKOGL" , 0 , 0 , 1600 , 900 , SDL_WINDOW_OPENGL));
        NDebug::NAssert::NError::GSDL.FHandle(VContext = SDL_GL_CreateContext(VWindow));
        NDebug::NAssert::NError::GSDL.FCode(SDL_GL_SetSwapInterval(0));
        SDL_DisplayMode LMode;
        NDebug::NAssert::NError::GSDL.FCode(SDL_GetWindowDisplayMode(VWindow , &LMode));
        VRatio = static_cast<float>(LMode.w) / static_cast<float>(LMode.h);
        VInversedRatio = static_cast<float>(LMode.h) / static_cast<float>(LMode.w);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        NDebug::NAssert::GError.FOGL();
    }

    void CVideo::FPreupdate()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    float CVideo::FRatio()
    {
        return VRatio;
    }

    float CVideo::FInversedRatio()
    {
        return VInversedRatio;
    }

    void CVideo::FPostupdate()
    {
        SDL_GL_SwapWindow(VWindow);
    }

    void CVideo::FDeinitialize()
    {
        SDL_GL_DeleteContext(VContext);
        SDL_DestroyWindow(VWindow);
    }
}
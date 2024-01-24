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
        SDL_DisplayMode LDisplayMode;
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_GetWindowDisplayMode(VWindow , &LDisplayMode));
        VRatio = static_cast<float>(LDisplayMode.w) / static_cast<float>(LDisplayMode.h);
        VInversedRatio = static_cast<float>(LDisplayMode.h) / static_cast<float>(LDisplayMode.w);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glShadeModel(GL_SMOOTH);
        std::array<float , 4> LLightModelAmbient{-0.1F , -0.1F , -0.1F , 1.0F};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT , LLightModelAmbient.data());
        std::array<float , 1> LLightModelColorControl{GL_SINGLE_COLOR};
        glLightModelfv(GL_LIGHT_MODEL_COLOR_CONTROL , LLightModelColorControl.data());
        std::array<float , 1> LLightModelLocalViewer{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER , LLightModelLocalViewer.data());
        std::array<float , 1> LLightModelTwoSide{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE , LLightModelTwoSide.data());
        std::array<float , 4> LLightAmbient{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_AMBIENT , LLightAmbient.data());
        std::array<float , 4> LLightDiffuse{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_DIFFUSE , LLightDiffuse.data());
        std::array<float , 4> LLightSpecular{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_SPECULAR , LLightSpecular.data());
        std::array<float , 1> LLightSpotExponent{1.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_EXPONENT , LLightSpotExponent.data());
        std::array<float , 1> LLightSpotCutoff{60.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_CUTOFF , LLightSpotCutoff.data());
        std::array<float , 1> LLightConstantAttenuation{1.0F};
        glLightfv(GL_LIGHT0 , GL_CONSTANT_ATTENUATION , LLightConstantAttenuation.data());
        std::array<float , 1> LLightLinearAttenuation{0.0F};
        glLightfv(GL_LIGHT0 , GL_LINEAR_ATTENUATION , LLightLinearAttenuation.data());
        std::array<float , 1> LLightQuadraticAttenuation{1.0F};
        glLightfv(GL_LIGHT0 , GL_QUADRATIC_ATTENUATION , LLightQuadraticAttenuation.data());
        std::array<float , 4> LMaterialAmbient{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_AMBIENT , LMaterialAmbient.data());
        std::array<float , 4> LMaterialDiffuse{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_DIFFUSE , LMaterialDiffuse.data());
        std::array<float , 4> LMaterialSpecular{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_SPECULAR , LMaterialSpecular.data());
        std::array<float , 4> LMaterialEmission{0.0F , 0.0F , 0.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_EMISSION , LMaterialEmission.data());
        std::array<float , 1> LMaterialShininess{0.0F};
        glMaterialfv(GL_FRONT , GL_SHININESS , LMaterialShininess.data());
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
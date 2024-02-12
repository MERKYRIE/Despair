#include"Video.hpp"

#include"Debug.hpp"
#include"Font.hpp"
#include"Texture.hpp"

namespace NBlindness::NEngine{
    void CVideo::FInitialize(){
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 3));
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 3));
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK , SDL_GL_CONTEXT_PROFILE_CORE));
        GDebug.FSimpleDirectMediaLayerHandleError(VWindow = SDL_CreateWindow("Blindness" , 0 , 0 , 1600 , 900 , SDL_WINDOW_OPENGL));
        GDebug.FSimpleDirectMediaLayerHandleError(VContext = SDL_GL_CreateContext(VWindow));
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetSwapInterval(0));
        SDL_DisplayMode LDisplayMode;
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GetWindowDisplayMode(VWindow , &LDisplayMode));
        VRatio = static_cast<float>(LDisplayMode.w) / static_cast<float>(LDisplayMode.h);
        VInversedRatio = static_cast<float>(LDisplayMode.h) / static_cast<float>(LDisplayMode.w);
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_SetRelativeMouseMode(SDL_TRUE));
        GDebug.FError(gladLoadGL(reinterpret_cast<GLADloadfunc>(SDL_GL_GetProcAddress)) < 30003);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        std::int32_t LSuccess;
        std::int32_t LLength;
        std::string LLog;
        std::fstream LFile;
        std::stringstream LStream;
        std::string LString;
        char* LArray;
        LFile.open("Program\\Vertex.ogl" , std::ios::in);
        VVertex = glCreateShader(GL_VERTEX_SHADER);
        LStream << LFile.rdbuf();
        LString = LStream.str();
        LArray = LString.data();
        glShaderSource(VVertex , 1 , &LArray , nullptr);
        glCompileShader(VVertex);
        glGetShaderiv(VVertex , GL_COMPILE_STATUS , &LSuccess);
        glGetShaderiv(VVertex , GL_INFO_LOG_LENGTH , &LLength);
        LLog.resize(LLength);
        glGetShaderInfoLog(VVertex , LLength , nullptr , LLog.data());
        GDebug.FError(!LSuccess , "Open Graphics Library - " + LLog);
        LFile.open("Program\\Fragment.ogl" , std::ios::in);
        VFragment = glCreateShader(GL_FRAGMENT_SHADER);
        LStream << LFile.rdbuf();
        LString = LStream.str();
        LArray = LString.data();
        glShaderSource(VFragment , 1 , &LArray , nullptr);
        glCompileShader(VFragment);
        glGetShaderiv(VFragment , GL_COMPILE_STATUS , &LSuccess);
        glGetShaderiv(VFragment , GL_INFO_LOG_LENGTH , &LLength);
        LLog.resize(LLength);
        glGetShaderInfoLog(VFragment , LLength , nullptr , LLog.data());
        GDebug.FError(!LSuccess , "Open Graphics Library - " + LLog);
        VProgram = glCreateProgram();
        glAttachShader(VProgram , VVertex);
        glAttachShader(VProgram , VFragment);
        glLinkProgram(VProgram);
        glGetProgramiv(VProgram , GL_LINK_STATUS , &LSuccess);
        glGetProgramiv(VProgram , GL_INFO_LOG_LENGTH , &LLength);
        LLog.resize(LLength);
        glGetProgramInfoLog(VProgram , LLength , nullptr , LLog.data());
        GDebug.FError(!LSuccess , "Open Graphics Library - " + LLog);
        glUseProgram(VProgram);
        /*
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
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
        */
        GDebug.FOpenGraphicsLibraryError();
        GDebug.FSimpleDirectMediaLayerCodeError(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Typeface"}){
            if(LEntry.path().extension() == ".ttf"){
                VFonts.emplace_back(new CFont{LEntry.path().string()});
            }
        }
        VFonts.shrink_to_fit();
        GDebug.FSimpleDirectMediaLayerFlagsError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Atlas"}){
            if(LEntry.path().extension() == ".png"){
                VTextures.emplace_back(new CTexture{LEntry.path().string()});
            }
        }
        VTextures.shrink_to_fit();
    }

    void CVideo::FPreupdate(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void CVideo::FPostupdate(){
        SDL_GL_SwapWindow(VWindow);
    }

    void CVideo::FDeinitialize(){
        VTextures.clear();
        IMG_Quit();
        VFonts.clear();
        TTF_Quit();
        glDetachShader(VProgram , VFragment);
        glDetachShader(VProgram , VVertex);
        glDeleteShader(VVertex);
        glDeleteShader(VFragment);
        glDeleteProgram(VProgram);
        SDL_GL_DeleteContext(VContext);
        SDL_DestroyWindow(VWindow);
    }

    float CVideo::FRatio(){
        return VRatio;
    }

    float CVideo::FInversedRatio(){
        return VInversedRatio;
    }

    const CFont& CVideo::FFont(const std::string& PPath){
        std::vector<std::shared_ptr<CFont>>::iterator LIterator{
            std::find_if(VFonts.begin() , VFonts.end() , [&PPath](const std::shared_ptr<CFont>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VFonts.end());
        return **LIterator;
    }

    const CTexture& CVideo::FTexture(const std::string& PPath){
        std::vector<std::shared_ptr<CTexture>>::iterator LIterator{
            std::find_if(VTextures.begin() , VTextures.end() , [&PPath](const std::shared_ptr<CTexture>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VTextures.end());
        return **LIterator;
    }
}
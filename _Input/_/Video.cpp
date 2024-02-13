#include"Video.hpp"

#include"Debug.hpp"
#include"Font.hpp"
#include"Texture.hpp"

namespace NBlindness{
    void CVideo::FInitialize(){
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug.FSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
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
        LStream.str("");
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
        LFile.close();
        LFile.open("Program\\Fragment.ogl" , std::ios::in);
        VFragment = glCreateShader(GL_FRAGMENT_SHADER);
        LStream.str("");
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
        LFile.close();
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
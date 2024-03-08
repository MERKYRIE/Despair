#include"Video.hpp"

#include"Debug.hpp"
#include"Video\\Font.hpp"
#include"Video\\Shader.hpp"
#include"Video\\Texture.hpp"

namespace NBlindness
{
    void CVideo::BInitialize()
    {
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK , SDL_GL_CONTEXT_PROFILE_CORE));
        GDebug.OSimpleDirectMediaLayerHandleError(FWindow = SDL_CreateWindow("Blindness" , 0 , 0 , 1600 , 900 , SDL_WINDOW_OPENGL));
        GDebug.OSimpleDirectMediaLayerHandleError(FContext = SDL_GL_CreateContext(FWindow));
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_GL_SetSwapInterval(0));
        SDL_DisplayMode LDisplayMode;
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_GetWindowDisplayMode(FWindow , &LDisplayMode));
        FRatio = static_cast<float>(LDisplayMode.w) / static_cast<float>(LDisplayMode.h);
        FInversedRatio = static_cast<float>(LDisplayMode.h) / static_cast<float>(LDisplayMode.w);
        GDebug.OSimpleDirectMediaLayerCodeError(SDL_SetRelativeMouseMode(SDL_TRUE));
        GDebug.OError(gladLoadGL(reinterpret_cast<GLADloadfunc>(SDL_GL_GetProcAddress)) != 40006);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        FVertex.reset(new NVideo::CShader{"\\Vertex.ogl" , GL_VERTEX_SHADER});
        FFragment.reset(new NVideo::CShader{"\\Fragment.ogl" , GL_FRAGMENT_SHADER});
        std::int32_t LSuccess;
        std::int32_t LLength;
        std::string LLog;
        FProgram = glCreateProgram();
        glAttachShader(FProgram , FVertex->BIdentifier());
        glAttachShader(FProgram , FFragment->BIdentifier());
        glLinkProgram(FProgram);
        glGetProgramiv(FProgram , GL_LINK_STATUS , &LSuccess);
        glGetProgramiv(FProgram , GL_INFO_LOG_LENGTH , &LLength);
        LLog.resize(LLength);
        glGetProgramInfoLog(FProgram , LLength , nullptr , LLog.data());
        GDebug.OError(!LSuccess , "Open Graphics Library - " + LLog);
        glUseProgram(FProgram);
        GDebug.OOpenGraphicsLibraryError();
        GDebug.OSimpleDirectMediaLayerCodeError(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Typeface"})
        {
            if(LEntry.path().extension() == ".ttf")
            {
                FFonts.emplace_back(new NVideo::CFont{LEntry.path().string()});
            }
        }
        FFonts.shrink_to_fit();
        GDebug.OSimpleDirectMediaLayerMaskError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Atlas"})
        {
            if(LEntry.path().extension() == ".png")
            {
                FTextures.emplace_back(new NVideo::CTexture{LEntry.path().string()});
            }
        }
        FTextures.shrink_to_fit();
    }
    void CVideo::BPreupdate()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void CVideo::BPostupdate()
    {
        SDL_GL_SwapWindow(FWindow);
    }
    void CVideo::BDeinitialize()
    {
        FTextures.clear();
        IMG_Quit();
        FFonts.clear();
        TTF_Quit();
        FFragment.reset();
        FVertex.reset();
        glDeleteProgram(FProgram);
        SDL_GL_DeleteContext(FContext);
        SDL_DestroyWindow(FWindow);
    }

    float CVideo::ORatio()
    {
        return(FRatio);
    }
    float CVideo::OInversedRatio()
    {
        return(FInversedRatio);
    }
    const NVideo::CFont& CVideo::OAccessFont(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NVideo::CFont>>::iterator LIterator
        {
            std::find_if(FFonts.begin() , FFonts.end() , [&PPath](const std::shared_ptr<NVideo::CFont>& LPointer){return(*LPointer == PPath);})
        };
        GDebug.OError(LIterator == FFonts.end());
        return(**LIterator);
    }
    const NVideo::CTexture& CVideo::OAccessSpecificTexture(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NVideo::CTexture>>::iterator LIterator
        {
            std::find_if(FTextures.begin() , FTextures.end() , [&PPath](const std::shared_ptr<NVideo::CTexture>& LPointer){return(*LPointer == PPath);})
        };
        GDebug.OError(LIterator == FTextures.end());
        return(**LIterator);
    }
    const NVideo::CTexture& CVideo::OAccessRandomTexture()
    {
        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDistributor{0 , FTextures.size() - 1};
        return(*FTextures[LDistributor(LGenerator)]);
    }
}
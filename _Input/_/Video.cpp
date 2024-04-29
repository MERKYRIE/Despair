#include"Video.hpp"

#include"Debug.hpp"
#include"Video\\Font.hpp"
#include"Video\\Shader.hpp"
#include"Video\\Texture.hpp"

namespace NDespair
{
    CVideo::CVideo()
    {
        GVideo = this;
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK , SDL_GL_CONTEXT_PROFILE_CORE));
        GDebug->ASimpleDirectMediaLayerHandleError(FWindow = SDL_CreateWindow("Despair" , 0 , 0 , 1600 , 900 , SDL_WINDOW_OPENGL));
        GDebug->ASimpleDirectMediaLayerHandleError(FContext = SDL_GL_CreateContext(FWindow));
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_GL_SetSwapInterval(0));
        SDL_DisplayMode LDisplayMode;
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_GetWindowDisplayMode(FWindow , &LDisplayMode));
        FRatio = static_cast<float>(LDisplayMode.w) / static_cast<float>(LDisplayMode.h);
        FInversedRatio = static_cast<float>(LDisplayMode.h) / static_cast<float>(LDisplayMode.w);
        GDebug->ASimpleDirectMediaLayerCodeError(SDL_SetRelativeMouseMode(SDL_TRUE));
        GDebug->AError(gladLoadGL(reinterpret_cast<GLADloadfunc>(SDL_GL_GetProcAddress)) != 40006);
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
        glAttachShader(FProgram , FVertex->AIdentifier());
        glAttachShader(FProgram , FFragment->AIdentifier());
        glLinkProgram(FProgram);
        glGetProgramiv(FProgram , GL_LINK_STATUS , &LSuccess);
        glGetProgramiv(FProgram , GL_INFO_LOG_LENGTH , &LLength);
        LLog.resize(LLength);
        glGetProgramInfoLog(FProgram , LLength , nullptr , LLog.data());
        GDebug->AError(!LSuccess , "Open Graphics Library - " + LLog);
        glUseProgram(FProgram);
        GDebug->AOpenGraphicsLibraryError();
        GDebug->ASimpleDirectMediaLayerCodeError(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Fonts"})
        {
            if(LEntry.path().extension() == ".ttf")
            {
                FFonts.emplace_back(new NVideo::CFont{LEntry.path().string()});
            }
        }
        FFonts.shrink_to_fit();
        GDebug->ASimpleDirectMediaLayerMaskError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Textures"})
        {
            if(LEntry.path().extension() == ".png")
            {
                FTextures.emplace_back(new NVideo::CTexture{LEntry.path().string()});
            }
        }
        FTextures.shrink_to_fit();
    }
    void CVideo::APreupdate()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    float CVideo::ARatio()
    {
        return(FRatio);
    }
    float CVideo::AInversedRatio()
    {
        return(FInversedRatio);
    }
    NVideo::CFont* CVideo::AAccessFont(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NVideo::CFont>>::iterator LIterator
        {
            std::find_if(FFonts.begin() , FFonts.end() , [&PPath](std::shared_ptr<NVideo::CFont>& LPointer){return(LPointer->AEqual(PPath));})
        };
        GDebug->AError(LIterator == FFonts.end());
        return(LIterator->get());
    }
    NVideo::CTexture* CVideo::AAccessSpecificTexture(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NVideo::CTexture>>::iterator LIterator
        {
            std::find_if(FTextures.begin() , FTextures.end() , [&PPath](std::shared_ptr<NVideo::CTexture>& LPointer){return(LPointer->AEqual(PPath));})
        };
        GDebug->AError(LIterator == FTextures.end());
        return(LIterator->get());
    }
    NVideo::CTexture* CVideo::AAccessRandomTexture()
    {
        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDistributor{0 , FTextures.size() - 1};
        return(FTextures[LDistributor(LGenerator)].get());
    }
    void CVideo::APostupdate()
    {
        SDL_GL_SwapWindow(FWindow);
    }
    CVideo::~CVideo()
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
}
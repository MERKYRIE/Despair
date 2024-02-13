#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Blindness.hpp"
#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"World.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**){
    NBlindness::NEngine::GDebug.FSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NBlindness::NEngine::GAudio.FInitialize();
    NBlindness::NEngine::GVideo.FInitialize();
    NBlindness::NEngine::GWorld.FInitialize();
    while(!NBlindness::NEngine::GInput.FKeyHeld(SDL_SCANCODE_ESCAPE)){
        NBlindness::NEngine::GInput.FUpdate();
        NBlindness::NEngine::GTime.FUpdate();
        NBlindness::NEngine::GVideo.FPreupdate();
        NBlindness::NEngine::GWorld.FUpdate();
        NBlindness::NEngine::GVideo.FPostupdate();
    };
    NBlindness::NEngine::GWorld.FDeinitialize();
    NBlindness::NEngine::GVideo.FDeinitialize();
    NBlindness::NEngine::GAudio.FDeinitialize();
    SDL_Quit();
    return 0;
}
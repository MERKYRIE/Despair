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
    NBlindness::GDebug.FSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NBlindness::GAudio.FInitialize();
    NBlindness::GVideo.FInitialize();
    NBlindness::GWorld.FInitialize();
    while(!NBlindness::GInput.FKeyHeld(SDL_SCANCODE_ESCAPE)){
        NBlindness::GInput.FUpdate();
        NBlindness::GTime.FUpdate();
        NBlindness::GVideo.FPreupdate();
        NBlindness::GWorld.FUpdate();
        NBlindness::GVideo.FPostupdate();
    };
    NBlindness::GWorld.FDeinitialize();
    NBlindness::GVideo.FDeinitialize();
    NBlindness::GAudio.FDeinitialize();
    SDL_Quit();
    return 0;
}
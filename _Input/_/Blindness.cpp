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
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**)
{
    NBlindness::GDebug.OSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NBlindness::GAudio.BInitialize();
    NBlindness::GVideo.BInitialize();
    NBlindness::GSpace.BInitialize();
    while(!NBlindness::GInput.OIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NBlindness::GInput.BUpdate();
        NBlindness::GTime.BUpdate();
        NBlindness::GVideo.BPreupdate();
        NBlindness::GSpace.BUpdate();
        NBlindness::GVideo.BPostupdate();
    };
    NBlindness::GSpace.BDeinitialize();
    NBlindness::GVideo.BDeinitialize();
    NBlindness::GAudio.BDeinitialize();
    SDL_Quit();
    return(0);
}
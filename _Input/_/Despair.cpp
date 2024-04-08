#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Despair.hpp"
#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**)
{
    NDespair::GDebug.OSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NDespair::GAudio.BInitialize();
    NDespair::GVideo.BInitialize();
    NDespair::GSpace.BInitialize();
    while(!NDespair::GInput.OIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NDespair::GInput.BUpdate();
        NDespair::GTime.BUpdate();
        NDespair::GVideo.BPreupdate();
        NDespair::GSpace.BUpdate();
        NDespair::GVideo.BPostupdate();
    };
    NDespair::GSpace.BDeinitialize();
    NDespair::GVideo.BDeinitialize();
    NDespair::GAudio.BDeinitialize();
    SDL_Quit();
    return(0);
}
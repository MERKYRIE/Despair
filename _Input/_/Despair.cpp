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
    NDespair::GDebug.ASimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NDespair::GAudio.AInitialize();
    NDespair::GVideo.AInitialize();
    NDespair::GSpace.AInitialize();
    while(!NDespair::GInput.AIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NDespair::GInput.AUpdate();
        NDespair::GTime.AUpdate();
        NDespair::GVideo.APreupdate();
        NDespair::GSpace.AUpdate();
        NDespair::GVideo.APostupdate();
    };
    NDespair::GSpace.ADeinitialize();
    NDespair::GVideo.ADeinitialize();
    NDespair::GAudio.ADeinitialize();
    SDL_Quit();
    return(0);
}
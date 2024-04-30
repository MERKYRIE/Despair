#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Network\\SDL2_net.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Despair.hpp"

#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Network.hpp"
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**)
{
    new NDespair::CDebug;
    NDespair::GDebug->AAssertSimpleDirectMediaLayerCode(SDL_Init(SDL_INIT_EVERYTHING));
    new NDespair::CNetwork;
    new NDespair::CAudio;
    new NDespair::CInput;
    new NDespair::CVideo;
    new NDespair::CTime;
    new NDespair::CSpace;
    while(!NDespair::GInput->AIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NDespair::GInput->AUpdate();
        NDespair::GTime->AUpdate();
        NDespair::GVideo->APreupdate();
        NDespair::GSpace->AUpdate();
        NDespair::GVideo->APostupdate();
    };
    delete NDespair::GSpace;
    delete NDespair::GTime;
    delete NDespair::GVideo;
    delete NDespair::GInput;
    delete NDespair::GAudio;
    delete NDespair::GNetwork;
    SDL_Quit();
    delete NDespair::GDebug;
    return(0);
}
#pragma comment(lib , "glu32.lib")
#pragma comment(lib , "opengl32.lib")

#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#include"Blindness.hpp"

#include"Audio.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"
#include"Input.hpp"
#include"Input\\Keyboard.hpp"
#include"Interface.hpp"
#include"Level.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**){
    NBlindness::NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(SDL_Init(SDL_INIT_EVERYTHING));
    NBlindness::GAudio.FInitialize();
    NBlindness::GInput.FInitialize();
    NBlindness::GVideo.FInitialize();
    NBlindness::GLevel.FInitialize();
    while(!NBlindness::NInput::GKeyboard.FHeld(SDL_SCANCODE_ESCAPE)){
        NBlindness::GInput.FUpdate();
        NBlindness::GTime.FUpdate();
        NBlindness::GVideo.FPreupdate();
        NBlindness::GLevel.FUpdate();
        //NMRKOGL::GInterface.FUpdate();
        NBlindness::GVideo.FPostupdate();
    };
    NBlindness::GLevel.FDeinitialize();
    NBlindness::GVideo.FDeinitialize();
    NBlindness::GAudio.FDeinitialize();
    SDL_Quit();
    return 0;
}
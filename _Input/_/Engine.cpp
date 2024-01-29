#pragma comment(lib , "glu32.lib")
#pragma comment(lib , "opengl32.lib")

#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#include"Engine.hpp"

#include"Engine\\Atlas.hpp"
#include"Engine\\Audio.hpp"
#include"Engine\\Debug.hpp"
#include"Engine\\Input.hpp"
#include"Engine\\Keyboard.hpp"
#include"Engine\\Level.hpp"
#include"Engine\\Soundpack.hpp"
#include"Engine\\Soundtrack.hpp"
#include"Engine\\Time.hpp"
#include"Engine\\Typeface.hpp"
#include"Engine\\Video.hpp"

#include"Game.hpp"

std::int32_t main(std::int32_t , char**){
    NBlindness::NEngine::GDebug.FSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NBlindness::NEngine::GAudio.FInitialize();
    NBlindness::NEngine::GSoundpack.FInitialize();
    NBlindness::NEngine::GSoundtrack.FInitialize();
    NBlindness::NEngine::GVideo.FInitialize();
    NBlindness::NEngine::GAtlas.FInitialize();
    NBlindness::NEngine::GTypeface.FInitialize();
    NBlindness::NEngine::GLevel.FInitialize();
    NBlindness::GGame.FInitialize();
    while(!NBlindness::NEngine::GKeyboard.FHeld(SDL_SCANCODE_ESCAPE)){
        NBlindness::NEngine::GInput.FUpdate();
        NBlindness::NEngine::GTime.FUpdate();
        NBlindness::NEngine::GVideo.FPreupdate();
        NBlindness::NEngine::GLevel.FUpdate();
        NBlindness::GGame.FUpdate();
        NBlindness::NEngine::GVideo.FPostupdate();
    };
    NBlindness::GGame.FDeinitialize();
    NBlindness::NEngine::GLevel.FDeinitialize();
    NBlindness::NEngine::GTypeface.FDeinitialize();
    NBlindness::NEngine::GAtlas.FDeinitialize();
    NBlindness::NEngine::GVideo.FDeinitialize();
    NBlindness::NEngine::GSoundtrack.FDeinitialize();
    NBlindness::NEngine::GSoundpack.FDeinitialize();
    NBlindness::NEngine::GAudio.FDeinitialize();
    SDL_Quit();
    return 0;
}
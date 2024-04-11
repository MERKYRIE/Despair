#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Audio.hpp"
#include"Core.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

/*

+-----+    +---------+    +-----+
|Mouse|    |Interface|    |Video|
^-----+    ^---------+    ^-----+
|          |              |
+--------+ +-------+      +-----+
|Keyboard| |Expanse|      |Audio|
^--------+ ^-------+      ^-----+
|          |              |
+--------+->------------+->------+
|Input   | |Logic       | |Output|
^--------+ ^------------+ ^------+
|          |              |
+----------+--------------+
|Debug                    |
+-------------------------+

*/

namespace NDespair
{
    CCore::CCore()
    {
        NDespair::GDebug->ASimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    }
    CCore::~CCore()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NDespair::GDebug = std::make_shared<NDespair::CDebug>();
    NDespair::GTime = std::make_shared<NDespair::CTime>();
    NDespair::GCore = std::make_shared<NDespair::CCore>();
    NDespair::GAudio = std::make_shared<NDespair::CAudio>();
    NDespair::GInput = std::make_shared<NDespair::CInput>();
    NDespair::GVideo = std::make_shared<NDespair::CVideo>();
    NDespair::GSpace = std::make_shared<NDespair::CSpace>();
    while(!NDespair::GInput->AIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NDespair::GInput->AUpdate();
        NDespair::GTime->AUpdate();
        NDespair::GVideo->APreupdate();
        NDespair::GSpace->AUpdate();
        NDespair::GVideo->APostupdate();
    };
    return(0);
}
#pragma comment(lib , "..\\SLSDL\\sdl2.lib")
#pragma comment(lib , "..\\SLSDL\\sdl2main.lib")
#pragma comment(lib , "..\\SLSDLLI\\sdl2_image.lib")
#pragma comment(lib , "..\\SLSDLLM\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SLSDLLT\\sdl2_ttf.lib")
#pragma comment(lib , "..\\AOL\\assimp-vc143-mt.lib")
#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")

#include "MRKOGL.hpp"

#include "Audio.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"
#include "Input.hpp"
#include "Input\\Keyboard.hpp"
#include "Interface.hpp"
#include "Level.hpp"
#include "Time.hpp"
#include "Video.hpp"

signed int main(signed int , char**)
{
    NMRKOGL::NDebug::NAssert::NError::GSDL.FCode(SDL_Init(SDL_INIT_EVERYTHING));
    NMRKOGL::GAudio.FInitialize();
    NMRKOGL::GInput.FInitialize();
    NMRKOGL::GVideo.FInitialize();
    NMRKOGL::GLevel.FInitialize();
    //NMRKOGL::GInterface.FInitialize();
    while(!NMRKOGL::NInput::GKeyboard.FHeld(SDL_SCANCODE_ESCAPE))
    {
        NMRKOGL::GInput.FUpdate();
        NMRKOGL::GTime.FUpdate();
        NMRKOGL::GVideo.FPreupdate();
        NMRKOGL::GLevel.FUpdate();
        //NMRKOGL::GInterface.FUpdate();
        NMRKOGL::GVideo.FPostupdate();
    };
    //NMRKOGL::GInterface.FDeinitialize();
    NMRKOGL::GLevel.FDeinitialize();
    NMRKOGL::GVideo.FDeinitialize();
    NMRKOGL::GAudio.FDeinitialize();
    SDL_Quit();
    return 0;
}
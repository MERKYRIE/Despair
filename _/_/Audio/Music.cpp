#include "Music.hpp"

#include "Debug\\Assert\\Error\\SDL.hpp"

namespace NMRKOGL::NAudio
{
    CMusic::CMusic(const std::string& PPath)
    {
        NDebug::NAssert::NError::GSDL.FHandle(VData = Mix_LoadMUS(PPath.c_str()));
    }

    CMusic& CMusic::FPlay()
    {
        NDebug::NAssert::NError::GSDL.FCode(Mix_PlayMusic(VData , 0));
        return *this;
    }

    CMusic& CMusic::FPause()
    {
        Mix_PauseMusic();
        return *this;
    }

    CMusic& CMusic::FResume()
    {
        Mix_ResumeMusic();
        return *this;
    }

    CMusic& CMusic::FStop()
    {
        Mix_HaltMusic();
        return *this;
    }

    CMusic::~CMusic()
    {
        Mix_FreeMusic(VData);
    }
}
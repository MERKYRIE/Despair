#include "Sound.hpp"

#include "Debug\\Assert.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"

namespace NMRKOGL::NAudio
{
    CSound::CSound(const std::string& PPath)
    {
        NDebug::NAssert::NError::GSDL.FHandle(VData = Mix_LoadWAV(PPath.c_str()));
        VTrack = Mix_AllocateChannels(SDL_QUERY);
        NDebug::GAssert.FError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != VTrack + 1);
    }

    CSound& CSound::FPlay()
    {
        NDebug::GAssert.FError(Mix_PlayChannel(VTrack , VData , 0) != VTrack);
        return *this;
    }

    bool CSound::FPlaying()
    {
        return Mix_Playing(VTrack);
    }

    CSound::~CSound()
    {
        Mix_FreeChunk(VData);
    }
}
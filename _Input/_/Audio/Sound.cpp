#include"Sound.hpp"

#include"Debug.hpp"

namespace NDespair::NAudio
{
    CSound::CSound(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        GDebug->AAssertSimpleDirectMediaLayerHandle(FHandle = Mix_LoadWAV(PPath.c_str()));
        FChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug->AAssert(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != FChannel + 1);
    }
    std::string CSound::APath()
    {
        return FPath;
    }
    bool CSound::AIs(const std::string& PPath)
    {
        return(FPath == PPath);
    }
    CSound* CSound::APlay()
    {
        GDebug->AAssertSimpleDirectMediaLayerCode(Mix_PlayChannel(FChannel , FHandle , 0) != FChannel);
        return(this);
    }
    bool CSound::AIsPlaying()
    {
        return(Mix_Playing(FChannel));
    }
    CSound::~CSound()
    {
        Mix_FreeChunk(FHandle);
    }
}
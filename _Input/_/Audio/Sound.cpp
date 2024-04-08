#include"Sound.hpp"

#include"Debug.hpp"

namespace NDespair::NAudio
{
    CSound::CSound(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        GDebug.ASimpleDirectMediaLayerHandleError(FHandle = Mix_LoadWAV(PPath.c_str()));
        FChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug.AError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != FChannel + 1);
    }
    bool CSound::AEqual(const std::string& PPath)
    {
        return(FPath == PPath);
    }
    CSound* CSound::APlay()
    {
        GDebug.ASimpleDirectMediaLayerCodeError(Mix_PlayChannel(FChannel , FHandle , 0) != FChannel);
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
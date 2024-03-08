#include"Sound.hpp"

#include"Debug.hpp"

namespace NBlindness::NAudio
{
    CSound::CSound(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        GDebug.OSimpleDirectMediaLayerHandleError(FHandle = Mix_LoadWAV(PPath.c_str()));
        FChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug.OError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != FChannel + 1);
    }
    bool CSound::operator==(const std::string& PPath) const
    {
        return(FPath == PPath);
    }

    const CSound& CSound::OPlay() const
    {
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_PlayChannel(FChannel , FHandle , 0) != FChannel);
        return(*this);
    }
    bool CSound::OIsPlaying() const
    {
        return(Mix_Playing(FChannel));
    }
    CSound::~CSound()
    {
        Mix_FreeChunk(FHandle);
    }
}
#include"Track.hpp"

#include"Debug.hpp"

namespace NBlindness::NAudio
{
    CTrack::CTrack(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        GDebug.OSimpleDirectMediaLayerHandleError(FHandle = Mix_LoadMUS(PPath.c_str()));
    }
    bool CTrack::operator==(const std::string& PPath) const
    {
        return(FPath == PPath);
    }

    const CTrack& CTrack::OPlay() const
    {
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_PlayMusic(FHandle , 0));
        return(*this);
    }
    const CTrack& CTrack::OPause() const
    {
        Mix_PauseMusic();
        return(*this);
    }
    const CTrack& CTrack::OResume() const
    {
        Mix_ResumeMusic();
        return(*this);
    }
    const CTrack& CTrack::OStop() const
    {
        Mix_HaltMusic();
        return(*this);
    }
    const CTrack& CTrack::OAccessVolume(std::uint8_t PValue) const
    {
        Mix_VolumeMusic(PValue);
        GDebug.OError(Mix_VolumeMusic(SDL_QUERY) != PValue);
        return(*this);
    }
    CTrack::~CTrack()
    {
        Mix_FreeMusic(FHandle);
    }
}
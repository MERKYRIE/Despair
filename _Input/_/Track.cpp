#include"Track.hpp"

#include"Debug.hpp"

namespace NBlindness{
    bool CTrack::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CTrack::CTrack(const std::string& PPath){
        VPath = PPath.substr(PPath.find('\\'));
        GDebug.FSimpleDirectMediaLayerHandleError(VHandle = Mix_LoadMUS(PPath.c_str()));
    }

    const CTrack& CTrack::FPlay() const{
        GDebug.FSimpleDirectMediaLayerCodeError(Mix_PlayMusic(VHandle , 0));
        return *this;
    }

    const CTrack& CTrack::FPause() const{
        Mix_PauseMusic();
        return *this;
    }

    const CTrack& CTrack::FResume() const{
        Mix_ResumeMusic();
        return *this;
    }

    const CTrack& CTrack::FStop() const{
        Mix_HaltMusic();
        return *this;
    }

    const CTrack& CTrack::FVolume(std::uint8_t PValue) const{
        Mix_VolumeMusic(PValue);
        GDebug.FError(Mix_VolumeMusic(SDL_QUERY) != PValue);
        return *this;
    }

    CTrack::~CTrack(){
        Mix_FreeMusic(VHandle);
    }
}
#include"Track.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    bool CTrack::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CTrack::CTrack(const std::string& PPath){
        VPath = PPath;
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

    CTrack::~CTrack(){
        Mix_FreeMusic(VHandle);
    }
}
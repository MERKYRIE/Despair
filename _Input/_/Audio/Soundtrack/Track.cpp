#include"Track.hpp"

#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NAudio::NSoundtrack{
    bool CTrack::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CTrack::CTrack(const std::string& PPath){
        VPath = PPath;
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(VHandle = Mix_LoadMUS(PPath.c_str()));
    }

    const CTrack& CTrack::FPlay() const{
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(Mix_PlayMusic(VHandle , 0));
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
#include"Track.hpp"

#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NAudio::NSoundtrack{
    CTrack::CTrack(const std::string& PPath){
        VPath = PPath;
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(VHandle = Mix_LoadMUS(PPath.c_str()));
    }

    std::string CTrack::FPath() const{
        return VPath;
    }

    CTrack& CTrack::FPlay(){
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(Mix_PlayMusic(VHandle , 0));
        return *this;
    }

    CTrack& CTrack::FPause(){
        Mix_PauseMusic();
        return *this;
    }

    CTrack& CTrack::FResume(){
        Mix_ResumeMusic();
        return *this;
    }

    CTrack& CTrack::FStop(){
        Mix_HaltMusic();
        return *this;
    }

    CTrack::~CTrack(){
        Mix_FreeMusic(VHandle);
    }
}
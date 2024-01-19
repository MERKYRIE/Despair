#include"Sound.hpp"

#include"Debug\\Assert.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NAudio::NSoundpack{
    CSound::CSound(const std::string& PPath){
        VPath = PPath;
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(VHandle = Mix_LoadWAV(PPath.c_str()));
        VChannel = Mix_AllocateChannels(SDL_QUERY);
        NDebug::GAssert.FError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != VChannel + 1);
    }

    std::string CSound::FPath() const{
        return VPath;
    }

    CSound& CSound::FPlay(){
        NDebug::GAssert.FError(Mix_PlayChannel(VChannel , VHandle , 0) != VChannel);
        return *this;
    }

    bool CSound::FPlaying(){
        return Mix_Playing(VChannel);
    }

    CSound::~CSound(){
        Mix_FreeChunk(VHandle);
    }
}
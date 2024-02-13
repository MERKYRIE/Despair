#include"Sound.hpp"

#include"Debug.hpp"

namespace NBlindness{
    bool CSound::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CSound::CSound(const std::string& PPath){
        VPath = PPath.substr(PPath.find('\\'));
        GDebug.FSimpleDirectMediaLayerHandleError(VHandle = Mix_LoadWAV(PPath.c_str()));
        VChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug.FError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != VChannel + 1);
    }

    const CSound& CSound::FPlay() const{
        GDebug.FSimpleDirectMediaLayerCodeError(Mix_PlayChannel(VChannel , VHandle , 0) != VChannel);
        return *this;
    }

    bool CSound::FPlaying() const{
        return Mix_Playing(VChannel);
    }

    CSound::~CSound(){
        Mix_FreeChunk(VHandle);
    }
}
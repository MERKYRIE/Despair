#include"Audio.hpp"

#include"Debug.hpp"
#include"Sound.hpp"
#include"Track.hpp"

namespace NBlindness::NEngine{
    void CAudio::FInitialize(){
        GDebug.FSimpleDirectMediaLayerFlagsError(Mix_Init(MIX_INIT_MP3));
        GDebug.FSimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        GDebug.FError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        GDebug.FError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        GDebug.FError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"}){
            if(LEntry.path().extension() == ".wav"){
                VSounds.emplace_back(new CSound{LEntry.path().string()});
            }
        }
        VSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"}){
            if(LEntry.path().extension() == ".mp3"){
                VTracks.emplace_back(new CTrack{LEntry.path().string()});
            }
        }
        VTracks.shrink_to_fit();
    }

    const CSound& CAudio::FSound(const std::string& PPath){
        std::vector<std::shared_ptr<CSound>>::iterator LIterator{
            std::find_if(VSounds.begin() , VSounds.end() , [&PPath](const std::shared_ptr<CSound>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VSounds.end());
        return **LIterator;
    }

    const CTrack& CAudio::FTrack(const std::string& PPath){
        std::vector<std::shared_ptr<CTrack>>::iterator LIterator{
            std::find_if(VTracks.begin() , VTracks.end() , [&PPath](const std::shared_ptr<CTrack>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VTracks.end());
        return **LIterator;
    }

    void CAudio::FDeinitialize(){
        VTracks.clear();
        VSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
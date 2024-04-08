#include"Audio.hpp"

#include"Debug.hpp"
#include"Audio\\Sound.hpp"
#include"Audio\\Track.hpp"

namespace NDespair
{
    void CAudio::AInitialize()
    {
        GDebug.ASimpleDirectMediaLayerMaskError(Mix_Init(MIX_INIT_MP3));
        GDebug.ASimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        GDebug.AError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        GDebug.AError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        GDebug.AError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"})
        {
            if(LEntry.path().extension() == ".wav")
            {
                FSounds.emplace_back(new NAudio::CSound{LEntry.path().string()});
            }
        }
        FSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"})
        {
            if(LEntry.path().extension() == ".mp3")
            {
                FTracks.emplace_back(new NAudio::CTrack{LEntry.path().string()});
            }
        }
        FTracks.shrink_to_fit();
    }
    NAudio::CSound* CAudio::AAccessSound(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NAudio::CSound>>::iterator LIterator
        {
            std::find_if(FSounds.begin() , FSounds.end() , [&PPath](const std::shared_ptr<NAudio::CSound>& LPointer){return(LPointer->AEqual(PPath));})
        };
        return(LIterator->get());
    }
    NAudio::CTrack* CAudio::AAccessTrack(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NAudio::CTrack>>::iterator LIterator
        {
            std::find_if(FTracks.begin() , FTracks.end() , [&PPath](const std::shared_ptr<NAudio::CTrack>& LPointer){return(LPointer->AEqual(PPath));})
        };
        return(LIterator->get());
    }
    void CAudio::ADeinitialize()
    {
        FTracks.clear();
        FSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
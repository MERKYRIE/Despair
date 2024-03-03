#include"Audio.hpp"

#include"Debug.hpp"
#include"Sound.hpp"
#include"Track.hpp"

namespace NBlindness
{
    void CAudio::AInitialize()
    {
        GDebug.OSimpleDirectMediaLayerFlagsError(Mix_Init(MIX_INIT_MP3));
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        GDebug.OError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        GDebug.OError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        GDebug.OError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"})
        {
            if(LEntry.path().extension() == ".wav")
            {
                FSounds.emplace_back(new CSound{LEntry.path().string()});
            }
        }
        FSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"})
        {
            if(LEntry.path().extension() == ".mp3")
            {
                FTracks.emplace_back(new CTrack{LEntry.path().string()});
            }
        }
        FTracks.shrink_to_fit();
    }

    const CSound& CAudio::OAccessSound(const std::string& PPath)
    {
        std::vector<std::shared_ptr<CSound>>::iterator LIterator
        {
            std::find_if(FSounds.begin() , FSounds.end() , [&PPath](const std::shared_ptr<CSound>& LPointer){return *LPointer == PPath;})
        };
        GDebug.OError(LIterator == FSounds.end());
        return **LIterator;
    }

    const CTrack& CAudio::OAccessTrack(const std::string& PPath)
    {
        std::vector<std::shared_ptr<CTrack>>::iterator LIterator
        {
            std::find_if(FTracks.begin() , FTracks.end() , [&PPath](const std::shared_ptr<CTrack>& LPointer){return *LPointer == PPath;})
        };
        GDebug.OError(LIterator == FTracks.end());
        return **LIterator;
    }

    void CAudio::ADeinitialize()
    {
        FTracks.clear();
        FSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
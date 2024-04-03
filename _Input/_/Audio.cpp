#include"Audio.hpp"

#include"Debug.hpp"
#include"Audio\\Sound.hpp"
#include"Audio\\Track.hpp"

namespace NDespair::NAudio
{
    std::vector<NSound::SSlot*> _GSounds;
    std::vector<NTrack::SSlot*> _GTracks;
    
    void FInitialize()
    {
        GDebug.OSimpleDirectMediaLayerMaskError(Mix_Init(MIX_INIT_MP3));
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t _LFrequency;
        std::uint16_t _LFormat;
        std::int32_t _LChannels;
        GDebug.OError(!Mix_QuerySpec(&_LFrequency , &_LFormat , &_LChannels));
        GDebug.OError(_LFrequency != MIX_DEFAULT_FREQUENCY || _LFormat != MIX_DEFAULT_FORMAT || _LChannels != MIX_DEFAULT_CHANNELS);
        GDebug.OError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& _LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"})
        {
            if(_LEntry.path().extension() == ".wav")
            {
                _GSounds.emplace_back();
                NSound::FSlot(&_GSounds.back());
                NSound::FConstruct(_LEntry.path().string());
            }
        }
        _GSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& _LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"})
        {
            if(_LEntry.path().extension() == ".mp3")
            {
                _GTracks.emplace_back();
                NTrack::FSlot(&_GTracks.back());
                NTrack::FConstruct(_LEntry.path().string());
            }
        }
        _GTracks.shrink_to_fit();
    }
    NSound::SSlot** FAccessSound(const std::string& _APath)
    {
        NSound::FSave();
        for(std::vector<NSound::SSlot*>::iterator _LIterator{_GSounds.begin()} ; _LIterator != _GSounds.end() ; _LIterator++)
        {
            NSound::FSlot(&*_LIterator);
            if(NSound::FEqual(_APath))
            {
                NSound::FLoad();
                return &*_LIterator;
            }
        }
        NSound::FLoad();
        return(nullptr);
    }
    NTrack::SSlot** FAccessTrack(const std::string& _APath)
    {
        NTrack::FSave();
        for(std::vector<NTrack::SSlot*>::iterator _LIterator{_GTracks.begin()} ; _LIterator != _GTracks.end() ; _LIterator++)
        {
            NTrack::FSlot(&*_LIterator);
            if(NTrack::FEqual(_APath))
            {
                NTrack::FLoad();
                return &*_LIterator;
            }
        }
        NTrack::FLoad();
        return(nullptr);
    }
    void FDeinitialize()
    {
        for(NTrack::SSlot* _LTrack : _GTracks)
        {
            NTrack::FSlot(&_LTrack);
            NTrack::FDeconstruct();
        }
        _GTracks.clear();
        for(NSound::SSlot* _LSound : _GSounds)
        {
            NSound::FSlot(&_LSound);
            NSound::FDeconstruct();
        }
        _GSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
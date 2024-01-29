#include"Audio.hpp"

#include"Engine\\Debug.hpp"

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
    }

    void CAudio::FDeinitialize(){
        Mix_CloseAudio();
        Mix_Quit();
    }
}
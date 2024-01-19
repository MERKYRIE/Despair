#include"Audio.hpp"

#include"Audio\\Soundpack.hpp"
#include"Audio\\Soundtrack.hpp"

#include"Debug\\Assert.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness{
    void CAudio::FInitialize(){
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FFlags(Mix_Init(MIX_INIT_MP3));
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        NDebug::GAssert.FError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        NDebug::GAssert.FError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        NDebug::GAssert.FError(Mix_AllocateChannels(0));
        NAudio::GSoundpack.FInitialize();
        NAudio::GSoundtrack.FInitialize();
    }

    void CAudio::FDeinitialize(){
        NAudio::GSoundtrack.FDeinitialize();
        NAudio::GSoundpack.FDeinitialize();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
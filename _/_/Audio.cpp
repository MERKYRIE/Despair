#include "Audio.hpp"

#include "Debug\\Assert.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"

namespace NMRKOGL
{
    void CAudio::FInitialize()
    {
        NDebug::NAssert::NError::GSDL.FFlags(Mix_Init(MIX_INIT_MP3));
        NDebug::NAssert::NError::GSDL.FCode(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        signed int Frequency;
        unsigned short Format;
        signed int Channels;
        NDebug::GAssert.FError(!Mix_QuerySpec(&Frequency , &Format , &Channels));
        NDebug::GAssert.FError(Frequency != MIX_DEFAULT_FREQUENCY || Format != MIX_DEFAULT_FORMAT || Channels != MIX_DEFAULT_CHANNELS);
        NDebug::GAssert.FError(Mix_AllocateChannels(0));
    }

    void CAudio::FDeinitialize()
    {
        Mix_CloseAudio();
        Mix_Quit();
    }
}
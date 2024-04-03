#pragma once

#include"Despair.hpp"

namespace NDespair::NAudio::NTrack
{
    void FSlot(SSlot** ASlot);
    void FSave();
    void FLoad();
    void FConstruct(const std::string& APath);
    bool FEqual(const std::string& APath);
    void FPlay();
    void FPause();
    void FResume();
    void FStop();
    void FAccessVolume(std::uint8_t AValue);
    void FDeconstruct();
}
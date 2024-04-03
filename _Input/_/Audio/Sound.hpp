#pragma once

#include"Despair.hpp"

namespace NDespair::NAudio::NSound
{
    void FSlot(SSlot** ASlot);
    void FSave();
    void FLoad();
    void FConstruct(const std::string& APath);
    bool FEqual(const std::string& APath);
    void FPlay();
    bool FIsPlaying();
    void FDeconstruct();
}
#pragma once

#include"Despair.hpp"

namespace NDespair::NAudio
{
    void FInitialize();
    NSound::SSlot** FAccessSound(const std::string& APath);
    NTrack::SSlot** FAccessTrack(const std::string& APath);
    void FDeinitialize();
}
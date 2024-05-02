#pragma once

#include"Despair.hpp"

namespace NDespair::NAudio
{
    class CTrack
    {
        private : std::string FPath;
        private : Mix_Music* FHandle;

        public : CTrack(const std::string& PPath);
        public : std::string APath();
        public : bool AIs(const std::string& PPath);
        public : CTrack* APlay();
        public : CTrack* APause();
        public : CTrack* AResume();
        public : CTrack* AStop();
        public : CTrack* AAccessVolume(std::uint8_t PValue);
        public : ~CTrack();
    };
}
#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CAudio
    {
        private : std::vector<std::shared_ptr<NAudio::CSound>> FSounds;
        private : std::vector<std::shared_ptr<NAudio::CTrack>> FTracks;

        public : CAudio();
        public : NAudio::CSound* AAccessSound(const std::string& PPath);
        public : NAudio::CTrack* AAccessTrack(const std::string& PPath);
        public : ~CAudio();
    }
    *GAudio;
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio{
    class CSound{
        private : Mix_Chunk* VData;
        private : std::int32_t VTrack;

        public : CSound(const std::string& PPath);
        public : CSound& FPlay();
        public : bool FPlaying();
        public : ~CSound();
    };
}
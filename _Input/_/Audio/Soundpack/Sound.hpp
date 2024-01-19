#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio::NSoundpack{
    class CSound{
        private : std::string VPath;
        private : Mix_Chunk* VHandle;
        private : std::int32_t VChannel;

        public : CSound(const std::string& PPath);
        public : std::string FPath() const;
        public : CSound& FPlay();
        public : bool FPlaying();
        public : ~CSound();
    };
}
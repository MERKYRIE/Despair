#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    class CSound{
        private : friend class CAudio;
        
        private : std::string VPath;
        private : Mix_Chunk* VHandle;
        private : std::int32_t VChannel;

        private : bool operator==(const std::string& PPath) const;

        private : CSound(const std::string& PPath);
        public : const CSound& FPlay() const;
        public : bool FPlaying() const;
        public : ~CSound();
    };
}
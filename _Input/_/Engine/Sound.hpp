#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CSound{
        private : friend class CSoundpack;
        
        private : std::string VPath;
        private : Mix_Chunk* VHandle;
        private : std::int32_t VChannel;

        private : bool operator==(const std::string& PPath) const;

        public : CSound(const std::string& PPath);
        public : const CSound& FPlay() const;
        public : bool FPlaying() const;
        public : ~CSound();
    };
}
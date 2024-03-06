#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio
{
    class CSound
    {
        friend class CAudio;
        
        private : std::string FPath;
        private : Mix_Chunk* FHandle;
        private : std::int32_t FChannel;

        private : CSound(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : const CSound& OPlay() const;
        public : bool OIsPlaying() const;
        public : ~CSound();
    };
}
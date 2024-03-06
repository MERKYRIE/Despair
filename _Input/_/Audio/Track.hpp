#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio
{
    class CTrack
    {
        friend class CAudio;
        
        private : std::string FPath;
        private : Mix_Music* FHandle;

        private : CTrack(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : const CTrack& OPlay() const;
        public : const CTrack& OPause() const;
        public : const CTrack& OResume() const;
        public : const CTrack& OStop() const;
        public : const CTrack& OAccessVolume(std::uint8_t PValue) const;
        public : ~CTrack();
    };
}
#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CTrack{
        private : friend class CAudio;
        
        private : std::string VPath;
        private : Mix_Music* VHandle;

        private : bool operator==(const std::string& PPath) const;

        private : CTrack(const std::string& PPath);
        public : const CTrack& FPlay() const;
        public : const CTrack& FPause() const;
        public : const CTrack& FResume() const;
        public : const CTrack& FStop() const;
        public : ~CTrack();
    };
}
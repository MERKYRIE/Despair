#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio::NSoundtrack{
    class CTrack{
        private : std::string VPath;
        private : Mix_Music* VData;

        public : CTrack(const std::string& PPath);
        public : std::string FPath() const;
        public : CTrack& FPlay();
        public : CTrack& FPause();
        public : CTrack& FResume();
        public : CTrack& FStop();
        public : ~CTrack();
    };
}
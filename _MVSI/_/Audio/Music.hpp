#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio{
    class CMusic{
        private : Mix_Music* VData;

        public : CMusic(const std::string& PPath);
        public : CMusic& FPlay();
        public : CMusic& FPause();
        public : CMusic& FResume();
        public : CMusic& FStop();
        public : ~CMusic();
    };
}
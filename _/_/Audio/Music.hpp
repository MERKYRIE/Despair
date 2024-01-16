#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NAudio
{
    class CMusic
    {
        private:
            Mix_Music* VData;
        public:
            CMusic(const std::string& PPath);
            CMusic& FPlay();
            CMusic& FPause();
            CMusic& FResume();
            CMusic& FStop();
            ~CMusic();
    };
}
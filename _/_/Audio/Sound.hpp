#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NAudio
{
    class CSound
    {
        private:
            Mix_Chunk* VData;
            signed int VTrack;
        public:
            CSound(const std::string& PPath);
            CSound& FPlay();
            bool FPlaying();
            ~CSound();

    };
}
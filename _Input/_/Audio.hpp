#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    namespace NAudio
    {
        class CSound;
        class CTrack;
    }
    
    inline class CAudio
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<NAudio::CSound>> FSounds;
        private : std::vector<std::shared_ptr<NAudio::CTrack>> FTracks;

        private : void BInitialize();
        private : void BDeinitialize();

        public : const NAudio::CSound& OAccessSound(const std::string& PPath);
        public : const NAudio::CTrack& OAccessTrack(const std::string& PPath);
    }
    GAudio;
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    class CSound;
    class CTrack;
    
    inline class CAudio
    {
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CSound>> FSounds;
        private : std::vector<std::shared_ptr<CTrack>> FTracks;

        private : void AInitialize();
        private : void ADeinitialize();

        public : const CSound& OAccessSound(const std::string& PPath);
        public : const CTrack& OAccessTrack(const std::string& PPath);
    }
    GAudio;
}
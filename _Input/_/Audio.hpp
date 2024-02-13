#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    class CSound;
    class CTrack;
    
    inline class CAudio{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CSound>> VSounds;
        private : std::vector<std::shared_ptr<CTrack>> VTracks;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const CSound& FSound(const std::string& PPath);
        public : const CTrack& FTrack(const std::string& PPath);
    }
    GAudio;
}
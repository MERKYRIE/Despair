#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio{
    namespace NSoundtrack{
        class CTrack;
    }
    
    inline class CSoundtrack{
        private : friend class CAudio;

        private : std::vector<std::shared_ptr<NSoundtrack::CTrack>> VTracks;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const NSoundtrack::CTrack& FTrack(const std::string& PPath);
    }
    GSoundtrack;
}
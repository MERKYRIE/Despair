#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CTrack;
    
    inline class CSoundtrack{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CTrack>> VTracks;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const CTrack& FTrack(const std::string& PPath);
    }
    GSoundtrack;
}
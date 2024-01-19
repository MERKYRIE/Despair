#pragma once

#include"Blindness.hpp"

namespace NBlindness::NAudio{
    namespace NSoundpack{
        class CSound;
    }
    
    inline class CSoundpack{
        private : friend class CAudio;

        private : std::vector<std::shared_ptr<NSoundpack::CSound>> VSounds;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const NSoundpack::CSound& FSound(const std::string& PPath);
    }
    GSoundpack;
}
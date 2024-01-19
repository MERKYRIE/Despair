#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo{
    namespace NTypeface{
        class CFont;
    }
    
    inline class CTypeface{
        private : friend class CVideo;

        private : std::vector<std::shared_ptr<NTypeface::CFont>> VFonts;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const NTypeface::CFont& FFont(const std::string& PPath);
    }
    GTypeface;
}
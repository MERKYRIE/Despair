#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CFont;
    
    inline class CTypeface{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CFont>> VFonts;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const CFont& FFont(const std::string& PPath);
    }
    GTypeface;
}
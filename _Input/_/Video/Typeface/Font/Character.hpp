#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo::NTypeface::NFont{
    class CCharacter{
        private : friend class CFont;
        
        private : std::uint32_t VIdentifier;

        public : CCharacter(TTF_Font* PFont , char PCode);
        public : std::uint32_t FIdentifier() const;
        public : ~CCharacter();
    };
}
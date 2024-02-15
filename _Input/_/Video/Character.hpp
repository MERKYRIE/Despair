#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo{
    class CCharacter{
        private : friend class CFont;
        
        private : std::uint32_t VIdentifier;

        private : CCharacter(TTF_Font* PFont , char PCode);

        public : std::uint32_t FIdentifier() const;
        public : ~CCharacter();
    };
}
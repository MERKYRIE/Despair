#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo
{
    class CCharacter
    {
        private : friend class CFont;
        
        private : std::uint32_t FIdentifier;

        private : CCharacter(TTF_Font* PFont , char PCode);

        public : std::uint32_t OAccessIdentifier() const;
        public : ~CCharacter();
    };
}
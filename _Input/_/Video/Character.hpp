#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CCharacter
    {
        private : std::uint32_t FIdentifier;

        public : CCharacter(TTF_Font* PFont , char PCode);
        public : std::uint32_t AIdentifier();
        public : CCharacter* ABind();
        public : ~CCharacter();
    };
}
#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CFont
    {       
        private : std::string FPath;
        private : std::vector<std::shared_ptr<CCharacter>> FDigits;
        private : std::vector<std::shared_ptr<CCharacter>> FUppercases;
        private : std::vector<std::shared_ptr<CCharacter>> FLowercases;

        public : CFont(const std::string& PPath);
        public : std::string APath();
        public : bool AIs(const std::string& PPath);
        public : CCharacter* AAccessDigit(char PCode);
        public : CCharacter* AAccessUppercase(char PCode);
        public : CCharacter* AAccessLowercase(char PCode);
        public : ~CFont();
    };
}
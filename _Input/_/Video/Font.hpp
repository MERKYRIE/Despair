#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo
{
    class CCharacter;
    
    class CFont
    {
        friend class CVideo;
        
        private : std::string FPath;
        private : std::vector<std::shared_ptr<CCharacter>> FDigits;
        private : std::vector<std::shared_ptr<CCharacter>> FUppercases;
        private : std::vector<std::shared_ptr<CCharacter>> FLowercases;

        private : CFont(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : const CCharacter& OAccessDigit(char PCode) const;
        public : const CCharacter& OAccessUppercase(char PCode) const;
        public : const CCharacter& OAccessLowercase(char PCode) const;
        public : ~CFont();
    };
}
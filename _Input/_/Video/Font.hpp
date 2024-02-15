#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo{
    class CCharacter;
    
    class CFont{
        private : friend class CVideo;
        
        private : std::string VPath;
        private : std::vector<std::shared_ptr<CCharacter>> VDigits;
        private : std::vector<std::shared_ptr<CCharacter>> VUppercases;
        private : std::vector<std::shared_ptr<CCharacter>> VLowercases;

        private : bool operator==(const std::string& PPath) const;

        private : CFont(const std::string& PPath);
        public : const CCharacter& FDigit(char PCode) const;
        public : const CCharacter& FUppercase(char PCode) const;
        public : const CCharacter& FLowercase(char PCode) const;
        public : ~CFont();
    };
}
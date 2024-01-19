#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo::NTypeface{
    namespace NFont{
        class CCharacter;
    }
    
    class CFont{
        private : friend class CTypeface;
        
        private : std::string VPath;
        private : std::vector<std::shared_ptr<NFont::CCharacter>> VDigits;
        private : std::vector<std::shared_ptr<NFont::CCharacter>> VUppercases;
        private : std::vector<std::shared_ptr<NFont::CCharacter>> VLowercases;

        private : bool operator==(const std::string& PPath) const;

        public : CFont(const std::string& PPath);
        public : const NFont::CCharacter& FDigit(char PCode) const;
        public : const NFont::CCharacter& FUppercase(char PCode) const;
        public : const NFont::CCharacter& FLowercase(char PCode) const;
        public : ~CFont();
    };
}
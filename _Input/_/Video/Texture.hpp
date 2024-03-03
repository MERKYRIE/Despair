#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo
{
    class CTexture
    {
        private : friend class CVideo;
        
        private : std::string FPath;
        private : std::uint32_t FIdentifier;

        private : CTexture(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : std::uint32_t OAccessIdentifier() const;
        public : ~CTexture();
    };
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo::NAtlas{
    class CTexture{
        private : friend class CAtlas;
        
        private : std::string VPath;
        private : std::uint32_t VIdentifier;

        private : bool operator==(const std::string& PPath) const;

        public : CTexture(const std::string& PPath);
        public : std::uint32_t FIdentifier() const;
        public : ~CTexture();
    };
}
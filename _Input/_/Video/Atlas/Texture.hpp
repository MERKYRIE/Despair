#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo::NAtlas{
    class CTexture{
        private : std::string VPath;
        private : std::uint32_t VIdentifier;

        public : CTexture(const std::string& PPath);
        public : std::string FPath() const;
        public : std::uint32_t FIdentifier() const;
        public : ~CTexture();
    };
}
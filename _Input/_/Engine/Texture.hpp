#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CTexture{
        private : friend class CVideo;
        
        private : std::string VPath;
        private : std::uint32_t VIdentifier;

        private : bool operator==(const std::string& PPath) const;

        private : CTexture(const std::string& PPath);
        public : std::uint32_t FIdentifier() const;
        public : ~CTexture();
    };
}
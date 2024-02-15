#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo{
    class CShader{
        private : friend class CVideo;
        
        private : std::uint32_t VIdentifier;

        private : CShader(const std::string& PPath , std::uint32_t PType);
        public : std::uint32_t FIdentifier() const;
        public : ~CShader();
    };
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo
{
    class CShader
    {
        friend class CVideo;
        
        private : std::uint32_t FIdentifier;

        private : CShader(const std::string& PPath , std::uint32_t PType);
        private : std::uint32_t BIdentifier();

        public : ~CShader();
    };
}
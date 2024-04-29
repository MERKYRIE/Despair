#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CTexture
    {
        private : std::string FPath;
        private : std::uint32_t FIdentifier;

        public : CTexture(const std::string& PPath);
        public : bool AEqual(const std::string& PPath);
        public : std::uint32_t AIdentifier();
        public : ~CTexture();
    };
}
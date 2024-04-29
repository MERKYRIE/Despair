#pragma once

#include"Despair.hpp"

namespace NDespair::NVideo
{
    class CShader
    {
        private : std::uint32_t FIdentifier;

        public : CShader(const std::string& PPath , std::uint32_t PType);
        public : std::uint32_t AIdentifier();
        public : ~CShader();
    };
}
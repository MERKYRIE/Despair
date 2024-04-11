#pragma once

#include"Core.hpp"

namespace NDespair
{
    class CTime
    {
        private : std::uint32_t FLast;
        private : std::uint32_t FAbsolute;
        private : std::uint32_t FRelative;

        public : void AUpdate();
        public : std::uint32_t AAbsolute();
        public : std::uint32_t ARelative();
    };
}
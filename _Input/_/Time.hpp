#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CTime
    {
        private : std::uint32_t FTimepointLast;
        private : std::uint32_t FTimepointAbsolute;
        private : std::uint32_t FTimepointRelative;

        public : CTime();
        public : void AUpdate();
        public : std::uint32_t AAbsolute();
        public : std::uint32_t ARelative();
    }
    *GTime;
}
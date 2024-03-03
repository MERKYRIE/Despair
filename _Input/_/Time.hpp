#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    inline class CTime
    {
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::uint32_t FLast;
        private : std::uint32_t FAbsolute;
        private : std::uint32_t FRelative;

        private : void AUpdate();

        public : std::uint32_t OAccessAbsolute();
        public : std::uint32_t OAccessRelative();
    }
    GTime;
}
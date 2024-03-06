#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    inline class CTime
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : std::uint32_t FLast;
        private : std::uint32_t FAbsolute;
        private : std::uint32_t FRelative;

        private : void BUpdate();

        public : std::uint32_t OAbsolute();
        public : std::uint32_t ORelative();
    }
    GTime;
}
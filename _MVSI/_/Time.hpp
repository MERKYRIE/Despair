#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CTime{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::uint32_t VLast;
        private : std::uint32_t VAbsolute;
        private : std::uint32_t VRelative;

        private : void FUpdate();

        public : std::uint32_t FAbsolute();
        public : std::uint32_t FRelative();
    }
    GTime;
}
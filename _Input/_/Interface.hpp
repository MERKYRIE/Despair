#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CInterface{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::array<std::uint32_t , 10> VDigits;
        private : std::array<std::array<std::uint32_t , 26> , 2> VLetters;
        private : std::string VCommand;

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GInterface;
}
#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CInterface{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::string VCommand;

        private : void FUpdate();
    }
    GInterface;
}
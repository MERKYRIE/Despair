#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CInput{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : void FInitialize();
        private : void FUpdate();
    }
    GInput;
}
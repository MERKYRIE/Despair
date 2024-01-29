#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CInput{
        private : friend std::int32_t (::main(std::int32_t , char**));
        
        private : void FUpdate();
    }
    GInput;
}
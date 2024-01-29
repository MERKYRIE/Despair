#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CLevel{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GLevel;
}
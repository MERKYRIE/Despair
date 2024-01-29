#pragma once

#include"Engine.hpp"

namespace NBlindness{
    inline class CGame{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GGame;
}
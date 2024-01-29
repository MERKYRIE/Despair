#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CAudio{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : void FInitialize();
        private : void FDeinitialize();
    }
    GAudio;
}
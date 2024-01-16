#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL
{
    inline class CInput
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            void FInitialize();
            void FUpdate();
    }
    GInput;
}
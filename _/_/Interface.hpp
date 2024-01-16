#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL
{
    inline class CInterface
    {
        private:
            friend signed int ::main(signed int , char**); 
        private:
            std::array<unsigned int , 10> VDigits;
            std::array<std::array<unsigned int , 26> , 2> VLetters;
            std::string VCommand;
        private:
            void FInitialize();
            void FUpdate();
            void FDeinitialize();
    }
    GInterface;
}
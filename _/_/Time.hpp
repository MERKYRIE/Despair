#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL
{
    inline class CTime
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            unsigned int VLast;
            unsigned int VAbsolute;
            unsigned int VRelative;
        private:
            void FUpdate();
        public:
            unsigned int FAbsolute();
            unsigned int FRelative();
    }
    GTime;
}
#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NDebug::NAssert::NInformation
{
    inline class CSDL
    {
        public:
            bool FCode(signed int PValue , const std::source_location& PLocation = std::source_location::current());
            bool FHandle(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
            bool FFlags(signed int PValue , const std::source_location& PLocation = std::source_location::current());
    }
    GSDL;
}
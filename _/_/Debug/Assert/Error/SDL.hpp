#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NDebug::NAssert::NError
{
    inline class CSDL
    {
        public:
            void FCode(signed int PValue , const std::source_location& PLocation = std::source_location::current());
            void FHandle(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
            void FFlags(signed int PValue , const std::source_location& PLocation = std::source_location::current());
    }
    GSDL;
}
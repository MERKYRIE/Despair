#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NDebug::NAssert
{
    inline class CError
    {
        public:
            void FOGL(const std::source_location& PLocation = std::source_location::current());
            void FOAIL(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    GError;
}
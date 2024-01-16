#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NDebug::NAssert
{
    inline class CWarning
    {
        public:
            bool FOGL(const std::source_location& PLocation = std::source_location::current());
            bool FOAIL(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    GWarning;
}
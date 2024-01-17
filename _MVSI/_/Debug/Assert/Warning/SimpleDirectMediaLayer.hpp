#pragma once

#include"Blindness.hpp"

namespace NBlindness::NDebug::NAssert::NWarning{
    inline class CSimpleDirectMediaLayer{
        public : bool FCode(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool FHandle(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool FFlags(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
    }
    GSimpleDirectMediaLayer;
}
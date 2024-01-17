#pragma once

#include"Blindness.hpp"

namespace NBlindness::NDebug::NAssert::NError{
    inline class CSimpleDirectMediaLayer{
        public : void FCode(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void FHandle(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : void FFlags(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
    }
    GSimpleDirectMediaLayer;
}
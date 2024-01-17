#pragma once

#include"Blindness.hpp"

namespace NBlindness::NDebug::NAssert{
    inline class CError{
        public : void FOpenGraphicsLibrary(const std::source_location& PLocation = std::source_location::current());
        public : void FOpenAssetImportLibrary(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    GError;
}
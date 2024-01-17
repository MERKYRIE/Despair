#pragma once

#include"Blindness.hpp"

namespace NBlindness::NDebug::NAssert{
    inline class CInformation{
        public : bool FOpenGraphicsLibrary(const std::source_location& PLocation = std::source_location::current());
        public : bool FOpenAssetImportLibrary(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    GInformation;
}
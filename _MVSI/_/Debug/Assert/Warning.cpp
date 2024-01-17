#include"Warning.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NDebug::NAssert{
    bool CWarning::FOpenGraphicsLibrary(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        return GAssert.FWarning(LCode , std::string{} + "Open Graphics Library - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    bool CWarning::FOpenAssetImportLibrary(const void* PHandle , const std::source_location& PLocation){
        return GAssert.FWarning(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
}
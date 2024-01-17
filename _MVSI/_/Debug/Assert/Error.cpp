#include"Error.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NDebug::NAssert{
    void CError::FOpenGraphicsLibrary(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        GAssert.FError(LCode , std::string{} + "Open Graphics Library - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    void CError::FOpenAssetImportLibrary(const void* PHandle , const std::source_location& PLocation){
        GAssert.FError(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
}
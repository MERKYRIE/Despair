#include"Information.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NDebug::NAssert{
    bool CInformation::FOpenGraphicsLibrary(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        return GAssert.FInformation(LCode , std::string{} + "Open Graphics Library - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    bool CInformation::FOpenAssetImportLibrary(const void* PHandle , const std::source_location& PLocation){
        return GAssert.FInformation(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
}
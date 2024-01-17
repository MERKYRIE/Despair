#include"SimpleDirectMediaLayer.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NDebug::NAssert::NError{
    void CSimpleDirectMediaLayer::FCode(std::int32_t PValue , const std::source_location& PLocation){
        GAssert.FError(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    
    void CSimpleDirectMediaLayer::FHandle(const void* PPointer , const std::source_location& PLocation){
        GAssert.FError(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    void CSimpleDirectMediaLayer::FFlags(std::int32_t PValue , const std::source_location& PLocation){
        GAssert.FError(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
}
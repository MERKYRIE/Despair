#include"SimpleDirectMediaLayer.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NDebug::NAssert::NInformation{
    bool CSimpleDirectMediaLayer::FCode(std::int32_t PValue , const std::source_location& PLocation){
        return GAssert.FInformation(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    
    bool CSimpleDirectMediaLayer::FHandle(const void* PPointer , const std::source_location& PLocation){
        return GAssert.FInformation(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CSimpleDirectMediaLayer::FFlags(std::int32_t PValue , const std::source_location& PLocation){
        return GAssert.FInformation(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
}
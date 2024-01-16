#include "SDL.hpp"

#include "Debug\\Assert.hpp"

namespace NMRKOGL::NDebug::NAssert::NWarning
{
    bool CSDL::FCode(signed int PValue , const std::source_location& PLocation)
    {
        return GAssert.FWarning(PValue < 0 , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }
    
    bool CSDL::FHandle(const void* PPointer , const std::source_location& PLocation)
    {
        return GAssert.FWarning(!PPointer , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }

    bool CSDL::FFlags(signed int PValue , const std::source_location& PLocation)
    {
        return GAssert.FWarning(!PValue , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }
}
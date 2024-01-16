#include "SDL.hpp"

#include "Debug\\Assert.hpp"

namespace NMRKOGL::NDebug::NAssert::NError
{
    void CSDL::FCode(signed int PValue , const std::source_location& PLocation)
    {
        GAssert.FError(PValue < 0 , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }
    
    void CSDL::FHandle(const void* PPointer , const std::source_location& PLocation)
    {
        GAssert.FError(!PPointer , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }

    void CSDL::FFlags(signed int PValue , const std::source_location& PLocation)
    {
        GAssert.FError(!PValue , std::string{} + "SDL - " + SDL_GetError() , PLocation);
    }
}
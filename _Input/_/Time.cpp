#include"Time.hpp"

namespace NDespair
{
    void CTime::AUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }
    std::uint32_t CTime::AAbsolute()
    {
        return(FAbsolute);
    }
    std::uint32_t CTime::ARelative()
    {
        return(FRelative);
    }
}
#include"Time.hpp"

namespace NDespair
{
    CTime::CTime()
    {
        GTime = this;
        FLast = 0;
        FAbsolute = 0;
        FRelative = 0;
    }
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
#include"Time.hpp"

namespace NBlindness
{
    void CTime::AUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }

    std::uint32_t CTime::OAccessAbsolute()
    {
        return FAbsolute;
    }

    std::uint32_t CTime::OAccessRelative()
    {
        return FRelative;
    }
}
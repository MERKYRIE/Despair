#include"Time.hpp"

namespace NDespair
{
    CTime::CTime()
    {
        GTime = this;
        FTimepointLast = 0;
        FTimepointAbsolute = 0;
        FTimepointRelative = 0;
    }
    void CTime::AUpdate()
    {
        FTimepointLast = FTimepointAbsolute;
        FTimepointAbsolute = SDL_GetTicks();
        FTimepointRelative = FTimepointAbsolute - FTimepointLast;
    }
    std::uint32_t CTime::AAbsolute()
    {
        return(FTimepointAbsolute);
    }
    std::uint32_t CTime::ARelative()
    {
        return(FTimepointRelative);
    }
}
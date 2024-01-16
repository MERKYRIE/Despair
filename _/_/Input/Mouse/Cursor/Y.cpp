#include "Y.hpp"

namespace NMRKOGL::NInput::NMouse::NCursor
{
    void CY::FPreupdate()
    {
        VRelative = 0;
        VChanged = false;
    }
    
    void CY::FPostupdate(const SDL_Event& PEvent)
    {
        VAbsolute = PEvent.motion.y;
        VRelative = PEvent.motion.yrel;
        VChanged = VRelative;
    }

    signed int CY::FAbsolute()
    {
        return VAbsolute;
    }

    signed int CY::FRelative()
    {
        return VRelative;
    }

    bool CY::FChanged()
    {
        return VChanged;
    }
}
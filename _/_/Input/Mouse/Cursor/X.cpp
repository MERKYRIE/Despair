#include "X.hpp"

namespace NMRKOGL::NInput::NMouse::NCursor
{
    void CX::FPreupdate()
    {
        VRelative = 0;
        VChanged = false;
    }
    
    void CX::FPostupdate(const SDL_Event& PEvent)
    {
        VAbsolute = PEvent.motion.x;
        VRelative = PEvent.motion.xrel;
        VChanged = VRelative;
    }

    signed int CX::FAbsolute()
    {
        return VAbsolute;
    }

    signed int CX::FRelative()
    {
        return VRelative;
    }

    bool CX::FChanged()
    {
        return VChanged;
    }
}
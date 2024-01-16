#include "Mouse.hpp"

#include "Mouse\\Button.hpp"
#include "Mouse\\Cursor.hpp"
#include "Mouse\\Wheel.hpp"

namespace NMRKOGL::NInput
{
    void CMouse::FInitialize()
    {
        NMouse::GCursor.FInitialize();
    }

    void CMouse::FPreupdate()
    {
        NMouse::GCursor.FPreupdate();
    }

    void CMouse::FPostupdate(const SDL_Event& PEvent)
    {
        switch(PEvent.type)
        {
            case SDL_MOUSEMOTION:
                NMouse::GCursor.FPostupdate(PEvent);
            break;
            case SDL_MOUSEBUTTONDOWN:
                NMouse::GButton.FUpdate(PEvent);
                VPressedX[PEvent.button.button - 1] = PEvent.button.x;
                VPressedY[PEvent.button.button - 1] = PEvent.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
                NMouse::GButton.FUpdate(PEvent);
                VReleasedX[PEvent.button.button - 1] = PEvent.button.x;
                VReleasedY[PEvent.button.button - 1] = PEvent.button.y;
            break;
            case SDL_MOUSEWHEEL:
                NMouse::GWheel.FUpdate(PEvent);
            break;
        }
    }

    signed int CMouse::FPressedX(unsigned char PButton)
    {
        return VPressedX[PButton - 1];
    }

    signed int CMouse::FPressedY(unsigned char PButton)
    {
        return VPressedY[PButton - 1];
    }

    signed int CMouse::FReleasedX(unsigned char PButton)
    {
        return VReleasedX[PButton - 1];
    }

    signed int CMouse::FReleasedY(unsigned char PButton)
    {
        return VReleasedY[PButton - 1];
    }
}
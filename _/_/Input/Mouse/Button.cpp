#include "Button.hpp"

namespace NMRKOGL::NInput::NMouse
{
    void CButton::FUpdate(const SDL_Event& PEvent)
    {
        switch(PEvent.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                VHeld[PEvent.button.button - 1] = true;
                VPressed[PEvent.button.button - 1] = true;
                VReleased[PEvent.button.button - 1] = false;
            break;
            case SDL_MOUSEBUTTONUP:
                VHeld[PEvent.button.button - 1] = false;
                VPressed[PEvent.button.button - 1] = false;
                VReleased[PEvent.button.button - 1] = true;
            break;
        }
    }

    bool CButton::FHeld(unsigned char PButton)
    {
        return VHeld[PButton - 1];
    }

    bool CButton::FPressed(unsigned char PButton)
    {
        return VPressed[PButton - 1];
    }

    bool CButton::FReleased(unsigned char PButton)
    {
        return VHeld[PButton - 1];
    }
}
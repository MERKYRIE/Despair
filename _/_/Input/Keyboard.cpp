#include "Keyboard.hpp"

namespace NMRKOGL::NInput
{
    void CKeyboard::FPreupdate()
    {
        for(unsigned short LKey{0} ; LKey < 512 ; LKey++)
        {
            VPressed[LKey] = false;
            VReleased[LKey] = false;
        }
    }
    
    void CKeyboard::FPostupdate(const SDL_Event& PEvent)
    {
        switch(PEvent.type)
        {
            case SDL_KEYDOWN:
                VHeld[PEvent.key.keysym.scancode] = true;
                if(!PEvent.key.repeat)
                {
                    VPressed[PEvent.key.keysym.scancode] = true;
                }
            break;
            case SDL_KEYUP:
                VHeld[PEvent.key.keysym.scancode] = false;
                if(!PEvent.key.repeat)
                {
                    VReleased[PEvent.key.keysym.scancode] = true;
                }
            break;
        }
    }

    bool CKeyboard::FHeld(unsigned short PKey)
    {
        return VHeld[PKey];
    }

    bool CKeyboard::FPressed(unsigned short PKey)
    {
        return VPressed[PKey];
    }

    bool CKeyboard::FReleased(unsigned short PKey)
    {
        return VReleased[PKey];
    }
}
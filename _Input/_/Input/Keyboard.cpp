#include"Keyboard.hpp"

namespace NBlindness::NInput{
    void CKeyboard::FPreupdate(){
        for(std::uint16_t LKey{0} ; LKey < 512 ; LKey++){
            VPressed[LKey] = false;
            VReleased[LKey] = false;
        }
    }
    
    void CKeyboard::FPostupdate(const SDL_Event& PEvent){
        switch(PEvent.type){
            case SDL_KEYDOWN:
                VHeld[PEvent.key.keysym.scancode] = true;
                if(!PEvent.key.repeat){
                    VPressed[PEvent.key.keysym.scancode] = true;
                }
            break;
            case SDL_KEYUP:
                VHeld[PEvent.key.keysym.scancode] = false;
                if(!PEvent.key.repeat){
                    VReleased[PEvent.key.keysym.scancode] = true;
                }
            break;
        }
    }

    bool CKeyboard::FHeld(std::uint16_t PKey){
        return VHeld[PKey];
    }

    bool CKeyboard::FPressed(std::uint16_t PKey){
        return VPressed[PKey];
    }

    bool CKeyboard::FReleased(std::uint16_t PKey){
        return VReleased[PKey];
    }
}
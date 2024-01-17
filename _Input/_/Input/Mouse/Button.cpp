#include"Button.hpp"

namespace NBlindness::NInput::NMouse{
    void CButton::FPreupdate(){
        for(std::uint8_t LButton{0} ; LButton <= 4 ; LButton++){
            VPressed[LButton] = false;
            VReleased[LButton] = false;
        }
    }
    
    void CButton::FUpdate(const SDL_Event& PEvent){
        switch(PEvent.type){
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

    bool CButton::FHeld(std::uint8_t PButton){
        return VHeld[PButton - 1];
    }

    bool CButton::FPressed(std::uint8_t PButton){
        return VPressed[PButton - 1];
    }

    bool CButton::FReleased(std::uint8_t PButton){
        return VHeld[PButton - 1];
    }
}
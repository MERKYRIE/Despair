#include"Input.hpp"

namespace NBlindness{
    void CInput::FUpdate(){
        for(std::uint16_t LKey{0} ; LKey < 512 ; LKey++){
            VKeyPressed[LKey] = false;
            VKeyReleased[LKey] = false;
        }
        for(std::uint8_t LButton{0} ; LButton <= 4 ; LButton++){
            VButtonPressed[LButton] = false;
            VButtonReleased[LButton] = false;
        }
        VRelativeX = 0;
        VXModified = false;
        VRelativeY = 0;
        VYModified = false;
        VWheelState = 0;
        VWheelModified = false;
        VWheelDown = false;
        VWheelUp = false;
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent)){
            switch(LEvent.type){
                case SDL_KEYDOWN:
                    VKeyHeld[LEvent.key.keysym.scancode] = true;
                    if(!LEvent.key.repeat){
                        VKeyPressed[LEvent.key.keysym.scancode] = true;
                    }
                break;
                case SDL_KEYUP:
                    VKeyHeld[LEvent.key.keysym.scancode] = false;
                    if(!LEvent.key.repeat){
                        VKeyReleased[LEvent.key.keysym.scancode] = true;
                    }
                break;
                case SDL_MOUSEBUTTONDOWN:
                    VButtonHeld[LEvent.button.button - 1] = true;
                    VButtonPressed[LEvent.button.button - 1] = true;
                    VButtonReleased[LEvent.button.button - 1] = false;
                    VPressedX[LEvent.button.button - 1] = LEvent.button.x;
                    VPressedY[LEvent.button.button - 1] = LEvent.button.y;
                break;
                case SDL_MOUSEBUTTONUP:
                    VButtonHeld[LEvent.button.button - 1] = false;
                    VButtonPressed[LEvent.button.button - 1] = false;
                    VButtonReleased[LEvent.button.button - 1] = true;
                    VReleasedX[LEvent.button.button - 1] = LEvent.button.x;
                    VReleasedY[LEvent.button.button - 1] = LEvent.button.y;
                break;
                case SDL_MOUSEMOTION:
                    VAbsoluteX = LEvent.motion.x;
                    VRelativeX = LEvent.motion.xrel;
                    VXModified = VRelativeX;
                    VAbsoluteY = LEvent.motion.y;
                    VRelativeY = LEvent.motion.yrel;
                    VYModified = VRelativeY;
                break;
                case SDL_MOUSEWHEEL:
                    switch(LEvent.wheel.y){
                        case -1:
                            VWheelState = LEvent.wheel.y;
                            VWheelModified = true;
                            VWheelDown = true;
                            VWheelUp = false;
                        break;
                        case 0:
                            VWheelState = LEvent.wheel.y;
                            VWheelModified = false;
                            VWheelDown = false;
                            VWheelUp = false;
                        break;
                        case +1:
                            VWheelState = LEvent.wheel.y;
                            VWheelModified = true;
                            VWheelDown = false;
                            VWheelUp = true;
                        break;
                    }
                break;
            }
        }
    }

    bool CInput::FKeyHeld(std::uint16_t PKey){
        return VKeyHeld[PKey];
    }

    bool CInput::FKeyPressed(std::uint16_t PKey){
        return VKeyPressed[PKey];
    }

    bool CInput::FKeyReleased(std::uint16_t PKey){
        return VKeyReleased[PKey];
    }

    bool CInput::FButtonHeld(std::uint8_t PButton){
        return VButtonHeld[PButton - 1];
    }

    bool CInput::FButtonPressed(std::uint8_t PButton){
        return VButtonPressed[PButton - 1];
    }

    bool CInput::FButtonReleased(std::uint8_t PButton){
        return VButtonHeld[PButton - 1];
    }

    std::int32_t CInput::FAbsoluteX(){
        return VAbsoluteX;
    }

    std::int32_t CInput::FRelativeX(){
        return VRelativeX;
    }

    bool CInput::FXModified(){
        return VXModified;
    }

    std::int32_t CInput::FAbsoluteY(){
        return VAbsoluteY;
    }

    std::int32_t CInput::FRelativeY(){
        return VRelativeY;
    }

    bool CInput::FYModified(){
        return VYModified;
    }

    std::int32_t CInput::FPressedX(std::uint8_t PButton){
        return VPressedX[PButton - 1];
    }

    std::int32_t CInput::FPressedY(std::uint8_t PButton){
        return VPressedY[PButton - 1];
    }

    std::int32_t CInput::FReleasedX(std::uint8_t PButton){
        return VReleasedX[PButton - 1];
    }

    std::int32_t CInput::FReleasedY(std::uint8_t PButton){
        return VReleasedY[PButton - 1];
    }

    std::int32_t CInput::FWheelState(){
        return VWheelState;
    }

    bool CInput::FWheelModified(){
        return VWheelModified;
    }

    bool CInput::FWheelDown(){
        return VWheelDown;
    }

    bool CInput::FWheelUp(){
        return VWheelUp;
    }
}
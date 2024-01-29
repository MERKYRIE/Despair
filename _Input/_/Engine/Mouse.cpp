#include"Mouse.hpp"

namespace NBlindness::NEngine{
    void CMouse::FPreupdate(){
        for(std::uint8_t LButton{0} ; LButton <= 4 ; LButton++){
            VPressed[LButton] = false;
            VReleased[LButton] = false;
        }
        VRelativeX = 0;
        VXModified = false;
        VRelativeY = 0;
        VYModified = false;
        VWheel = 0;
        VWheelModified = false;
        VWheelDown = false;
        VWheelUp = false;
    }

    void CMouse::FPostupdate(const SDL_Event& PEvent){
        switch(PEvent.type){
            case SDL_MOUSEBUTTONDOWN:
                VHeld[PEvent.button.button - 1] = true;
                VPressed[PEvent.button.button - 1] = true;
                VReleased[PEvent.button.button - 1] = false;
                VPressedX[PEvent.button.button - 1] = VAbsoluteX;
                VPressedY[PEvent.button.button - 1] = VAbsoluteY;
            break;
            case SDL_MOUSEBUTTONUP:
                VHeld[PEvent.button.button - 1] = false;
                VPressed[PEvent.button.button - 1] = false;
                VReleased[PEvent.button.button - 1] = true;
                VReleasedX[PEvent.button.button - 1] = VAbsoluteX;
                VReleasedY[PEvent.button.button - 1] = VAbsoluteY;
            break;
            case SDL_MOUSEMOTION:
                VAbsoluteX = PEvent.motion.x;
                VRelativeX = PEvent.motion.xrel;
                VXModified = VRelativeX;
                VAbsoluteY = PEvent.motion.y;
                VRelativeY = PEvent.motion.yrel;
                VYModified = VRelativeY;
            break;
            case SDL_MOUSEWHEEL:
                switch(PEvent.wheel.y){
                    case -1:
                        VWheel = PEvent.wheel.y;
                        VWheelModified = true;
                        VWheelDown = true;
                        VWheelUp = false;
                    break;
                    case 0:
                        VWheel = PEvent.wheel.y;
                        VWheelModified = false;
                        VWheelDown = false;
                        VWheelUp = false;
                    break;
                    case +1:
                        VWheel = PEvent.wheel.y;
                        VWheelModified = true;
                        VWheelDown = false;
                        VWheelUp = true;
                    break;
                }
            break;
        }
    }

    bool CMouse::FHeld(std::uint8_t PButton){
        return VHeld[PButton - 1];
    }

    bool CMouse::FPressed(std::uint8_t PButton){
        return VPressed[PButton - 1];
    }

    bool CMouse::FReleased(std::uint8_t PButton){
        return VHeld[PButton - 1];
    }

    std::int32_t CMouse::FAbsoluteX(){
        return VAbsoluteX;
    }

    std::int32_t CMouse::FRelativeX(){
        return VRelativeX;
    }

    bool CMouse::FXModified(){
        return VXModified;
    }

    std::int32_t CMouse::FAbsoluteY(){
        return VAbsoluteY;
    }

    std::int32_t CMouse::FRelativeY(){
        return VRelativeY;
    }

    bool CMouse::FYModified(){
        return VYModified;
    }

    std::int32_t CMouse::FPressedX(std::uint8_t PButton){
        return VPressedX[PButton - 1];
    }

    std::int32_t CMouse::FPressedY(std::uint8_t PButton){
        return VPressedY[PButton - 1];
    }

    std::int32_t CMouse::FReleasedX(std::uint8_t PButton){
        return VReleasedX[PButton - 1];
    }

    std::int32_t CMouse::FReleasedY(std::uint8_t PButton){
        return VReleasedY[PButton - 1];
    }

    std::int32_t CMouse::FWheel(){
        return VWheel;
    }

    bool CMouse::FWheelModified(){
        return VWheelModified;
    }

    bool CMouse::FWheelDown(){
        return VWheelDown;
    }

    bool CMouse::FWheelUp(){
        return VWheelUp;
    }
}
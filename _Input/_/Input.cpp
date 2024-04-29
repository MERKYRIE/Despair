#include"Input.hpp"

namespace NDespair
{
    CInput::CInput()
    {
        GInput = this;
        for(std::uint16_t LKey{0} ; LKey < 512 ; LKey++)
        {
            FIsKeyHeld[LKey] = false;
            FIsKeyPressed[LKey] = false;
            FIsKeyReleased[LKey] = false;
        }
        for(std::uint8_t LButton{0} ; LButton <= 4 ; LButton++)
        {
            FIsButtonHeld[LButton] = false;
            FIsButtonPressed[LButton] = false;
            FIsButtonReleased[LButton] = false;
            FPressedX[LButton] = 0;
            FPressedY[LButton] = 0;
            FReleasedX[LButton] = 0;
            FReleasedY[LButton] = 0;
        }
        FAbsoluteX = 0;
        FRelativeX = 0;
        FIsXModified = false;
        FAbsoluteY = 0;
        FRelativeY = 0;
        FIsYModified = false;
        FWheelState = 0;
        FIsWheelModified = false;
        FIsWheelDown = false;
        FIsWheelUp = false;
    }
    void CInput::AUpdate()
    {
        for(std::uint16_t LKey{0} ; LKey < 512 ; LKey++)
        {
            FIsKeyPressed[LKey] = false;
            FIsKeyReleased[LKey] = false;
        }
        for(std::uint8_t LButton{0} ; LButton <= 4 ; LButton++)
        {
            FIsButtonPressed[LButton] = false;
            FIsButtonReleased[LButton] = false;
        }
        FRelativeX = 0;
        FIsXModified = false;
        FRelativeY = 0;
        FIsYModified = false;
        FWheelState = 0;
        FIsWheelModified = false;
        FIsWheelDown = false;
        FIsWheelUp = false;
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent))
        {
            switch(LEvent.type)
            {
                case(SDL_KEYDOWN):
                    FIsKeyHeld[LEvent.key.keysym.scancode] = true;
                    if(!LEvent.key.repeat)
                    {
                        FIsKeyPressed[LEvent.key.keysym.scancode] = true;
                    }
                break;
                case(SDL_KEYUP):
                    FIsKeyHeld[LEvent.key.keysym.scancode] = false;
                    if(!LEvent.key.repeat)
                    {
                        FIsKeyReleased[LEvent.key.keysym.scancode] = true;
                    }
                break;
                case(SDL_MOUSEBUTTONDOWN):
                    FIsButtonHeld[LEvent.button.button - 1] = true;
                    FIsButtonPressed[LEvent.button.button - 1] = true;
                    FIsButtonReleased[LEvent.button.button - 1] = false;
                    FPressedX[LEvent.button.button - 1] = LEvent.button.x;
                    FPressedY[LEvent.button.button - 1] = LEvent.button.y;
                break;
                case(SDL_MOUSEBUTTONUP):
                    FIsButtonHeld[LEvent.button.button - 1] = false;
                    FIsButtonPressed[LEvent.button.button - 1] = false;
                    FIsButtonReleased[LEvent.button.button - 1] = true;
                    FReleasedX[LEvent.button.button - 1] = LEvent.button.x;
                    FReleasedY[LEvent.button.button - 1] = LEvent.button.y;
                break;
                case(SDL_MOUSEMOTION):
                    FAbsoluteX = LEvent.motion.x;
                    FRelativeX = LEvent.motion.xrel;
                    FIsXModified = FRelativeX;
                    FAbsoluteY = LEvent.motion.y;
                    FRelativeY = LEvent.motion.yrel;
                    FIsYModified = FRelativeY;
                break;
                case(SDL_MOUSEWHEEL):
                    switch(LEvent.wheel.y)
                    {
                        case(-1):
                            FWheelState = LEvent.wheel.y;
                            FIsWheelModified = true;
                            FIsWheelDown = true;
                            FIsWheelUp = false;
                        break;
                        case(0):
                            FWheelState = LEvent.wheel.y;
                            FIsWheelModified = false;
                            FIsWheelDown = false;
                            FIsWheelUp = false;
                        break;
                        case(+1):
                            FWheelState = LEvent.wheel.y;
                            FIsWheelModified = true;
                            FIsWheelDown = false;
                            FIsWheelUp = true;
                        break;
                    }
                break;
            }
        }
    }
    bool CInput::AIsKeyHeld(std::uint16_t PKey)
    {
        return(FIsKeyHeld[PKey]);
    }
    bool CInput::AIsKeyPressed(std::uint16_t PKey)
    {
        return(FIsKeyPressed[PKey]);
    }
    bool CInput::AIsKeyReleased(std::uint16_t PKey)
    {
        return(FIsKeyReleased[PKey]);
    }
    bool CInput::AIsButtonHeld(std::uint8_t PButton)
    {
        return(FIsButtonHeld[PButton - 1]);
    }
    bool CInput::AIsButtonPressed(std::uint8_t PButton)
    {
        return(FIsButtonPressed[PButton - 1]);
    }
    bool CInput::AIsButtonReleased(std::uint8_t PButton)
    {
        return(FIsButtonHeld[PButton - 1]);
    }
    std::int32_t CInput::AAbsoluteX()
    {
        return(FAbsoluteX);
    }
    std::int32_t CInput::ARelativeX()
    {
        return(FRelativeX);
    }
    bool CInput::AIsXModified()
    {
        return(FIsXModified);
    }
    std::int32_t CInput::AAbsoluteY()
    {
        return(FAbsoluteY);
    }
    std::int32_t CInput::ARelativeY()
    {
        return(FRelativeY);
    }
    bool CInput::AIsYModified()
    {
        return(FIsYModified);
    }
    std::int32_t CInput::APressedX(std::uint8_t PButton)
    {
        return(FPressedX[PButton - 1]);
    }
    std::int32_t CInput::APressedY(std::uint8_t PButton)
    {
        return(FPressedY[PButton - 1]);
    }
    std::int32_t CInput::AReleasedX(std::uint8_t PButton)
    {
        return(FReleasedX[PButton - 1]);
    }
    std::int32_t CInput::AReleasedY(std::uint8_t PButton)
    {
        return(FReleasedY[PButton - 1]);
    }
    std::int32_t CInput::AWheelState()
    {
        return(FWheelState);
    }
    bool CInput::AIsWheelModified()
    {
        return(FIsWheelModified);
    }
    bool CInput::AIsWheelDown()
    {
        return(FIsWheelDown);
    }
    bool CInput::AIsWheelUp()
    {
        return(FIsWheelUp);
    }
}
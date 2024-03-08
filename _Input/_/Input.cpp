#include"Input.hpp"

namespace NBlindness
{
    void CInput::BUpdate()
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

    bool CInput::OIsKeyHeld(std::uint16_t PKey)
    {
        return(FIsKeyHeld[PKey]);
    }
    bool CInput::OIsKeyPressed(std::uint16_t PKey)
    {
        return(FIsKeyPressed[PKey]);
    }
    bool CInput::OIsKeyReleased(std::uint16_t PKey)
    {
        return(FIsKeyReleased[PKey]);
    }
    bool CInput::OIsButtonHeld(std::uint8_t PButton)
    {
        return(FIsButtonHeld[PButton - 1]);
    }
    bool CInput::OIsButtonPressed(std::uint8_t PButton)
    {
        return(FIsButtonPressed[PButton - 1]);
    }
    bool CInput::OIsButtonReleased(std::uint8_t PButton)
    {
        return(FIsButtonHeld[PButton - 1]);
    }
    std::int32_t CInput::OAbsoluteX()
    {
        return(FAbsoluteX);
    }
    std::int32_t CInput::ORelativeX()
    {
        return(FRelativeX);
    }
    bool CInput::OIsXModified()
    {
        return(FIsXModified);
    }
    std::int32_t CInput::OAbsoluteY()
    {
        return(FAbsoluteY);
    }
    std::int32_t CInput::ORelativeY()
    {
        return(FRelativeY);
    }
    bool CInput::OIsYModified()
    {
        return(FIsYModified);
    }
    std::int32_t CInput::OPressedX(std::uint8_t PButton)
    {
        return(FPressedX[PButton - 1]);
    }
    std::int32_t CInput::OPressedY(std::uint8_t PButton)
    {
        return(FPressedY[PButton - 1]);
    }
    std::int32_t CInput::OReleasedX(std::uint8_t PButton)
    {
        return(FReleasedX[PButton - 1]);
    }
    std::int32_t CInput::OReleasedY(std::uint8_t PButton)
    {
        return(FReleasedY[PButton - 1]);
    }
    std::int32_t CInput::OWheelState()
    {
        return(FWheelState);
    }
    bool CInput::OIsWheelModified()
    {
        return(FIsWheelModified);
    }
    bool CInput::OIsWheelDown()
    {
        return(FIsWheelDown);
    }
    bool CInput::OIsWheelUp()
    {
        return(FIsWheelUp);
    }
}
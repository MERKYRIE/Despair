#include"Mouse.hpp"

#include"Mouse\\Button.hpp"
#include"Mouse\\Cursor.hpp"
#include"Mouse\\Wheel.hpp"

namespace NBlindness::NInput{
    void CMouse::FInitialize(){
        NMouse::GCursor.FInitialize();
    }

    void CMouse::FPreupdate(){
        NMouse::GButton.FPreupdate();
        NMouse::GCursor.FPreupdate();
        NMouse::GWheel.FPreupdate();
    }

    void CMouse::FPostupdate(const SDL_Event& PEvent){
        switch(PEvent.type){
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
}
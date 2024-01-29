#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CMouse{
        private : friend class CInput;

        private : bool VHeld[5];
        private : bool VPressed[5];
        private : bool VReleased[5];
        private : std::int32_t VAbsoluteX;
        private : std::int32_t VRelativeX;
        private : bool VXModified;
        private : std::int32_t VAbsoluteY;
        private : std::int32_t VRelativeY;
        private : bool VYModified;
        private : std::int32_t VPressedX[5];
        private : std::int32_t VPressedY[5];
        private : std::int32_t VReleasedX[5];
        private : std::int32_t VReleasedY[5];
        private : std::int32_t VWheel;
        private : bool VWheelModified;
        private : bool VWheelDown;
        private : bool VWheelUp;

        private : void FPreupdate();
        private : void FPostupdate(const SDL_Event& PEvent);

        public : bool FHeld(std::uint8_t PButton);
        public : bool FPressed(std::uint8_t PButton);
        public : bool FReleased(std::uint8_t PButton);
        public : std::int32_t FAbsoluteX();
        public : std::int32_t FRelativeX();
        public : bool FXModified();
        public : std::int32_t FAbsoluteY();
        public : std::int32_t FRelativeY();
        public : bool FYModified();
        public : std::int32_t FPressedX(std::uint8_t PButton);
        public : std::int32_t FPressedY(std::uint8_t PButton);
        public : std::int32_t FReleasedX(std::uint8_t PButton);
        public : std::int32_t FReleasedY(std::uint8_t PButton);
        public : std::int32_t FWheel();
        public : bool FWheelModified();
        public : bool FWheelDown();
        public : bool FWheelUp();
    }
    GMouse;
}
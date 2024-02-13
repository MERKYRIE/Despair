#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CInput{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : bool VKeyHeld[512];
        private : bool VKeyPressed[512];
        private : bool VKeyReleased[512];
        private : bool VButtonHeld[5];
        private : bool VButtonPressed[5];
        private : bool VButtonReleased[5];
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
        private : std::int32_t VWheelState;
        private : bool VWheelModified;
        private : bool VWheelDown;
        private : bool VWheelUp;
        
        private : void FUpdate();

        public : bool FKeyHeld(std::uint16_t PKey);
        public : bool FKeyPressed(std::uint16_t PKey);
        public : bool FKeyReleased(std::uint16_t PKey);
        public : bool FButtonHeld(std::uint8_t PButton);
        public : bool FButtonPressed(std::uint8_t PButton);
        public : bool FButtonReleased(std::uint8_t PButton);
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
        public : std::int32_t FWheelState();
        public : bool FWheelModified();
        public : bool FWheelDown();
        public : bool FWheelUp();
    }
    GInput;
}
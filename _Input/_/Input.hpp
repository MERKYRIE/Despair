#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CInput
    {
        private : bool FIsKeyHeld[512];
        private : bool FIsKeyPressed[512];
        private : bool FIsKeyReleased[512];
        private : bool FIsButtonHeld[5];
        private : bool FIsButtonPressed[5];
        private : bool FIsButtonReleased[5];
        private : std::int32_t FAbsoluteX;
        private : std::int32_t FRelativeX;
        private : bool FIsXModified;
        private : std::int32_t FAbsoluteY;
        private : std::int32_t FRelativeY;
        private : bool FIsYModified;
        private : std::int32_t FPressedX[5];
        private : std::int32_t FPressedY[5];
        private : std::int32_t FReleasedX[5];
        private : std::int32_t FReleasedY[5];
        private : std::int32_t FWheelState;
        private : bool FIsWheelModified;
        private : bool FIsWheelDown;
        private : bool FIsWheelUp;
        
        public : CInput();
        public : void AUpdate();
        public : bool AIsKeyHeld(std::uint16_t PKey);
        public : bool AIsKeyPressed(std::uint16_t PKey);
        public : bool AIsKeyReleased(std::uint16_t PKey);
        public : bool AIsButtonHeld(std::uint8_t PButton);
        public : bool AIsButtonPressed(std::uint8_t PButton);
        public : bool AIsButtonReleased(std::uint8_t PButton);
        public : std::int32_t AAbsoluteX();
        public : std::int32_t ARelativeX();
        public : bool AIsXModified();
        public : std::int32_t AAbsoluteY();
        public : std::int32_t ARelativeY();
        public : bool AIsYModified();
        public : std::int32_t APressedX(std::uint8_t PButton);
        public : std::int32_t APressedY(std::uint8_t PButton);
        public : std::int32_t AReleasedX(std::uint8_t PButton);
        public : std::int32_t AReleasedY(std::uint8_t PButton);
        public : std::int32_t AWheelState();
        public : bool AIsWheelModified();
        public : bool AIsWheelDown();
        public : bool AIsWheelUp();
    }
    *GInput;
}
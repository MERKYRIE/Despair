#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    inline class CInput
    {
        friend std::int32_t (::main(std::int32_t , char**));

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
        
        private : void BUpdate();

        public : bool OIsKeyHeld(std::uint16_t PKey);
        public : bool OIsKeyPressed(std::uint16_t PKey);
        public : bool OIsKeyReleased(std::uint16_t PKey);
        public : bool OIsButtonHeld(std::uint8_t PButton);
        public : bool OIsButtonPressed(std::uint8_t PButton);
        public : bool OIsButtonReleased(std::uint8_t PButton);
        public : std::int32_t OAbsoluteX();
        public : std::int32_t ORelativeX();
        public : bool OIsXModified();
        public : std::int32_t OAbsoluteY();
        public : std::int32_t ORelativeY();
        public : bool OIsYModified();
        public : std::int32_t OPressedX(std::uint8_t PButton);
        public : std::int32_t OPressedY(std::uint8_t PButton);
        public : std::int32_t OReleasedX(std::uint8_t PButton);
        public : std::int32_t OReleasedY(std::uint8_t PButton);
        public : std::int32_t OWheelState();
        public : bool OIsWheelModified();
        public : bool OIsWheelDown();
        public : bool OIsWheelUp();
    }
    GInput;
}
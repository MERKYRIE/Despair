#pragma once

#include"Blindness.hpp"

namespace NBlindness::NInput{
    inline class CMouse{
        private : friend class CInput;

        private : std::int32_t VPressedX[5];
        private : std::int32_t VPressedY[5];
        private : std::int32_t VReleasedX[5];
        private : std::int32_t VReleasedY[5];

        private : void FInitialize();
        private : void FPreupdate();
        private : void FPostupdate(const SDL_Event& PEvent);

        public : std::int32_t FPressedX(std::uint8_t PButton);
        public : std::int32_t FPressedY(std::uint8_t PButton);
        public : std::int32_t FReleasedX(std::uint8_t PButton);
        public : std::int32_t FReleasedY(std::uint8_t PButton);
    }
    GMouse;
}
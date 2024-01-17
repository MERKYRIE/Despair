#pragma once

#include"Blindness.hpp"

namespace NBlindness::NInput::NMouse{
    inline class CButton{
        private : friend class CMouse;

        private : bool VHeld[5];
        private : bool VPressed[5];
        private : bool VReleased[5];

        private : void FPreupdate();
        private : void FUpdate(const SDL_Event& PEvent);

        public : bool FHeld(std::uint8_t PButton);
        public : bool FPressed(std::uint8_t PButton);
        public : bool FReleased(std::uint8_t PButton);
    }
    GButton;
}
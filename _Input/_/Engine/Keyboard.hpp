#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CKeyboard{
        private : friend class CInput;

        private : bool VHeld[512];
        private : bool VPressed[512];
        private : bool VReleased[512];

        private : void FPreupdate();
        private : void FPostupdate(const SDL_Event& PEvent);

        public : bool FHeld(std::uint16_t PKey);
        public : bool FPressed(std::uint16_t PKey);
        public : bool FReleased(std::uint16_t PKey);
    }
    GKeyboard;
}
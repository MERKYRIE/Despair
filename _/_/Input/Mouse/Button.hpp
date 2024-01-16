#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput::NMouse
{
    inline class CButton
    {
        private:
            friend class CMouse;
        private:    
            bool VHeld[5];
            bool VPressed[5];
            bool VReleased[5];
        private:
            void FUpdate(const SDL_Event& PEvent);
        public:
            bool FHeld(unsigned char PButton);
            bool FPressed(unsigned char PButton);
            bool FReleased(unsigned char PButton);
    }
    GButton;
}
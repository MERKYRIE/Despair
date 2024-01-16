#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput
{
    inline class CKeyboard
    {
        private:
            friend class CInput;
        private:    
            unsigned char VHeld[512];
            unsigned char VPressed[512];
            unsigned char VReleased[512];
        private:    
            void FPreupdate();
            void FPostupdate(const SDL_Event& PEvent);
        public:
            bool FHeld(unsigned short PKey);
            bool FPressed(unsigned short PKey);
            bool FReleased(unsigned short PKey);
    }
    GKeyboard;
}
#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput
{
    inline class CMouse
    {
        private:
            friend class CInput;
        private:    
            signed int VPressedX[5];
            signed int VPressedY[5];
            signed int VReleasedX[5];
            signed int VReleasedY[5];
        private:
            void FInitialize();
            void FPreupdate();
            void FPostupdate(const SDL_Event& PEvent);
        public:
            signed int FPressedX(unsigned char PButton);
            signed int FPressedY(unsigned char PButton);
            signed int FReleasedX(unsigned char PButton);
            signed int FReleasedY(unsigned char PButton);
    }
    GMouse;
}
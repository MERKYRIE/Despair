#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput::NMouse
{
    inline class CWheel
    {
        private:
            friend class CMouse;
        private:    
            signed int VState;
            bool VChanged;
            bool VDown;
            bool VUp;
        private:    
            void FUpdate(const SDL_Event& PEvent);
        public:
            signed int FState();
            bool FChanged();
            bool FDown();
            bool FUp();
    }
    GWheel;
}
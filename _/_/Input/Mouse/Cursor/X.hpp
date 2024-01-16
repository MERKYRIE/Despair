#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput::NMouse::NCursor
{
    inline class CX
    {
        private:
            friend class CCursor;
        private:    
            signed int VAbsolute;
            signed int VRelative;
            bool VChanged;
        private:
            void FPreupdate();
            void FPostupdate(const SDL_Event& PEvent);
        public:
            signed int FAbsolute();
            signed int FRelative();
            bool FChanged();
    }
    GX;
}
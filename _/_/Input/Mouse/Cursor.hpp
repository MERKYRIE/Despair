#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NInput::NMouse
{
    inline class CCursor
    {
        private:
            friend class CMouse;
        private:
            void FInitialize();
            void FPreupdate();
            void FPostupdate(const SDL_Event& PEvent);
    }
    GCursor;
}
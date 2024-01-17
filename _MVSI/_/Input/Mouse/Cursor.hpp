#pragma once

#include"Blindness.hpp"

namespace NBlindness::NInput::NMouse{
    inline class CCursor{
        private : friend class CMouse;

        private : void FInitialize();
        private : void FPreupdate();
        private : void FPostupdate(const SDL_Event& PEvent);
    }
    GCursor;
}
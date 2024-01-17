#pragma once

#include"Blindness.hpp"

namespace NBlindness::NInput::NMouse::NCursor{
    inline class CX{
        private : friend class CCursor;

        private : std::int32_t VAbsolute;
        private : std::int32_t VRelative;
        private : bool VChanged;

        private : void FPreupdate();
        private : void FPostupdate(const SDL_Event& PEvent);

        public : std::int32_t FAbsolute();
        public : std::int32_t FRelative();
        public : bool FChanged();
    }
    GX;
}
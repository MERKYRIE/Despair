#pragma once

#include"Blindness.hpp"

namespace NBlindness::NInput::NMouse{
    inline class CWheel{
        private : friend class CMouse;

        private : std::int32_t VState;
        private : bool VChanged;
        private : bool VDown;
        private : bool VUp;

        private : void FPreupdate();
        private : void FUpdate(const SDL_Event& PEvent);

        public : std::int32_t FState();
        public : bool FChanged();
        public : bool FDown();
        public : bool FUp();
    }
    GWheel;
}
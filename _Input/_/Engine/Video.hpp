#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CVideo{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : SDL_Window* VWindow;
        private : SDL_GLContext VContext;
        private : float VRatio;
        private : float VInversedRatio;

        private : void FInitialize();
        private : void FPreupdate();
        private : void FPostupdate();
        private : void FDeinitialize();

        public : float FRatio();
        public : float FInversedRatio();
    }
    GVideo;
}
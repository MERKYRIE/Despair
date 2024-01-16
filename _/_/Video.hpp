#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL
{
    inline class CVideo
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            SDL_Window* VWindow;
            SDL_GLContext VContext;
            float VRatio;
            float VInversedRatio;
        private:
            void FInitialize();
            void FPreupdate();
            void FPostupdate();
            void FDeinitialize();
        public:    
            float FRatio();
            float FInversedRatio();
    }
    GVideo;
}
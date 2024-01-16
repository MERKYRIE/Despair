#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL
{
    inline class CDebug
    {
        public:
            void FAssert
            (
                bool PCondition = true ,
                const std::string& PMessage = "" ,
                SDL_MessageBoxFlags PFlags = SDL_MESSAGEBOX_ERROR ,
                const std::source_location& PLocation = std::source_location::current()
            );
    }
    GDebug;
}
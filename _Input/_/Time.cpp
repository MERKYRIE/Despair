#include"Time.hpp"

namespace NBlindness{
    void CTime::FUpdate(){
        VLast = VAbsolute;
        VAbsolute = SDL_GetTicks();
        VRelative = VAbsolute - VLast;
    }

    std::uint32_t CTime::FAbsolute(){
        return VAbsolute;
    }

    std::uint32_t CTime::FRelative(){
        return VRelative;
    }
}
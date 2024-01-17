#include"Y.hpp"

namespace NBlindness::NInput::NMouse::NCursor{
    void CY::FPreupdate(){
        VRelative = 0;
        VChanged = false;
    }
    
    void CY::FPostupdate(const SDL_Event& PEvent){
        VAbsolute = PEvent.motion.y;
        VRelative = PEvent.motion.yrel;
        VChanged = VRelative;
    }

    std::int32_t CY::FAbsolute(){
        return VAbsolute;
    }

    std::int32_t CY::FRelative(){
        return VRelative;
    }

    bool CY::FChanged(){
        return VChanged;
    }
}
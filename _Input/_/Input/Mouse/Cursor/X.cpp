#include"X.hpp"

namespace NBlindness::NInput::NMouse::NCursor{
    void CX::FPreupdate(){
        VRelative = 0;
        VChanged = false;
    }
    
    void CX::FPostupdate(const SDL_Event& PEvent){
        VAbsolute = PEvent.motion.x;
        VRelative = PEvent.motion.xrel;
        VChanged = VRelative;
    }

    std::int32_t CX::FAbsolute(){
        return VAbsolute;
    }

    std::int32_t CX::FRelative(){
        return VRelative;
    }

    bool CX::FChanged(){
        return VChanged;
    }
}
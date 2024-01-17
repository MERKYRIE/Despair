#include"Wheel.hpp"

namespace NBlindness::NInput::NMouse{
    void CWheel::FPreupdate(){
        VState = 0;
        VChanged = false;
        VDown = false;
        VUp = false;
    }
    
    void CWheel::FUpdate(const SDL_Event& PEvent){
        switch(PEvent.wheel.y){
            case -1:
                VState = PEvent.wheel.y;
                VChanged = true;
                VDown = true;
                VUp = false;
            break;
            case 0:
                VState = PEvent.wheel.y;
                VChanged = false;
                VDown = false;
                VUp = false;
            break;
            case +1:
                VState = PEvent.wheel.y;
                VChanged = true;
                VDown = false;
                VUp = true;
            break;
        }
    }

    std::int32_t CWheel::FState(){
        return VState;
    }

    bool CWheel::FChanged(){
        return VChanged;
    }

    bool CWheel::FDown(){
        return VDown;
    }

    bool CWheel::FUp(){
        return VUp;
    }
}
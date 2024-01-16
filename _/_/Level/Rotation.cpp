#include "Rotation.hpp"

#include "Input\\Keyboard.hpp"

namespace NMRKOGL::NLevel{
    void CRotation::FInitialize(){
        VAngle = 0.0F;
    }

    void CRotation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_Q)){
            FLeft();
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_E)){
            FRight();
        }
        glRotatef(-VAngle , 0.0F , 1.0F , 0.0F);
    }

    signed char CRotation::FX(){
        return -static_cast<signed char>(std::sin(VAngle * std::numbers::pi_v<float> / 180.0F));
    }

    signed char CRotation::FZ(){
        return -static_cast<signed char>(std::cos(VAngle * std::numbers::pi_v<float> / 180.0F));
    }

    void CRotation::FLeft(){
        VAngle += 90.0F;
        if(VAngle > 360.0F){
            VAngle -= 360.0F;
        }
    }

    void CRotation::FRight(){
        VAngle -= 90.0F;
        if(VAngle < 0.0F){
            VAngle += 360.0F;
        }
    }
}
#include"Rotation.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CRotation::FInitialize(){
        VAngle = 0.0F;
    }

    void CRotation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_Q)){
            VAngle += 90.0F;
            if(VAngle > 360.0F){
                VAngle -= 360.0F;
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_E)){
            VAngle -= 90.0F;
            if(VAngle < 0.0F){
                VAngle += 360.0F;
            }
        }
        glRotatef(-90.0F , 1.0F , 0.0F , 0.0F);
        glRotatef(-VAngle , 0.0F , 0.0F , 1.0F);
    }

    float CRotation::FLeftX(){
        return -std::cos(VAngle * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FLeftY(){
        return -std::sin(VAngle * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FRightX(){
        return std::cos(VAngle * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FRightY(){
        return std::sin(VAngle * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FBackwardX(){
        return -std::cos((90.0F + VAngle) * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FBackwardY(){
        return -std::sin((90.0F + VAngle) * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FForwardX(){
        return +std::cos((90.0F + VAngle) * std::numbers::pi_v<float> / 180.0F);
    }

    float CRotation::FForwardY(){
        return +std::sin((90.0F + VAngle) * std::numbers::pi_v<float> / 180.0F);
    }
}
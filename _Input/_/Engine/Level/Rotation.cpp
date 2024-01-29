#include"Rotation.hpp"

#include"Engine\\Keyboard.hpp"

namespace NBlindness::NEngine::NLevel{
    void CRotation::FInitialize(){
        VValue = 360.0;
    }

    void CRotation::FUpdate(){
        if(GKeyboard.FPressed(SDL_SCANCODE_A)){
            VValue += 90.0;
            if(VValue > 360.0){
                VValue -= 360.0;
            }
        }
        if(GKeyboard.FPressed(SDL_SCANCODE_D)){
            VValue -= 90.0;
            if(VValue <= 0.0){
                VValue += 360.0;
            }
        }
        glRotated(-90.0 , 1.0 , 0.0 , 0.0);
        glRotated(-VValue , 0.0 , 0.0 , 1.0);
    }

    std::int8_t CRotation::FBackwardX(){
        return static_cast<std::int8_t>(std::round(-std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FBackwardY(){
        return static_cast<std::int8_t>(std::round(-std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FForwardX(){
        return static_cast<std::int8_t>(std::round(+std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FForwardY(){
        return static_cast<std::int8_t>(std::round(+std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }
}
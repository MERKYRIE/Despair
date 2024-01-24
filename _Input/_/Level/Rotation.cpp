#include"Rotation.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CRotation::FInitialize(){
        VValue = 360.0;
    }

    void CRotation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            VValue += 90.0;
            if(VValue > 360.0){
                VValue -= 360.0;
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            VValue -= 90.0;
            if(VValue <= 0.0){
                VValue += 360.0;
            }
        }
        glRotated(-90.0 , 1.0 , 0.0 , 0.0);
        glRotated(-VValue , 0.0 , 0.0 , 1.0);
    }

    double CRotation::FRealBackwardX(){
        return -std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0);
    }

    double CRotation::FRealBackwardY(){
        return -std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0);
    }

    double CRotation::FRealForwardX(){
        return +std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0);
    }

    double CRotation::FRealForwardY(){
        return +std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0);
    }

    std::int8_t CRotation::FIntegerBackwardX(){
        return static_cast<std::int8_t>(std::round(-std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FIntegerBackwardY(){
        return static_cast<std::int8_t>(std::round(-std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FIntegerForwardX(){
        return static_cast<std::int8_t>(std::round(+std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }

    std::int8_t CRotation::FIntegerForwardY(){
        return static_cast<std::int8_t>(std::round(+std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0)));
    }
}
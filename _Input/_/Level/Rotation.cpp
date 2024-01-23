#include"Rotation.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CRotation::FInitialize(){
        VValue = 0.0;
    }

    void CRotation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            VValue += 90.0;
            if(VValue >= 360.0){
                VValue -= 360.0;
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            VValue -= 90.0;
            if(VValue < 0.0){
                VValue += 360.0;
            }
        }
        glRotated(-90.0 , 1.0 , 0.0 , 0.0);
        glRotated(-VValue , 0.0 , 0.0 , 1.0);
    }

    template<typename TReal> TReal CRotation::FBackwardX(){
        return static_cast<TReal>(-std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0));
    }

    template<typename TInteger> TInteger CRotation::FBackwardX() requires std::signed_integral<TInteger>{
        return static_cast<TInteger>(std::round(FBackwardX<double>()));
    }

    template<typename TReal> TReal CRotation::FBackwardY(){
        return static_cast<TReal>(-std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0));
    }

    template<typename TInteger> TInteger CRotation::FBackwardY() requires std::signed_integral<TInteger>{
        return static_cast<TInteger>(std::round(FBackwardY<double>()));
    }
   
    template<typename TReal> TReal CRotation::FForwardX(){
        return static_cast<TReal>(+std::cos((90.0 + VValue) * std::numbers::pi_v<double> / 180.0));
    }

    template<typename TInteger> TInteger CRotation::FForwardX() requires std::signed_integral<TInteger>{
        return static_cast<TInteger>(std::round(FForwardX<double>()));
    }

    template<typename TReal> TReal CRotation::FForwardY(){
        return static_cast<TReal>(+std::sin((90.0 + VValue) * std::numbers::pi_v<double> / 180.0));
    }

    template<typename TInteger> TInteger CRotation::FForwardY() requires std::signed_integral<TInteger>{
        return static_cast<TInteger>(std::round(FForwardY<double>()));
    }
}
#include"X.hpp"

#include"Y.hpp"
#include"Z.hpp"

#include"Input\\Keyboard.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Space\\Partition.hpp"

namespace NBlindness::NLevel::NTranslation{
    void CX::FInitialize(){
        VValue = 0.5;
    }

    void CX::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GSpace.FPartition(FValue<std::uintmax_t>() , NTranslation::GY.FValue<std::uintmax_t>() , NTranslation::GZ.FValue<std::uintmax_t>()).FCollision(
                FValue<std::uintmax_t>() + GRotation.FBackwardX<std::int8_t>() ,
                NTranslation::GY.FValue<std::uintmax_t>() + GRotation.FBackwardY<std::int8_t>() ,
                NTranslation::GZ.FValue<std::uintmax_t>()
            )){
                VValue += GRotation.FBackwardX<double>();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GSpace.FPartition(FValue<std::uintmax_t>() , NTranslation::GY.FValue<std::uintmax_t>() , NTranslation::GZ.FValue<std::uintmax_t>()).FCollision(
                FValue<std::uintmax_t>() + GRotation.FForwardX<std::int8_t>() ,
                NTranslation::GY.FValue<std::uintmax_t>() + GRotation.FForwardY<std::int8_t>() ,
                NTranslation::GZ.FValue<std::uintmax_t>()
            )){
                VValue += GRotation.FForwardX<double>();
            }
        }
        glTranslated(-VValue , 0.0 , 0.0);
    }
}
#include"Y.hpp"

#include"X.hpp"
#include"Z.hpp"

#include"Input\\Keyboard.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Space\\Partition.hpp"

namespace NBlindness::NLevel::NTranslation{
    void CY::FInitialize(){
        VValue = 0.5;
    }

    void CY::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GSpace.FPartition(NTranslation::GX.FValue<std::uintmax_t>() , FValue<std::uintmax_t>() , NTranslation::GZ.FValue<std::uintmax_t>()).FCollision(
                NTranslation::GX.FValue<std::uintmax_t>() + GRotation.FBackwardX<std::int8_t>() ,
                FValue<std::uintmax_t>() + GRotation.FBackwardY<std::int8_t>() ,
                NTranslation::GZ.FValue<std::uintmax_t>()
            )){
                VValue += GRotation.FBackwardY<double>();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GSpace.FPartition(NTranslation::GX.FValue<std::uintmax_t>() , FValue<std::uintmax_t>() , NTranslation::GZ.FValue<std::uintmax_t>()).FCollision(
                NTranslation::GX.FValue<std::uintmax_t>() + GRotation.FForwardX<std::int8_t>() ,
                FValue<std::uintmax_t>() + GRotation.FForwardY<std::int8_t>() ,
                NTranslation::GZ.FValue<std::uintmax_t>()
            )){
                VValue += GRotation.FForwardY<double>();
            }
        }
        glTranslated(0.0 , -VValue , 0.0);
    }
}
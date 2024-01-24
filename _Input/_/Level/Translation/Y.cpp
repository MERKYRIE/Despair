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
            if(
                GSpace.FPartition(NTranslation::GX.FInteger() , FInteger() , NTranslation::GZ.FInteger())
                .FCollision(NTranslation::GX.FInteger() + GRotation.FIntegerBackwardX() , FInteger() + GRotation.FIntegerBackwardY() , NTranslation::GZ.FInteger())
            ){
                VValue += GRotation.FRealBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(
                GSpace.FPartition(NTranslation::GX.FInteger() , FInteger() , NTranslation::GZ.FInteger())
                .FCollision(NTranslation::GX.FInteger() + GRotation.FIntegerForwardX() , FInteger() + GRotation.FIntegerForwardY() , NTranslation::GZ.FInteger())
            ){
                VValue += GRotation.FRealForwardY();
            }
        }
        glTranslated(0.0 , -VValue , 0.0);
    }

    std::uintmax_t CY::FInteger(){
        return static_cast<std::uintmax_t>(std::round(VValue - 0.5));
    }
}
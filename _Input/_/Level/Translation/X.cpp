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
            if(
                GSpace.FPartition(FInteger() , NTranslation::GY.FInteger() , NTranslation::GZ.FInteger())
                .FCollision(FInteger() + GRotation.FIntegerBackwardX() , NTranslation::GY.FInteger() + GRotation.FIntegerBackwardY() , NTranslation::GZ.FInteger())
            ){
                VValue += GRotation.FRealBackwardX();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(
                GSpace.FPartition(FInteger() , NTranslation::GY.FInteger() , NTranslation::GZ.FInteger())
                .FCollision(FInteger() + GRotation.FIntegerForwardX() , NTranslation::GY.FInteger() + GRotation.FIntegerForwardY() , NTranslation::GZ.FInteger())
            ){
                VValue += GRotation.FRealForwardX();
            }
        }
        glTranslated(-VValue , 0.0 , 0.0);
    }

    std::uintmax_t CX::FInteger(){
        return static_cast<std::uintmax_t>(std::round(VValue - 0.5));
    }
}
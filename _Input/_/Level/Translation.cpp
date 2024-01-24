#include"Translation.hpp"

#include"Input\\Keyboard.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Space\\Partition.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        VX = 0.5;
        VY = 0.5;
        VZ = 0.5;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(
                GSpace.FPartition(FX() , FY() , FZ())
                .FCollision(FX() + GRotation.FBackwardX() , FY() + GRotation.FBackwardY() , FZ())
            ){
                VX += GRotation.FBackwardX();
                VY += GRotation.FBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(
                GSpace.FPartition(FX() , FY() , FZ())
                .FCollision(FX() + GRotation.FForwardX() , FY() + GRotation.FForwardY() , FZ())
            ){
                VX += GRotation.FForwardX();
                VY += GRotation.FForwardY();
            }
        }
        glTranslated(-VX , -VY , -VZ);
    }

    std::uintmax_t CTranslation::FX(){
        return static_cast<std::uintmax_t>(std::round(VX - 0.5));
    }

    std::uintmax_t CTranslation::FY(){
        return static_cast<std::uintmax_t>(std::round(VY - 0.5));
    }

    std::uintmax_t CTranslation::FZ(){
        return static_cast<std::uintmax_t>(std::round(VZ - 0.5));
    }
}
#include"Translation.hpp"

#include"Rotation.hpp"
#include"Space.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        VX = 0.5;
        VY = 0.5;
        VZ = 0.5;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            if(GSpace.FCollision(FX() + GRotation.FIntegerLeftwardX() , FY() + GRotation.FIntegerLeftwardY() , FZ())){
                VX += GRotation.FRealLeftwardX();
                VY += GRotation.FRealLeftwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            if(GSpace.FCollision(FX() + GRotation.FIntegerRightwardX() , FY() + GRotation.FIntegerRightwardY() , FZ())){
                VX += GRotation.FRealRightwardX();
                VY += GRotation.FRealRightwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GSpace.FCollision(FX() + GRotation.FIntegerBackwardX() , FY() + GRotation.FIntegerBackwardY() , FZ())){
                VX += GRotation.FRealBackwardX();
                VY += GRotation.FRealBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GSpace.FCollision(FX() + GRotation.FIntegerForwardX() , FY() + GRotation.FIntegerForwardY() , FZ())){
                VX += GRotation.FRealForwardX();
                VY += GRotation.FRealForwardY();
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
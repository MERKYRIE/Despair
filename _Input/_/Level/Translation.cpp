#include"Translation.hpp"

#include"Rotation.hpp"

#include"Input\\Keyboard.hpp"
#include"Level.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        VX = 0.5;
        VY = 0.5;
        VZ = 0.5;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            if(GLevel.FCollision(FX() + GRotation.FIntegerLeftwardX() , FY() + GRotation.FIntegerLeftwardY() , FZ())){
                VX += GRotation.FRealLeftwardX();
                VY += GRotation.FRealLeftwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            if(GLevel.FCollision(FX() + GRotation.FIntegerRightwardX() , FY() + GRotation.FIntegerRightwardY() , FZ())){
                VX += GRotation.FRealRightwardX();
                VY += GRotation.FRealRightwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GLevel.FCollision(FX() + GRotation.FIntegerBackwardX() , FY() + GRotation.FIntegerBackwardY() , FZ())){
                VX += GRotation.FRealBackwardX();
                VY += GRotation.FRealBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GLevel.FCollision(FX() + GRotation.FIntegerForwardX() , FY() + GRotation.FIntegerForwardY() , FZ())){
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
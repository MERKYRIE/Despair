#include"Translation.hpp"

#include"Rotation.hpp"
#include"Space.hpp"
#include"Translation\\X.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        NTranslation::GX.FInitialize();
        VY = 0.5;
        VZ = 0.5;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerLeftwardX() , FY() + GRotation.FIntegerLeftwardY() , FZ())){
                NTranslation::GX += GRotation.FRealLeftwardX();
                VY += GRotation.FRealLeftwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerRightwardX() , FY() + GRotation.FIntegerRightwardY() , FZ())){
                NTranslation::GX += GRotation.FRealRightwardX();
                VY += GRotation.FRealRightwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerBackwardX() , FY() + GRotation.FIntegerBackwardY() , FZ())){
                NTranslation::GX += GRotation.FRealBackwardX();
                VY += GRotation.FRealBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerForwardX() , FY() + GRotation.FIntegerForwardY() , FZ())){
                NTranslation::GX += GRotation.FRealForwardX();
                VY += GRotation.FRealForwardY();
            }
        }
        glTranslated(-NTranslation::GX , -VY , -VZ);
    }

    std::uintmax_t CTranslation::FY(){
        return static_cast<std::uintmax_t>(std::round(VY - 0.5));
    }

    std::uintmax_t CTranslation::FZ(){
        return static_cast<std::uintmax_t>(std::round(VZ - 0.5));
    }
}
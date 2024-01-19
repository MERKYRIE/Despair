#include"Translation.hpp"

#include"Rotation.hpp"
#include"Space.hpp"
#include"Translation\\X.hpp"
#include"Translation\\Y.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        NTranslation::GX.FInitialize();
        NTranslation::GY.FInitialize();
        VZ = 0.5;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerLeftwardX() , NTranslation::GY.FValue() + GRotation.FIntegerLeftwardY() , FZ())){
                NTranslation::GX += GRotation.FRealLeftwardX();
                NTranslation::GY += GRotation.FRealLeftwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerRightwardX() , NTranslation::GY.FValue() + GRotation.FIntegerRightwardY() , FZ())){
                NTranslation::GX += GRotation.FRealRightwardX();
                NTranslation::GY += GRotation.FRealRightwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerBackwardX() , NTranslation::GY.FValue() + GRotation.FIntegerBackwardY() , FZ())){
                NTranslation::GX += GRotation.FRealBackwardX();
                NTranslation::GY += GRotation.FRealBackwardY();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            if(GSpace.FCollision(NTranslation::GX.FValue() + GRotation.FIntegerForwardX() , NTranslation::GY.FValue() + GRotation.FIntegerForwardY() , FZ())){
                NTranslation::GX += GRotation.FRealForwardX();
                NTranslation::GY += GRotation.FRealForwardY();
            }
        }
        glTranslated(-NTranslation::GX , -NTranslation::GY , -VZ);
    }

    std::uintmax_t CTranslation::FZ(){
        return static_cast<std::uintmax_t>(std::round(VZ - 0.5));
    }
}
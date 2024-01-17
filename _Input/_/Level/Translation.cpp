#include"Translation.hpp"

#include"Rotation.hpp"

#include"Input\\Keyboard.hpp"
#include"Level.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        VX = 0.5F;
        VY = 0.5F;
        VZ = 0.5F;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_A)){
            VX += GRotation.FLeftX();
            VY += GRotation.FLeftY();
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_D)){
            VX += GRotation.FRightX();
            VY += GRotation.FRightY();
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_S)){
            VX += GRotation.FBackwardX();
            VY += GRotation.FBackwardY();
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_W)){
            VX += GRotation.FForwardX();
            VY += GRotation.FForwardY();
        }
        glTranslatef(-VX , -VY , -VZ);
    }
}
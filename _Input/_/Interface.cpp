#include"Interface.hpp"

#include"Debug\\Assert\\Error.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"
#include"Input\\Keyboard.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Translation.hpp"
#include"Video\\Typeface.hpp"
#include"Video\\Typeface\\Font.hpp"
#include"Video\\Typeface\\Font\\Character.hpp"

namespace NBlindness{
    void CInterface::FUpdate(){
        if(VCommand.length() < 49){
            for(std::uint16_t LKey{SDL_SCANCODE_1} ; LKey <= SDL_SCANCODE_0 ; LKey++){
                if(NInput::GKeyboard.FPressed(LKey)){
                    VCommand += (!NInput::GKeyboard.FPressed(SDL_SCANCODE_0) ? '1' : '0' - 9) + LKey - SDL_SCANCODE_1;
                }
            }
            for(std::uint16_t LKey{SDL_SCANCODE_A} ; LKey <= SDL_SCANCODE_Z ; LKey++){
                if(NInput::GKeyboard.FPressed(LKey)){
                    VCommand += (!NInput::GKeyboard.FHeld(SDL_SCANCODE_LSHIFT) ? 'a' : 'A') + LKey - SDL_SCANCODE_A;
                }
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_BACKSPACE)){
            if(!VCommand.empty()){
                VCommand.pop_back();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_RETURN)){
            /*
            if(VCommand == "TL")
            {
                NLevel::GTranslation.FLeftward();
            }
            else if(VCommand == "TR")
            {
                NLevel::GTranslation.FRightward();
            }
            else if(VCommand == "TB")
            {
                NLevel::GTranslation.FBackward();
            }
            else if(VCommand == "TF")
            {
                NLevel::GTranslation.FForward();
            }
            else if(VCommand == "RL")
            {
                NLevel::GRotation.FLeft();
            }
            else if(VCommand == "RR")
            {
                NLevel::GRotation.FRight();
            }
            */
            VCommand.clear();
        }
        glDisable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0F , 100.0F , 100.0F , 0.0F);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor4ub(30 , 30 , 30 , 255);
        glBindTexture(GL_TEXTURE_2D , 0);
        glBegin(GL_QUADS);
        glVertex2f(0.0F , 96.0F + 0.0F);
        glVertex2f(0.0F , 96.0F + 4.0F);
        glVertex2f(100.0F , 96.0F + 4.0F);
        glVertex2f(100.0F , 96.0F + 0.0F);
        glEnd();
        glColor4ub(255 , 255 , 255 , 255);
        static NVideo::NTypeface::CFont LFont{NVideo::GTypeface.FFont("\\Consolas.ttf")};
        for(std::uintmax_t LCharacter{0} ; LCharacter < VCommand.length() ; LCharacter++){
            if(std::isdigit(VCommand[LCharacter])){
                glBindTexture(GL_TEXTURE_2D , LFont.FDigit(VCommand[LCharacter]).FIdentifier());
            }
            else{
                if(std::isupper(VCommand[LCharacter])){
                    glBindTexture(GL_TEXTURE_2D , LFont.FUppercase(VCommand[LCharacter]).FIdentifier());
                }
                else{
                    glBindTexture(GL_TEXTURE_2D , LFont.FLowercase(VCommand[LCharacter]).FIdentifier());
                }
            }
            glBegin(GL_QUADS);
            glTexCoord2f(0.0F , 0.0F);
            glVertex2f(2.0F * LCharacter + 0.0F , 96.0F + 0.0F);
            glTexCoord2f(0.0F , 1.0F);
            glVertex2f(2.0F * LCharacter + 0.0F , 96.0F + 4.0F);
            glTexCoord2f(1.0F , 1.0F);
            glVertex2f(2.0F * LCharacter + 2.0F , 96.0F + 4.0F);
            glTexCoord2f(1.0F , 0.0F);
            glVertex2f(2.0F * LCharacter + 2.0F , 96.0F + 0.0F);
            glEnd();
        }
    }
}
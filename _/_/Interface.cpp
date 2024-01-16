#include "Interface.hpp"

#include "Debug\\Assert\\Error.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"
#include "Input\\Keyboard.hpp"
#include "Level\\Rotation.hpp"
#include "Level\\Translation.hpp"

namespace NMRKOGL
{
    void CInterface::FInitialize()
    {
        NDebug::NAssert::NError::GSDL.FCode(TTF_Init());
        TTF_Font* LFont{TTF_OpenFont("Fonts\\Consolas.ttf" , 64)};
        NDebug::NAssert::NError::GSDL.FHandle(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++)
        {
            SDL_Surface* LUnsuitable{TTF_RenderText_Blended(LFont , std::string{LDigit}.c_str() , SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}})};
            NDebug::NAssert::NError::GSDL.FHandle(LUnsuitable);
            SDL_Surface* LSuitable{SDL_ConvertSurfaceFormat(LUnsuitable , SDL_PIXELFORMAT_RGBA32 , 0)};
            NDebug::NAssert::NError::GSDL.FHandle(LSuitable);
            glGenTextures(1 , &VDigits[LDigit - '0']);
            glBindTexture(GL_TEXTURE_2D , VDigits[LDigit - '0']);
            glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LSuitable->w , LSuitable->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LSuitable->pixels);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
            NDebug::NAssert::GError.FOGL();
            SDL_FreeSurface(LSuitable);
            SDL_FreeSurface(LUnsuitable);
        }
        for(unsigned char LLetter{0} ; LLetter <= 25 ; LLetter++)
        {
            SDL_Surface* LUnsuitable{TTF_RenderText_Blended(LFont , std::string{static_cast<char>('a' + LLetter)}.c_str() , SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}})};
            NDebug::NAssert::NError::GSDL.FHandle(LUnsuitable);
            SDL_Surface* LSuitable{SDL_ConvertSurfaceFormat(LUnsuitable , SDL_PIXELFORMAT_RGBA32 , 0)};
            NDebug::NAssert::NError::GSDL.FHandle(LSuitable);
            glGenTextures(1 , &VLetters[false][LLetter]);
            glBindTexture(GL_TEXTURE_2D , VLetters[false][LLetter]);
            glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LSuitable->w , LSuitable->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LSuitable->pixels);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
            NDebug::NAssert::GError.FOGL();
            SDL_FreeSurface(LSuitable);
            SDL_FreeSurface(LUnsuitable);
            LUnsuitable = TTF_RenderText_Blended(LFont , std::string{static_cast<char>('A' + LLetter)}.c_str() , SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}});
            NDebug::NAssert::NError::GSDL.FHandle(LUnsuitable);
            LSuitable = SDL_ConvertSurfaceFormat(LUnsuitable , SDL_PIXELFORMAT_RGBA32 , 0);
            NDebug::NAssert::NError::GSDL.FHandle(LSuitable);
            glGenTextures(1 , &VLetters[true][LLetter]);
            glBindTexture(GL_TEXTURE_2D , VLetters[true][LLetter]);
            glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LSuitable->w , LSuitable->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LSuitable->pixels);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
            NDebug::NAssert::GError.FOGL();
            SDL_FreeSurface(LSuitable);
            SDL_FreeSurface(LUnsuitable);
        }
        TTF_CloseFont(LFont);
    }
    
    void CInterface::FUpdate()
    {
        if(VCommand.length() < 49)
        {
            for(unsigned short LKey{SDL_SCANCODE_1} ; LKey <= SDL_SCANCODE_0 ; LKey++)
            {
                if(NInput::GKeyboard.FPressed(LKey))
                {
                    VCommand += (!NInput::GKeyboard.FPressed(SDL_SCANCODE_0) ? '1' : '0' - 9) + LKey - SDL_SCANCODE_1;
                }
            }
            for(unsigned short LKey{SDL_SCANCODE_A} ; LKey <= SDL_SCANCODE_Z ; LKey++)
            {
                if(NInput::GKeyboard.FPressed(LKey))
                {
                    VCommand += (!NInput::GKeyboard.FHeld(SDL_SCANCODE_LSHIFT) ? 'a' : 'A') + LKey - SDL_SCANCODE_A;
                }
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_BACKSPACE))
        {
            if(!VCommand.empty())
            {
                VCommand.pop_back();
            }
        }
        if(NInput::GKeyboard.FPressed(SDL_SCANCODE_RETURN))
        {
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
        for(unsigned int LCharacter{0} ; LCharacter < VCommand.length() ; LCharacter++)
        {
            if(std::isdigit(VCommand[LCharacter]))
            {
                glBindTexture(GL_TEXTURE_2D , VDigits[VCommand[LCharacter] - '0']);
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D , VLetters[std::isupper(VCommand[LCharacter])][VCommand[LCharacter] - (!std::isupper(VCommand[LCharacter]) ? 'a' : 'A')]);
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

    void CInterface::FDeinitialize()
    {
        TTF_Quit();
    }
}
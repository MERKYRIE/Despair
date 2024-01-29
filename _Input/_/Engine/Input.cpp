#include"Input.hpp"

#include"Engine\\Keyboard.hpp"
#include"Engine\\Mouse.hpp"

namespace NBlindness::NEngine{
    void CInput::FUpdate(){
        GKeyboard.FPreupdate();
        GMouse.FPreupdate();
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent)){
            switch(LEvent.type){
                case SDL_KEYDOWN:
                    GKeyboard.FPostupdate(LEvent);
                break;
                case SDL_KEYUP:
                    GKeyboard.FPostupdate(LEvent);
                break;
                case SDL_MOUSEMOTION:
                    GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEBUTTONUP:
                    GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEWHEEL:
                    GMouse.FPostupdate(LEvent);
                break;
            }
        }
    }
}
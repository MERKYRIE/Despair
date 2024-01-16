#include "Input.hpp"

#include "Input\\Keyboard.hpp"
#include "Input\\Mouse.hpp"

namespace NMRKOGL
{
    void CInput::FInitialize()
    {
        NInput::GMouse.FInitialize();
    }

    void CInput::FUpdate()
    {
        NInput::GKeyboard.FPreupdate();
        NInput::GMouse.FPreupdate();
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent))
        {
            switch(LEvent.type)
            {
                case SDL_KEYDOWN:
                    NInput::GKeyboard.FPostupdate(LEvent);
                break;
                case SDL_KEYUP:
                    NInput::GKeyboard.FPostupdate(LEvent);
                break;
                case SDL_MOUSEMOTION:
                    NInput::GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    NInput::GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEBUTTONUP:
                    NInput::GMouse.FPostupdate(LEvent);
                break;
                case SDL_MOUSEWHEEL:
                    NInput::GMouse.FPostupdate(LEvent);
                break;
            }
        }
    }
}
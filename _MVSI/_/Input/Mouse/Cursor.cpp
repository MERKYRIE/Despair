#include"Cursor.hpp"

#include"Cursor\\X.hpp"
#include"Cursor\\Y.hpp"

namespace NBlindness::NInput::NMouse{
    void CCursor::FInitialize(){
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }

    void CCursor::FPreupdate(){
        NCursor::GX.FPreupdate();
        NCursor::GY.FPreupdate();
    }

    void CCursor::FPostupdate(const SDL_Event& PEvent){
        NCursor::GX.FPostupdate(PEvent);
        NCursor::GY.FPostupdate(PEvent);
    }
}
#include"Shade.hpp"

namespace NBlindness::NLevel::NLight{
    void CShade::FInitialize(){
        VModel = GL_SMOOTH;
        glShadeModel(VModel);
    }
}
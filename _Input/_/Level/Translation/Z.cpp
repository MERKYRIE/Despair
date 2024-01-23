#include"Z.hpp"

namespace NBlindness::NLevel::NTranslation{
    void CZ::FInitialize(){
        VValue = 0.5;
    }

    void CZ::FUpdate(){
        glTranslated(0.0 , 0.0 , -VValue);
    }
}
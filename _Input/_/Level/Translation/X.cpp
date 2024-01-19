#include"X.hpp"

#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel::NTranslation{
    void CX::FInitialize(){
        VValue = 0.5;
    }

    CX::operator double(){
        return VValue;
    }

    void CX::operator+=(double PValue){
        VValue += PValue;
    }

    std::uintmax_t CX::FValue(){
        return static_cast<std::uintmax_t>(std::round(VValue - 0.5));
    }
}
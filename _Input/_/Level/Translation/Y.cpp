#include"Y.hpp"

#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"

#include"Input\\Keyboard.hpp"

namespace NBlindness::NLevel::NTranslation{
    void CY::FInitialize(){
        VValue = 0.5;
    }

    CY::operator double(){
        return VValue;
    }

    void CY::operator+=(double PValue){
        VValue += PValue;
    }

    std::uintmax_t CY::FValue(){
        return static_cast<std::uintmax_t>(std::round(VValue - 0.5));
    }
}
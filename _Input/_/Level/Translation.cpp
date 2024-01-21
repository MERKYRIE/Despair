#include"Translation.hpp"

#include"Translation\\X.hpp"
#include"Translation\\Y.hpp"
#include"Translation\\Z.hpp"

namespace NBlindness::NLevel{
    void CTranslation::FInitialize(){
        NTranslation::GX.FInitialize();
        NTranslation::GY.FInitialize();
        NTranslation::GZ.FInitialize();
    }

    void CTranslation::FUpdate(){
        NTranslation::GX.FUpdate();
        NTranslation::GY.FUpdate();
        NTranslation::GZ.FUpdate();
    }
}
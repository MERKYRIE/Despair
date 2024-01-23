#include"Light.hpp"

#include"Light\\Model.hpp"
#include"Light\\Shade.hpp"
#include"Rotation.hpp"
#include"Translation\\X.hpp"
#include"Translation\\Y.hpp"
#include"Translation\\Z.hpp"

namespace NBlindness::NLevel{
    void CLight::FInitialize(){
        VAmbient = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_AMBIENT , VAmbient.data());
        VDiffuse = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_DIFFUSE , VDiffuse.data());
        VSpecular = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_SPECULAR , VSpecular.data());
        VExponent = std::array<float , 1>{1.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_EXPONENT , VExponent.data());
        VCutoff = std::array<float , 1>{60.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_CUTOFF , VCutoff.data());
        VConstant = std::array<float , 1>{1.0F};
        glLightfv(GL_LIGHT0 , GL_CONSTANT_ATTENUATION , VConstant.data());
        VLinear = std::array<float , 1>{0.0F};
        glLightfv(GL_LIGHT0 , GL_LINEAR_ATTENUATION , VLinear.data());
        VQuadratic = std::array<float , 1>{1.0F};
        glLightfv(GL_LIGHT0 , GL_QUADRATIC_ATTENUATION , VQuadratic.data());
        NLight::GModel.FInitialize();
        NLight::GShade.FInitialize();
    }

    void CLight::FUpdate(){
        VPosition = std::array<float , 4>{NTranslation::GX.FValue<float>() , NTranslation::GY.FValue<float>() , NTranslation::GZ.FValue<float>() , 1.0F};
        glLightfv(GL_LIGHT0 , GL_POSITION , VPosition.data());
        VDirection = std::array<float , 3>{GRotation.FForwardX<float>() , GRotation.FForwardY<float>() , 0.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_DIRECTION , VDirection.data());
    }
}
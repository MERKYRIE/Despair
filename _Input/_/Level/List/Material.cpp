#include"Material.hpp"

namespace NBlindness::NLevel::NList{
    void CMaterial::FInitialize(){
        VAmbient  = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_AMBIENT , VAmbient.data());
        VDiffuse = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_DIFFUSE , VDiffuse.data());
        VSpecular = std::array<float , 4>{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_SPECULAR , VSpecular.data());
        VEmission = std::array<float , 4>{0.0F , 0.0F , 0.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_EMISSION , VEmission.data());
        VShininess = std::array<float , 1>{0.0F};
        glMaterialfv(GL_FRONT , GL_SHININESS , VShininess.data());
    }
}
#include"Level.hpp"

#include"Level\\List.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Translation.hpp"

#include"Video.hpp"

namespace NBlindness{
    void CLevel::FInitialize(){
        NLevel::GRotation.FInitialize();
        NLevel::GTranslation.FInitialize();
        NLevel::GSpace.FInitialize();
        NLevel::GList.FInitialize();
    }

    void CLevel::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0 , GVideo.FRatio() , 0.25 , 1'000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        NLevel::GRotation.FUpdate();
        NLevel::GTranslation.FUpdate();

        std::array<float , 4> LMaterialAmbient{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_AMBIENT , LMaterialAmbient.data());
        std::array<float , 4> LMaterialDiffuse{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_DIFFUSE , LMaterialDiffuse.data());
        std::array<float , 4> LMaterialSpecular{1.0F , 1.0F , 1.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_SPECULAR , LMaterialSpecular.data());
        std::array<float , 4> LMaterialEmission{0.0F , 0.0F , 0.0F , 1.0F};
        glMaterialfv(GL_FRONT , GL_EMISSION , LMaterialEmission.data());
        std::array<float , 1> LMaterialShininess{0.0F};
        glMaterialfv(GL_FRONT , GL_SHININESS , LMaterialShininess.data());

        NLevel::GList.FUpdate();

        glBindTexture(GL_TEXTURE_2D , 0);
        glBegin(GL_TRIANGLES);
            glVertex3d(0.25 , 1.5 , 0.25);
            glVertex3d(0.5 , 1.5 , 0.75);
            glVertex3d(0.75 , 1.5 , 0.25);
        glEnd();

        glShadeModel(GL_SMOOTH);
        std::array<float , 4> LLightModelAmbient{-0.1F , -0.1F , -0.1F , 1.0F};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT , LLightModelAmbient.data());
        std::array<float , 1> LLightModelColorControl{GL_SINGLE_COLOR};
        glLightModelfv(GL_LIGHT_MODEL_COLOR_CONTROL , LLightModelColorControl.data());
        std::array<float , 1> LLightModelLocalViewer{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER , LLightModelLocalViewer.data());
        std::array<float , 1> LLightModelTwoSide{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE , LLightModelTwoSide.data());
        std::array<float , 4> LLightAmbient{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_AMBIENT , LLightAmbient.data());
        std::array<float , 4> LLightDiffuse{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_DIFFUSE , LLightDiffuse.data());
        std::array<float , 4> LLightSpecular{1.0F , 1.0F , 1.0F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_SPECULAR , LLightSpecular.data());
        std::array<float , 4> LLightPosition{0.5F , 0.5F , 0.5F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_POSITION , LLightPosition.data());
        std::array<float , 3> LLightDirection{0.0F , 1.0F , 0.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_DIRECTION , LLightDirection.data());
        std::array<float , 1> LLightExponent{1.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_EXPONENT , LLightExponent.data());
        std::array<float , 1> LLightCutoff{60.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_CUTOFF , LLightCutoff.data());
        std::array<float , 1> LLightConstant{1.0F};
        glLightfv(GL_LIGHT0 , GL_CONSTANT_ATTENUATION , LLightConstant.data());
        std::array<float , 1> LLightLinear{0.0F};
        glLightfv(GL_LIGHT0 , GL_LINEAR_ATTENUATION , LLightLinear.data());
        std::array<float , 1> LLightQuadratic{1.0F};
        glLightfv(GL_LIGHT0 , GL_QUADRATIC_ATTENUATION , LLightQuadratic.data());
    }

    void CLevel::FDeinitialize(){
        NLevel::GList.FDeinitialize();
    }
}
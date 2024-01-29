#include"Level.hpp"

#include"Level\\List.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Translation.hpp"

#include"Video.hpp"

namespace NBlindness::NEngine{
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
        NLevel::GList.FUpdate();
        std::array<float , 4> LLightPosition{0.5F , 0.5F , 0.5F , 1.0F};
        glLightfv(GL_LIGHT0 , GL_POSITION , LLightPosition.data());
        std::array<float , 3> LLightSpotDirection{0.0F , 1.0F , 0.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_DIRECTION , LLightSpotDirection.data());
    }

    void CLevel::FDeinitialize(){
        NLevel::GList.FDeinitialize();
    }
}
#include"Level.hpp"

#include"Level\\Light.hpp"
#include"Level\\List.hpp"
#include"Level\\Rotation.hpp"
#include"Level\\Space.hpp"
#include"Level\\Translation.hpp"

#include"Video.hpp"

namespace NBlindness{
    void CLevel::FInitialize(){
        NLevel::GRotation.FInitialize();
        NLevel::GTranslation.FInitialize();
        NLevel::GLight.FInitialize();
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
        NLevel::GLight.FUpdate();
        NLevel::GList.FUpdate();
    }

    void CLevel::FDeinitialize(){
        NLevel::GList.FDeinitialize();
    }
}
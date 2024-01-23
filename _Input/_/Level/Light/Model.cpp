#include"Model.hpp"

namespace NBlindness::NLevel::NLight{
    void CModel::FInitialize(){
        VAmbient = std::array<float , 4>{-0.1F , -0.1F , -0.1F , 1.0F};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT , VAmbient.data());
        VColorControl = std::array<float , 1>{GL_SINGLE_COLOR};
        glLightModelfv(GL_LIGHT_MODEL_COLOR_CONTROL , VColorControl.data());
        VLocalViewer = std::array<float , 1>{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER , VLocalViewer.data());
        VTwoSide = std::array<float , 1>{0.0F};
        glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE , VTwoSide.data());
    }
}
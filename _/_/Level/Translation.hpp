#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        //private : CGAL::Point_3<CGAL::Simple_cartesian<unsigned int>> VPoint;
        private : float VX;
        private : float VZ;

        private : void FInitialize();
        private : void FUpdate();

        public : void FLeftward();
        public : void FRightward();
        public : void FBackward();
        public : void FForward();
    }
    GTranslation;
}
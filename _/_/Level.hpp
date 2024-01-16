#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL{
    inline class CLevel{
        private : friend signed int ::main(signed int , char**);

        private :
            struct SPartition{
                CGAL::Iso_cuboid_3<CGAL::Simple_cartesian<float>> VCuboid;
                bool VCollision;
            };

        private : std::string VPath;
        /*private*/public : std::array<std::array<std::array<SPartition , 8> , 8> , 8> VSpace;
        private : unsigned int VList;

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GLevel;
}
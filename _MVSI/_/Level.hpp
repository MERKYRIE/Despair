#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    inline class CLevel{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private :
            struct SPartition{
                std::uint32_t VLeftward;
                std::uint32_t VRightward;
                std::uint32_t VBackward;
                std::uint32_t VForward;
                std::uint32_t VDownward;
                std::uint32_t VUpward;
            };

        private : std::array<std::array<std::array<SPartition , 1> , 1> , 1> VSpace;
        private : std::uint32_t VList;

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();
    }
    GLevel;
}
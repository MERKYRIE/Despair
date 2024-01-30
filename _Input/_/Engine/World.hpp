#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CPartition;
    
    inline class CWorld{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : static constexpr std::uintmax_t VWidth{100};
        private : static constexpr std::uintmax_t VDepth{100};
        private : static constexpr std::uintmax_t VHeight{1};
        
        private : std::uint32_t VList;
        private : double VRotation;
        private : std::int8_t VBackwardX;
        private : std::int8_t VBackwardY;
        private : std::int8_t VForwardX;
        private : std::int8_t VForwardY;
        private : std::vector<std::vector<std::vector<std::shared_ptr<CPartition>>>> VSpace;
        private : double VRealX;
        private : double VRealY;
        private : double VRealZ;
        private : std::uintmax_t VIntegralX;
        private : std::uintmax_t VIntegralY;
        private : std::uintmax_t VIntegralZ;

        private : void FInitialize();
        private : void FUpdate();
        private : void FDeinitialize();

        public : std::uintmax_t FWidth();
        public : std::uintmax_t FDepth();
        public : std::uintmax_t FHeight();
        public : std::uintmax_t FX();
        public : std::uintmax_t FY();
        public : std::uintmax_t FZ();
        public : const CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    }
    GWorld;
}
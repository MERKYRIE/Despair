#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    namespace NSpace{
        class CPartition;
    }
    
    inline class CSpace{
        private : friend class CLevel;

        private : std::vector<std::vector<std::vector<std::shared_ptr<NSpace::CPartition>>>> VValue;

        private : void FInitialize();

        public : const NSpace::CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    }
    GSpace;
}
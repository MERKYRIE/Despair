#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    namespace NSpace{
        class CPartition;
    }
    
    inline class CSpace{
        private : friend class CLevel;

        private : static constexpr std::uintmax_t VWidth{5};
        private : static constexpr std::uintmax_t VDepth{5};
        private : static constexpr std::uintmax_t VHeight{5};

        private : std::vector<std::vector<std::vector<std::shared_ptr<NSpace::CPartition>>>> VValue;

        private : void FInitialize();

        public : std::uintmax_t FWidth();
        public : std::uintmax_t FDepth();
        public : std::uintmax_t FHeight();
        public : const NSpace::CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    }
    GSpace;
}
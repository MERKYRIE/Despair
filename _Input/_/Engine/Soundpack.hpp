#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CSound;

    inline class CSoundpack{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CSound>> VSounds;

        private : void FInitialize();
        private : void FDeinitialize();

        public : const CSound& FSound(const std::string& PPath);
    }
    GSoundpack;
}
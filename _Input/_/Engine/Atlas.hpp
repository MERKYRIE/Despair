#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CTexture;
    
    inline class CAtlas{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::shared_ptr<CTexture>> VTextures;

        private : void FInitialize();
        private : void FDeinitialize();

        public : std::uint32_t FTexture(const std::string& PPath);
    }
    GAtlas;
}
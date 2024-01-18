#pragma once

#include"Blindness.hpp"

namespace NBlindness::NVideo{
    namespace NAtlas{
        class CTexture;
    }
    
    inline class CAtlas{
        private : friend class CVideo;

        private : std::vector<std::shared_ptr<NAtlas::CTexture>> VTextures;

        private : void FInitialize();
        private : void FDeinitialize();

        public : std::uint32_t FTexture(const std::string& PPath);
    }
    GAtlas;
}
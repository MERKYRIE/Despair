#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    class CFont;
    class CTexture;
    
    inline class CVideo{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : SDL_Window* VWindow;
        private : SDL_GLContext VContext;
        private : float VRatio;
        private : float VInversedRatio;
        private : std::uint32_t VVertex;
        private : std::uint32_t VFragment;
        private : std::uint32_t VProgram;
        private : std::vector<std::shared_ptr<CFont>> VFonts;
        private : std::vector<std::shared_ptr<CTexture>> VTextures;

        private : void FInitialize();
        private : void FPreupdate();
        private : void FPostupdate();
        private : void FDeinitialize();

        public : float FRatio();
        public : float FInversedRatio();
        public : const CFont& FFont(const std::string& PPath);
        public : const CTexture& FTexture(const std::string& PPath);
    }
    GVideo;
}
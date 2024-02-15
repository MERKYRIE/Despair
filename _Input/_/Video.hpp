#pragma once

#include"Blindness.hpp"

namespace NBlindness{
    namespace NVideo{
        class CFont;
        class CShader;
        class CTexture;
    }
    
    inline class CVideo{
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : SDL_Window* VWindow;
        private : SDL_GLContext VContext;
        private : float VRatio;
        private : float VInversedRatio;
        private : std::shared_ptr<NVideo::CShader> VVertex;
        private : std::shared_ptr<NVideo::CShader> VFragment;
        private : std::uint32_t VProgram;
        private : std::vector<std::shared_ptr<NVideo::CFont>> VFonts;
        private : std::vector<std::shared_ptr<NVideo::CTexture>> VTextures;

        private : void FInitialize();
        private : void FPreupdate();
        private : void FPostupdate();
        private : void FDeinitialize();

        public : float FRatio();
        public : float FInversedRatio();
        public : const NVideo::CFont& FFont(const std::string& PPath);
        public : const NVideo::CTexture& FTexture(const std::string& PPath);
    }
    GVideo;
}
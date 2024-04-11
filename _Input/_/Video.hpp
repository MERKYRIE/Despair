#pragma once

#include"Core.hpp"

namespace NDespair
{
    class CVideo
    {
        private : SDL_Window* FWindow;
        private : SDL_GLContext FContext;
        private : float FRatio;
        private : float FInversedRatio;
        private : std::shared_ptr<NVideo::CShader> FVertex;
        private : std::shared_ptr<NVideo::CShader> FFragment;
        private : std::uint32_t FProgram;
        private : std::vector<std::shared_ptr<NVideo::CFont>> FFonts;
        private : std::vector<std::shared_ptr<NVideo::CTexture>> FTextures;

        public : CVideo();
        public : void APreupdate();
        public : float ARatio();
        public : float AInversedRatio();
        public : NVideo::CFont* AAccessFont(const std::string& PPath);
        public : NVideo::CTexture* AAccessSpecificTexture(const std::string& PPath);
        public : NVideo::CTexture* AAccessRandomTexture();
        public : void APostupdate();
        public : ~CVideo();
    };
}
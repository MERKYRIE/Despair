#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    namespace NVideo
    {
        class CFont;
        class CShader;
        class CTexture;
    }
    
    inline class CVideo
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : SDL_Window* FWindow;
        private : SDL_GLContext FContext;
        private : float FRatio;
        private : float FInversedRatio;
        private : std::shared_ptr<NVideo::CShader> FVertex;
        private : std::shared_ptr<NVideo::CShader> FFragment;
        private : std::uint32_t FProgram;
        private : std::vector<std::shared_ptr<NVideo::CFont>> FFonts;
        private : std::vector<std::shared_ptr<NVideo::CTexture>> FTextures;

        private : void BInitialize();
        private : void BPreupdate();
        private : void BPostupdate();
        private : void BDeinitialize();

        public : float ORatio();
        public : float OInversedRatio();
        public : const NVideo::CFont& OAccessFont(const std::string& PPath);
        public : const NVideo::CTexture& OAccessSpecificTexture(const std::string& PPath);
        public : const NVideo::CTexture& OAccessRandomTexture();
    }
    GVideo;
}
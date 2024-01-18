#include"Atlas.hpp"

#include"Atlas\\Texture.hpp"

#include"Debug\\Assert.hpp"
#include"Debug\\Assert\\Error.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NVideo{
    void CAtlas::FInitialize(){
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FFlags(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Textures"}){
            if(LEntry.path().extension() == ".png"){
                VTextures.emplace_back(new NAtlas::CTexture{LEntry.path().string()});
            }
        }
        VTextures.shrink_to_fit();
    }

    void CAtlas::FDeinitialize(){
        VTextures.clear();
        IMG_Quit();
    }

    std::uint32_t CAtlas::FTexture(const std::string& PPath){
        std::vector<std::shared_ptr<NAtlas::CTexture>>::iterator LIterator{
            std::find_if(VTextures.begin() , VTextures.end() , [&PPath](const std::shared_ptr<NAtlas::CTexture>& LPointer){return LPointer->FPath() == PPath;})
        };
        if(LIterator != VTextures.end()){
            return LIterator->get()->FIdentifier();
        }
        else{
            return 0;
        }
    }
}
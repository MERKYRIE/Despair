#include"Atlas.hpp"

#include"Texture.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    void CAtlas::FInitialize(){
        GDebug.FSimpleDirectMediaLayerFlagsError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Atlas"}){
            if(LEntry.path().extension() == ".png"){
                VTextures.emplace_back(new CTexture{LEntry.path().string()});
            }
        }
        VTextures.shrink_to_fit();
    }

    void CAtlas::FDeinitialize(){
        VTextures.clear();
        IMG_Quit();
    }

    std::uint32_t CAtlas::FTexture(const std::string& PPath){
        std::vector<std::shared_ptr<CTexture>>::iterator LIterator{
            std::find_if(VTextures.begin() , VTextures.end() , [&PPath](const std::shared_ptr<CTexture>& LPointer){return *LPointer == PPath;})
        };
        if(LIterator != VTextures.end()){
            return LIterator->get()->FIdentifier();
        }
        else{
            return 0;
        }
    }
}
#include"Typeface.hpp"

#include"Font.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    void CTypeface::FInitialize(){
        GDebug.FSimpleDirectMediaLayerCodeError(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Typeface"}){
            if(LEntry.path().extension() == ".ttf"){
                VFonts.emplace_back(new CFont{LEntry.path().string()});
            }
        }
        VFonts.shrink_to_fit();
    }

    void CTypeface::FDeinitialize(){
        VFonts.clear();
        TTF_Quit();
    }

    const CFont& CTypeface::FFont(const std::string& PPath){
        std::vector<std::shared_ptr<CFont>>::iterator LIterator{
            std::find_if(VFonts.begin() , VFonts.end() , [&PPath](const std::shared_ptr<CFont>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VFonts.end());
        return **LIterator;
    }
}
#include"Typeface.hpp"

#include"Typeface\\Font.hpp"

#include"Debug\\Assert.hpp"
#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NVideo{
    void CTypeface::FInitialize(){
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FCode(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Typeface"}){
            if(LEntry.path().extension() == ".ttf"){
                VFonts.emplace_back(new NTypeface::CFont{LEntry.path().string()});
            }
        }
        VFonts.shrink_to_fit();
    }

    void CTypeface::FDeinitialize(){
        VFonts.clear();
        TTF_Quit();
    }

    const NTypeface::CFont& CTypeface::FFont(const std::string& PPath){
        std::vector<std::shared_ptr<NTypeface::CFont>>::iterator LIterator{
            std::find_if(VFonts.begin() , VFonts.end() , [&PPath](const std::shared_ptr<NTypeface::CFont>& LPointer){return *LPointer == PPath;})
        };
        NDebug::GAssert.FError(LIterator == VFonts.end());
        return **LIterator;
    }
}
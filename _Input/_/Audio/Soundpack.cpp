#include"Soundpack.hpp"

#include"Soundpack\\Sound.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NAudio{
    void CSoundpack::FInitialize(){
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"}){
            if(LEntry.path().extension() == ".wav"){
                VSounds.emplace_back(new NSoundpack::CSound{LEntry.path().string()});
            }
        }
        VSounds.shrink_to_fit();
    }

    void CSoundpack::FDeinitialize(){
        VSounds.clear();
    }

    const NSoundpack::CSound& CSoundpack::FSound(const std::string& PPath){
        std::vector<std::shared_ptr<NSoundpack::CSound>>::iterator LIterator{
            std::find_if(VSounds.begin() , VSounds.end() , [&PPath](const std::shared_ptr<NSoundpack::CSound>& LPointer){return *LPointer == PPath;})
        };
        NDebug::GAssert.FError(LIterator == VSounds.end());
        return **LIterator;
    }
}
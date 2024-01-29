#include"Soundpack.hpp"

#include"Sound.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    void CSoundpack::FInitialize(){
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundpack"}){
            if(LEntry.path().extension() == ".wav"){
                VSounds.emplace_back(new CSound{LEntry.path().string()});
            }
        }
        VSounds.shrink_to_fit();
    }

    void CSoundpack::FDeinitialize(){
        VSounds.clear();
    }

    const CSound& CSoundpack::FSound(const std::string& PPath){
        std::vector<std::shared_ptr<CSound>>::iterator LIterator{
            std::find_if(VSounds.begin() , VSounds.end() , [&PPath](const std::shared_ptr<CSound>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VSounds.end());
        return **LIterator;
    }
}
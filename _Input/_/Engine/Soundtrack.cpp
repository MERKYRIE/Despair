#include"Soundtrack.hpp"

#include"Track.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    void CSoundtrack::FInitialize(){
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"}){
            if(LEntry.path().extension() == ".mp3"){
                VTracks.emplace_back(new CTrack{LEntry.path().string()});
            }
        }
        VTracks.shrink_to_fit();
    }

    void CSoundtrack::FDeinitialize(){
        VTracks.clear();
    }

    const CTrack& CSoundtrack::FTrack(const std::string& PPath){
        std::vector<std::shared_ptr<CTrack>>::iterator LIterator{
            std::find_if(VTracks.begin() , VTracks.end() , [&PPath](const std::shared_ptr<CTrack>& LPointer){return *LPointer == PPath;})
        };
        GDebug.FError(LIterator == VTracks.end());
        return **LIterator;
    }
}
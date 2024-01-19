#include"Soundtrack.hpp"

#include"Soundtrack\\Track.hpp"

#include"Debug\\Assert.hpp"

namespace NBlindness::NAudio{
    void CSoundtrack::FInitialize(){
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Soundtrack"}){
            if(LEntry.path().extension() == ".mp3"){
                VTracks.emplace_back(new NSoundtrack::CTrack{LEntry.path().string()});
            }
        }
        VTracks.shrink_to_fit();
    }

    void CSoundtrack::FDeinitialize(){
        VTracks.clear();
    }

    const NSoundtrack::CTrack& CSoundtrack::FTrack(const std::string& PPath){
        std::vector<std::shared_ptr<NSoundtrack::CTrack>>::iterator LIterator{
            std::find_if(VTracks.begin() , VTracks.end() , [&PPath](const std::shared_ptr<NSoundtrack::CTrack>& LPointer){return *LPointer == PPath;})
        };
        NDebug::GAssert.FError(LIterator == VTracks.end());
        return **LIterator;
    }
}
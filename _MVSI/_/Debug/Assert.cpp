#include"Assert.hpp"

#include"Debug.hpp"

namespace NBlindness::NDebug{
    void CAssert::FError(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        GDebug.FAssert(PCondition , PMessage , SDL_MESSAGEBOX_ERROR , PLocation);
    }

    bool CAssert::FWarning(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        GDebug.FAssert(PCondition , PMessage , SDL_MESSAGEBOX_WARNING , PLocation);
        return PCondition;
    }

    bool CAssert::FInformation(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        GDebug.FAssert(PCondition , PMessage , SDL_MESSAGEBOX_INFORMATION , PLocation);
        return PCondition;
    }
}
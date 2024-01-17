#pragma once

#include"Blindness.hpp"

namespace NBlindness::NDebug{
    inline class CAssert{
        public : void FError(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool FWarning(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool FInformation(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
    }
    GAssert;
}
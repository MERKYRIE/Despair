#pragma once

#include "MRKOGL.hpp"

namespace NMRKOGL::NDebug
{
    inline class CAssert
    {
        public:
            void FError(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
            bool FWarning(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
            bool FInformation(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
    }
    GAssert;
}
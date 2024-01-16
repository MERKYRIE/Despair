#include "Information.hpp"

#include "Debug\\Assert.hpp"

namespace NMRKOGL::NDebug::NAssert
{
    bool CInformation::FOGL(const std::source_location& PLocation)
    {
        unsigned int LCode{glGetError()};
        return GAssert.FInformation(LCode , std::string{} + "OGL - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    bool CInformation::FOAIL(const void* PHandle , const std::source_location& PLocation)
    {
        return GAssert.FInformation(!PHandle , std::string{} + "AI - " + aiGetErrorString() , PLocation);
    }
}
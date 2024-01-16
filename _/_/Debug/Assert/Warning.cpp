#include "Warning.hpp"

#include "Debug\\Assert.hpp"

namespace NMRKOGL::NDebug::NAssert
{
    bool CWarning::FOGL(const std::source_location& PLocation)
    {
        unsigned int LCode{glGetError()};
        return GAssert.FWarning(LCode , std::string{} + "OGL - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    bool CWarning::FOAIL(const void* PHandle , const std::source_location& PLocation)
    {
        return GAssert.FWarning(!PHandle , std::string{} + "AI - " + aiGetErrorString() , PLocation);
    }
}
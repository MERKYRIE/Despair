#include "Error.hpp"

#include "Debug\\Assert.hpp"

namespace NMRKOGL::NDebug::NAssert
{
    void CError::FOGL(const std::source_location& PLocation)
    {
        unsigned int LCode{glGetError()};
        GAssert.FError(LCode , std::string{} + "OGL - " + reinterpret_cast<const char*>(gluErrorString(LCode)) , PLocation);
    }

    void CError::FOAIL(const void* PHandle , const std::source_location& PLocation)
    {
        GAssert.FError(!PHandle , std::string{} + "AI - " + aiGetErrorString() , PLocation);
    }
}
#include"Coordinate.hpp"

namespace NBlindness::NLevel{
    template<typename TReal> TReal CCoordinate::FValue(){
        return static_cast<TReal>(VValue);
    }

    template<typename TInteger> TInteger CCoordinate::FValue() requires std::unsigned_integral<TInteger>{
        return static_cast<TInteger>(std::round(FValue<double>() - 0.5));
    }
}
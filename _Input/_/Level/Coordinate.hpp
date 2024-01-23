#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    class CCoordinate{
        protected : double VValue;

        public : template<typename TReal> TReal FValue();
        public : template<typename TInteger> TInteger FValue() requires std::unsigned_integral<TInteger>;
    };
}

#include"Coordinate.inl"
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    class CDimension{
        protected : std::uintmax_t VValue;

        public : template<typename TInteger> TInteger FValue() requires std::unsigned_integral<TInteger>;
    };
}

#include"Dimension.inl"
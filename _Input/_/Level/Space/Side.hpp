#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    class CSide{
        protected : std::uint32_t VValue;

        public : CSide(std::uint32_t PValue);
        public : template<typename TInteger> TInteger FValue() requires std::unsigned_integral<TInteger>;
    };
}

#include"Side.inl"
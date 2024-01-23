#include"Dimension.hpp"

namespace NBlindness::NLevel{
    template<typename TInteger> TInteger CDimension::FValue() requires std::unsigned_integral<TInteger>{
        return static_cast<TInteger>(VValue);
    }
}
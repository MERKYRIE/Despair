#include"Side.hpp"

namespace NBlindness::NLevel{
    CSide::CSide(std::uint32_t PValue){
        VValue = PValue;
    }
    
    template<typename TInteger> TInteger CSide::FValue() requires std::unsigned_integral<TInteger>{
        return static_cast<TInteger>(VValue);
    }
}
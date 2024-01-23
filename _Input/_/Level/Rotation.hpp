#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CRotation{
        private : friend class CLevel;

        private : double VValue;

        private : void FInitialize();
        private : void FUpdate();

        public : template<typename TReal> TReal FBackwardX();
        public : template<typename TInteger> TInteger FBackwardX() requires std::signed_integral<TInteger>;
        public : template<typename TReal> TReal FBackwardY();
        public : template<typename TInteger> TInteger FBackwardY() requires std::signed_integral<TInteger>;
        public : template<typename TReal> TReal FForwardX();
        public : template<typename TInteger> TInteger FForwardX() requires std::signed_integral<TInteger>;
        public : template<typename TReal> TReal FForwardY();
        public : template<typename TInteger> TInteger FForwardY() requires std::signed_integral<TInteger>;
    }
    GRotation;

    template float CRotation::FBackwardX<float>();
    template double CRotation::FBackwardX<double>();
    template std::int8_t CRotation::FBackwardX<std::int8_t>();
    template std::int16_t CRotation::FBackwardX<std::int16_t>();
    template std::int32_t CRotation::FBackwardX<std::int32_t>();
    template std::intmax_t CRotation::FBackwardX<std::intmax_t>();
    template float CRotation::FBackwardY<float>();
    template double CRotation::FBackwardY<double>();
    template std::int8_t CRotation::FBackwardY<std::int8_t>();
    template std::int16_t CRotation::FBackwardY<std::int16_t>();
    template std::int32_t CRotation::FBackwardY<std::int32_t>();
    template std::intmax_t CRotation::FBackwardY<std::intmax_t>();
    template float CRotation::FForwardX<float>();
    template double CRotation::FForwardX<double>();
    template std::int8_t CRotation::FForwardX<std::int8_t>();
    template std::int16_t CRotation::FForwardX<std::int16_t>();
    template std::int32_t CRotation::FForwardX<std::int32_t>();
    template std::intmax_t CRotation::FForwardX<std::intmax_t>();
    template float CRotation::FForwardY<float>();
    template double CRotation::FForwardY<double>();
    template std::int8_t CRotation::FForwardY<std::int8_t>();
    template std::int16_t CRotation::FForwardY<std::int16_t>();
    template std::int32_t CRotation::FForwardY<std::int32_t>();
    template std::intmax_t CRotation::FForwardY<std::intmax_t>();
}
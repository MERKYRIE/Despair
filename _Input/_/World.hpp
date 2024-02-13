#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld{
    struct SCube;

    inline constexpr std::uintmax_t VDistanceAlongX{100};
    inline constexpr std::uintmax_t VDistanceAlongY{100};
    inline constexpr std::uintmax_t VDistanceAlongZ{1};
        
    inline double VRotation;
    inline std::int8_t VDirectionBackwardX;
    inline std::int8_t VDirectionBackwardY;
    inline std::int8_t VDirectionForwardX;
    inline std::int8_t VDirectionForwardY;
    inline std::vector<std::vector<std::vector<SCube>>> VSpace;
    inline double VTranslationRealX;
    inline double VTranslationRealY;
    inline double VTranslationRealZ;
    inline std::uintmax_t VTranslationIntegralX;
    inline std::uintmax_t VTranslationIntegralY;
    inline std::uintmax_t VTranslationIntegralZ;

    void FInitialize();
    void FUpdate();
    std::uintmax_t FDistanceAlongX();
    std::uintmax_t FDistanceAlongY();
    std::uintmax_t FDistanceAlongZ();
    std::uintmax_t FTranslationIntegralX();
    std::uintmax_t FTranslationIntegralY();
    std::uintmax_t FTranslationIntegralZ();
    SCube& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    void FDeinitialize();
}
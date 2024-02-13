#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld{
    struct SCube{
        std::uint32_t VTextureNegativeX;
        std::uint32_t VTexturePositiveX;
        std::uint32_t VTextureNegativeY;
        std::uint32_t VTexturePositiveY;
        std::uint32_t VTextureNegativeZ;
        std::uint32_t VTexturePositiveZ;
        std::uint32_t VVertexArrayObject;
        std::uint32_t VVertexBufferObject;
        std::uint32_t VElementBufferObject;
    };

    inline SCube* GCube;

    namespace NCube{
        inline constexpr std::array<double , 20> GSquareNegativeX{
            0.0 , 0.0 , 0.0 , 0.0 , 1.0 ,
            0.0 , 0.0 , 1.0 , 0.0 , 0.0 ,
            0.0 , 1.0 , 1.0 , 1.0 , 0.0 ,
            0.0 , 1.0 , 0.0 , 1.0 , 1.0
        };
        inline constexpr std::array<double , 20> GSquarePositiveX{
            1.0 , 1.0 , 0.0 , 0.0 , 1.0 ,
            1.0 , 1.0 , 1.0 , 0.0 , 0.0 ,
            1.0 , 0.0 , 1.0 , 1.0 , 0.0 ,
            1.0 , 0.0 , 0.0 , 1.0 , 1.0
        };
        inline constexpr std::array<double , 20> GSquareNegativeY{
            1.0 , 0.0 , 0.0 , 0.0 , 1.0 ,
            1.0 , 0.0 , 1.0 , 0.0 , 0.0 ,
            0.0 , 0.0 , 1.0 , 1.0 , 0.0 ,
            0.0 , 0.0 , 0.0 , 1.0 , 1.0
        };
        inline constexpr std::array<double , 20> GSquarePositiveY{
            0.0 , 1.0 , 0.0 , 0.0 , 1.0 ,
            0.0 , 1.0 , 1.0 , 0.0 , 0.0 ,
            1.0 , 1.0 , 1.0 , 1.0 , 0.0 ,
            1.0 , 1.0 , 0.0 , 1.0 , 1.0
        };
        inline constexpr std::array<double , 20> GSquareNegativeZ{
            0.0 , 0.0 , 0.0 , 0.0 , 1.0 ,
            0.0 , 1.0 , 0.0 , 0.0 , 0.0 ,
            1.0 , 1.0 , 0.0 , 1.0 , 0.0 ,
            1.0 , 0.0 , 0.0 , 1.0 , 1.0
        };
        inline constexpr std::array<double , 20> GSquarePositiveZ{
            0.0 , 1.0 , 1.0 , 0.0 , 1.0 ,
            0.0 , 0.0 , 1.0 , 0.0 , 0.0 ,
            1.0 , 0.0 , 1.0 , 1.0 , 0.0 ,
            1.0 , 1.0 , 1.0 , 1.0 , 1.0
        };
        
        bool FCanBeGenerated(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        bool FGenerate(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        void FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        bool FIsCollisionDetected(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
    };
}
#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CSpace
    {
        private : struct SPartition
        {
            NVideo::CTexture* FTextureNegativeX;
            NVideo::CTexture* FTexturePositiveX;
            NVideo::CTexture* FTextureNegativeY;
            NVideo::CTexture* FTexturePositiveY;
            NVideo::CTexture* FTextureNegativeZ;
            NVideo::CTexture* FTexturePositiveZ;
        };
        
        private : std::intmax_t FSizeX;
        private : std::intmax_t FSizeY;
        private : std::intmax_t FSizeZ;
        private : std::intmax_t FPositionX;
        private : std::intmax_t FPositionY;
        private : std::intmax_t FPositionZ;
        private : std::int8_t FDirectionX;
        private : std::int8_t FDirectionY;
        private : std::intmax_t FVision;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeX;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveX;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeY;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveY;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeZ;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveZ;
        private : std::vector<std::vector<std::vector<SPartition>>> FMatrix;

        private : void IReevaluatePositionXY();
        private : void IReevaluatePositionZ();
        private : bool IDoesPartitionExist(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : std::intmax_t IEvaluateOffsetX(std::intmax_t PCoordinate);
        private : std::intmax_t IEvaluateOffsetY(std::intmax_t PCoordinate);
        private : std::intmax_t IEvaluateOffsetZ(std::intmax_t PCoordinate);
        private : bool ICanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool IGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool ICanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool IGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool IIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);

        public : CSpace();
        public : void AUpdate();
    }
    *GSpace;
}
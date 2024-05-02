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
        private : std::intmax_t FTranslationX;
        private : std::intmax_t FTranslationY;
        private : std::intmax_t FTranslationZ;
        private : std::int8_t FRotationX;
        private : std::int8_t FRotationY;
        private : std::intmax_t FVision;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeX;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveX;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeY;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveY;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectNegativeZ;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObjectPositiveZ;
        private : std::vector<std::vector<std::vector<SPartition>>> FMatrix;

        private : void IReevaluateTranslation(std::intmax_t& PTranslation , const std::intmax_t& PSize);
        private : void IReevaluateTranslationX();
        private : void IReevaluateTranslationY();
        private : void IReevaluateTranslationZ();
        private : void IReevaluateTranslationXY();
        private : void IReevaluateTranslationXYZ();
        private : void IConstructVertexArrayObject(std::shared_ptr<NVideo::CVertexArrayObject>& PVertexArrayObject , const std::array<float , 20>& PVertices);
        private : std::intmax_t IEvaluateOffset(const std::intmax_t& PTo , const std::intmax_t& PFrom);
        private : std::intmax_t IEvaluateOffsetX(const std::intmax_t& PTo);
        private : std::intmax_t IEvaluateOffsetY(const std::intmax_t& PTo);
        private : std::intmax_t IEvaluateOffsetZ(const std::intmax_t& PTo);
        private : bool IDoesTranslationExist(const std::intmax_t& PTranslation , const std::intmax_t& PSize);
        private : bool IDoesPartitionExist(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);
        private : bool IGenerateTransition(NVideo::CTexture*& PFrom , NVideo::CTexture*& PTo);
        private : void ITryGenerateTransitionHorizontal(std::intmax_t& PGenerated , const std::intmax_t& PRequested , const std::intmax_t& PX , const std::intmax_t& PY);
        private : bool ICanGenerateTransitionHorizontal(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);
        private : bool IGenerateTransitionHorizontal(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);
        private : void ITryGenerateTransitionVertical(const std::intmax_t& PZ);
        private : bool ICanGenerateTransitionVertical(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);
        private : bool IGenerateTransitionVertical(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);
        private : bool IIsCollisionDetected(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ);

        public : CSpace();
        public : void AUpdate();
    }
    *GSpace;
}
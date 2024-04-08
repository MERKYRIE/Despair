#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CSpace
    {
        private : std::intmax_t FSizeX;
        private : std::intmax_t FSizeY;
        private : std::intmax_t FSizeZ;
        private : std::intmax_t FPositionX;
        private : std::intmax_t FPositionY;
        private : std::intmax_t FPositionZ;
        private : std::int8_t FDirectionX;
        private : std::int8_t FDirectionY;
        private : std::intmax_t FVision;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeX;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveX;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeY;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveY;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeZ;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveZ;
        private : std::vector<std::vector<std::vector<std::shared_ptr<NSpace::CPartition>>>> FMatrix;

        private : void IReevaluatePositionXY();
        private : void IReevaluatePositionZ();

        public : void AInitialize();
        public : void AUpdate();
        public : NSpace::CPartition& AAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : bool ADoesPartitionExist(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : std::intmax_t AEvaluateOffsetX(std::intmax_t PCoordinate);
        public : std::intmax_t AEvaluateOffsetY(std::intmax_t PCoordinate);
        public : std::intmax_t AEvaluateOffsetZ(std::intmax_t PCoordinate);
        public : void ABindVertexArrayObjectNegativeX();
        public : void ABindVertexArrayObjectPositiveX();
        public : void ABindVertexArrayObjectNegativeY();
        public : void ABindVertexArrayObjectPositiveY();
        public : void ABindVertexArrayObjectNegativeZ();
        public : void ABindVertexArrayObjectPositiveZ();
        public : void ADeinitialize();
    }
    GSpace;
}
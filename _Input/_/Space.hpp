#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    namespace NSpace
    {
        class CPartition;
        class CVertexArrayObject;
    }

    inline class CSpace
    {
        friend std::int32_t (::main(std::int32_t , char**));

        friend class NSpace::CPartition;

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

        private : void BInitialize();
        private : void BUpdate();
        private : void BDeinitialize();

        private : NSpace::CPartition& DAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : bool DDoesPartitionExist(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        private : std::intmax_t DEvaluateOffsetX(std::intmax_t PCoordinate);
        private : std::intmax_t DEvaluateOffsetY(std::intmax_t PCoordinate);
        private : std::intmax_t DEvaluateOffsetZ(std::intmax_t PCoordinate);
        private : void DBindVertexArrayObjectNegativeX();
        private : void DBindVertexArrayObjectPositiveX();
        private : void DBindVertexArrayObjectNegativeY();
        private : void DBindVertexArrayObjectPositiveY();
        private : void DBindVertexArrayObjectNegativeZ();
        private : void DBindVertexArrayObjectPositiveZ();
    }
    GSpace;
}
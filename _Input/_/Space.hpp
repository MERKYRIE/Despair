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

        private : std::vector<std::vector<std::vector<std::shared_ptr<NSpace::CPartition>>>> FMatrix;
        private : std::intmax_t FSizeX;
        private : std::intmax_t FSizeY;
        private : std::intmax_t FSizeZ;
        private : float FTranslationX;
        private : float FTranslationY;
        private : float FTranslationZ;
        private : std::intmax_t FPositionX;
        private : std::intmax_t FPositionY;
        private : std::intmax_t FPositionZ;
        private : float FRotation;
        private : std::int8_t FDirectionX;
        private : std::int8_t FDirectionY;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeX;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveX;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeY;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveY;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectNegativeZ;
        private : std::shared_ptr<NSpace::CVertexArrayObject> FVertexArrayObjectPositiveZ;

        private : void IReevaluateDirection();
        private : void IReevaluatePositionXY();
        private : void IReevaluatePositionZ();

        private : void BInitialize();
        private : void BUpdate();
        private : void BDeinitialize();

        private : std::intmax_t DSizeX();
        private : std::intmax_t DSizeY();
        private : std::intmax_t DSizeZ();
        private : std::intmax_t DPositionX();
        private : std::intmax_t DPositionY();
        private : std::intmax_t DPositionZ();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectNegativeX();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectPositiveX();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectNegativeY();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectPositiveY();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectNegativeZ();
        private : const std::shared_ptr<NSpace::CVertexArrayObject>& DVertexArrayObjectPositiveZ();
        private : NSpace::CPartition& DAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
    }
    GSpace;
}
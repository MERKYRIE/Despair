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
        private : friend std::int32_t (::main(std::int32_t , char**));

        private : std::vector<std::vector<std::vector<std::shared_ptr<NSpace::CPartition>>>> FMatrix;
        private : std::intmax_t FDistanceAlongX;
        private : std::intmax_t FDistanceAlongY;
        private : std::intmax_t FDistanceAlongZ;
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

        private : void AInitialize();
        private : void AUpdate();
        private : void ADeinitialize();

        public : std::intmax_t OAccessTranslationIntegralX();
        public : std::intmax_t OAccessTranslationIntegralY();
        public : std::intmax_t OAccessTranslationIntegralZ();
        public : NSpace::CPartition& OAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ);
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectNegativeX();
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectPositiveX();
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectNegativeY();
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectPositiveY();
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectNegativeZ();
        public : const std::shared_ptr<NSpace::CVertexArrayObject>& OVertexArrayObjectPositiveZ();
    }
    GSpace;
}
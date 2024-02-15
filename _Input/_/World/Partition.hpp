#pragma once

#include"Blindness.hpp"

namespace NBlindness::NWorld{
    class CVertexArrayObject;
    
    class CPartition{
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectNegativeX;
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectPositiveX;
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectNegativeY;
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectPositiveY;
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectNegativeZ;
        private : std::shared_ptr<NWorld::CVertexArrayObject> VVertexArrayObjectPositiveZ;
        private : std::uint32_t VTextureNegativeX;
        private : std::uint32_t VTexturePositiveX;
        private : std::uint32_t VTextureNegativeY;
        private : std::uint32_t VTexturePositiveY;
        private : std::uint32_t VTextureNegativeZ;
        private : std::uint32_t VTexturePositiveZ;

        public : CPartition(
            std::uintmax_t PX ,
            std::uintmax_t PY ,
            std::uintmax_t PZ ,
            std::uint32_t PTextureNegativeX ,
            std::uint32_t PTexturePositiveX ,
            std::uint32_t PTextureNegativeY ,
            std::uint32_t PTexturePositiveY ,
            std::uint32_t PTextureNegativeZ ,
            std::uint32_t PTexturePositiveZ
        );
        public : bool FCanGenerateTransition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FGenerateNewTransition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FCanGenerateShaft(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FGenerateNewShaft(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : void FRender(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : bool FIsCollisionDetected(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ);
        public : ~CPartition();
    };
}
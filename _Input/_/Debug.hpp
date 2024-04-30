#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CDebug
    {
        private : std::string IAssert(const std::string& PMessage , const std::source_location& PLocation);
        
        public : CDebug();
        public : void AAssert(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : void AAssertSimpleDirectMediaLayerCode(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void AAssertSimpleDirectMediaLayerMask(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void AAssertSimpleDirectMediaLayerHandle(void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : void AAssertOpenGraphicsLibrary(const std::source_location& PLocation = std::source_location::current());
        public : void AAssertOpenAssetImportLibrary(void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    *GDebug;
}
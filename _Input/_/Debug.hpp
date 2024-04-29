#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CDebug
    {
        private : void IAssert(bool PCondition , const std::string& PMessage , SDL_MessageBoxFlags PFlags , const std::source_location& PLocation);

        public : CDebug();
        public : void AError(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool AWarning(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool AInformation(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : void ASimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void ASimpleDirectMediaLayerMaskError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerMaskWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerMaskInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void ASimpleDirectMediaLayerHandleError(void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerHandleWarning(void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool ASimpleDirectMediaLayerHandleInformation(void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : void AOpenGraphicsLibraryError(const std::source_location& PLocation = std::source_location::current());
        public : bool AOpenGraphicsLibraryWarning(const std::source_location& PLocation = std::source_location::current());
        public : bool AOpenGraphicsLibraryInformation(const std::source_location& PLocation = std::source_location::current());
        public : void AOpenAssetImportLibraryError(void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool AOpenAssetImportLibraryWarning(void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool AOpenAssetImportLibraryInformation(void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    *GDebug;
}
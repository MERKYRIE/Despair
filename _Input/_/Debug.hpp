#pragma once

#include"Blindness.hpp"

namespace NBlindness
{
    inline class CDebug
    {
        public : void OAssert
        (
            bool PCondition = true , const std::string& PMessage = "" , SDL_MessageBoxFlags PFlags = SDL_MESSAGEBOX_ERROR , const std::source_location& PLocation = std::source_location::current()
        );
        public : void OError(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool OWarning(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool OInformation(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : void OSimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void OSimpleDirectMediaLayerFlagsError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerFlagsWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerFlagsInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void OSimpleDirectMediaLayerHandleError(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerHandleWarning(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool OSimpleDirectMediaLayerHandleInformation(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : void OOpenGraphicsLibraryError(const std::source_location& PLocation = std::source_location::current());
        public : bool OOpenGraphicsLibraryWarning(const std::source_location& PLocation = std::source_location::current());
        public : bool OOpenGraphicsLibraryInformation(const std::source_location& PLocation = std::source_location::current());
        public : void OOpenAssetImportLibraryError(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool OOpenAssetImportLibraryWarning(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool OOpenAssetImportLibraryInformation(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
    }
    GDebug;
}
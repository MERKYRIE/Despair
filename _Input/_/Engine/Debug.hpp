#pragma once

#include"Engine.hpp"

namespace NBlindness::NEngine{
    inline class CDebug{
        public : void FAssert(
            bool PCondition = true ,
            const std::string& PMessage = "" ,
            SDL_MessageBoxFlags PFlags = SDL_MESSAGEBOX_ERROR ,
            const std::source_location& PLocation = std::source_location::current()
        );
        public : void FError(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool FWarning(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : bool FInformation(bool PCondition = true , const std::string& PMessage = "" , const std::source_location& PLocation = std::source_location::current());
        public : void FOpenGraphicsLibraryError(const std::source_location& PLocation = std::source_location::current());
        public : void FOpenAssetImportLibraryError(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool FOpenGraphicsLibraryWarning(const std::source_location& PLocation = std::source_location::current());
        public : bool FOpenAssetImportLibraryWarning(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : bool FOpenGraphicsLibraryInformation(const std::source_location& PLocation = std::source_location::current());
        public : bool FOpenAssetImportLibraryInformation(const void* PHandle , const std::source_location& PLocation = std::source_location::current());
        public : void FSimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : void FSimpleDirectMediaLayerHandleError(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : void FSimpleDirectMediaLayerFlagsError(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerHandleWarning(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerFlagsWarning(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerHandleInformation(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
        public : bool FSimpleDirectMediaLayerFlagsInformation(std::int32_t PValue , const std::source_location& PLocation = std::source_location::current());
    }
    GDebug;
}
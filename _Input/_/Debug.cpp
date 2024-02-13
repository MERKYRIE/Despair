#include"Debug.hpp"

namespace NBlindness{
    void CDebug::FAssert(bool PCondition , const std::string& PMessage , SDL_MessageBoxFlags PFlags , const std::source_location& PLocation){
        if(PCondition){
            if(PFlags & SDL_MESSAGEBOX_INFORMATION || SDL_ShowSimpleMessageBox(PFlags , "Debug" , (
                std::string{} +
                "File - " + PLocation.file_name() + "\n" +
                "Function - " + PLocation.function_name() + "\n" +
                "Line - " + std::to_string(PLocation.line()) + "\n" +
                "Column - " + std::to_string(PLocation.column()) + "\n" +
                PMessage
            ).data() , nullptr) < 0){
                std::cout << "Debug:" << "\n"
                          << "    File - " << PLocation.file_name() << "\n"
                          << "    Function - " << PLocation.function_name() << "\n"
                          << "    Line - " << PLocation.line() << "\n"
                          << "    Column - " << PLocation.column() << "\n"
                          << PMessage << "\n\n";
            }
            if(PFlags & SDL_MESSAGEBOX_ERROR){
                std::exit(0);
            }
        }
    }

    void CDebug::FError(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        FAssert(PCondition , PMessage , SDL_MESSAGEBOX_ERROR , PLocation);
    }

    bool CDebug::FWarning(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        FAssert(PCondition , PMessage , SDL_MESSAGEBOX_WARNING , PLocation);
        return PCondition;
    }

    bool CDebug::FInformation(bool PCondition , const std::string& PMessage , const std::source_location& PLocation){
        FAssert(PCondition , PMessage , SDL_MESSAGEBOX_INFORMATION , PLocation);
        return PCondition;
    }

    void CDebug::FSimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation){
        FError(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation){
        return FWarning(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation){
        return FInformation(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    void CDebug::FSimpleDirectMediaLayerFlagsError(std::int32_t PValue , const std::source_location& PLocation){
        FError(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerFlagsWarning(std::int32_t PValue , const std::source_location& PLocation){
        return FWarning(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerFlagsInformation(std::int32_t PValue , const std::source_location& PLocation){
        return FInformation(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    
    void CDebug::FSimpleDirectMediaLayerHandleError(const void* PPointer , const std::source_location& PLocation){
        FError(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerHandleWarning(const void* PPointer , const std::source_location& PLocation){
        return FWarning(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    bool CDebug::FSimpleDirectMediaLayerHandleInformation(const void* PPointer , const std::source_location& PLocation){
        return FInformation(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }

    void CDebug::FOpenGraphicsLibraryError(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        FError(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }

    bool CDebug::FOpenGraphicsLibraryWarning(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        return FWarning(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }

    bool CDebug::FOpenGraphicsLibraryInformation(const std::source_location& PLocation){
        std::uint32_t LCode{glGetError()};
        return FInformation(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }

    void CDebug::FOpenAssetImportLibraryError(const void* PHandle , const std::source_location& PLocation){
        FError(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }

    bool CDebug::FOpenAssetImportLibraryWarning(const void* PHandle , const std::source_location& PLocation){
        return FWarning(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }

    bool CDebug::FOpenAssetImportLibraryInformation(const void* PHandle , const std::source_location& PLocation){
        return FInformation(!PHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
}
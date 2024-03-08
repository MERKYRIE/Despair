#include"Debug.hpp"

namespace NBlindness{
    void CDebug::IAssert(bool PCondition , const std::string& PMessage , SDL_MessageBoxFlags PFlags , const std::source_location& PLocation)
    {
        if(PCondition)
        {
            if
            (
                (PFlags & SDL_MESSAGEBOX_INFORMATION)
                ||
                SDL_ShowSimpleMessageBox
                (
                    PFlags , "Debug" ,
                    (
                        std::string{} +
                        "File - " + PLocation.file_name() + "\n" +
                        "Function - " + PLocation.function_name() + "\n" +
                        "Line - " + std::to_string(PLocation.line()) + "\n" +
                        "Column - " + std::to_string(PLocation.column()) + "\n" +
                        PMessage
                    )
                    .data() , nullptr
                )
                < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << PLocation.file_name() << "\n"
                          << "    Function - " << PLocation.function_name() << "\n"
                          << "    Line - " << PLocation.line() << "\n"
                          << "    Column - " << PLocation.column() << "\n"
                          << PMessage << "\n\n";
            }
            if(PFlags & SDL_MESSAGEBOX_ERROR)
            {
                std::exit(0);
            }
        }
    }

    void CDebug::OError(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_ERROR , PLocation);
    }
    bool CDebug::OWarning(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_WARNING , PLocation);
        return(PCondition);
    }
    bool CDebug::OInformation(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_INFORMATION , PLocation);
        return(PCondition);
    }
    void CDebug::OSimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation)
    {
        OError(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::OSimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(OWarning(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::OSimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(OInformation(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::OSimpleDirectMediaLayerMaskError(std::int32_t PValue , const std::source_location& PLocation)
    {
        OError(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::OSimpleDirectMediaLayerMaskWarning(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(OWarning(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::OSimpleDirectMediaLayerMaskInformation(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(OInformation(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::OSimpleDirectMediaLayerHandleError(const void* PPointer , const std::source_location& PLocation)
    {
        OError(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::OSimpleDirectMediaLayerHandleWarning(const void* PPointer , const std::source_location& PLocation)
    {
        return(OWarning(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::OSimpleDirectMediaLayerHandleInformation(const void* PPointer , const std::source_location& PLocation)
    {
        return(OInformation(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::OOpenGraphicsLibraryError(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        OError(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }
    bool CDebug::OOpenGraphicsLibraryWarning(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        return(OWarning(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation));
    }
    bool CDebug::OOpenGraphicsLibraryInformation(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        return(OInformation(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation));
    }
    void CDebug::OOpenAssetImportLibraryError(const void* AHandle , const std::source_location& PLocation)
    {
        OError(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
    bool CDebug::OOpenAssetImportLibraryWarning(const void* AHandle , const std::source_location& PLocation)
    {
        return(OWarning(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation));
    }
    bool CDebug::OOpenAssetImportLibraryInformation(const void* AHandle , const std::source_location& PLocation)
    {
        return(OInformation(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation));
    }
}
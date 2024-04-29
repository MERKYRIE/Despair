#include"Debug.hpp"

namespace NDespair{
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
                    PFlags
                    ,
                    "Debug"
                    ,
                    (
                        std::string{}
                        +
                        "File - " + PLocation.file_name() + "\n"
                        +
                        "Function - " + PLocation.function_name() + "\n"
                        +
                        "Line - " + std::to_string(PLocation.line()) + "\n"
                        +
                        "Column - " + std::to_string(PLocation.column()) + "\n"
                        +
                        PMessage
                    )
                    .
                    data()
                    ,
                    nullptr
                )
                <
                0
            )
            {
                std::cout
                <<
                "Debug:" << "\n"
                <<
                "    File - " << PLocation.file_name() << "\n"
                <<
                "    Function - " << PLocation.function_name() << "\n"
                <<
                "    Line - " << PLocation.line() << "\n"
                <<
                "    Column - " << PLocation.column() << "\n"
                <<
                PMessage << "\n\n";
            }
            if(PFlags & SDL_MESSAGEBOX_ERROR)
            {
                std::exit(0);
            }
        }
    }

    CDebug::CDebug()
    {
        GDebug = this;
    }
    void CDebug::AError(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_ERROR , PLocation);
    }
    bool CDebug::AWarning(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_WARNING , PLocation);
        return(PCondition);
    }
    bool CDebug::AInformation(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        IAssert(PCondition , PMessage , SDL_MESSAGEBOX_INFORMATION , PLocation);
        return(PCondition);
    }
    void CDebug::ASimpleDirectMediaLayerCodeError(std::int32_t PValue , const std::source_location& PLocation)
    {
        AError(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::ASimpleDirectMediaLayerCodeWarning(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(AWarning(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::ASimpleDirectMediaLayerCodeInformation(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(AInformation(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::ASimpleDirectMediaLayerMaskError(std::int32_t PValue , const std::source_location& PLocation)
    {
        AError(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::ASimpleDirectMediaLayerMaskWarning(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(AWarning(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::ASimpleDirectMediaLayerMaskInformation(std::int32_t PValue , const std::source_location& PLocation)
    {
        return(AInformation(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::ASimpleDirectMediaLayerHandleError(void* PPointer , const std::source_location& PLocation)
    {
        AError(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    bool CDebug::ASimpleDirectMediaLayerHandleWarning(void* PPointer , const std::source_location& PLocation)
    {
        return(AWarning(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    bool CDebug::ASimpleDirectMediaLayerHandleInformation(void* PPointer , const std::source_location& PLocation)
    {
        return(AInformation(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation));
    }
    void CDebug::AOpenGraphicsLibraryError(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        AError(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }
    bool CDebug::AOpenGraphicsLibraryWarning(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        return(AWarning(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation));
    }
    bool CDebug::AOpenGraphicsLibraryInformation(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        return(AInformation(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation));
    }
    void CDebug::AOpenAssetImportLibraryError(void* AHandle , const std::source_location& PLocation)
    {
        AError(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
    bool CDebug::AOpenAssetImportLibraryWarning(void* AHandle , const std::source_location& PLocation)
    {
        return(AWarning(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation));
    }
    bool CDebug::AOpenAssetImportLibraryInformation(void* AHandle , const std::source_location& PLocation)
    {
        return(AInformation(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation));
    }
}
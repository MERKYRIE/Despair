#include"Debug.hpp"

namespace NDespair{
    std::string CDebug::IAssert(const std::string& PMessage , const std::source_location& PLocation)
    {
        return
        (
            std::string{}
            +
            "File - " + PLocation.file_name() + "\n"
            +
            "Function - " + PLocation.function_name() + "\n"
            +
            "Line - " + std::to_string(PLocation.line()) + "\n"
            +
            "Column - " + std::to_string(PLocation.column()) + (!PMessage.empty() ? "\n" + PMessage : "")
        );
    }
    
    CDebug::CDebug()
    {
        GDebug = this;
    }
    void CDebug::AAssert(bool PCondition , const std::string& PMessage , const std::source_location& PLocation)
    {
        if(PCondition)
        {
            if(SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR , "Debug" , IAssert(PMessage , PLocation).data() , nullptr) < 0)
            {
                std::cout << "Debug:" << "\n"
                <<
                IAssert(PMessage , PLocation) << "\n\n";
            }
            std::exit(0);
        }
    }
    void CDebug::AAssertSimpleDirectMediaLayerCode(std::int32_t PValue , const std::source_location& PLocation)
    {
        AAssert(PValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    void CDebug::AAssertSimpleDirectMediaLayerMask(std::int32_t PValue , const std::source_location& PLocation)
    {
        AAssert(!PValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    void CDebug::AAssertSimpleDirectMediaLayerHandle(void* PPointer , const std::source_location& PLocation)
    {
        AAssert(!PPointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , PLocation);
    }
    void CDebug::AAssertOpenGraphicsLibrary(const std::source_location& PLocation)
    {
        std::uint32_t LCode{glGetError()};
        AAssert(LCode , std::string{} + "Open Graphics Library - " + std::to_string(LCode) , PLocation);
    }
    void CDebug::AAssertOpenAssetImportLibrary(void* AHandle , const std::source_location& PLocation)
    {
        AAssert(!AHandle , std::string{} + "Open Asset Import Library - " + aiGetErrorString() , PLocation);
    }
}
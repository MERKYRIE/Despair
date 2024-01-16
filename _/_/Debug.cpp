#include "Debug.hpp"

namespace NMRKOGL
{
    void CDebug::FAssert(bool PCondition , const std::string& PMessage , SDL_MessageBoxFlags PFlags , const std::source_location& PLocation)
    {
        if(PCondition)
        {
            if(PFlags & SDL_MESSAGEBOX_INFORMATION || SDL_ShowSimpleMessageBox(PFlags , "Debug" ,
            (
                std::string{} +
                "File - " + PLocation.file_name() + "\n" +
                "Function - " + PLocation.function_name() + "\n" +
                "Line - " + std::to_string(PLocation.line()) + "\n" +
                "Column - " + std::to_string(PLocation.column()) + "\n" +
                PMessage
            ).data() , nullptr) < 0)
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
}
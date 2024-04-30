#include"Shader.hpp"

#include"Debug.hpp"

namespace NDespair::NVideo
{
    CShader::CShader(const std::string& PPath , std::uint32_t PType)
    {
        std::fstream LFile{"Shaders" + PPath , std::ios::in};
        FIdentifier = glCreateShader(PType);
        std::stringstream LStream;
        LStream << LFile.rdbuf();
        std::string LString{LStream.str()};
        char* LArray{LString.data()};
        glShaderSource(FIdentifier , 1 , &LArray , nullptr);
        glCompileShader(FIdentifier);
        std::int32_t LSuccess;
        glGetShaderiv(FIdentifier , GL_COMPILE_STATUS , &LSuccess);
        std::int32_t LLength;
        glGetShaderiv(FIdentifier , GL_INFO_LOG_LENGTH , &LLength);
        std::string LLog;
        LLog.resize(LLength);
        glGetShaderInfoLog(FIdentifier , LLength , nullptr , LLog.data());
        GDebug->AAssert(!LSuccess , "Open Graphics Library - " + LLog);
    }
    std::uint32_t CShader::AIdentifier()
    {
        return(FIdentifier);
    }
    CShader::~CShader()
    {
        glDeleteShader(FIdentifier);
        GDebug->AAssertOpenGraphicsLibrary();
    }
}
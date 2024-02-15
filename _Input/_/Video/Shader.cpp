#include"Shader.hpp"

#include"Debug.hpp"

namespace NBlindness::NVideo{
    CShader::CShader(const std::string& PPath , std::uint32_t PType){
        std::fstream LFile{"Program" + PPath , std::ios::in};
        VIdentifier = glCreateShader(PType);
        std::stringstream LStream;
        LStream << LFile.rdbuf();
        std::string LString{LStream.str()};
        char* LArray{LString.data()};
        glShaderSource(VIdentifier , 1 , &LArray , nullptr);
        glCompileShader(VIdentifier);
        std::int32_t LSuccess;
        glGetShaderiv(VIdentifier , GL_COMPILE_STATUS , &LSuccess);
        std::int32_t LLength;
        glGetShaderiv(VIdentifier , GL_INFO_LOG_LENGTH , &LLength);
        std::string LLog;
        LLog.resize(LLength);
        glGetShaderInfoLog(VIdentifier , LLength , nullptr , LLog.data());
        GDebug.FError(!LSuccess , "Open Graphics Library - " + LLog);
    }

    std::uint32_t CShader::FIdentifier() const{
        return VIdentifier;
    }

    CShader::~CShader(){
        glDeleteShader(VIdentifier);
        GDebug.FOpenGraphicsLibraryError();
    }
}
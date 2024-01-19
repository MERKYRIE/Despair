#include"Font.hpp"

#include"Font\\Character.hpp"

#include"Debug\\Assert\\Error\\SimpleDirectMediaLayer.hpp"

namespace NBlindness::NVideo::NTypeface{
    bool CFont::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CFont::CFont(const std::string& PPath){
        TTF_Font* LFont{TTF_OpenFont(PPath.c_str() , 64)};
        NDebug::NAssert::NError::GSimpleDirectMediaLayer.FHandle(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++){
            VDigits.emplace_back(new NFont::CCharacter{LFont , LDigit});
        }
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++){
            VUppercases.emplace_back(new NFont::CCharacter{LFont , LUppercase});
        }
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++){
            VUppercases.emplace_back(new NFont::CCharacter{LFont , LUppercase});
        }
        for(char LLowercase{'a'} ; LLowercase <= 'z' ; LLowercase++){
            VLowercases.emplace_back(new NFont::CCharacter{LFont , LLowercase});
        }
        TTF_CloseFont(LFont);
    }

    const NFont::CCharacter& CFont::FDigit(char PCode) const{
        return *VDigits[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('0')];
    }

    const NFont::CCharacter& CFont::FUppercase(char PCode) const{
        return *VUppercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('A')];
    }

    const NFont::CCharacter& CFont::FLowercase(char PCode) const{
        return *VLowercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('a')];
    }

    CFont::~CFont(){
        VLowercases.clear();
        VUppercases.clear();
        VDigits.clear();
    }
}
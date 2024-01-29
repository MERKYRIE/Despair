#include"Font.hpp"

#include"Character.hpp"

#include"Engine\\Debug.hpp"

namespace NBlindness::NEngine{
    bool CFont::operator==(const std::string& PPath) const{
        return VPath == PPath;
    }
    
    CFont::CFont(const std::string& PPath){
        TTF_Font* LFont{TTF_OpenFont(PPath.c_str() , 64)};
        GDebug.FSimpleDirectMediaLayerHandleError(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++){
            VDigits.emplace_back(new CCharacter{LFont , LDigit});
        }
        VDigits.shrink_to_fit();
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++){
            VUppercases.emplace_back(new CCharacter{LFont , LUppercase});
        }
        VUppercases.shrink_to_fit();
        for(char LLowercase{'a'} ; LLowercase <= 'z' ; LLowercase++){
            VLowercases.emplace_back(new CCharacter{LFont , LLowercase});
        }
        VLowercases.shrink_to_fit();
        TTF_CloseFont(LFont);
    }

    const CCharacter& CFont::FDigit(char PCode) const{
        return *VDigits[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('0')];
    }

    const CCharacter& CFont::FUppercase(char PCode) const{
        return *VUppercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('A')];
    }

    const CCharacter& CFont::FLowercase(char PCode) const{
        return *VLowercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('a')];
    }

    CFont::~CFont(){
        VLowercases.clear();
        VUppercases.clear();
        VDigits.clear();
    }
}
#include"Font.hpp"

#include"Character.hpp"

#include"Debug.hpp"

namespace NDespair::NVideo
{
    CFont::CFont(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        TTF_Font* LFont{TTF_OpenFont(PPath.c_str() , 64)};
        GDebug->AAssertSimpleDirectMediaLayerHandle(LFont);
        for(char LDigit{'0'} ; LDigit <= '9' ; LDigit++)
        {
            FDigits.emplace_back(new CCharacter{LFont , LDigit});
        }
        FDigits.shrink_to_fit();
        for(char LUppercase{'A'} ; LUppercase <= 'Z' ; LUppercase++)
        {
            FUppercases.emplace_back(new CCharacter{LFont , LUppercase});
        }
        FUppercases.shrink_to_fit();
        for(char LLowercase{'a'} ; LLowercase <= 'z' ; LLowercase++)
        {
            FLowercases.emplace_back(new CCharacter{LFont , LLowercase});
        }
        FLowercases.shrink_to_fit();
        TTF_CloseFont(LFont);
    }
    std::string CFont::APath()
    {
        return FPath;
    }
    bool CFont::AIs(const std::string& PPath)
    {
        return(FPath == PPath);
    }
    CCharacter* CFont::AAccessDigit(char PCode)
    {
        return(FDigits[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('0')].get());
    }
    CCharacter* CFont::AAccessUppercase(char PCode)
    {
        return(FUppercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('A')].get());
    }
    CCharacter* CFont::AAccessLowercase(char PCode)
    {
        return(FLowercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('a')].get());
    }
    CFont::~CFont()
    {
        FLowercases.clear();
        FUppercases.clear();
        FDigits.clear();
    }
}
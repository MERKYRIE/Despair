#include"Font.hpp"

#include"Character.hpp"

#include"Debug.hpp"

namespace NBlindness::NVideo
{
    CFont::CFont(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        TTF_Font* LFont{TTF_OpenFont(PPath.c_str() , 64)};
        GDebug.OSimpleDirectMediaLayerHandleError(LFont);
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
    bool CFont::operator==(const std::string& PPath) const
    {
        return(FPath == PPath);
    }

    const CCharacter& CFont::OAccessDigit(char PCode) const
    {
        return(*FDigits[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('0')]);
    }
    const CCharacter& CFont::OAccessUppercase(char PCode) const
    {
        return(*FUppercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('A')]);
    }
    const CCharacter& CFont::OAccessLowercase(char PCode) const
    {
        return(*FLowercases[static_cast<std::int64_t>(PCode) - static_cast<std::int64_t>('a')]);
    }
    CFont::~CFont()
    {
        FLowercases.clear();
        FUppercases.clear();
        FDigits.clear();
    }
}
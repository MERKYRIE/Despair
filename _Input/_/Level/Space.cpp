#include"Space.hpp"

#include"Translation.hpp"

#include"Video\\Atlas.hpp"

namespace NBlindness::NLevel{
    void CSpace::FInitialize(){
        std::uint32_t LFloor{NVideo::GAtlas.FTexture("\\sfloor4_5.png")};
        std::uint32_t LWall000{NVideo::GAtlas.FTexture("\\twall2_3.png")};
        std::uint32_t LWall010{NVideo::GAtlas.FTexture("\\twall2_5.png")};
        std::uint32_t LWall020{NVideo::GAtlas.FTexture("\\twall2_6.png")};
        std::uint32_t LWall110{NVideo::GAtlas.FTexture("\\twall5_3.png")};
        std::uint32_t LWall210{NVideo::GAtlas.FTexture("\\uwall1_2.png")};
        std::uint32_t LCeiling{NVideo::GAtlas.FTexture("\\plat_top1.png")};
        for(std::uintmax_t LX{0} ; LX < VValue.size() ; LX++){
            for(std::uintmax_t LY{0} ; LY < VValue[0].size() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VValue[0][0].size() ; LZ++){
                    VValue[LX][LY][LZ].VLeftward = LWall000;
                    VValue[LX][LY][LZ].VRightward = LWall000;
                    VValue[LX][LY][LZ].VBackward = LWall000;
                    VValue[LX][LY][LZ].VForward = LWall000;
                    VValue[LX][LY][LZ].VDownward = LFloor;
                    VValue[LX][LY][LZ].VUpward = LCeiling;
                }
            }
        }
        VValue[0][2][0].VForward = LWall020;
        VValue[0][2][0].VLeftward = LWall020;
        VValue[0][2][0].VRightward = LWall020;
        VValue[0][2][0].VBackward = 0;

        VValue[0][1][0].VForward = 0;         VValue[1][1][0].VForward = LWall110;  VValue[2][1][0].VForward = LWall210;
        VValue[0][1][0].VLeftward = LWall010; VValue[1][1][0].VLeftward = 0;        VValue[2][1][0].VLeftward = 0;
        VValue[0][1][0].VRightward = 0;       VValue[1][1][0].VRightward = 0;       VValue[2][1][0].VRightward = LWall210;
                                              VValue[1][1][0].VBackward = LWall110; VValue[2][1][0].VBackward = LWall210;
        VValue[0][1][0].VBackward = 0;        

        VValue[0][0][0].VForward = 0;
        VValue[0][0][0].VLeftward = LWall000;
        VValue[0][0][0].VRightward = LWall000;
        VValue[0][0][0].VBackward = LWall000;
    }

    std::uintmax_t CSpace::FWidth(){
        return VValue.size();
    }

    std::uintmax_t CSpace::FDepth(){
        return VValue[0].size();
    }

    std::uintmax_t CSpace::FHeight(){
        return VValue[0][0].size();
    }

    const CSpace::SPartition& CSpace::FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return VValue[PX][PY][PZ];
    }

    bool CSpace::FCollision(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        if(
            PX != std::clamp<std::uintmax_t>(PX , 0 , VValue.size() - 1) ||
            PY != std::clamp<std::uintmax_t>(PY , 0 , VValue[0].size() - 1) ||
            PZ != std::clamp<std::uintmax_t>(PZ , 0 , VValue[0][0].size() - 1)
        ){
            return false;
        }
        if(PX - NLevel::GTranslation.FX()){
            switch(PX - NLevel::GTranslation.FX()){
                case -1:
                    return !VValue[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VLeftward && !VValue[PX][PY][PZ].VRightward;
                break;
                case +1:
                    return !VValue[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VRightward && !VValue[PX][PY][PZ].VLeftward;
                break;
            }
        }
        if(PY - NLevel::GTranslation.FY()){
            switch(PY - NLevel::GTranslation.FY()){
                case -1:
                    return !VValue[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VBackward && !VValue[PX][PY][PZ].VForward;
                break;
                case +1:
                    return !VValue[NLevel::GTranslation.FX()][NLevel::GTranslation.FY()][NLevel::GTranslation.FZ()].VForward && !VValue[PX][PY][PZ].VBackward;
                break;
            }
        }
        return false;
    }
}
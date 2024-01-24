#include"Space.hpp"

#include"Space\\Partition.hpp"

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
        for(std::uintmax_t LX{0} ; LX < VWidth ; LX++){
            VValue.emplace_back();
            for(std::uintmax_t LY{0} ; LY < VDepth ; LY++){
                VValue[LX].emplace_back();
                for(std::uintmax_t LZ{0} ; LZ < VHeight ; LZ++){
                    VValue[LX][LY].emplace_back(new NSpace::CPartition{LWall000 , LWall000 , LWall000 , LWall000 , LFloor , LCeiling});
                }
                VValue[LX][LY].shrink_to_fit();
            }
            VValue[LX].shrink_to_fit();
        }
        VValue.shrink_to_fit();
        VValue[0][2][0]->FPartition(LWall020 , LWall020 , 0 , LWall020 , LFloor , LCeiling);
        VValue[0][1][0]->FPartition(LWall010 , 0 , 0 , 0 , LFloor , LCeiling);               VValue[1][1][0]->FPartition(0 , 0 , LWall110 , LWall110 , LFloor , LCeiling); VValue[2][1][0]->FPartition(0 , LWall210 , LWall210 , LWall210 , LFloor , LCeiling);
        VValue[0][0][0]->FPartition(LWall000 , LWall000 , LWall000 , 0 , LFloor , LCeiling);
    }

    std::uintmax_t CSpace::FWidth(){
        return VWidth;
    }

    std::uintmax_t CSpace::FDepth(){
        return VDepth;
    }

    std::uintmax_t CSpace::FHeight(){
        return VHeight;
    }

    const NSpace::CPartition& CSpace::FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return *VValue[PX][PY][PZ];
    }
}
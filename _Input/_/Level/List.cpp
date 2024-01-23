#include"List.hpp"

#include"List\\Material.hpp"

#include"Space.hpp"
#include"Space\\Depth.hpp"
#include"Space\\Height.hpp"
#include"Space\\Partition.hpp"
#include"Space\\Width.hpp"

namespace NBlindness::NLevel{
    void CList::FInitialize(){
        VValue = glGenLists(1);
        glNewList(VValue , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < NSpace::GWidth.FValue<std::uintmax_t>() ; LX++){
            for(std::uintmax_t LY{0} ; LY < NSpace::GDepth.FValue<std::uintmax_t>() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < NSpace::GHeight.FValue<std::uintmax_t>() ; LZ++){
                    GSpace.FPartition(LX , LY , LZ).FRender(LX , LY , LZ);
                }
            }
        }
        glEndList();
        NList::GMaterial.FInitialize();
    }

    void CList::FUpdate(){
        glCallList(VValue);
    }

    void CList::FDeinitialize(){
        glDeleteLists(VValue , 1);
    }
}
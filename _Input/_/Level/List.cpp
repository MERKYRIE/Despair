#include"List.hpp"

#include"Space.hpp"
#include"Space\\Partition.hpp"

namespace NBlindness::NLevel{
    void CList::FInitialize(){
        VValue = glGenLists(1);
        glNewList(VValue , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < GSpace.FWidth() ; LX++){
            for(std::uintmax_t LY{0} ; LY < GSpace.FDepth() ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < GSpace.FHeight() ; LZ++){
                    GSpace.FPartition(LX , LY , LZ).FRender(LX , LY , LZ);
                }
            }
        }
        glEndList();
    }

    void CList::FUpdate(){
        glCallList(VValue);
    }

    void CList::FDeinitialize(){
        glDeleteLists(VValue , 1);
    }
}
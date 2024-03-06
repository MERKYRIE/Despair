#include"Partition.hpp"

#include"VertexArrayObject.hpp"

#include"Debug.hpp"
#include"Space.hpp"

namespace NBlindness::NSpace
{
    CPartition::CPartition
    (
        std::uint32_t PTextureNegativeX ,
        std::uint32_t PTexturePositiveX ,
        std::uint32_t PTextureNegativeY ,
        std::uint32_t PTexturePositiveY ,
        std::uint32_t PTextureNegativeZ ,
        std::uint32_t PTexturePositiveZ
    )
    {
        FTextureNegativeX = PTextureNegativeX;
        FTexturePositiveX = PTexturePositiveX;
        FTextureNegativeY = PTextureNegativeY;
        FTexturePositiveY = PTexturePositiveY;
        FTextureNegativeZ = PTextureNegativeZ;
        FTexturePositiveZ = PTexturePositiveZ;
    }
    bool CPartition::BCanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return PX == std::clamp<std::intmax_t>(PX , 0 , GSpace.DSizeX() - 1) &&
            PY == std::clamp<std::intmax_t>(PY , 0 , GSpace.DSizeY() - 1) &&
            PZ == std::clamp<std::intmax_t>(PZ , 0 , GSpace.DSizeZ() - 1);
    }
    bool CPartition::BGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(PX - GSpace.DPositionX())
        {
            case -1:
                if(!FTextureNegativeX && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX)
                {
                    return false;
                }
                FTextureNegativeX = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX = 0;
            return true;
            case +1:
                if(!FTexturePositiveX && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX)
                {
                    return false;
                }
                FTexturePositiveX = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX = 0;
            return true;
        }
        switch(PY - GSpace.DPositionY())
        {
            case -1:
                if(!FTextureNegativeY && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY)
                {
                    return false;
                }
                FTextureNegativeY = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY = 0;
            return true;
            case +1:
                if(!FTexturePositiveY && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY)
                {
                    return false;
                }
                FTexturePositiveY = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY = 0;
            return true;
        }
        GDebug.OError();
        return false;
    }
    bool CPartition::BCanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ){
        return (!FTextureNegativeX || !FTexturePositiveX || !FTextureNegativeY || !FTexturePositiveX) && (
            !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX ||
            !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX ||
            !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY ||
            !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX
        );
    }
    bool CPartition::BGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(PZ - GSpace.DPositionZ())
        {
            case -1:
                if(!FTextureNegativeZ && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ)
                {
                    return false;
                }
                FTextureNegativeZ = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ = 0;
            return true;
            case +1:
                if(!FTexturePositiveZ && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ)
                {
                    return false;
                }
                FTexturePositiveZ = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ = 0;
            return true;
        }
        GDebug.OError();
        return false;
    }
    void CPartition::BRender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(FTextureNegativeX)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectNegativeX()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveX)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectPositiveX()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeY)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectNegativeY()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveY)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectPositiveY()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeZ)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectNegativeZ()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveZ)
        {
            glBindVertexArray(GSpace.DVertexArrayObjectPositiveZ()->OIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
    }
    bool CPartition::BIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if
        (
            PX != std::clamp<std::intmax_t>(PX , 0 , GSpace.DSizeX() - 1) ||
            PY != std::clamp<std::intmax_t>(PY , 0 , GSpace.DSizeY() - 1) ||
            PZ != std::clamp<std::intmax_t>(PZ , 0 , GSpace.DSizeZ() - 1)
        )
        {
            return true;
        }
        switch(PX - GSpace.DPositionX())
        {
            case -1:
                return !(!FTextureNegativeX && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX);
            break;
            case +1:
                return !(!FTexturePositiveX && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX);
            break;
        }
        switch(PY - GSpace.DPositionY())
        {
            case -1:
                return !(!FTextureNegativeY && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY);
            break;
            case +1:
                return !(!FTexturePositiveY && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY);
            break;
        }
        switch(PZ - GSpace.DPositionZ())
        {
            case -1:
                return !(!FTextureNegativeZ && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ);
            break;
            case +1:
                return !(!FTexturePositiveZ && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ);
            break;
        }
        return true;
    }
}
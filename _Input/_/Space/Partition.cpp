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
    
    bool CPartition::OCanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return PX == std::clamp<std::intmax_t>(PX , 0 , GSpace.FDistanceAlongX - 1) &&
            PY == std::clamp<std::intmax_t>(PY , 0 , GSpace.FDistanceAlongY - 1) &&
            PZ == std::clamp<std::intmax_t>(PZ , 0 , GSpace.FDistanceAlongZ - 1);
    }

    bool CPartition::OGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(PX - GSpace.OAccessTranslationIntegralX())
        {
            case -1:
                if(!FTextureNegativeX && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveX)
                {
                    return false;
                }
                FTextureNegativeX = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveX = 0;
            return true;
            case +1:
                if(!FTexturePositiveX && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeX)
                {
                    return false;
                }
                FTexturePositiveX = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeX = 0;
            return true;
        }
        switch(PY - GSpace.OAccessTranslationIntegralY())
        {
            case -1:
                if(!FTextureNegativeY && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveY)
                {
                    return false;
                }
                FTextureNegativeY = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveY = 0;
            return true;
            case +1:
                if(!FTexturePositiveY && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeY)
                {
                    return false;
                }
                FTexturePositiveY = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeY = 0;
            return true;
        }
        GDebug.OError();
        return false;
    }

    bool CPartition::OCanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ){
        return (!FTextureNegativeX || !FTexturePositiveX || !FTextureNegativeY || !FTexturePositiveX) && (
            !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeX ||
            !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveX ||
            !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeY ||
            !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveX
        );
    }

    bool CPartition::OGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(PZ - GSpace.OAccessTranslationIntegralZ())
        {
            case -1:
                if(!FTextureNegativeZ && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveZ)
                {
                    return false;
                }
                FTextureNegativeZ = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveZ = 0;
            return true;
            case +1:
                if(!FTexturePositiveZ && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeZ)
                {
                    return false;
                }
                FTexturePositiveZ = 0;
                GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeZ = 0;
            return true;
        }
        GDebug.OError();
        return false;
    }

    void CPartition::ORender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(FTextureNegativeX)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectNegativeX()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveX)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectPositiveX()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeY)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectNegativeY()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveY)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectPositiveY()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeZ)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectNegativeZ()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveZ)
        {
            glBindVertexArray(GSpace.OVertexArrayObjectPositiveZ()->OAccessIdentifier());
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
    }

    bool CPartition::OIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if
        (
            PX != std::clamp<std::intmax_t>(PX , 0 , GSpace.FDistanceAlongX - 1) ||
            PY != std::clamp<std::intmax_t>(PY , 0 , GSpace.FDistanceAlongY - 1) ||
            PZ != std::clamp<std::intmax_t>(PZ , 0 , GSpace.FDistanceAlongZ - 1)
        )
        {
            return true;
        }
        switch(PX - GSpace.OAccessTranslationIntegralX())
        {
            case -1:
                return !(!FTextureNegativeX && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveX);
            break;
            case +1:
                return !(!FTexturePositiveX && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeX);
            break;
        }
        switch(PY - GSpace.OAccessTranslationIntegralY())
        {
            case -1:
                return !(!FTextureNegativeY && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveY);
            break;
            case +1:
                return !(!FTexturePositiveY && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeY);
            break;
        }
        switch(PZ - GSpace.OAccessTranslationIntegralZ())
        {
            case -1:
                return !(!FTextureNegativeZ && !GSpace.OAccessPartition(PX , PY , PZ).FTexturePositiveZ);
            break;
            case +1:
                return !(!FTexturePositiveZ && !GSpace.OAccessPartition(PX , PY , PZ).FTextureNegativeZ);
            break;
        }
        return true;
    }
}
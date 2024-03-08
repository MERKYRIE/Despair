#include"Partition.hpp"

#include"VertexArrayObject.hpp"

#include"Debug.hpp"
#include"Space.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"

namespace NBlindness::NSpace
{
    CPartition::CPartition()
    {
        FTextureNegativeX = GVideo.OAccessRandomTexture().OIdentifier();
        FTexturePositiveX = GVideo.OAccessRandomTexture().OIdentifier();
        FTextureNegativeY = GVideo.OAccessRandomTexture().OIdentifier();
        FTexturePositiveY = GVideo.OAccessRandomTexture().OIdentifier();
        FTextureNegativeZ = GVideo.OAccessRandomTexture().OIdentifier();
        FTexturePositiveZ = GVideo.OAccessRandomTexture().OIdentifier();
    }
    bool CPartition::BCanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return(GSpace.DDoesPartitionExist(PX , PY , PZ));
    }
    bool CPartition::BGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(GSpace.DEvaluateOffsetX(PX))
        {
            case(-1):
                if(!FTextureNegativeX && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX)
                {
                    return(false);
                }
                FTextureNegativeX = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveX && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX)
                {
                    return(false);
                }
                FTexturePositiveX = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX = 0;
            return(true);
        }
        switch(GSpace.DEvaluateOffsetY(PY))
        {
            case(-1):
                if(!FTextureNegativeY && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY)
                {
                    return(false);
                }
                FTextureNegativeY = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveY && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY)
                {
                    return(false);
                }
                FTexturePositiveY = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY = 0;
            return(true);
        }
        GDebug.OError();
        return(false);
    }
    bool CPartition::BCanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ){
        return
        (
            (!FTextureNegativeX || !FTexturePositiveX || !FTextureNegativeY || !FTexturePositiveX) &&
            (
                !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX ||
                !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX ||
                !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY ||
                !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX
            )
        );
    }
    bool CPartition::BGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(GSpace.DEvaluateOffsetZ(PZ))
        {
            case(-1):
                if(!FTextureNegativeZ && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ)
                {
                    return(false);
                }
                FTextureNegativeZ = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveZ && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ)
                {
                    return(false);
                }
                FTexturePositiveZ = 0;
                GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ = 0;
            return(true);
        }
        GDebug.OError();
        return(false);
    }
    void CPartition::BRender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(FTextureNegativeX)
        {
            GSpace.DBindVertexArrayObjectNegativeX();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveX)
        {
            GSpace.DBindVertexArrayObjectPositiveX();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeY)
        {
            GSpace.DBindVertexArrayObjectNegativeY();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveY)
        {
            GSpace.DBindVertexArrayObjectPositiveY();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeZ)
        {
            GSpace.DBindVertexArrayObjectNegativeZ();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveZ)
        {
            GSpace.DBindVertexArrayObjectPositiveZ();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
    }
    bool CPartition::BIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(!GSpace.DDoesPartitionExist(PX , PY , PZ))
        {
            return(true);
        }
        switch(GSpace.DEvaluateOffsetX(PX))
        {
            case(-1):
                return(!(!FTextureNegativeX && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveX));
            break;
            case(+1):
                return(!(!FTexturePositiveX && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeX));
            break;
        }
        switch(GSpace.DEvaluateOffsetY(PY))
        {
            case(-1):
                return(!(!FTextureNegativeY && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveY));
            break;
            case(+1):
                return(!(!FTexturePositiveY && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeY));
            break;
        }
        switch(GSpace.DEvaluateOffsetZ(PZ))
        {
            case(-1):
                return(!(!FTextureNegativeZ && !GSpace.DAccessPartition(PX , PY , PZ).FTexturePositiveZ));
            break;
            case(+1):
                return(!(!FTexturePositiveZ && !GSpace.DAccessPartition(PX , PY , PZ).FTextureNegativeZ));
            break;
        }
        return(true);
    }
}
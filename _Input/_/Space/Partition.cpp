#include"Partition.hpp"

#include"VertexArrayObject.hpp"

#include"Debug.hpp"
#include"Space.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"

namespace NDespair::NSpace
{
    CPartition::CPartition()
    {
        FTextureNegativeX = GVideo.AAccessRandomTexture()->AIdentifier();
        FTexturePositiveX = GVideo.AAccessRandomTexture()->AIdentifier();
        FTextureNegativeY = GVideo.AAccessRandomTexture()->AIdentifier();
        FTexturePositiveY = GVideo.AAccessRandomTexture()->AIdentifier();
        FTextureNegativeZ = GVideo.AAccessRandomTexture()->AIdentifier();
        FTexturePositiveZ = GVideo.AAccessRandomTexture()->AIdentifier();
    }
    bool CPartition::ACanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return(GSpace.ADoesPartitionExist(PX , PY , PZ));
    }
    bool CPartition::AGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(GSpace.AEvaluateOffsetX(PX))
        {
            case(-1):
                if(!FTextureNegativeX && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveX)
                {
                    return(false);
                }
                FTextureNegativeX = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveX = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveX && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeX)
                {
                    return(false);
                }
                FTexturePositiveX = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeX = 0;
            return(true);
        }
        switch(GSpace.AEvaluateOffsetY(PY))
        {
            case(-1):
                if(!FTextureNegativeY && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveY)
                {
                    return(false);
                }
                FTextureNegativeY = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveY = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveY && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeY)
                {
                    return(false);
                }
                FTexturePositiveY = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeY = 0;
            return(true);
        }
        GDebug.AError();
        return(false);
    }
    bool CPartition::ACanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ){
        return
        (
            (!FTextureNegativeX || !FTexturePositiveX || !FTextureNegativeY || !FTexturePositiveX) &&
            (
                !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeX ||
                !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveX ||
                !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeY ||
                !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveX
            )
        );
    }
    bool CPartition::AGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(GSpace.AEvaluateOffsetZ(PZ))
        {
            case(-1):
                if(!FTextureNegativeZ && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveZ)
                {
                    return(false);
                }
                FTextureNegativeZ = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveZ = 0;
            return(true);
            case(+1):
                if(!FTexturePositiveZ && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeZ)
                {
                    return(false);
                }
                FTexturePositiveZ = 0;
                GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeZ = 0;
            return(true);
        }
        GDebug.AError();
        return(false);
    }
    void CPartition::ARender(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(FTextureNegativeX)
        {
            GSpace.ABindVertexArrayObjectNegativeX();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveX)
        {
            GSpace.ABindVertexArrayObjectPositiveX();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveX);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeY)
        {
            GSpace.ABindVertexArrayObjectNegativeY();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveY)
        {
            GSpace.ABindVertexArrayObjectPositiveY();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveY);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTextureNegativeZ)
        {
            GSpace.ABindVertexArrayObjectNegativeZ();
            glBindTexture(GL_TEXTURE_2D , FTextureNegativeZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
        if(FTexturePositiveZ)
        {
            GSpace.ABindVertexArrayObjectPositiveZ();
            glBindTexture(GL_TEXTURE_2D , FTexturePositiveZ);
            glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
        }
    }
    bool CPartition::AIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(!GSpace.ADoesPartitionExist(PX , PY , PZ))
        {
            return(true);
        }
        switch(GSpace.AEvaluateOffsetX(PX))
        {
            case(-1):
                return(!(!FTextureNegativeX && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveX));
            break;
            case(+1):
                return(!(!FTexturePositiveX && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeX));
            break;
        }
        switch(GSpace.AEvaluateOffsetY(PY))
        {
            case(-1):
                return(!(!FTextureNegativeY && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveY));
            break;
            case(+1):
                return(!(!FTexturePositiveY && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeY));
            break;
        }
        switch(GSpace.AEvaluateOffsetZ(PZ))
        {
            case(-1):
                return(!(!FTextureNegativeZ && !GSpace.AAccessPartition(PX , PY , PZ).FTexturePositiveZ));
            break;
            case(+1):
                return(!(!FTexturePositiveZ && !GSpace.AAccessPartition(PX , PY , PZ).FTextureNegativeZ));
            break;
        }
        return(true);
    }
}
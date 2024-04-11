#include"Space.hpp"

#include"Audio.hpp"
#include"Audio\\Track.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NDespair
{
    void CSpace::IReevaluatePositionXY()
    {
        FPositionX = FSizeX / 2;
        FPositionY = FSizeY / 2;
    }
    void CSpace::IReevaluatePositionZ()
    {
        FPositionZ = FSizeZ / 2;
    }
    bool CSpace::IDoesPartitionExist(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return
        (
            PX == std::clamp<std::intmax_t>(PX , 0 , FSizeX - 1)
            &&
            PY == std::clamp<std::intmax_t>(PY , 0 , FSizeY - 1)
            &&
            PZ == std::clamp<std::intmax_t>(PZ , 0 , FSizeZ - 1)
        );
    }
    std::intmax_t CSpace::IEvaluateOffsetX(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionX);
    }
    std::intmax_t CSpace::IEvaluateOffsetY(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionY);
    }
    std::intmax_t CSpace::IEvaluateOffsetZ(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionZ);
    }
    bool CSpace::ICanGenerateTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return(IDoesPartitionExist(PX , PY , PZ));
    }
    bool CSpace::IGenerateNewTransition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(IEvaluateOffsetX(PX))
        {
            case(-1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX && !FMatrix[PX][PY][PZ].FTexturePositiveX)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX = nullptr;
                FMatrix[PX][PY][PZ].FTexturePositiveX = nullptr;
            return(true);
            case(+1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX && !FMatrix[PX][PY][PZ].FTextureNegativeX)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX = nullptr;
                FMatrix[PX][PY][PZ].FTextureNegativeX = nullptr;
            return(true);
        }
        switch(IEvaluateOffsetY(PY))
        {
            case(-1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY && !FMatrix[PX][PY][PZ].FTexturePositiveY)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY = nullptr;
                FMatrix[PX][PY][PZ].FTexturePositiveY = nullptr;
            return(true);
            case(+1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveY && !FMatrix[PX][PY][PZ].FTextureNegativeY)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveY = nullptr;
                FMatrix[PX][PY][PZ].FTextureNegativeY = nullptr;
            return(true);
        }
        GDebug.AError();
        return(false);
    }
    bool CSpace::ICanGenerateShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ){
        return
        (
            (
                !FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX
                ||
                !FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX
                ||
                !FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY
                ||
                !FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX
            )
            &&
            (
                !FMatrix[PX][PY][PZ].FTextureNegativeX
                ||
                !FMatrix[PX][PY][PZ].FTexturePositiveX
                ||
                !FMatrix[PX][PY][PZ].FTextureNegativeY
                ||
                !FMatrix[PX][PY][PZ].FTexturePositiveX
            )
        );
    }
    bool CSpace::IGenerateNewShaft(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        switch(IEvaluateOffsetZ(PZ))
        {
            case(-1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeZ && !FMatrix[PX][PY][PZ].FTexturePositiveZ)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeZ = nullptr;
                FMatrix[PX][PY][PZ].FTexturePositiveZ = nullptr;
            return(true);
            case(+1):
                if(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveZ && !FMatrix[PX][PY][PZ].FTextureNegativeZ)
                {
                    return(false);
                }
                FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveZ = nullptr;
                FMatrix[PX][PY][PZ].FTextureNegativeZ = nullptr;
            return(true);
        }
        GDebug.AError();
        return(false);
    }
    bool CSpace::IIsCollisionDetected(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        if(!IDoesPartitionExist(PX , PY , PZ))
        {
            return(true);
        }
        switch(IEvaluateOffsetX(PX))
        {
            case(-1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX && !FMatrix[PX][PY][PZ].FTexturePositiveX));
            break;
            case(+1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX && !FMatrix[PX][PY][PZ].FTextureNegativeX));
            break;
        }
        switch(IEvaluateOffsetY(PY))
        {
            case(-1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY && !FMatrix[PX][PY][PZ].FTexturePositiveY));
            break;
            case(+1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveY && !FMatrix[PX][PY][PZ].FTextureNegativeY));
            break;
        }
        switch(IEvaluateOffsetZ(PZ))
        {
            case(-1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeZ && !FMatrix[PX][PY][PZ].FTexturePositiveZ));
            break;
            case(+1):
                return(!(!FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveZ && !FMatrix[PX][PY][PZ].FTextureNegativeZ));
            break;
        }
        return(true);
    }

    void CSpace::AInitialize()
    {
        FSizeX = 100;
        FSizeY = 100;
        FSizeZ = 3;
        FPositionX = FSizeX / 2;
        FPositionY = FSizeY / 2;
        FPositionZ = FSizeZ / 2;
        FDirectionX = 0;
        FDirectionY = 1;
        FVision = 10;
        FVertexArrayObjectNegativeX.reset
        (
            new NVideo::CVertexArrayObject
            {
                {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveX.reset
        (
            new NVideo::CVertexArrayObject
            {
                {1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectNegativeY.reset
        (
            new NVideo::CVertexArrayObject
            {
                {1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveY.reset
        (
            new NVideo::CVertexArrayObject
            {
                {0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectNegativeZ.reset
        (
            new NVideo::CVertexArrayObject
            {
                {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveZ.reset
        (
            new NVideo::CVertexArrayObject
            {
                {0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FMatrix.resize(FSizeX);
        for(std::intmax_t LX{0} ; LX < FSizeX ; LX++)
        {
            std::cout << "P" << LX << "\n";
            FMatrix[LX].resize(FSizeY);
            for(std::intmax_t LY{0} ; LY < FSizeY ; LY++)
            {
                FMatrix[LX][LY].resize(FSizeZ);
                for(std::intmax_t LZ{0} ; LZ < FSizeZ ; LZ++)
                {
                    FMatrix[LX][LY][LZ].FTextureNegativeX = GVideo.AAccessRandomTexture();
                    FMatrix[LX][LY][LZ].FTexturePositiveX = GVideo.AAccessRandomTexture();
                    FMatrix[LX][LY][LZ].FTextureNegativeY = GVideo.AAccessRandomTexture();
                    FMatrix[LX][LY][LZ].FTexturePositiveY = GVideo.AAccessRandomTexture();
                    FMatrix[LX][LY][LZ].FTextureNegativeZ = GVideo.AAccessRandomTexture();
                    FMatrix[LX][LY][LZ].FTexturePositiveZ = GVideo.AAccessRandomTexture();
                }
                FMatrix[LX][LY].shrink_to_fit();
            }
            FMatrix[LX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        for(FPositionZ = 0 ; FPositionZ < FSizeZ ; FPositionZ++)
        {
            std::cout << "T" << FPositionZ << "\n";
            IReevaluatePositionXY();
            std::intmax_t LGenerated{0};
            for(std::intmax_t LIteration{0} ; LIteration <= 1000 ; LIteration += LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LDistance{3 , 5};
                std::intmax_t LRequested{LDistance(LGenerator)};
                std::uniform_int_distribution<std::intmax_t> LDirection{0 , 3};
                switch(LDirection(LGenerator))
                {
                    case(0):
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if(ICanGenerateTransition(FPositionX + 1 , FPositionY , FPositionZ))
                            {
                                LGenerated += IGenerateNewTransition(FPositionX + 1 , FPositionY , FPositionZ);
                                FPositionX++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case(1):
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if(ICanGenerateTransition(FPositionX , FPositionY + 1 , FPositionZ))
                            {
                                LGenerated += IGenerateNewTransition(FPositionX , FPositionY + 1 , FPositionZ);
                                FPositionY++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case(2):
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if(ICanGenerateTransition(FPositionX - 1 , FPositionY , FPositionZ))
                            {
                                LGenerated += IGenerateNewTransition(FPositionX - 1 , FPositionY , FPositionZ);
                                FPositionX--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case(3):
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if(ICanGenerateTransition(FPositionX , FPositionY - 1 , FPositionZ))
                            {
                                LGenerated += IGenerateNewTransition(FPositionX , FPositionY - 1 , FPositionZ);
                                FPositionY--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                }
            }
        }
        IReevaluatePositionZ();
        for(std::intmax_t LIteration{0} ; LIteration <= 9 ; LIteration++)
        {
            std::cout << "D" << LIteration << "\n";
            bool LGenerated{false};
            while(!LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LX{0 , FSizeX - 1};
                std::uniform_int_distribution<std::intmax_t> LY{0 , FSizeY - 1};
                FPositionX = LX(LGenerator);
                FPositionY = LY(LGenerator);
                if(ICanGenerateShaft(FPositionX , FPositionY , FPositionZ - 1))
                {
                    LGenerated = IGenerateNewShaft(FPositionX , FPositionY , FPositionZ - 1);
                }
            }
        }
        IReevaluatePositionZ();
        for(std::intmax_t LIteration{0} ; LIteration <= 9 ; LIteration++)
        {
            std::cout << "A" << LIteration << "\n";
            bool LGenerated{false};
            while(!LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LX{0 , FSizeX - 1};
                std::uniform_int_distribution<std::intmax_t> LY{0 , FSizeY - 1};
                FPositionX = LX(LGenerator);
                FPositionY = LY(LGenerator);
                if(ICanGenerateShaft(FPositionX , FPositionY , FPositionZ + 1))
                {
                    LGenerated = IGenerateNewShaft(FPositionX , FPositionY , FPositionZ + 1);
                }
            }
        }
        IReevaluatePositionXY();
        IReevaluatePositionZ();
        GAudio.AAccessTrack("\\Mountain Realm - Grayshadow Ruins.mp3")->AAccessVolume(16)->APlay();
    }
    void CSpace::AUpdate()
    {
        if(GInput.AIsKeyPressed(SDL_SCANCODE_A))
        {
            std::swap(FDirectionX , FDirectionY);
            if(FDirectionX)
            {
                FDirectionX *= -1;
            }
        }
        if(GInput.AIsKeyPressed(SDL_SCANCODE_D))
        {
            std::swap(FDirectionX , FDirectionY);
            if(FDirectionY)
            {
                FDirectionY *= -1;
            }
        }
        if(GInput.AIsKeyPressed(SDL_SCANCODE_S))
        {
            if(!IIsCollisionDetected(FPositionX - FDirectionX , FPositionY - FDirectionY , FPositionZ))
            {
                FPositionX -= FDirectionX;
                FPositionY -= FDirectionY;
                if(!IIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FPositionZ--;
                }
            }
        }
        if(GInput.AIsKeyPressed(SDL_SCANCODE_W))
        {
            if(!IIsCollisionDetected(FPositionX + FDirectionX , FPositionY + FDirectionY , FPositionZ))
            {
                FPositionX += FDirectionX;
                FPositionY += FDirectionY;
                if(!IIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FPositionZ--;
                }
            }
        }
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.ARatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::rotate
        (
            LView
            ,
            glm::radians
            (
                static_cast<float>
                (
                    -std::round(std::acos(FDirectionX ? FDirectionX : 1) * 180.0F / std::numbers::pi_v<float> + std::asin(FDirectionY ? FDirectionY : 0) * 180.0F / std::numbers::pi_v<float> - 90.0F)
                )
            )
            ,
            glm::vec3{0.0F , 0.0F , 1.0F}
        );
        LView = glm::translate(LView , -glm::vec3{FPositionX + 0.5F , FPositionY + 0.5F , FPositionZ + 0.5F});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        for
        (
            std::intmax_t LX{std::clamp<std::intmax_t>(FPositionX - FVision , 0 , FSizeX - 1)}
            ;
            LX <= std::clamp<std::intmax_t>(FPositionX + FVision , 0 , FSizeX - 1)
            ;
            LX++
        )
        {
            for
            (
                std::intmax_t LY{std::clamp<std::intmax_t>(FPositionY - FVision , 0 , FSizeY - 1)}
                ;
                LY <= std::clamp<std::intmax_t>(FPositionY + FVision , 0 , FSizeY - 1)
                ;
                LY++
            )
            {
                for
                (
                    std::intmax_t LZ{std::clamp<std::intmax_t>(FPositionZ - FVision , 0 , FSizeZ - 1)}
                    ;
                    LZ <= std::clamp<std::intmax_t>(FPositionZ + FVision , 0 , FSizeZ - 1)
                    ;
                    LZ++
                )
                {
                    glUniform1f(7 , std::clamp(0.2F / glm::distance(glm::vec3{FPositionX , FPositionY , FPositionZ} , glm::vec3{LX , LY , LZ}) , 0.0F , 0.4F));
                    glm::mat4 LModel{1.0F};
                    LModel = glm::translate(LModel , glm::vec3{LX , LY , LZ});
                    glUniformMatrix4fv(5 , 1 , GL_FALSE , &LModel[0][0]);
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX)
                    {
                        glBindVertexArray(FVertexArrayObjectNegativeX->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeX->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX)
                    {
                        glBindVertexArray(FVertexArrayObjectPositiveX->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveX->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY)
                    {
                        glBindVertexArray(FVertexArrayObjectNegativeY->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeY->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveY)
                    {
                        glBindVertexArray(FVertexArrayObjectPositiveY->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveY->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeZ)
                    {
                        glBindVertexArray(FVertexArrayObjectNegativeZ->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTextureNegativeZ->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveZ)
                    {
                        glBindVertexArray(FVertexArrayObjectPositiveZ->AIdentifier());
                        glBindTexture(GL_TEXTURE_2D , FMatrix[FPositionX][FPositionY][FPositionZ].FTexturePositiveZ->AIdentifier());
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                }
            }
        }
    }
    void CSpace::ADeinitialize()
    {
        FVertexArrayObjectPositiveZ.reset();
        FVertexArrayObjectNegativeZ.reset();
        FVertexArrayObjectPositiveY.reset();
        FVertexArrayObjectNegativeY.reset();
        FVertexArrayObjectPositiveX.reset();
        FVertexArrayObjectNegativeX.reset();
    }
}
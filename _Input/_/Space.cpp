#include"Space.hpp"

#include"Audio.hpp"
#include"Audio\\Track.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Video.hpp"
#include"Space\\Partition.hpp"
#include"Space\\VertexArrayObject.hpp"

namespace NBlindness
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

    void CSpace::BInitialize()
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
            new NSpace::CVertexArrayObject
            {
                {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveX.reset
        (
            new NSpace::CVertexArrayObject
            {
                {1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectNegativeY.reset
        (
            new NSpace::CVertexArrayObject
            {
                {1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveY.reset
        (
            new NSpace::CVertexArrayObject
            {
                {0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectNegativeZ.reset
        (
            new NSpace::CVertexArrayObject
            {
                {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F} , {0 , 1 , 2 , 2 , 3 , 0}
            }
        );
        FVertexArrayObjectPositiveZ.reset
        (
            new NSpace::CVertexArrayObject
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
                    FMatrix[LX][LY][LZ].reset(new NSpace::CPartition);
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
                            if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition(FPositionX + 1 , FPositionY , FPositionZ))
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition(FPositionX + 1 , FPositionY , FPositionZ);
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
                            if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition(FPositionX , FPositionY + 1 , FPositionZ))
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition(FPositionX , FPositionY + 1 , FPositionZ);
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
                            if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition(FPositionX - 1 , FPositionY , FPositionZ))
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition(FPositionX - 1 , FPositionY , FPositionZ);
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
                            if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition(FPositionX , FPositionY - 1 , FPositionZ))
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition(FPositionX , FPositionY - 1 , FPositionZ);
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
                if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateShaft(FPositionX , FPositionY , FPositionZ - 1))
                {
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewShaft(FPositionX , FPositionY , FPositionZ - 1);
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
                if(FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateShaft(FPositionX , FPositionY , FPositionZ + 1))
                {
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewShaft(FPositionX , FPositionY , FPositionZ + 1);
                }
            }
        }
        IReevaluatePositionXY();
        IReevaluatePositionZ();
        GAudio.OAccessTrack("\\Mountain Realm - Grayshadow Ruins.mp3").OAccessVolume(16).OPlay();
    }
    void CSpace::BUpdate()
    {
        if(GInput.OIsKeyPressed(SDL_SCANCODE_A))
        {
            std::swap(FDirectionX , FDirectionY);
            if(FDirectionX)
            {
                FDirectionX *= -1;
            }
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_D))
        {
            std::swap(FDirectionX , FDirectionY);
            if(FDirectionY)
            {
                FDirectionY *= -1;
            }
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_S))
        {
            if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX - FDirectionX , FPositionY - FDirectionY , FPositionZ))
            {
                FPositionX -= FDirectionX;
                FPositionY -= FDirectionY;
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FPositionZ--;
                }
            }
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_W))
        {
            if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX + FDirectionX , FPositionY + FDirectionY , FPositionZ))
            {
                FPositionX += FDirectionX;
                FPositionY += FDirectionY;
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FPositionZ--;
                }
            }
        }
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.ORatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::rotate
        (
            LView ,
            glm::radians
            (
                static_cast<float>
                (
                    -std::round(std::acos(FDirectionX ? FDirectionX : 1) * 180.0F / std::numbers::pi_v<float> + std::asin(FDirectionY ? FDirectionY : 0) * 180.0F / std::numbers::pi_v<float> - 90.0F)
                )
            ) ,
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
                    FMatrix[LX][LY][LZ]->BRender(LX , LY , LZ);
                }
            }
        }
    }
    void CSpace::BDeinitialize()
    {
        FVertexArrayObjectPositiveZ.reset();
        FVertexArrayObjectNegativeZ.reset();
        FVertexArrayObjectPositiveY.reset();
        FVertexArrayObjectNegativeY.reset();
        FVertexArrayObjectPositiveX.reset();
        FVertexArrayObjectNegativeX.reset();
        FMatrix.clear();
    }

    NSpace::CPartition& CSpace::DAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return(*FMatrix[PX][PY][PZ]);
    }
    bool CSpace::DDoesPartitionExist(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return
        (
            PX == std::clamp<std::intmax_t>(PX , 0 , FSizeX - 1) &&
            PY == std::clamp<std::intmax_t>(PY , 0 , FSizeY - 1) &&
            PZ == std::clamp<std::intmax_t>(PZ , 0 , FSizeZ - 1)
        );
    }
    std::intmax_t CSpace::DEvaluateOffsetX(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionX);
    }
    std::intmax_t CSpace::DEvaluateOffsetY(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionY);
    }
    std::intmax_t CSpace::DEvaluateOffsetZ(std::intmax_t PCoordinate)
    {
        return(PCoordinate - FPositionZ);
    }
    void CSpace::DBindVertexArrayObjectNegativeX()
    {
        glBindVertexArray(FVertexArrayObjectNegativeX->OIdentifier());
    }
    void CSpace::DBindVertexArrayObjectPositiveX()
    {
        glBindVertexArray(FVertexArrayObjectPositiveX->OIdentifier());
    }
    void CSpace::DBindVertexArrayObjectNegativeY()
    {
        glBindVertexArray(FVertexArrayObjectNegativeY->OIdentifier());
    }
    void CSpace::DBindVertexArrayObjectPositiveY()
    {
        glBindVertexArray(FVertexArrayObjectPositiveY->OIdentifier());
    }
    void CSpace::DBindVertexArrayObjectNegativeZ()
    {
        glBindVertexArray(FVertexArrayObjectNegativeZ->OIdentifier());
    }
    void CSpace::DBindVertexArrayObjectPositiveZ()
    {
        glBindVertexArray(FVertexArrayObjectPositiveZ->OIdentifier());
    }
}
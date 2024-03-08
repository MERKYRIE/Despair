#include"Space.hpp"

#include"Audio.hpp"
#include"Audio\\Track.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"
#include"Space\\Partition.hpp"
#include"Space\\VertexArrayObject.hpp"

namespace NBlindness
{
    void CSpace::IReevaluateDirection()
    {
        FDirectionX = static_cast<std::int8_t>(std::round(+std::cos((90.0F + FRotation) * std::numbers::pi_v<float> / 180.0F)));
        FDirectionY = static_cast<std::int8_t>(std::round(+std::sin((90.0F + FRotation) * std::numbers::pi_v<float> / 180.0F)));
    }
    void CSpace::IReevaluatePositionXY()
    {
        FPositionX = static_cast<std::intmax_t>(std::round(FTranslationX - 0.5F));
        FPositionY = static_cast<std::intmax_t>(std::round(FTranslationY - 0.5F));
    }
    void CSpace::IReevaluatePositionZ()
    {
        FPositionZ = static_cast<std::intmax_t>(std::round(FTranslationZ - 0.5F));
    }
    
    void CSpace::BInitialize()
    {
        FSizeX = 100;
        FSizeY = 100;
        FSizeZ = 3;
        FTranslationX = 0.5F;
        FTranslationY = 0.5F;
        FTranslationZ = 1.5F;
        FRotation = 0.0F;
        IReevaluateDirection();
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
        FVision = 10;
        std::uint32_t LTextureNegativeX{GVideo.OAccessTexture("\\twall2_5.png").OIdentifier()};
        std::uint32_t LTexturePositiveX{GVideo.OAccessTexture("\\twall2_6.png").OIdentifier()};
        std::uint32_t LTextureNegativeY{GVideo.OAccessTexture("\\twall5_3.png").OIdentifier()};
        std::uint32_t LTexturePositiveY{GVideo.OAccessTexture("\\uwall1_2.png").OIdentifier()};
        std::uint32_t LTextureNegativeZ{GVideo.OAccessTexture("\\sfloor4_5.png").OIdentifier()};
        std::uint32_t LTexturePositiveZ{GVideo.OAccessTexture("\\plat_top1.png").OIdentifier()};
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
                    FMatrix[LX][LY][LZ].reset(new NSpace::CPartition{LTextureNegativeX , LTexturePositiveX , LTextureNegativeY , LTexturePositiveY , LTextureNegativeZ , LTexturePositiveZ});
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
                    case 0:
                        LGenerated = 0;
                        while(LGenerated < LRequested){
                            if
                            (
                                FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition
                                (
                                    FPositionX + 1 , FPositionY , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition
                                (
                                    FPositionX + 1 , FPositionY , FPositionZ
                                );
                                FPositionX++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case 1:
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if
                            (
                                FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition
                                (
                                    FPositionX , FPositionY + 1 , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition
                                (
                                    FPositionX , FPositionY + 1 , FPositionZ
                                );
                                FPositionY++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case 2:
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if
                            (
                                FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition
                                (
                                    FPositionX - 1 , FPositionY , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition
                                (
                                    FPositionX - 1 , FPositionY , FPositionZ
                                );
                                FPositionX--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    break;
                    case 3:
                        LGenerated = 0;
                        while(LGenerated < LRequested)
                        {
                            if
                            (
                                FMatrix[FPositionX][FPositionY][FPositionZ]->BCanGenerateTransition
                                (
                                    FPositionX , FPositionY - 1 , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewTransition
                                (
                                    FPositionX , FPositionY - 1 , FPositionZ
                                );
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
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewShaft
                    (
                        FPositionX , FPositionY , FPositionZ - 1
                    );
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
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->BGenerateNewShaft
                    (
                        FPositionX , FPositionY , FPositionZ + 1
                    );
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
            FRotation += 90.0F;
            if(FRotation >= 360.0F)
            {
                FRotation -= 360.0F;
            }
            IReevaluateDirection();
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_D))
        {
            FRotation -= 90.0F;
            if(FRotation < 0.0F)
            {
                FRotation += 360.0F;
            }
            IReevaluateDirection();
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_S))
        {
            if
            (
                !FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected
                (
                    FPositionX - FDirectionX , FPositionY - FDirectionY , FPositionZ
                )
            )
            {
                FTranslationX -= FDirectionX;
                FTranslationY -= FDirectionY;
                IReevaluatePositionXY();
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FTranslationZ--;
                    IReevaluatePositionZ();
                }
            }
        }
        if(GInput.OIsKeyPressed(SDL_SCANCODE_W))
        {
            if
            (
                !FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected
                (
                    FPositionX + FDirectionX , FPositionY + FDirectionY , FPositionZ
                )
            )
            {
                FTranslationX += FDirectionX;
                FTranslationY += FDirectionY;
                IReevaluatePositionXY();
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->BIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FTranslationZ--;
                    IReevaluatePositionZ();
                }
            }
        }
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.ORatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::rotate(LView , glm::radians(-FRotation) , glm::vec3{0.0F , 0.0F , 1.0F});
        LView = glm::translate(LView , -glm::vec3{FTranslationX , FTranslationY , FTranslationZ});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        for
        (
            std::intmax_t LX{std::clamp<std::intmax_t>(FPositionX - FVision , 0 , FSizeX - 1)}
            ;
            LX < std::clamp<std::intmax_t>(FPositionX + FVision , 0 , FSizeX - 1)
            ;
            LX++
        )
        {
            for
            (
                std::intmax_t LY{std::clamp<std::intmax_t>(FPositionY - FVision , 0 , FSizeY - 1)}
                ;
                LY < std::clamp<std::intmax_t>(FPositionY + FVision , 0 , FSizeY - 1)
                ;
                LY++
            )
            {
                for
                (
                    std::intmax_t LZ{std::clamp<std::intmax_t>(FPositionZ - FVision , 0 , FSizeZ - 1)}
                    ;
                    LZ < std::clamp<std::intmax_t>(FPositionZ + FVision , 0 , FSizeZ - 1)
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
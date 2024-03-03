#include"Space.hpp"

#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Track.hpp"
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
    
    void CSpace::AInitialize()
    {
        FDistanceAlongX = 100;
        FDistanceAlongY = 100;
        FDistanceAlongZ = 3;
        FRotation = 0.0F;
        IReevaluateDirection();
        FTranslationX = 0.5F;
        FTranslationY = 0.5F;
        FTranslationZ = 1.5F;
        std::uint32_t LTextureNegativeX{GVideo.OAccessTexture("\\twall2_5.png").OAccessIdentifier()};
        std::uint32_t LTexturePositiveX{GVideo.OAccessTexture("\\twall2_6.png").OAccessIdentifier()};
        std::uint32_t LTextureNegativeY{GVideo.OAccessTexture("\\twall5_3.png").OAccessIdentifier()};
        std::uint32_t LTexturePositiveY{GVideo.OAccessTexture("\\uwall1_2.png").OAccessIdentifier()};
        std::uint32_t LTextureNegativeZ{GVideo.OAccessTexture("\\sfloor4_5.png").OAccessIdentifier()};
        std::uint32_t LTexturePositiveZ{GVideo.OAccessTexture("\\plat_top1.png").OAccessIdentifier()};
        FMatrix.resize(FDistanceAlongX);
        for(std::intmax_t LX{0} ; LX < FDistanceAlongX ; LX++)
        {
            FMatrix[LX].resize(FDistanceAlongY);
            for(std::intmax_t LY{0} ; LY < FDistanceAlongY ; LY++)
            {
                FMatrix[LX][LY].resize(FDistanceAlongZ);
                for(std::intmax_t LZ{0} ; LZ < FDistanceAlongZ ; LZ++)
                {
                    std::cout << "Partition - " << LX << "." << LY << "." << LZ << "\n";
                    FMatrix[LX][LY][LZ].reset(new NSpace::CPartition{LTextureNegativeX , LTexturePositiveX , LTextureNegativeY , LTexturePositiveY , LTextureNegativeZ , LTexturePositiveZ});
                }
                FMatrix[LX][LY].shrink_to_fit();
            }
            FMatrix[LX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        for(FPositionZ = 0 ; FPositionZ < FDistanceAlongZ ; FPositionZ++)
        {
            IReevaluatePositionXY();
            std::intmax_t LGenerated{0};
            for(std::intmax_t LIteration{0} ; LIteration <= 1000 ; LIteration += LGenerated)
            {
                std::cout << "Transition - " << FPositionZ << "." << LIteration << "\n";
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
                                FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateTransition
                                (
                                    FPositionX + 1 , FPositionY , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewTransition
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
                                FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateTransition
                                (
                                    FPositionX , FPositionY + 1 , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewTransition
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
                                FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateTransition
                                (
                                    FPositionX - 1 , FPositionY , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewTransition
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
                                FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateTransition
                                (
                                    FPositionX , FPositionY - 1 , FPositionZ
                                )
                            )
                            {
                                LGenerated += FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewTransition
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
            std::cout << "Descent - " << LIteration << "\n";
            bool LGenerated{false};
            while(!LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LX{0 , FDistanceAlongX - 1};
                std::uniform_int_distribution<std::intmax_t> LY{0 , FDistanceAlongY - 1};
                FPositionX = LX(LGenerator);
                FPositionY = LY(LGenerator);
                if(FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateShaft(FPositionX , FPositionY , FPositionZ - 1))
                {
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewShaft
                    (
                        FPositionX , FPositionY , FPositionZ - 1
                    );
                }
            }
        }
        IReevaluatePositionZ();
        for(std::intmax_t LIteration{0} ; LIteration <= 9 ; LIteration++)
        {
            std::cout << "Ascent - " << LIteration << "\n";
            bool LGenerated{false};
            while(!LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LX{0 , FDistanceAlongX - 1};
                std::uniform_int_distribution<std::intmax_t> LY{0 , FDistanceAlongY - 1};
                FPositionX = LX(LGenerator);
                FPositionY = LY(LGenerator);
                if(FMatrix[FPositionX][FPositionY][FPositionZ]->OCanGenerateShaft(FPositionX , FPositionY , FPositionZ + 1))
                {
                    LGenerated = FMatrix[FPositionX][FPositionY][FPositionZ]->OGenerateNewShaft
                    (
                        FPositionX , FPositionY , FPositionZ + 1
                    );
                }
            }
        }
        IReevaluatePositionXY();
        IReevaluatePositionZ();
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
        GAudio.OAccessTrack("\\Mountain Realm - Grayshadow Ruins.mp3").OModifyVolume(16).OPlay();
    }

    void CSpace::AUpdate()
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
                !FMatrix[FPositionX][FPositionY][FPositionZ]->OIsCollisionDetected
                (
                    FPositionX - FDirectionX , FPositionY - FDirectionY , FPositionZ
                )
            )
            {
                FTranslationX -= FDirectionX;
                FTranslationY -= FDirectionY;
                IReevaluatePositionXY();
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->OIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
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
                !FMatrix[FPositionX][FPositionY][FPositionZ]->OIsCollisionDetected
                (
                    FPositionX + FDirectionX , FPositionY + FDirectionY , FPositionZ
                )
            )
            {
                FTranslationX += FDirectionX;
                FTranslationY += FDirectionY;
                IReevaluatePositionXY();
                if(!FMatrix[FPositionX][FPositionY][FPositionZ]->OIsCollisionDetected(FPositionX , FPositionY , FPositionZ - 1))
                {
                    FTranslationZ--;
                    IReevaluatePositionZ();
                }
            }
        }
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.OAccessRatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::rotate(LView , glm::radians(-FRotation) , glm::vec3{0.0F , 0.0F , 1.0F});
        LView = glm::translate(LView , -glm::vec3{FTranslationX , FTranslationY , FTranslationZ});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        for
        (
            std::intmax_t LX{std::clamp<std::intmax_t>(FPositionX - 10 , 0 , FDistanceAlongX - 1)}
            ;
            LX < std::clamp<std::intmax_t>(FPositionX + 10 , 0 , FDistanceAlongX - 1)
            ;
            LX++
        )
        {
            for
            (
                std::intmax_t LY{std::clamp<std::intmax_t>(FPositionY - 10 , 0 , FDistanceAlongY - 1)}
                ;
                LY < std::clamp<std::intmax_t>(FPositionY + 10 , 0 , FDistanceAlongY - 1)
                ;
                LY++
            )
            {
                for
                (
                    std::intmax_t LZ{std::clamp<std::intmax_t>(FPositionZ - 10 , 0 , FDistanceAlongZ - 1)}
                    ;
                    LZ < std::clamp<std::intmax_t>(FPositionZ + 10 , 0 , FDistanceAlongZ - 1)
                    ;
                    LZ++
                )
                {
                    glUniform1f(7 , std::clamp(0.2F / glm::distance(glm::vec3{FPositionX , FPositionY , FPositionZ} , glm::vec3{LX , LY , LZ}) , 0.0F , 0.4F));
                    glm::mat4 LModel{1.0F};
                    LModel = glm::translate(LModel , glm::vec3{LX , LY , LZ});
                    glUniformMatrix4fv(5 , 1 , GL_FALSE , &LModel[0][0]);
                    FMatrix[LX][LY][LZ]->ORender(LX , LY , LZ);
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
        FMatrix.clear();
    }

    std::intmax_t CSpace::OAccessTranslationIntegralX()
    {
        return FPositionX;
    }

    std::intmax_t CSpace::OAccessTranslationIntegralY()
    {
        return FPositionY;
    }

    std::intmax_t CSpace::OAccessTranslationIntegralZ()
    {
        return FPositionZ;
    }

    NSpace::CPartition& CSpace::OAccessPartition(std::intmax_t PX , std::intmax_t PY , std::intmax_t PZ)
    {
        return *FMatrix[PX][PY][PZ];
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectNegativeX()
    {
        return FVertexArrayObjectNegativeX;
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectPositiveX()
    {
        return FVertexArrayObjectPositiveX;
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectNegativeY()
    {
        return FVertexArrayObjectNegativeY;
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectPositiveY()
    {
        return FVertexArrayObjectPositiveY;
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectNegativeZ()
    {
        return FVertexArrayObjectNegativeZ;
    }

    const std::shared_ptr<NSpace::CVertexArrayObject>& CSpace::OVertexArrayObjectPositiveZ()
    {
        return FVertexArrayObjectPositiveZ;
    }
}
#include"Space.hpp"

#include"Audio.hpp"
#include"Audio\\Track.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Network.hpp"
#include"Time.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NDespair
{
    void CSpace::IReevaluateTranslation(std::intmax_t& PTranslation , const std::intmax_t& PSize)
    {
        PTranslation = PSize / 2;
    }
    void CSpace::IReevaluateTranslationX()
    {
        IReevaluateTranslation(FTranslationX , FSizeX);
    }
    void CSpace::IReevaluateTranslationY()
    {
        IReevaluateTranslation(FTranslationY , FSizeY);
    }
    void CSpace::IReevaluateTranslationZ()
    {
        IReevaluateTranslation(FTranslationZ , FSizeZ);
    }
    void CSpace::IReevaluateTranslationXY()
    {
        IReevaluateTranslationX();
        IReevaluateTranslationY();
    }
    void CSpace::IReevaluateTranslationXYZ()
    {
        IReevaluateTranslationXY();
        IReevaluateTranslationZ();
    }
    void CSpace::IConstructVertexArrayObject(std::shared_ptr<NVideo::CVertexArrayObject>& PVertexArrayObject , const std::array<float , 20>& PVertices)
    {
        PVertexArrayObject = std::make_shared<NVideo::CVertexArrayObject>(PVertices , std::array<std::uint32_t , 6>{0 , 1 , 2 , 2 , 3 , 0});
    }
    std::intmax_t CSpace::IEvaluateOffset(const std::intmax_t& PTo , const std::intmax_t& PFrom)
    {
        return(PTo - PFrom);
    }
    std::intmax_t CSpace::IEvaluateOffsetX(const std::intmax_t& PTo)
    {
        return(IEvaluateOffset(PTo , FTranslationX));
    }
    std::intmax_t CSpace::IEvaluateOffsetY(const std::intmax_t& PTo)
    {
        return(IEvaluateOffset(PTo , FTranslationY));
    }
    std::intmax_t CSpace::IEvaluateOffsetZ(const std::intmax_t& PTo)
    {
        return(IEvaluateOffset(PTo , FTranslationZ));
    }
    bool CSpace::IDoesTranslationExist(const std::intmax_t& PTranslation , const std::intmax_t& PSize)
    {
        return(PTranslation == std::clamp<std::intmax_t>(PTranslation , 0 , PSize - 1));
    }
    bool CSpace::IDoesPartitionExist(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        return
        (
            IDoesTranslationExist(PX , FSizeX)
            &&
            IDoesTranslationExist(PY , FSizeY)
            &&
            IDoesTranslationExist(PZ , FSizeZ)
        );
    }
    bool CSpace::IGenerateTransition(NVideo::CTexture*& PFrom , NVideo::CTexture*& PTo)
    {
        if(!PFrom && !PTo)
        {
            return(false);
        }
        PFrom = nullptr;
        PTo = nullptr;
        return(true);
    }
    void CSpace::ITryGenerateTransitionHorizontal(std::intmax_t& PGenerated , const std::intmax_t& PRequested , const std::intmax_t& PX , const std::intmax_t& PY)
    {
        PGenerated = 0;
        while(PGenerated < PRequested)
        {
            if(ICanGenerateTransitionHorizontal(FTranslationX + PX , FTranslationY + PY , FTranslationZ))
            {
                PGenerated += IGenerateTransitionHorizontal(FTranslationX + PX , FTranslationY + PY , FTranslationZ);
                FTranslationX += PX;
                FTranslationY += PY;
            }
            else
            {
                break;
            }
        }
    }
    bool CSpace::ICanGenerateTransitionHorizontal(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        return(IDoesPartitionExist(PX , PY , PZ));
    }
    bool CSpace::IGenerateTransitionHorizontal(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        switch(IEvaluateOffsetX(PX))
        {
            case(-1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeX , FMatrix[PX][PY][PZ].FTexturePositiveX);
            case(+1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveX , FMatrix[PX][PY][PZ].FTextureNegativeX);
        }
        switch(IEvaluateOffsetY(PY))
        {
            case(-1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeY , FMatrix[PX][PY][PZ].FTexturePositiveY);
            case(+1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveY , FMatrix[PX][PY][PZ].FTextureNegativeY);
        }
        GDebug->AAssert();
        return(false);
    }
    void CSpace::ITryGenerateTransitionVertical(const std::intmax_t& PZ)
    {
        for(std::intmax_t LIteration{0} ; LIteration <= 9 ; LIteration++)
        {
            //std::cout "V " << PZ << " " << LIteration << "\n";
            bool LGenerated{false};
            while(!LGenerated)
            {
                std::random_device LGenerator;
                std::uniform_int_distribution<std::intmax_t> LX{0 , FSizeX - 1};
                std::uniform_int_distribution<std::intmax_t> LY{0 , FSizeY - 1};
                FTranslationX = LX(LGenerator);
                FTranslationY = LY(LGenerator);
                if(ICanGenerateTransitionVertical(FTranslationX , FTranslationY , FTranslationZ + PZ))
                {
                    LGenerated = IGenerateTransitionVertical(FTranslationX , FTranslationY , FTranslationZ + PZ);
                }
            }
        }
    }
    bool CSpace::ICanGenerateTransitionVertical(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        return
        (
            (
                !FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeX
                ||
                !FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveX
                ||
                !FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeY
                ||
                !FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveY
            )
            &&
            (
                !FMatrix[PX][PY][PZ].FTextureNegativeX
                ||
                !FMatrix[PX][PY][PZ].FTexturePositiveX
                ||
                !FMatrix[PX][PY][PZ].FTextureNegativeY
                ||
                !FMatrix[PX][PY][PZ].FTexturePositiveY
            )
        );
    }
    bool CSpace::IGenerateTransitionVertical(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        switch(IEvaluateOffsetZ(PZ))
        {
            case(-1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeZ , FMatrix[PX][PY][PZ].FTexturePositiveZ);
            case(+1):
                return IGenerateTransition(FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveZ , FMatrix[PX][PY][PZ].FTextureNegativeZ);
        }
        GDebug->AAssert();
        return(false);
    }
    bool CSpace::IIsCollisionDetected(const std::intmax_t& PX , const std::intmax_t& PY , const std::intmax_t& PZ)
    {
        if(!IDoesPartitionExist(PX , PY , PZ))
        {
            return(true);
        }
        switch(IEvaluateOffsetX(PX))
        {
            case(-1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeX && !FMatrix[PX][PY][PZ].FTexturePositiveX));
            break;
            case(+1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveX && !FMatrix[PX][PY][PZ].FTextureNegativeX));
            break;
        }
        switch(IEvaluateOffsetY(PY))
        {
            case(-1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeY && !FMatrix[PX][PY][PZ].FTexturePositiveY));
            break;
            case(+1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveY && !FMatrix[PX][PY][PZ].FTextureNegativeY));
            break;
        }
        switch(IEvaluateOffsetZ(PZ))
        {
            case(-1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTextureNegativeZ && !FMatrix[PX][PY][PZ].FTexturePositiveZ));
            break;
            case(+1):
                return(!(!FMatrix[FTranslationX][FTranslationY][FTranslationZ].FTexturePositiveZ && !FMatrix[PX][PY][PZ].FTextureNegativeZ));
            break;
        }
        return(true);
    }

    CSpace::CSpace()
    {
        GSpace = this;
        FSizeX = 100;
        FSizeY = 100;
        FSizeZ = 3;
        IReevaluateTranslationXYZ();
        FRotationX = 0;
        FRotationY = 1;
        FVision = 10;
        IConstructVertexArrayObject
        (
            FVertexArrayObjectNegativeX , {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F}
        );
        IConstructVertexArrayObject
        (
            FVertexArrayObjectPositiveX , {1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F}
        );
        IConstructVertexArrayObject
        (
            FVertexArrayObjectNegativeY , {1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F}
        );
        IConstructVertexArrayObject
        (
            FVertexArrayObjectPositiveY , {0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F}
        );
        IConstructVertexArrayObject
        (
            FVertexArrayObjectNegativeZ , {0.0F , 0.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 1.0F}
        );
        IConstructVertexArrayObject
        (
            FVertexArrayObjectPositiveZ , {0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 0.0F , 1.0F , 0.0F , 1.0F , 1.0F , 0.0F , 1.0F , 1.0F , 1.0F , 1.0F , 1.0F}
        );
        FTimer = 0;
        if(GNetwork->AMode() == "Server")
        {
            std::cout << "Waiting for space to generate... (restart it if you are seeing this message for more than a second, it's a bug)" << "\n";
            FMatrix.resize(FSizeX);
            for(std::intmax_t LX{0} ; LX < FSizeX ; LX++)
            {
                //std::cout << "P " << LX << "\n";
                FMatrix[LX].resize(FSizeY);
                for(std::intmax_t LY{0} ; LY < FSizeY ; LY++)
                {
                    FMatrix[LX][LY].resize(FSizeZ);
                    for(std::intmax_t LZ{0} ; LZ < FSizeZ ; LZ++)
                    {
                        FMatrix[LX][LY][LZ].FTextureNegativeX = GVideo->AAccessRandomTexture();
                        FMatrix[LX][LY][LZ].FTexturePositiveX = GVideo->AAccessRandomTexture();
                        FMatrix[LX][LY][LZ].FTextureNegativeY = GVideo->AAccessRandomTexture();
                        FMatrix[LX][LY][LZ].FTexturePositiveY = GVideo->AAccessRandomTexture();
                        FMatrix[LX][LY][LZ].FTextureNegativeZ = GVideo->AAccessRandomTexture();
                        FMatrix[LX][LY][LZ].FTexturePositiveZ = GVideo->AAccessRandomTexture();
                    }
                    FMatrix[LX][LY].shrink_to_fit();
                }
                FMatrix[LX].shrink_to_fit();
            }
            FMatrix.shrink_to_fit();
            for(FTranslationZ = 0 ; FTranslationZ < FSizeZ ; FTranslationZ++)
            {
                //std::cout << "H " << FPositionZ << "\n";
                IReevaluateTranslationXY();
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
                            ITryGenerateTransitionHorizontal(LGenerated , LRequested , +1 , 0);
                            break;
                        case(1):
                            ITryGenerateTransitionHorizontal(LGenerated , LRequested , 0 , +1);
                            break;
                        case(2):
                            ITryGenerateTransitionHorizontal(LGenerated , LRequested , -1 , 0);
                            break;
                        case(3):
                            ITryGenerateTransitionHorizontal(LGenerated , LRequested , 0 , -1);
                            break;
                    }
                }
            }
            IReevaluateTranslationZ();
            ITryGenerateTransitionVertical(-1);
            ITryGenerateTransitionVertical(+1);
            IReevaluateTranslationXY();
            std::cout << "Space generated successfully!" << "\n";
            for(std::intmax_t LX{0} ; LX < FSizeX ; LX++)
            {
                for(std::intmax_t LY{0} ; LY < FSizeY ; LY++)
                {
                    for(std::intmax_t LZ{0} ; LZ < FSizeZ ; LZ++)
                    {
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTextureNegativeX ? FMatrix[LX][LY][LZ].FTextureNegativeX->APath() : "");
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTexturePositiveX ? FMatrix[LX][LY][LZ].FTexturePositiveX->APath() : "");
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTextureNegativeY ? FMatrix[LX][LY][LZ].FTextureNegativeY->APath() : "");
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTexturePositiveY ? FMatrix[LX][LY][LZ].FTexturePositiveY->APath() : "");
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTextureNegativeZ ? FMatrix[LX][LY][LZ].FTextureNegativeZ->APath() : "");
                        GNetwork->ASend(FMatrix[LX][LY][LZ].FTexturePositiveZ ? FMatrix[LX][LY][LZ].FTexturePositiveZ->APath() : "");
                    }
                }
            }
            return;
        }
        if(GNetwork->AMode() == "Client")
        {
            FMatrix.resize(FSizeX);
            for(std::intmax_t LX{0} ; LX < FSizeX ; LX++)
            {
                FMatrix[LX].resize(FSizeY);
                for(std::intmax_t LY{0} ; LY < FSizeY ; LY++)
                {
                    FMatrix[LX][LY].resize(FSizeZ);
                    for(std::intmax_t LZ{0} ; LZ < FSizeZ ; LZ++)
                    {
                        std::string LTexture;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTextureNegativeX = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTexturePositiveX = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTextureNegativeY = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTexturePositiveY = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTextureNegativeZ = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                        LTexture = GNetwork->AReceive();
                        FMatrix[LX][LY][LZ].FTexturePositiveZ = !LTexture.empty() ? GVideo->AAccessSpecificTexture(LTexture) : nullptr;
                    }
                    FMatrix[LX][LY].shrink_to_fit();
                }
                FMatrix[LX].shrink_to_fit();
            }
            FMatrix.shrink_to_fit();
            GAudio->AAccessTrack("\\Mountain Realm - Grayshadow Ruins.mp3")->AAccessVolume(16)->APlay();
            return;
        }
    }
    void CSpace::AUpdate()
    {
        if(GInput->AIsKeyPressed(SDL_SCANCODE_A))
        {
            std::swap(FRotationX , FRotationY);
            if(FRotationX)
            {
                FRotationX *= -1;
            }
        }
        if(GInput->AIsKeyPressed(SDL_SCANCODE_D))
        {
            std::swap(FRotationX , FRotationY);
            if(FRotationY)
            {
                FRotationY *= -1;
            }
        }
        if(GInput->AIsKeyPressed(SDL_SCANCODE_S))
        {
            if(!IIsCollisionDetected(FTranslationX - FRotationX , FTranslationY - FRotationY , FTranslationZ))
            {
                FTranslationX -= FRotationX;
                FTranslationY -= FRotationY;
                if(!IIsCollisionDetected(FTranslationX , FTranslationY , FTranslationZ - 1))
                {
                    FTranslationZ--;
                }
            }
        }
        if(GInput->AIsKeyPressed(SDL_SCANCODE_W))
        {
            if(!IIsCollisionDetected(FTranslationX + FRotationX , FTranslationY + FRotationY , FTranslationZ))
            {
                FTranslationX += FRotationX;
                FTranslationY += FRotationY;
                if(!IIsCollisionDetected(FTranslationX , FTranslationY , FTranslationZ - 1))
                {
                    FTranslationZ--;
                }
            }
        }
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo->ARatio() , 0.25F , 1'000.0F)};
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
                    -std::round(std::acos(FRotationX ? FRotationX : 1) * 180.0F / std::numbers::pi_v<float> + std::asin(FRotationY ? FRotationY : 0) * 180.0F / std::numbers::pi_v<float> - 90.0F)
                )
            )
            ,
            glm::vec3{0.0F , 0.0F , 1.0F}
        );
        LView = glm::translate(LView , -glm::vec3{FTranslationX + 0.5F , FTranslationY + 0.5F , FTranslationZ + 0.5F});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        FTimer += GTime->ARelative();
        if(FTimer >= 5000)
        {
            FTimer = 0;
            for
            (
                std::intmax_t LX{std::clamp<std::intmax_t>(FTranslationX - FVision , 0 , FSizeX - 1)}
                ;
                LX <= std::clamp<std::intmax_t>(FTranslationX + FVision , 0 , FSizeX - 1)
                ;
                LX++
            )
            {
                for
                (
                    std::intmax_t LY{std::clamp<std::intmax_t>(FTranslationY - FVision , 0 , FSizeY - 1)}
                    ;
                    LY <= std::clamp<std::intmax_t>(FTranslationY + FVision , 0 , FSizeY - 1)
                    ;
                    LY++
                )
                {
                        if(!(GTime->AAbsolute() / 5000 % 2))
                        {
                            if(!FMatrix[LX][LY][0].FTextureNegativeZ)
                            {
                                FMatrix[LX][LY][0].FTextureNegativeZ = FMatrix[LX][LY][1].FTextureNegativeZ;
                                FMatrix[LX][LY][0].FTexturePositiveZ = nullptr;
                                FMatrix[LX][LY][1].FTextureNegativeZ = nullptr;
                                if(FTranslationX == LX && FTranslationY == LY)
                                {
                                    FTranslationZ = 0;
                                }
                                continue;
                            }
                            if(!FMatrix[LX][LY][1].FTextureNegativeZ)
                            {
                                FMatrix[LX][LY][0].FTexturePositiveZ = FMatrix[LX][LY][0].FTextureNegativeZ;
                                FMatrix[LX][LY][1].FTextureNegativeZ = FMatrix[LX][LY][0].FTextureNegativeZ;
                                FMatrix[LX][LY][0].FTextureNegativeZ = nullptr;
                                if(FTranslationX == LX && FTranslationY == LY)
                                {
                                    FTranslationZ = 1;
                                }
                                continue;
                            }
                        }
                        if(GTime->AAbsolute() / 5000 % 2)
                        {
                            std::random_device LGenerator;
                            std::intmax_t LDeltaX{std::uniform_int_distribution<std::intmax_t>{-1 , +1}(LGenerator)};
                            std::intmax_t LDeltaY{std::uniform_int_distribution<std::intmax_t>{-1 , +1}(LGenerator)};
                            if(!FMatrix[LX][LY][0].FTextureNegativeZ)
                            {
                                std::swap(FMatrix[LX][LY][0].FTextureNegativeZ , FMatrix[LX + LDeltaX][LY + LDeltaY][0].FTextureNegativeZ);
                                std::swap(FMatrix[LX][LY][0].FTexturePositiveZ , FMatrix[LX + LDeltaX][LY + LDeltaY][0].FTexturePositiveZ);
                                if(FTranslationX == LX && FTranslationY == LY && FTranslationZ == 0)
                                {
                                    FTranslationX += LDeltaX;
                                    FTranslationY += LDeltaY;
                                }
                                continue;
                            }
                            if(!FMatrix[LX][LY][1].FTextureNegativeZ)
                            {
                                std::swap(FMatrix[LX][LY][1].FTextureNegativeZ , FMatrix[LX + LDeltaX][LY + LDeltaY][1].FTextureNegativeZ);
                                std::swap(FMatrix[LX][LY][1].FTexturePositiveZ , FMatrix[LX + LDeltaX][LY + LDeltaY][1].FTexturePositiveZ);
                                if(FTranslationX == LX && FTranslationY == LY && FTranslationZ == 1)
                                {
                                    FTranslationX += LDeltaX;
                                    FTranslationY += LDeltaY;
                                }
                                continue;
                            }
                        }
                }
            }
        }
        for
        (
            std::intmax_t LX{std::clamp<std::intmax_t>(FTranslationX - FVision , 0 , FSizeX - 1)}
            ;
            LX <= std::clamp<std::intmax_t>(FTranslationX + FVision , 0 , FSizeX - 1)
            ;
            LX++
        )
        {
            for
            (
                std::intmax_t LY{std::clamp<std::intmax_t>(FTranslationY - FVision , 0 , FSizeY - 1)}
                ;
                LY <= std::clamp<std::intmax_t>(FTranslationY + FVision , 0 , FSizeY - 1)
                ;
                LY++
            )
            {
                for
                (
                    std::intmax_t LZ{std::clamp<std::intmax_t>(FTranslationZ - FVision , 0 , FSizeZ - 1)}
                    ;
                    LZ <= std::clamp<std::intmax_t>(FTranslationZ + FVision , 0 , FSizeZ - 1)
                    ;
                    LZ++
                )
                {
                    glUniform1f(7 , std::clamp(0.2F / glm::distance(glm::vec3{FTranslationX , FTranslationY , FTranslationZ} , glm::vec3{LX , LY , LZ}) , 0.0F , 0.4F));
                    glm::mat4 LModel{1.0F};
                    LModel = glm::translate(LModel , glm::vec3{LX , LY , LZ});
                    glUniformMatrix4fv(5 , 1 , GL_FALSE , &LModel[0][0]);
                    if(FMatrix[LX][LY][LZ].FTextureNegativeX)
                    {
                        FVertexArrayObjectNegativeX->ABind();
                        FMatrix[LX][LY][LZ].FTextureNegativeX->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[LX][LY][LZ].FTexturePositiveX)
                    {
                        FVertexArrayObjectPositiveX->ABind();
                        FMatrix[LX][LY][LZ].FTexturePositiveX->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[LX][LY][LZ].FTextureNegativeY)
                    {
                        FVertexArrayObjectNegativeY->ABind();
                        FMatrix[LX][LY][LZ].FTextureNegativeY->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[LX][LY][LZ].FTexturePositiveY)
                    {
                        FVertexArrayObjectPositiveY->ABind();
                        FMatrix[LX][LY][LZ].FTexturePositiveY->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[LX][LY][LZ].FTextureNegativeZ)
                    {
                        FVertexArrayObjectNegativeZ->ABind();
                        FMatrix[LX][LY][LZ].FTextureNegativeZ->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                    if(FMatrix[LX][LY][LZ].FTexturePositiveZ)
                    {
                        FVertexArrayObjectPositiveZ->ABind();
                        FMatrix[LX][LY][LZ].FTexturePositiveZ->ABind();
                        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , nullptr);
                    }
                }
            }
        }
    }
}
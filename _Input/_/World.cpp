#include"World.hpp"

#include"Audio.hpp"
#include"Input.hpp"
#include"Partition.hpp"
#include"Texture.hpp"
#include"Track.hpp"
#include"Video.hpp"

namespace NBlindness::NWorld{
    void FInitialize(){
        VRotation = 0.0;
        VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VTranslationRealX = 0.5;
        VTranslationRealY = 0.5;
        VTranslationRealZ = 0.5;
        VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5));
        VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5));
        VTranslationIntegralZ = static_cast<std::uintmax_t>(std::round(VTranslationRealZ - 0.5));
        std::uint32_t LTextureNegativeX{GVideo.FTexture("\\twall2_5.png").FIdentifier()};
        std::uint32_t LTexturePositiveX{GVideo.FTexture("\\twall2_6.png").FIdentifier()};
        std::uint32_t LTextureNegativeY{GVideo.FTexture("\\twall5_3.png").FIdentifier()};
        std::uint32_t LTexturePositiveY{GVideo.FTexture("\\uwall1_2.png").FIdentifier()};
        std::uint32_t LTextureNegativeZ{GVideo.FTexture("\\sfloor4_5.png").FIdentifier()};
        std::uint32_t LTexturePositiveZ{GVideo.FTexture("\\plat_top1.png").FIdentifier()};
        for(std::uintmax_t LX{0} ; LX < VDistanceAlongX ; LX++){
            VSpace.emplace_back();
            for(std::uintmax_t LY{0} ; LY < VDistanceAlongY ; LY++){
                VSpace[LX].emplace_back();
                for(std::uintmax_t LZ{0} ; LZ < VDistanceAlongZ ; LZ++){
                    VSpace[LX][LY].emplace_back(LTextureNegativeX , LTexturePositiveX , LTextureNegativeY , LTexturePositiveY , LTextureNegativeZ , LTexturePositiveZ);
                }
                VSpace[LX][LY].shrink_to_fit();
            }
            VSpace[LX].shrink_to_fit();
        }
        VSpace.shrink_to_fit();
        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDirection{0 , 3};
        std::uniform_int_distribution<std::uintmax_t> LDistance{3 , 5};
        std::uintmax_t LGenerated{0};
        for(std::uintmax_t LIteration{0} ; LIteration <= 1000 ; LIteration += LGenerated){
            std::uintmax_t LRequested{LDistance(LGenerator)};
            switch(LDirection(LGenerator)){
                case 0:
                    LGenerated = 0;
                    while(LGenerated < LRequested){
                        GCube = &VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ];
                        if(NCube::FCanBeGenerated(VTranslationIntegralX + 1 , VTranslationIntegralY , VTranslationIntegralZ)){
                            LGenerated += VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FGenerate(
                                VTranslationIntegralX + 1 , VTranslationIntegralY , VTranslationIntegralZ
                            );
                            VTranslationIntegralX++;
                        }
                        else{
                            break;
                        }
                    }
                break;
                case 1:
                    LGenerated = 0;
                    while(LGenerated < LRequested){
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(
                            VTranslationIntegralX , VTranslationIntegralY + 1 , VTranslationIntegralZ
                        )){
                            LGenerated += VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FGenerate(
                                VTranslationIntegralX , VTranslationIntegralY + 1 , VTranslationIntegralZ
                            );
                            VTranslationIntegralY++;
                        }
                        else{
                            break;
                        }
                    }
                break;
                case 2:
                    LGenerated = 0;
                    while(LGenerated < LRequested){
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(
                            VTranslationIntegralX - 1 , VTranslationIntegralY , VTranslationIntegralZ
                        )){
                            LGenerated += VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FGenerate(
                                VTranslationIntegralX - 1 , VTranslationIntegralY , VTranslationIntegralZ
                            );
                            VTranslationIntegralX--;
                        }
                        else{
                            break;
                        }
                    }
                break;
                case 3:
                    LGenerated = 0;
                    while(LGenerated < LRequested){
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(
                            VTranslationIntegralX , VTranslationIntegralY - 1 , VTranslationIntegralZ
                        )){
                            LGenerated += VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FGenerate(
                                VTranslationIntegralX , VTranslationIntegralY - 1 , VTranslationIntegralZ
                            );
                            VTranslationIntegralY--;
                        }
                        else{
                            break;
                        }
                    }
                break;
            }
        }
        VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5));
        VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5));
        VTranslationIntegralZ = static_cast<std::uintmax_t>(std::round(VTranslationRealZ - 0.5));

        glGenVertexArrays(1 , &VVertexArrayObject);
        glBindVertexArray(VVertexArrayObject);
        glGenBuffers(1 , &VVertexBufferObject);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVertices) , VVertices , GL_STATIC_DRAW);
        glGenBuffers(1 , &VElementBufferObject);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(VElements) , VElements , GL_STATIC_DRAW);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        
        VList = glGenLists(1);
        glNewList(VList , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < VDistanceAlongX ; LX++){
            for(std::uintmax_t LY{0} ; LY < VDistanceAlongY ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VDistanceAlongZ ; LZ++){
                    VSpace[LX][LY][LZ]->FRender(
                        LX , LY , LZ
                    );
                }
            }
        }
        glEndList();

        GAudio.FTrack("\\Mountain Realm - Grayshadow Ruins.mp3").FVolume(32).FPlay();
    }

    void FUpdate(){
        glEnable(GL_DEPTH_TEST);
        /*
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0 , GVideo.FRatio() , 0.25 , 1'000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        */
        if(GInput.FKeyPressed(SDL_SCANCODE_A)){
            VRotation += 90.0;
            if(VRotation >= 360.0){
                VRotation -= 360.0;
            }
            VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_D)){
            VRotation -= 90.0;
            if(VRotation < 0.0){
                VRotation += 360.0;
            }
            VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        }
        /*
        glRotated(-90.0 , 1.0 , 0.0 , 0.0);
        glRotated(-VRotation , 0.0 , 0.0 , 1.0);
        */
        if(GInput.FKeyPressed(SDL_SCANCODE_S)){
            if(
                VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]
                ->FIsCollisionDetected(VTranslationIntegralX + VDirectionBackwardX , VTranslationIntegralY + VDirectionBackwardY , VTranslationIntegralZ)
            ){
                VTranslationRealX += VDirectionBackwardX;
                VTranslationRealY += VDirectionBackwardY;
                VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5));
                VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5));
            }
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_W)){
            if(
                VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]
                ->FIsCollisionDetected(VTranslationIntegralX + VDirectionForwardX , VTranslationIntegralY + VDirectionForwardY , VTranslationIntegralZ)
            ){
                VTranslationRealX += VDirectionForwardX;
                VTranslationRealY += VDirectionForwardY;
                VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5));
                VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5));
            }
        }
        /*
        glTranslated(-VTranslationRealX , -VTranslationRealY , -VTranslationRealZ);
        glCallList(VList);
        std::array<float , 4> LLightPosition{static_cast<float>(VTranslationRealX) , static_cast<float>(VTranslationRealY) , static_cast<float>(VTranslationRealZ) , 1.0F};
        glLightfv(GL_LIGHT0 , GL_POSITION , LLightPosition.data());
        std::array<float , 3> LLightSpotDirection{static_cast<float>(VDirectionForwardX) , static_cast<float>(VDirectionForwardY) , 0.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_DIRECTION , LLightSpotDirection.data());
        */
    }

    void FDeinitialize(){
        //glDeleteLists(VList , 1);
    }

    std::uintmax_t FDistanceAlongX(){
        return VDistanceAlongX;
    }

    std::uintmax_t FDistanceAlongY(){
        return VDistanceAlongY;
    }

    std::uintmax_t FDistanceAlongZ(){
        return VDistanceAlongZ;
    }

    std::uintmax_t FTranslationIntegralX(){
        return VTranslationIntegralX;
    }

    std::uintmax_t FTranslationIntegralY(){
        return VTranslationIntegralY;
    }

    std::uintmax_t FTranslationIntegralZ(){
        return VTranslationIntegralZ;
    }

    CPartition& FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return *VSpace[PX][PY][PZ];
    }
}
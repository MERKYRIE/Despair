#include"World.hpp"

#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Track.hpp"
#include"Video.hpp"
#include"Video\\Texture.hpp"
#include"World\\Partition.hpp"
#include"World\\VertexArrayObject.hpp"

namespace NBlindness{
    void CWorld::FInitialize(){
        VRotation = 0.0F;
        VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        VTranslationRealX = 0.5F;
        VTranslationRealY = 0.5F;
        VTranslationRealZ = 0.5F;
        VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5F));
        VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5F));
        VTranslationIntegralZ = static_cast<std::uintmax_t>(std::round(VTranslationRealZ - 0.5F));
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
                    VSpace[LX][LY].emplace_back(new NWorld::CPartition{
                        LX , LY , LZ , LTextureNegativeX , LTexturePositiveX , LTextureNegativeY , LTexturePositiveY , LTextureNegativeZ , LTexturePositiveZ
                    });
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
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(VTranslationIntegralX + 1 , VTranslationIntegralY , VTranslationIntegralZ)){
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
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(VTranslationIntegralX , VTranslationIntegralY + 1 , VTranslationIntegralZ)){
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
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(VTranslationIntegralX - 1 , VTranslationIntegralY , VTranslationIntegralZ)){
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
                        if(VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]->FCanBeGenerated(VTranslationIntegralX , VTranslationIntegralY - 1 , VTranslationIntegralZ)){
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
        VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5F));
        VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5F));
        VTranslationIntegralZ = static_cast<std::uintmax_t>(std::round(VTranslationRealZ - 0.5F));
        glUniform1i(6 , 0);
        GDebug.FOpenGraphicsLibraryError();
        GAudio.FTrack("\\Mountain Realm - Grayshadow Ruins.mp3").FVolume(32).FPlay();
    }

    void CWorld::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.FRatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        if(GInput.FKeyPressed(SDL_SCANCODE_A)){
            VRotation += 90.0F;
            if(VRotation >= 360.0F){
                VRotation -= 360.0F;
            }
            VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_D)){
            VRotation -= 90.0F;
            if(VRotation < 0.0F){
                VRotation += 360.0F;
            }
            VDirectionBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
            VDirectionForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0F + VRotation) * std::numbers::pi_v<float> / 180.0F)));
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_S)){
            if(
                VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]
                ->FIsCollisionDetected(VTranslationIntegralX + VDirectionBackwardX , VTranslationIntegralY + VDirectionBackwardY , VTranslationIntegralZ)
            ){
                VTranslationRealX += VDirectionBackwardX;
                VTranslationRealY += VDirectionBackwardY;
                VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5F));
                VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5F));
            }
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_W)){
            if(
                VSpace[VTranslationIntegralX][VTranslationIntegralY][VTranslationIntegralZ]
                ->FIsCollisionDetected(VTranslationIntegralX + VDirectionForwardX , VTranslationIntegralY + VDirectionForwardY , VTranslationIntegralZ)
            ){
                VTranslationRealX += VDirectionForwardX;
                VTranslationRealY += VDirectionForwardY;
                VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5F));
                VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5F));
            }
        }
        glm::mat4 LModelview{1.0F};
        LModelview = glm::rotate(LModelview , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LModelview = glm::rotate(LModelview , glm::radians(-VRotation) , glm::vec3{0.0F , 0.0F , 1.0F});
        LModelview = glm::translate(LModelview , glm::vec3{VTranslationRealX , VTranslationRealY , VTranslationRealZ});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LModelview[0][0]);
        for(std::uintmax_t LX{0} ; LX < VDistanceAlongX ; LX++){
            for(std::uintmax_t LY{0} ; LY < VDistanceAlongY ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VDistanceAlongZ ; LZ++){
                    VSpace[LX][LY][LZ]->FRender(LX , LY , LZ);
                }
            }
        }
    }

    std::uintmax_t CWorld::FDistanceAlongX(){
        return VDistanceAlongX;
    }

    std::uintmax_t CWorld::FDistanceAlongY(){
        return VDistanceAlongY;
    }

    std::uintmax_t CWorld::FDistanceAlongZ(){
        return VDistanceAlongZ;
    }

    std::uintmax_t CWorld::FTranslationIntegralX(){
        return VTranslationIntegralX;
    }

    std::uintmax_t CWorld::FTranslationIntegralY(){
        return VTranslationIntegralY;
    }

    std::uintmax_t CWorld::FTranslationIntegralZ(){
        return VTranslationIntegralZ;
    }

    NWorld::CPartition& CWorld::FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return *VSpace[PX][PY][PZ];
    }

    void CWorld::FDeinitialize(){
        VSpace.clear();
    }
}
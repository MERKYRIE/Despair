#include"World.hpp"

#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Partition.hpp"
#include"Texture.hpp"
#include"Track.hpp"
#include"Video.hpp"

namespace NBlindness{
    void CWorld::FInitialize(){
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
                    VSpace[LX][LY].emplace_back(new CPartition{LTextureNegativeX , LTexturePositiveX , LTextureNegativeY , LTexturePositiveY , LTextureNegativeZ , LTexturePositiveZ});
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
        VTranslationIntegralX = static_cast<std::uintmax_t>(std::round(VTranslationRealX - 0.5));
        VTranslationIntegralY = static_cast<std::uintmax_t>(std::round(VTranslationRealY - 0.5));
        VTranslationIntegralZ = static_cast<std::uintmax_t>(std::round(VTranslationRealZ - 0.5));

        glGenBuffers(1 , &VElementBufferObject);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(VElements) , VElements.data() , GL_STATIC_DRAW);

        glGenVertexArrays(1 , &VVertexArrayObjectNegativeX);
        glBindVertexArray(VVertexArrayObjectNegativeX);
        glGenBuffers(1 , &VVertexBufferObjectNegativeX);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectNegativeX);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesNegativeX) , VVerticesNegativeX.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1 , &VVertexArrayObjectPositiveX);
        glBindVertexArray(VVertexArrayObjectPositiveX);
        glGenBuffers(1 , &VVertexBufferObjectPositiveX);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectPositiveX);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesPositiveX) , VVerticesPositiveX.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1 , &VVertexArrayObjectNegativeY);
        glBindVertexArray(VVertexArrayObjectNegativeY);
        glGenBuffers(1 , &VVertexBufferObjectNegativeY);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectNegativeY);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesNegativeY) , VVerticesNegativeY.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1 , &VVertexArrayObjectPositiveY);
        glBindVertexArray(VVertexArrayObjectPositiveY);
        glGenBuffers(1 , &VVertexBufferObjectPositiveY);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectPositiveY);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesPositiveY) , VVerticesPositiveY.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1 , &VVertexArrayObjectNegativeZ);
        glBindVertexArray(VVertexArrayObjectNegativeZ);
        glGenBuffers(1 , &VVertexBufferObjectNegativeZ);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectNegativeZ);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesNegativeZ) , VVerticesNegativeZ.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1 , &VVertexArrayObjectPositiveZ);
        glBindVertexArray(VVertexArrayObjectPositiveZ);
        glGenBuffers(1 , &VVertexBufferObjectPositiveZ);
        glBindBuffer(GL_ARRAY_BUFFER , VVertexBufferObjectPositiveZ);
        glBufferData(GL_ARRAY_BUFFER , sizeof(VVerticesPositiveZ) , VVerticesPositiveZ.data() , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VElementBufferObject);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glUniform1i(7 , 0);

        GDebug.FOpenGraphicsLibraryError();

        GAudio.FTrack("\\Mountain Realm - Grayshadow Ruins.mp3").FVolume(32).FPlay();
    }

    void CWorld::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.FRatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{glm::lookAt(glm::vec3{VTranslationRealX , VTranslationRealY , VTranslationRealZ} , glm::vec3{VDirectionForwardX , VDirectionForwardY , 0.0F} , glm::vec3{0.0F , 0.0F , 1.0F})};
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
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
        for(std::uintmax_t LX{0} ; LX < VDistanceAlongX ; LX++){
            for(std::uintmax_t LY{0} ; LY < VDistanceAlongY ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VDistanceAlongZ ; LZ++){
                    glm::mat4 LModel{1.0F};
                    LModel = glm::translate(LModel , glm::vec3{-VTranslationRealX , -VTranslationRealY , -VTranslationRealZ});
                    glUniformMatrix4fv(5 , 1 , GL_FALSE , &LModel[0][0]);
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

    CPartition& CWorld::FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return *VSpace[PX][PY][PZ];
    }

    std::uint32_t CWorld::FVertexArrayObjectNegativeX(){
        return VVertexArrayObjectNegativeX;
    }

    std::uint32_t CWorld::FVertexArrayObjectPositiveX(){
        return VVertexArrayObjectPositiveX;
    }

    std::uint32_t CWorld::FVertexArrayObjectNegativeY(){
        return VVertexArrayObjectNegativeY;
    }

    std::uint32_t CWorld::FVertexArrayObjectPositiveY(){
        return VVertexArrayObjectPositiveY;
    }

    std::uint32_t CWorld::FVertexArrayObjectNegativeZ(){
        return VVertexArrayObjectNegativeZ;
    }

    std::uint32_t CWorld::FVertexArrayObjectPositiveZ(){
        return VVertexArrayObjectPositiveZ;
    }

    void CWorld::FDeinitialize(){
        glDeleteVertexArrays(1 , &VVertexArrayObjectNegativeX);
        glDeleteVertexArrays(1 , &VVertexArrayObjectPositiveX);
        glDeleteVertexArrays(1 , &VVertexArrayObjectNegativeY);
        glDeleteVertexArrays(1 , &VVertexArrayObjectPositiveY);
        glDeleteVertexArrays(1 , &VVertexArrayObjectNegativeZ);
        glDeleteVertexArrays(1 , &VVertexArrayObjectPositiveZ);
        glDeleteBuffers(1 , &VVertexBufferObjectNegativeX);
        glDeleteBuffers(1 , &VVertexBufferObjectPositiveX);
        glDeleteBuffers(1 , &VVertexBufferObjectNegativeY);
        glDeleteBuffers(1 , &VVertexBufferObjectPositiveY);
        glDeleteBuffers(1 , &VVertexBufferObjectNegativeZ);
        glDeleteBuffers(1 , &VVertexBufferObjectPositiveZ);
        glDeleteBuffers(1 , &VElementBufferObject);
    }
}
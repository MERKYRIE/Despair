#include"World.hpp"

#include"Input.hpp"
#include"Partition.hpp"
#include"Texture.hpp"
#include"Video.hpp"

namespace NBlindness::NEngine{
    void CWorld::FInitialize(){
        VRotation = 0.0;
        VBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        VRealX = 0.5;
        VRealY = 0.5;
        VRealZ = 0.5;
        VIntegralX = static_cast<std::uintmax_t>(std::round(VRealX - 0.5));
        VIntegralY = static_cast<std::uintmax_t>(std::round(VRealY - 0.5));
        VIntegralZ = static_cast<std::uintmax_t>(std::round(VRealZ - 0.5));
        std::uint32_t LLeftward{GVideo.FTexture("\\twall2_5.png").FIdentifier()};
        std::uint32_t LRightward{GVideo.FTexture("\\twall2_6.png").FIdentifier()};
        std::uint32_t LBackward{GVideo.FTexture("\\twall5_3.png").FIdentifier()};
        std::uint32_t LForward{GVideo.FTexture("\\uwall1_2.png").FIdentifier()};
        std::uint32_t LDownward{GVideo.FTexture("\\sfloor4_5.png").FIdentifier()};
        std::uint32_t LUpward{GVideo.FTexture("\\plat_top1.png").FIdentifier()};
        for(std::uintmax_t LX{0} ; LX < VWidth ; LX++){
            VSpace.emplace_back();
            for(std::uintmax_t LY{0} ; LY < VDepth ; LY++){
                VSpace[LX].emplace_back();
                for(std::uintmax_t LZ{0} ; LZ < VHeight ; LZ++){
                    VSpace[LX][LY].emplace_back(new CPartition{LLeftward , LRightward , LBackward , LForward , LDownward , LUpward});
                }
                VSpace[LX][LY].shrink_to_fit();
            }
            VSpace[LX].shrink_to_fit();
        }
        VSpace.shrink_to_fit();

        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDistributor{0 , 3};
        std::uintmax_t LX{0};
        std::uintmax_t LY{0};
        std::uintmax_t LZ{0};
        for(std::uintmax_t LIteration{0} ; LIteration <= 99 ; LIteration++){
            bool LGenerated{false};
            while(!LGenerated){
                switch(LDistributor(LGenerator)){
                    case 0:
                        if(LX + 1 == std::clamp<std::uintmax_t>(LX + 1 , 0 , GWorld.FWidth() - 1)){
                            if(VSpace[LX][LY][LZ]->FEnclosed() && VSpace[LX + 1][LY][LZ]->FEnclosed()){
                                VSpace[LX][LY][LZ]->FRightward(0);
                                VSpace[LX + 1][LY][LZ]->FLeftward(0);
                            }
                            LX++;
                            LGenerated = true;
                        }
                    break;
                    case 1:
                        if(LY + 1 == std::clamp<std::uintmax_t>(LY + 1 , 0 , GWorld.FDepth() - 1)){
                            if(VSpace[LX][LY][LZ]->FEnclosed() && VSpace[LX + 1][LY][LZ]->FEnclosed()){
                                VSpace[LX][LY][LZ]->FForward(0);
                                VSpace[LX][LY + 1][LZ]->FBackward(0);
                            }
                            LY++;
                            LGenerated = true;
                        }
                    break;
                    case 2:
                        if(LX - 1 == std::clamp<std::uintmax_t>(LX - 1 , 0 , GWorld.FWidth() - 1)){
                            if(VSpace[LX][LY][LZ]->FEnclosed() && VSpace[LX + 1][LY][LZ]->FEnclosed()){
                                VSpace[LX][LY][LZ]->FLeftward(0);
                                VSpace[LX - 1][LY][LZ]->FRightward(0);
                            }
                            LX--;
                            LGenerated = true;
                        }
                    break;
                    case 3:
                        if(LY - 1 == std::clamp<std::uintmax_t>(LY - 1 , 0 , GWorld.FDepth() - 1)){
                            if(VSpace[LX][LY][LZ]->FEnclosed() && VSpace[LX + 1][LY][LZ]->FEnclosed()){
                                VSpace[LX][LY][LZ]->FBackward(0);
                                VSpace[LX][LY - 1][LZ]->FForward(0);
                            }
                            LY--;
                            LGenerated = true;
                        }
                    break;
                }
            }
        }

        /*
        VList = glGenLists(1);
        glNewList(VList , GL_COMPILE);
        for(std::uintmax_t LX{0} ; LX < VWidth ; LX++){
            for(std::uintmax_t LY{0} ; LY < VDepth ; LY++){
                for(std::uintmax_t LZ{0} ; LZ < VHeight ; LZ++){
                    VSpace[LX][LY][LZ]->FRender(LX , LY , LZ);
                }
            }
        }
        glEndList();
        */
    }

    void CWorld::FUpdate(){
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
            VBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_D)){
            VRotation -= 90.0;
            if(VRotation < 0.0){
                VRotation += 360.0;
            }
            VBackwardX = static_cast<std::int8_t>(std::round(-std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VBackwardY = static_cast<std::int8_t>(std::round(-std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VForwardX = static_cast<std::int8_t>(std::round(+std::cos((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
            VForwardY = static_cast<std::int8_t>(std::round(+std::sin((90.0 + VRotation) * std::numbers::pi_v<double> / 180.0)));
        }
        /*
        glRotated(-90.0 , 1.0 , 0.0 , 0.0);
        glRotated(-VRotation , 0.0 , 0.0 , 1.0);
        */
        if(GInput.FKeyPressed(SDL_SCANCODE_S)){
            if(
                VSpace[VIntegralX][VIntegralY][VIntegralZ]
                ->FCollision(VIntegralX + VBackwardX , VIntegralY + VBackwardY , VIntegralZ)
            ){
                VRealX += VBackwardX;
                VRealY += VBackwardY;
                VIntegralX = static_cast<std::uintmax_t>(std::round(VRealX - 0.5));
                VIntegralY = static_cast<std::uintmax_t>(std::round(VRealY - 0.5));
            }
        }
        if(GInput.FKeyPressed(SDL_SCANCODE_W)){
            if(
                VSpace[VIntegralX][VIntegralY][VIntegralZ]
                ->FCollision(VIntegralX + VForwardX , VIntegralY + VForwardY , VIntegralZ)
            ){
                VRealX += VForwardX;
                VRealY += VForwardY;
                VIntegralX = static_cast<std::uintmax_t>(std::round(VRealX - 0.5));
                VIntegralY = static_cast<std::uintmax_t>(std::round(VRealY - 0.5));
            }
        }
        /*
        glTranslated(-VRealX , -VRealY , -VRealZ);
        glCallList(VList);
        std::array<float , 4> LLightPosition{static_cast<float>(VRealX) , static_cast<float>(VRealY) , static_cast<float>(VRealZ) , 1.0F};
        glLightfv(GL_LIGHT0 , GL_POSITION , LLightPosition.data());
        std::array<float , 3> LLightSpotDirection{static_cast<float>(VForwardX) , static_cast<float>(VForwardY) , 0.0F};
        glLightfv(GL_LIGHT0 , GL_SPOT_DIRECTION , LLightSpotDirection.data());
        */
    }

    void CWorld::FDeinitialize(){
        //glDeleteLists(VList , 1);
    }

    std::uintmax_t CWorld::FWidth(){
        return VWidth;
    }

    std::uintmax_t CWorld::FDepth(){
        return VDepth;
    }

    std::uintmax_t CWorld::FHeight(){
        return VHeight;
    }

    std::uintmax_t CWorld::FX(){
        return VIntegralX;
    }

    std::uintmax_t CWorld::FY(){
        return VIntegralY;
    }

    std::uintmax_t CWorld::FZ(){
        return VIntegralZ;
    }

    const CPartition& CWorld::FPartition(std::uintmax_t PX , std::uintmax_t PY , std::uintmax_t PZ){
        return *VSpace[PX][PY][PZ];
    }
}
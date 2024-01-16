#include "Translation.hpp"

#include "Rotation.hpp"

#include "Input\\Keyboard.hpp"
#include "Level.hpp"

namespace NMRKOGL::NLevel{
    void CTranslation::FInitialize(){
        VX = 0.0F;
        VZ = 0.0F;
    }

    void CTranslation::FUpdate(){
        if(NInput::GKeyboard.FHeld(SDL_SCANCODE_A)){
            VX--;
        }
        if(NInput::GKeyboard.FHeld(SDL_SCANCODE_D)){
            VX++;
        }
        if(NInput::GKeyboard.FHeld(SDL_SCANCODE_S)){
            VZ++;
        }
        if(NInput::GKeyboard.FHeld(SDL_SCANCODE_W)){
            VX += GRotation.FX();
            VZ += GRotation.FZ();
        }
        glTranslatef(-VX , 0.0F , -VZ);
        std::cout << "Minimum = " << GLevel.VSpace[0][0][0].VCuboid.min() << " < Translation = " << VX << " 0 " << VZ << " < Maximum = " << GLevel.VSpace[7][7][7].VCuboid.max() << "\n";
        /*
        glTranslatef(
            -CGAL::midpoint<CGAL::Simple_cartesian<float>>(
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.min() ,
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.max()
            ).x() ,
            -CGAL::midpoint<CGAL::Simple_cartesian<float>>(
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.min() ,
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.max()
            ).y() ,
            -CGAL::midpoint<CGAL::Simple_cartesian<float>>(
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.min() ,
                GLevel.VSpace[VPoint.x()][VPoint.y()][VPoint.z()].VCuboid.max()
            ).z()
        );
        */
    }

    void CTranslation::FLeftward(){
        /*
        VTranslation -= VTranslationSpeed * CGAL::Vector_3<CGAL::Simple_cartesian<float>>{
            -std::sin((VRotation.y() - 90.0F) * std::numbers::pi_v<float> / 180.0F) , 0.0F , std::cos((VRotation.y() - 90.0F) * std::numbers::pi_v<float> / 180.0F)
        };
        */
    }

    void CTranslation::FRightward(){
        /*
        VTranslation += VTranslationSpeed * CGAL::Vector_3<CGAL::Simple_cartesian<float>>{
            -std::sin((VRotation.y() - 90.0F) * std::numbers::pi_v<float> / 180.0F) , 0.0F , std::cos((VRotation.y() - 90.0F) * std::numbers::pi_v<float> / 180.0F)
        };
        */
    }

    void CTranslation::FBackward(){
        /*
        if(
            CGAL::Point_3<CGAL::Simple_cartesian<unsigned int>>{VPoint.x() + GRotation.FX() , VPoint.y() , VPoint.z() + GRotation.FZ()} ==
            std::clamp<CGAL::Point_3<CGAL::Simple_cartesian<unsigned int>>>(
                {VPoint.x() + GRotation.FX() , VPoint.y() , VPoint.z() + GRotation.FZ()} ,
                {0 , VPoint.y() , 0} ,
                {GLevel.VSpace.size() - 1 , VPoint.y() , GLevel.VSpace[0][0].size() - 1}
            )
        ){
            if(!GLevel.VSpace[VPoint.x() + GRotation.FX()][VPoint.y()][VPoint.z() + GRotation.FZ()].VCollision){
                VPoint = {
                    VPoint.x() + GRotation.FX() ,
                    VPoint.y() ,
                    VPoint.z() + GRotation.FZ()
                };
            }
        }
        */
    }

    void CTranslation::FForward(){
        /*
        if(
            CGAL::Point_3<CGAL::Simple_cartesian<unsigned int>>{VPoint.x() - GRotation.FX() , VPoint.y() , VPoint.z() + GRotation.FZ()} ==
            std::clamp<CGAL::Point_3<CGAL::Simple_cartesian<unsigned int>>>(
                {VPoint.x() - GRotation.FX() , VPoint.y() , VPoint.z() + GRotation.FZ()} ,
                {0 , VPoint.y() , 0} ,
                {GLevel.VSpace.size() - 1 , VPoint.y() , GLevel.VSpace[0][0].size() - 1}
            )
        ){
            if(!GLevel.VSpace[VPoint.x() - GRotation.FX()][VPoint.y()][VPoint.z() + GRotation.FZ()].VCollision){
                VPoint = {
                    VPoint.x() - GRotation.FX() ,
                    VPoint.y() ,
                    VPoint.z() + GRotation.FZ()
                };
            }
        }
        */
    }
}
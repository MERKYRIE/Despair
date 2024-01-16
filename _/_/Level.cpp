#include "Level.hpp"

#include "Level\\Rotation.hpp"
#include "Level\\Translation.hpp"

#include "Debug\\Assert\\Error.hpp"
#include "Debug\\Assert\\Error\\SDL.hpp"
#include "Video.hpp"

namespace NMRKOGL{
    void CLevel::FInitialize(){
        VPath = "Levels\\Episode 1\\Map 1\\E1M1.obj";
        NLevel::GRotation.FInitialize();
        NLevel::GTranslation.FInitialize();
        NDebug::NAssert::NError::GSDL.FFlags(IMG_Init(IMG_INIT_PNG));
        const aiScene* LScene;
        NDebug::NAssert::GError.FOAIL(LScene = aiImportFile(VPath.c_str() , 0));
        std::vector<unsigned int> LMaterials;
        std::vector<std::vector<CGAL::Point_2<CGAL::Simple_cartesian<float>>>> LCoordinates;
        std::vector<std::vector<CGAL::Point_3<CGAL::Simple_cartesian<float>>>> LVertices;
        for(unsigned int LMesh{0} ; LMesh < LScene->mNumMeshes ; LMesh++){
            aiString LString;
            aiGetMaterialTexture(LScene->mMaterials[LScene->mMeshes[LMesh]->mMaterialIndex] , aiTextureType_DIFFUSE , 0 , &LString);
            SDL_Surface* LSurface{IMG_Load(LString.C_Str())};
            NDebug::NAssert::NError::GSDL.FHandle(LSurface);
            LMaterials.emplace_back();
            glGenTextures(1 , &LMaterials.back());
            glBindTexture(GL_TEXTURE_2D , LMaterials.back());
            glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , LSurface->w , LSurface->h , 0 , GL_RGB , GL_UNSIGNED_BYTE , LSurface->pixels);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
            NDebug::NAssert::GError.FOGL();
            SDL_FreeSurface(LSurface);
            LCoordinates.emplace_back();
            LVertices.emplace_back();
            for(unsigned int LVertex{0} ; LVertex < LScene->mMeshes[LMesh]->mNumVertices ; LVertex++){
                LCoordinates[LMesh].emplace_back(LScene->mMeshes[LMesh]->mTextureCoords[0][LVertex].x , LScene->mMeshes[LMesh]->mTextureCoords[0][LVertex].y);
                LVertices[LMesh].emplace_back(LScene->mMeshes[LMesh]->mVertices[LVertex].x , LScene->mMeshes[LMesh]->mVertices[LVertex].y , LScene->mMeshes[LMesh]->mVertices[LVertex].z);
            }
        }
        aiReleaseImport(LScene);
        if(!std::filesystem::directory_entry{std::string{VPath} + ".msp"}.exists()){
            CGAL::Point_3<CGAL::Simple_cartesian<float>> LMinimum{std::numeric_limits<float>::max() , std::numeric_limits<float>::max() , std::numeric_limits<float>::max()};
            CGAL::Point_3<CGAL::Simple_cartesian<float>> LMaximum{std::numeric_limits<float>::min() , std::numeric_limits<float>::min() , std::numeric_limits<float>::min()};
            for(unsigned int LMaterial{0} ; LMaterial < LMaterials.size() ; LMaterial++){
                for(unsigned int LVertex{0} ; LVertex < LVertices[LMaterial].size() ; LVertex++){
                    if(LVertices[LMaterial][LVertex].x() < LMinimum.x()){
                        LMinimum = {LVertices[LMaterial][LVertex].x() , LMinimum.y() , LMinimum.z()};
                    }
                    if(LVertices[LMaterial][LVertex].y() < LMinimum.y()){
                        LMinimum = {LMinimum.x() , LVertices[LMaterial][LVertex].y() , LMinimum.z()};
                    }
                    if(LVertices[LMaterial][LVertex].z() < LMinimum.z()){
                        LMinimum = {LMinimum.x() , LMinimum.y() , LVertices[LMaterial][LVertex].z()};
                    }
                    if(LVertices[LMaterial][LVertex].x() > LMaximum.x()){
                        LMaximum = {LVertices[LMaterial][LVertex].x() , LMaximum.y() , LMaximum.z()};
                    }
                    if(LVertices[LMaterial][LVertex].y() > LMaximum.y()){
                        LMaximum = {LMaximum.x() , LVertices[LMaterial][LVertex].y() , LMaximum.z()};
                    }
                    if(LVertices[LMaterial][LVertex].z() > LMaximum.z()){
                        LMaximum = {LMaximum.x() , LMaximum.y() , LVertices[LMaterial][LVertex].z()};
                    }
                }
            }
            std::vector<CGAL::Triangle_3<CGAL::Simple_cartesian<float>>> LTriangles;
            for(unsigned int LMesh{0} ; LMesh < LMaterials.size() ; LMesh++){
                for(unsigned int LVertex{0} ; LVertex < LVertices[LMesh].size() ; LVertex += 3){
                    LTriangles.emplace_back(LVertices[LMesh][LVertex + 0] , LVertices[LMesh][LVertex + 1] , LVertices[LMesh][LVertex + 2]);
                }
            }
            CGAL::Vector_3<CGAL::Simple_cartesian<float>> LDivision{
                (LMaximum.x() - LMinimum.x()) / VSpace.size() , (LMaximum.y() - LMinimum.y()) / VSpace[0].size() , (LMaximum.z() - LMinimum.z()) / VSpace[0][0].size()
            };
            for(unsigned int LX{0} ; LX < VSpace.size() ; LX++){
                for(unsigned int LY{0} ; LY < VSpace[LX].size() ; LY++){
                    for(unsigned int LZ{0} ; LZ < VSpace[LX][LY].size() ; LZ++){
                        VSpace[LX][LY][LZ].VCuboid = {
                            {LMinimum.x() + LDivision.x() * (LX + 0) , LMinimum.y() + LDivision.y() * (LY + 0) , LMinimum.z() + LDivision.z() * (LZ + 0)} ,
                            {LMinimum.x() + LDivision.x() * (LX + 1) , LMinimum.y() + LDivision.y() * (LY + 1) , LMinimum.z() + LDivision.z() * (LZ + 1)}
                        };
                        for(unsigned int LTriangle{0} ; LTriangle < LTriangles.size() ; LTriangle++){
                            if(CGAL::squared_distance<CGAL::Simple_cartesian<float>>(
                                CGAL::midpoint<CGAL::Simple_cartesian<float>>(VSpace[LX][LY][LZ].VCuboid.min() , VSpace[LX][LY][LZ].VCuboid.max()) ,
                                LTriangles[LTriangle]
                            ) <= 25.0F){
                                VSpace[LX][LY][LZ].VCollision = true;
                                break;
                            }
                        }
                    }
                }
            }
            std::ofstream LFile{std::string{VPath} + ".msp" , std::ios::out | std::ios::binary};
            for(unsigned int LX{0} ; LX < VSpace.size() ; LX++){
                for(unsigned int LY{0} ; LY < VSpace[LX].size() ; LY++){
                    for(unsigned int LZ{0} ; LZ < VSpace[LX][LY].size() ; LZ++){
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.min().x()) , sizeof(VSpace[LX][LY][LZ].VCuboid.min().x()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.min().y()) , sizeof(VSpace[LX][LY][LZ].VCuboid.min().y()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.min().z()) , sizeof(VSpace[LX][LY][LZ].VCuboid.min().z()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.max().x()) , sizeof(VSpace[LX][LY][LZ].VCuboid.max().x()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.max().y()) , sizeof(VSpace[LX][LY][LZ].VCuboid.max().y()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCuboid.max().z()) , sizeof(VSpace[LX][LY][LZ].VCuboid.max().z()));
                        LFile.write(reinterpret_cast<const char*>(&VSpace[LX][LY][LZ].VCollision) , sizeof(VSpace[LX][LY][LZ].VCollision));
                    }
                }
            }
        }
        else{
            std::ifstream LFile{std::string{VPath} + ".msp" , std::ios::in | std::ios::binary};
            for(unsigned int LX{0} ; LX < VSpace.size() ; LX++){
                for(unsigned int LY{0} ; LY < VSpace[LX].size() ; LY++){
                    for(unsigned int LZ{0} ; LZ < VSpace[LX][LY].size() ; LZ++){
                        float LBoxMinimumX;
                        LFile.read(reinterpret_cast<char*>(&LBoxMinimumX) , sizeof(LBoxMinimumX));
                        float LBoxMinimumY;
                        LFile.read(reinterpret_cast<char*>(&LBoxMinimumY) , sizeof(LBoxMinimumY));
                        float LBoxMinimumZ;
                        LFile.read(reinterpret_cast<char*>(&LBoxMinimumZ) , sizeof(LBoxMinimumZ));
                        float LBoxMaximumX;
                        LFile.read(reinterpret_cast<char*>(&LBoxMaximumX) , sizeof(LBoxMaximumX));
                        float LBoxMaximumY;
                        LFile.read(reinterpret_cast<char*>(&LBoxMaximumY) , sizeof(LBoxMaximumY));
                        float LBoxMaximumZ;
                        LFile.read(reinterpret_cast<char*>(&LBoxMaximumZ) , sizeof(LBoxMaximumZ));
                        VSpace[LX][LY][LZ].VCuboid = {
                            {LBoxMinimumX , LBoxMinimumY , LBoxMinimumZ} ,
                            {LBoxMaximumX , LBoxMaximumY , LBoxMaximumZ}
                        };
                        LFile.read(reinterpret_cast<char*>(&VSpace[LX][LY][LZ].VCollision) , sizeof(VSpace[LX][LY][LZ].VCollision));
                    }
                }
            }
        }
        VList = glGenLists(1);
        glNewList(VList , GL_COMPILE);
        for(unsigned int LMaterial{0} ; LMaterial < LMaterials.size() ; LMaterial++){
            glColor4ub(255 , 255 , 255 , 255);
            glBindTexture(GL_TEXTURE_2D , LMaterials[LMaterial]);
            glBegin(GL_TRIANGLES);
            for(unsigned int LVertex{0} ; LVertex < LVertices[LMaterial].size() ; LVertex++){
                glTexCoord2f(LCoordinates[LMaterial][LVertex].x() , LCoordinates[LMaterial][LVertex].y());
                glVertex3f(LVertices[LMaterial][LVertex].x() , LVertices[LMaterial][LVertex].y() , LVertices[LMaterial][LVertex].z());
            }
            glEnd();
            glColor4ub(0 , 100 , 100 , 255);
            glBindTexture(GL_TEXTURE_2D , 0);
            glBegin(GL_LINES);
            for(unsigned int LX{0} ; LX < VSpace.size() ; LX++){
                for(unsigned int LY{0} ; LY < VSpace[LX].size() ; LY++){
                    for(unsigned int LZ{0} ; LZ < VSpace[LX][LY].size() ; LZ++){
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());

                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());

                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.min().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.max().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.max().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                        glVertex3f(VSpace[LX][LY][LZ].VCuboid.min().x() , VSpace[LX][LY][LZ].VCuboid.min().y() , VSpace[LX][LY][LZ].VCuboid.max().z());
                    }
                }
            }
            glEnd();
        }
        glEndList();
    }

    void CLevel::FUpdate(){
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0F , GVideo.FRatio() , 1.0F , 1'000'000.0F);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        NLevel::GRotation.FUpdate();
        NLevel::GTranslation.FUpdate();
        glCallList(VList);
    }

    void CLevel::FDeinitialize(){
        glDeleteLists(VList , 1);
        IMG_Quit();
    }
}
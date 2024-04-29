#pragma once

#include<Array>
#include<Filesystem>
#include<Fstream>
#include<Iostream>
#include<Numbers>
#include<Random>
#include<Source_location>
#include<String>
#include<Vector>

#pragma warning(push)
    #pragma warning(disable : 4267 4551 6001 6385 6386 26451 26495 26819 33010)
    #include"..\\OpenAssetImportLibrary\\scene.h"
    #include"..\\OpenAssetImportLibrary\\cimport.h"
    #include"..\\GraphicsLibraryAddress\\gl.h"
    #include"..\\SimpleDirectMediaLayer\\sdl.h"
    #include"..\\SimpleDirectMediaLayer\\Image\\sdl_image.h"
    #include"..\\SimpleDirectMediaLayer\\Mixer\\sdl_mixer.h"
    #include"..\\SimpleDirectMediaLayer\\Network\\SDL_net.h"
    #include"..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl_ttf.h"
    #include"..\\GraphicsLibraryMathematics\\glm.hpp"
    #include"..\\GraphicsLibraryMathematics\\gtc\\matrix_transform.hpp"
    #include"..\\GraphicsLibraryMathematics\\gtc\\type_ptr.hpp"
#pragma warning(pop)

namespace NDespair
{
    class CAudio;
    namespace NAudio
    {
        class CSound;
        class CTrack;
    }
    class CDebug;
    class CInput;
    class CNetwork;
    class CSpace;
    class CTime;
    class CVideo;
    namespace NVideo
    {
        class CCharacter;
        class CElementBufferObject;
        class CFont;
        class CShader;
        class CTexture;
        class CVertexArrayObject;
        class CVertexBufferObject;
    }
}

#pragma warning(disable : 26495)
#pragma once

#include<array>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<numbers>
#include<random>
#include<source_location>
#include<string>
#include<vector>

#pragma warning(push)
    #pragma warning(disable : 4267 4551 6001 6385 6386 26451 26495 26819 33010)
    #include"..\\OpenAssetImportLibrary\\scene.h"
    #include"..\\OpenAssetImportLibrary\\cimport.h"
    #include"..\\GraphicsLibraryAddress\\gl.h"
    #include"..\\SimpleDirectMediaLayer\\sdl.h"
    #include"..\\SimpleDirectMediaLayer\\Image\\sdl_image.h"
    #include"..\\SimpleDirectMediaLayer\\Mixer\\sdl_mixer.h"
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

namespace NDespair
{
    class CCore
    {
        public : CCore();
        public : ~CCore();
    };
}

namespace NDespair
{
    inline std::shared_ptr<CDebug> GDebug;
    inline std::shared_ptr<CTime> GTime;
    inline std::shared_ptr<CCore> GCore;
    inline std::shared_ptr<CAudio> GAudio;
    inline std::shared_ptr<CInput> GInput;
    inline std::shared_ptr<CVideo> GVideo;
    inline std::shared_ptr<CSpace> GSpace;
}

#pragma warning(disable : 26495)
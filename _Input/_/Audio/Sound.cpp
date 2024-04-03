#include"Sound.hpp"

#include"Debug.hpp"

#define _PSlot (*_GSlot)

namespace NDespair::NAudio::NSound
{
    struct SSlot
    {
        std::string _IPath;
        Mix_Chunk* _IHandle;
        std::int32_t _IChannel;
    };

    SSlot** _GSlot;
    SSlot** _GReserve;
    
    void FSlot(SSlot** _ASlot)
    {
        _GSlot = _ASlot;
    }
    void FSave()
    {
        _GReserve = _GSlot;
    }
    void FLoad()
    {
        _GSlot = _GReserve;
    }
    void FConstruct(const std::string& _APath)
    {
        _PSlot = new SSlot;
        _PSlot->_IPath = _APath.substr(_APath.find('\\'));
        GDebug.OSimpleDirectMediaLayerHandleError(_PSlot->_IHandle = Mix_LoadWAV(_APath.c_str()));
        _PSlot->_IChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug.OError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != _PSlot->_IChannel + 1);
    }
    bool FEqual(const std::string& _APath)
    {
        return(_PSlot->_IPath == _APath);
    }
    void FPlay()
    {
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_PlayChannel(_PSlot->_IChannel , _PSlot->_IHandle , 0) != _PSlot->_IChannel);
    }
    bool FIsPlaying()
    {
        return(Mix_Playing(_PSlot->_IChannel));
    }
    void FDeconstruct()
    {
        Mix_FreeChunk(_PSlot->_IHandle);
        delete _PSlot;
    }
}
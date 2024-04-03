#include"Track.hpp"

#include"Debug.hpp"

#define _PSlot (*_GSlot)

namespace NDespair::NAudio::NTrack
{
    struct SSlot
    {
        std::string _IPath;
        Mix_Music* _IHandle;
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
        GDebug.OSimpleDirectMediaLayerHandleError(_PSlot->_IHandle = Mix_LoadMUS(_APath.c_str()));
    }
    bool FEqual(const std::string& _APath)
    {
        return(_PSlot->_IPath == _APath);
    }
    void FPlay()
    {
        GDebug.OSimpleDirectMediaLayerCodeError(Mix_PlayMusic(_PSlot->_IHandle , 0));
    }
    void FPause()
    {
        Mix_PauseMusic();
    }
    void FResume()
    {
        Mix_ResumeMusic();
    }
    void FStop()
    {
        Mix_HaltMusic();
    }
    void FAccessVolume(std::uint8_t _AValue)
    {
        Mix_VolumeMusic(_AValue);
        GDebug.OError(Mix_VolumeMusic(SDL_QUERY) != _AValue);
    }
    void FDeconstruct()
    {
        Mix_FreeMusic(_PSlot->_IHandle);
        delete _PSlot;
    }
}
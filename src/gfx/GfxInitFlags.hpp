/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/

#ifndef GfxInitFlags_hpp
#define GfxInitFlags_hpp

#include <cstdint>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

namespace gfx
{

class GfxInitFlags final : public GfxRootClass
{
public:
    typedef uint32_t SdlType;
    typedef uint32_t* SdlTypePtr;

    static const char ClassName[];

    enum class GfxInitFlagsValues : int32_t
    {
        initNothing = 0,
        initTimer = SDL_INIT_TIMER,
        initAudio = SDL_INIT_AUDIO,
        initVideo = SDL_INIT_VIDEO,
        initJoystick = SDL_INIT_JOYSTICK,
        initHaptic = SDL_INIT_HAPTIC,
        initGameController = SDL_INIT_GAMECONTROLLER,
        initEvents = SDL_INIT_EVENTS,
        initEverything = SDL_INIT_EVERYTHING,
        initNoParachute = SDL_INIT_NOPARACHUTE
    };

    GfxInitFlags();

    explicit GfxInitFlags(const int32_t flags);
    explicit GfxInitFlags(GfxInitFlagsValues const& flags);

    GfxInitFlags(const GfxInitFlags&);
    GfxInitFlags(GfxInitFlags&&);

    GfxInitFlags& operator=(GfxInitFlags const&);
    GfxInitFlags& operator=(GfxInitFlags&&);

    virtual explicit operator bool() const;

    bool isNothing(void) const;
    bool isTimer(void) const;
    bool isAudio(void) const;
    bool isVideo(void) const;
    bool isJoystick(void) const;
    bool isHaptic(void) const;
    bool isGameController(void) const;
    bool isEvents(void) const;
    bool isEverything(void) const;
    bool isNoParachute(void) const;

    void setTimer(void);
    void resetTimer(void);
    void setAudio(void);
    void resetAudio(void);
    void setVideo(void);
    void resetVideo(void);
    void setJoystick(void);
    void resetJoystick(void);
    void setHaptic(void);
    void resetHaptic(void);
    void setGameController(void);
    void resetGameController(void);
    void setEvents(void);
    void resetEvents(void);
    void setEverything(void);
    void resetEverything(void);
    void setNoParachute(void);
    void resetNoParachute(void);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    uint32_t flags_;
};

}  // namespace gfx

#endif /* GfxInitFlags_hpp */

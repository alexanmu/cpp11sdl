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

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace initquit
{

class GfxInitFlags final : public GfxObject
{
public:
    typedef uint32_t SdlType;
    typedef uint32_t* SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;

    enum class ValueType : int32_t
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

    GfxInitFlags() noexcept;

    explicit GfxInitFlags(const int32_t flags) noexcept;
    explicit GfxInitFlags(const ValueType flags) noexcept;

    GfxInitFlags(GfxInitFlags const& other) noexcept;
    GfxInitFlags(GfxInitFlags&& other) noexcept;

    GfxInitFlags& operator=(GfxInitFlags const& other) noexcept;
    GfxInitFlags& operator=(GfxInitFlags&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isNothing(void) const noexcept;
    bool isTimer(void) const noexcept;
    bool isAudio(void) const noexcept;
    bool isVideo(void) const noexcept;
    bool isJoystick(void) const noexcept;
    bool isHaptic(void) const noexcept;
    bool isGameController(void) const noexcept;
    bool isEvents(void) const noexcept;
    bool isEverything(void) const noexcept;
    bool isNoParachute(void) const noexcept;

    void setTimer(void) noexcept;
    void resetTimer(void) noexcept;
    void setAudio(void) noexcept;
    void resetAudio(void) noexcept;
    void setVideo(void) noexcept;
    void resetVideo(void) noexcept;
    void setJoystick(void) noexcept;
    void resetJoystick(void) noexcept;
    void setHaptic(void) noexcept;
    void resetHaptic(void) noexcept;
    void setGameController(void) noexcept;
    void resetGameController(void) noexcept;
    void setEvents(void) noexcept;
    void resetEvents(void) noexcept;
    void setEverything(void) noexcept;
    void resetEverything(void) noexcept;
    void setNoParachute(void) noexcept;
    void resetNoParachute(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    uint32_t flags_;
};

}  // namespace initquit

}  // namespace gfx

#endif /* GfxInitFlags_hpp */

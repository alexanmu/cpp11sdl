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

#ifndef GfxKeymod_hpp
#define GfxKeymod_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace keycode
{

class GfxKeymod final : public GfxObject
{
public:
    typedef sdl2::SDL_Keymod SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint16_t
    {
        kmodNone = sdl2::KMOD_NONE,
        kmodLShift = sdl2::KMOD_LSHIFT,
        kmodRShift = sdl2::KMOD_RSHIFT,
        kmodLCtrl = sdl2::KMOD_LCTRL,
        kmodRCtrl = sdl2::KMOD_RCTRL,
        kmodLAlt = sdl2::KMOD_LALT,
        kmodRAlt = sdl2::KMOD_RALT,
        kmodLGui = sdl2::KMOD_LGUI,
        kmodRGui = sdl2::KMOD_RGUI,
        kmodNum = sdl2::KMOD_NUM,
        kmodCaps = sdl2::KMOD_CAPS,
        kmodMode = sdl2::KMOD_MODE,
        kmodReserved = sdl2::KMOD_RESERVED,
    };

    GfxKeymod() noexcept;

    explicit GfxKeymod(const uint16_t mod) noexcept;
    explicit GfxKeymod(const ValueType mod) noexcept;
    explicit GfxKeymod(const SdlType mod) noexcept;

    GfxKeymod(GfxKeymod const& other) noexcept;
    GfxKeymod(GfxKeymod&& other) noexcept;

    GfxKeymod& operator=(GfxKeymod const& other) noexcept;
    GfxKeymod& operator=(GfxKeymod&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isNone(void) const noexcept;
    bool isLeftShift(void) const noexcept;
    bool isRightShift(void) const noexcept;
    bool isLeftControl(void) const noexcept;
    bool isRightControl(void) const noexcept;
    bool isLeftAlt(void) const noexcept;
    bool isRightAlt(void) const noexcept;
    bool isLeftGui(void) const noexcept;
    bool isRightGui(void) const noexcept;
    bool isNumLock(void) const noexcept;
    bool isCapsLock(void) const noexcept;
    bool isMode(void) const noexcept;

    bool isControl(void) const noexcept;
    bool isShift(void) const noexcept;
    bool isAlt(void) const noexcept;
    bool isGui(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType mod_;

    static const uint16_t kmodCtrl = sdl2::KMOD_LCTRL | sdl2::KMOD_RCTRL;
    static const uint16_t kmodShift = sdl2::KMOD_LSHIFT | sdl2::KMOD_RSHIFT;
    static const uint16_t kmodAlt = sdl2::KMOD_LALT | sdl2::KMOD_RALT;
    static const uint16_t kmodGui = sdl2::KMOD_LGUI | sdl2::KMOD_RGUI;
};

}  // namespace keycode

}  // namespace gfx

#endif /* GfxKeymod_hpp */

/*
  Giotto
  Copyright (C) 2020 George Oros

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
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace keycode
{

class GfxKeymod final : public GfxObject
{
public:
    typedef SDL_Keymod SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint16_t
    {
        kmodNone = KMOD_NONE,
        kmodLShift = KMOD_LSHIFT,
        kmodRShift = KMOD_RSHIFT,
        kmodLCtrl = KMOD_LCTRL,
        kmodRCtrl = KMOD_RCTRL,
        kmodLAlt = KMOD_LALT,
        kmodRAlt = KMOD_RALT,
        kmodLGui = KMOD_LGUI,
        kmodRGui = KMOD_RGUI,
        kmodNum = KMOD_NUM,
        kmodCaps = KMOD_CAPS,
        kmodMode = KMOD_MODE,
        kmodReserved = KMOD_RESERVED,
    };

    GfxKeymod() noexcept;

    explicit GfxKeymod(const uint16_t mod) noexcept;
    explicit GfxKeymod(const ValueType mod) noexcept;
    explicit GfxKeymod(const SdlType mod) noexcept;

    GfxKeymod(const GfxKeymod& other) noexcept;
    GfxKeymod(GfxKeymod&& other) noexcept;

    GfxKeymod& operator=(const GfxKeymod& other) noexcept;
    GfxKeymod& operator=(GfxKeymod&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

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

    static const uint16_t kmodCtrl = KMOD_LCTRL | KMOD_RCTRL;
    static const uint16_t kmodShift = KMOD_LSHIFT | KMOD_RSHIFT;
    static const uint16_t kmodAlt = KMOD_LALT | KMOD_RALT;
    static const uint16_t kmodGui = KMOD_LGUI | KMOD_RGUI;
};

}  // namespace keycode

}  // namespace gfx

#endif /* GfxKeymod_hpp */

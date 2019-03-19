/*
  Giotto
  Copyright (C) 2019 George Oros

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

#ifndef GfxKeyboard_hpp
#define GfxKeyboard_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxScancode.hpp"
#include "GfxKeycode.hpp"
#include "GfxKeymod.hpp"
#include "GfxWindow.hpp"
#include "GfxBool.hpp"
#include "GfxRect.hpp"

namespace gfx
{

namespace keyboard
{

class GfxKeyboard final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxKeyboard() noexcept;

    GfxKeyboard(const GfxKeyboard& other) noexcept;
    GfxKeyboard(GfxKeyboard&& other) noexcept;

    GfxKeyboard& operator=(const GfxKeyboard& other) noexcept;
    GfxKeyboard& operator=(GfxKeyboard&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    video::GfxWindow::SdlTypePtr getKeyboardFocus(void) const noexcept;
    const uint8_t * getKeyboardState(int32_t * numkeys) const noexcept;
    const keycode::GfxKeymod getModState(void) const noexcept;
    void setModState(const keycode::GfxKeymod& mod) const noexcept;
    const keycode::GfxKeycode getKeyFromScancode(const scancode::GfxScancode& scancode) const noexcept;
    const scancode::GfxScancode getScancodeFromKey(const keycode::GfxKeycode& keycode) const noexcept;
    const std::string getScancodeName(const scancode::GfxScancode& scancode) const noexcept;
    const scancode::GfxScancode getScancodeFromName(const std::string& name) const noexcept;
    const std::string getKeyName(const keycode::GfxKeycode& keycode) const noexcept;
    const keycode::GfxKeycode getKeyFromName(const std::string& name) const noexcept;
    void startTextInput(void) const noexcept;
    const GfxBool isTextInputActive(void) const noexcept;
    void stopTextInput(void) const noexcept;
    void setTextInputRect(const rect::GfxRect& rect) const noexcept;
    const GfxBool hasScreenKeyboardSupport(void) const noexcept;
    const GfxBool isScreenKeyboardShown(const video::GfxWindow& window) const noexcept;
};

}  // namespace keyboard

}  // namespace gfx

#endif /* GfxKeyboard_hpp */

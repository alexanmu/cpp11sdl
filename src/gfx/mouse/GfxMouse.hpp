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

#ifndef GfxMouse_hpp
#define GfxMouse_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxWindow.hpp"
#include "GfxButton.hpp"
#include "GfxBool.hpp"

namespace gfx
{

namespace mouse
{

class GfxMouse final : public GfxObject
{
public:
    typedef sdl2::SDL_Cursor * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxMouse() noexcept;

    GfxMouse(GfxMouse const& other) noexcept;
    GfxMouse(GfxMouse&& other) noexcept;

    GfxMouse& operator=(GfxMouse const& other) noexcept;
    GfxMouse& operator=(GfxMouse&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    video::GfxWindow::SdlTypePtr getMouseFocus(void) const noexcept;
    GfxButton getMouseState(int32_t * x, int32_t * y) const noexcept;
    GfxButton getGlobalMouseState(int32_t * x, int32_t * y) const noexcept;
    GfxButton getRelativeMouseState(int32_t * x, int32_t * y) const noexcept;
    void warpMouseInWindow(video::GfxWindow const& window, const int32_t x, const int32_t y) const noexcept;
    void warpMouseGlobal(const int32_t x, const int32_t y) const noexcept;
    void setRelativeMouseMode(GfxBool const& enabled) const noexcept;
    void captureMouse(GfxBool const& enabled) const noexcept;
    GfxBool getRelativeMouseMode(void) const noexcept;
};

}  // namespace mouse

}  // namespace gfx

#endif /* GfxMouse_hpp */

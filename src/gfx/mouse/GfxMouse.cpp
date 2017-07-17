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

#include <cassert>
#include <string>
#include <utility>

#include "GfxMouse.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmouse::mouse::gfx");

namespace gfx
{

namespace mouse
{

const char GfxMouse::ClassName[] = "GfxMouse";

GfxMouse::GfxMouse() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxMouse::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMouse::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

video::GfxWindow::SdlTypePtr GfxMouse::getMouseFocus(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_GetMouseFocus();
}

GfxButton GfxMouse::getMouseState(int32_t * x, int32_t * y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x != nullptr);
    assert(y != nullptr);

    uint32_t ret;

    ret = sdl2::SDL_GetMouseState(x, y);
    return GfxButton(ret);
}

GfxButton GfxMouse::getGlobalMouseState(int32_t * x, int32_t * y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x != nullptr);
    assert(y != nullptr);

    uint32_t ret;

    ret = sdl2::SDL_GetGlobalMouseState(x, y);
    return GfxButton(ret);
}

GfxButton GfxMouse::getRelativeMouseState(int32_t * x, int32_t * y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x != nullptr);
    assert(y != nullptr);

    uint32_t ret;

    ret = sdl2::SDL_GetGlobalMouseState(x, y);
    return GfxButton(ret);
}

void GfxMouse::warpMouseInWindow(video::GfxWindow const& window, const int32_t x, const int32_t y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(window);
    assert(x >= 0);
    assert(y >= 0);

    sdl2::SDL_WarpMouseInWindow(window.getAsSdlTypePtr(), x, y);
}

void GfxMouse::warpMouseGlobal(const int32_t x, const int32_t y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x >= 0);
    assert(y >= 0);

    int32_t ret;

    ret = sdl2::SDL_WarpMouseGlobal(x, y);
    assert(ret == 0);
}

void GfxMouse::setRelativeMouseMode(GfxBool const& enabled) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(enabled);

    int32_t ret;

    ret = sdl2::SDL_SetRelativeMouseMode(enabled.getAsSdlType());
    assert(ret == 0);
}

void GfxMouse::captureMouse(GfxBool const& enabled) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(enabled);

    int32_t ret;

    ret = sdl2::SDL_CaptureMouse(enabled.getAsSdlType());
    assert(ret == 0);
}

GfxBool GfxMouse::getRelativeMouseMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_GetRelativeMouseMode();
    return GfxBool(sdlbool);
}

}  // namespace mouse

}  // namespace gfx

/* EOF */

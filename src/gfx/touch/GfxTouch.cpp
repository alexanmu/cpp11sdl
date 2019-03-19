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

#include <cassert>
#include <string>
#include <utility>

#include "GfxTouch.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtouch::touch::gfx");

namespace gfx
{

namespace touch
{

const char GfxTouch::ClassName[] = "GfxTouch";

GfxTouch::GfxTouch() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxTouch::GfxTouch(const GfxTouch& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxTouch::GfxTouch(GfxTouch&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxTouch& GfxTouch::operator=(const GfxTouch& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
    }
    return *this;
}

GfxTouch& GfxTouch::operator=(GfxTouch&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxTouch::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTouch::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxTouch::getNumTouchDevices(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return SDL_GetNumTouchDevices();
}

const GfxTouchID GfxTouch::getTouchDevice(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxTouchID::SdlType id;

    id = SDL_GetTouchDevice(index);
    return GfxTouchID(id);
}

int32_t GfxTouch::getNumTouchFingers(const GfxTouchID& touchid) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(touchid);

    return SDL_GetNumTouchFingers(touchid.getAsSdlType());
}

const GfxFinger GfxTouch::getTouchFinger(const GfxTouchID& touchid, const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(touchid);
    assert(index >= 0);

    GfxFinger::SdlType * fingerPtr;

    fingerPtr = SDL_GetTouchFinger(touchid.getAsSdlType(), index);
    if (fingerPtr != nullptr)
    {
        return GfxFinger(*fingerPtr);
    }
    return GfxFinger();
}

}  // namespace touch

}  // namespace gfx

/* EOF */

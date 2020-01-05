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

#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxGesture.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgesture::gesture::gfx");

namespace gfx
{

namespace gesture
{

const char GfxGesture::ClassName[] = "GfxGesture";

GfxGesture::GfxGesture() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxGesture::GfxGesture(const GfxGesture& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxGesture::GfxGesture(GfxGesture&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxGesture& GfxGesture::operator=(const GfxGesture& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
    }
    return *this;
}

GfxGesture& GfxGesture::operator=(GfxGesture&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxGesture::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGesture::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxGesture::recordGesture(const touch::GfxTouchID& touchId) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(touchId);

    int32_t ret = SDL_RecordGesture(touchId.getAsSdlType());
    return ret;
}

int32_t GfxGesture::saveAllDollarTemplates(const rwops::GfxRwOps& rwops) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rwops);

    int32_t ret = SDL_SaveAllDollarTemplates(rwops.getAsSdlTypePtr());
    return ret;
}

int32_t GfxGesture::saveDollarTemplate(const GfxGestureID& gestureId, const rwops::GfxRwOps& rwops) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(gestureId);
    assert(rwops);

    int32_t ret = SDL_SaveDollarTemplate(gestureId.getAsSdlType(), rwops.getAsSdlTypePtr());
    return ret;
}

int32_t GfxGesture::loadDollarTemplates(const touch::GfxTouchID& touchId, const rwops::GfxRwOps& rwops) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(touchId);
    assert(rwops);

    int32_t ret = SDL_LoadDollarTemplates(touchId.getAsSdlType(), rwops.getAsSdlTypePtr());
    return ret;
}


}  // namespace gesture

}  // namespace gfx

/* EOF */

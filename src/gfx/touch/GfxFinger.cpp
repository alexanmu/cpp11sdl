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
#include <string>
#include <utility>

#include "GfxFinger.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxfinger::touch::gfx");

namespace gfx
{

namespace touch
{

const char GfxFinger::ClassName[] = "GfxFinger";

GfxFinger::GfxFinger() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxFinger::GfxFinger(const SdlType finger) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(finger.id >= 0);

    finger_ = finger;
}

GfxFinger::GfxFinger(const GfxFinger& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    finger_ = other.finger_;
}

GfxFinger::GfxFinger(GfxFinger&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    finger_ = other.finger_;
    // Delete other's data
    other.clear();
}

GfxFinger& GfxFinger::operator=(const GfxFinger& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        finger_ = other.finger_;
    }
    return *this;
}

GfxFinger& GfxFinger::operator=(GfxFinger&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        finger_ = other.finger_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxFinger::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxFinger::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxFingerID GfxFinger::getId(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxFingerID(finger_.id);
}

float GfxFinger::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return finger_.x;
}

float GfxFinger::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return finger_.y;
}

float GfxFinger::getPressure(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return finger_.pressure;
}

void GfxFinger::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    finger_.id = static_cast<GfxFingerID::SdlType>(-1);
    finger_.x = 0.0f;
    finger_.y = 0.0f;
    finger_.pressure = 0.0f;
}

GfxFinger::SdlType GfxFinger::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return finger_;
}

}  // namespace touch

}  // namespace gfx

/* EOF */

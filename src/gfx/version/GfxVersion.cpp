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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxVersion.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxversion::version::gfx");

namespace gfx
{

namespace version
{

const char GfxVersion::ClassName[] = "GfxVersion";

GfxVersion::GfxVersion() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxVersion::GfxVersion(const uint8_t major, const uint8_t minor, const uint8_t patch) noexcept :
            GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    ver_.major = major;
    ver_.minor = minor;
    ver_.patch = patch;
}

GfxVersion::GfxVersion(const SdlType ver) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    ver_ = ver;
}

GfxVersion::GfxVersion(const GfxVersion& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    ver_ = other.ver_;
}

GfxVersion::GfxVersion(GfxVersion&& other) noexcept : GfxObject(std::move(other))
{
    ver_ = other.ver_;
    // Delete other's data
    other.clear();
}

GfxVersion& GfxVersion::operator=(const GfxVersion& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        ver_ = other.ver_;
    }
    return *this;
}

GfxVersion& GfxVersion::operator=(GfxVersion&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        ver_ = other.ver_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxVersion::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxVersion::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

uint8_t GfxVersion::getMajor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ver_.major;
}

uint8_t GfxVersion::getMinor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ver_.minor;
}

uint8_t GfxVersion::getPatch(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ver_.patch;
}

void GfxVersion::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    ver_.major = 0;
    ver_.minor = 0;
    ver_.patch = 0;
}

const std::string GfxVersion::getAsString(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string str;

    str = std::to_string(ver_.major) + "." + std::to_string(ver_.minor) + "." + std::to_string(ver_.patch);
    return str;
}

GfxVersion::SdlType GfxVersion::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ver_;
}

GfxVersion::SdlTypePtr GfxVersion::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&ver_;
}

}  // namespace version

}  // namespace gfx

/* EOF */

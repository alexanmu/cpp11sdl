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

#include <string>

#include "GfxVersion.hpp"

namespace gfx
{

const char GfxVersion::ClassName[] = "GfxVersion";

GfxVersion::GfxVersion() : GfxRootClass(ClassName)
{
    clear();
}

GfxVersion::GfxVersion(const uint8_t major, const uint8_t minor, const uint8_t patch) : GfxRootClass(ClassName)
{
    ver_.major = major;
    ver_.minor = minor;
    ver_.patch = patch;
}

GfxVersion::GfxVersion(const SdlType ver) : GfxRootClass(ClassName)
{
    ver_ = ver;
}

GfxVersion::GfxVersion(GfxVersion const& other) : GfxRootClass(ClassName)
{
    ver_ = other.ver_;
}

GfxVersion::GfxVersion(GfxVersion&& other) : GfxRootClass(ClassName)
{
    ver_ = other.ver_;
    // Delete other's data
    other.clear();
}

GfxVersion& GfxVersion::operator=(GfxVersion const& other)
{
    if (this != &other)
    {
        ver_ = other.ver_;
    }
    return *this;
}

GfxVersion& GfxVersion::operator=(GfxVersion&& other)
{
    if (this != &other)
    {
        ver_ = other.ver_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

uint8_t GfxVersion::getMajor(void) const
{
    return ver_.major;
}

uint8_t GfxVersion::getMinor(void) const
{
    return ver_.minor;
}

uint8_t GfxVersion::getPatch(void) const
{
    return ver_.patch;
}

void GfxVersion::set(const SdlType ver)
{
    ver_ = ver;
}

void GfxVersion::clear(void)
{
    ver_.major = 0;
    ver_.minor = 0;
    ver_.patch = 0;
}

std::string GfxVersion::getAsString(void) const
{
    std::string str;

    str = std::to_string(ver_.major) + "." + std::to_string(ver_.minor) + "." + std::to_string(ver_.patch);
    return str;
}

GfxVersion::SdlType GfxVersion::getAsSdlType(void) const
{
    return ver_;
}

GfxVersion::SdlTypePtr GfxVersion::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&ver_;
}

}  // namespace gfx

/* EOF */

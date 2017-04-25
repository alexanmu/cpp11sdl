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

GfxVersion::GfxVersion() : GfxRootClass("GfxVersion")
{
    ver_.major = 0;
    ver_.minor = 0;
    ver_.patch = 0;
}

GfxVersion::GfxVersion(uint8_t major, uint8_t minor, uint8_t patch) : GfxRootClass("GfxVersion")
{
    ver_.major = major;
    ver_.minor = minor;
    ver_.patch = patch;
}

GfxVersion::GfxVersion(SdlType ver) : GfxRootClass("GfxVersion")
{
    ver_ = ver;
}

GfxVersion::GfxVersion(GfxVersion const& other) : GfxRootClass("GfxVersion")
{
    ver_ = other.ver_;
}

GfxVersion::GfxVersion(GfxVersion&& other) : GfxRootClass("GfxVersion")
{
    ver_ = other.ver_;
    // Delete other's data
    other.ver_.major = 0;
    other.ver_.minor = 0;
    other.ver_.patch = 0;
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
        other.ver_.major = 0;
        other.ver_.minor = 0;
        other.ver_.patch = 0;
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

void GfxVersion::set(SdlType ver)
{
    ver_ = ver;
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

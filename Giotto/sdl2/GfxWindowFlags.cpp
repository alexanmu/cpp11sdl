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

#include "GfxWindowFlags.hpp"

GfxWindowFlags::GfxWindowFlags() : GfxRootClass("GfxWindowFlags")
{
    flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowUnknown);
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlagsValues flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = static_cast<SdlType>(flag);
}

GfxWindowFlags::GfxWindowFlags(SdlType flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = flag;
}

GfxWindowFlags::GfxWindowFlags(SdlTypePtr flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = *flag;
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlags const& other) : GfxRootClass("GfxWindowFlags")
{
    flags_ = other.flags_;
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlags&& other) : GfxRootClass("GfxWindowFlags")
{
    flags_ = other.flags_;
    // Delete other's data
    other.flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowUnknown);
}

GfxWindowFlags& GfxWindowFlags::operator=(GfxWindowFlags const& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxWindowFlags& GfxWindowFlags::operator=(GfxWindowFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowUnknown);
    }
    return *this;
}

GfxWindowFlags::SdlType GfxWindowFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxWindowFlags::SdlTypePtr GfxWindowFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

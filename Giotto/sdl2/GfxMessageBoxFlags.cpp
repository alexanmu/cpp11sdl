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

#include "GfxMessageBoxFlags.hpp"

GfxMessageBoxFlags::GfxMessageBoxFlags() : GfxRootClass("GfxMessageBoxFlags"), flag_(GfxMessageBoxFlagsValues::flagError)
{
    // Nothing to do
}

GfxMessageBoxFlags::GfxMessageBoxFlags(GfxMessageBoxFlagsValues flag) : GfxRootClass("GfxMessageBoxFlags"), flag_(flag)
{
    // Nothing to do
}

GfxMessageBoxFlags::GfxMessageBoxFlags(SdlType flag) : GfxRootClass("GfxMessageBoxFlags")
{
    flag_ = static_cast<GfxMessageBoxFlagsValues>(flag);
}

GfxMessageBoxFlags::GfxMessageBoxFlags(SdlTypePtr flag) : GfxRootClass("GfxMessageBoxFlags")
{
    flag_ = static_cast<GfxMessageBoxFlagsValues>(*flag);
}

GfxMessageBoxFlags::GfxMessageBoxFlags(const GfxMessageBoxFlags& other) : GfxRootClass("GfxMessageBoxFlags")
{
    flag_ = other.flag_;
}

GfxMessageBoxFlags::GfxMessageBoxFlags(GfxMessageBoxFlags&& other) : GfxRootClass("GfxMessageBoxFlags")
{
    flag_ = other.flag_;
    // Delete other's data
    other.flag_ = GfxMessageBoxFlagsValues::flagError;
}

GfxMessageBoxFlags& GfxMessageBoxFlags::operator=(const GfxMessageBoxFlags& other)
{
    if (this != &other)
    {
        flag_ = other.flag_;
    }
    return *this;
}

GfxMessageBoxFlags& GfxMessageBoxFlags::operator=(GfxMessageBoxFlags&& other)
{
    if (this != &other)
    {
        flag_ = other.flag_;
        // Delete other's data
        other.flag_ = GfxMessageBoxFlagsValues::flagError;
    }
    return *this;
}

bool GfxMessageBoxFlags::operator==(const GfxMessageBoxFlags& other)
{
    return (flag_ == other.flag_);
}

GfxMessageBoxFlags::GfxMessageBoxFlagsValues GfxMessageBoxFlags::getFlag(void) const
{
    return flag_;
}

GfxMessageBoxFlags::SdlType GfxMessageBoxFlags::getAsSdlType(void) const
{
    return (SdlType)flag_;
}

GfxMessageBoxFlags::SdlTypePtr GfxMessageBoxFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)flag_;
}

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

#include "GfxMessageBoxFlags.hpp"

namespace gfx
{

const char GfxMessageBoxFlags::ClassName[] = "GfxMessageBoxFlags";

GfxMessageBoxFlags::GfxMessageBoxFlags() : GfxRootClass(ClassName)
{
    clear();
}

GfxMessageBoxFlags::GfxMessageBoxFlags(ValueType flag) : GfxRootClass(ClassName)
{
    flag_ = static_cast<SdlType>(flag);
}

GfxMessageBoxFlags::GfxMessageBoxFlags(const SdlType flag) : GfxRootClass(ClassName)
{
    assert(flag > 0);

    flag_ = flag;
}

GfxMessageBoxFlags::GfxMessageBoxFlags(const GfxMessageBoxFlags& other) : GfxRootClass(ClassName)
{
    flag_ = other.flag_;
}

GfxMessageBoxFlags::GfxMessageBoxFlags(GfxMessageBoxFlags&& other) : GfxRootClass(ClassName)
{
    flag_ = other.flag_;
    // Delete other's data
    other.clear();
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
        other.clear();
    }
    return *this;
}

bool GfxMessageBoxFlags::operator==(const GfxMessageBoxFlags& other)
{
    return (flag_ == other.flag_);
}

GfxMessageBoxFlags::operator bool() const
{
    return true;
}

GfxMessageBoxFlags::ValueType GfxMessageBoxFlags::getFlag(void) const
{
    return static_cast<ValueType>(flag_);
}

bool GfxMessageBoxFlags::isError(void) const
{
    return (flag_ == sdl2::SDL_MESSAGEBOX_ERROR);
}

bool GfxMessageBoxFlags::isWarning(void) const
{
    return (flag_ == sdl2::SDL_MESSAGEBOX_WARNING);
}

bool GfxMessageBoxFlags::isInformation(void) const
{
    return (flag_ == sdl2::SDL_MESSAGEBOX_INFORMATION);
}

void GfxMessageBoxFlags::clear(void)
{
    flag_ = static_cast<SdlType>(ValueType::flagError);
}

GfxMessageBoxFlags::SdlType GfxMessageBoxFlags::getAsSdlType(void) const
{
    return (SdlType)flag_;
}

GfxMessageBoxFlags::SdlTypePtr GfxMessageBoxFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flag_;
}

}  // namespace gfx

/* EOF */

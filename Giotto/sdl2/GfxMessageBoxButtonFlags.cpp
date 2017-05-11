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

#include "GfxMessageBoxButtonFlags.hpp"

namespace gfx
{

const char GfxMessageBoxButtonFlags::ClassName[] = "GfxMessageBoxButtonFlags";

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags() : GfxRootClass(ClassName)
{
    flags_ = static_cast<SdlType>(GfxMessageBoxButtonFlagsValues::noneDefault);
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const GfxMessageBoxButtonFlagsValues flags) :
        GfxRootClass(ClassName)
{
    flags_ = static_cast<SdlType>(flags);
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const SdlType flags) : GfxRootClass(ClassName)
{
    flags_ = flags;
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const GfxMessageBoxButtonFlags& other) :
        GfxRootClass(ClassName)
{
    flags_ = other.flags_;
}
GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags&& other) :
        GfxRootClass(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.flags_ = static_cast<SdlType>(GfxMessageBoxButtonFlagsValues::noneDefault);
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(const GfxMessageBoxButtonFlags& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(GfxMessageBoxButtonFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.flags_ = static_cast<SdlType>(GfxMessageBoxButtonFlagsValues::noneDefault);
    }
    return *this;
}

bool GfxMessageBoxButtonFlags::operator==(const GfxMessageBoxButtonFlags& other)
{
    return (flags_ == other.flags_);
}

bool GfxMessageBoxButtonFlags::isReturnDefault(void) const
{
    return (flags_ == sdl2::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT);
}

bool GfxMessageBoxButtonFlags::isEscDefault(void) const
{
    return (flags_ == sdl2::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT);
}

GfxMessageBoxButtonFlags::SdlType GfxMessageBoxButtonFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxMessageBoxButtonFlags::SdlTypePtr GfxMessageBoxButtonFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

}  // namespace gfx

/* EOF */

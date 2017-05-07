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

#include "GfxBlendMode.hpp"

namespace gfx
{

const std::string GfxBlendMode::ClassName = "GfxBlendMode";

GfxBlendMode::GfxBlendMode() : GfxRootClass(ClassName)
{
    blendmode_ = static_cast<SdlType>(GfxBlendModeValues::blendNone);
}

GfxBlendMode::GfxBlendMode(const GfxBlendModeValues blendmode) : GfxRootClass(ClassName)
{
    blendmode_ = static_cast<SdlType>(blendmode);
}

GfxBlendMode::GfxBlendMode(const SdlType blendmode) : GfxRootClass(ClassName)
{
    blendmode_ = blendmode;
}

GfxBlendMode::GfxBlendMode(const GfxBlendMode& other) : GfxRootClass(ClassName)
{
    blendmode_ = other.blendmode_;
}

GfxBlendMode::GfxBlendMode(GfxBlendMode&& other) : GfxRootClass(ClassName)
{
    blendmode_ = other.blendmode_;
    // Destroy other's data
    other.blendmode_ = static_cast<SdlType>(GfxBlendModeValues::blendNone);
}

GfxBlendMode& GfxBlendMode::operator=(const GfxBlendMode& other)
{
    if (this != &other)
    {
        blendmode_ = other.blendmode_;
    }
    return *this;
}

GfxBlendMode& GfxBlendMode::operator=(GfxBlendMode&& other)
{
    if (this != &other)
    {
        blendmode_ = other.blendmode_;
        // Destroy other's data
        other.blendmode_ = static_cast<SdlType>(GfxBlendModeValues::blendNone);
    }
    return *this;
}

bool GfxBlendMode::operator==(const GfxBlendMode& other)
{
    return (blendmode_ == other.blendmode_);
}

GfxBlendMode::GfxBlendModeValues GfxBlendMode::getBlendMode(void) const
{
    return static_cast<GfxBlendModeValues>(blendmode_);
}

bool GfxBlendMode::isBlend(void) const
{
    return (blendmode_ == sdl2::SDL_BLENDMODE_BLEND);
}

bool GfxBlendMode::isAdd(void) const
{
    return (blendmode_ == sdl2::SDL_BLENDMODE_ADD);
}

bool GfxBlendMode::isMod(void) const
{
    return (blendmode_ == sdl2::SDL_BLENDMODE_MOD);
}

GfxBlendMode::SdlType GfxBlendMode::getAsSdlType(void) const
{
    return (SdlType)blendmode_;
}

GfxBlendMode::SdlTypePtr GfxBlendMode::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)blendmode_;
}

}  // namespace gfx

/* EOF */

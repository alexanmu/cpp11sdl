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
#include <cstring>
#include <string>

#include "GfxRendererInfo.hpp"

namespace gfx
{

const char GfxRendererInfo::ClassName[] = "GfxRendererInfo";

GfxRendererInfo::GfxRendererInfo() : GfxRootClass(ClassName)
{
    clear();
}

GfxRendererInfo::GfxRendererInfo(SdlType info) : GfxRootClass(ClassName)
{
    info_ = info;
}

GfxRendererInfo::GfxRendererInfo(const GfxRendererInfo& other) : GfxRootClass(ClassName)
{
    info_ = other.info_;
}

GfxRendererInfo::GfxRendererInfo(GfxRendererInfo&& other) : GfxRootClass(ClassName)
{
    info_ = other.info_;
    // Delete other's data
    other.clear();
}

GfxRendererInfo& GfxRendererInfo::operator=(const GfxRendererInfo& other)
{
    if (this != &other)
    {
        info_ = other.info_;
    }
    return *this;
}

GfxRendererInfo& GfxRendererInfo::operator=(GfxRendererInfo&& other)
{
    if (this != &other)
    {
        info_ = other.info_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxRendererInfo::operator bool() const
{
    return true;
}

std::string GfxRendererInfo::getName(void) const
{
    std::string str;

    str = info_.name;
    return str;
}

uint32_t GfxRendererInfo::getFlags(void) const
{
    return info_.flags;
}

uint32_t GfxRendererInfo::getNumTextureFormats(void) const
{
    return info_.num_texture_formats;
}

GfxRendererInfo::GfxTextureFormats GfxRendererInfo::getTextureFormats(void) const
{
    GfxTextureFormats tf;
    uint32_t max;

    std::memset(reinterpret_cast<void *>(&tf.formats[0]), 0, sizeof(tf.formats));
    if (info_.num_texture_formats > kTextureFormatsArrayLength)
    {
        max = kTextureFormatsArrayLength;
    }
    else
    {
        max = info_.num_texture_formats;
    }
    for (uint32_t i = 0; i < max; i++)
    {
        tf[i] = info_.texture_formats[i];
    }
    return tf;
}

int32_t GfxRendererInfo::getMaxTextureWidth(void) const
{
    return info_.max_texture_width;
}

int32_t GfxRendererInfo::getMaxTextureHeight(void) const
{
    return info_.max_texture_height;
}

void GfxRendererInfo::set(const SdlType info)
{
    info_ = info;
}

void GfxRendererInfo::clear(void)
{
    info_.name = nullptr;
    info_.flags = 0;
    info_.num_texture_formats = 0;
    for (int i = 0; i < kTextureFormatsArrayLength; i++)
    {
        info_.texture_formats[i] = 0;
    }
    info_.max_texture_width = -1;
    info_.max_texture_height = -1;
}

GfxRendererInfo::SdlType GfxRendererInfo::getAsSdlType(void) const
{
    return (SdlType)info_;
}

GfxRendererInfo::SdlTypePtr GfxRendererInfo::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&info_;
}

}  // namespace gfx

/* EOF */

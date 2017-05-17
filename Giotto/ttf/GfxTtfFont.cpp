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

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxTtfFont.hpp"

namespace gfx
{

namespace ttf
{

const char GfxTtfFont::ClassName[] = "GfxTtfFont";

GfxTtfFont::GfxTtfFont() : GfxRootClass(ClassName)
{
    clear();
}

GfxTtfFont::GfxTtfFont(std::string const& filename, int32_t pointsize) : GfxRootClass(ClassName)
{
    ttf_ = sdl2::TTF_OpenFont(filename.c_str(), pointsize);
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = -1;
}

GfxTtfFont::GfxTtfFont(std::string const& filename, int32_t pointsize, int32_t index) : GfxRootClass(ClassName)
{
    ttf_ = sdl2::TTF_OpenFontIndex(filename.c_str(), pointsize, index);
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = index;
}

GfxTtfFont::GfxTtfFont(GfxTtfFont&& other) : GfxRootClass(ClassName)
{
    ttf_ = other.ttf_;
    fileName_ = other.fileName_;
    pointSize_ = other.pointSize_;
    index_ = other.index_;
    // Delete other's data
    other.clear();
}

GfxTtfFont& GfxTtfFont::operator=(GfxTtfFont&& other)
{
    if (this != &other)
    {
        ttf_ = other.ttf_;
        fileName_ = other.fileName_;
        pointSize_ = other.pointSize_;
        index_ = other.index_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTtfFont::~GfxTtfFont(void)
{
    if (ttf_ != nullptr)
    {
        sdl2::TTF_CloseFont(ttf_);
    }
}

void GfxTtfFont::openFont(std::string const& filename, int32_t pointsize) throw(std::runtime_error)
{
    if (ttf_ == nullptr)
    {
        throw std::runtime_error("Font already loaded");
    }
    ttf_ = sdl2::TTF_OpenFont(filename.c_str(), pointsize);
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = -1;
}

void GfxTtfFont::openFont(std::string const& filename, int32_t pointsize, int32_t index) throw(std::runtime_error)
{
    if (ttf_ == nullptr)
    {
        throw std::runtime_error("Font already loaded");
    }
    ttf_ = sdl2::TTF_OpenFontIndex(filename.c_str(), pointsize, index);
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = index;
}

void GfxTtfFont::closeFont(void)
{
    if (ttf_ != nullptr)
    {
        sdl2::TTF_CloseFont(ttf_);
        ttf_ = nullptr;
    }
}

void GfxTtfFont::clear(void)
{
    ttf_ = nullptr;
    fileName_ = "";
    pointSize_ = -1;
    index_ = -1;
}

GfxTtfFont::SdlTypePtr GfxTtfFont::getAsSdlTypePtr(void) const
{
    return ttf_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */

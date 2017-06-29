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

#include "GfxTextSettingsType.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

const char GfxTextSettingsType::ClassName[] = "GfxTextSettingsType";

GfxTextSettingsType::GfxTextSettingsType() noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    clear();
}

GfxTextSettingsType::GfxTextSettingsType(const BgiType textsettings) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    textSettings_ = textsettings;
}

GfxTextSettingsType::GfxTextSettingsType(GfxTextSettingsType const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    textSettings_ = other.textSettings_;
}

GfxTextSettingsType::GfxTextSettingsType(GfxTextSettingsType&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    textSettings_ = other.textSettings_;
    // Delete other's value
    other.clear();
}

GfxTextSettingsType& GfxTextSettingsType::operator=(GfxTextSettingsType const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        textSettings_ = other.textSettings_;
    }
    return *this;
}

GfxTextSettingsType& GfxTextSettingsType::operator=(GfxTextSettingsType&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        textSettings_ = other.textSettings_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxTextSettingsType::operator bool() const noexcept
{
    TRACE_P0();
    return true;
}

GfxFonts GfxTextSettingsType::getFont(void) const noexcept
{
    TRACE_P0();
    return GfxFonts(textSettings_.font);
}

GfxDirection GfxTextSettingsType::getDirection(void) const noexcept
{
    TRACE_P0();
    return GfxDirection(textSettings_.direction);
}

int32_t GfxTextSettingsType::getCharSize(void) const noexcept
{
    TRACE_P0();
    return textSettings_.charsize;
}

GfxTextJustification GfxTextSettingsType::getHorizontalJustification(void) const noexcept
{
    TRACE_P0();
    return GfxTextJustification(textSettings_.horiz);
}

GfxTextJustification GfxTextSettingsType::getVerticalJustification(void) const noexcept
{
    TRACE_P0();
    return GfxTextJustification(textSettings_.vert);
}

void GfxTextSettingsType::setValue(const BgiType textsettings) noexcept
{
    TRACE_P0();
    textSettings_ = textsettings;
}

void GfxTextSettingsType::clear(void) noexcept
{
    TRACE_P0();
    textSettings_.font = prv::GfxCanvasBgi::bgiFonts::DEFAULT_FONT;
    textSettings_.direction = prv::GfxCanvasBgi::bgiDirection::HORIZ_DIR;
    textSettings_.charsize = -1;
    textSettings_.horiz = prv::GfxCanvasBgi::bgiTextJustification::LEFT_TEXT;
    textSettings_.vert = prv::GfxCanvasBgi::bgiTextJustification::TOP_TEXT;
}

GfxTextSettingsType::BgiType GfxTextSettingsType::getAsBgiType(void) const noexcept
{
    TRACE_P0();
    return textSettings_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

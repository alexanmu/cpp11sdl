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

#include "GfxLineSettingsType.hpp"

namespace gfx
{

namespace bgi
{

const char GfxLineSettingsType::ClassName[] = "GfxLineSettingsType";

GfxLineSettingsType::GfxLineSettingsType() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxLineSettingsType::GfxLineSettingsType(const BgiType linesettings) noexcept : GfxObject(ClassName)
{
    lineSettings_ = linesettings;
}

GfxLineSettingsType::GfxLineSettingsType(GfxLineSettingsType const& other) noexcept : GfxObject(ClassName)
{
    lineSettings_ = other.lineSettings_;
}

GfxLineSettingsType::GfxLineSettingsType(GfxLineSettingsType&& other) noexcept : GfxObject(ClassName)
{
    lineSettings_ = other.lineSettings_;
    // Delete other's value
    other.clear();
}

GfxLineSettingsType& GfxLineSettingsType::operator=(GfxLineSettingsType const& other) noexcept
{
    if (this != &other)
    {
        lineSettings_ = other.lineSettings_;
    }
    return *this;
}

GfxLineSettingsType& GfxLineSettingsType::operator=(GfxLineSettingsType&& other) noexcept
{
    if (this != &other)
    {
        lineSettings_ = other.lineSettings_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxLineSettingsType::operator bool() const noexcept
{
    return true;
}

GfxLineStyle GfxLineSettingsType::getLineStyle(void) const noexcept
{
    return GfxLineStyle(lineSettings_.linestyle);
}

GfxFillStyles GfxLineSettingsType::getFillStyles(void) const noexcept
{
    return GfxFillStyles(lineSettings_.upattern);
}

GfxLineThickness GfxLineSettingsType::getLineThickness(void) const noexcept
{
    return GfxLineThickness(lineSettings_.thickness);
}

void GfxLineSettingsType::setValue(const BgiType linesettings) noexcept
{
    lineSettings_ = linesettings;
}

void GfxLineSettingsType::clear(void) noexcept
{
    lineSettings_.linestyle = prv::GfxCanvasBgi::bgiLineStyle::SOLID_LINE;
    lineSettings_.upattern = prv::GfxCanvasBgi::bgiFillStyles::EMPTY_FILL;
    lineSettings_.thickness = prv::GfxCanvasBgi::bgiLineThickness::NORM_WIDTH;
}

GfxLineSettingsType::BgiType GfxLineSettingsType::getAsBgiType(void) const noexcept
{
    return lineSettings_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

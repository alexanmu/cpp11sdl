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

#include "GfxFillSettingsType.hpp"

namespace gfx
{

namespace bgi
{

const char GfxFillSettingsType::ClassName[] = "GfxFillSettingsType";

GfxFillSettingsType::GfxFillSettingsType() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxFillSettingsType::GfxFillSettingsType(const BgiType fillsettings) noexcept : GfxObject(ClassName)
{
    fillSettings_ = fillsettings;
}

GfxFillSettingsType::GfxFillSettingsType(GfxFillSettingsType const& other) noexcept : GfxObject(ClassName)
{
    fillSettings_ = other.fillSettings_;
}

GfxFillSettingsType::GfxFillSettingsType(GfxFillSettingsType&& other) noexcept : GfxObject(ClassName)
{
    fillSettings_ = other.fillSettings_;
    // Delete other's value
    other.clear();
}

GfxFillSettingsType& GfxFillSettingsType::operator=(GfxFillSettingsType const& other) noexcept
{
    if (this != &other)
    {
        fillSettings_ = other.fillSettings_;
    }
    return *this;
}

GfxFillSettingsType& GfxFillSettingsType::operator=(GfxFillSettingsType&& other) noexcept
{
    if (this != &other)
    {
        fillSettings_ = other.fillSettings_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxFillSettingsType::operator bool() const noexcept
{
    return true;
}

GfxFillStyles GfxFillSettingsType::getFillStyles(void) const noexcept
{
    return GfxFillStyles(fillSettings_.pattern);
}

GfxColors2 GfxFillSettingsType::getColors2(void) const noexcept
{
    return GfxColors2(fillSettings_.color);
}

void GfxFillSettingsType::setValue(const BgiType fillsettings) noexcept
{
    fillSettings_ = fillsettings;
}

void GfxFillSettingsType::clear(void) noexcept
{
    fillSettings_.pattern = prv::GfxCanvasBgi::bgiFillStyles::EMPTY_FILL;
    fillSettings_.color = prv::GfxCanvasBgi::bgiColors::BLACK;
}

GfxFillSettingsType::BgiType GfxFillSettingsType::getAsBgiType(void) const noexcept
{
    return fillSettings_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

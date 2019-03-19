/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include "GColorScheme.hpp"
#include "GfxColor.hpp"

namespace gto
{

namespace gobj
{

const gfx::pixels::GfxColor GColorScheme::kDefaultForegroundColor { 0xFF, 0xFF, 0xFF, 0xFF };
const gfx::pixels::GfxColor GColorScheme::kDefaultBackgroundColor { 0x00, 0x00, 0x00, 0xFF };
const gfx::pixels::GfxColor GColorScheme::kDefaultBorderColor { 0xC0, 0xC0, 0xC0, 0xFF };
const gfx::pixels::GfxColor GColorScheme::kDefaultBorderShadowColor { 0x60, 0x60, 0x60, 0xFF };

GColorScheme::GColorScheme() : GObject()
{
    clear();
}

GColorScheme::GColorScheme(const GColorScheme& other) : GObject()
{
    backgroundColor_ = other.backgroundColor_;
    foregroundColor_ = other.foregroundColor_;
    borderColor_ = other.borderColor_;
    borderShadowColor_ = other.borderShadowColor_;
}

GColorScheme::GColorScheme(GColorScheme&& other) : GObject()
{
    backgroundColor_ = other.backgroundColor_;
    foregroundColor_ = other.foregroundColor_;
    borderColor_ = other.borderColor_;
    borderShadowColor_ = other.borderShadowColor_;
    // Delete other's data
    other.clear();
}

GColorScheme& GColorScheme::operator=(const GColorScheme& other)
{
    if (this != &other)
    {
        backgroundColor_ = other.backgroundColor_;
        foregroundColor_ = other.foregroundColor_;
        borderColor_ = other.borderColor_;
        borderShadowColor_ = other.borderShadowColor_;
    }
    return *this;
}

GColorScheme& GColorScheme::operator=(GColorScheme&& other)
{
    if (this != &other)
    {
        backgroundColor_ = other.backgroundColor_;
        foregroundColor_ = other.foregroundColor_;
        borderColor_ = other.borderColor_;
        borderShadowColor_ = other.borderShadowColor_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

const gfx::pixels::GfxColor& GColorScheme::getForegroundColor(void) const noexcept
{
    return foregroundColor_;
}

void GColorScheme::setForegroundColor(const gfx::pixels::GfxColor& color) noexcept
{
    assert(color);

    foregroundColor_ = color;
}

const gfx::pixels::GfxColor& GColorScheme::getBackgroundColor(void) const noexcept
{
    return backgroundColor_;
}

void GColorScheme::setBackgroundColor(const gfx::pixels::GfxColor& color) noexcept
{
    assert(color);

    backgroundColor_ = color;
}

const gfx::pixels::GfxColor& GColorScheme::getBorderColor(void) const noexcept
{
    return borderColor_;
}

void GColorScheme::setBorderColor(const gfx::pixels::GfxColor& color) noexcept
{
    assert(color);

    borderColor_ = color;
}

const gfx::pixels::GfxColor& GColorScheme::getBorderShadowColor(void) const noexcept
{
    return borderShadowColor_;
}

void GColorScheme::setBorderShadowColor(const gfx::pixels::GfxColor& color) noexcept
{
    assert(color);

    borderShadowColor_ = color;
}

void GColorScheme::setDefault(void) noexcept
{
    clear();
}

void GColorScheme::clear(void) noexcept
{
    backgroundColor_ = kDefaultBackgroundColor;
    foregroundColor_ = kDefaultForegroundColor;
    borderColor_ = kDefaultBorderColor;
    borderShadowColor_ = kDefaultBorderShadowColor;
}

}  // namespace gobj

}  // namespace gto

/* EOF */

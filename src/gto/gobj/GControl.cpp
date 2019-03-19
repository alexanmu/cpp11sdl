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
#include <cstdint>
#include <string>

#include "GControl.hpp"

namespace gto
{

namespace gobj
{

GControl::GControl(const std::string& vname, GComponent* owner) : GComponent(vname, owner)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);

    bounds_.clear();
    clientBounds_.clear();
    enabled_ = false;
    borderThikness_ = kDefaultBorderThikness;
    borderStyle_ = kDefaultBorderStyle;
    backgroundStyle_ = kDefaultBackgroundStyle;
    hint_.clear();
    showHint_ = false;
    visible_ = false;
}

GControl::~GControl()
{
    // nothing to do yet
}

void GControl::setBounds(const gfx::rect::GfxRect& bounds) noexcept
{
    assert(bounds);

    bounds_ = bounds;
    adjustClientBounds();
}

const gfx::rect::GfxRect& GControl::getBounds(void) const noexcept
{
    return bounds_;
}

const gfx::rect::GfxRect& GControl::getClientBounds(void) const noexcept
{
    return clientBounds_;
}

void GControl::setEnabled(void) noexcept
{
    enabled_ = true;
}

bool GControl::getEnabled(void) const noexcept
{
    return enabled_;
}

void GControl::setBorderThikness(const GBorderThikness& borderthikness) noexcept
{
    borderThikness_ = borderthikness;
    adjustClientBounds();
}

GBorderThikness GControl::getBorderThikness(void) const noexcept
{
    return borderThikness_;
}

void GControl::setBorderStyle(const GBorderStyle& borderstyle) noexcept
{
    borderStyle_ = borderstyle;
}

GBorderStyle GControl::getBorderStyle(void) const noexcept
{
    return borderStyle_;
}

void GControl::setBackgroundStyle(const GBackgroundStyle& backgroundstyle) noexcept
{
    backgroundStyle_ = backgroundstyle;
}

GBackgroundStyle GControl::getBackgroundStyle(void) const noexcept
{
    return backgroundStyle_;
}

void GControl::setHint(const std::string& hint) noexcept
{
    hint_ = hint;
}

const std::string& GControl::getHint(void) const noexcept
{
    return hint_;
}

bool GControl::hasHint(void) const noexcept
{
    return (hint_.length() > 0);
}

void GControl::showHint(void) noexcept
{
    showHint_ = true;
}
void GControl::hideHint(void) noexcept
{
    showHint_ = false;
}

bool GControl::getShowHint(void) const noexcept
{
    return showHint_;
}

void GControl::hide(void) noexcept
{
    visible_ = false;
}

void GControl::show(void) noexcept
{
    visible_ = true;
}

bool GControl::isVisible(void) const noexcept
{
    return visible_;
}

int32_t GControl::getWidth(void) const noexcept
{
    return bounds_.getWidth();
}

int32_t GControl::getHeight(void) const noexcept
{
    return bounds_.getHeight();
}

// Private methods
void GControl::adjustClientBounds(void) noexcept
{
    uint8_t borderThikness;

    if (borderThikness_ == GBorderThikness::noBorder)
    {
        clientBounds_ = bounds_;
    }
    else
    {
        borderThikness = static_cast<uint8_t>(borderThikness_);
        clientBounds_.setX(bounds_.getX() + borderThikness);
        clientBounds_.setY(bounds_.getY() + borderThikness);
        clientBounds_.setWidth(bounds_.getWidth() - 2 * borderThikness);
        clientBounds_.setHeight(bounds_.getHeight() - 2 * borderThikness);
    }
}

}  // namespace gobj

}  // namespace gto

/* EOF */

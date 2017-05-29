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

#include "GGraphicControl.hpp"
#include "GTypes.hpp"
#include "GComponent.hpp"
#include "GfxRect.hpp"

namespace gto
{

namespace gobj
{

const gfx::GfxColor GGraphicControl::kDefaultForegroundColor { 0xFF, 0xFF, 0xFF, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBackgroundColor { 0x00, 0x00, 0x00, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBorderColor { 0xC0, 0xC0, 0xC0, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBorderShadowColor { 0x60, 0x60, 0x60, 0xFF };

GGraphicControl::GGraphicControl(std::string const& vname, GComponent * owner, const uint16_t width,
        const uint16_t height) : GControl(vname, owner)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
    assert(width <= kMaxObjectWidth);
    assert(height <= kMaxObjectHeight);

    setBounds(gfx::GfxRect(0, 0, width, height));
    foregroundColor_ = kDefaultForegroundColor;
    backgroundColor_ = kDefaultBackgroundColor;
    borderColor_ = kDefaultBorderColor;
    borderShadowColor_ = kDefaultBorderShadowColor;
    surf_.createSurface(width, height);
}

GGraphicControl::~GGraphicControl()
{
    // nothing to do yet
}

gfx::supp::GfxControlledSurface const& GGraphicControl::getSurface(void) const noexcept
{
    return surf_;
}

gfx::GfxColor const& GGraphicControl::getForegroundColor(void) const noexcept
{
    return foregroundColor_;
}

void GGraphicControl::setForegroundColor(gfx::GfxColor const& color) noexcept
{
    assert(color);

    foregroundColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBackgroundColor(void) const noexcept
{
    return backgroundColor_;
}

void GGraphicControl::setBackgroundColor(gfx::GfxColor const& color) noexcept
{
    assert(color);

    backgroundColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBorderColor(void) const noexcept
{
    return borderColor_;
}

void GGraphicControl::setBorderColor(gfx::GfxColor const& color) noexcept
{
    assert(color);

    borderColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBorderShadowColor(void) const noexcept
{
    return borderShadowColor_;
}

void GGraphicControl::setBorderShadowColor(gfx::GfxColor const& color) noexcept
{
    assert(color);

    borderShadowColor_ = color;
}

void GGraphicControl::draw(void)
{
    drawBorder();
    drawBackground();
}

//  Private methods
void GGraphicControl::drawBorder(void) noexcept
{
    gfx::GfxRect east;
    gfx::GfxRect west;
    gfx::GfxRect north;
    gfx::GfxRect south;

    gfx::GfxColor color1;
    gfx::GfxColor color2;

    if (getBorderThikness() == GBorderThikness::noBorder)
    {
        return;
    }
    switch (borderStyle_)
    {
        case GBorderStyle::flatBorder:
            color1 = borderColor_;
            color2 = borderColor_;
            break;
        case GBorderStyle::raised3DBorder:
            color1 = borderColor_;
            color2 = borderShadowColor_;
            break;
        case GBorderStyle::sunken3DBorder:
            color1 = borderShadowColor_;
            color2 = borderColor_;
            break;
    }
    east.setX(0);
    east.setY(0);
    east.setWidth(1);
    east.setHeight(bounds_.getHeight() - 1);

    north.setX(0);
    north.setY(0);
    north.setWidth(bounds_.getWidth() - 1);
    north.setHeight(1);

    south.setX(0);
    south.setY(bounds_.getHeight() - 1);
    south.setWidth(bounds_.getWidth());
    south.setHeight(1);

    west.setX(bounds_.getWidth() - 1);
    west.setY(0);
    west.setWidth(1);
    west.setHeight(bounds_.getHeight() - 1);

    surf_().fillRect(east, color1);
    surf_().fillRect(north, color1);
    surf_().fillRect(west, color2);
    surf_().fillRect(south, color2);

    if (borderThikness_ == GBorderThikness::thikBorder)
    {
        east.setX(1);
        east.setY(1);
        east.setWidth(1);
        east.setHeight(bounds_.getHeight() - 2);

        north.setX(1);
        north.setY(1);
        north.setWidth(bounds_.getWidth() - 2);
        north.setHeight(1);

        south.setX(1);
        south.setY(bounds_.getHeight() - 2);
        south.setWidth(bounds_.getWidth() - 2);
        south.setHeight(1);

        west.setX(bounds_.getWidth() - 2);
        west.setY(1);
        west.setWidth(1);
        west.setHeight(bounds_.getHeight() - 2);

        surf_().fillRect(east, color1);
        surf_().fillRect(north, color1);
        surf_().fillRect(west, color2);
        surf_().fillRect(south, color2);
    }
}

void GGraphicControl::drawBackground(void) noexcept
{
    switch (backgroundStyle_)
    {
        case GBackgroundStyle::solidColor :
            surf_().fillRect(clientBounds_, backgroundColor_);
            break;
        case GBackgroundStyle::transparentColor :
            /* Nothing to do */
            break;
    }
}

}  // namespace gobj

}  // namespace gto

/* EOF */

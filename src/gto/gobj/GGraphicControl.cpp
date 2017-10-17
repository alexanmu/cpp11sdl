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

GGraphicControl::GGraphicControl(std::string const& vname, GComponent * owner, const uint16_t width,
        const uint16_t height) : GControl(vname, owner)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
    assert(width <= kMaxObjectWidth);
    assert(height <= kMaxObjectHeight);

    setBounds(gfx::rect::GfxRect(0, 0, width, height));
    colorScheme_.setDefault();
    surf_.createSurface("GGraphicControl::" + vname, width, height);
}

GGraphicControl::~GGraphicControl()
{
    // nothing to do yet
}

gfx::surface::GfxSurface const& GGraphicControl::getSurface(void) const noexcept
{
    return surf_;
}

gfx::pixels::GfxColor const& GGraphicControl::getForegroundColor(void) const noexcept
{
    return colorScheme_.getForegroundColor();
}

void GGraphicControl::setForegroundColor(gfx::pixels::GfxColor const& color) noexcept
{
    assert(color);

    colorScheme_.setForegroundColor(color);
}

gfx::pixels::GfxColor const& GGraphicControl::getBackgroundColor(void) const noexcept
{
    return colorScheme_.getBackgroundColor();
}

void GGraphicControl::setBackgroundColor(gfx::pixels::GfxColor const& color) noexcept
{
    assert(color);

    colorScheme_.setBackgroundColor(color);
}

gfx::pixels::GfxColor const& GGraphicControl::getBorderColor(void) const noexcept
{
    return colorScheme_.getBorderColor();
}

void GGraphicControl::setBorderColor(gfx::pixels::GfxColor const& color) noexcept
{
    assert(color);

    colorScheme_.setBorderColor(color);
}

gfx::pixels::GfxColor const& GGraphicControl::getBorderShadowColor(void) const noexcept
{
    return colorScheme_.getBorderShadowColor();
}

void GGraphicControl::setBorderShadowColor(gfx::pixels::GfxColor const& color) noexcept
{
    assert(color);

    colorScheme_.setBorderShadowColor(color);
}

GColorScheme const& GGraphicControl::getColorScheme(void) const noexcept
{
    return colorScheme_;
}

void GGraphicControl::setColorScheme(GColorScheme const& colorScheme) noexcept
{
    colorScheme_ = colorScheme;
}

void GGraphicControl::draw(void)
{
    drawBorder();
    drawBackground();
}

//  Private methods
void GGraphicControl::drawBorder(void) noexcept
{
    gfx::rect::GfxRect east;
    gfx::rect::GfxRect west;
    gfx::rect::GfxRect north;
    gfx::rect::GfxRect south;

    gfx::pixels::GfxColor color1;
    gfx::pixels::GfxColor color2;

    if (getBorderThikness() == GBorderThikness::noBorder)
    {
        return;
    }
    switch (borderStyle_)
    {
        case GBorderStyle::flatBorder:
            color1 = colorScheme_.getBorderColor();
            color2 = colorScheme_.getBorderColor();
            break;
        case GBorderStyle::raised3DBorder:
            color1 = colorScheme_.getBorderColor();
            color2 = colorScheme_.getBorderShadowColor();
            break;
        case GBorderStyle::sunken3DBorder:
            color1 = colorScheme_.getBorderShadowColor();
            color2 = colorScheme_.getBorderColor();
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

    surf_.fillRect(east, color1);
    surf_.fillRect(north, color1);
    surf_.fillRect(west, color2);
    surf_.fillRect(south, color2);

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

        surf_.fillRect(east, color1);
        surf_.fillRect(north, color1);
        surf_.fillRect(west, color2);
        surf_.fillRect(south, color2);
    }
}

void GGraphicControl::drawBackground(void) noexcept
{
    switch (backgroundStyle_)
    {
        case GBackgroundStyle::solidColor :
            surf_.fillRect(clientBounds_, colorScheme_.getBackgroundColor());
            break;
        case GBackgroundStyle::transparentColor :
            /* Nothing to do */
            break;
    }
}

}  // namespace gobj

}  // namespace gto

/* EOF */

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

#include "GGraphicControl.hpp"
#include "GComponent.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxRect.hpp"

namespace giotto
{

namespace objects
{

const gfx::GfxColor GGraphicControl::kDefaultForegroundColor { 0xFF, 0xFF, 0xFF, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBackgroundColor { 0x00, 0x00, 0x00, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBorderLightColor { 0xC0, 0xC0, 0xC0, 0xFF };
const gfx::GfxColor GGraphicControl::kDefaultBorderShadowColor { 0x60, 0x60, 0x60, 0xFF };

GGraphicControl::GGraphicControl(std::string const& name, GComponent* owner, uint16_t width, uint16_t height) :
        GControl(name, owner), surf_(gfx::GfxSurfaceFlags(gfx::GfxSurfaceFlags::GfxSurfaceFlagsValues::flagSwSurface),
                                    width, height)
{
    setBounds(gfx::GfxRect(0,0, width, height));
    foregroundColor_ = kDefaultForegroundColor;
    backgroundColor_ = kDefaultBackgroundColor;
    borderLightColor_ = kDefaultBorderLightColor;
    borderShadowColor_ = kDefaultBorderShadowColor;
}

GGraphicControl::~GGraphicControl()
{
    // nothing to do yet
}

gfx::GfxSurface const& GGraphicControl::getSurface(void) const noexcept
{
    return surf_;
}

gfx::GfxColor const& GGraphicControl::getForegroundColor(void) const noexcept
{
    return foregroundColor_;
}

void GGraphicControl::setForegroundColor(gfx::GfxColor const& color) noexcept
{
    foregroundColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBackgroundColor(void) const noexcept
{
    return backgroundColor_;
}

void GGraphicControl::setBackgroundColor(gfx::GfxColor const& color) noexcept
{
    backgroundColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBorderLightColor(void) const noexcept
{
    return borderLightColor_;
}

void GGraphicControl::setBorderLightColor(gfx::GfxColor const& color) noexcept
{
    borderLightColor_ = color;
}

gfx::GfxColor const& GGraphicControl::getBorderShadowColor(void) const noexcept
{
    return borderShadowColor_;
}

void GGraphicControl::setBorderShadowColor(gfx::GfxColor const& color) noexcept
{
    borderShadowColor_ = color;
}

void GGraphicControl::draw(void)
{
    if (hasBorder() == true)
    {
        drawBorder();
    }
    surf_.fillRect(clientBounds_, backgroundColor_);
}

//  Private methods
void GGraphicControl::drawBorder(void) noexcept
{
    gfx::GfxRect east;
    gfx::GfxRect west;
    gfx::GfxRect north;
    gfx::GfxRect south;

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

    surf_.fillRect(east, borderLightColor_);
    surf_.fillRect(north, borderLightColor_);
    surf_.fillRect(west, borderShadowColor_);
    surf_.fillRect(south, borderShadowColor_);

    if (borderType_ == GBorderType::thikBorder)
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

        surf_.fillRect(east, borderLightColor_);
        surf_.fillRect(north, borderLightColor_);
        surf_.fillRect(west, borderShadowColor_);
        surf_.fillRect(south, borderShadowColor_);
    }
}

}  // namespace objects

}  // namespace giotto

/* EOF */

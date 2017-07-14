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
#include <cassert>
#include <cstdint>
#include <string>

#include "GBitmap.hpp"
#include "GTypes.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"

namespace gto
{

namespace gobj
{

GBitmap::GBitmap(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                GImageScaleMode const& scalemode, std::string const& filename) :
        GImage(vname, owner, width, height)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
    assert(width <= kMaxObjectWidth);
    assert(height <= kMaxObjectHeight);
    assert(filename.length() > 0);

    setScaleMode(scalemode);
    setFileName(filename);
}

GBitmap::~GBitmap()
{
    imgSurf_.freeSurface();
}

void GBitmap::load(void) throw(std::runtime_error)
{
    imgSurf_.createSurface("GBitmap::load", fileName_);
}

void GBitmap::draw(void) throw(std::runtime_error)
{
    gfx::rect::GfxRect imgBounds(0, 0, imgSurf_.getWidth(), imgSurf_.getHeight());
    gfx::rect::GfxRect dstBounds;

    switch (scaleMode_)
    {
        case GImageScaleMode::centerScaled:
            if ( imgSurf_.getWidth() < getClientBounds().getWidth() )
            {
                dstBounds.setX((getClientBounds().getWidth() - imgSurf_.getWidth()) / 2);
                dstBounds.setWidth(imgSurf_.getWidth());
            }
            else
            {
                dstBounds.setX(0);
                dstBounds.setWidth(getClientBounds().getWidth());
                imgBounds.setX((imgSurf_.getWidth() - getClientBounds().getWidth()) / 2);
                imgBounds.setWidth(getClientBounds().getWidth());
            }
            if ( imgSurf_.getHeight() < getClientBounds().getHeight() )
            {
                dstBounds.setY((getClientBounds().getHeight() - imgSurf_.getHeight()) / 2);
                dstBounds.setHeight(imgSurf_.getHeight());
            }
            else
            {
                dstBounds.setY(0);
                dstBounds.setHeight(getClientBounds().getHeight());
                imgBounds.setY((imgSurf_.getHeight() - getClientBounds().getHeight()) / 2);
                imgBounds.setHeight(getClientBounds().getHeight());
            }
            surf_.blitSurface(imgSurf_, imgBounds, dstBounds);
            break;
        case GImageScaleMode::strechScaled:
            surf_.blitScaled(imgSurf_, imgBounds, getClientBounds());
            break;
        case GImageScaleMode::tileScaled:
            throw std::runtime_error("Not implemented");
            break;
    };
    GImage::draw();
}

}  // namespace gobj

}  // namespace gto

/* EOF */

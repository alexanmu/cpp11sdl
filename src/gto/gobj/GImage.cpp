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
#include <cstdint>
#include <string>

#include "GImage.hpp"
#include "GTypes.hpp"

namespace gto
{

namespace gobj
{

GImage::GImage(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height) :
        GGraphicControl(vname, owner, width, height)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
    assert(width <= kMaxObjectWidth);
    assert(height <= kMaxObjectHeight);

    scaleMode_ = kDefaultImageScaleMode;
    fileName_ = "";
}

GImage::~GImage()
{
    // Nothing to do
}

GImageScaleMode GImage::getScaleMode(void) const noexcept
{
    return scaleMode_;
}

void GImage::setScaleMode(GImageScaleMode const& scalemode) noexcept
{
    scaleMode_ = scalemode;
}

std::string const& GImage::getFileName(void) const noexcept
{
    return fileName_;
}

void GImage::setFileName(std::string const& filename) noexcept
{
    assert(filename.length() > 0);

    fileName_ = filename;
}

void GImage::draw(void)
{
    GGraphicControl::draw();
}

}  // namespace gobj

}  // namespace gto

/* EOF */

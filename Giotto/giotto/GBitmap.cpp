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

#include <cstdint>
#include <string>

#include "GBitmap.hpp"
#include "GTypes.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"

namespace giotto
{

namespace objects
{

GBitmap::GBitmap(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                GImageScaleMode const& scalemode, std::string const& filename) :
        GImage(vname, owner, width, height)
{
    setScaleMode(scalemode);
    setFileName(filename);
}

GBitmap::~GBitmap()
{
    imgSurf_.free();
}

void GBitmap::load(void) throw(std::runtime_error)
{
    imgSurf_.createSurface(fileName_);
}

void GBitmap::draw(void)
{
    gfx::GfxRect imgBounds(0, 0, imgSurf_().getWidth(), imgSurf_().getHeight());

    switch (scaleMode_)
    {
        case GImageScaleMode::centerScaled:
            break;
        case GImageScaleMode::strechScaled:
            break;
        case GImageScaleMode::tileScaled:
            break;
    };
    surf_().blitScaled(imgSurf_(), imgBounds, getClientBounds());
    GImage::draw();
}

}  // namespace objects

}  // namespace giotto

/* EOF */

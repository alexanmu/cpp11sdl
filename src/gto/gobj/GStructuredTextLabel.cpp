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

#include "GStructuredTextLabel.hpp"

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>

#include "GLabel.hpp"
#include "GTypes.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"
#include "GfxTtfFont.hpp"
#include "GfxTtfFontStyle.hpp"
#include "GfxTtfFontRenderer.hpp"
#include "GfxFontInfo.hpp"

namespace gto
{

namespace gobj
{

GStructuredTextLabel::GStructuredTextLabel(std::string const& vname, GComponent* owner, uint16_t width,
                                           uint16_t height, std::string const& text, uint8_t const& textsize) :
        GLabel(vname, owner, width, height, text, textsize)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
}

void GStructuredTextLabel::draw(void)
{
    GLabel::draw();
}

}  // namespace gobj

}  // namespace gto

/* EOF */

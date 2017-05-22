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

#include "GfxClipboard.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

const char GfxClipboard::ClassName[] = "GfxClipboard";

GfxClipboard::GfxClipboard() : GfxRootClass(ClassName)
{
    // Nothing to do
}

GfxClipboard::operator bool() const
{
    return true;
}

void GfxClipboard::setClipboardText(const std::string& str) const
{
    assert(str.length() > 0);

    sdl2::SDL_SetClipboardText(str.c_str());
}

std::string GfxClipboard::getClipboardText(void) const
{
    char * c;
    std::string str { "" };

    c = sdl2::SDL_GetClipboardText();
    if (c != nullptr)
    {
        str = c;
        sdl2::SDL_free(c);
    }
    return str;
}

bool GfxClipboard::hasClipboardText(void) const
{
    return sdl2::SDL_HasClipboardText();
}

}  // namespace gfx

/* EOF */

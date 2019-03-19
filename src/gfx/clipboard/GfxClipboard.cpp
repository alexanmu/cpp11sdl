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

#include <cstdlib>
#include <cassert>
#include <string>
#include <utility>

#include "GfxClipboard.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxclipboard::clipboard::gfx");

namespace gfx
{

namespace clipboard
{

const char GfxClipboard::ClassName[] = "GfxClipboard";

GfxClipboard::GfxClipboard() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxClipboard::GfxClipboard(const GfxClipboard& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxClipboard::GfxClipboard(GfxClipboard&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxClipboard& GfxClipboard::operator=(const GfxClipboard& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(other);
    }
    return *this;
}

GfxClipboard& GfxClipboard::operator=(GfxClipboard&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxClipboard::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxClipboard::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxClipboard::setClipboardText(const std::string& str) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(str.length() > 0);

    SDL_SetClipboardText(str.c_str());
}

const std::string GfxClipboard::getClipboardText(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    char * c;
    std::string str { "" };

    c = SDL_GetClipboardText();
    if (c != nullptr)
    {
        str = c;
        SDL_free(c);
    }
    return str;
}

const GfxBool GfxClipboard::hasClipboardText(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool ret;

    ret = SDL_HasClipboardText();
    return GfxBool(ret);
}

}  // namespace clipboard

}  // namespace gfx

/* EOF */

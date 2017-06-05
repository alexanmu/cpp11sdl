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

#include "GfxWindowPosition.hpp"

namespace gfx
{

namespace video
{

const char GfxWindowPosition::ClassName[] = "GfxWindowPosition";

GfxWindowPosition::GfxWindowPosition() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxWindowPosition::GfxWindowPosition(ValueType pos, int32_t coord) noexcept : GfxObject(ClassName)
{
    assert(coord >= 0);

    pos_ = pos;
    if (pos_ == GfxWindowPosition::ValueType::positionSpecified)
    {
        if (coord <= 16384)
        {
            coord_ = coord;
        }
        else
        {
            coord_ = 100;
        }
    }
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition const& other) noexcept : GfxObject(ClassName)
{
    pos_ = other.pos_;
    coord_ = other.coord_;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition&& other) noexcept : GfxObject(ClassName)
{
    pos_ = other.pos_;
    coord_ = other.coord_;
    // Delete other's data
    other.clear();
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition const& other) noexcept
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
    }
    return *this;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition&& other) noexcept
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxWindowPosition::operator bool() const noexcept
{
    return true;
}

void GfxWindowPosition::setPosition(const ValueType pos) noexcept
{
    pos_ = pos;
}

GfxWindowPosition::ValueType GfxWindowPosition::getPosition(void) const noexcept
{
    return pos_;
}

void GfxWindowPosition::setCoordinate(const int32_t coord) noexcept
{
    assert(coord >= 0);

    coord_ = coord;
}

int32_t GfxWindowPosition::getCoordinate(void) const noexcept
{
    int32_t ret;

    switch (pos_)
    {
        case ValueType::positionUndefined:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
        case ValueType::positionCentered:
            ret = SDL_WINDOWPOS_CENTERED;
            break;
        case ValueType::positionSpecified:
            ret = coord_;
            break;
        default:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
    }
    return ret;
}

void GfxWindowPosition::clear(void) noexcept
{
    pos_ = ValueType::positionUndefined;
    coord_ = -1;
}

}  // namespace video

}  // namespace gfx

/* EOF */

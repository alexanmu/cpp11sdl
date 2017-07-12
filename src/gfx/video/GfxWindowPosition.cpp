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
#include <utility>

#include "GfxWindowPosition.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxwindowposition::video::gfx");

namespace gfx
{

namespace video
{

const char GfxWindowPosition::ClassName[] = "GfxWindowPosition";

GfxWindowPosition::GfxWindowPosition() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxWindowPosition::GfxWindowPosition(const ValueType pos, const int32_t coord) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(coord >= -1);

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

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    pos_ = other.pos_;
    coord_ = other.coord_;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    pos_ = other.pos_;
    coord_ = other.coord_;
    // Delete other's data
    other.clear();
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        pos_ = other.pos_;
        coord_ = other.coord_;
    }
    return *this;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        pos_ = other.pos_;
        coord_ = other.coord_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxWindowPosition::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxWindowPosition::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxWindowPosition::setPosition(const ValueType pos) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pos_ = pos;
}

GfxWindowPosition::ValueType GfxWindowPosition::getPosition(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pos_;
}

void GfxWindowPosition::setCoordinate(const int32_t coord) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(coord >= 0);

    coord_ = coord;
}

int32_t GfxWindowPosition::getCoordinate(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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
    LOG_TRACE_PRIO_LOW();

    pos_ = ValueType::positionUndefined;
    coord_ = -1;
}

}  // namespace video

}  // namespace gfx

/* EOF */

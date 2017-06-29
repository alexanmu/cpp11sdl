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

#include "GfxViewPortType.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

const char GfxViewPortType::ClassName[] = "GfxViewPortType";

GfxViewPortType::GfxViewPortType() noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    clear();
}

GfxViewPortType::GfxViewPortType(const BgiType viewport) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    viewPort_ = viewport;
}

GfxViewPortType::GfxViewPortType(GfxViewPortType const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    viewPort_ = other.viewPort_;
}

GfxViewPortType::GfxViewPortType(GfxViewPortType&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    viewPort_ = other.viewPort_;
    // Delete other's value
    other.clear();
}

GfxViewPortType& GfxViewPortType::operator=(GfxViewPortType const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        viewPort_ = other.viewPort_;
    }
    return *this;
}

GfxViewPortType& GfxViewPortType::operator=(GfxViewPortType&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        viewPort_ = other.viewPort_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxViewPortType::operator bool() const noexcept
{
    TRACE_P0();
    return true;
}

int32_t GfxViewPortType::getLeft() const noexcept
{
    TRACE_P0();
    return viewPort_.left;
}

int32_t GfxViewPortType::getTop() const noexcept
{
    TRACE_P0();
    return viewPort_.top;
}

int32_t GfxViewPortType::getRight() const noexcept
{
    TRACE_P0();
    return viewPort_.right;
}

int32_t GfxViewPortType::getBottom() const noexcept
{
    TRACE_P0();
    return viewPort_.bottom;
}

bool GfxViewPortType::getClip(void) const noexcept
{
    TRACE_P0();
    return viewPort_.clip;
}

void GfxViewPortType::setValue(const BgiType viewport) noexcept
{
    TRACE_P0();
    viewPort_ = viewport;
}

void GfxViewPortType::clear(void) noexcept
{
    TRACE_P0();
    viewPort_.left = -1;
    viewPort_.top = -1;
    viewPort_.right = -1;
    viewPort_.bottom = -1;
    viewPort_.clip = false;
}

GfxViewPortType::BgiType GfxViewPortType::getAsBgiType(void) const noexcept
{
    TRACE_P0();
    return viewPort_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

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

#include <string>
#include <utility>

#include "GfxViewPortType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxviewporttype::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxViewPortType::ClassName[] = "GfxViewPortType";

GfxViewPortType::GfxViewPortType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxViewPortType::GfxViewPortType(const BgiType viewport) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    viewPort_ = viewport;
}

GfxViewPortType::GfxViewPortType(const GfxViewPortType& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    viewPort_ = other.viewPort_;
}

GfxViewPortType::GfxViewPortType(GfxViewPortType&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    viewPort_ = other.viewPort_;
    // Delete other's value
    other.clear();
}

GfxViewPortType& GfxViewPortType::operator=(const GfxViewPortType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        viewPort_ = other.viewPort_;
    }
    return *this;
}

GfxViewPortType& GfxViewPortType::operator=(GfxViewPortType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        viewPort_ = other.viewPort_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxViewPortType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxViewPortType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxViewPortType::getLeft() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_.left;
}

int32_t GfxViewPortType::getTop() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_.top;
}

int32_t GfxViewPortType::getRight() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_.right;
}

int32_t GfxViewPortType::getBottom() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_.bottom;
}

bool GfxViewPortType::getClip(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_.clip;
}

void GfxViewPortType::setValue(const BgiType viewport) noexcept
{
    LOG_TRACE_PRIO_LOW();

    viewPort_ = viewport;
}

void GfxViewPortType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    viewPort_.left = -1;
    viewPort_.top = -1;
    viewPort_.right = -1;
    viewPort_.bottom = -1;
    viewPort_.clip = false;
}

GfxViewPortType::BgiType GfxViewPortType::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return viewPort_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

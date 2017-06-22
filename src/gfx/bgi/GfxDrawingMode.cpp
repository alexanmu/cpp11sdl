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

#include "GfxDrawingMode.hpp"

namespace gfx
{

namespace bgi
{

const char GfxDrawingMode::ClassName[] = "GfxDrawingMode";

GfxDrawingMode::GfxDrawingMode() noexcept : GfxObject(ClassName)
{
    value_ = prv::GfxCanvasBgi::bgiDrawingMode::COPY_PUT;
}

GfxDrawingMode::GfxDrawingMode(const ValueType value) noexcept : GfxObject(ClassName)
{
    value_ = value;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode const& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode&& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
    // Delete other's value
    other.value_ = prv::GfxCanvasBgi::bgiDrawingMode::COPY_PUT;
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode const& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = prv::GfxCanvasBgi::bgiDrawingMode::COPY_PUT;
    }
    return *this;
}


GfxDrawingMode::operator bool() const noexcept
{
    return true;
}

GfxDrawingMode::ValueType GfxDrawingMode::getValue() const noexcept
{
    return value_;
}

void GfxDrawingMode::setValue(const ValueType value) noexcept
{
    value_ = value;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

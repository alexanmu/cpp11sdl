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

#include <cassert>
#include <string>
#include <utility>

#include "GfxMessageBoxColorType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxcolortype::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxColorType::ClassName[] = "GfxMessageBoxColorType";

GfxMessageBoxColorType::GfxMessageBoxColorType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const SdlType type) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(type >= 0);

    type_ = type;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const ValueType type) noexcept :
    GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = static_cast<SdlType>(type);
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const GfxMessageBoxColorType& other) noexcept :
    GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    type_ = other.type_;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(GfxMessageBoxColorType&& other) noexcept :
    GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    type_ = other.type_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(const GfxMessageBoxColorType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        type_ = other.type_;
    }
    return *this;
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(GfxMessageBoxColorType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        type_ = other.type_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBoxColorType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxColorType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxMessageBoxColorType::ValueType GfxMessageBoxColorType::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(type_);
}

bool GfxMessageBoxColorType::isBackground(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_BACKGROUND);
}

bool GfxMessageBoxColorType::isText(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_TEXT);
}

bool GfxMessageBoxColorType::isButtonBorder(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_BUTTON_BORDER);
}

bool GfxMessageBoxColorType::isButtonBackground(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND);
}

bool GfxMessageBoxColorType::isButtonSelected(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED);
}

bool GfxMessageBoxColorType::isMax(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (type_ == SDL_MESSAGEBOX_COLOR_MAX);
}

void GfxMessageBoxColorType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    type_ = static_cast<SdlType>(ValueType::colorMax);
}

GfxMessageBoxColorType::SdlType GfxMessageBoxColorType::getAsSdllType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return type_;
}

GfxMessageBoxColorType::SdlTypePtr GfxMessageBoxColorType::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&type_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

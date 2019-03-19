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
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include "GfxMessageBoxColorScheme.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxcolorscheme::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxColorScheme::ClassName[] = "GfxMessageBoxColorScheme";

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(const GfxMessageBoxColor colors[]) noexcept :
        GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    for (int32_t index = 0; index < kColorsArraySize; index++)
    {
        assert(colors[index]);

        clrscheme_.colors[index] = colors[index].getAsSdlType();
    }
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(const std::vector<GfxMessageBoxColor>& colors) noexcept :
    GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(colors.size() == kColorsArraySize);

    for (int32_t index = 0; index < kColorsArraySize; index++)
    {
        assert(colors[index]);

        clrscheme_.colors[index] = colors[index].getAsSdlType();
    }
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(const GfxMessageBoxColorScheme& other) noexcept :
    GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    clrscheme_ = other.clrscheme_;
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(GfxMessageBoxColorScheme&& other) noexcept :
    GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_LOW();

    clrscheme_ = other.clrscheme_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxColorScheme& GfxMessageBoxColorScheme::operator=(const GfxMessageBoxColorScheme& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        clrscheme_ = other.clrscheme_;
    }
    return *this;
}

GfxMessageBoxColorScheme& GfxMessageBoxColorScheme::operator=(GfxMessageBoxColorScheme&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        clrscheme_ = other.clrscheme_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBoxColorScheme::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxColorScheme::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxMessageBoxColorScheme::setColor(const GfxMessageBoxColorType& type, const GfxMessageBoxColor& color) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);
    assert(color);

    int32_t index = static_cast<int32_t>(type.getValue());

    clrscheme_.colors[index] = color.getAsSdlType();
}

void GfxMessageBoxColorScheme::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    for (int32_t index = 0; index < kColorsArraySize; index++)
    {
        clrscheme_.colors[index].r = 0x00;
        clrscheme_.colors[index].g = 0x00;
        clrscheme_.colors[index].b = 0x00;
    }
}

GfxMessageBoxColorScheme::SdlType GfxMessageBoxColorScheme::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)clrscheme_;
}

GfxMessageBoxColorScheme::SdlTypePtr GfxMessageBoxColorScheme::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&clrscheme_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

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

#include "GfxMessageBoxButtonData.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxbuttondata::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxButtonData::ClassName[] = "GfxMessageBoxButtonData";

GfxMessageBoxButtonData::GfxMessageBoxButtonData() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonFlags const& flags,
                            const int32_t buttonid, std::string const& text) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags);
    assert(buttonid >= 0);
    assert(text.length() > 0);

    data_.flags = flags.getAsSdlType();
    data_.buttonid = buttonid;
    data_.text = text.c_str();
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonData const& other) noexcept :
         GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    data_ = other.data_;
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonData&& other) noexcept :
        GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    data_ = other.data_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxButtonData& GfxMessageBoxButtonData::operator=(GfxMessageBoxButtonData const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        data_ = other.data_;
    }
    return *this;
}

GfxMessageBoxButtonData& GfxMessageBoxButtonData::operator=(GfxMessageBoxButtonData&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        data_ = other.data_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBoxButtonData::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxButtonData::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxMessageBoxButtonData::getButtonId(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return data_.buttonid;
}

const std::string GfxMessageBoxButtonData::getText(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string text { data_.text };

    return text;
}

void GfxMessageBoxButtonData::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    data_.flags = 0;
    data_.buttonid = -1;
    data_.text = nullptr;
}

GfxMessageBoxButtonData::SdlType GfxMessageBoxButtonData::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return data_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

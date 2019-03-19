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

#include "GfxTextEditingEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtexteditingevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxTextEditingEvent::ClassName[] = "GfxTextEditingEvent";

GfxTextEditingEvent::GfxTextEditingEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTextEditingEvent::GfxTextEditingEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    textEditingEvent_ = event;
}

GfxTextEditingEvent::GfxTextEditingEvent(const GfxTextEditingEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    textEditingEvent_ = other.textEditingEvent_;
}

GfxTextEditingEvent::GfxTextEditingEvent(GfxTextEditingEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    textEditingEvent_ = other.textEditingEvent_;
    // Delete other's data
    other.clear();
}

GfxTextEditingEvent& GfxTextEditingEvent::operator=(const GfxTextEditingEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        textEditingEvent_ = other.textEditingEvent_;
    }
    return *this;
}

GfxTextEditingEvent& GfxTextEditingEvent::operator=(GfxTextEditingEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        textEditingEvent_ = other.textEditingEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextEditingEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTextEditingEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxTextEditingEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(textEditingEvent_.type, textEditingEvent_.timestamp);

    return cEv;
}

uint32_t GfxTextEditingEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textEditingEvent_.windowID;
}

const std::string GfxTextEditingEvent::getText(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return std::string(textEditingEvent_.text);
}

int32_t GfxTextEditingEvent::getStart(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textEditingEvent_.start;
}

int32_t GfxTextEditingEvent::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textEditingEvent_.length;
}

void GfxTextEditingEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    textEditingEvent_ = event;
}

void GfxTextEditingEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    textEditingEvent_.type = 0;
    textEditingEvent_.timestamp = 0;
    textEditingEvent_.windowID = 0;
    textEditingEvent_.text[0] = 0;
    textEditingEvent_.start = 0;
    textEditingEvent_.length = 0;
}

GfxTextEditingEvent::SdlType GfxTextEditingEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textEditingEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */

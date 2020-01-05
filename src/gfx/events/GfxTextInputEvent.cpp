/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#include "GfxTextInputEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtexteditingevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxTextInputEvent::ClassName[] = "GfxTextInputEvent";

GfxTextInputEvent::GfxTextInputEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTextInputEvent::GfxTextInputEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    textInputEvent_ = event;
}

GfxTextInputEvent::GfxTextInputEvent(const GfxTextInputEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    textInputEvent_ = other.textInputEvent_;
}

GfxTextInputEvent::GfxTextInputEvent(GfxTextInputEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    textInputEvent_ = other.textInputEvent_;
    // Delete other's data
    other.clear();
}

GfxTextInputEvent& GfxTextInputEvent::operator=(const GfxTextInputEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        textInputEvent_ = other.textInputEvent_;
    }
    return *this;
}

GfxTextInputEvent& GfxTextInputEvent::operator=(GfxTextInputEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        textInputEvent_ = other.textInputEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextInputEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTextInputEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxTextInputEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(textInputEvent_.type, textInputEvent_.timestamp);

    return cEv;
}

uint32_t GfxTextInputEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textInputEvent_.windowID;
}

const std::string GfxTextInputEvent::getText(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return std::string(textInputEvent_.text);
}

void GfxTextInputEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    textInputEvent_ = event;
}

void GfxTextInputEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    textInputEvent_.type = 0;
    textInputEvent_.timestamp = 0;
    textInputEvent_.windowID = 0;
    textInputEvent_.text[0] = 0;
}

GfxTextInputEvent::SdlType GfxTextInputEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textInputEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */

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

#include "GfxScreenSaver.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxscreensaver::video::gfx");

namespace gfx
{

namespace video
{

const char GfxScreenSaver::ClassName[] = "GfxScreenSaver";

GfxScreenSaver::GfxScreenSaver() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    GfxBool status { SDL_IsScreenSaverEnabled() };

    ssstatus_ = static_cast<ScreenSaverStatus>(status.getValue());
    ssinitstatus_ = ssstatus_;
}

GfxScreenSaver::GfxScreenSaver(GfxScreenSaver&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    ssstatus_ = other.ssstatus_;
    ssinitstatus_ = other.ssinitstatus_;
    // Delete other's data
    other.clear();
}

GfxScreenSaver& GfxScreenSaver::operator=(GfxScreenSaver&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        ssstatus_ = other.ssstatus_;
        ssinitstatus_ = other.ssinitstatus_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxScreenSaver::~GfxScreenSaver() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (ssinitstatus_ == ScreenSaverStatus::statusEnabled)
    {
        SDL_EnableScreenSaver();
    }
    else
    {
        SDL_DisableScreenSaver();
    }
}

GfxScreenSaver::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxScreenSaver::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxScreenSaver::isScreenSaverEnabled(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<bool>(ssstatus_);
}

void GfxScreenSaver::enableScreenSaver(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_EnableScreenSaver();
    ssstatus_ = ScreenSaverStatus::statusEnabled;
}

void GfxScreenSaver::disableScreenSaver(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_DisableScreenSaver();
    ssstatus_ = ScreenSaverStatus::statusDisabled;
}

void GfxScreenSaver::clear(void) noexcept
{
    ssstatus_ = ScreenSaverStatus::statusDisabled;
    ssinitstatus_ = ScreenSaverStatus::statusDisabled;
}

}  // namespace video

}  // namespace gfx

/* EOF */

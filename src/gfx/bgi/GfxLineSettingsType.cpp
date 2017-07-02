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

#include <string>

#include "GfxLineSettingsType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlinesettingstype::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxLineSettingsType::ClassName[] = "GfxLineSettingsType";

GfxLineSettingsType::GfxLineSettingsType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLineSettingsType::GfxLineSettingsType(const BgiType linesettings) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    lineSettings_ = linesettings;
}

GfxLineSettingsType::GfxLineSettingsType(GfxLineSettingsType const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    lineSettings_ = other.lineSettings_;
}

GfxLineSettingsType::GfxLineSettingsType(GfxLineSettingsType&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    lineSettings_ = other.lineSettings_;
    // Delete other's value
    other.clear();
}

GfxLineSettingsType& GfxLineSettingsType::operator=(GfxLineSettingsType const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        lineSettings_ = other.lineSettings_;
    }
    return *this;
}

GfxLineSettingsType& GfxLineSettingsType::operator=(GfxLineSettingsType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        lineSettings_ = other.lineSettings_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxLineSettingsType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLineSettingsType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxLineStyle GfxLineSettingsType::getLineStyle(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxLineStyle(lineSettings_.linestyle);
}

GfxFillStyles GfxLineSettingsType::getFillStyles(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxFillStyles(lineSettings_.upattern);
}

GfxLineThickness GfxLineSettingsType::getLineThickness(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxLineThickness(lineSettings_.thickness);
}

void GfxLineSettingsType::setValue(const BgiType linesettings) noexcept
{
    LOG_TRACE_PRIO_LOW();

    lineSettings_ = linesettings;
}

void GfxLineSettingsType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    lineSettings_.linestyle = prv::GfxCanvasBgi::bgiLineStyle::SOLID_LINE;
    lineSettings_.upattern = prv::GfxCanvasBgi::bgiFillStyles::EMPTY_FILL;
    lineSettings_.thickness = prv::GfxCanvasBgi::bgiLineThickness::NORM_WIDTH;
}

GfxLineSettingsType::BgiType GfxLineSettingsType::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return lineSettings_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */

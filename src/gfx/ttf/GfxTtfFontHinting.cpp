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
#include <string>

#include "GfxTtfFontHinting.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttffonthinting::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfFontHinting::ClassName[] = "GfxTtfFontHinting";

GfxTtfFontHinting::GfxTtfFontHinting() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTtfFontHinting::GfxTtfFontHinting(GfxTtfFontHintingValues const& hinting) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hinting_ = static_cast<SdlType>(hinting);
}

GfxTtfFontHinting::GfxTtfFontHinting(SdlType hinting) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(hinting >= 0);

    hinting_ = hinting;
}

GfxTtfFontHinting::GfxTtfFontHinting(GfxTtfFontHinting const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hinting_ = other.hinting_;
}

GfxTtfFontHinting::GfxTtfFontHinting(GfxTtfFontHinting&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hinting_ = other.hinting_;
    // Delete other's data
    other.clear();
}

GfxTtfFontHinting& GfxTtfFontHinting::operator=(GfxTtfFontHinting const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        hinting_ = other.hinting_;
    }
    return *this;
}

GfxTtfFontHinting& GfxTtfFontHinting::operator=(GfxTtfFontHinting&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        hinting_ = other.hinting_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTtfFontHinting::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTtfFontHinting::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxTtfFontHinting::isNormal(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hinting_ == TTF_HINTING_NORMAL);
}

bool GfxTtfFontHinting::isLight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hinting_ == TTF_HINTING_LIGHT);
}

bool GfxTtfFontHinting::isMono(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hinting_ == TTF_HINTING_MONO);
}

bool GfxTtfFontHinting::isNone(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hinting_ == TTF_HINTING_NONE);
}

void GfxTtfFontHinting::setNormal(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hinting_ = TTF_HINTING_NORMAL;
}

void GfxTtfFontHinting::setLight(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hinting_ = TTF_HINTING_LIGHT;
}

void GfxTtfFontHinting::setMono(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hinting_ = TTF_HINTING_MONO;
}

void GfxTtfFontHinting::setNone(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hinting_ = TTF_HINTING_NONE;
}

void GfxTtfFontHinting::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hinting_ = static_cast<SdlType>(GfxTtfFontHintingValues::hintingNormal);
}

GfxTtfFontHinting::SdlType GfxTtfFontHinting::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hinting_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */

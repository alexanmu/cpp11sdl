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

#include "GfxLogCategory.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlogcategory::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLogCategory::ClassName[] = "GfxLogCategory";

GfxLogCategory::GfxLogCategory() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLogCategory::GfxLogCategory(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxLogCategory::GfxLogCategory(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxLogCategory::GfxLogCategory(const GfxLogCategory& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxLogCategory::GfxLogCategory(GfxLogCategory&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxLogCategory& GfxLogCategory::operator=(const GfxLogCategory& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        value_ = other.value_;
    }
    return *this;
}

GfxLogCategory& GfxLogCategory::operator=(GfxLogCategory&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxLogCategory::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLogCategory::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxLogCategory::ValueType GfxLogCategory::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

bool GfxLogCategory::isApplication(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_APPLICATION);
}

bool GfxLogCategory::isError(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_ERROR);
}

bool GfxLogCategory::isAssert(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_ASSERT);
}

bool GfxLogCategory::isSystem(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_SYSTEM);
}

bool GfxLogCategory::isAudio(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_AUDIO);
}

bool GfxLogCategory::isVideo(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_VIDEO);
}

bool GfxLogCategory::isRender(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RENDER);
}

bool GfxLogCategory::isInput(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_INPUT);
}

bool GfxLogCategory::isTest(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_TEST);
}

bool GfxLogCategory::isReserved1(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED1);
}

bool GfxLogCategory::isReserved2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED2);
}

bool GfxLogCategory::isReserved3(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED3);
}

bool GfxLogCategory::isReserved4(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED4);
}

bool GfxLogCategory::isReserved5(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED5);
}

bool GfxLogCategory::isReserved6(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED6);
}

bool GfxLogCategory::isReserved7(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED7);
}

bool GfxLogCategory::isReserved8(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED8);
}

bool GfxLogCategory::isReserved9(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED9);
}

bool GfxLogCategory::isReserved10(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_RESERVED10);
}

bool GfxLogCategory::isCustom(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_CATEGORY_CUSTOM);
}

void GfxLogCategory::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::logCategoryCustom);
}

GfxLogCategory::SdlType GfxLogCategory::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace log

}  // namespace gfx

/* EOF */

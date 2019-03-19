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

#include "GfxError.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxerror::error::gfx");

namespace gfx
{

namespace error
{

const char GfxError::ClassName[] = "GfxError";

GfxError::GfxError() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxError::GfxError(const std::string& error) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(error.length() > 0);

    error_ = error;
}

GfxError::GfxError(const GfxError& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    error_ = other.error_;
}

GfxError::GfxError(GfxError&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    error_ = other.error_;
    // Delete other's data
    other.clear();
}

GfxError& GfxError::operator=(const GfxError& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        error_ = other.error_;
    }
    return *this;
}

GfxError& GfxError::operator=(GfxError&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        error_ = other.error_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxError::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (error_.length() > 0);
}

std::string GfxError::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const std::string& GfxError::get(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return error_;
}

void GfxError::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    error_.clear();
}

}  // namespace error

}  // namespace gfx

/* EOF */

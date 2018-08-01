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
#include <utility>

#include "GfxGetError.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgeterror::error::gfx");

namespace gfx
{

namespace error
{

const char GfxGetError::ClassName[] = "GfxGetError";

GfxGetError::GfxGetError() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxGetError::GfxGetError(const GfxGetError& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxGetError::GfxGetError(GfxGetError&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxGetError& GfxGetError::operator=(const GfxGetError& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(other);
    }
    return *this;
}

GfxGetError& GfxGetError::operator=(GfxGetError&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxGetError::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGetError::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxError GfxGetError::getErrorObject(void) noexcept
{
    std::string str;

    str = SDL_GetError();
    return GfxError(str);
}

void GfxGetError::clearSDL2Error(void) noexcept
{
    SDL_ClearError();
}

}  // namespace error

}  // namespace gfx

/* EOF */


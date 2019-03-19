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

#include "GfxTimerCallback.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtimercallback::timer::gfx");

namespace gfx
{

namespace timer
{

const char GfxTimerCallback::ClassName[] = "GfxTimerCallback";

GfxTimerCallback::GfxTimerCallback() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxTimerCallback::~GfxTimerCallback() noexcept
{
    LOG_TRACE_PRIO_MED();
}

GfxTimerCallback::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTimerCallback::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

}  // namespace timer

}  // namespace gfx

/* EOF */

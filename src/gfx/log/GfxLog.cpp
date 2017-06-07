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

#include "GfxLog.hpp"

namespace gfx
{

namespace log
{

const char GfxLog::ClassName[] = "GfxLog";

GfxLog::GfxLog() noexcept : GfxObject(ClassName)
{
    // Nothing to do
}

GfxLog::operator bool() const noexcept
{
    return true;
}

void GfxLog::setAllPriority(GfxLogPriority const& prio) const noexcept
{
    assert(prio);

    sdl2::SDL_LogSetAllPriority(prio.getAsSdlType());
}

void GfxLog::setPriority(GfxLogCategory const& cat, GfxLogPriority const& prio) const noexcept
{
    assert(cat);
    assert(prio);

    sdl2::SDL_LogSetPriority(cat.getAsSdlType(), prio.getAsSdlType());
}

GfxLogPriority GfxLog::getPriority(GfxLogCategory const& cat) const noexcept
{
    assert(cat);

    GfxLogPriority::SdlType sdlprio;

    sdlprio = sdl2::SDL_LogGetPriority(cat.getAsSdlType());
    return GfxLogPriority(sdlprio);
}

void GfxLog::resetPriorities(void) const noexcept
{
    sdl2::SDL_LogResetPriorities();
}

}  // namespace log

}  // namespace gfx

/* EOF */

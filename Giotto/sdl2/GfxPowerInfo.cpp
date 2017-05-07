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

#include "GfxPowerInfo.hpp"

namespace gfx
{

const std::string GfxPowerInfo::ClassName = "GfxPowerInfo";

GfxPowerInfo::GfxPowerInfo() : GfxRootClass(ClassName)
{
    pstate_ = GfxPowerState(GfxPowerState::GfxPowerStateValues::stateUnknown);
    seconds_ = -1;
    percentage_ = -1;
}

void GfxPowerInfo::queryPowerInfo(void)
{
    GfxPowerState::SdlType pstate;

    pstate = sdl2::SDL_GetPowerInfo(&seconds_, &percentage_);
    pstate_ = GfxPowerState(pstate);
}

GfxPowerState& GfxPowerInfo::getPowerState(void) const
{
    return (GfxPowerState&)pstate_;
}

int GfxPowerInfo::getRemainingSeconds(void) const
{
    return seconds_;
}

int GfxPowerInfo::getRemainingPercentage(void) const
{
    return percentage_;
}

std::string GfxPowerInfo::getAsString(void) const
{
    std::string str;

    str = pstate_.getAsString() + "\n";
    str += "Minutes remaining " + std::to_string(seconds_ / 60) + "\n";
    str += "Percentage left " + std::to_string(percentage_) + "%";
    return str;
}

}  // namespace gfx

/* EOF */

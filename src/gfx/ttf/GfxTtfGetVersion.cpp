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

#include "GfxTtfGetVersion.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttfgetversion::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfGetVersion::ClassName[] = "GfxTtfGetVersion";

GfxTtfGetVersion::GfxTtfGetVersion() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxTtfGetVersion::GfxTtfGetVersion(const GfxTtfGetVersion& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxTtfGetVersion::GfxTtfGetVersion(GfxTtfGetVersion&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxTtfGetVersion& GfxTtfGetVersion::operator=(const GfxTtfGetVersion& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(other);
    }
    return *this;
}

GfxTtfGetVersion& GfxTtfGetVersion::operator=(GfxTtfGetVersion&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxTtfGetVersion::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTtfGetVersion::to_string() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const gfx::version::GfxVersion GfxTtfGetVersion::getVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    gfx::version::GfxVersion::SdlTypePtr ver;

    ver = const_cast<gfx::version::GfxVersion::SdlTypePtr>(TTF_Linked_Version());
    if (ver != nullptr)
    {
        return gfx::version::GfxVersion(*ver);
    }
    return gfx::version::GfxVersion();
}

}  // namespace ttf

}  // namespace gfx

/* EOF */

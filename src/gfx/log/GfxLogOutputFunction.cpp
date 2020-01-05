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

#include "GfxLogOutputFunction.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlogoutputfunction::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLogOutputFunction::ClassName[] = "GfxLogOutputFunction";

GfxLogOutputFunction::GfxLogOutputFunction() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxLogOutputFunction::~GfxLogOutputFunction() noexcept
{
    LOG_TRACE_PRIO_MED();
}

GfxLogOutputFunction::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLogOutputFunction::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

}  // namespace log

}  // namespace gfx

/* EOF */

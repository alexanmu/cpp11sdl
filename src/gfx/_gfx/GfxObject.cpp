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
#include <cstdint>
#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace _gfx
{

int32_t GfxObject::i32InstanceCounter_ = 0;

GfxObject::GfxObject() noexcept
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = "$init$";
}

GfxObject::GfxObject(std::string const& strClassName) noexcept : strClassName_(strClassName)
{
    assert(strClassName.length() > 0);

    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
}

GfxObject::GfxObject(GfxObject const& other) noexcept
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = "$cpctor$" + other.strClassName_;
}

GfxObject::GfxObject(GfxObject&& other) noexcept
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = "$mvctor$" + other.strClassName_;
    // Delete other's data
    other.i32InstanceId_ = -1;
    other.strClassName_ = "$null$";
}

GfxObject::~GfxObject() noexcept
{
    strClassName_ = "$null$";
    i32InstanceId_ = -1;
}

GfxObject& GfxObject::operator=(GfxObject const& other) noexcept
{
    if (this != &other)
    {
        GfxObject::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxObject::i32InstanceCounter_;
        strClassName_ = "$cpoprt$" + other.strClassName_;
    }
    return *this;
}

GfxObject& GfxObject::operator=(GfxObject&& other) noexcept
{
    if (this != &other)
    {
        GfxObject::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxObject::i32InstanceCounter_;
        strClassName_ = "$mvoprt$" + other.strClassName_;
        // Delete other's data
        other.i32InstanceId_ = -1;
        other.strClassName_ = "$null$";
    }
    return *this;
}

bool GfxObject::operator==(GfxObject const& other) const noexcept
{
    return ((i32InstanceId_ == other.i32InstanceId_) && (strClassName_ == other.strClassName_));
}

GfxObject::operator bool() const noexcept
{
    return true;
}

std::string const& GfxObject::getClassName(void) const noexcept
{
    return strClassName_;
}

int32_t GfxObject::getInstanceId(void) const noexcept
{
    return i32InstanceId_;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

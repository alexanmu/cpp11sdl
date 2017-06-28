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

#include "GfxObject.hpp"

namespace gfx
{

namespace _gfx
{

int32_t GfxObject::i32InstanceCounter_ = 0;

static const char strInitMsg[] = "$init$";
static const char strNullMsg[] = "$null$";

GfxObject::GfxObject() noexcept : rmeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = strInitMsg;
    rmeta_->constructObject(strClassName_, i32InstanceId_);
}

GfxObject::GfxObject(const char * strClassName) noexcept : rmeta_(&GfxRuntimeMeta::getInstance())
{
    assert(strClassName != nullptr);

    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = strClassName;
    rmeta_->constructObject(strClassName_, i32InstanceId_);
}

GfxObject::GfxObject(GfxObject const& other) noexcept : rmeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = other.strClassName_;
    rmeta_->constructObject(strClassName_, i32InstanceId_);
}

GfxObject::GfxObject(GfxObject&& other) noexcept : rmeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxObject::i32InstanceCounter_;
    strClassName_ = other.strClassName_;
    rmeta_->constructObject(strClassName_, i32InstanceId_);
    // Delete other's data
    other.strClassName_ = strNullMsg;
    other.i32InstanceId_ = -1;
}

GfxObject::~GfxObject() noexcept
{
    rmeta_->destructObject(strClassName_, i32InstanceId_);
    // Delete my data
    strClassName_ = strNullMsg;
    i32InstanceId_ = -1;
}

GfxObject& GfxObject::operator=(GfxObject const& other) noexcept
{
    if (this != &other)
    {
        GfxObject::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxObject::i32InstanceCounter_;
        strClassName_ = other.strClassName_;
    }
    return *this;
}

GfxObject& GfxObject::operator=(GfxObject&& other) noexcept
{
    if (this != &other)
    {
        GfxObject::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxObject::i32InstanceCounter_;
        strClassName_ = other.strClassName_;
        // Delete other's data
        other.strClassName_ = strNullMsg;
        other.i32InstanceId_ = -1;
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

const char * GfxObject::getClassName(void) const noexcept
{
    return strClassName_;
}

int32_t GfxObject::getInstanceId(void) const noexcept
{
    return i32InstanceId_;
}

// Don't use in code; just for testing
int32_t GfxObject::getInstanceCounter(void) noexcept
{
    return GfxObject::i32InstanceCounter_;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

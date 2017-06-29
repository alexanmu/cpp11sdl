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

int32_t GfxObject::instanceCounter_ = 0;

const char GfxObject::initMsg[] = "$init$";
const char GfxObject::nullMsg[] = "$null$";

GfxObject::GfxObject() noexcept : rMeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::instanceCounter_ += 1;
    instanceId_ = GfxObject::instanceCounter_;
    className_ = initMsg;
    rMeta_->constructObject(className_, instanceId_);
}

GfxObject::GfxObject(const char * className) noexcept : rMeta_(&GfxRuntimeMeta::getInstance())
{
    assert(className != nullptr);

    GfxObject::instanceCounter_ += 1;
    instanceId_ = GfxObject::instanceCounter_;
    className_ = className;
    rMeta_->constructObject(className_, instanceId_);
}

GfxObject::GfxObject(GfxObject const& other) noexcept : rMeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::instanceCounter_ += 1;
    instanceId_ = GfxObject::instanceCounter_;
    className_ = other.className_;
    rMeta_->constructObject(className_, instanceId_);
}

GfxObject::GfxObject(GfxObject&& other) noexcept : rMeta_(&GfxRuntimeMeta::getInstance())
{
    GfxObject::instanceCounter_ += 1;
    instanceId_ = GfxObject::instanceCounter_;
    className_ = other.className_;
    rMeta_->constructObject(className_, instanceId_);
    // Delete other's data
    other.className_ = nullMsg;
    other.instanceId_ = -1;
}

GfxObject::~GfxObject() noexcept
{
    rMeta_->destructObject(className_, instanceId_);
    // Delete my data
    className_ = nullMsg;
    instanceId_ = -1;
    padding1 = -1;
}

GfxObject& GfxObject::operator=(GfxObject const& other) noexcept
{
    if (this != &other)
    {
        GfxObject::instanceCounter_ += 1;
        instanceId_ = GfxObject::instanceCounter_;
        className_ = other.className_;
    }
    return *this;
}

GfxObject& GfxObject::operator=(GfxObject&& other) noexcept
{
    if (this != &other)
    {
        GfxObject::instanceCounter_ += 1;
        instanceId_ = GfxObject::instanceCounter_;
        className_ = other.className_;
        // Delete other's data
        other.className_ = nullMsg;
        other.instanceId_ = -1;
    }
    return *this;
}

bool GfxObject::operator==(GfxObject const& other) const noexcept
{
    return ((instanceId_ == other.instanceId_) && (className_ == other.className_));
}

GfxObject::operator bool() const noexcept
{
    return true;
}

const char * GfxObject::getClassName(void) const noexcept
{
    return className_;
}

int32_t GfxObject::getInstanceId(void) const noexcept
{
    return instanceId_;
}

// Don't use in code; just for testing
int32_t GfxObject::getInstanceCounter(void) noexcept
{
    return GfxObject::instanceCounter_;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

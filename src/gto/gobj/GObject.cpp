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
#include <string>

#include "GObject.hpp"

namespace gto
{

namespace gobj
{

GObject::GObject() noexcept
{
    initType_ = GInitType::defaultCtor;
}

GObject::GObject(const GObject& other) noexcept
{
    assert(other);

    initType_ = GInitType::copyCtor;
}

GObject::GObject(GObject&& other) noexcept
{
    assert(other);

    initType_ = GInitType::moveCtor;
    // Delete other's data
    other.initType_ = GInitType::notSet;
}

GObject& GObject::operator=(const GObject& other) noexcept
{
    assert(other);

    if (this != &other)
    {
        initType_ = other.initType_;
    }
    return *this;
}

GObject& GObject::operator=(GObject&& other) noexcept
{
    assert(other);

    if (this != &other)
    {
        initType_ = other.initType_;
        // Delete other's data
        other.initType_ = GInitType::notSet;
    }
    return *this;
}

GObject::~GObject() noexcept
{
    initType_ = GInitType::notSet;
}

GObject::operator bool() const noexcept
{
    return true;
}

bool GObject::operator==(const GObject& other) const noexcept
{
    assert(other);

    if (initType_ == other.initType_)
    {
        return true;
    }
    return false;
}

}  // namespace gobj

}  // namespace gto

/* EOF */

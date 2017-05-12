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

#include "GObject.hpp"

#include <string>

namespace giotto
{

namespace objects
{

GObject::GObject(std::string const& name)
{
    inittype_ = GInitType::defaultCtor;
    name_ = name;
}

GObject::GObject(GObject const& other)
{
    inittype_ = GInitType::copyCtor;
    // Avoid compiler warning
    static_cast<GObject>(other) = static_cast<GObject>(other);
}
GObject::GObject(GObject&& other)
{
    inittype_ = GInitType::moveCtor;
    // Avoid compiler warning
    other = other;
}

GObject& GObject::operator=(GObject const& other)
{
    // Nothing to do yet
    // Avoid compiler warning
    static_cast<GObject>(other) = static_cast<GObject>(other);
    return *this;
}

GObject& GObject::operator=(GObject&& other)
{
    // Nothing to do yet
    // Avoid compiler warning
    other = other;
    return *this;
}

GObject::~GObject()
{
    // Nothing to do yet
}

bool GObject::operator==(GObject const& other)
{
    if (this != &other)
    {
        if (inittype_ == other.inittype_)
        {
            return true;
        }
        return false;
    }
    return true;
}

const std::string& GObject::getName(void) const
{
    return name_;
}

}  // namespace objects

}  // namespace giotto

/* EOF */

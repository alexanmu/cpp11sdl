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

#include "GPanel.hpp"

namespace giotto
{

namespace objects
{

GPanel::GPanel(GPanel const& other) : GObject()
{
    bounds_ = other.bounds_;
}

GPanel::GPanel(GPanel&& other) : GObject()
{
    bounds_ = other.bounds_;
    // Delete other's data
    other.clear();
}

GPanel::GPanel(gfx::GfxRect const& bounds)
{
    bounds_ = bounds;
}

GPanel& GPanel::operator=(GPanel const& other)
{
    if (this != &other)
    {
        bounds_ = other.bounds_;
    }
    return *this;
}

GPanel& GPanel::operator=(GPanel&& other)
{
    if (this != &other)
    {
        bounds_ = other.bounds_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

void GPanel::drawObject(void)
{
    //
}

void GPanel::clear(void)
{
    bounds_.clear();
}

}  // namespace objects

}  // namespace giotto

/* EOF */

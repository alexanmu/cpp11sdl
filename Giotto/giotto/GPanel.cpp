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

GPanel::GPanel() : GObject()
{
    //
}

GPanel::GPanel(GPanel const& other) : GObject()
{
    width_ = other.width_;
    height_ = other.height_;
}

GPanel::GPanel(GPanel&& other) : GObject()
{
    width_ = other.width_;
    height_ = other.height_;
    // Delete other's data
    other.width_ = 0;
    other.height_ = 0;
}

GPanel& GPanel::operator=(GPanel const& other)
{
    if (this != &other)
    {
        width_ = other.width_;
        height_ = other.height_;
    }
    return *this;
}

GPanel& GPanel::operator=(GPanel&& other)
{
    if (this != &other)
    {
        width_ = other.width_;
        height_ = other.height_;
        // Delete other's data
        other.width_ = 0;
        other.height_ = 0;
    }
    return *this;
}

void GPanel::drawObject(void)
{
    //
}

}  // namespace objects

}  // namespace giotto

/* EOF */

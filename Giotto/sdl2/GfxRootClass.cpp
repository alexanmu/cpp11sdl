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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

int GfxRootClass::intInstanceCounter_ = 0;

GfxRootClass::GfxRootClass()
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$init$";
}

GfxRootClass::GfxRootClass(std::string strClassName) : strClassName_(strClassName)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
}

GfxRootClass::GfxRootClass(const GfxRootClass& other)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$cpctor$" + other.strClassName_;
}

GfxRootClass::GfxRootClass(GfxRootClass&& other)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$mvctor$" + other.strClassName_;
    // Delete other's data
    other.intInstanceId_ = -1;
    other.strClassName_ = "$null$";
}

GfxRootClass::~GfxRootClass()
{
    strClassName_ = "$null$";
    intInstanceId_ = -1;
}

GfxRootClass& GfxRootClass::operator=(const GfxRootClass& other)
{
    if (this != &other)
    {
        GfxRootClass::intInstanceCounter_ += 1;
        intInstanceId_ = GfxRootClass::intInstanceCounter_;
        strClassName_ = "$cpoprt$" + other.strClassName_;
    }
    return *this;
}

GfxRootClass& GfxRootClass::operator=(GfxRootClass&& other)
{
    if (this != &other)
    {
        GfxRootClass::intInstanceCounter_ += 1;
        intInstanceId_ = GfxRootClass::intInstanceCounter_;
        strClassName_ = "$mvoprt$" + other.strClassName_;
        // Delete other's data
        other.intInstanceId_ = -1;
        other.strClassName_ = "$null$";
    }
    return *this;
}

bool GfxRootClass::operator==(const GfxRootClass& other)
{
    return ((intInstanceId_ == other.intInstanceId_) && (strClassName_ == other.strClassName_));
}

std::string GfxRootClass::getClassName(void) const
{
    return strClassName_;
}

/* EOF */

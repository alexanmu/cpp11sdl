//
//  GfxRootClass.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/8/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxRootClass.hpp"

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

int GfxRootClass::getInstanceId(void) const
{
    return intInstanceId_;
}

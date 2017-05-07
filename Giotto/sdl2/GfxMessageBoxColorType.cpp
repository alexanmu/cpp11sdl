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

#include "GfxMessageBoxColorType.hpp"

const std::string GfxMessageBoxColorType::ClassName = "GfxMessageBoxColorType";

GfxMessageBoxColorType::GfxMessageBoxColorType() : GfxRootClass(ClassName)
{
    type_ = static_cast<SdlType>(GfxMessageBoxColorTypeValues::colorMax);
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const SdlType type) : GfxRootClass(ClassName)
{
    type_ = type;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const GfxMessageBoxColorTypeValues type) :
        GfxRootClass(ClassName)
{
    type_ = static_cast<SdlType>(type);
}

GfxMessageBoxColorType::GfxMessageBoxColorType(GfxMessageBoxColorType const& other) :
        GfxRootClass(ClassName)
{
    type_ = other.type_;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(GfxMessageBoxColorType&& other) : GfxRootClass(ClassName)
{
    type_ = other.type_;
    // Delete other's data
    other.type_ = static_cast<SdlType>(GfxMessageBoxColorTypeValues::colorMax);
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(GfxMessageBoxColorType const& other)
{
    if (this != &other)
    {
        type_ = other.type_;
    }
    return *this;
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(GfxMessageBoxColorType&& other)
{
    if (this != &other)
    {
        type_ = other.type_;
        // Delete other's data
        other.type_ = static_cast<SdlType>(GfxMessageBoxColorTypeValues::colorMax);
    }
    return *this;
}

GfxMessageBoxColorType::GfxMessageBoxColorTypeValues GfxMessageBoxColorType::getType(void) const
{
    return static_cast<GfxMessageBoxColorTypeValues>(type_);
}

GfxMessageBoxColorType::SdlType GfxMessageBoxColorType::getAsSdllType(void) const
{
    return type_;
}

GfxMessageBoxColorType::SdlTypePtr GfxMessageBoxColorType::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&type_;
}

/* EOF */

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

#include "GfxMessageBoxButtonData.hpp"

GfxMessageBoxButtonData::GfxMessageBoxButtonData() : GfxRootClass("GfxMessageBoxButtonData")
{
    data_.flags = 0;
    data_.buttonid = -1;
    data_.text = nullptr;;
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonFlags const& flags,int buttonid,std::string text) : GfxRootClass("GfxMessageBoxButtonData")
{
    data_.flags = flags.getAsSdlType();
    data_.buttonid = buttonid;
    data_.text = text.c_str();
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonData const& other) : GfxRootClass("GfxMessageBoxButtonData")
{
    data_ = other.data_;
}

GfxMessageBoxButtonData::GfxMessageBoxButtonData(GfxMessageBoxButtonData&& other) : GfxRootClass("GfxMessageBoxButtonData")
{
    data_ = other.data_;
    // Delete other's data
    other.data_.flags = 0;
    other.data_.buttonid = -1;
    other.data_.text = nullptr;
}

GfxMessageBoxButtonData& GfxMessageBoxButtonData::operator=(GfxMessageBoxButtonData const& other)
{
    if (this != &other)
    {
        data_ = other.data_;
    }
    return *this;
}

GfxMessageBoxButtonData& GfxMessageBoxButtonData::operator=(GfxMessageBoxButtonData&& other)
{
    if (this != &other)
    {
        data_ = other.data_;
        // Delete other's data
        other.data_.flags = 0;
        other.data_.buttonid = -1;
        other.data_.text = nullptr;
    }
    return *this;
}

GfxMessageBoxButtonData::SdlType GfxMessageBoxButtonData::getAsSdlType(void) const
{
    return data_;
}

GfxMessageBoxButtonData::SdlTypePtr GfxMessageBoxButtonData::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&data_;
}

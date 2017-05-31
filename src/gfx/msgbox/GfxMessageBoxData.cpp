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
#include <string>

#include "GfxMessageBoxData.hpp"

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxData::ClassName[] = "GfxMessageBoxData";

GfxMessageBoxData::GfxMessageBoxData() : GfxRootClass(ClassName)
{
    btndataptr = nullptr;
    clear();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxFlags& flags, GfxRootClass* win,
                                     const std::string& title, const std::string& message, const int32_t numbuttons,
                                     GfxMessageBoxButtonData buttons[], const GfxMessageBoxColorScheme& colorScheme) :
        GfxRootClass(ClassName)
{
    assert(flags);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(numbuttons > 0);
    assert(colorScheme);

    data_.flags = flags.getAsSdlType();
    if (win != nullptr)
    {
        data_.window = reinterpret_cast<video::GfxWindow *>(win)->getAsSdlTypePtr();
    }
    else
    {
        data_.window = nullptr;
    }
    title_ = title;
    data_.title = title_.c_str();
    message_ = message;
    data_.message = message_.c_str();
    data_.numbuttons = numbuttons;
    btndataptr = new GfxMessageBoxButtonData::SdlType[numbuttons];
    for (int32_t i = 0; i < numbuttons; i++)
    {
        btndataptr[i] = buttons[i].getAsSdlType();
    }
    data_.buttons = btndataptr;
    data_.colorScheme = colorScheme.getAsSdlTypePtr();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxFlags& flags, const video::GfxWindow& win,
                                     const std::string& title, const std::string& message, const int32_t numbuttons,
                                     GfxMessageBoxButtonData buttons[]) :
        GfxRootClass(ClassName)
{
    assert(flags);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(numbuttons > 0);

    data_.flags = flags.getAsSdlType();
    data_.window = win.getAsSdlTypePtr();
    title_ = title;
    data_.title = title_.c_str();
    message_ = message;
    data_.message = message_.c_str();
    data_.numbuttons = numbuttons;
    btndataptr = new GfxMessageBoxButtonData::SdlType[numbuttons];
    for (int32_t i = 0; i < numbuttons; i++)
    {
        btndataptr[i] = buttons[i].getAsSdlType();
    }
    data_.buttons = btndataptr;
    data_.colorScheme = nullptr;
}

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxData const& other) : GfxRootClass(ClassName)
{
    data_ = other.data_;
    title_ = other.title_;
    message_ = other.message_;
}

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxData&& other) : GfxRootClass(ClassName)
{
    data_ = other.data_;
    title_ = other.title_;
    message_ = other.message_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxData::~GfxMessageBoxData()
{
    if (btndataptr != nullptr)
    {
        delete btndataptr;
    }
}

GfxMessageBoxData& GfxMessageBoxData::operator=(GfxMessageBoxData const& other)
{
    if (this != &other)
    {
        data_ = other.data_;
        title_ = other.title_;
        message_ = other.message_;
    }
    return *this;
}

GfxMessageBoxData& GfxMessageBoxData::operator=(GfxMessageBoxData&& other)
{
    if (this != &other)
    {
        data_ = other.data_;
        title_ = other.title_;
        message_ = other.message_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBoxData::operator bool() const
{
    return true;
}

void GfxMessageBoxData::clear(void)
{
    data_.flags = 0;
    data_.window = nullptr;
    title_ = "";
    data_.title = "";
    message_ = "";
    data_.message = "'";
    data_.numbuttons = 0;
    if (btndataptr != nullptr)
    {
        delete btndataptr;
        btndataptr = nullptr;
    }
    data_.colorScheme = nullptr;
}

GfxMessageBoxData::SdlType GfxMessageBoxData::getAsSdlType(void) const
{
    return data_;
}

GfxMessageBoxData::SdlTypePtr GfxMessageBoxData::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&data_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

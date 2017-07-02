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
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxdata::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxData::ClassName[] = "GfxMessageBoxData";

GfxMessageBoxData::GfxMessageBoxData() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    btndataptr = nullptr;
    clear();
}

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxFlags const& flags, GfxObject * win,
                                     std::string const& title, std::string const& message, const int32_t numbuttons,
                                     const GfxMessageBoxButtonData buttons[],
                                     GfxMessageBoxColorScheme const& colorScheme) noexcept :
        GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

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

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxFlags const& flags, video::GfxWindow const& win,
                                     std::string const& title, std::string const& message, const int32_t numbuttons,
                                     const GfxMessageBoxButtonData buttons[]) noexcept :
        GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

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

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxData const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    data_ = other.data_;
    title_ = other.title_;
    message_ = other.message_;
}

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxData&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    data_ = other.data_;
    title_ = other.title_;
    message_ = other.message_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxData& GfxMessageBoxData::operator=(GfxMessageBoxData const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        data_ = other.data_;
        title_ = other.title_;
        message_ = other.message_;
    }
    return *this;
}

GfxMessageBoxData& GfxMessageBoxData::operator=(GfxMessageBoxData&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

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

GfxMessageBoxData::~GfxMessageBoxData() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (btndataptr != nullptr)
    {
        delete btndataptr;
    }
}

GfxMessageBoxData::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxData::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxMessageBoxData::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    data_.flags = 0;
    data_.window = nullptr;
    title_ = "";
    data_.title = "";
    message_ = "";
    data_.message = "'";
    data_.numbuttons = 0;
    btndataptr = nullptr;
    data_.colorScheme = nullptr;
}

GfxMessageBoxData::SdlType GfxMessageBoxData::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return data_;
}

GfxMessageBoxData::SdlTypePtr GfxMessageBoxData::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&data_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

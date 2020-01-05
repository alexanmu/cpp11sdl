/*
 Giotto
 Copyright (C) 2020 George Oros
 
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
#include <utility>

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

#warning Default construction will probably fail during runtime. Must check!

    clear();
    buildData();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxFlags& flags, const std::string& title,
                                     const std::string& message, const int32_t numbuttons,
                                     const GfxMessageBoxButtonData buttons[],
                                     const GfxMessageBoxColorScheme& colorScheme) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(numbuttons > 0);
    assert(colorScheme);

    flags_ = flags;
    winPtr_ = NULL;
    title_ = title;
    message_ = message;
    numButtons_ = numbuttons;
    btnDataPtr_ = new GfxMessageBoxButtonData[numbuttons];
    for (int32_t i = 0; i < numbuttons; i++)
    {
        btnDataPtr_[i] = buttons[i];
    }
    colorScheme_ = colorScheme;
    btnDataSdl_ = nullptr;
    buildData();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxFlags& flags, const video::GfxWindow& win,
                                     const std::string& title, const std::string& message, const int32_t numbuttons,
                                     const GfxMessageBoxButtonData buttons[],
                                     const GfxMessageBoxColorScheme& colorScheme) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags);
    assert(win);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(numbuttons > 0);
    assert(colorScheme);

    flags_ = flags;
    winPtr_ = win.getAsSdlTypePtr();
    title_ = title;
    message_ = message;
    numButtons_ = numbuttons;
    btnDataPtr_ = new GfxMessageBoxButtonData[numbuttons];
    for (int32_t i = 0; i < numbuttons; i++)
    {
        btnDataPtr_[i] = buttons[i];
    }
    colorScheme_ = colorScheme;
    btnDataSdl_ = nullptr;
    buildData();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxFlags& flags, const video::GfxWindow& win,
                                     const std::string& title, const std::string& message, const int32_t numbuttons,
                                     const GfxMessageBoxButtonData buttons[]) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags);
    assert(win);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(numbuttons > 0);

    flags_ = flags;
    winPtr_ = win.getAsSdlTypePtr();
    title_ = title;
    message_ = message;
    numButtons_ = numbuttons;
    btnDataPtr_ = new GfxMessageBoxButtonData[numbuttons];
    for (int32_t i = 0; i < numbuttons; i++)
    {
        btnDataPtr_[i] = buttons[i];
    }
    colorScheme_.clear();
    btnDataSdl_ = nullptr;
    buildData();
}

GfxMessageBoxData::GfxMessageBoxData(const GfxMessageBoxData& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    winPtr_ = other.winPtr_;
    title_ = other.title_;
    message_ = other.message_;
    numButtons_ = other.numButtons_;
    btnDataPtr_ = new GfxMessageBoxButtonData[numButtons_];
    for (int32_t i = 0; i < numButtons_; i++)
    {
        btnDataPtr_[i] = other.btnDataPtr_[i];
    }
    colorScheme_ = other.colorScheme_;
    btnDataSdl_ = nullptr;
    buildData();
}

GfxMessageBoxData::GfxMessageBoxData(GfxMessageBoxData&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    winPtr_ = other.winPtr_;
    title_ = other.title_;
    message_ = other.message_;
    numButtons_ = other.numButtons_;
    btnDataPtr_ = other.btnDataPtr_;
    colorScheme_ = other.colorScheme_;
    btnDataSdl_ = other.btnDataSdl_;
    // Delete other's data
    other.clear();
    buildData();
}

GfxMessageBoxData& GfxMessageBoxData::operator=(const GfxMessageBoxData& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flags_ = other.flags_;
        winPtr_ = other.winPtr_;
        title_ = other.title_;
        message_ = other.message_;
        numButtons_ = other.numButtons_;
        btnDataPtr_ = new GfxMessageBoxButtonData[numButtons_];
        for (int32_t i = 0; i < numButtons_; i++)
        {
            btnDataPtr_[i] = other.btnDataPtr_[i];
        }
        colorScheme_ = other.colorScheme_;
        btnDataSdl_ = nullptr;
        buildData();
    }
    return *this;
}

GfxMessageBoxData& GfxMessageBoxData::operator=(GfxMessageBoxData&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flags_ = other.flags_;
        winPtr_ = other.winPtr_;
        title_ = other.title_;
        message_ = other.message_;
        numButtons_ = other.numButtons_;
        btnDataPtr_ = other.btnDataPtr_;
        colorScheme_ = other.colorScheme_;
        btnDataSdl_ = other.btnDataSdl_;
        // Delete other's data
        other.clear();
        buildData();
    }
    return *this;
}

GfxMessageBoxData::~GfxMessageBoxData() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (btnDataSdl_ != nullptr)
    {
        delete[] btnDataSdl_;
    }
    if (btnDataPtr_ != nullptr)
    {
        delete[] btnDataPtr_;
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

    flags_.clear();
    winPtr_ = nullptr;
    title_.clear();
    message_.clear();
    numButtons_ = 0;
    btnDataPtr_ = nullptr;
    colorScheme_.clear();
    btnDataSdl_ = nullptr;
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

// Private methods
void GfxMessageBoxData::buildData(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    data_.flags = flags_.getAsSdlType();
    data_.window = winPtr_;
    data_.title = title_.c_str();
    data_.message = message_.c_str();
    data_.numbuttons = numButtons_;
    btnDataSdl_ = new GfxMessageBoxButtonData::SdlType[numButtons_];
    for (int32_t index = 0; index < numButtons_; index++)
    {
        btnDataSdl_[index] = btnDataPtr_[index].getAsSdlType();
    }
    data_.buttons = btnDataSdl_;
    data_.colorScheme = colorScheme_.getAsSdlTypePtr();
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

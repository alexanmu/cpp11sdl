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

#include "GfxMessageBox.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessagebox::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBox::ClassName[] = "GfxMessageBox";

GfxMessageBox::GfxMessageBox(GfxMessageBoxData const& data) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(data);

    data_ = data;
    type_ = GfxMessageBoxType::typeComplex;
}

GfxMessageBox::GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title,
                             std::string const& message) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flag);
    assert(title.length() > 0);
    assert(message.length() > 0);

    flag_ = flag;
    title_ = title;
    message_ = message;
    winptr_ = nullptr;
    type_ = GfxMessageBoxType::typeSimple;
}

GfxMessageBox::GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title, std::string const& message,
                             video::GfxWindow const& win) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flag);
    assert(title.length() > 0);
    assert(message.length() > 0);
    assert(win);

    flag_ = flag;
    title_ = title;
    message_ = message;
    winptr_ = reinterpret_cast<video::GfxWindow const *>(&win);
    type_ = GfxMessageBoxType::typeSimple;
}

GfxMessageBox::GfxMessageBox(GfxMessageBox&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = other.type_;
    data_ = other.data_;
    flag_ = other.flag_;
    title_ = other.title_;
    message_ = other.message_;
    winptr_ = other.winptr_;
    // Delete other's data
    other.clear();
}

GfxMessageBox& GfxMessageBox::operator=(GfxMessageBox&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        type_ = other.type_;
        data_ = other.data_;
        flag_ = other.flag_;
        title_ = other.title_;
        message_ = other.message_;
        winptr_ = other.winptr_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBox::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBox::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxMessageBox::showModal() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret;

    if (type_ == GfxMessageBoxType::typeComplex)
    {
        ret = showModalComplex();
    }
    else
    {
        ret = showModalSimple();
    }
    return ret;
}

int32_t GfxMessageBox::showModalSimple(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (winptr_ == nullptr)
    {
        sdl2::SDL_ShowSimpleMessageBox(flag_.getAsSdlType(), title_.c_str(),
                                       message_.c_str(), NULL);
    }
    else
    {
        sdl2::SDL_ShowSimpleMessageBox(flag_.getAsSdlType(), title_.c_str(),
                                       message_.c_str(), winptr_->getAsSdlTypePtr());
    }
    return 1;
}

int32_t GfxMessageBox::showModalComplex(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t buttonid;
    GfxMessageBoxData::SdlTypePtr p;

    p = data_.getAsSdlTypePtr();
    sdl2::SDL_ShowMessageBox(p, &buttonid);
    return buttonid;
}

void GfxMessageBox::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    type_ = GfxMessageBoxType::typeSimple;
    data_.clear();
    flag_.clear();
    title_.clear();
    message_.clear();
    winptr_ = nullptr;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */

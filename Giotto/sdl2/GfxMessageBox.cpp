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

#include "GfxMessageBox.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

const char GfxMessageBox::ClassName[] = "GfxMessageBox";

GfxMessageBox::GfxMessageBox(GfxMessageBoxData const& data) : GfxRootClass(ClassName)
{
    data_ = data;
    type_ = GfxMessageBoxType::typeComplex;
}

GfxMessageBox::GfxMessageBox(GfxMessageBoxFlags const& flag, const std::string& title, const std::string& message)
{
    flag_ = flag;
    title_ = title;
    message_ = message;
    winptr_ = nullptr;
    type_ = GfxMessageBoxType::typeSimple;
}

GfxMessageBox::GfxMessageBox(GfxMessageBoxFlags const& flag, const std::string& title,
                             const std::string& message, GfxWindow const& win)
{
    flag_ = flag;
    title_ = title;
    message_ = message;
    winptr_ = reinterpret_cast<GfxWindow const *>(&win);
    type_ = GfxMessageBoxType::typeSimple;
}

int GfxMessageBox::showModal() const
{
    int ret;

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

int GfxMessageBox::showModalSimple(void) const
{
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

int GfxMessageBox::showModalComplex(void) const
{
    int buttonid;
    GfxMessageBoxData::SdlTypePtr p;

    p = data_.getAsSdlTypePtr();
    sdl2::SDL_ShowMessageBox(p, &buttonid);
    return buttonid;
}

}  // namespace gfx

/* EOF */

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
#include <string>

#include "GForm.hpp"
#include "GfxError.hpp"

namespace gto
{

namespace gobj
{

GForm::GForm(const std::string& vname) : GComponent(vname, nullptr)
{
    assert(vname.length() > 0);

    title_ = "GForm";
    window_ = nullptr;
    canvas_ = nullptr;
    canvasInUse_ = false;
}

GForm::GForm(const std::string& vname, const std::string& title) : GComponent(vname, nullptr)
{
    assert(vname.length() > 0);
    assert(title.length() > 0);

    title_ = title;
    window_ = nullptr;
    canvas_ = nullptr;
    canvasInUse_ = false;
}

GForm::~GForm()
{
    if (window_ != nullptr)
    {
        delete window_;
    }
}

void GForm::setTitle(const std::string& title)
{
    assert(title.length() > 0);

    title_ = title;
    if (window_ != nullptr)
    {
        window_->setWindowTitle(title_);
    }
}

void GForm::create(void)
{
    gfx::video::GfxWindowFlags winFlags(gfx::video::GfxWindowFlags::ValueType::windowFlagResizable);
    gfx::video::GfxWindowPosition winPosCenter(gfx::video::GfxWindowPosition::ValueType::positionCentered);

    window_ =  new gfx::video::GfxWindow(title_, winPosCenter, winPosCenter, kDefaultFormWidth,
                                         kDefaultFormHeight, winFlags);
    canvas_ = nullptr;
}

void GForm::close(void)
{
    //
}

void GForm::loadResources(void)
{
    //
}

void GForm::run(void)
{
    //
}

gfx::bgi::GfxCanvas * GForm::getCanvas(void)
{
    if (window_ != nullptr)
    {
        canvas_ = new gfx::bgi::GfxCanvas(window_->getWindowSurface());
        canvasInUse_ = true;

        return canvas_;
    }
    return nullptr;
}

void GForm::draw(void)
{
    if (window_ != nullptr)
    {
        if (canvasInUse_ == true)
        {
            window_->updateWindowSurface();
        }
    }
}

}  // namespace gobj

}  // namespace gto

/* EOF */

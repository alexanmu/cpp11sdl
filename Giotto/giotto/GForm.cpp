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
#include <memory>

#include "GForm.hpp"
#include "GfxError.hpp"

GForm::GForm() : GObject()
{
    title_ = "GForm";
    window_ = nullptr;
    canvasInUse_ = false;
}

GForm::GForm(const std::string& title) : GObject()
{
    title_ = title;
    window_ = nullptr;
    canvasInUse_ = false;
}

void GForm::setFormTitle(const std::string& title)
{
    title_ = title;
    if (window_ != nullptr)
    {
        window_->setTitle(title_);
    }
}

void GForm::createForm(void)
{
    gfx::GfxWindowFlags winFlags(gfx::GfxWindowFlags::GfxWindowFlagsValues::windowFlagResizable);
    gfx::GfxWindowPosition winPosCenter(gfx::GfxWindowPosition::GfxWindowPositionValues::positionCentered);

    std::string s = title_;

    window_ = std::make_shared<gfx::GfxWindow>(s, winPosCenter, winPosCenter, WIN_W, WIN_H, winFlags);
    canvas_ = std::make_shared<gfx::bgi::GfxCanvas>(*(window_->getWindowSurface()));
}

void GForm::closeForm(void)
{
    //
}

std::shared_ptr<gfx::bgi::GfxCanvas> GForm::getFormCanvas(void)
{
    canvasInUse_ = true;
    return canvas_;
}

void GForm::drawForm(void)
{
    if (canvasInUse_ == true)
    {
        window_->updateWindowSurface();
    }
}

/* EOF */

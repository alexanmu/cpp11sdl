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

#include "GDemoForm.hpp"

#include <memory>
#include <string>

#include "GfxInitQuit.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GAbortRetryIgnoreMsgBox.hpp"
#include "GRetryCancelMsgBox.hpp"
#include "GfxError.hpp"
#include "GForm.hpp"
#include "GOKMsgBox.hpp"
#include "GOKCancelMsgBox.hpp"
#include "GQuitCancelMsgBox.hpp"
#include "GfxSurface.hpp"
#include "GGraphicControl.hpp"
#include "GfxRect.hpp"
#include "GControl.hpp"

uint16_t pixels[16*16] = {  // ...or with raw pixel data:
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0aab, 0x0789, 0x0bcc, 0x0eee, 0x09aa, 0x099a, 0x0ddd,
    0x0fff, 0x0eee, 0x0899, 0x0fff, 0x0fff, 0x1fff, 0x0dde, 0x0dee,
    0x0fff, 0xabbc, 0xf779, 0x8cdd, 0x3fff, 0x9bbc, 0xaaab, 0x6fff,
    0x0fff, 0x3fff, 0xbaab, 0x0fff, 0x0fff, 0x6689, 0x6fff, 0x0dee,
    0xe678, 0xf134, 0x8abb, 0xf235, 0xf678, 0xf013, 0xf568, 0xf001,
    0xd889, 0x7abc, 0xf001, 0x0fff, 0x0fff, 0x0bcc, 0x9124, 0x5fff,
    0xf124, 0xf356, 0x3eee, 0x0fff, 0x7bbc, 0xf124, 0x0789, 0x2fff,
    0xf002, 0xd789, 0xf024, 0x0fff, 0x0fff, 0x0002, 0x0134, 0xd79a,
    0x1fff, 0xf023, 0xf000, 0xf124, 0xc99a, 0xf024, 0x0567, 0x0fff,
    0xf002, 0xe678, 0xf013, 0x0fff, 0x0ddd, 0x0fff, 0x0fff, 0xb689,
    0x8abb, 0x0fff, 0x0fff, 0xf001, 0xf235, 0xf013, 0x0fff, 0xd789,
    0xf002, 0x9899, 0xf001, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0xe789,
    0xf023, 0xf000, 0xf001, 0xe456, 0x8bcc, 0xf013, 0xf002, 0xf012,
    0x1767, 0x5aaa, 0xf013, 0xf001, 0xf000, 0x0fff, 0x7fff, 0xf124,
    0x0fff, 0x089a, 0x0578, 0x0fff, 0x089a, 0x0013, 0x0245, 0x0eff,
    0x0223, 0x0dde, 0x0135, 0x0789, 0x0ddd, 0xbbbc, 0xf346, 0x0467,
    0x0fff, 0x4eee, 0x3ddd, 0x0edd, 0x0dee, 0x0fff, 0x0fff, 0x0dee,
    0x0def, 0x08ab, 0x0fff, 0x7fff, 0xfabc, 0xf356, 0x0457, 0x0467,
    0x0fff, 0x0bcd, 0x4bde, 0x9bcc, 0x8dee, 0x8eff, 0x8fff, 0x9fff,
    0xadee, 0xeccd, 0xf689, 0xc357, 0x2356, 0x0356, 0x0467, 0x0467,
    0x0fff, 0x0ccd, 0x0bdd, 0x0cdd, 0x0aaa, 0x2234, 0x4135, 0x4346,
    0x5356, 0x2246, 0x0346, 0x0356, 0x0467, 0x0356, 0x0467, 0x0467,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff
 };

GDemoForm::GDemoForm(const std::string& appName) : giotto::objects::GForm(appName)
{
}

void GDemoForm::draw(void)
{
    auto canvas = getCanvas();
    canvas->Bar(gfx::GfxRect(0, 0, 300, 300), gfx::GfxColor(200, 200, 200));
    canvas->Line(gfx::GfxPoint(110, 110), gfx::GfxPoint(110, 190), gfx::bgi::GfxBgiConstants::vgaWhite());
    canvas->Line(gfx::GfxPoint(110, 110), gfx::GfxPoint(190, 110), gfx::bgi::GfxBgiConstants::vgaWhite());
    canvas->Line(gfx::GfxPoint(190, 110), gfx::GfxPoint(190, 190), gfx::bgi::GfxBgiConstants::vgaDarkGray());
    canvas->Line(gfx::GfxPoint(110, 190), gfx::GfxPoint(190, 190), gfx::bgi::GfxBgiConstants::vgaDarkGray());

    auto surf = gfx::GfxSurface(pixels, 16, 16, 16, 16 * 2, 0x0f00, 0x00f0, 0x000f, 0xf000);
    window_.get()->setWindowIcon(surf);

    /*************************************************************************************************/
    giotto::objects::GGraphicControl g(GVarName(g), nullptr, 50, 50);
    g.setBorderThikness(giotto::objects::GBorderThikness::thikBorder);
    g.setBorderColor(gfx::bgi::GfxBgiConstants::vgaWhite());
    g.setBorderShadowColor(gfx::bgi::GfxBgiConstants::vgaDarkGray());
    g.setBorderStyle(giotto::objects::GBorderStyle::sunken3DBorder);
    g.setBackgroundColor(gfx::bgi::GfxBgiConstants::vgaLightGray());
    g.draw();
    windowsurface_->blitSurface(g.getSurface(), gfx::GfxRect(0, 0, 50, 50), gfx::GfxRect(10, 10, 60, 60));
    GForm::draw();
}

void GDemoForm::run(void)
{
    giotto::dialogs::GQuitCancelMsgBox g(GVarName(g), this, "Error", "An error occured. What should I do?");
    g.showModal();

    giotto::dialogs::GDialogsConstants sel;

    sel = g.getSelection();
    while (sel != giotto::dialogs::GDialogsConstants::kButtonQuit)
    {
        g.showModal();
        sel = g.getSelection();
    }
}

/* EOF */

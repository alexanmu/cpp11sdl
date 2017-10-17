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
#include <iostream>

#include "GfxInitQuit.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GAbortRetryIgnoreMsgBox.hpp"
#include "GRetryCancelMsgBox.hpp"
#include "GfxGetError.hpp"
#include "GForm.hpp"
#include "GOKMsgBox.hpp"
#include "GOKCancelMsgBox.hpp"
#include "GQuitCancelMsgBox.hpp"
#include "GfxSurface.hpp"
#include "GGraphicControl.hpp"
#include "GfxRect.hpp"
#include "GControl.hpp"
#include "GBitmap.hpp"
#include "GfxSdlHeader.hpp"
#include "GTypes.hpp"
#include "GLabel.hpp"
#include "GfxTtfGetVersion.hpp"
#include "GStructuredTextLabel.hpp"
#include "GApplication.hpp"
#include "GfxEvent.hpp"
#include "GfxKeycode.hpp"
#include "GfxEventFilter.hpp"

struct MMEvFilter : public gfx::events::GfxEventFilter
{
    virtual int32_t operator()(gfx::events::GfxEvent const& event) const noexcept
    {
        std::cout << "MMEvFilter called " << event.commonEvent().getTimeStamp() << std::endl;
        if (event.eventType().isMouseMotion())
        {
            std::cout << "Mouse motion " + std::to_string(event.mouseMotionEvent().getX()) + " "
                         + std::to_string(event.mouseMotionEvent().getY()) << std::endl;
            return 0;
        }
        std::cout << "Nothing at 0 0" << std::endl;
        return 1;
    }
};

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

GDemoForm::GDemoForm(std::string const& appName) : gto::gobj::GForm(appName)
{
    dynLabel_ = nullptr;
    dynLabelText_ = "$init$";
}

void GDemoForm::draw(void)
{
    std::string __base_path = gto::gobj::GApplication::activeApp->getBasePath();

    auto canvas = getCanvas();

    // Bar
    canvas->SetFillStyle(gfx::bgi::GfxFillStyles(gfx::bgi::GfxFillStyles::ValueType::interleaveFill),
                         gfx::bgi::GfxColors2(gfx::pixels::GfxColor(200, 200, 200).getColor()));
    canvas->Bar(gfx::rect::GfxRect(0, 0, 300, 300));
    // Line
    canvas->SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::kWhite));
    canvas->Line(gfx::rect::GfxPoint(110, 110), gfx::rect::GfxPoint(110, 190));
    // Line
    canvas->SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::kWhite));
    canvas->Line(gfx::rect::GfxPoint(110, 110), gfx::rect::GfxPoint(190, 110));
    // Line
    canvas->SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::kDarkGray));
    canvas->Line(gfx::rect::GfxPoint(190, 110), gfx::rect::GfxPoint(190, 190));
    // Line
    canvas->SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::kDarkGray));
    canvas->Line(gfx::rect::GfxPoint(110, 190), gfx::rect::GfxPoint(190, 190));

    auto surf = gfx::surface::GfxSurface("GDemoForm::draw", pixels, 16, 16, 16, 16 * 2,
                                         0x0f00, 0x00f0, 0x000f, 0xf000);
    window_->setWindowIcon(surf);

    /*************************************************************************************************/
    gto::gobj::GGraphicControl g(GVarName(g), this, 50, 50);
    g.setBorderThikness(gto::gobj::GBorderThikness::thikBorder);
    g.setBorderColor(gfx::bgi::kColorWhite());
    g.setBorderShadowColor(gfx::bgi::kColorDarkGray());
    g.setBorderStyle(gto::gobj::GBorderStyle::sunken3DBorder);
    g.setBackgroundColor(gfx::bgi::kColorLightGray());
    g.setBackgroundStyle(gto::gobj::GBackgroundStyle::solidColor);
    g.draw();
    window_->getWindowSurface().blitSurface(g.getSurface(), gfx::rect::GfxRect(0, 0, 50, 50),
                                gfx::rect::GfxRect(10, 10, 60, 60));

    gto::gobj::GBitmap bmp(GVarName(bmp), this, 384, 384,
                gto::gobj::GImageScaleMode::centerScaled, __base_path + "/OKCheckMark.bmp");
    bmp.load();
    bmp.setBorderColor(gfx::bgi::kColorLightGreen());
    bmp.setBorderThikness(gto::gobj::GBorderThikness::thinBorder);
    bmp.setBorderShadowColor(gfx::bgi::kColorGreen());
    bmp.setBorderStyle(gto::gobj::GBorderStyle::sunken3DBorder);
    bmp.setScaleMode(gto::gobj::GImageScaleMode::strechScaled);
    bmp.draw();
    window_->getWindowSurface().blitSurface(bmp.getSurface(), bmp.getBounds(),
                                            gfx::rect::GfxRect(90, 90, 384, 384));

    gfx::version::GfxVersion v;
    gfx::ttf::GfxTtfGetVersion gv;
    v = gv.getVersion();
    std::string labelText = "Label text " + v.getAsString();

    gto::gobj::GLabel g2(GVarName(g2), this, 280, 60, labelText, 32);
    g2.setBorderThikness(gto::gobj::GBorderThikness::thikBorder);
    g2.setBorderColor(gfx::bgi::kColorWhite());
    g2.setBorderShadowColor(gfx::bgi::kColorDarkGray());
    g2.setBorderStyle(gto::gobj::GBorderStyle::raised3DBorder);
    g2.setBackgroundColor(gfx::bgi::kColorLightGray());
    g2.setForegroundColor(gfx::bgi::kColorLightCyan());
    g2.getFontInfo().setFontUnderline(true);
    g2.getFontInfo().setFontName("Raleway-ExtraBold");
    g2.setTextRenderMode(gto::gobj::GTextRenderMode::blendedText);
    g2.draw();
    window_->getWindowSurface().blitSurface(g2.getSurface(), gfx::rect::GfxRect(0, 0, 280, 60),
                                            gfx::rect::GfxRect(640, 10, 120, 60));

    // labelText = "john.doe@example.com";
    // labelText = "https://www.apple.com";
    labelText = "192.168.100.1";
    gto::gobj::GStructuredTextLabel g3(GVarName(g3), this, 280, 60, labelText, 18,
            gto::gobj::GStructuredTextType::ipAddress);
    g3.setBorderThikness(gto::gobj::GBorderThikness::thikBorder);
    g3.setBorderColor(gfx::bgi::kColorWhite());
    g3.setBorderShadowColor(gfx::bgi::kColorDarkGray());
    g3.setBorderStyle(gto::gobj::GBorderStyle::raised3DBorder);
    g3.setBackgroundColor(gfx::bgi::kColorLightGray());
    g3.setForegroundColor(gfx::bgi::kColorLightCyan());
    g3.getFontInfo().setFontUnderline(true);
    g3.setTextRenderMode(gto::gobj::GTextRenderMode::blendedText);
    g3.draw();
    window_->getWindowSurface().blitSurface(g3.getSurface(), gfx::rect::GfxRect(0, 0, 300, 60),
                                            gfx::rect::GfxRect(310, 10, 120, 60));

    gto::gobj::GLabel g4(GVarName(g4), this, 280, 60, "Hello from Ale", 24);
    g4.setBorderThikness(gto::gobj::GBorderThikness::thinBorder);
    g4.setForegroundColor(gfx::bgi::kColorLightRed());
    g4.draw();
    window_->getWindowSurface().blitSurface(g4.getSurface(), gfx::rect::GfxRect(0, 0, 320, 60),
                                            gfx::rect::GfxRect(940, 10, 200, 60));

    dynLabel_ = new gto::gobj::GLabel(GVarName(dynLabel_), this, 600, 60, dynLabelText_, 32);
    dynLabel_->setBorderThikness(gto::gobj::GBorderThikness::thinBorder);
    dynLabel_->setBorderColor(gfx::bgi::kColorWhite());
    dynLabel_->setBorderShadowColor(gfx::bgi::kColorDarkGray());
    dynLabel_->setBorderStyle(gto::gobj::GBorderStyle::sunken3DBorder);
    dynLabel_->setBackgroundColor(gfx::bgi::kColorLightGray());
    dynLabel_->setForegroundColor(gfx::bgi::kColorLightBlue());
    dynLabel_->getFontInfo().setFontItalic(true);
    dynLabel_->getFontInfo().setFontName("Raleway-Light");
    dynLabel_->setTextRenderMode(gto::gobj::GTextRenderMode::shadedText);
    dynLabel_->draw();
    window_->getWindowSurface().blitSurface(dynLabel_->getSurface(), gfx::rect::GfxRect(0, 0, 600, 60),
                                            gfx::rect::GfxRect(500, 100, 600, 60));
    delete dynLabel_;

    GForm::draw();
}

void GDemoForm::run(void)
{
    gfx::events::GfxEvent e;
    bool quit = false;
    MMEvFilter MMEvFilterObj;

    while (quit == false)
    {
        e.filterEvents(MMEvFilterObj);
        if (e.pollEvent())
        {
            if (e.eventType().isQuit())
            {
                quit = true;
            }
            if (e.eventType().isMouseMotion())
            {
                dynLabelText_ = "Mouse motion " + std::to_string(e.mouseMotionEvent().getX()) + " "
                         + std::to_string(e.mouseMotionEvent().getY());
                draw();
            }
            if (e.eventType().isMouseButtonUp())
            {
                if (e.mouseButtonEvent().getButton().isLeftButton() == true)
                {
                    dynLabelText_ = "Left click";
                }
                if (e.mouseButtonEvent().getButton().isRightButton() == true)
                {
                    dynLabelText_ = "Right click";
                }
                if (e.mouseButtonEvent().getButton().isMiddleButton() == true)
                {
                    dynLabelText_ = "Middle click";
                }
                draw();
            }
            if (e.eventType().isKeyUp())
            {
                if (e.keyboardEvent().getKeysym().getKeyCode().getValue() ==
                        gfx::keycode::GfxKeycode::ValueType::kKeyQ)
                {
                    quit = true;
                }
            }
            if (e.eventType().isMouseWheel())
            {
                if (e.mouseWheelEvent().getDirection().getValue() ==
                        gfx::mouse::GfxMouseWheelDirection::ValueType::mouseWheelNormal)
                {
                    dynLabelText_ = "Mouse wheel - normal";
                }
                if (e.mouseWheelEvent().getDirection().getValue() ==
                        gfx::mouse::GfxMouseWheelDirection::ValueType::mouseWheelFlipped)
                {
                    dynLabelText_ = "Mouse wheel - flipped";
                }
                draw();
            }
            if (e.eventType().isWindowEvent())
            {
                if (e.windowEvent().getWindowEventID().isMinimized())
                {
                    //
                }
                draw();
            }
        }
        if (quit == true)
        {
            gto::dlgs::GQuitCancelMsgBox g(GVarName(g), this, "Error", "A thing occured. What should I do?");
            g.showModal();

            gto::dlgs::GDialogsConstants sel;

            sel = g.getSelection();
            if (sel != gto::dlgs::GDialogsConstants::kButtonQuit)
            {
                quit = false;
                draw();
            }
        }
    }
}

/* EOF */

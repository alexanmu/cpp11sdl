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

#include "GDemoApp.hpp"

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

GDemoApp::GDemoApp() : GApplication()
{
    appName_ = "GDemoApp";
}

GDemoApp::GDemoApp(const std::string& appName) : GApplication()
{
    appName_ = appName;
}

GDemoApp::~GDemoApp()
{
    // Nothing to do yet
}

void GDemoApp::loadAppConfiguration(void)
{
    // Nothing to do yet
}

void GDemoApp::run(void)
{
    gfx::GfxInitQuit iq(gfx::GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
    {
        return;
    }

    mainForm_ = std::make_shared<GForm>(appName_);
    mainForm_->createForm();

    auto canvas = mainForm_->getFormCanvas();
    canvas->Bar(gfx::GfxRect(0, 0, 100, 100), gfx::GfxColor(200, 200, 200));
    canvas->Line(gfx::GfxPoint(10,10), gfx::GfxPoint(10,90), gfx::bgi::GfxBgiConstants::vgaWhite());
    canvas->Line(gfx::GfxPoint(10,10), gfx::GfxPoint(90,10), gfx::bgi::GfxBgiConstants::vgaWhite());
    canvas->Line(gfx::GfxPoint(90,10), gfx::GfxPoint(90,90), gfx::bgi::GfxBgiConstants::vgaDarkGray());
    canvas->Line(gfx::GfxPoint(10,90), gfx::GfxPoint(90,90), gfx::bgi::GfxBgiConstants::vgaDarkGray());
    mainForm_->drawForm();
    
    GQuitCancelMsgBox g(this,"Error","An error occured. What should I do?");
    g.showModal();
    
    GDialogsConstants sel;
    
    sel = g.getSelection();
    while (sel != GDialogsConstants::kButtonQuit)
    {
        g.showModal();
        sel = g.getSelection();
    }
}

/* EOF */

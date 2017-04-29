//
//  GDemoApp.cpp
//  Giotto
//
//  Created by George Oros on 4/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GDemoApp.hpp"

#include <iostream>

#include "GfxInitQuit.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GAbortRetryIgnoreMsgBox.hpp"
#include "GRetryCancelMsgBox.hpp"
#include "GfxError.hpp"
#include "GForm.hpp"

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
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init failed\n";
        return;
    }
    
    mainForm_ = std::make_shared<GForm>(appName_);
    mainForm_->createForm();
    
    auto canvas = mainForm_->getFormCanvas();
    canvas->Bar(GfxRect(0, 0, 100, 100), GfxColor(200, 200, 200));
    
    mainForm_->drawForm();
    
    GRetryCancelMsgBox g(this,"Error","An error occured. What should I do?");
    g.showModal();
    
    GDialogsConstants sel;
    
    sel = g.getSelection();
    while (sel != GDialogsConstants::kButtonCancel)
    {
        g.showModal();
        sel = g.getSelection();
    }
}

/* EOF */

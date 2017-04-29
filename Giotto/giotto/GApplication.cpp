//
//  GApplication.cpp
//  Giotto
//
//  Created by George Oros on 4/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GApplication.hpp"

#include <iostream>

#include "GfxInitQuit.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GAbortRetryIgnoreMsgBox.hpp"
#include "GRetryCancelMsgBox.hpp"

GApplication::GApplication(std::string appName) : GObject()
{
    appName_ = appName;
}

void GApplication::loadAppConfiguration(void)
{
    // NOthing to do yet
}

void GApplication::run(void)
{
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init failed\n";
        return;
    }
    GfxWindowFlags winFlags(GfxWindowFlags::GfxWindowFlagsValues::windowFlagResizable);
    GfxWindow win(appName_,
                  GfxWindowPosition(GfxWindowPosition::GfxWindowPositionValues::positionCentered),
                  GfxWindowPosition(GfxWindowPosition::GfxWindowPositionValues::positionCentered),
                  WIN_W,
                  WIN_H,
                  winFlags);
    GfxRenderer rend(win);

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

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

#include "GfxInitFlags.hpp"
#include "GApplication.hpp"

namespace gto
{

namespace gobj
{

GApplication * GApplication::activeApp = nullptr;

GApplication::GApplication(const std::string& appname) : GObject()
{
    assert(appname.length() > 0);

    if (GApplication::activeApp != nullptr)
    {
        throw std::runtime_error("App instance already running");
    }
    appName_ = appname;
    mainForm_ = nullptr;
    iq_ = nullptr;
    fontManager_ = nullptr;
    /* Set global var */
    GApplication::activeApp = this;
}

GApplication::~GApplication()
{
    if (ttfiq_ != nullptr)
    {
        delete ttfiq_;
    }
    if (iq_ != nullptr)
    {
        delete iq_;
    }
    if (fontManager_ != nullptr)
    {
        delete fontManager_;
    }
    /* Delete global var */
    GApplication::activeApp = nullptr;
}

void GApplication::setMainForm(GForm * mainForm)
{
    assert(mainForm != nullptr);

    mainForm_ = mainForm;
}

void GApplication::loadAppConfiguration(void)
{
    if (mainForm_ != nullptr)
    {
        mainForm_->loadResources();
    }
}

void GApplication::run()
{
    gfx::initquit::GfxInitFlags iflags;

    iflags.setVideo();
    iflags.setEvents();
    iq_ = new gfx::initquit::GfxInitQuit(iflags);
    if (!iq_)
    {
        return;
    }
    ttfiq_ = new gfx::ttf::GfxTtfInitQuit();
    if (!ttfiq_)
    {
        return;
    }
    fontManager_ = new util::GFontManager(getBasePath() + "/Raleway");
    if (!fontManager_)
    {
        return;
    }
    fontManager_->loadFonts();
    if (mainForm_ != nullptr)
    {
        mainForm_->create();
        mainForm_->draw();
        mainForm_->run();
        mainForm_->close();
    }
}

util::GFontManager * GApplication::getActiveFontManager(void) const noexcept
{
    return fontManager_;
}

const std::string GApplication::getBasePath(void) const noexcept
{
    return "data";
}

}  // namespace gobj

}  // namespace gto

/* EOF */

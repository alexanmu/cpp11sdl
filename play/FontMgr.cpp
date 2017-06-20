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

#include "FontMgr.hpp"

/******************************************************* FontMgr *******************************************************/
#include <iostream>

#include "GFontManager.hpp"
#include "GfxInitQuit.hpp"
#include "GfxInitFlags.hpp"
#include "GfxTtfInitQuit.hpp"
#include "GfxTtfFont.hpp"

void _doFontMgr(void)
{
    gfx::initquit::GfxInitQuit iq(gfx::initquit::GfxInitFlags(gfx::initquit::GfxInitFlags::ValueType::initEverything));
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init error" << std::endl;
        return;
    }
    gfx::ttf::GfxTtfInitQuit tiq;

    gto::util::GFontManager fm("/var/fpwork/goros/cpp11work/tool_v5/data/Raleway");

    std::cout << "FontMgr" << std::endl;
    fm.loadFonts();
    gfx::ttf::GfxTtfFont * ptr = fm.getFont("Raleway-Regular.ttf", 16);
    if (ptr != nullptr)
    {
        std::cout << "ok" << std::endl;
    }
    delete ptr;
}

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

#include "Keyboard.hpp"

/******************************************************* Keyboard *******************************************************/

#include <iostream>

#include "GfxInitFlags.hpp"
#include "GfxInitQuit.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxWindow.hpp"
#include "GfxEventType.hpp"
#include "GfxKeyboardEvent.hpp"
#include "GfxScancode.hpp"
#include "GfxKeyboard.hpp"

using namespace gfx;

static initquit::GfxInitQuit * iq;
static video::GfxWindow * win;

static void _init(void)
{
    initquit::GfxInitFlags flags;

    flags.clear();
    flags.setEvents();
    flags.setVideo();
    iq = new initquit::GfxInitQuit(flags);
    win = new video::GfxWindow("Title", 200, 200);
}

static void _quit(void)
{
    delete win;
    delete iq;
}

static void _do(void)
{
    gfx::sdl2::SDL_Event e;
    bool quit = false;

    keyboard::GfxKeyboard kdb;

    std::cout << "start while(!quit)" << std::endl;
    while (!quit)
    {
        if (SDL_PollEvent(&e))
        {
            events::GfxEventType evType(e.type);
            events::GfxKeyboardEvent evKbd(e.key);

            if (evType.isQuit())
            {
                std::cout << "isQuit()=true" << std::endl;
                quit = true;
            }
            if (evType.isKeyUp())
            {
                std::cout << kdb.getKeyName(evKbd.getKeysym().getKeyCode()) << std::endl;
                if (evKbd.getKeysym().getScanCode().getValue() == scancode::GfxScancode::ValueType::kScanCodeQ)
                {
                    quit = true;
                }
            }
        }
    }
}

void _doKeyboard(void)
{
    std::cout << "Keyboard" << std::endl;
    _init();
    _do();
    _quit();
}

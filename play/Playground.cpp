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

#include <iostream>
#include <cstring>

#include "Playground.hpp"

#include "Benchmark.hpp"
#include "Fonts.hpp"
#include "PaletteSDL.hpp"
#include "PaletteGFX.hpp"
#include "CCallback.hpp"
#include "Component.hpp"
#include "FSO.hpp"
#include "Log.hpp"
#include "Meta.hpp"
#include "RuntimeMeta.hpp"
#include "FontMgr.hpp"
#include "Keyboard.hpp"
#include "BgiDemo.hpp"
#include "ToString.hpp"
#include "Ver.hpp"

/******************************************************* main *******************************************************/
typedef struct _Command_t
{
    void (*func)(void);
    const char * cmd;
} _Command_t;

/* Forward declaration */
void _doPlayground(void);

static _Command_t commands[] = {
    { _doBenchmark, "benchmark" },
    { _doFonts, "fonts" },
    { _doPaletteSdl, "palettesdl" },
    { _doPaletteGfx, "palettegfx" },
    { _doCallback, "callback" },
    { _doComponent, "component" },
    { _doFSO, "fso" },
    { _doRuntimeMeta, "rmeta" },
    { _doMeta, "meta" },
    { _doLog, "log" },
    { _doFontMgr, "fontmgr" },
    { _doKeyboard, "keyboard" },
    { _doBgiDemo, "bgidemo" },
    { _doToString, "tostring" },
    { _doVer, "ver" },
    { _doPlayground, "all" }
};

void _doPlayground(void)
{
    _doBenchmark();
    _doFonts();
    _doPaletteSdl();
    _doPaletteGfx();
    _doCallback();
    _doComponent();
    _doFSO();
    _doRuntimeMeta();
    _doMeta();
    _doLog();
    _doFontMgr();
    _doKeyboard();
    _doBgiDemo();
    _doToString();
    _doVer();
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        for (int32_t i = 1; i < argc; i++)
        {
            for (auto& it : commands)
            {
                if (std::strcmp(argv[i], it.cmd) == 0)
                {
                    it.func();
                    break;
                }
            }
        }
    }
    else
    {
        std::cout << "Select one or more from: ";
        for (auto& it : commands)
        {
            std::cout << it.cmd << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

/* EOF */

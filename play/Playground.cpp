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

/******************************************************* main *******************************************************/
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
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (std::strcmp(argv[1], "benchmark") == 0)
        {
            _doBenchmark();
        }
        if (std::strcmp(argv[1], "fonts") == 0)
        {
            _doFonts();
        }
        if (std::strcmp(argv[1], "palettesdl") == 0)
        {
            _doPaletteSdl();
        }
        if (std::strcmp(argv[1], "palettegfx") == 0)
        {
            _doPaletteGfx();
        }
        if (std::strcmp(argv[1], "callback") == 0)
        {
            _doCallback();
        }
        if (std::strcmp(argv[1], "component") == 0)
        {
            _doComponent();
        }
        if (std::strcmp(argv[1], "fso") == 0)
        {
            _doFSO();
        }
        if (std::strcmp(argv[1], "rmeta") == 0)
        {
            _doRuntimeMeta();
        }
        if (std::strcmp(argv[1], "meta") == 0)
        {
            _doMeta();
        }
        if (std::strcmp(argv[1], "log") == 0)
        {
            _doLog();
        }
        // ALL
        if (std::strcmp(argv[1], "all") == 0)
        {
            _doPlayground();
        }
    }
    else
    {
    	std::cout << "Select option" << std::endl;
    }
    return 0;
}

/* EOF */

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

#include "Ver.hpp"

/******************************************************* Ver *******************************************************/
#include <iostream>
#include <string>
#include <cstdint>

#include "GfxGetVersion.hpp"
#include "GfxVersion.hpp"

void _doVer(void)
{
    std::cout << "===VERSION===" << std::endl;

    gfx::version::GfxGetVersion getVer;
    gfx::version::GfxVersion verInfo;
    std::string revision;
    int32_t revNumber;
    uint8_t major;
    uint8_t minor;
    uint8_t patch;

    // Get VersionInfo
    verInfo = getVer.getVersion();
    revision = getVer.getRevision();
    revNumber = getVer.getRevisionNumber();
    // Get Version
    major = verInfo.getMajor();
    minor = verInfo.getMinor();
    patch = verInfo.getPatch();

    std::cout << "SDL2-" << static_cast<int>(major) << "." <<
             static_cast<int>(minor) << "." << static_cast<int>(patch) << std::endl;
    std::cout << "Revision: " << revision << std::endl;
    std::cout << "Revision number: " << revNumber << std::endl;
}

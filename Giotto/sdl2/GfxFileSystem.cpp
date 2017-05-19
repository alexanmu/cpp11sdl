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

#include <string>

#include "GfxFileSystem.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

const char GfxFileSystem::ClassName[] = "GfxFileSystem";

GfxFileSystem::GfxFileSystem() : GfxRootClass(ClassName)
{
    // Nothing to do
}

GfxFileSystem::operator bool() const
{
    return true;
}

const std::string GfxFileSystem::getBasePath(void) const
{
    char * base_path = NULL;
    std::string str;

    str = sdl2::SDL_GetBasePath();
    if (base_path != NULL)
    {
        str = base_path;
    }
    else
    {
        str = getThisFolder();
    }
    return str;
}

const std::string GfxFileSystem::getPrefPath(const std::string& organization, const std::string& appname) const
{
    char * base_path = NULL;
    std::string str;

    base_path = sdl2::SDL_GetPrefPath(organization.c_str(), appname.c_str());
    if (base_path != NULL)
    {
        str = base_path;
    }
    else
    {
        str = getThisFolder();
    }
    return str;
}

std::string GfxFileSystem::getThisFolder(void) const
{
#ifdef __windows_machine
    return ".\\";
#else
    return "./";
#endif
}

}  // namespace gfx

/* EOF */

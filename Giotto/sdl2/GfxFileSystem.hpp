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

#ifndef GfxFileSystem_hpp
#define GfxFileSystem_hpp

#include <string>

#include "GfxRootClass.hpp"

class GfxFileSystem final : public GfxRootClass
{
public:
    static const std::string ClassName;

    GfxFileSystem();

    GfxFileSystem(GfxFileSystem const&) = delete;
    GfxFileSystem(GfxFileSystem&&) = delete;

    GfxFileSystem& operator=(GfxFileSystem const&) = delete;
    GfxFileSystem& operator=(GfxFileSystem&&) = delete;

    std::string getBasePath(void) const;
    std::string getPrefPath(const std::string& organization, const std::string& appname) const;
private:
    std::string getThisFolder(void) const;
};

#endif /* GfxFileSystem_hpp */

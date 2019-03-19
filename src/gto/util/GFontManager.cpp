/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include "GObject.hpp"
#include "GFontManager.hpp"
#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"
#include "GFileObject.hpp"
#include "GFileCollectionElement.hpp"

#include "GfxFontInfo.hpp"

namespace gto
{

namespace util
{

const char GFontManager::kDefaultFontName[] = "Raleway-Regular";
const char GFontManager::kDefaultFontFileExtension[] = ".ttf";

GFontManager::GFontManager(const std::string& fontsFolder) noexcept : GObject()
{
    assert(fontsFolder.length() > 0);

    fontsFolder_ = fontsFolder;
    fontFiles_.reserve(4);
}

GFontManager::~GFontManager() noexcept
{
    // Nothing to do yet
}

void GFontManager::loadFonts(void) noexcept
{
    gto::fso::GFileSystemObject fso;
    gto::fso::GFolderObject * fo = fso.getFolder(fontsFolder_);
    gto::fso::GFilesCollection fcoll;
    std::string fName;

    if (fo != nullptr)
    {
        fcoll = fo->getFilesCollection();
        for (auto& it : fcoll)
        {
            fName = fso.getFileName(it.getFileSpec());
            if (fName.rfind(".ttf") != std::string::npos)
            {
                gto::fso::GFileObject fileo(it.getFileSpec());

                if (fileo.getFileSize() > 0)
                {
                    fontFiles_.push_back(it.getFileSpec());
                }
            }
        }
    }
    delete fo;
}

gfx::ttf::GfxTtfFont * GFontManager::getFont(const std::string& fontName, const int pointSize) const noexcept
{
    std::string fontFileName = "";

    if (fontName != std::string(gfx::xtra::GfxFontInfo::kDefaultFontName))
    {
        fontFileName = getFileNameByFontName(fontName);
    }
    if (fontFileName.length() == 0)
    {
        fontFileName = getFileNameByFontName(std::string(kDefaultFontName) +
                                             std::string(kDefaultFontFileExtension));
    }
    return new gfx::ttf::GfxTtfFont(fontFileName, pointSize);
}

void GFontManager::freeFont(gfx::ttf::GfxTtfFont * font) const noexcept
{
    delete font;
}

// Private methods
std::string GFontManager::getFileNameByFontName(const std::string& fontName) const noexcept
{
    std::string fileName = "";

    if (fontFiles_.size() > 0)
    {
        for (auto& it : fontFiles_)
        {
            if (it.rfind(fontName) != std::string::npos)
            {
                fileName = it;
                break;
            }
        }
    }
    return fileName;
}

}  // namespace util

}  // namespace gto

/* EOF */

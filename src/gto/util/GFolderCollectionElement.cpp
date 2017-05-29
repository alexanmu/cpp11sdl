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

#include "GFolderCollectionElement.hpp"

namespace gto
{

namespace util
{

GFolderCollectionElement::GFolderCollectionElement() : GFSBaseClass()
{
    folderSpec_ = "";
}

GFolderCollectionElement::GFolderCollectionElement(std::string const& folderSpec) : GFSBaseClass()
{
    folderSpec_ = folderSpec;
}

GFolderCollectionElement::GFolderCollectionElement(GFolderCollectionElement const& other) : GFSBaseClass()
{
    folderSpec_ = other.folderSpec_;
}

GFolderCollectionElement::GFolderCollectionElement(GFolderCollectionElement&& other) : GFSBaseClass()
{
    folderSpec_ = other.folderSpec_;
    // Delete other's data
    other .clear();
}

GFolderCollectionElement& GFolderCollectionElement::operator=(GFolderCollectionElement const& other)
{
    if (this != &other)
    {
        folderSpec_ = other.folderSpec_;
    }
    return *this;
}

GFolderCollectionElement& GFolderCollectionElement::operator=(GFolderCollectionElement&& other)
{
    if (this != &other)
    {
        folderSpec_ = other.folderSpec_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GFolderCollectionElement::~GFolderCollectionElement()
{
    clear();
}

std::string const& GFolderCollectionElement::getFolderSpec(void) const noexcept
{
    return folderSpec_;
}

void GFolderCollectionElement::clear(void)
{
    folderSpec_ = "";
}

}  // namespace util

}  // namespace gto

/* EOF */

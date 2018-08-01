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

#include "GFileCollectionElement.hpp"

namespace gto
{

namespace fso
{

GFileCollectionElement::GFileCollectionElement(const std::string& fileSpec) : GFSBaseClass()
{
    fileSpec_ = fileSpec;
}

GFileCollectionElement::GFileCollectionElement(const GFileCollectionElement& other) : GFSBaseClass()
{
    fileSpec_ = other.fileSpec_;
}

GFileCollectionElement::GFileCollectionElement(GFileCollectionElement&& other) : GFSBaseClass()
{
    fileSpec_ = other.fileSpec_;
    // Delete other's data
    other.clear();
}

GFileCollectionElement& GFileCollectionElement::operator=(const GFileCollectionElement& other)
{
    if (this != &other)
    {
        fileSpec_ = other.fileSpec_;
    }
    return *this;
}

GFileCollectionElement& GFileCollectionElement::operator=(GFileCollectionElement&& other)
{
    if (this != &other)
    {
        fileSpec_ = other.fileSpec_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GFileCollectionElement::~GFileCollectionElement()
{
    clear();
}

const std::string& GFileCollectionElement::getFileSpec(void) const noexcept
{
    return fileSpec_;
}

void GFileCollectionElement::clear(void)
{
    fileSpec_ = "";
}

}  // namespace fso

}  // namespace gto

/* EOF */

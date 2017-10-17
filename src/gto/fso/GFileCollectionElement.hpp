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

#ifndef GFileCollectionElement_hpp
#define GFileCollectionElement_hpp

#include <string>
#include <vector>

#include "GFSBaseClass.hpp"

namespace gto
{

namespace fso
{

class GFileCollectionElement : public GFSBaseClass
{
public:
    GFileCollectionElement();
    explicit GFileCollectionElement(std::string const& fileSpec);

    GFileCollectionElement(GFileCollectionElement const& other);
    GFileCollectionElement(GFileCollectionElement&& other);

    GFileCollectionElement& operator=(GFileCollectionElement const& other);
    GFileCollectionElement& operator=(GFileCollectionElement&& other);

    virtual ~GFileCollectionElement();

    std::string const& getFileSpec(void) const noexcept;
    void clear(void);
private:
    std::string fileSpec_;
};

typedef std::vector<GFileCollectionElement> GFilesCollection;

}  // namespace fso

}  // namespace gto

#endif /* GFileCollectionElement_hpp */

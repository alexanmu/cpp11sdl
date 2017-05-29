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

#ifndef GFolderObject_hpp
#define GFolderObject_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GFSBaseClass.hpp"
#include "GFolderCollectionElement.hpp"
#include "GFileCollectionElement.hpp"

namespace gto
{

namespace util
{

class GFileObject;

class GFolderObject : public GFSBaseClass
{
public:
    GFolderObject() = delete;

    explicit GFolderObject(std::string const& pathSpec);
    explicit GFolderObject(GFolderCollectionElement const& folder);

    GFolderObject(GFolderObject const&) = delete;
    GFolderObject(GFolderObject&&) = delete;

    GFolderObject& operator=(GFolderObject const&) = delete;
    GFolderObject& operator=(GFolderObject&&) = delete;

    virtual ~GFolderObject();

    std::string const& getFolderSpec(void) const noexcept;

    void rescan(void);

    GFilesCollection getFilesCollection(void);
private:
    void scanFolder(void);

    std::string folderSpec_;
    // uint32_t attributes_;
    // uint32_t dateLastAccessed_;
    // uint32_t dateLastModified_;
    // bool isRootFolder;
    std::string parentFolder_;
    // uint64_t size_;
    GFolderCollection subFolders_;
    GFilesCollection files_;
};

}  // namespace util

}  // namespace gto

#endif /* GFolderObject_hpp */

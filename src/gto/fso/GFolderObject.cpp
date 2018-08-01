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

#include <dirent.h>
#include <cstring>
#include <string>

#include "GFolderObject.hpp"
#include "GFileObject.hpp"

namespace gto
{

namespace fso
{

GFolderObject::GFolderObject(const std::string& folderSpec) : GFSBaseClass()
{
    folderSpec_ = folderSpec;
    scanFolder();
}

GFolderObject::GFolderObject(const GFolderCollectionElement& folder) : GFSBaseClass()
{
    folderSpec_ = folder.getFolderSpec();
    scanFolder();
}

GFolderObject::~GFolderObject()
{
    if (subFolders_.size() > 0)
    {
        for (auto& it : subFolders_)
        {
            it.clear();
        }
    }
    if (files_.size() > 0)
    {
        for (auto& it : files_)
        {
            it.clear();
        }
    }
}

const std::string& GFolderObject::getFolderSpec(void) const noexcept
{
    return folderSpec_;
}

void GFolderObject::rescan(void)
{
    scanFolder();
}

const GFilesCollection GFolderObject::getFilesCollection(void)
{
    return files_;
}

//  Private methods
void GFolderObject::scanFolder(void)
{
    DIR *d;
    struct dirent *dir;
    std::string fullpath;

    d = opendir(folderSpec_.c_str());
    if (d != NULL)
    {
        dir = readdir(d);
        while (dir != NULL)
        {
            fullpath = folderSpec_ + dir->d_name;
            if (dir->d_type == DT_DIR)
            {
                if ((std::strcmp(dir->d_name, ".") != 0) && (std::strcmp(dir->d_name, "..") != 0))
                {
                    GFolderCollectionElement folder(fullpath);
                    subFolders_.push_back(folder);
                }
            }
            if (dir->d_type == DT_REG)
            {
                GFileCollectionElement file(fullpath);
                files_.push_back(file);
            }
            dir = readdir(d);
        }
        closedir(d);
    }
}

}  // namespace fso

}  // namespace gto

/* EOF */

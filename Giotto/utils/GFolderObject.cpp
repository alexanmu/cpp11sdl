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
#include <string>

#include "GFolderObject.hpp"
#include "GFileObject.hpp"

namespace giotto
{

namespace utils
{

GFolderObject::GFolderObject(std::string const& pathSpec, bool scan) : GObject()
{
    pathSpec_ = pathSpec;
    scanned_ = false;
    if (scan == true)
    {
        scanned_ = true;
        scanFolder();
    }
}

GFolderObject::~GFolderObject()
{
    if (subFolders_.size() > 0)
    {
        for (auto& it : subFolders_)
        {
            delete it;
        }
    }
    if (files_.size() > 0)
    {
        for (auto& it : files_)
        {
            delete it;
        }
    }
}

void GFolderObject::scan(void)
{
    scanFolder();
    scanned_ = true;
}

GFileObject::GFilesCollection GFolderObject::getFilesCollection(void)
{
    return files_;
}

//  Private methods
void GFolderObject::scanFolder(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(pathSpec_.c_str());
    if (d)
    {
        dir = readdir(d);
        while (dir != NULL)
        {
            if (dir->d_type == DT_DIR)
            {
                if ((std::strcmp(dir->d_name,".") != 0) && (std::strcmp(dir->d_name,"..") != 0))
                {
                    GFolderObject * folder = new GFolderObject(dir->d_name, false);
                    subFolders_.push_back(folder);
                }
            }
            if (dir->d_type == DT_REG)
            {
                GFileObject * file = new GFileObject(dir->d_name);
                files_.push_back(file);
            }
            dir = readdir(d);
        }
    }
}

}  // namespace utils

}  // namespace giotto

/* EOF */

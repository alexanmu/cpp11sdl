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

#include "GFileObject.hpp"

#include <sys/stat.h>
#include <time.h>
#include <cassert>
#include <ctime>
#include <string>

#include <iostream>

namespace giotto
{

namespace utils
{

GFileObject::GFileObject(std::string const& fileSpec) : GFSBaseClass()
{
    fileSpec_ = fileSpec;
    scanFile();
}

GFileObject::GFileObject(GFileCollectionElement const& file) : GFSBaseClass()
{
    fileSpec_ = file.getFileSpec();
    scanFile();
}

GFileObject::~GFileObject()
{
}

std::string const& GFileObject::getFileSpec(void) const
{
    return fileSpec_;
}

std::string GFileObject::getAttributesAsString(void) const
{
    std::string attrs = "-";

    //  User
    if (rdUsr_ == true)
    {
        attrs += "r";
    }
    else
    {
        attrs += "-";
    }
    if (wrUsr_ == true)
    {
        attrs += "w";
    }
    else
    {
        attrs += "-";
    }
    if (xcUsr_ == true)
    {
        attrs += "x";
    }
    else
    {
        attrs += "-";
    }
    //  Group
    if (rdGrp_ == true)
    {
        attrs += "r";
    }
    else
    {
        attrs += "-";
    }
    if (wrGrp_ == true)
    {
        attrs += "w";
    }
    else
    {
        attrs += "-";
    }
    if (xcGrp_ == true)
    {
        attrs += "x";
    }
    else
    {
        attrs += "-";
    }
    //  Other
    if (rdOth_ == true)
    {
        attrs += "r";
    }
    else
    {
        attrs += "-";
    }
    if (wrOth_ == true)
    {
        attrs += "w";
    }
    else
    {
        attrs += "-";
    }
    if (xcOth_ == true)
    {
        attrs += "x";
    }
    else
    {
        attrs += "-";
    }
    //  Done
    return attrs;
}

void GFileObject::rescan(void)
{
    scanFile();
}

// Private methods
void GFileObject::scanFile(void)
{
    // http://codewiki.wikidot.com/c:system-call:stat

    struct stat fileStat;
    int ret;
    std::tm * ptr;

    ret = lstat(fileSpec_.c_str(), &fileStat);
    if (ret == 0)
    {
        size_ = fileStat.st_size;
        rdUsr_ = (fileStat.st_mode & S_IRUSR) != 0;
        wrUsr_ = (fileStat.st_mode & S_IWUSR) != 0;
        xcUsr_ = (fileStat.st_mode & S_IXUSR) != 0;
        rdGrp_ = (fileStat.st_mode & S_IRGRP) != 0;
        wrGrp_ = (fileStat.st_mode & S_IWGRP) != 0;
        xcGrp_ = (fileStat.st_mode & S_IXGRP) != 0;
        rdOth_ = (fileStat.st_mode & S_IROTH) != 0;
        wrOth_ = (fileStat.st_mode & S_IWOTH) != 0;
        xcOth_ = (fileStat.st_mode & S_IXOTH) != 0;
        isLink_ = S_ISLNK(fileStat.st_mode);
        ptr = std::localtime(&fileStat.st_ctime);
        if (ptr != NULL)
        {
            dateCreated_ = *ptr;
        }
        ptr = std::localtime(&fileStat.st_atime);
        if (ptr != NULL)
        {
            dateLastAccessed_ = *ptr;
        }
        ptr = std::localtime(&fileStat.st_mtime);
        if (ptr != NULL)
        {
            dateLastModified_ = *ptr;
        }
    }
    std::cout << fileSpec_ << std::endl;
    std::cout << getAttributesAsString() << std::endl;
    std::cout << size_ << std::endl;
    std::cout << std::asctime(&dateCreated_);
    std::cout << std::asctime(&dateLastAccessed_);
    std::cout << std::asctime(&dateLastModified_);
    parentFolder_ = "";
    path_ = "";
}

}  // namespace utils

}  // namespace giotto

/* EOF */

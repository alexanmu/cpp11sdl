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
#include <limits>
#include <cstring>

#include <iostream>

namespace giotto
{

namespace utils
{

GFileObject::GFileObject(std::string const& fileSpec) : GFSBaseClass()
{
    clear();
    fileSpec_ = fileSpec;
    scanFile();
}

GFileObject::GFileObject(GFileCollectionElement const& file) : GFSBaseClass()
{
    clear();
    fileSpec_ = file.getFileSpec();
    scanFile();
}

GFileObject::~GFileObject()
{
    clear();
}

std::string const& GFileObject::getFileSpec(void) const noexcept
{
    return fileSpec_;
}

std::string GFileObject::getFileName(void) const noexcept
{
    return GFSBaseClass::_getFileName(fileSpec_);
}

std::string GFileObject::getFilePath(void) const noexcept
{
    return GFSBaseClass::_getFilePath(fileSpec_);
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

void GFileObject::getUserAttributes(bool * rd, bool * wr, bool * xc) const noexcept
{
    assert(rd != nullptr);
    assert(wr != nullptr);
    assert(xc != nullptr);

    *rd = rdUsr_;
    *wr = wrUsr_;
    *xc = xcUsr_;
}

void GFileObject::getGroupAttributes(bool * rd, bool * wr, bool * xc) const noexcept
{
    assert(rd != nullptr);
    assert(wr != nullptr);
    assert(xc != nullptr);

    *rd = rdGrp_;
    *wr = wrGrp_;
    *xc = xcGrp_;
}

void GFileObject::getOtherAttributes(bool * rd, bool * wr, bool * xc) const noexcept
{
    assert(rd != nullptr);
    assert(wr != nullptr);
    assert(xc != nullptr);

    *rd = rdOth_;
    *wr = wrOth_;
    *xc = xcOth_;
}

bool GFileObject::isLink(void) const noexcept
{
    return isLink_;
}

uint64_t GFileObject::getFileSize(void) const noexcept
{
    return fileSize_;
}

std::string GFileObject::getDateCreated(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateCreated_) == true)
    {
        str = _getDateAsString(dateCreated_);
    }
    return str;
}

std::string GFileObject::getDateLastAccessed(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastAccessed_) == true)
    {
        str = _getDateAsString(dateLastAccessed_);
    }
    return str;
}

std::string GFileObject::getDateLastModified(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastModified_) == true)
    {
        str = _getDateAsString(dateLastModified_);
    }
    return str;
}

std::string GFileObject::getTimeCreated(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateCreated_) == true)
    {
        str = _getTimeAsString(dateCreated_);
    }
    return str;
}

std::string GFileObject::getTimeLastAccessed(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastAccessed_) == true)
    {
        str = _getTimeAsString(dateLastAccessed_);
    }
    return str;
}

std::string GFileObject::getTimeLastModified(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastModified_) == true)
    {
        str = _getTimeAsString(dateLastModified_);
    }
    return str;
}

std::string GFileObject::getDateTimeCreated(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateCreated_) == true)
    {
        str = _getDateAsString(dateCreated_) + " " + _getTimeAsString(dateCreated_);
    }
    return str;
}

std::string GFileObject::getDateTimeLastAccessed(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastAccessed_) == true)
    {
        str = _getDateAsString(dateLastAccessed_) + " " + _getTimeAsString(dateLastAccessed_);;
    }
    return str;
}

std::string GFileObject::getDateTimeLastModified(void) const noexcept
{
    std::string str { "" };

    if (isTmValid(dateLastModified_) == true)
    {
        str = _getDateAsString(dateLastModified_) + " " + _getTimeAsString(dateLastModified_);
    }
    return str;
}

std::string GFileObject::getParentFolder(void) const noexcept
{
    return GFSBaseClass::_getParentFolder(fileSpec_);
}

void GFileObject::rescan(void)
{
    clear();
    scanFile();
}

// Private methods
void GFileObject::clear(void)
{
    fileSpec_ = "";
    rdUsr_ = false;
    wrUsr_ = false;
    xcUsr_ = false;
    rdGrp_ = false;
    wrGrp_ = false;
    xcGrp_ = false;
    rdOth_ = false;
    wrOth_ = false;
    xcOth_ = false;
    isLink_ = false;
    std::memset(reinterpret_cast<void *>(&dateCreated_), 0xFF, sizeof(std::tm));
    std::memset(reinterpret_cast<void *>(&dateLastAccessed_), 0xFF, sizeof(std::tm));
    std::memset(reinterpret_cast<void *>(&dateLastModified_), 0xFF, sizeof(std::tm));
    fileSize_ = std::numeric_limits<uint64_t>::max();
}

void GFileObject::scanFile(void)
{
    // http://codewiki.wikidot.com/c:system-call:stat

    struct stat fileStat;
    int ret;
    std::tm * ptr;

    ret = lstat(fileSpec_.c_str(), &fileStat);
    if (ret == 0)
    {
        fileSize_ = fileStat.st_size;
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
            if (isTmValid(*ptr) == true)
            {
                dateCreated_ = *ptr;
            }
            else
            {
                std::memset(reinterpret_cast<char *>(&dateCreated_), 0xFF, sizeof(dateCreated_));
            }
        }
        ptr = std::localtime(&fileStat.st_atime);
        if (ptr != NULL)
        {
            if (isTmValid(*ptr) == true)
            {
                dateLastAccessed_ = *ptr;
            }
            else
            {
                std::memset(reinterpret_cast<char *>(&dateLastAccessed_), 0xFF, sizeof(dateLastAccessed_));
            }
        }
        ptr = std::localtime(&fileStat.st_mtime);
        if (ptr != NULL)
        {
            if (isTmValid(*ptr) == true)
            {
                dateLastModified_ = *ptr;
            }
            else
            {
                std::memset(reinterpret_cast<char *>(&dateLastModified_), 0xFF, sizeof(dateLastModified_));
            }
        }
    }
    std::cout << fileSpec_ << std::endl;
    std::cout << getAttributesAsString() << std::endl;
    std::cout << fileSize_ << std::endl;
    std::cout << std::asctime(&dateCreated_);
    std::cout << std::asctime(&dateLastAccessed_);
    std::cout << std::asctime(&dateLastModified_);
}

bool GFileObject::isTmValid(std::tm const& tm) const noexcept
{
    if ((tm.tm_sec < 0) || (tm.tm_sec > 60))
    {
        return false;
    }
    if ((tm.tm_min < 0) || (tm.tm_min > 59))
    {
        return false;
    }
    if ((tm.tm_hour < 0) || (tm.tm_hour > 23))
    {
        return false;
    }
    if ((tm.tm_mday < 1) || (tm.tm_mday > 31))
    {
        return false;
    }
    if ((tm.tm_mon < 0) || (tm.tm_mon > 11))
    {
        return false;
    }
    if (tm.tm_year > 2000)
    {
        // Assume this SW will not run after year 2100 :-)
        return false;
    }
    if ((tm.tm_wday < 0) || (tm.tm_wday > 6))
    {
        return false;
    }
    if ((tm.tm_yday < 0) || (tm.tm_yday > 365))
    {
        return false;
    }
    if (tm.tm_isdst > 0)
    {
        return false;
    }
    return true;
}

}  // namespace utils

}  // namespace giotto

/* EOF */

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
#include <cstdint>
#include <string>
#include <limits>
#include <cstring>

namespace gto
{

namespace fso
{

GFileObject::GFileObject(std::string const& fileSpec) throw(std::runtime_error) : GFSBaseClass()
{
    clear();
    fileSpec_ = fileSpec;
    scanFile();
}

GFileObject::GFileObject(GFileCollectionElement const& file) throw(std::runtime_error) : GFSBaseClass()
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

std::string GFileObject::getAttributesAsString(void) const noexcept
{
    std::string attrs { kAttrCharNothing };

    //  User
    if (readUser_ == true)
    {
        attrs += kAttrCharRead;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (writeUser_ == true)
    {
        attrs += kAttrCharWrite;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (executeUser_ == true)
    {
        attrs += kAttrCharExecute;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    //  Group
    if (readGroup_ == true)
    {
        attrs += kAttrCharRead;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (writeGroup_ == true)
    {
        attrs += kAttrCharWrite;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (executeGroup_ == true)
    {
        attrs += kAttrCharExecute;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    //  Other
    if (readOther_ == true)
    {
        attrs += kAttrCharRead;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (writeOther_ == true)
    {
        attrs += kAttrCharWrite;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    if (executeOther_ == true)
    {
        attrs += kAttrCharExecute;
    }
    else
    {
        attrs += kAttrCharNothing;
    }
    //  Done
    return attrs;
}

void GFileObject::getUserAttributes(bool * read, bool * write, bool * execute) const noexcept
{
    assert(read != nullptr);
    assert(write != nullptr);
    assert(execute != nullptr);

    *read = readUser_;
    *write = writeUser_;
    *execute = executeUser_;
}

void GFileObject::getGroupAttributes(bool * read, bool * write, bool * execute) const noexcept
{
    assert(read != nullptr);
    assert(write != nullptr);
    assert(execute != nullptr);

    *read = readGroup_;
    *write = writeGroup_;
    *execute = executeGroup_;
}

void GFileObject::getOtherAttributes(bool * read, bool * write, bool * execute) const noexcept
{
    assert(read != nullptr);
    assert(write != nullptr);
    assert(execute != nullptr);

    *read = readOther_;
    *write = writeOther_;
    *execute = executeOther_;
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

void GFileObject::rescan(void) throw(std::runtime_error)
{
    clear();
    scanFile();
}

// Private methods
void GFileObject::clear(void) noexcept
{
    fileSpec_ = "";
    readUser_ = false;
    writeUser_ = false;
    executeUser_ = false;
    readGroup_ = false;
    writeGroup_ = false;
    executeGroup_ = false;
    readOther_ = false;
    writeOther_ = false;
    executeOther_ = false;
    isLink_ = false;
    std::memset(reinterpret_cast<void *>(&dateCreated_),
                std::numeric_limits<uint8_t>::max(), sizeof(std::tm));
    std::memset(reinterpret_cast<void *>(&dateLastAccessed_),
                std::numeric_limits<uint8_t>::max(), sizeof(std::tm));
    std::memset(reinterpret_cast<void *>(&dateLastModified_),
                std::numeric_limits<uint8_t>::max(), sizeof(std::tm));
    fileSize_ = std::numeric_limits<uint64_t>::max();
}

void GFileObject::scanFile(void) throw(std::runtime_error)
{
    // http://codewiki.wikidot.com/c:system-call:stat

    struct stat fileStat;
    int32_t ret;
    std::tm * ptr;

    ret = lstat(fileSpec_.c_str(), &fileStat);
    if (ret == 0)
    {
        fileSize_ = fileStat.st_size;
        readUser_ = ((fileStat.st_mode & S_IRUSR) != 0);
        writeUser_ = ((fileStat.st_mode & S_IWUSR) != 0);
        executeUser_ = ((fileStat.st_mode & S_IXUSR) != 0);
        readGroup_ = ((fileStat.st_mode & S_IRGRP) != 0);
        writeGroup_ = ((fileStat.st_mode & S_IWGRP) != 0);
        executeGroup_ = ((fileStat.st_mode & S_IXGRP) != 0);
        readOther_ = ((fileStat.st_mode & S_IROTH) != 0);
        writeOther_ = ((fileStat.st_mode & S_IWOTH) != 0);
        executeOther_ = ((fileStat.st_mode & S_IXOTH) != 0);
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
                std::memset(reinterpret_cast<char *>(&dateCreated_),
                            std::numeric_limits<uint8_t>::max(), sizeof(dateCreated_));
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
                std::memset(reinterpret_cast<char *>(&dateLastAccessed_),
                            std::numeric_limits<uint8_t>::max(), sizeof(dateLastAccessed_));
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
                std::memset(reinterpret_cast<char *>(&dateLastModified_),
                            std::numeric_limits<uint8_t>::max(), sizeof(dateLastModified_));
            }
        }
    }
    else
    {
        clear();
    }
}

bool GFileObject::isTmValid(std::tm const& tm) const noexcept
{
    if ((tm.tm_sec < kTimeDateMinSec) || (tm.tm_sec > kTimeDateMaxSec))
    {
        return false;
    }
    if ((tm.tm_min < kTimeDateMinMin) || (tm.tm_min > kTimeDateMaxMin))
    {
        return false;
    }
    if ((tm.tm_hour < kTimeDateMinHour) || (tm.tm_hour > kTimeDateMaxHour))
    {
        return false;
    }
    if ((tm.tm_mday < kTimeDateMinMonthDay) || (tm.tm_mday > kTimeDateMaxMonthDay))
    {
        return false;
    }
    if ((tm.tm_mon < kTimeDateMinMonth) || (tm.tm_mon > kTimeDateMaxMonth))
    {
        return false;
    }
    if (tm.tm_year > kTimeDateMaxYearIncrement)
    {
        // Assume this SW will not run beyond year 2100 :-)
        return false;
    }
    if ((tm.tm_wday < kTimeDateMinWeekDay) || (tm.tm_wday > kTimeDateMaxWeekDay))
    {
        return false;
    }
    if ((tm.tm_yday < kTimeDateMinYearDay) || (tm.tm_yday > kTimeDateMaxYearDay))
    {
        return false;
    }
    if ((tm.tm_isdst < kTimeDateMinDstValue) || (tm.tm_isdst > kTimeDateMaxDstValue))
    {
        return false;
    }
    return true;
}

}  // namespace fso

}  // namespace gto

/* EOF */

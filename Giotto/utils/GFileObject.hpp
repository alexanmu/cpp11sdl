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

#ifndef GFileObject_hpp
#define GFileObject_hpp

#include <stdexcept>
#include <cstdint>
#include <ctime>
#include <string>

#include "GFSBaseClass.hpp"
#include "GFileCollectionElement.hpp"

namespace giotto
{

namespace utils
{

class GFileObject : public GFSBaseClass
{
public:
    GFileObject() = delete;

    explicit GFileObject(std::string const& fileSpec) throw(std::runtime_error);
    explicit GFileObject(GFileCollectionElement const& file) throw(std::runtime_error);

    GFileObject(GFileObject const&) = delete;
    GFileObject(GFileObject&&) = delete;

    GFileObject& operator=(GFileObject const&) = delete;
    GFileObject& operator=(GFileObject&&) = delete;

    virtual ~GFileObject();

    std::string const& getFileSpec(void) const noexcept;
    std::string getFileName(void) const noexcept;
    std::string getFilePath(void) const noexcept;

    std::string getAttributesAsString(void) const noexcept;
    void getUserAttributes(bool * read, bool * write, bool * execute) const noexcept;
    void getGroupAttributes(bool * read, bool * write, bool * execute) const noexcept;
    void getOtherAttributes(bool * read, bool * wriye, bool * execute) const noexcept;
    bool isLink(void) const noexcept;
    uint64_t getFileSize(void) const noexcept;
    std::string getDateCreated(void) const noexcept;
    std::string getDateLastAccessed(void) const noexcept;
    std::string getDateLastModified(void) const noexcept;
    std::string getTimeCreated(void) const noexcept;
    std::string getTimeLastAccessed(void) const noexcept;
    std::string getTimeLastModified(void) const noexcept;
    std::string getDateTimeCreated(void) const noexcept;
    std::string getDateTimeLastAccessed(void) const noexcept;
    std::string getDateTimeLastModified(void) const noexcept;
    std::string getParentFolder(void) const noexcept;

    void rescan(void) throw(std::runtime_error);
private:
    void clear(void) noexcept;
    void scanFile(void) throw(std::runtime_error);
    bool isTmValid(std::tm const& tm) const noexcept;

    std::string fileSpec_;
    bool readUser_;
    bool writeUser_;
    bool executeUser_;
    bool readGroup_;
    bool writeGroup_;
    bool executeGroup_;
    bool readOther_;
    bool writeOther_;
    bool executeOther_;
    bool isLink_;
    std::tm dateCreated_;
    std::tm dateLastAccessed_;
    std::tm dateLastModified_;
    uint64_t fileSize_;

    static const char kAttrCharNothing = '-';
    static const char kAttrCharRead = 'r';
    static const char kAttrCharWrite = 'w';
    static const char kAttrCharExecute = 'x';
    static const int32_t kTimeDateMinSec = 0;
    static const int32_t kTimeDateMaxSec = 60;
    static const int32_t kTimeDateMinMin = 0;
    static const int32_t kTimeDateMaxMin = 59;
    static const int32_t kTimeDateMinHour = 0;
    static const int32_t kTimeDateMaxHour = 23;
    static const int32_t kTimeDateMinMonthDay = 1;
    static const int32_t kTimeDateMaxMonthDay = 31;
    static const int32_t kTimeDateMinMonth = 0;
    static const int32_t kTimeDateMaxMonth = 11;
    static const int32_t kTimeDateMaxYearIncrement = 200;
    static const int32_t kTimeDateMinWeekDay = 0;
    static const int32_t kTimeDateMaxWeekDay = 6;
    static const int32_t kTimeDateMinYearDay = 0;
    static const int32_t kTimeDateMaxYearDay = 365;
    static const int32_t kTimeDateMinDstValue = -1;
    static const int32_t kTimeDateMaxDstValue = 1;
};

}  // namespace utils

}  // namespace giotto

#endif /* GFileObject_hpp */

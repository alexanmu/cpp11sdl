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

#ifndef GFSBaseClass_hpp
#define GFSBaseClass_hpp

#include <stdexcept>
#include <cstdint>
#include <ctime>
#include <string>

#include "GObject.hpp"

namespace giotto
{

namespace utils
{

class GFSBaseClass : public objects::GObject
{
public:
    virtual ~GFSBaseClass();

    std::string _getWorkingDirectory(void) const;
    void _setWorkingDirectory(std::string const& dir) const throw(std::runtime_error);
    std::string _getFilePath(std::string const& filespec) const;
    std::string _getFileName(std::string const& filespec) const;
    std::string _getParentFolder(std::string const& filespec) const;

    std::string _getCurrentDateAsString(std::string const& sep1, std::string const& sep2) const;
    std::string _getCurrentDateAsString(void) const;
    std::string _getCurrentTimeAsString(std::string const& sep1, std::string const& sep2) const;
    std::string _getCurrentTimeAsString(void) const;

    std::string _getDateAsString(std::tm const& date, std::string const& sep1, std::string const& sep2) const;
    std::string _getDateAsString(std::tm const& date) const;
    std::string _getTimeAsString(std::tm const& time, std::string const& sep1, std::string const& sep2) const;
    std::string _getTimeAsString(std::tm const& time) const;

    const char kFolderSeparator = '/';
    const char kExtensionSeparator = '.';
private:
    std::string _lz(std::string const& str, const uint32_t elen) const;
};

}  // namespace utils

}  // namespace giotto

#endif /* GFSBaseClass_hpp */

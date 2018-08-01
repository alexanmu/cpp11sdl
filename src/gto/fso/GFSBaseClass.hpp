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

namespace gto
{

namespace fso
{

class GFSBaseClass : public gobj::GObject
{
public:
    virtual ~GFSBaseClass();

    std::string _getWorkingDirectory(void) const;
    void _setWorkingDirectory(const std::string& dir) const throw(std::runtime_error);
    std::string _getFilePath(const std::string& filespec) const;
    std::string _getFileName(const std::string& filespec) const;
    std::string _getParentFolder(const std::string& filespec) const;

    std::string _getCurrentDateAsString(const std::string& sep1, const std::string& sep2) const;
    std::string _getCurrentDateAsString(void) const;
    std::string _getCurrentTimeAsString(const std::string& sep1, const std::string& sep2) const;
    std::string _getCurrentTimeAsString(void) const;

    std::string _getDateAsString(const std::tm& date, const std::string& sep1, const std::string& sep2) const;
    std::string _getDateAsString(const std::tm& date) const;
    std::string _getTimeAsString(const std::tm& time, const std::string& sep1, const std::string& sep2) const;
    std::string _getTimeAsString(const std::tm& time) const;

    const char kFolderSeparator = '/';
    const char kExtensionSeparator = '.';
private:
    std::string _lz(const std::string& str, const uint32_t elen) const;
};

}  // namespace fso

}  // namespace gto

#endif /* GFSBaseClass_hpp */

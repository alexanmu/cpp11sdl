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

#include <unistd.h>
#include <errno.h>
#include <stdexcept>
#include <cassert>
#include <ctime>
#include <string>

#include "GFSBaseClass.hpp"

namespace giotto
{

namespace utils
{

GFSBaseClass::~GFSBaseClass()
{
    // Nothing to do yet
}

std::string GFSBaseClass::_getWorkingDirectory(void) const
{
    // https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html#Working-Directory
    std::size_t size = 100;
    char * buffer;
    std::string ret = "";

    while (1)
    {
        buffer = reinterpret_cast<char *>(malloc(size));
        if (getcwd(buffer, size) == buffer)
        {
            break;
        }
        free(buffer);
        if (errno != ERANGE)
        {
            return ret;
        }
        size *= 2;
    }
    ret = std::string(buffer);
    free(buffer);
    return ret;
}

void GFSBaseClass::_setWorkingDirectory(std::string const& dir) const throw(std::runtime_error)
{
    int ret;

    ret = chdir(dir.c_str());
    if (ret != 0)
    {
        throw std::runtime_error("Failure occured");
    }
}

std::string GFSBaseClass::_getFilePath(std::string const& filespec)
{
    assert(filespec.length() > 0);

    std::size_t n;
    std::string ret;

    n = filespec.rfind(kFolderSeparator);
    if (n != std::string::npos)
    {
        ret =  filespec.substr(0, n);
    }
    else
    {
        ret = filespec;
    }
    return ret;
}

std::string GFSBaseClass::_getFileName(std::string const& filespec)
{
    assert(filespec.length() > 0);

    std::size_t n;
    std::string fname;
    std::string name;
    std::string ext;
    std::string ret;

    n = filespec.rfind(kFolderSeparator);
    if (n != std::string::npos)
    {
        fname =  filespec.substr(n + 1);
    }
    else
    {
        fname = filespec;
    }
    n = fname.rfind(kExtensionSeparator);
    if (n != std::string::npos)
    {
        if (n == 1)
        {
            ext = "";
            name = fname;
        }
        else
        {
            ext = fname.substr(n + 1);
            name = fname.substr(0, n);
        }
    }
    else
    {
        ext = "";
        name = fname;
    }
    if (ext.length() > 0)
    {
        ret = name + kExtensionSeparator + ext;
    }
    else
    {
        ret = name;
    }
    return ret;
}

std::string GFSBaseClass::_getCurrentDateAsString(std::string const& sep1, std::string const& sep2)
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::string y = std::to_string(tm.tm_year + 1900);
    std::string m = std::to_string(tm.tm_mon + 1);
    std::string d = std::to_string(tm.tm_mday);

    return y + sep1 + _lz(m, 2) + sep2 + _lz(d, 2);
}

std::string GFSBaseClass::_getCurrentTimeAsString(std::string const& sep1, std::string const& sep2)
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::string h = std::to_string(tm.tm_hour);
    std::string m = std::to_string(tm.tm_min);
    std::string s = std::to_string(tm.tm_sec);

    return _lz(h, 2) + sep1 + _lz(m, 2) + sep2 + _lz(s, 2);
}

// Private methods
std::string GFSBaseClass::_lz(std::string const& str, const uint32_t elen)
{
    std::string s;

    if (str.length() < elen)
    {
        for (uint32_t i = 0; i < elen - str.length(); i++)
        {
            s += "0";
        }
    }
    else
    {
        s = "";
    }
    return s + str;
}

}  // namespace utils

}  // namespace giotto

/* EOF */

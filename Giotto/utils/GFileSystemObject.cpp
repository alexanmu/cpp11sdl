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

#include <string>

#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"

namespace giotto
{

namespace utils
{

GFileSystemObject::GFileSystemObject(std::string const& vname) : objects::GObject(vname)
{
}

GFileSystemObject::~GFileSystemObject()
{
}

std::string GFileSystemObject::buildPath(std::string const& path, std::string const& filename)
{
    std::string spec;

    if (path[path.length() - 1] != kFolderSeparator)
    {
        spec = path + kFolderSeparator + filename;
    }
    else
    {
        spec = path + filename;
    }
    return spec;
}

void GFileSystemObject::copyFile(std::string const& source, std::string const& destiantion, bool overwrite) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::copyFolder(std::string const& source, std::string const& destination, bool overwrite) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::createFolder(std::string const& foldername) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::deleteFile(std::string const& filespec, bool force) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::deleteFolder(std::string const& folderspec, bool force) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

bool GFileSystemObject::fileExists(std::string const& filespec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

bool GFileSystemObject::folderExists(std::string const& folderspec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

/*GFileObject GFileSystemObject::getFile(std::string const& filespec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}*/

std::string GFileSystemObject::getFileName(std::string const& filespec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

GFolderObject GFileSystemObject::getFolder(std::string const& folderspec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

std::string GFileSystemObject::getParentFolderName(std::string const& folderspec) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

std::string GFileSystemObject::getTempName(void) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::moveFile(std::string const& source, std::string const& destination) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::moveFolder(std::string const& source, std::string const& destination) throw(std::runtime_error)
{
    throw std::runtime_error("Not implemented");
}

}  // namespace utils

}  // namespace giotto

/* EOF */

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

#include <cassert>
#include <string>

#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"
#include "GFileObject.hpp"

namespace gto
{

namespace fso
{

GFileSystemObject::GFileSystemObject() : GFSBaseClass()
{
    errorCode_ = GFSOErrorCode::noError;
}

GFileSystemObject::~GFileSystemObject()
{
}

GFileSystemObject::GFSOErrorCode GFileSystemObject::getError(void) const noexcept
{
    return errorCode_;
}

const std::string GFileSystemObject::buildPath(const std::string& path, const std::string& filename)
{
    assert(path.length() > 0);
    assert(filename.length() > 0);

    std::string spec;

    if (path[path.length() - 1] != kFolderSeparator)
    {
        spec = path + kFolderSeparator + filename;
    }
    else
    {
        spec = path + filename;
    }
    errorCode_ = GFSOErrorCode::noError;
    return spec;
}

void GFileSystemObject::copyFile(const std::string& source, const std::string& destination, const bool overwrite)
                throw(std::runtime_error)
{
    assert(source.length() > 0);
    assert(destination.length() > 0);
    assert(overwrite == true || overwrite == false);
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::copyFolder(const std::string& source, const std::string& destination, const bool overwrite)
                throw(std::runtime_error)
{
    assert(source.length() > 0);
    assert(destination.length() > 0);
    assert((overwrite == true || overwrite == false));
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::createFolder(const std::string& foldername) throw(std::runtime_error)
{
    assert(foldername.length() > 0);

    /* sys/stat.h
        int mkdir(const char *filename, mode_t mode)
    */
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::deleteFile(const std::string& filespec, const bool force) throw(std::runtime_error)
{
    assert(filespec.length() > 0);
    assert((force == true || force == false));

    /* unistd.h
        int unlink(const char* filename);
    */
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::deleteFolder(const std::string& folderspec, const bool force) throw(std::runtime_error)
{
    assert(folderspec.length() > 0);
    assert((force == true || force == false));
    /* unistd.h
        int rmdir(const char * filename);
    */
    throw std::runtime_error("Not implemented");
}

bool GFileSystemObject::fileExists(const std::string& filespec)
{
    //  https://stackoverflow.com/questions/9314586/c-faster-way-to-check-if-a-directory-exists
    assert(filespec.length() > 0);

    if (access(filespec.c_str(), F_OK) != 0)
    {
        return false;
    }
    errorCode_ = GFSOErrorCode::noError;
    return true;
}

bool GFileSystemObject::folderExists(const std::string& folderspec)
{
    //  https://stackoverflow.com/questions/9314586/c-faster-way-to-check-if-a-directory-exists
    assert(folderspec.length() > 0);

    std::string path;

    path = folderspec;
    if (folderspec[folderspec.length() - 1] != kFolderSeparator)
    {
        path += kFolderSeparator;
    }
    if (access(path.c_str(), F_OK) != 0)
    {
        if (errno == ENOENT)
        {
            // Does not exist
            return false;
        }
        if (errno == ENOTDIR)
        {
            // Not a directory
            return false;
        }
        // Another error occurred
        return false;
    }
    errorCode_ = GFSOErrorCode::noError;
    return true;
}

GFileObject * GFileSystemObject::getFile(const std::string& filespec)
{
    assert(filespec.length() > 0);

    errorCode_ = GFSOErrorCode::noError;
    return new GFileObject(filespec);
}

const std::string GFileSystemObject::getFileName(const std::string& filespec)
{
    assert(filespec.length() > 0);

    errorCode_ = GFSOErrorCode::noError;
    return _getFileName(filespec);
}

GFolderObject * GFileSystemObject::getFolder(const std::string& folderspec)
{
    assert(folderspec.length() > 0);

    std::string fullpath;

    if (folderspec[folderspec.length() - 1] != kFolderSeparator)
    {
        fullpath = folderspec + kFolderSeparator;
    }
    else
    {
        fullpath = folderspec;
    }
    errorCode_ = GFSOErrorCode::noError;
    return new GFolderObject(fullpath);
}

const std::string GFileSystemObject::getParentFolderName(const std::string& folderspec) throw(std::runtime_error)
{
    assert(folderspec.length() > 0);
    throw std::runtime_error("Not implemented");
}

const std::string GFileSystemObject::getTempName(void) throw(std::runtime_error)
{
    /* unistd.h?
        char * tmpname(const char* dir, const char * prefix);
        == NULL on failure
    */
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::moveFile(const std::string& source, const std::string& destination) throw(std::runtime_error)
{
    assert(source.length() > 0);
    assert(destination.length() > 0);

    /* unistd.h?
        int rename(const char* oldname, const char* newname);
    */
    throw std::runtime_error("Not implemented");
}

void GFileSystemObject::moveFolder(const std::string& source, const std::string& destination) throw(std::runtime_error)
{
    assert(source.length() > 0);
    assert(destination.length() > 0);

    /* unistd.h?
        int rename(const char* oldname, const char* newname);
    */
    throw std::runtime_error("Not implemented");
}

}  // namespace fso

}  // namespace gto

/* EOF */


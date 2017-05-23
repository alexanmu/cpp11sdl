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

#ifndef GFileSystemObject_hpp
#define GFileSystemObject_hpp

#include <stdexcept>
#include <string>

#include "GFSBaseClass.hpp"

namespace giotto
{

namespace utils
{

class GFileObject;
class GFolderObject;

class GFileSystemObject : public GFSBaseClass
{
public:
    GFileSystemObject();

    GFileSystemObject(GFileSystemObject const&) = delete;
    GFileSystemObject(GFileSystemObject&&) = delete;

    GFileSystemObject& operator=(GFileSystemObject const&) = delete;
    GFileSystemObject& operator=(GFileSystemObject&&) = delete;

    virtual ~GFileSystemObject();

    std::string buildPath(std::string const& path, std::string const& filename);
    void copyFile(std::string const& source, std::string const& destination, bool overwrite)
               throw(std::runtime_error);
    void copyFolder(std::string const& source, std::string const& destination, bool overwrite)
               throw(std::runtime_error);
    void createFolder(std::string const& foldername) throw(std::runtime_error);
    void deleteFile(std::string const& filespec, bool force) throw(std::runtime_error);
    void deleteFolder(std::string const& folderspec, bool force) throw(std::runtime_error);
    bool fileExists(std::string const& filespec) throw(std::runtime_error);
    bool folderExists(std::string const& folderspec) throw(std::runtime_error);
    GFileObject * getFile(std::string const& filespec);
    std::string getFileName(std::string const& filespec);
    GFolderObject * getFolder(std::string const& folderspec);
    std::string getParentFolderName(std::string const& folderspec) throw(std::runtime_error);
    std::string getTempName(void) throw(std::runtime_error);
    void moveFile(std::string const& source, std::string const& destination) throw(std::runtime_error);
    void moveFolder(std::string const& source, std::string const& destination) throw(std::runtime_error);
private:
};

}  // namespace utils

}  // namespace giotto

#endif /* GFileSystemObject_hpp */

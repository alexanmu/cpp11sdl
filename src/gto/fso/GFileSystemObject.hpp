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
#include <cstdint>
#include <string>

#include "GFSBaseClass.hpp"

namespace gto
{

namespace fso
{

class GFileObject;
class GFolderObject;

class GFileSystemObject : public GFSBaseClass
{
public:
    enum class GFSOErrorCode : uint8_t
    {
        noError = 0
    };

    GFileSystemObject();

    GFileSystemObject(const GFileSystemObject&) = delete;
    GFileSystemObject(GFileSystemObject&&) = delete;

    GFileSystemObject& operator=(const GFileSystemObject&) = delete;
    GFileSystemObject& operator=(GFileSystemObject&&) = delete;

    virtual ~GFileSystemObject();

    GFSOErrorCode getError(void) const noexcept;

    const std::string buildPath(const std::string& path, const std::string& filename);
    void copyFile(const std::string& source, const std::string& destination, const bool overwrite)
               throw(std::runtime_error);
    void copyFolder(const std::string& source, const std::string& destination, const bool overwrite)
               throw(std::runtime_error);
    void createFolder(const std::string& foldername) throw(std::runtime_error);
    void deleteFile(const std::string& filespec, const bool force) throw(std::runtime_error);
    void deleteFolder(const std::string& folderspec, const bool force) throw(std::runtime_error);
    bool fileExists(const std::string& filespec);
    bool folderExists(const std::string& folderspec);
    GFileObject * getFile(const std::string& filespec);
    const std::string getFileName(const std::string& filespec);
    GFolderObject * getFolder(const std::string& folderspec);
    const std::string getParentFolderName(const std::string& folderspec) throw(std::runtime_error);
    const std::string getTempName(void) throw(std::runtime_error);
    void moveFile(const std::string& source, const std::string& destination) throw(std::runtime_error);
    void moveFolder(const std::string& source, const std::string& destination) throw(std::runtime_error);
private:
    GFSOErrorCode errorCode_;
};

}  // namespace fso

}  // namespace gto

#endif /* GFileSystemObject_hpp */

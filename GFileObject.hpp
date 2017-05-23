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
#include <vector>
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

    explicit GFileObject(std::string const& fileSpec);
    explicit GFileObject(GFileCollectionElement const& file);

    GFileObject(GFileObject const&) = delete;
    GFileObject(GFileObject&&) = delete;

    GFileObject& operator=(GFileObject const&) = delete;
    GFileObject& operator=(GFileObject&&) = delete;

    virtual ~GFileObject();

    std::string const& getFileSpec(void) const;
    std::string getAttributesAsString(void) const;

    void rescan(void);
private:
    void scanFile(void);

    std::string fileSpec_;
    bool rdUsr_;
    bool wrUsr_;
    bool xcUsr_;
    bool rdGrp_;
    bool wrGrp_;
    bool xcGrp_;
    bool rdOth_;
    bool wrOth_;
    bool xcOth_;
    bool isLink_;
    std::tm dateCreated_;
    std::tm dateLastAccessed_;
    std::tm dateLastModified_;
    std::string parentFolder_;
    std::string path_;
    uint64_t size_;
};

}  // namespace utils

}  // namespace giotto

#endif /* GFileObject_hpp */

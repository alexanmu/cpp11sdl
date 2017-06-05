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

#ifndef GfxRootClass_hpp
#define GfxRootClass_hpp

#include <cstdint>
#include <string>

namespace gfx
{

class GfxRootClass
{
public:
    GfxRootClass() noexcept;

    explicit GfxRootClass(const std::string& strClassName) noexcept;

    GfxRootClass(const GfxRootClass& other) noexcept;
    GfxRootClass(GfxRootClass&& other) noexcept;

    virtual ~GfxRootClass() noexcept;

    GfxRootClass& operator=(const GfxRootClass& other) noexcept;
    GfxRootClass& operator=(GfxRootClass&& other) noexcept;

    bool operator==(const GfxRootClass& other) const noexcept;

    virtual explicit operator bool() const noexcept;

    std::string const& getClassName(void) const noexcept;
    int32_t getInstanceId(void) const noexcept;
private:
    std::string strClassName_;
    int32_t i32InstanceId_;

    struct stClassInfo
    {
        const char * pchClassName;
        int32_t iSize;
    };

    static const struct stClassInfo astClassInfo[];
    static const int32_t i32ClassNamesCount;

    static int32_t i32InstanceCounter_;
};

}  // namespace gfx

#endif /* GfxRootClass_hpp */

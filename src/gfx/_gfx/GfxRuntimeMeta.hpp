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

#ifndef GfxRuntimeMeta_hpp
#define GfxRuntimeMeta_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <map>
#include <ostream>

namespace gfx
{

namespace _gfx
{

class GfxRuntimeMeta final
{
public:
    struct ClassInfo
    {
        int32_t maxObjectInstanceCount_;
        int32_t objectInstanceCount_;
        int32_t firstInstanceId_;
        int32_t lastInstanceId_;
    };

    static bool runtimeMetaActive;

    static GfxRuntimeMeta& getInstance(void) noexcept;

    const ClassInfo& getClassInfo(const int32_t index) noexcept;
    const std::string getClassName(const int32_t index) noexcept;
    int32_t getClassCount(void) const noexcept;

    void constructObject(const char * className, const int32_t instanceId) noexcept;
    void destructObject(const char * className, const int32_t instanceId) noexcept;

    std::ostream& printToStream(std::ostream& ostream) const noexcept;

    // Should only be called during debugging
    void clear_map(void) noexcept;
private:
    GfxRuntimeMeta() noexcept;

    GfxRuntimeMeta(const GfxRuntimeMeta&) = delete;
    GfxRuntimeMeta(GfxRuntimeMeta&&) = delete;

    GfxRuntimeMeta& operator=(const GfxRuntimeMeta&) = delete;
    GfxRuntimeMeta& operator=(GfxRuntimeMeta&&) = delete;

    ~GfxRuntimeMeta() noexcept;

    void clear(void) noexcept;

    // std::map is faster! Hash computation in case of
    // std::unordered_map is slow for my case
    std::map<const char *, ClassInfo> classUMap;

    ClassInfo classInfo_;
};

}  // namespace _gfx

}  // namespace gfx

#endif  // GfxRuntimeMeta_hpp

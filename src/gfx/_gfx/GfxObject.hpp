/*
  Giotto
  Copyright (C) 2020 George Oros

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

#ifndef GfxObject_hpp
#define GfxObject_hpp

#include <cstdint>
#include <string>

#include "GfxRuntimeMeta.hpp"

namespace gfx
{

namespace _gfx
{

class GfxObject
{
public:
    GfxObject() noexcept;

    explicit GfxObject(const char * className) noexcept;

    GfxObject(const GfxObject& other) noexcept;
    GfxObject(GfxObject&& other) noexcept;

    virtual ~GfxObject() noexcept;

    GfxObject& operator=(const GfxObject& other) noexcept;
    GfxObject& operator=(GfxObject&& other) noexcept;

    bool operator==(const GfxObject& other) const noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const char * getClassName(void) const noexcept;
    int32_t getInstanceId(void) const noexcept;

    // Don't use in code; just for testing
    static int32_t getInstanceCounter(void) noexcept;
private:
    alignas(8) const char * className_;
    alignas(8) GfxRuntimeMeta * rMeta_;
    alignas(4) int32_t instanceId_;
    alignas(4) int32_t padding1;
    /* alignas(8) void * vtable; */

    static int32_t instanceCounter_;
    static const char initMsg[];
    static const char nullMsg[];
};

}  // namespace _gfx

using _gfx::GfxObject;

static_assert(sizeof(void *) == 8, "Size of pointer is not 8 bytes");
static_assert(sizeof(int32_t) == 4, "Size of int32_t is not 4 bytes");
static_assert(sizeof(GfxObject) == 32, "Size of GfxObject is not 32 bytes");

}  // namespace gfx

#endif /* GfxObject_hpp */


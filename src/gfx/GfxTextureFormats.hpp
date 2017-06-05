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

#ifndef GfxTextureFormats_hpp
#define GfxTextureFormats_hpp

#include <stdexcept>
#include <cstdint>

#include "GfxRootClass.hpp"

namespace gfx
{

class GfxTextureFormats final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxTextureFormats() noexcept;
    explicit GfxTextureFormats(const int32_t formatsCount) throw(std::runtime_error);
    explicit GfxTextureFormats(const int32_t formatsCount, const uint32_t formats[]) throw(std::runtime_error);

    GfxTextureFormats(GfxTextureFormats const& other) noexcept;
    GfxTextureFormats(GfxTextureFormats&& other) noexcept;

    GfxTextureFormats& operator=(GfxTextureFormats const& other) noexcept;
    GfxTextureFormats& operator=(GfxTextureFormats&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    void setCount(const int32_t formatsCount) throw(std::runtime_error);
    void setFormat(const int32_t formatIndex, const uint32_t formatValue) throw(std::runtime_error);
    void setAllFormats(const uint32_t formats[]) noexcept;
    int32_t getMaxFormatsCount(void) const noexcept;
    int32_t getFormatsCount(void) const noexcept;

    uint32_t& operator[](const int32_t formatIndex) throw(std::runtime_error);
    uint32_t const& operator[](const int32_t formatIndex) const throw(std::runtime_error);

    void clear(void) noexcept;
private:
    static const int32_t kTextureFormatsArrayLength = 16;
    uint32_t formats_[kTextureFormatsArrayLength];
    int32_t formatsCount_;
};

}  // namespace gfx

#endif /* GfxTextureFormats_hpp */

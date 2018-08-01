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

#ifndef GfxRwOps_hpp
#define GfxRwOps_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"

namespace gfx
{

namespace rwops
{

class GfxRwOps final : public GfxObject
{
public:
    typedef SDL_RWops * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxRwOps() noexcept;
    explicit GfxRwOps(const SdlTypePtr rwops) throw(std::runtime_error);

    GfxRwOps(const GfxRwOps& other) = delete;
    GfxRwOps(GfxRwOps&& other) noexcept;

    GfxRwOps& operator=(const GfxRwOps& other) = delete;
    GfxRwOps& operator=(GfxRwOps&& other) noexcept;

    virtual ~GfxRwOps() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    static constexpr const int32_t rwSeekSet = 0;
    static constexpr const int32_t reSeekCur = 1;
    static constexpr const int32_t rwSeekEnd = 2;

    static const GfxRwOps rwFromFile(const std::string& file, const std::string& mode);
    static const GfxRwOps rwFromFP(void * fp, const GfxBool& autoclose);
    static const GfxRwOps rwFromMem(void * mem, const int32_t size);
    static const GfxRwOps rwFromConstMem(const void * mem, const int32_t size);

    void allocRw(void) throw(std::runtime_error);
    void freeRw(void) throw(std::runtime_error);

    void * loadFileRw(std::size_t * datasize, const int32_t freesrc) const;

    uint8_t readU8(void) const;
    uint16_t readLE16(void) const;
    uint16_t readBE16(void) const;
    uint32_t readLE32(void) const;
    uint32_t readBE32(void) const;
    uint64_t readLE64(void) const;
    uint64_t readBE64(void) const;

    std::size_t writeU8(const uint8_t value) const;
    std::size_t writeLE16(const uint16_t value) const;
    std::size_t writeBE16(const uint16_t value) const;
    std::size_t writeLE32(const uint32_t value) const;
    std::size_t writeBE32(const uint32_t value) const;
    std::size_t writeLE64(const uint64_t value) const;
    std::size_t writeBE64(const uint64_t value) const;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr rwOps_;
};

}  // namespace rwops

}  // namespace gfx

#endif /* GfxRwOps_hpp */

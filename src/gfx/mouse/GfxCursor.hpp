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

#ifndef GfxCursor_hpp
#define GfxCursor_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxSurface.hpp"
#include "GfxSystemCursor.hpp"

namespace gfx
{

namespace mouse
{

class GfxCursor final : public GfxObject
{
public:
    typedef sdl2::SDL_Cursor * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxCursor() noexcept;
    explicit GfxCursor(const SdlTypePtr cursor) noexcept;
    GfxCursor(const uint8_t * data, const uint8_t * mask, const int32_t w, const int32_t h,
              const int32_t hot_x, const int32_t hot_y) throw(std::runtime_error);
    GfxCursor(surface::GfxSurface const& surface, const int32_t hot_x,
              const int32_t hot_y) throw(std::runtime_error);
    explicit GfxCursor(GfxSystemCursor const& id) throw(std::runtime_error);

    GfxCursor(GfxCursor const&) = delete;
    GfxCursor(GfxCursor&& other) noexcept;

    GfxCursor& operator=(GfxCursor const&) = delete;
    GfxCursor& operator=(GfxCursor&& other) noexcept;

    virtual ~GfxCursor() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createCursor(const SdlTypePtr cursor) throw(std::runtime_error);
    void createCursor(const uint8_t * data, const uint8_t * mask, const int32_t w, const int32_t h,
                      const int32_t hot_x, const int32_t hot_y) throw(std::runtime_error);
    void createCursor(surface::GfxSurface const& surface, const int32_t hot_x,
                      const int32_t hot_y) throw(std::runtime_error);
    void createCursor(GfxSystemCursor const& id) throw(std::runtime_error);
    void setCursor(void) const noexcept;
    GfxCursor::SdlTypePtr getCursor(void) const noexcept;
    GfxCursor::SdlTypePtr getDefaultCursor(void) const noexcept;
    void freeCursor(void) noexcept;
    int32_t showCursor(const int32_t toggle) const noexcept;

    void showCursor(void) const noexcept;
    void hideCursor(void) const noexcept;
    GfxBool isVisible(void) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr cursor_;
};

}  // namespace mouse

}  // namespace gfx

#endif /* GfxCursor_hpp */

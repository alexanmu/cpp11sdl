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

#ifndef GfxTtfFont_hpp
#define GfxTtfFont_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFont final : public GfxRootClass
{
public:
    typedef sdl2::TTF_Font* SdlTypePtr;

    static const char ClassName[];

    GfxTtfFont();
    GfxTtfFont(std::string const& filename, int32_t pointsize);
    GfxTtfFont(std::string const& filename, int32_t pointsize, int32_t index);

    /* GfxTtfFont(SDL_RWops * src ...)
    GfxTtfFont(SDL_RWops * src ..., long index) */

    GfxTtfFont(GfxTtfFont const& other) = delete;
    GfxTtfFont(GfxTtfFont&& other);

    GfxTtfFont& operator=(GfxTtfFont const& other) = delete;
    GfxTtfFont& operator=(GfxTtfFont&& other);

    virtual ~GfxTtfFont();

    void openFont(std::string const& filename, int32_t pointsize) throw(std::runtime_error);
    void openFont(std::string const& filename, int32_t pointsize, int32_t index) throw(std::runtime_error);
    void closeFont(void);

    void clear(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlTypePtr ttf_;
    std::string fileName_;
    int32_t pointSize_;
    int32_t index_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFont_hpp

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

#ifndef GBitmap_hpp
#define GBitmap_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GComponent.hpp"
#include "GImage.hpp"
#include "GTypes.hpp"

namespace gto
{

namespace gobj
{

class GBitmap : public GImage
{
public:
    GBitmap() = delete;

    GBitmap(GBitmap const& other) = delete;
    GBitmap(GBitmap&& other) = delete;

    GBitmap& operator=(GBitmap const& other) = delete;
    GBitmap& operator=(GBitmap&& other) = delete;

    explicit GBitmap(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                    GImageScaleMode const& scalemode, std::string const& filename);
    virtual ~GBitmap();

    virtual void load(void) throw(std::runtime_error);
    virtual void draw(void) throw(std::runtime_error);
private:
    gfx::supp::GfxControlledSurface imgSurf_;
};

}  // namespace gobj

}  // namespace gto

#endif /* GBitmap_hpp */

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

#ifndef GfxControlledSurface_hpp
#define GfxControlledSurface_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxSurface.hpp"

namespace gfx
{

namespace supp
{

class GfxControlledSurface final
{
public:
    GfxControlledSurface();

    GfxControlledSurface(const GfxControlledSurface&) = delete;
    GfxControlledSurface(GfxControlledSurface&& surf) = delete;

    GfxControlledSurface& operator=(const GfxControlledSurface&) = delete;
    GfxControlledSurface& operator=(GfxControlledSurface&& surf) = delete;

    virtual ~GfxControlledSurface();

    virtual explicit operator bool() const;

    void createSurface(const uint16_t w, const uint16_t h) throw(std::runtime_error);
    void createSurface(std::string const& filename) throw(std::runtime_error);

    void free(void) noexcept;

    gfx::GfxSurface& operator()(void) const throw(std::runtime_error);
private:
    gfx::GfxSurface * surf_;
    bool surfaceConstructed_;
};

}  // namespace supp

}  // namespace gfx

#endif /* GfxControledSurface_hpp */

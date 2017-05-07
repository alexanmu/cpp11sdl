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

#ifndef GfxTexture_hpp
#define GfxTexture_hpp

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxSurface.hpp"
#include "GfxBlendMode.hpp"
#include "GfxTextureModulate.hpp"
#include "GfxTextureAccess.hpp"

namespace gfx
{

class GfxTexture final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Texture SdlType;
    typedef sdl2::SDL_Texture* SdlTypePtr;

    static const std::string ClassName;

    GfxTexture() = delete;

    explicit GfxTexture(GfxRootClass * rend, const GfxTextureAccess& acc, const int32_t w, const int32_t h);
    explicit GfxTexture(GfxRootClass * rend, const GfxSurface& surf);

    virtual ~GfxTexture();

    GfxTexture(const GfxTexture&) = delete;
    GfxTexture(GfxTexture&& tex);

    GfxTexture& operator=(const GfxTexture&) = delete;
    GfxTexture& operator=(GfxTexture&& tex);

    void destroyTexture(void);

    void setBlendMode(const GfxBlendMode& blendmode);
    void setBlendMode(const GfxBlendMode::GfxBlendModeValues blendmode);
    GfxBlendMode getBlendMode(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    GfxRootClass * rend_;
    SdlTypePtr tex_;
};

}  // namespace gfx

#endif /* GfxTexture_hpp */

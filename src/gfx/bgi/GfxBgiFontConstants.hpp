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

#ifndef GfxBgiFontConstants_hpp
#define GfxBgiFontConstants_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxBitmapFont.hpp"

namespace gfx
{
namespace bgi
{
namespace fnt
{

class GfxBgiFontConstants final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxBgiFontConstants() = delete;

    GfxBgiFontConstants(const GfxBgiFontConstants&) = delete;
    GfxBgiFontConstants(GfxBgiFontConstants&&) = delete;

    GfxBgiFontConstants& operator=(const GfxBgiFontConstants&) = delete;
    GfxBgiFontConstants& operator=(GfxBgiFontConstants&&) = delete;

    static const int fntNumFonts = 10;

    enum class GfxFontIndex : int32_t
    {
        indexStandard8x16 = 0,
        indexAntique = 1,
        indexBroadway = 2,
        indexCourrier = 3,
        indexDragon = 4,
        indexMedieval = 5,
        indexRoman = 6,
        indexSansserif = 7,
        indexScript = 8,
        indexWacky = 9
    };

    static const GfxBitmapFont& fntStandard8x16(void);
    static const GfxBitmapFont& fntAntique(void);
    static const GfxBitmapFont& fntBroadway(void);
    static const GfxBitmapFont& fntCourrier(void);
    static const GfxBitmapFont& fntDragon(void);
    static const GfxBitmapFont& fntMedieval(void);
    static const GfxBitmapFont& fntRoman(void);
    static const GfxBitmapFont& fntSansserif(void);
    static const GfxBitmapFont& fntScript(void);
    static const GfxBitmapFont& fntWacky(void);

    static const GfxBitmapFont& fntGetFontByIndex(const GfxFontIndex index);
private:
    static const GfxBitmapFont fonts_[fntNumFonts];

    static const uint8_t fntStandard8x16Data_[16 * 256];
    static const uint8_t fntAntiqueData_[16 * 256];
    static const uint8_t fntBroadwayData_[16 * 256];
    static const uint8_t fntCourrierData_[16 * 256];
    static const uint8_t fntDragonData_[16 * 256];
    static const uint8_t fntMedievalData_[16 * 256];
    static const uint8_t fntRomanData_[16 * 256];
    static const uint8_t fntSansserifData_[16 * 256];
    static const uint8_t fntScriptData_[16 * 256];
    static const uint8_t fntWackyData_[16 * 256];
};

}  // namespace fnt
}  // namespace bgi
}  // namespace gfx

#endif

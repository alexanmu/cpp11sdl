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

#include <string>

#include "GfxBitmapFont.hpp"
#include "GfxBgiFontConstants.hpp"

#include "fntStandard8x16.hpp"
#include "fntAntique.hpp"
#include "fntBroadway.hpp"
#include "fntCourrier.hpp"
#include "fntDragon.hpp"
#include "fntMedieval.hpp"
#include "fntRoman.hpp"
#include "fntSansserif.hpp"
#include "fntScript.hpp"
#include "fntWacky.hpp"

namespace gfx
{
namespace bgi
{
namespace fnt
{

const char GfxBgiFontConstants::ClassName[] = "GfxBgiFontConstants";

const GfxBitmapFont GfxBgiFontConstants::fonts_[10] {
    { &fntStandard8x16Data_[0], 8, 16 },
    { &fntAntiqueData_[0], 8, 16 },
    { &fntBroadwayData_[0], 8, 16 },
    { &fntCourrierData_[0], 8, 16 },
    { &fntDragonData_[0], 8, 16 },
    { &fntMedievalData_[0], 8, 16 },
    { &fntRomanData_[0], 8, 16 },
    { &fntSansserifData_[0], 8, 16 },
    { &fntScriptData_[0], 8, 16 },
    { &fntWackyData_[0], 8, 16 }
};

const GfxBitmapFont& GfxBgiFontConstants::fntStandard8x16(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexStandard8x16)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntAntique(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexAntique)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntBroadway(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexBroadway)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntCourrier(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexCourrier)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntDragon(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexDragon)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntMedieval(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexMedieval)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntRoman(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexRoman)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntSansserif(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexSansserif)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntScript(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexScript)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntWacky(void)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(GfxFontIndex::indexWacky)];
}

const GfxBitmapFont& GfxBgiFontConstants::fntGetFontByIndex(const GfxFontIndex index)
{
    return GfxBgiFontConstants::fonts_[static_cast<int>(index)];
}

}  // namespace fnt
}  // namespace bgi
}  // namespace gfx

/* EOF */

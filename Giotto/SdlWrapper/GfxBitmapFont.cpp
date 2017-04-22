/*
  CPP11SDL
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
#include <cstring>

#include "GfxBitmapFont.hpp"

GfxBitmapFont::GfxBitmapFont() : GfxRootClass("GfxBitmapFont"), fontData_(nullptr), fontDataSize_(0), fontWidth_(0), fontHeight_(0)
{
    //
}

GfxBitmapFont::GfxBitmapFont(const uint8_t* fontData, const uint8_t fontWidth, const uint8_t fontHeight) : GfxRootClass("GfxBitmapFont")
{
    fontWidth_ = 0;
    fontHeight_ = 0;
    fontDataSize_ = 0;
    fontData_ = nullptr;

    if ((fontWidth > 0) && (fontHeight > 0))
    {
        if (((fontWidth % 8) == 0) && ((fontHeight % 8) == 0))
        {
            fontWidth_ = fontWidth;
            fontHeight_ = fontHeight;
            fontDataSize_ = fontWidth / 8 * fontHeight * 256;
            fontData_ = new uint8_t[fontDataSize_];
            std::memcpy(fontData_,fontData,fontDataSize_);
        }
    }
}

GfxBitmapFont::GfxBitmapFont(const GfxBitmapFont& other)
{
    fontWidth_ = other.fontWidth_;
    fontHeight_ = other.fontHeight_;
    fontDataSize_ = other.fontDataSize_;
    fontData_ = new uint8_t[fontDataSize_];
    std::memcpy(fontData_,other.fontData_,fontDataSize_);
}

GfxBitmapFont::GfxBitmapFont(GfxBitmapFont&& other)
{
    fontWidth_ = other.fontWidth_;
    fontHeight_ = other.fontHeight_;
    fontDataSize_ = other.fontDataSize_;
    fontData_ = other.fontData_;
    // Delete other's data
    other.fontWidth_ = 0;
    other.fontHeight_ = 0;
    other.fontDataSize_ = 0;
    other.fontData_ = nullptr;
}

GfxBitmapFont::~GfxBitmapFont()
{
    if (fontData_ != nullptr)
    {
        delete[] fontData_;
    }
}

GfxBitmapFont& GfxBitmapFont::operator=(const GfxBitmapFont& other)
{
    if (this != &other)
    {
        fontWidth_ = other.fontWidth_;
        fontHeight_ = other.fontHeight_;
        if (fontData_ != nullptr)
        {
            delete[] fontData_;
        }
        fontDataSize_ = other.fontDataSize_;
        fontData_ = new uint8_t[fontDataSize_];
        std::memcpy(fontData_,other.fontData_,fontDataSize_);
    }
    return *this;
}

GfxBitmapFont& GfxBitmapFont::operator=(GfxBitmapFont&& other)
{
    if (this != &other)
    {
        fontWidth_ = other.fontWidth_;
        fontHeight_ = other.fontHeight_;
        fontDataSize_ = other.fontDataSize_;
        fontData_ = other.fontData_;
        // Delete other's data
        other.fontWidth_ = 0;
        other.fontHeight_ = 0;
        other.fontDataSize_ = 0;
        other.fontData_ = nullptr;
    }
    return *this;
}

uint8_t* GfxBitmapFont::getFontData(void) const
{
    return fontData_;
}

uint16_t GfxBitmapFont::getFontDataSize(void) const
{
    return fontDataSize_;
}

uint8_t GfxBitmapFont::getFontWidth(void) const
{
    return fontWidth_;
}

uint8_t GfxBitmapFont::getFontHeight(void) const
{
    return fontHeight_;
}

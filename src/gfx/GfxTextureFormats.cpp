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

#include "GfxTextureFormats.hpp"

namespace gfx
{

const char GfxTextureFormats::ClassName[] = "GfxTextureFormats";

GfxTextureFormats::GfxTextureFormats() noexcept : GfxRootClass(ClassName)
{
    clear();
}

GfxTextureFormats::GfxTextureFormats(const int32_t formatsCount) throw(std::runtime_error) :
        GfxRootClass(ClassName)
{
    clear();
    formatsCount_ = formatsCount;
}

GfxTextureFormats::GfxTextureFormats(const int32_t formatsCount, const uint32_t formats[]) throw(std::runtime_error) :
        GfxRootClass(ClassName)
{
    formatsCount_ = formatsCount;
    for (int32_t index = 0; index < formatsCount_; index++)
    {
        formats_[index] = formats[index];
    }
}

GfxTextureFormats::GfxTextureFormats(GfxTextureFormats const& other) noexcept : GfxRootClass(ClassName)
{
    formatsCount_ = other.formatsCount_;
    for (int32_t index = 0; index < other.formatsCount_; index++)
    {
        formats_[index] = other.formats_[index];
    }
}

GfxTextureFormats::GfxTextureFormats(GfxTextureFormats&& other) noexcept : GfxRootClass(ClassName)
{
    formatsCount_ = other.formatsCount_;
    for (int32_t index = 0; index < other.formatsCount_; index++)
    {
        formats_[index] = other.formats_[index];
    }
    // Delete other's data
    other.clear();
}

GfxTextureFormats& GfxTextureFormats::operator=(GfxTextureFormats const& other) noexcept
{
    if (this != &other)
    {
        formatsCount_ = other.formatsCount_;
        for (int32_t index = 0; index < other.formatsCount_; index++)
        {
            formats_[index] = other.formats_[index];
        }
    }
    return *this;
}

GfxTextureFormats& GfxTextureFormats::operator=(GfxTextureFormats&& other) noexcept
{
    if (this != &other)
    {
        formatsCount_ = other.formatsCount_;
        for (int32_t index = 0; index < other.formatsCount_; index++)
        {
            formats_[index] = other.formats_[index];
        }
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextureFormats::operator bool() const noexcept
{
    return true;
}

void GfxTextureFormats::setCount(const int32_t formatsCount) throw(std::runtime_error)
{
    if ((formatsCount <= 0) || (formatsCount > kTextureFormatsArrayLength))
    {
        throw std::runtime_error("Count out of bounds");
    }
    formatsCount_ = formatsCount;
}

void GfxTextureFormats::setFormat(const int32_t formatIndex, const uint32_t formatValue) throw(std::runtime_error)
{
    if ((formatIndex < 0) || (formatIndex >= formatsCount_))
    {
        throw std::runtime_error("Index of ouf bounds");
    }
    formats_[formatIndex] = formatValue;
}

void GfxTextureFormats::setAllFormats(const uint32_t formats[]) noexcept
{
    formatsCount_ = kTextureFormatsArrayLength;
    for (int32_t index = 0; index < kTextureFormatsArrayLength; index++)
    {
        formats_[index] = formats[index];
    }
}

int32_t GfxTextureFormats::getMaxFormatsCount(void) const noexcept
{
    return kTextureFormatsArrayLength;
}

int32_t GfxTextureFormats::getFormatsCount(void) const noexcept
{
    return formatsCount_;
}

uint32_t& GfxTextureFormats::operator[](const int32_t formatIndex) throw(std::runtime_error)
{
    if ((formatIndex < 0) || (formatIndex >= kTextureFormatsArrayLength))
    {
        throw std::runtime_error("Index out of bounds");
    }
    return formats_[formatIndex];
}

uint32_t const& GfxTextureFormats::operator[](const int32_t formatIndex) const throw(std::runtime_error)
{
    if ((formatIndex < 0) || (formatIndex >= kTextureFormatsArrayLength))
    {
        throw std::runtime_error("Index out of bounds");
    }
    return formats_[formatIndex];
}

void GfxTextureFormats::clear(void) noexcept
{
    formatsCount_ = -1;
    std::memset(reinterpret_cast<void *>(&formats_[0]), 0, sizeof(formats_));
}

}  // namespace gfx

/* EOF */


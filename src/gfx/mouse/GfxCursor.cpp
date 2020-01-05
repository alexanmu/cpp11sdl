/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#include <stdexcept>
#include <cassert>
#include <string>
#include <utility>

#include "GfxCursor.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcursor::mouse::gfx");

namespace gfx
{

namespace mouse
{

const char GfxCursor::ClassName[] = "GfxCursor";

GfxCursor::GfxCursor() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxCursor::GfxCursor(const SdlTypePtr cursor) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(cursor != nullptr);

    cursor_ = cursor;
}

GfxCursor::GfxCursor(const uint8_t * data, const uint8_t * mask, const int32_t w, const int32_t h,
                     const int32_t hot_x, const int32_t hot_y) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(data != nullptr);
    assert(mask != nullptr);
    assert(w > 0);
    assert(h > 0);
    assert((hot_x >= 0) && (hot_x < w));
    assert((hot_y >= 0) && (hot_y < h));

    SdlTypePtr tmpcursor;

    tmpcursor = SDL_CreateCursor(data, mask, w, h, hot_x, hot_y);
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

GfxCursor::GfxCursor(const surface::GfxSurface& surface, const int32_t hot_x,
                     const int32_t hot_y) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(surface);
    assert((hot_x >= 0) && (hot_x < surface.getWidth()));
    assert((hot_y >= 0) && (hot_y < surface.getHeight()));

    SdlTypePtr tmpcursor;

    tmpcursor = SDL_CreateColorCursor(surface.getAsSdlTypePtr(), hot_x, hot_y);
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

GfxCursor::GfxCursor(const GfxSystemCursor& id) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(id);

    SdlTypePtr tmpcursor;

    tmpcursor = SDL_CreateSystemCursor(id.getAsSdlType());
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

GfxCursor::GfxCursor(GfxCursor&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    cursor_ = other.cursor_;
    // Delete other's data
    other.clear();
}

GfxCursor& GfxCursor::operator=(GfxCursor&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        cursor_ = other.cursor_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxCursor::~GfxCursor() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (cursor_ != nullptr)
    {
        SDL_FreeCursor(cursor_);
    }
    cursor_ = nullptr;
}

GfxCursor::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxCursor::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxCursor::createCursor(const SdlTypePtr cursor) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(cursor != nullptr);

    if (cursor_ != nullptr)
    {
        throw std::runtime_error("Cursor already created");
    }
    cursor_ = cursor;
}

void GfxCursor::createCursor(const uint8_t * data, const uint8_t * mask, const int32_t w, const int32_t h,
                             const int32_t hot_x, const int32_t hot_y) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(data != nullptr);
    assert(mask != nullptr);
    assert(w > 0);
    assert(h > 0);
    assert((hot_x >= 0) && (hot_x < w));
    assert((hot_y >= 0) && (hot_y < h));

    SdlTypePtr tmpcursor;

    if (cursor_ != nullptr)
    {
        throw std::runtime_error("Cursor already created");
    }
    tmpcursor = SDL_CreateCursor(data, mask, w, h, hot_x, hot_y);
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

void GfxCursor::createCursor(const surface::GfxSurface& surface, const int32_t hot_x,
                             const int32_t hot_y) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(surface);
    assert((hot_x >= 0) && (hot_x < surface.getWidth()));
    assert((hot_y >= 0) && (hot_y < surface.getHeight()));

    SdlTypePtr tmpcursor;

    if (cursor_ != nullptr)
    {
        throw std::runtime_error("Cursor already created");
    }
    tmpcursor = SDL_CreateColorCursor(surface.getAsSdlTypePtr(), hot_x, hot_y);
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

void GfxCursor::createCursor(const GfxSystemCursor& id) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(id);

    SdlTypePtr tmpcursor;

    if (cursor_ != nullptr)
    {
        throw std::runtime_error("Cursor already created");
    }
    tmpcursor = SDL_CreateSystemCursor(id.getAsSdlType());
    if (tmpcursor == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create cursor (" + sdlErr +")");
    }
    cursor_ = tmpcursor;
}

void GfxCursor::setCursor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (cursor_ != nullptr)
    {
        SDL_SetCursor(cursor_);
    }
}

GfxCursor::SdlTypePtr GfxCursor::getCursor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SdlTypePtr tmpcursor = nullptr;

    if (cursor_ != nullptr)
    {
        tmpcursor = SDL_GetCursor();
    }
    return tmpcursor;
}

GfxCursor::SdlTypePtr GfxCursor::getDefaultCursor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SdlTypePtr tmpcursor = nullptr;

    if (cursor_ != nullptr)
    {
        tmpcursor = SDL_GetDefaultCursor();
    }
    return tmpcursor;
}

void GfxCursor::freeCursor(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (cursor_ != nullptr)
    {
        SDL_FreeCursor(cursor_);
        cursor_ = nullptr;
    }
}

int32_t GfxCursor::showCursor(const int32_t toggle) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((toggle == -1) || (toggle == 0) || (toggle == 1));

    int32_t ret = -1;

    if (cursor_ != nullptr)
    {
        ret = SDL_ShowCursor(toggle);
        assert((ret == 1) || (ret == 0));
    }
    return ret;
}

void GfxCursor::showCursor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    (void)SDL_ShowCursor(1);
}

void GfxCursor::hideCursor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    (void)SDL_ShowCursor(0);
}

GfxBool GfxCursor::isVisible(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret;

    ret = SDL_ShowCursor(-1);
    if (ret == 1)
    {
        return GfxBool(true);
    }
    return GfxBool(false);
}

void GfxCursor::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = nullptr;
}

GfxCursor::SdlTypePtr GfxCursor::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return cursor_;
}

}  // namespace mouse

}  // namespace gfx

/* EOF */

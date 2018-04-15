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

#include <cassert>
#include <cstdint>
#include <map>
#include <string>
#include <utility>

#include "GfxVideo.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxvideo::video::gfx");

namespace gfx
{

namespace video
{

const char GfxVideo::ClassName[] = "GfxVideo";

GfxVideo::GfxVideo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxVideo::GfxVideo(GfxVideo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    numvideodrivers_ = other.numvideodrivers_;
    numvideodisplays_ = other.numvideodisplays_;
    numdisplaymodes_ = std::move(other.numdisplaymodes_);
    // Delete other's data
    other.clear();
}

GfxVideo& GfxVideo::operator=(GfxVideo&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        numvideodrivers_ = other.numvideodrivers_;
        numvideodisplays_ = other.numvideodisplays_;
        numdisplaymodes_ = std::move(other.numdisplaymodes_);
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxVideo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxVideo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxVideo::videoInit(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Use GfxInitQuit.hpp");
}

void GfxVideo::videoQuit(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Use GfxInitQuit.hpp");
}

int32_t GfxVideo::getNumVideoDrivers(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    numvideodrivers_ = SDL_GetNumVideoDrivers();
    return numvideodrivers_;
}

const std::string GfxVideo::getVideoDriver(const int32_t driverindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(driverindex >= 0);

    std::string str = "";

    if ((numvideodrivers_ >= 0) && (driverindex < numvideodrivers_))
    {
        str = SDL_GetVideoDriver(driverindex);
    }
    return str;
}

const std::string GfxVideo::getCurrentVideoDriver(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * c;
    std::string str = "Not initialized";

    c = reinterpret_cast<const char *>(SDL_GetCurrentVideoDriver());
    if (c != NULL)
    {
        str = c;
    }
    return str;
}

int32_t GfxVideo::getNumVideoDisplays(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    numvideodisplays_ = SDL_GetNumVideoDisplays();
    return numvideodisplays_;
}

const std::string GfxVideo::getDisplayName(const int32_t displayindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    std::string str = "";

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        str = SDL_GetDisplayName(displayindex);
    }
    return str;
}

const rect::GfxRect GfxVideo::getDisplayBounds(const int32_t displayindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    rect::GfxRect::SdlType rt;
    int32_t ret = 1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        ret = SDL_GetDisplayBounds(displayindex, &rt);
        assert(ret == 0);
        return rect::GfxRect(rt);
    }
    return rect::GfxRect();
}

const rect::GfxRect GfxVideo::getDisplayUsableBounds(const int32_t displayindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    rect::GfxRect::SdlType rt;
    int32_t ret = 1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        ret = SDL_GetDisplayUsableBounds(displayindex, &rt);
        assert(ret == 0);
        return rect::GfxRect(rt);
    }
    return rect::GfxRect();
}

void GfxVideo::getDisplayDPI(const int32_t displayindex, float * ddpi, float * hdpi, float * vdpi) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);
    assert(ddpi != nullptr);
    assert(hdpi != nullptr);
    assert(vdpi != nullptr);

    int32_t ret = 1;

    *ddpi = 0.0f;
    *hdpi = 0.0f;
    *vdpi = 0.0f;
    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        ret = SDL_GetDisplayDPI(displayindex, ddpi, hdpi, vdpi);
        // assert(ret == 0); Fails if DPI information is not available!
        assert(ret == ret);
    }
}

int32_t GfxVideo::getNumDisplayModes(const int32_t displayindex) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    int32_t numdisplaymodes = -1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        numdisplaymodes = SDL_GetNumDisplayModes(displayindex);
        if (numdisplaymodes >= 1)
        {
            numdisplaymodes_[displayindex] = numdisplaymodes;
        }
        else
        {
            // Error occured
        }
    }
    return numdisplaymodes;
}

const GfxDisplayMode GfxVideo::getDisplayMode(const int32_t displayindex, const int32_t modeindex) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);
    assert(modeindex >= 0);

    int32_t mcount;
    GfxDisplayMode::SdlType dms;
    int32_t ret = 1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        try
        {
            mcount = numdisplaymodes_.at(displayindex);
        }
        catch(std::out_of_range& e)
        {
            mcount = -1;
        }
        if ((mcount >= 0) && (modeindex < mcount))
        {
            ret = SDL_GetDisplayMode(displayindex, modeindex, &dms);
            assert(ret == 0);
            return GfxDisplayMode(dms);
        }
    }
    return GfxDisplayMode();
}

const GfxDisplayMode GfxVideo::getDesktopDisplayMode(const int32_t displayindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    GfxDisplayMode::SdlType dms;
    int32_t ret = 1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        ret = SDL_GetDesktopDisplayMode(displayindex, &dms);
        assert(ret == 0);
        return GfxDisplayMode(dms);
    }
    return GfxDisplayMode();
}

const GfxDisplayMode GfxVideo::getCurrentDisplayMode(const int32_t displayindex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);

    GfxDisplayMode::SdlType dms;
    int32_t ret = 1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        ret = SDL_GetCurrentDisplayMode(displayindex, &dms);
        assert(ret == 0);
        return GfxDisplayMode(dms);
    }
    return GfxDisplayMode();
}

const GfxDisplayMode GfxVideo::getClosestDisplayMode(const int32_t displayindex,
                                                     GfxDisplayMode const& mode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(displayindex >= 0);
    assert(mode);

    GfxDisplayMode::SdlType dms;
    GfxDisplayMode::SdlTypePtr dmsptr;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        dmsptr = SDL_GetClosestDisplayMode(displayindex, mode.getAsSdlTypePtr(), &dms);
        if (dmsptr == &dms)
        {
            return GfxDisplayMode(dms);
        }
    }
    return GfxDisplayMode();
}

// Private methods
void GfxVideo::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    numvideodrivers_ = -1;
    numvideodisplays_ = -1;
    numdisplaymodes_.clear();
}

}  // namespace video

}  // namespace gfx

/* EOF */

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

#include <memory>
#include <map>
#include <string>

#include "GfxVideo.hpp"

namespace gfx
{

const char GfxVideo::ClassName[] = "GfxVideo";

GfxVideo::GfxVideo() : GfxRootClass(ClassName)
{
    numvideodrivers_ = -1;
    numvideodisplays_ = -1;
    numdisplaymodes_.clear();
}

void GfxVideo::videoInit(void) throw()
{
    throw;
}

void GfxVideo::videoQuit(void) throw()
{
    throw;
}

int GfxVideo::getNumVideoDrivers(void)
{
    numvideodrivers_ = sdl2::SDL_GetNumVideoDrivers();
    return numvideodrivers_;
}

std::string GfxVideo::getVideoDriver(const int driverindex) const
{
     std::string str = "";

    if ((numvideodrivers_ >= 0) && (driverindex < numvideodrivers_))
    {
        str = sdl2::SDL_GetVideoDriver(driverindex);
    }
    return str;
}

std::string GfxVideo::getCurrentVideoDriver(void) const
{
    const char * c;
    std::string str = "Not initialized";

    c = reinterpret_cast<const char *>(sdl2::SDL_GetCurrentVideoDriver());
    if (c != NULL)
    {
        str = c;
    }
    return str;
}

int GfxVideo::getNumVideoDisplays(void)
{
    numvideodisplays_ = sdl2::SDL_GetNumVideoDisplays();
    return numvideodisplays_;
}

std::string GfxVideo::getDisplayName(const int displayindex) const
{
    std::string str = "";

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        str = sdl2::SDL_GetDisplayName(displayindex);
    }
    return str;
}

std::unique_ptr<GfxRect> GfxVideo::getDisplayBounds(const int displayindex) const
{
    std::unique_ptr<GfxRect> r { new GfxRect() };
    GfxRect::SdlType rt;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        (void)SDL_GetDisplayBounds(displayindex, &rt);
        r.get()->set(rt);
    }
    return r;
}

std::unique_ptr<GfxRect> GfxVideo::getDisplayUsableBounds(const int displayindex) const
{
    std::unique_ptr<GfxRect> r { new GfxRect() };
    GfxRect::SdlType rt;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        (void)SDL_GetDisplayUsableBounds(displayindex, &rt);
        r.get()->set(rt);
    }
    return r;
}

void GfxVideo::getDisplayDPI(const int displayindex, float * ddpi, float * hdpi, float * vdpi) const
{
    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        sdl2::SDL_GetDisplayDPI(displayindex, ddpi, hdpi, vdpi);
    }
}

int GfxVideo::getNumDisplayModes(const int displayindex)
{
    int numdisplaymodes = -1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        numdisplaymodes = sdl2::SDL_GetNumDisplayModes(displayindex);
        numdisplaymodes_[displayindex] = numdisplaymodes;
    }
    return numdisplaymodes;
}

std::unique_ptr<GfxDisplayMode> GfxVideo::getDisplayMode(const int displayindex, const int modeindex)
{
    int mcount;
    std::unique_ptr<GfxDisplayMode> dm { new GfxDisplayMode() };
    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        try
        {
            mcount = numdisplaymodes_.at(displayindex);
        }
        catch(std::out_of_range e)
        {
            mcount = -1;
        }
        if ((mcount >= 0) && (modeindex < mcount))
        {
            SDL_GetDisplayMode(displayindex, modeindex, &dms);
            dm.get()->set(dms);
        }
    }
    return dm;
}

std::unique_ptr<GfxDisplayMode> GfxVideo::getDesktopDisplayMode(const int displayindex) const
{
    std::unique_ptr<GfxDisplayMode> dm { new GfxDisplayMode() };
    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        SDL_GetDesktopDisplayMode(displayindex, &dms);
        dm.get()->set(dms);
    }
    return dm;
}

std::unique_ptr<GfxDisplayMode> GfxVideo::getCurrentDisplayMode(const int displayindex) const
{
    std::unique_ptr<GfxDisplayMode> dm { new GfxDisplayMode() };
    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        SDL_GetCurrentDisplayMode(displayindex, &dms);
        dm.get()->set(dms);
    }
    return dm;
}

std::unique_ptr<GfxDisplayMode> GfxVideo::getClosestDisplayMode(const int displayindex,
                                                                GfxDisplayMode const& mode) const
{
    std::unique_ptr<GfxDisplayMode> dm { new GfxDisplayMode() };
    GfxDisplayMode::SdlType dms;
    GfxDisplayMode::SdlTypePtr dmsptr;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        dmsptr = SDL_GetClosestDisplayMode(displayindex, mode.getAsSdlTypePtr(), &dms);
        if (dmsptr == &dms)
        {
            dm.get()->set(dms);
        }
    }
    return dm;
}

}  // namespace gfx

/* EOF */

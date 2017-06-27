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

#ifndef GfxVideo_hpp
#define GfxVideo_hpp

#include <stdexcept>
#include <cstdint>
#include <map>
#include <string>

#include "GfxObject.hpp"
#include "GfxRect.hpp"
#include "GfxDisplayMode.hpp"

namespace gfx
{

namespace video
{

class GfxVideo final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxVideo() noexcept;

    GfxVideo(GfxVideo const&) = delete;
    GfxVideo(GfxVideo&& other) noexcept;

    GfxVideo& operator=(GfxVideo const&) = delete;
    GfxVideo& operator=(GfxVideo&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    void videoInit(void) throw(std::runtime_error);
    void videoQuit(void) throw(std::runtime_error);

    int32_t getNumVideoDrivers(void) noexcept;
    std::string getVideoDriver(const int32_t driverindex) const noexcept;
    std::string getCurrentVideoDriver(void) const noexcept;
    int32_t getNumVideoDisplays(void) noexcept;
    std::string getDisplayName(const int32_t displayindex) const noexcept;
    rect::GfxRect getDisplayBounds(const int32_t displayindex) const noexcept;
    rect::GfxRect getDisplayUsableBounds(const int32_t displayindex) const noexcept;
    void getDisplayDPI(const int32_t displayindex, float * ddpi, float * hdpi, float * vdpi) const noexcept;
    int32_t getNumDisplayModes(const int32_t displayindex) noexcept;
    GfxDisplayMode getDisplayMode(const int32_t displayindex, const int32_t modeindex) noexcept;
    GfxDisplayMode getDesktopDisplayMode(const int32_t displayindex) const noexcept;
    GfxDisplayMode getCurrentDisplayMode(const int32_t displayindex) const noexcept;
    GfxDisplayMode getClosestDisplayMode(const int32_t displayindex,
                                         GfxDisplayMode const& mode) const noexcept;

private:
    void clear(void) noexcept;

    int32_t numvideodrivers_;
    int32_t numvideodisplays_;
    std::map<int32_t, int32_t> numdisplaymodes_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxVideo_hpp */

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
#include <memory>
#include <map>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxRect.hpp"
#include "GfxDisplayMode.hpp"

namespace gfx
{

namespace video
{

class GfxVideo final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxVideo();

    GfxVideo(GfxVideo const&) = delete;
    GfxVideo(GfxVideo&&) = delete;

    GfxVideo& operator=(GfxVideo const&) = delete;
    GfxVideo& operator=(GfxVideo&&) = delete;

    virtual explicit operator bool() const;

    void videoInit(void) throw(std::runtime_error);
    void videoQuit(void) throw(std::runtime_error);

    int32_t getNumVideoDrivers(void);
    std::string getVideoDriver(const int32_t driverindex) const;
    std::string getCurrentVideoDriver(void) const;
    int32_t getNumVideoDisplays(void);
    std::string getDisplayName(const int32_t displayindex) const;
    std::unique_ptr<rect::GfxRect> getDisplayBounds(const int32_t displayindex) const;
    std::unique_ptr<rect::GfxRect> getDisplayUsableBounds(const int32_t displayindex) const;
    void getDisplayDPI(const int32_t displayindex, float * ddpi, float * hdpi, float * vdpi) const;
    int32_t getNumDisplayModes(const int32_t displayindex);
    std::unique_ptr<GfxDisplayMode> getDisplayMode(const int32_t displayindex, const int32_t modeindex);
    std::unique_ptr<GfxDisplayMode> getDesktopDisplayMode(const int32_t displayindex) const;
    std::unique_ptr<GfxDisplayMode> getCurrentDisplayMode(const int32_t displayindex) const;
    std::unique_ptr<GfxDisplayMode> getClosestDisplayMode(const int32_t displayindex,
                                                            GfxDisplayMode const& mode) const;
private:
    int32_t numvideodrivers_;
    int32_t numvideodisplays_;
    std::map<int32_t, int32_t> numdisplaymodes_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxVideo_hpp */

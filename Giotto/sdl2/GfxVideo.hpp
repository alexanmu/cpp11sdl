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

#include <memory>
#include <map>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxRect.hpp"
#include "GfxDisplayMode.hpp"

namespace gfx
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

    void videoInit(void) throw();
    void videoQuit(void) throw();

    int getNumVideoDrivers(void);
    std::string getVideoDriver(const int driverindex) const;
    std::string getCurrentVideoDriver(void) const;
    int getNumVideoDisplays(void);
    std::string getDisplayName(const int displayindex) const;
    std::unique_ptr<GfxRect> getDisplayBounds(const int displayindex) const;
    std::unique_ptr<GfxRect> getDisplayUsableBounds(const int displayindex) const;
    void getDisplayDPI(const int displayindex, float * ddpi, float * hdpi, float * vdpi) const;
    int getNumDisplayModes(const int displayindex);
    std::unique_ptr<GfxDisplayMode> getDisplayMode(const int displayindex, const int modeindex);
    std::unique_ptr<GfxDisplayMode> getDesktopDisplayMode(const int displayindex) const;
    std::unique_ptr<GfxDisplayMode> getCurrentDisplayMode(const int displayindex) const;
    std::unique_ptr<GfxDisplayMode> getClosestDisplayMode(const int displayindex, GfxDisplayMode const& mode) const;
private:
    int numvideodrivers_;
    int numvideodisplays_;
    std::map<int, int> numdisplaymodes_;
};

}  // namespace gfx

#endif /* GfxVideo_hpp */

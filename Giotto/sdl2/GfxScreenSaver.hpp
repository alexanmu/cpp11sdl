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

#ifndef GfxScreenSaver_hpp
#define GfxScreenSaver_hpp

#include <string>

#include "GfxRootClass.hpp"

class GfxScreenSaver final : public GfxRootClass
{
public:
    static const std::string ClassName;

    GfxScreenSaver();

    GfxScreenSaver(GfxScreenSaver const&) = delete;
    GfxScreenSaver(GfxScreenSaver&&) = delete;

    GfxScreenSaver& operator=(GfxScreenSaver const&) = delete;
    GfxScreenSaver& operator=(GfxScreenSaver&&) = delete;

    bool isScreenSaverEnabled(void) const;
    void enableScreenSaver(void);
    void disableScreenSaver(void);
private:
    enum class ScreenSaverStatus : bool
    {
        statusEnabled = true,
        statusDisabled = false
    };

    ScreenSaverStatus ssstatus_;
};

#endif /* GfxScreenSaver_hpp */

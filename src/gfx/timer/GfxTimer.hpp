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

#ifndef GfxTimer_hpp
#define GfxTimer_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <map>

#include "GfxObject.hpp"
#include "GfxBool.hpp"
#include "GfxTimerID.hpp"
#include "GfxTimerCallback.hpp"

namespace gfx
{

namespace timer
{

class GfxTimer final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxTimer() noexcept;

    GfxTimer(GfxTimer const&) = delete;
    GfxTimer(GfxTimer&& other) noexcept;

    GfxTimer& operator=(GfxTimer const&) = delete;
    GfxTimer& operator=(GfxTimer&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    uint32_t getTicks(void) const noexcept;
    int32_t ticksPassed(const uint32_t a, const uint32_t b) const noexcept;

    uint64_t getPerformanceCounter(void) const noexcept;
    uint64_t getPerformanceFrequency(void) const noexcept;
    void delay_(const uint32_t ms) const noexcept;

    GfxTimerID addTimer(uint32_t interval, GfxTimerCallback const& callback) noexcept;
    GfxBool removeTimer(GfxTimerID const& id) throw(std::runtime_error);

    void clear(void) noexcept;

    static void delay(const uint32_t ms) noexcept;
private:
    // Will be called from C by SDL
    static uint32_t timerCallbackFunction(uint32_t interval, void * userdata);

    std::map<GfxTimerID::SdlType, GfxTimerCallback *> callbackMap_;
};

}  // namespace timer

}  // namespace gfx

#endif /* GfxTimer_hpp */

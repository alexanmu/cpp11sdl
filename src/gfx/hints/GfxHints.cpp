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
#include <string>
#include <map>
#include <utility>

#include "GfxHints.hpp"

namespace gfx
{
namespace hints
{

namespace prv
{

std::map<std::string, std::pair<GfxHintCallback *, void *>> * callbackMapPtr = nullptr;

extern "C" {
void hintCallbackFunction(void * userdata, const char * name, const char * oldv, const char * newv)
{
    std::pair<GfxHintCallback *, void *> inmap;
    GfxHintCallback * gfxhcb;

    if (callbackMapPtr != nullptr)
    {
        if (callbackMapPtr->size() > 0)
        {
            auto pos = callbackMapPtr->find(std::string(name));
            if (pos != callbackMapPtr->end())
            {
                inmap = callbackMapPtr->operator[](std::string(name));
                gfxhcb = inmap.first;
                (*gfxhcb)(userdata, std::string(name), std::string(oldv), std::string(newv));
            }
        }
    }
}
}  // extern "C"
}  // namespace prv

const char GfxHints::ClassName[] = "GfxHints";

GfxHints::GfxHints() noexcept : GfxObject(ClassName)
{
    callbackMap_.clear();
}

GfxHints::operator bool() const noexcept
{
    return true;
}

GfxBool GfxHints::setHintWithPriority(std::string const& name, std::string const& value,
                                     GfxHintPriority const& prio) const noexcept
{
    assert(name.length() > 0);
    assert(value.length() > 0);
    assert(prio);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_SetHintWithPriority(name.c_str(), value.c_str(), prio.getAsSdlType());
    return GfxBool(sdlbool);
}

GfxBool GfxHints::setHint(std::string const& name, std::string const& value) const noexcept
{
    assert(name.length() > 0);
    assert(value.length() > 0);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_SetHint(name.c_str(), value.c_str());
    return GfxBool(sdlbool);
}

std::string GfxHints::getHint(std::string const& name) const noexcept
{
    assert(name.length() > 0);

    const char * ret;

    ret = sdl2::SDL_GetHint(name.c_str());
    if (ret != NULL)
    {
        return std::string(ret);
    }
    return "";
}

GfxBool GfxHints::getHintBoolean(std::string const& name, GfxBool const& defvalue) const noexcept
{
    assert(name.length() > 0);
    assert(defvalue);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_GetHintBoolean(name.c_str(), defvalue.getAsSdlType());
    return GfxBool(sdlbool);
}

void GfxHints::addHintCallback(std::string const& name, GfxHintCallback const& callback, void * userdata) noexcept
{
    assert(name.length() > 0);
    assert(callback);
    assert(userdata != nullptr);

    prv::callbackMapPtr = &callbackMap_;
    callbackMap_[name] = std::make_pair(const_cast<GfxHintCallback *>(&callback), userdata);
    sdl2::SDL_AddHintCallback(name.c_str(), prv::hintCallbackFunction, userdata);
}

void GfxHints::delHintCallback(std::string const& name, GfxHintCallback const& callback,
                                void * userdata) throw(std::runtime_error)
{
    assert(name.length() > 0);
    assert(callback);
    assert(userdata != nullptr);

    std::pair<GfxHintCallback *, void *> params;
    std::pair<GfxHintCallback *, void *> inmap;

    prv::callbackMapPtr = &callbackMap_;
    params = std::make_pair(const_cast<GfxHintCallback *>(&callback), userdata);
    if (callbackMap_.size() > 0)
    {
        auto pos = callbackMap_.find(name);
        if (pos != callbackMap_.end())
        {
            inmap = callbackMap_[name];
            if (params == inmap)
            {
                callbackMap_.erase(pos);
                sdl2::SDL_DelHintCallback(name.c_str(), prv::hintCallbackFunction, userdata);
            }
            else
            {
                throw std::runtime_error("Callback and userdata do not match");
            }
        }
        else
        {
            throw std::runtime_error("Callback not found");
        }
    }
    else
    {
        throw std::runtime_error("No callback set");
    }
}

void GfxHints::clearHints(void) const noexcept
{
    sdl2::SDL_ClearHints();
}

}  // namespace hints

}  // namespace gfx

/* EOF */

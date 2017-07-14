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

#include <stdexcept>
#include <cassert>
#include <string>
#include <utility>

#include "GfxLoadSo.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxloadso::loadso::gfx");

namespace gfx
{

namespace loadso
{

const char GfxLoadSo::ClassName[] = "GfxLoadSo";

GfxLoadSo::GfxLoadSo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    objectName_.clear();
    handle_ = nullptr;
}

GfxLoadSo::GfxLoadSo(std::string const& objectName) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(objectName.length() > 0);

    objectName_ = objectName;
    handle_ = sdl2::SDL_LoadObject(objectName_.c_str());
}

GfxLoadSo::GfxLoadSo(GfxLoadSo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    objectName_ = other.objectName_;
    handle_ = other.handle_;
    // Delete other's data
    other.objectName_ = "";
    other.handle_ = nullptr;
}

GfxLoadSo::~GfxLoadSo() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if (handle_ != nullptr)
    {
        sdl2::SDL_UnloadObject(handle_);
    }
    handle_ = nullptr;
}

GfxLoadSo& GfxLoadSo::operator=(GfxLoadSo&& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Free own resource
        if (handle_ != nullptr)
        {
            unloadObject();
        }
        // Copy other's data
        objectName_ = other.objectName_;
        handle_ = other.handle_;
        // Delete other's data
        other.objectName_ = "";
        other.handle_ = nullptr;
    }
    return *this;
}

GfxLoadSo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (handle_ != nullptr);
}

std::string GfxLoadSo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxLoadSo::isObjectLoaded(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (handle_ != nullptr);
}

std::string const& GfxLoadSo::getObjectName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return objectName_;
}

void * GfxLoadSo::loadFunction(std::string const& function) const noexcept
{
    LOG_TRACE_PRIO_HIGH();

    assert(function.length() > 0);

    void * func = nullptr;

    if (handle_ != nullptr)
    {
        func = sdl2::SDL_LoadFunction(handle_, function.c_str());
    }
    return func;
}

void GfxLoadSo::loadObject(std::string const& objectName) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    assert(objectName.length() > 0);

    if (handle_ != nullptr)
    {
        unloadObject();
    }
    objectName_ = objectName;
    handle_ = sdl2::SDL_LoadObject(objectName_.c_str());
}

void GfxLoadSo::unloadObject() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    sdl2::SDL_UnloadObject(handle_);
    handle_ = nullptr;
}

}  // namespace loadso

}  // namespace gfx

/* EOF */

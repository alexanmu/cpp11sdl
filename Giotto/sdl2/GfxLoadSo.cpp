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

#include <string>

#include "GfxLoadSo.hpp"
#include "GfxSdlHeader.hpp"

const std::string GfxLoadSo::ClassName = "GfxLoadSo";

GfxLoadSo::GfxLoadSo(const std::string& objectname) : GfxRootClass(ClassName)
{
    objectname_ = objectname;
    handle_ = sdl2::SDL_LoadObject(objectname_.c_str());
}

GfxLoadSo::GfxLoadSo(GfxLoadSo&& other) : GfxRootClass(ClassName)
{
    objectname_ = other.objectname_;
    handle_ = other.handle_;
    // Delete other's data
    other.objectname_ = "";
    other.handle_ = nullptr;
}

GfxLoadSo::~GfxLoadSo()
{
    if (handle_ != nullptr)
    {
        sdl2::SDL_UnloadObject(handle_);
    }
}

GfxLoadSo& GfxLoadSo::operator=(GfxLoadSo&& other)
{
    if (this != &other)
    {
        objectname_ = other.objectname_;
        handle_ = other.handle_;
        // Delete other's data
        other.objectname_ = "";
        other.handle_ = nullptr;
    }
    return *this;
}

bool GfxLoadSo::isObjectLoaded(void) const
{
    return (handle_ != nullptr);
}

std::string GfxLoadSo::getObjectName(void) const
{
    return objectname_;
}

void * GfxLoadSo::loadFunction(const std::string& function)
{
    void * func = nullptr;

    if (handle_ != nullptr)
    {
        func = sdl2::SDL_LoadFunction(handle_,function.c_str());
    }
    return func;
}

void GfxLoadSo::unloadObject()
{
    sdl2::SDL_UnloadObject(handle_);
    handle_ = nullptr;
}

/* EOF */

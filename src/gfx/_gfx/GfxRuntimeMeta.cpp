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
#include <cstring>
#include <string>
#include <ostream>

#include "prettyprint.hpp"

#include "GfxRuntimeMeta.hpp"

namespace gfx
{

namespace _gfx
{

inline std::ostream& operator<<(std::ostream& outstream, const GfxRuntimeMeta::ClassInfo& cinfo)
{
    assert(cinfo.objectInstanceCount_ >= 0);

    outstream << "(m:" << cinfo.maxObjectInstanceCount_;
    if (cinfo.objectInstanceCount_ > 0)
    {
        outstream << ",i:" << cinfo.objectInstanceCount_;
    }
    outstream << ",f:" << cinfo.firstInstanceId_ << ",l:" << cinfo.lastInstanceId_ << ")";
    return outstream;
}

bool GfxRuntimeMeta::runtimeMetaActive = true;

GfxRuntimeMeta& GfxRuntimeMeta::getInstance(void) noexcept
{
    static GfxRuntimeMeta instance_;

    return instance_;
}

const GfxRuntimeMeta::ClassInfo& GfxRuntimeMeta::getClassInfo(const int32_t index) noexcept
{
    assert(classUMap.size() > 0);

    int32_t ctr = 0;

    clear();
    for (auto it : classUMap)
    {
        if (ctr == index)
        {
            classInfo_ = it.second;
            break;
        }
        ctr += 1;
    }
    return classInfo_;
}

const std::string GfxRuntimeMeta::getClassName(const int32_t index) noexcept
{
    assert(classUMap.size() > 0);

    int32_t ctr = 0;
    std::string ret;

    for (auto it : classUMap)
    {
        if (ctr == index)
        {
            ret = it.first;
            break;
        }
        ctr += 1;
    }
    return ret;
}

int32_t GfxRuntimeMeta::getClassCount(void) const noexcept
{
    return static_cast<int32_t>(classUMap.size());
}

void GfxRuntimeMeta::constructObject(const char * className, const int32_t instanceId) noexcept
{
    /* Disable RuntimeMeta feature */
    if (GfxRuntimeMeta::runtimeMetaActive == false)
    {
        return;
    }

    assert(className != nullptr);
    assert(instanceId > 0);

    auto find_it = classUMap.find(className);
    if (find_it == classUMap.end())
    {
        ClassInfo cinfo;

        cinfo.objectInstanceCount_ = 1;
        cinfo.maxObjectInstanceCount_ = 1;
        cinfo.firstInstanceId_ = instanceId;
        cinfo.lastInstanceId_ = -1;
        classUMap[className] = cinfo;
    }
    else
    {
        find_it->second.objectInstanceCount_ += 1;
        find_it->second.maxObjectInstanceCount_ += 1;
        find_it->second.lastInstanceId_ = instanceId;
    }
}

void GfxRuntimeMeta::destructObject(const char * className, const int32_t instanceId) noexcept
{
    /* Disable RuntimeMeta feature */
    if (GfxRuntimeMeta::runtimeMetaActive == false)
    {
        return;
    }

    assert(className != nullptr);
    assert((instanceId > 0) || ((instanceId == -1) && (std::strcmp(className, "$null$") == 0)));

    auto find_it = classUMap.find(className);
    if (find_it != classUMap.end())
    {
        find_it->second.objectInstanceCount_ -= 1;
        find_it->second.lastInstanceId_ = instanceId;
    }
}

std::ostream& GfxRuntimeMeta::printToStream(std::ostream& outstream) const noexcept
{
    outstream << classUMap;
    return outstream;
}

void GfxRuntimeMeta::clear_map(void) noexcept
{
    classUMap.clear();
}

// Private methods
GfxRuntimeMeta::GfxRuntimeMeta() noexcept
{
    clear();
    classUMap.clear();
}

GfxRuntimeMeta::~GfxRuntimeMeta() noexcept
{
    // Nothing to do
}

void GfxRuntimeMeta::clear(void) noexcept
{
    classInfo_.objectInstanceCount_ = -1;
    classInfo_.maxObjectInstanceCount_ = -1;
    classInfo_.firstInstanceId_ = -1;
    classInfo_.lastInstanceId_ = -1;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

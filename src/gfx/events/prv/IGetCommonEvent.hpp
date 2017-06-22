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

#ifndef IGetCommonEvent_hpp
#define IGetCommonEvent_hpp

#include <cstdint>

#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"

namespace gfx
{

namespace events
{

namespace prv
{

class IGetCommonEvent
{
public:
    virtual ~IGetCommonEvent() {}

    virtual GfxCommonEvent getCommonEvent(void) const noexcept = 0;
    virtual GfxEventType getEventType(void) const noexcept = 0;
    virtual uint32_t getTimeStamp(void) const noexcept = 0;
};

}  // namespace prv

}  // namespace events

}  // namespace gfx

#endif  /* IGetCommonEvent_hpp */
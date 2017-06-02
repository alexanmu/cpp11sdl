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

#ifndef GTypes_hpp
#define GTypes_hpp

#include <cstdint>

namespace gto
{

namespace gobj
{

enum class GBorderThikness : uint8_t
{
    noBorder = 0,
    thinBorder = 1,
    thikBorder = 2
};

enum class GBackgroundStyle : uint8_t
{
    transparentColor = 0,
    solidColor = 1
};

enum class GBorderStyle : uint8_t
{
    flatBorder = 0,
    raised3DBorder = 1,
    sunken3DBorder = 2
};

enum class GImageScaleMode : uint8_t
{
    centerScaled = 0,
    strechScaled = 1,
    tileScaled = 2
};

enum class GTextRenderMode : uint8_t
{
    solidText = 0,
    shadedText = 1,
    blendedText = 2
};

enum class GStructuredTextType : uint8_t
{
    hexValue = 0,
    emailAddress = 1,
    hyperLink = 2,
    ipAddress = 3,
    customRegex = 4
};

extern const uint16_t kMaxObjectWidth;
extern const uint16_t kMaxObjectHeight;

}  // namespace gobj

}  // namespace gto

#endif /* GTypes_hpp */

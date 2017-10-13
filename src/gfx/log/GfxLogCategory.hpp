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

#ifndef GfxLogCategory_hpp
#define GfxLogCategory_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace log
{

class GfxLogCategory final : public GfxObject
{
public:
    typedef int32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        logCategoryApplication = sdl2::SDL_LOG_CATEGORY_APPLICATION,
        logCategoryError = sdl2::SDL_LOG_CATEGORY_ERROR,
        logCategoryAssert = sdl2::SDL_LOG_CATEGORY_ASSERT,
        logCategorySystem = sdl2::SDL_LOG_CATEGORY_SYSTEM,
        logCategoryAudio = sdl2::SDL_LOG_CATEGORY_AUDIO,
        logCategoryVideo = sdl2::SDL_LOG_CATEGORY_VIDEO,
        logCategoryRender = sdl2::SDL_LOG_CATEGORY_RENDER,
        logCategoryInput = sdl2::SDL_LOG_CATEGORY_INPUT,
        logCategoryTest = sdl2::SDL_LOG_CATEGORY_TEST,
        /* Reserved by SDL for future use */
        logCategoryReserved1 = sdl2::SDL_LOG_CATEGORY_RESERVED1,
        logCategoryReserved2 = sdl2::SDL_LOG_CATEGORY_RESERVED2,
        logCategoryReserved3 = sdl2::SDL_LOG_CATEGORY_RESERVED3,
        logCategoryReserved4 = sdl2::SDL_LOG_CATEGORY_RESERVED4,
        logCategoryReserved5 = sdl2::SDL_LOG_CATEGORY_RESERVED5,
        logCategoryReserved6 = sdl2::SDL_LOG_CATEGORY_RESERVED6,
        logCategoryReserved7 = sdl2::SDL_LOG_CATEGORY_RESERVED7,
        logCategoryReserved8 = sdl2::SDL_LOG_CATEGORY_RESERVED8,
        logCategoryReserved9 = sdl2::SDL_LOG_CATEGORY_RESERVED9,
        logCategoryReserved10 = sdl2::SDL_LOG_CATEGORY_RESERVED10,
        /* For application use ... not supported by Gfx (yet ?!) */
        logCategoryCustom = sdl2::SDL_LOG_CATEGORY_CUSTOM
    };

    GfxLogCategory() noexcept;

    explicit GfxLogCategory(const ValueType value) noexcept;
    explicit GfxLogCategory(const SdlType value) noexcept;

    GfxLogCategory(GfxLogCategory const& other) noexcept;
    GfxLogCategory(GfxLogCategory&& other) noexcept;

    GfxLogCategory& operator=(GfxLogCategory const& other) noexcept;
    GfxLogCategory& operator=(GfxLogCategory&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isApplication(void) const noexcept;
    bool isError(void) const noexcept;
    bool isAssert(void) const noexcept;
    bool isSystem(void) const noexcept;
    bool isAudio(void) const noexcept;
    bool isVideo(void) const noexcept;
    bool isRender(void) const noexcept;
    bool isInput(void) const noexcept;
    bool isTest(void) const noexcept;
    bool isReserved1(void) const noexcept;
    bool isReserved2(void) const noexcept;
    bool isReserved3(void) const noexcept;
    bool isReserved4(void) const noexcept;
    bool isReserved5(void) const noexcept;
    bool isReserved6(void) const noexcept;
    bool isReserved7(void) const noexcept;
    bool isReserved8(void) const noexcept;
    bool isReserved9(void) const noexcept;
    bool isReserved10(void) const noexcept;
    bool isCustom(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace log

}  // namespace gfx

#endif /* GfxLogCategory_hpp */

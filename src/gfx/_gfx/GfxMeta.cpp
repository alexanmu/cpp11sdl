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

#include "GfxMeta.hpp"

#include "GfxBits.hpp"
#include "GfxBlendMode.hpp"
#include "GfxBool.hpp"
#include "GfxClipboard.hpp"
#include "GfxColor.hpp"
#include "GfxCpuInfo.hpp"
#include "GfxDisplayMode.hpp"
#include "GfxEndian.hpp"
#include "GfxGetError.hpp"
#include "GfxFileSystem.hpp"
#include "GfxGetRendererInfo.hpp"
#include "GfxGetVersion.hpp"
#include "GfxInitQuit.hpp"
#include "GfxLoadSo.hpp"
#include "GfxMessageBox.hpp"
#include "GfxMessageBoxButtonData.hpp"
#include "GfxMessageBoxButtonFlags.hpp"
#include "GfxMessageBoxColor.hpp"
#include "GfxMessageBoxColorScheme.hpp"
#include "GfxMessageBoxData.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxPalette.hpp"
#include "GfxPixelFormat.hpp"
#include "GfxPlatform.hpp"
#include "GfxPoint.hpp"
#include "GfxPowerInfo.hpp"
#include "GfxPowerState.hpp"
#include "GfxRect.hpp"
#include "GfxRenderer.hpp"
#include "GfxRendererFlags.hpp"
#include "GfxRendererFlip.hpp"
#include "GfxRendererInfo.hpp"
#include "GfxScreenSaver.hpp"
#include "GfxSurface.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxTexture.hpp"
#include "GfxTextureAccess.hpp"
#include "GfxTextureModulate.hpp"
#include "GfxVersion.hpp"
#include "GfxVideo.hpp"
#include "GfxWindow.hpp"
#include "GfxWindowEventID.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxAngle.hpp"
#include "GfxBitmapFont.hpp"
#include "GfxCanvas.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxRadius.hpp"
#include "GfxString.hpp"
#include "GfxInitFlags.hpp"  // 2017.05.17
#include "GfxTtfFont.hpp"  // 2017.05.17
#include "GfxTtfInitQuit.hpp"  // 2017.05.17
#include "GfxTtfGetVersion.hpp"  // 2017.05.18
#include "GfxTtfFontStyle.hpp"  // 2017.05.18
#include "GfxTtfFontHinting.hpp"  // 2017.05.18
#include "GfxTtfFontRenderer.hpp"  // 2017.05.19
#include "GfxFontInfo.hpp"  // 2017.05.19
#include "GfxControlledSurface.hpp"
#include "GfxPixelType.hpp"  // 2017.05.30
#include "GfxBitmapOrder.hpp"  // 2017.05.30
#include "GfxPackedOrder.hpp"  // 2017.05.30
#include "GfxArrayOrder.hpp"  // 2017.05.30
#include "GfxPackedLayout.hpp"  // 2017.05.30
#include "GfxPixelFormatEnum.hpp"  // 2017.05.30
#include "GfxHitTestResult.hpp"  // 2017.05.31
#include "GfxGammaRamp.hpp"  // 2017.06.01
#include "GfxHitTest.hpp"  // 2017.06.02
#include "GfxTextureFormats.hpp"  // 2017.06.02
#include "GfxError.hpp"  // 2017.06.03
#include "GfxLogPriority.hpp"  // 2017.06.07
#include "GfxLogCategory.hpp"  // 2017.06.07
#include "GfxLog.hpp"  // 2017.06.07
#include "GfxLogOutputFunction.hpp"  // 2017.06.09
#include "GfxHintPriority.hpp"  // 2017.06.16
#include "GfxHints.hpp"  // 2017.06.16
#include "GfxHintCallback.hpp"  // 2017.06.16
#include "GfxEventType.hpp"  // 2017.06.18
#include "GfxCommonEvent.hpp"  // 2017.06.19
#include "GfxWindowEvent.hpp"  // 2017.06.19

namespace gfx
{

namespace _gfx
{

namespace prv
{

// Based on https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error
template <typename T>
struct hasSdlTypeNested {
    // Types "yes" and "no" are guaranteed to have different sizes,
    // specifically sizeof(yes) == 1 and sizeof(no) == 2.
    typedef char yes[1];
    typedef char no[2];

    template <typename C>
    static yes& test(typename C::SdlType *);

    template <typename>
    static no& test(...);

    // If the "sizeof" of the result of calling test<T>(nullptr) is equal to sizeof(yes),
    // the first overload worked and T has a nested type named foobar.
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

template <typename T>
struct hasSdlTypePtrNested {
    // Types "yes" and "no" are guaranteed to have different sizes,
    // specifically sizeof(yes) == 1 and sizeof(no) == 2.
    typedef char yes[1];
    typedef char no[2];

    template <typename C>
    static yes& test(typename C::SdlTypePtr *);

    template <typename>
    static no& test(...);

    // If the "sizeof" of the result of calling test<T>(nullptr) is equal to sizeof(yes),
    // the first overload worked and T has a nested type named foobar.
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

template <typename T>
struct hasValueType {
    // Types "yes" and "no" are guaranteed to have different sizes,
    // specifically sizeof(yes) == 1 and sizeof(no) == 2.
    typedef char yes[1];
    typedef char no[2];

    template <typename C>
    static yes& test(typename C::ValueType *);

    template <typename>
    static no& test(...);

    // If the "sizeof" of the result of calling test<T>(nullptr) is equal to sizeof(yes),
    // the first overload worked and T has a nested type named foobar.
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

template <typename T>
constexpr GfxMeta::ClassInfo makeClassInfo(void)
{
    return {
        T::ClassName,
        sizeof(T),
        T::SdlResource,
        T::CallsSdl,
        prv::hasSdlTypeNested<T>::value,
        prv::hasSdlTypePtrNested<T>::value,
        prv::hasValueType<T>::value,
        std::is_abstract<T>::value,
        std::is_polymorphic<T>::value,
        std::is_copy_constructible<T>::value,
        std::is_copy_assignable<T>::value,
        std::is_move_constructible<T>::value,
        std::is_move_assignable<T>::value,
        std::is_base_of<GfxObject, T>::value,
        0,
        0
    };
}

}  // namespace prv

const struct GfxMeta::ClassInfo GfxMeta::classInfoArray_[] =
{
    // gfx::bits
    {        prv::makeClassInfo<gfx::bits::GfxBits>()    },
    // gfx::blendmode
    {        prv::makeClassInfo<gfx::blendmode::GfxBlendMode>()    },
    // gfx
    {        prv::makeClassInfo<gfx::GfxBool>()    },
    // gfx::clipboard
    {        prv::makeClassInfo<gfx::clipboard::GfxClipboard>()    },
    // gfx::pixels
    {        prv::makeClassInfo<gfx::pixels::GfxColor>()    },
    {        prv::makeClassInfo<gfx::pixels::GfxPalette>()    },
    {        prv::makeClassInfo<gfx::pixels::GfxPixelFormat>()    },
    {        prv::makeClassInfo<gfx::pixels::GfxPixelType>()    },  // 2017.05.30
    {        prv::makeClassInfo<gfx::pixels::GfxBitmapOrder>()    },  // 2017.05.30
    {        prv::makeClassInfo<gfx::pixels::GfxPackedOrder>()    },  // 2017.05.30
    {        prv::makeClassInfo<gfx::pixels::GfxArrayOrder>()    },  // 2017.05.30
    {        prv::makeClassInfo<gfx::pixels::GfxPackedLayout>()    },  // 2017.05.30
    {        prv::makeClassInfo<gfx::pixels::GfxPixelFormatEnum>()    },  // 2017.05.30
    // gfx::cpuinfo
    {        prv::makeClassInfo<gfx::cpuinfo::GfxCpuInfo>()    },
    // gfx::video
    {        prv::makeClassInfo<gfx::video::GfxDisplayMode>()    },
    {        prv::makeClassInfo<gfx::video::GfxScreenSaver>()    },
    {        prv::makeClassInfo<gfx::video::GfxVideo>()    },
    {        prv::makeClassInfo<gfx::video::GfxWindow>()    },
    {        prv::makeClassInfo<gfx::video::GfxWindowEventID>()    },
    {        prv::makeClassInfo<gfx::video::GfxWindowFlags>()    },
    {        prv::makeClassInfo<gfx::video::GfxWindowPosition>()    },
    {        prv::makeClassInfo<gfx::video::GfxHitTestResult>()    },  // 2017.05.31
    {        prv::makeClassInfo<gfx::video::GfxHitTest>()    },  // 2017.06.02
    // gfx::endian
    {        prv::makeClassInfo<gfx::endian::GfxEndian>()    },
    // gfx::error
    {        prv::makeClassInfo<gfx::error::GfxGetError>()    },
    {        prv::makeClassInfo<gfx::error::GfxError>()    },  // 2017.06.03
    // gfx::filesystem
    {        prv::makeClassInfo<gfx::filesystem::GfxFileSystem>()    },
    // gfx::version
    {        prv::makeClassInfo<gfx::version::GfxGetVersion>()    },
    {        prv::makeClassInfo<gfx::version::GfxVersion>()    },
    // gfx::initquit
    {        prv::makeClassInfo<gfx::initquit::GfxInitQuit>()    },
    {        prv::makeClassInfo<gfx::initquit::GfxInitFlags>()    },  // 2017.05.17
    // gfx::loadso
    {        prv::makeClassInfo<gfx::loadso::GfxLoadSo>()    },
    // gfx::msgbox
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBox>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxButtonData>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxButtonFlags>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxColor>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxColorScheme>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxData>()    },
    {        prv::makeClassInfo<gfx::msgbox::GfxMessageBoxFlags>()    },
    // gfx::platform
    {        prv::makeClassInfo<gfx::platform::GfxPlatform>()    },
    // gfx::rect
    {        prv::makeClassInfo<gfx::rect::GfxPoint>()    },
    {        prv::makeClassInfo<gfx::rect::GfxRect>()    },
    // gfx::power
    {        prv::makeClassInfo<gfx::power::GfxPowerInfo>()    },
    {        prv::makeClassInfo<gfx::power::GfxPowerState>()    },
    // gfx::surface
    {        prv::makeClassInfo<gfx::surface::GfxSurface>()    },
    {        prv::makeClassInfo<gfx::surface::GfxSurfaceFlags>()    },
    // gfx::bgi
    {        prv::makeClassInfo<gfx::bgi::GfxAngle>()    },
    {        prv::makeClassInfo<gfx::bgi::GfxCanvas>()    },
    {        prv::makeClassInfo<gfx::bgi::GfxCanvasBgi>()    },
    {        prv::makeClassInfo<gfx::bgi::GfxRadius>()    },
    {        prv::makeClassInfo<gfx::bgi::GfxString>()    },
    // gfx::bgi::fnt
    {        prv::makeClassInfo<gfx::bgi::fnt::GfxBitmapFont>()    },
    // gfx::tf
    {        prv::makeClassInfo<gfx::ttf::GfxTtfFont>()    },  // 2017.05.17
    {        prv::makeClassInfo<gfx::ttf::GfxTtfInitQuit>()    },  // 2017.05.17
    {        prv::makeClassInfo<gfx::ttf::GfxTtfGetVersion>()    },  // 2017.05.18
    {        prv::makeClassInfo<gfx::ttf::GfxTtfFontStyle>()    },  // 2017.05.18
    {        prv::makeClassInfo<gfx::ttf::GfxTtfFontHinting>()    },  // 2017.05.18
    {        prv::makeClassInfo<gfx::ttf::GfxTtfFontRenderer>()    },  // 2017.05.19
    // gfx::xtra
    {        prv::makeClassInfo<gfx::xtra::GfxFontInfo>()    },  // 2017.05.19
    {        prv::makeClassInfo<gfx::xtra::GfxControlledSurface>()    },
    {        prv::makeClassInfo<gfx::xtra::GfxGammaRamp>()    },  // 2017.06.01
    // gfx::log
    {        prv::makeClassInfo<gfx::log::GfxLogPriority>()    },  // 2017.06.07
    {        prv::makeClassInfo<gfx::log::GfxLogCategory>()    },  // 2017.06.07
    {        prv::makeClassInfo<gfx::log::GfxLog>()    },  // 2017.06.07
    {        prv::makeClassInfo<gfx::log::GfxLogOutputFunction>()    },  // 2017.06.09
    // gfx::render
    {        prv::makeClassInfo<gfx::render::GfxGetRendererInfo>()    },
    {        prv::makeClassInfo<gfx::render::GfxRenderer>()    },
    {        prv::makeClassInfo<gfx::render::GfxRendererFlags>()    },
    {        prv::makeClassInfo<gfx::render::GfxRendererFlip>()    },
    {        prv::makeClassInfo<gfx::render::GfxRendererInfo>()    },
    {        prv::makeClassInfo<gfx::render::GfxTexture>()    },
    {        prv::makeClassInfo<gfx::render::GfxTextureAccess>()    },
    {        prv::makeClassInfo<gfx::render::GfxTextureModulate>()    },
    {        prv::makeClassInfo<gfx::render::GfxTextureFormats>()    },  // 2017.06.02
    //  gfx::hints
    {        prv::makeClassInfo<gfx::hints::GfxHintPriority>()    },  // 2017.06.16
    {        prv::makeClassInfo<gfx::hints::GfxHints>()    },  // 2017.06.16
    {        prv::makeClassInfo<gfx::hints::GfxHintCallback>()    },  // 2017.06.16
    //  gfx::events
    {        prv::makeClassInfo<gfx::events::GfxEventType>()    },  // 2017.06.18
    {        prv::makeClassInfo<gfx::events::GfxCommonEvent>()    },  // 2017.06.19
    {        prv::makeClassInfo<gfx::events::GfxWindowEvent>()    }  // 2017.06.19
};

const int32_t GfxMeta::classNamesCount_ = sizeof(GfxMeta::classInfoArray_) /
                                          sizeof(GfxMeta::classInfoArray_[0]);

GfxMeta::GfxMeta() noexcept
{
    clear();
}

GfxMeta::~GfxMeta() noexcept
{
    // Nothing to do
}

GfxMeta::ClassInfo const& GfxMeta::getClassInfo(std::string const& className) noexcept
{
    clear();
    for (const auto& it : classInfoArray_)
    {
        if (className == std::string(it.className_))
        {
            classInfo_ = it;
        }
    }
    return classInfo_;
}

GfxMeta::ClassInfo const& GfxMeta::getClassInfo(const int32_t index) noexcept
{
    clear();
    if (index < GfxMeta::classNamesCount_)
    {
        classInfo_ = GfxMeta::classInfoArray_[index];
    }
    return classInfo_;
}

int32_t GfxMeta::getClassCount(void) const noexcept
{
    return GfxMeta::classNamesCount_;
}

int32_t GfxMeta::getClassInfoTableSizeInBytes(void) const noexcept
{
    return static_cast<int32_t>(sizeof(GfxMeta::classInfoArray_));
}

// Private methods
void GfxMeta::clear(void) noexcept
{
    classInfo_.className_ = nullptr;
    classInfo_.size_ = -1;
    classInfo_.hasSdlType_ = false;
    classInfo_.hasSdlTypePtr_ = false;
    classInfo_.isAbstract_ = false;
    classInfo_.isPolymorphic_ = false;
    classInfo_.isMoveConstructible_ = false;
    classInfo_.isMoveAssignable_ = false;
    classInfo_.isDerivedFromGfxObject_ = false;
    classInfo_.sdlResource_ = false;
    classInfo_.hasValueType_ = false;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

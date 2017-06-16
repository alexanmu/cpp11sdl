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

}  // namespace prv

const struct GfxMeta::ClassInfo GfxMeta::classInfoArray_[] =
{
    // gfx::bits
    {
        gfx::bits::GfxBits::ClassName,
        sizeof(gfx::bits::GfxBits),
        prv::hasSdlTypeNested<gfx::bits::GfxBits>::value,
        prv::hasSdlTypePtrNested<gfx::bits::GfxBits>::value,
        std::is_abstract<gfx::bits::GfxBits>::value,
        std::is_polymorphic<gfx::bits::GfxBits>::value,
        std::is_move_constructible<gfx::bits::GfxBits>::value,
        std::is_move_assignable<gfx::bits::GfxBits>::value,
        std::is_base_of<GfxObject, gfx::bits::GfxBits>::value,
        gfx::bits::GfxBits::SdlResource,
        prv::hasValueType<gfx::bits::GfxBits>::value
    },
    // gfx::blendmode
    {
        gfx::blendmode::GfxBlendMode::ClassName,
        sizeof(gfx::blendmode::GfxBlendMode),
        prv::hasSdlTypeNested<gfx::blendmode::GfxBlendMode>::value,
        prv::hasSdlTypePtrNested<gfx::blendmode::GfxBlendMode>::value,
        std::is_abstract<gfx::blendmode::GfxBlendMode>::value,
        std::is_polymorphic<gfx::blendmode::GfxBlendMode>::value,
        std::is_move_constructible<gfx::blendmode::GfxBlendMode>::value,
        std::is_move_assignable<gfx::blendmode::GfxBlendMode>::value,
        std::is_base_of<GfxObject, gfx::blendmode::GfxBlendMode>::value,
        gfx::blendmode::GfxBlendMode::SdlResource,
        prv::hasValueType<gfx::blendmode::GfxBlendMode>::value
    },
    // gfx
    {
        gfx::GfxBool::ClassName,
        sizeof(gfx::GfxBool),
        prv::hasSdlTypeNested<gfx::GfxBool>::value,
        prv::hasSdlTypePtrNested<gfx::GfxBool>::value,
        std::is_abstract<gfx::GfxBool>::value,
        std::is_polymorphic<gfx::GfxBool>::value,
        std::is_move_constructible<gfx::GfxBool>::value,
        std::is_move_assignable<gfx::GfxBool>::value,
        std::is_base_of<GfxObject, gfx::GfxBool>::value,
        gfx::GfxBool::SdlResource,
        prv::hasValueType<gfx::GfxBool>::value
    },
    // gfx::clipboard
    {
        gfx::clipboard::GfxClipboard::ClassName,
        sizeof(gfx::clipboard::GfxClipboard),
        prv::hasSdlTypeNested<gfx::clipboard::GfxClipboard>::value,
        prv::hasSdlTypePtrNested<gfx::clipboard::GfxClipboard>::value,
        std::is_abstract<gfx::clipboard::GfxClipboard>::value,
        std::is_polymorphic<gfx::clipboard::GfxClipboard>::value,
        std::is_move_constructible<gfx::clipboard::GfxClipboard>::value,
        std::is_move_assignable<gfx::clipboard::GfxClipboard>::value,
        std::is_base_of<GfxObject, gfx::clipboard::GfxClipboard>::value,
        gfx::clipboard::GfxClipboard::SdlResource,
        prv::hasValueType<gfx::clipboard::GfxClipboard>::value
    },
    // gfx::pixels
    {
        gfx::pixels::GfxColor::ClassName,
        sizeof(gfx::pixels::GfxColor),
        prv::hasSdlTypeNested<gfx::pixels::GfxColor>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxColor>::value,
        std::is_abstract<gfx::pixels::GfxColor>::value,
        std::is_polymorphic<gfx::pixels::GfxColor>::value,
        std::is_move_constructible<gfx::pixels::GfxColor>::value,
        std::is_move_assignable<gfx::pixels::GfxColor>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxColor>::value,
        gfx::pixels::GfxColor::SdlResource,
        prv::hasValueType<gfx::pixels::GfxColor>::value
    },
    {
        gfx::pixels::GfxPalette::ClassName,
        sizeof(gfx::pixels::GfxPalette),
        prv::hasSdlTypeNested<gfx::pixels::GfxPalette>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPalette>::value,
        std::is_abstract<gfx::pixels::GfxPalette>::value,
        std::is_polymorphic<gfx::pixels::GfxPalette>::value,
        std::is_move_constructible<gfx::pixels::GfxPalette>::value,
        std::is_move_assignable<gfx::pixels::GfxPalette>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPalette>::value,
        gfx::pixels::GfxPalette::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPalette>::value
    },
    {
        gfx::pixels::GfxPixelFormat::ClassName,
        sizeof(gfx::pixels::GfxPixelFormat),
        prv::hasSdlTypeNested<gfx::pixels::GfxPixelFormat>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelFormat>::value,
        std::is_abstract<gfx::pixels::GfxPixelFormat>::value,
        std::is_polymorphic<gfx::pixels::GfxPixelFormat>::value,
        std::is_move_constructible<gfx::pixels::GfxPixelFormat>::value,
        std::is_move_assignable<gfx::pixels::GfxPixelFormat>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPixelFormat>::value,
        gfx::pixels::GfxPixelFormat::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPixelFormat>::value
    },
    {
        gfx::pixels::GfxPixelType::ClassName,
        sizeof(gfx::pixels::GfxPixelType),
        prv::hasSdlTypeNested<gfx::pixels::GfxPixelType>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelType>::value,
        std::is_abstract<gfx::pixels::GfxPixelType>::value,
        std::is_polymorphic<gfx::pixels::GfxPixelType>::value,
        std::is_move_constructible<gfx::pixels::GfxPixelType>::value,
        std::is_move_assignable<gfx::pixels::GfxPixelType>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPixelType>::value,
        gfx::pixels::GfxPixelType::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPixelType>::value
    },  // 2017.05.30
    {
        gfx::pixels::GfxBitmapOrder::ClassName,
        sizeof(gfx::pixels::GfxBitmapOrder),
        prv::hasSdlTypeNested<gfx::pixels::GfxBitmapOrder>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxBitmapOrder>::value,
        std::is_abstract<gfx::pixels::GfxBitmapOrder>::value,
        std::is_polymorphic<gfx::pixels::GfxBitmapOrder>::value,
        std::is_move_constructible<gfx::pixels::GfxBitmapOrder>::value,
        std::is_move_assignable<gfx::pixels::GfxBitmapOrder>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxBitmapOrder>::value,
        gfx::pixels::GfxBitmapOrder::SdlResource,
        prv::hasValueType<gfx::pixels::GfxBitmapOrder>::value
    },  // 2017.05.30
    {
        gfx::pixels::GfxPackedOrder::ClassName,
        sizeof(gfx::pixels::GfxPackedOrder),
        prv::hasSdlTypeNested<gfx::pixels::GfxPackedOrder>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPackedOrder>::value,
        std::is_abstract<gfx::pixels::GfxPackedOrder>::value,
        std::is_polymorphic<gfx::pixels::GfxPackedOrder>::value,
        std::is_move_constructible<gfx::pixels::GfxPackedOrder>::value,
        std::is_move_assignable<gfx::pixels::GfxPackedOrder>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPackedOrder>::value,
        gfx::pixels::GfxPackedOrder::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPackedOrder>::value
    },  // 2017.05.30
    {
        gfx::pixels::GfxArrayOrder::ClassName,
        sizeof(gfx::pixels::GfxArrayOrder),
        prv::hasSdlTypeNested<gfx::pixels::GfxArrayOrder>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxArrayOrder>::value,
        std::is_abstract<gfx::pixels::GfxArrayOrder>::value,
        std::is_polymorphic<gfx::pixels::GfxArrayOrder>::value,
        std::is_move_constructible<gfx::pixels::GfxArrayOrder>::value,
        std::is_move_assignable<gfx::pixels::GfxArrayOrder>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxArrayOrder>::value,
        gfx::pixels::GfxArrayOrder::SdlResource,
        prv::hasValueType<gfx::pixels::GfxArrayOrder>::value
    },  // 2017.05.30
    {
        gfx::pixels::GfxPackedLayout::ClassName,
        sizeof(gfx::pixels::GfxPackedLayout),
        prv::hasSdlTypeNested<gfx::pixels::GfxPackedLayout>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPackedLayout>::value,
        std::is_abstract<gfx::pixels::GfxPackedLayout>::value,
        std::is_polymorphic<gfx::pixels::GfxPackedLayout>::value,
        std::is_move_constructible<gfx::pixels::GfxPackedLayout>::value,
        std::is_move_assignable<gfx::pixels::GfxPackedLayout>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPackedLayout>::value,
        gfx::pixels::GfxPackedLayout::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPackedLayout>::value
    },  // 2017.05.30
    {
        gfx::pixels::GfxPixelFormatEnum::ClassName,
        sizeof(gfx::pixels::GfxPixelFormatEnum),
        prv::hasSdlTypeNested<gfx::pixels::GfxPixelFormatEnum>::value,
        prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelFormatEnum>::value,
        std::is_abstract<gfx::pixels::GfxPixelFormatEnum>::value,
        std::is_polymorphic<gfx::pixels::GfxPixelFormatEnum>::value,
        std::is_move_constructible<gfx::pixels::GfxPixelFormatEnum>::value,
        std::is_move_assignable<gfx::pixels::GfxPixelFormatEnum>::value,
        std::is_base_of<GfxObject, gfx::pixels::GfxPixelFormatEnum>::value,
        gfx::pixels::GfxPixelFormatEnum::SdlResource,
        prv::hasValueType<gfx::pixels::GfxPixelFormatEnum>::value
    },  // 2017.05.30
    // gfx::cpuinfo
    {
        gfx::cpuinfo::GfxCpuInfo::ClassName,
        sizeof(gfx::cpuinfo::GfxCpuInfo),
        prv::hasSdlTypeNested<gfx::cpuinfo::GfxCpuInfo>::value,
        prv::hasSdlTypePtrNested<gfx::cpuinfo::GfxCpuInfo>::value,
        std::is_abstract<gfx::cpuinfo::GfxCpuInfo>::value,
        std::is_polymorphic<gfx::cpuinfo::GfxCpuInfo>::value,
        std::is_move_constructible<gfx::cpuinfo::GfxCpuInfo>::value,
        std::is_move_assignable<gfx::cpuinfo::GfxCpuInfo>::value,
        std::is_base_of<GfxObject, gfx::cpuinfo::GfxCpuInfo>::value,
        gfx::cpuinfo::GfxCpuInfo::SdlResource,
        prv::hasValueType<gfx::cpuinfo::GfxCpuInfo>::value
    },
    // gfx::video
    {
        gfx::video::GfxDisplayMode::ClassName,
        sizeof(gfx::video::GfxDisplayMode),
        prv::hasSdlTypeNested<gfx::video::GfxDisplayMode>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxDisplayMode>::value,
        std::is_abstract<gfx::video::GfxDisplayMode>::value,
        std::is_polymorphic<gfx::video::GfxDisplayMode>::value,
        std::is_move_constructible<gfx::video::GfxDisplayMode>::value,
        std::is_move_assignable<gfx::video::GfxDisplayMode>::value,
        std::is_base_of<GfxObject, gfx::video::GfxDisplayMode>::value,
        gfx::video::GfxDisplayMode::SdlResource,
        prv::hasValueType<gfx::video::GfxDisplayMode>::value
    },
    {
        gfx::video::GfxScreenSaver::ClassName,
        sizeof(gfx::video::GfxScreenSaver),
        prv::hasSdlTypeNested<gfx::video::GfxScreenSaver>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxScreenSaver>::value,
        std::is_abstract<gfx::video::GfxScreenSaver>::value,
        std::is_polymorphic<gfx::video::GfxScreenSaver>::value,
        std::is_move_constructible<gfx::video::GfxScreenSaver>::value,
        std::is_move_assignable<gfx::video::GfxScreenSaver>::value,
        std::is_base_of<GfxObject, gfx::video::GfxScreenSaver>::value,
        gfx::video::GfxScreenSaver::SdlResource,
        prv::hasValueType<gfx::video::GfxScreenSaver>::value
    },
    {
        gfx::video::GfxVideo::ClassName,
        sizeof(gfx::video::GfxVideo),
        prv::hasSdlTypeNested<gfx::video::GfxVideo>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxVideo>::value,
        std::is_abstract<gfx::video::GfxVideo>::value,
        std::is_polymorphic<gfx::video::GfxVideo>::value,
        std::is_move_constructible<gfx::video::GfxVideo>::value,
        std::is_move_assignable<gfx::video::GfxVideo>::value,
        std::is_base_of<GfxObject, gfx::video::GfxVideo>::value,
        gfx::video::GfxVideo::SdlResource,
        prv::hasValueType<gfx::video::GfxVideo>::value
    },
    {
        gfx::video::GfxWindow::ClassName,
        sizeof(gfx::video::GfxWindow),
        prv::hasSdlTypeNested<gfx::video::GfxWindow>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxWindow>::value,
        std::is_abstract<gfx::video::GfxWindow>::value,
        std::is_polymorphic<gfx::video::GfxWindow>::value,
        std::is_move_constructible<gfx::video::GfxWindow>::value,
        std::is_move_assignable<gfx::video::GfxWindow>::value,
        std::is_base_of<GfxObject, gfx::video::GfxWindow>::value,
        gfx::video::GfxWindow::SdlResource,
        prv::hasValueType<gfx::video::GfxWindow>::value
    },
    {
        gfx::video::GfxWindowEventID::ClassName,
        sizeof(gfx::video::GfxWindowEventID),
        prv::hasSdlTypeNested<gfx::video::GfxWindowEventID>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxWindowEventID>::value,
        std::is_abstract<gfx::video::GfxWindowEventID>::value,
        std::is_polymorphic<gfx::video::GfxWindowEventID>::value,
        std::is_move_constructible<gfx::video::GfxWindowEventID>::value,
        std::is_move_assignable<gfx::video::GfxWindowEventID>::value,
        std::is_base_of<GfxObject, gfx::video::GfxWindowEventID>::value,
        gfx::video::GfxWindowEventID::SdlResource,
        prv::hasValueType<gfx::video::GfxWindowEventID>::value
    },
    {
        gfx::video::GfxWindowFlags::ClassName,
        sizeof(gfx::video::GfxWindowFlags),
        prv::hasSdlTypeNested<gfx::video::GfxWindowFlags>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxWindowFlags>::value,
        std::is_abstract<gfx::video::GfxWindowFlags>::value,
        std::is_polymorphic<gfx::video::GfxWindowFlags>::value,
        std::is_move_constructible<gfx::video::GfxWindowFlags>::value,
        std::is_move_assignable<gfx::video::GfxWindowFlags>::value,
        std::is_base_of<GfxObject, gfx::video::GfxWindowFlags>::value,
        gfx::video::GfxWindowFlags::SdlResource,
        prv::hasValueType<gfx::video::GfxWindowFlags>::value
    },
    {
        gfx::video::GfxWindowPosition::ClassName,
        sizeof(gfx::video::GfxWindowPosition),
        prv::hasSdlTypeNested<gfx::video::GfxWindowPosition>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxWindowPosition>::value,
        std::is_abstract<gfx::video::GfxWindowPosition>::value,
        std::is_polymorphic<gfx::video::GfxWindowPosition>::value,
        std::is_move_constructible<gfx::video::GfxWindowPosition>::value,
        std::is_move_assignable<gfx::video::GfxWindowPosition>::value,
        std::is_base_of<GfxObject, gfx::video::GfxWindowPosition>::value,
        gfx::video::GfxWindowPosition::SdlResource,
        prv::hasValueType<gfx::video::GfxWindowPosition>::value
    },
    {
        gfx::video::GfxHitTestResult::ClassName,
        sizeof(gfx::video::GfxHitTestResult),
        prv::hasSdlTypeNested<gfx::video::GfxHitTestResult>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxHitTestResult>::value,
        std::is_abstract<gfx::video::GfxHitTestResult>::value,
        std::is_polymorphic<gfx::video::GfxHitTestResult>::value,
        std::is_move_constructible<gfx::video::GfxHitTestResult>::value,
        std::is_move_assignable<gfx::video::GfxHitTestResult>::value,
        std::is_base_of<GfxObject, gfx::video::GfxHitTestResult>::value,
        gfx::video::GfxHitTestResult::SdlResource,
        prv::hasValueType<gfx::video::GfxHitTestResult>::value
    },  // 2017.05.31
    {
        gfx::video::GfxHitTest::ClassName,
        sizeof(gfx::video::GfxHitTest),
        prv::hasSdlTypeNested<gfx::video::GfxHitTest>::value,
        prv::hasSdlTypePtrNested<gfx::video::GfxHitTest>::value,
        std::is_abstract<gfx::video::GfxHitTest>::value,
        std::is_polymorphic<gfx::video::GfxHitTest>::value,
        std::is_move_constructible<gfx::video::GfxHitTest>::value,
        std::is_move_assignable<gfx::video::GfxHitTest>::value,
        std::is_base_of<GfxObject, gfx::video::GfxHitTest>::value,
        gfx::video::GfxHitTest::SdlResource,
        prv::hasValueType<gfx::video::GfxHitTest>::value
    },  // 2017.06.02
    // gfx::endian
    {
        gfx::endian::GfxEndian::ClassName,
        sizeof(gfx::endian::GfxEndian),
        prv::hasSdlTypeNested<gfx::endian::GfxEndian>::value,
        prv::hasSdlTypePtrNested<gfx::endian::GfxEndian>::value,
        std::is_abstract<gfx::endian::GfxEndian>::value,
        std::is_polymorphic<gfx::endian::GfxEndian>::value,
        std::is_move_constructible<gfx::endian::GfxEndian>::value,
        std::is_move_assignable<gfx::endian::GfxEndian>::value,
        std::is_base_of<GfxObject, gfx::endian::GfxEndian>::value,
        gfx::endian::GfxEndian::SdlResource,
        prv::hasValueType<gfx::endian::GfxEndian>::value
    },
    // gfx::error
    {
        gfx::error::GfxGetError::ClassName,
        sizeof(gfx::error::GfxGetError),
        prv::hasSdlTypeNested<gfx::error::GfxGetError>::value,
        prv::hasSdlTypePtrNested<gfx::error::GfxGetError>::value,
        std::is_abstract<gfx::error::GfxGetError>::value,
        std::is_polymorphic<gfx::error::GfxGetError>::value,
        std::is_move_constructible<gfx::error::GfxGetError>::value,
        std::is_move_assignable<gfx::error::GfxGetError>::value,
        std::is_base_of<GfxObject, gfx::error::GfxGetError>::value,
        gfx::error::GfxGetError::SdlResource,
        prv::hasValueType<gfx::error::GfxGetError>::value
    },
    {
        gfx::error::GfxError::ClassName,
        sizeof(gfx::error::GfxError),
        prv::hasSdlTypeNested<gfx::error::GfxError>::value,
        prv::hasSdlTypePtrNested<gfx::error::GfxError>::value,
        std::is_abstract<gfx::error::GfxError>::value,
        std::is_polymorphic<gfx::error::GfxError>::value,
        std::is_move_constructible<gfx::error::GfxError>::value,
        std::is_move_assignable<gfx::error::GfxError>::value,
        std::is_base_of<GfxObject, gfx::error::GfxError>::value,
        gfx::error::GfxError::SdlResource,
        prv::hasValueType<gfx::error::GfxError>::value
    },  // 2017.06.03
    // gfx::filesystem
    {
        gfx::filesystem::GfxFileSystem::ClassName,
        sizeof(gfx::filesystem::GfxFileSystem),
        prv::hasSdlTypeNested<gfx::filesystem::GfxFileSystem>::value,
        prv::hasSdlTypePtrNested<gfx::filesystem::GfxFileSystem>::value,
        std::is_abstract<gfx::filesystem::GfxFileSystem>::value,
        std::is_polymorphic<gfx::filesystem::GfxFileSystem>::value,
        std::is_move_constructible<gfx::filesystem::GfxFileSystem>::value,
        std::is_move_assignable<gfx::filesystem::GfxFileSystem>::value,
        std::is_base_of<GfxObject, gfx::filesystem::GfxFileSystem>::value,
        gfx::filesystem::GfxFileSystem::SdlResource,
        prv::hasValueType<gfx::filesystem::GfxFileSystem>::value
    },
    // gfx::version
    {
        gfx::version::GfxGetVersion::ClassName,
        sizeof(gfx::version::GfxGetVersion),
        prv::hasSdlTypeNested<gfx::version::GfxGetVersion>::value,
        prv::hasSdlTypePtrNested<gfx::version::GfxGetVersion>::value,
        std::is_abstract<gfx::version::GfxGetVersion>::value,
        std::is_polymorphic<gfx::version::GfxGetVersion>::value,
        std::is_move_constructible<gfx::version::GfxGetVersion>::value,
        std::is_move_assignable<gfx::version::GfxGetVersion>::value,
        std::is_base_of<GfxObject, gfx::version::GfxGetVersion>::value,
        gfx::version::GfxGetVersion::SdlResource,
        prv::hasValueType<gfx::version::GfxGetVersion>::value
    },
    {
        gfx::version::GfxVersion::ClassName,
        sizeof(gfx::version::GfxVersion),
        prv::hasSdlTypeNested<gfx::version::GfxVersion>::value,
        prv::hasSdlTypePtrNested<gfx::version::GfxVersion>::value,
        std::is_abstract<gfx::version::GfxVersion>::value,
        std::is_polymorphic<gfx::version::GfxVersion>::value,
        std::is_move_constructible<gfx::version::GfxVersion>::value,
        std::is_move_assignable<gfx::version::GfxVersion>::value,
        std::is_base_of<GfxObject, gfx::version::GfxVersion>::value,
        gfx::version::GfxVersion::SdlResource,
        prv::hasValueType<gfx::version::GfxVersion>::value
    },
    // gfx::initquit
    {
        gfx::initquit::GfxInitQuit::ClassName,
        sizeof(gfx::initquit::GfxInitQuit),
        prv::hasSdlTypeNested<gfx::initquit::GfxInitQuit>::value,
        prv::hasSdlTypePtrNested<gfx::initquit::GfxInitQuit>::value,
        std::is_abstract<gfx::initquit::GfxInitQuit>::value,
        std::is_polymorphic<gfx::initquit::GfxInitQuit>::value,
        std::is_move_constructible<gfx::initquit::GfxInitQuit>::value,
        std::is_move_assignable<gfx::initquit::GfxInitQuit>::value,
        std::is_base_of<GfxObject, gfx::initquit::GfxInitQuit>::value,
        gfx::initquit::GfxInitQuit::SdlResource,
        prv::hasValueType<gfx::initquit::GfxInitQuit>::value
    },
    {
        gfx::initquit::GfxInitFlags::ClassName,
        sizeof(gfx::initquit::GfxInitFlags),
        prv::hasSdlTypeNested<gfx::initquit::GfxInitFlags>::value,
        prv::hasSdlTypePtrNested<gfx::initquit::GfxInitFlags>::value,
        std::is_abstract<gfx::initquit::GfxInitFlags>::value,
        std::is_polymorphic<gfx::initquit::GfxInitFlags>::value,
        std::is_move_constructible<gfx::initquit::GfxInitFlags>::value,
        std::is_move_assignable<gfx::initquit::GfxInitFlags>::value,
        std::is_base_of<GfxObject, gfx::initquit::GfxInitFlags>::value,
        gfx::initquit::GfxInitFlags::SdlResource,
        prv::hasValueType<gfx::initquit::GfxInitFlags>::value
    },  // 2017.05.17
    // gfx::loadso
    {
        gfx::loadso::GfxLoadSo::ClassName,
        sizeof(gfx::loadso::GfxLoadSo),
        prv::hasSdlTypeNested<gfx::loadso::GfxLoadSo>::value,
        prv::hasSdlTypePtrNested<gfx::loadso::GfxLoadSo>::value,
        std::is_abstract<gfx::loadso::GfxLoadSo>::value,
        std::is_polymorphic<gfx::loadso::GfxLoadSo>::value,
        std::is_move_constructible<gfx::loadso::GfxLoadSo>::value,
        std::is_move_assignable<gfx::loadso::GfxLoadSo>::value,
        std::is_base_of<GfxObject, gfx::loadso::GfxLoadSo>::value,
        gfx::loadso::GfxLoadSo::SdlResource,
        prv::hasValueType<gfx::loadso::GfxLoadSo>::value
    },
    // gfx::msgbox
    {
        gfx::msgbox::GfxMessageBox::ClassName,
        sizeof(gfx::msgbox::GfxMessageBox),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBox>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBox>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBox>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBox>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBox>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBox>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBox>::value,
        gfx::msgbox::GfxMessageBox::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBox>::value
    },
    {
        gfx::msgbox::GfxMessageBoxButtonData::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxButtonData),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxButtonData>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxButtonData>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxButtonData>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxButtonData>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxButtonData>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxButtonData>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxButtonData>::value,
        gfx::msgbox::GfxMessageBoxButtonData::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxButtonData>::value
    },
    {
        gfx::msgbox::GfxMessageBoxButtonFlags::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxButtonFlags),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxButtonFlags>::value,
        gfx::msgbox::GfxMessageBoxButtonFlags::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxButtonFlags>::value
    },
    {
        gfx::msgbox::GfxMessageBoxColor::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxColor),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxColor>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxColor>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxColor>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxColor>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxColor>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxColor>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxColor>::value,
        gfx::msgbox::GfxMessageBoxColor::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxColor>::value
    },
    {
        gfx::msgbox::GfxMessageBoxColorScheme::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxColorScheme),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxColorScheme>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxColorScheme>::value,
        gfx::msgbox::GfxMessageBoxColorScheme::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxColorScheme>::value
    },
    {
        gfx::msgbox::GfxMessageBoxData::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxData),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxData>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxData>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxData>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxData>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxData>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxData>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxData>::value,
        gfx::msgbox::GfxMessageBoxData::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxData>::value
    },
    {
        gfx::msgbox::GfxMessageBoxFlags::ClassName,
        sizeof(gfx::msgbox::GfxMessageBoxFlags),
        prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxFlags>::value,
        prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxFlags>::value,
        std::is_abstract<gfx::msgbox::GfxMessageBoxFlags>::value,
        std::is_polymorphic<gfx::msgbox::GfxMessageBoxFlags>::value,
        std::is_move_constructible<gfx::msgbox::GfxMessageBoxFlags>::value,
        std::is_move_assignable<gfx::msgbox::GfxMessageBoxFlags>::value,
        std::is_base_of<GfxObject, gfx::msgbox::GfxMessageBoxFlags>::value,
        gfx::msgbox::GfxMessageBoxFlags::SdlResource,
        prv::hasValueType<gfx::msgbox::GfxMessageBoxFlags>::value
    },
    // gfx::platform
    {
        gfx::platform::GfxPlatform::ClassName,
        sizeof(gfx::platform::GfxPlatform),
        prv::hasSdlTypeNested<gfx::platform::GfxPlatform>::value,
        prv::hasSdlTypePtrNested<gfx::platform::GfxPlatform>::value,
        std::is_abstract<gfx::platform::GfxPlatform>::value,
        std::is_polymorphic<gfx::platform::GfxPlatform>::value,
        std::is_move_constructible<gfx::platform::GfxPlatform>::value,
        std::is_move_assignable<gfx::platform::GfxPlatform>::value,
        std::is_base_of<GfxObject, gfx::platform::GfxPlatform>::value,
        gfx::platform::GfxPlatform::SdlResource,
        prv::hasValueType<gfx::platform::GfxPlatform>::value
    },
    // gfx::rect
    {
        gfx::rect::GfxPoint::ClassName,
        sizeof(gfx::rect::GfxPoint),
        prv::hasSdlTypeNested<gfx::rect::GfxPoint>::value,
        prv::hasSdlTypePtrNested<gfx::rect::GfxPoint>::value,
        std::is_abstract<gfx::rect::GfxPoint>::value,
        std::is_polymorphic<gfx::rect::GfxPoint>::value,
        std::is_move_constructible<gfx::rect::GfxPoint>::value,
        std::is_move_assignable<gfx::rect::GfxPoint>::value,
        std::is_base_of<GfxObject, gfx::rect::GfxPoint>::value,
        gfx::rect::GfxPoint::SdlResource,
        prv::hasValueType<gfx::rect::GfxPoint>::value
    },
    {
        gfx::rect::GfxRect::ClassName,
        sizeof(gfx::rect::GfxRect),
        prv::hasSdlTypeNested<gfx::rect::GfxRect>::value,
        prv::hasSdlTypePtrNested<gfx::rect::GfxRect>::value,
        std::is_abstract<gfx::rect::GfxRect>::value,
        std::is_polymorphic<gfx::rect::GfxRect>::value,
        std::is_move_constructible<gfx::rect::GfxRect>::value,
        std::is_move_assignable<gfx::rect::GfxRect>::value,
        std::is_base_of<GfxObject, gfx::rect::GfxRect>::value,
        gfx::rect::GfxRect::SdlResource,
        prv::hasValueType<gfx::rect::GfxRect>::value
    },
    // gfx::power
    {
        gfx::power::GfxPowerInfo::ClassName,
        sizeof(gfx::power::GfxPowerInfo),
        prv::hasSdlTypeNested<gfx::power::GfxPowerInfo>::value,
        prv::hasSdlTypePtrNested<gfx::power::GfxPowerInfo>::value,
        std::is_abstract<gfx::power::GfxPowerInfo>::value,
        std::is_polymorphic<gfx::power::GfxPowerInfo>::value,
        std::is_move_constructible<gfx::power::GfxPowerInfo>::value,
        std::is_move_assignable<gfx::power::GfxPowerInfo>::value,
        std::is_base_of<GfxObject, gfx::power::GfxPowerInfo>::value,
        gfx::power::GfxPowerInfo::SdlResource,
        prv::hasValueType<gfx::power::GfxPowerInfo>::value
    },
    {
        gfx::power::GfxPowerState::ClassName,
        sizeof(gfx::power::GfxPowerState),
        prv::hasSdlTypeNested<gfx::power::GfxPowerState>::value,
        prv::hasSdlTypePtrNested<gfx::power::GfxPowerState>::value,
        std::is_abstract<gfx::power::GfxPowerState>::value,
        std::is_polymorphic<gfx::power::GfxPowerState>::value,
        std::is_move_constructible<gfx::power::GfxPowerState>::value,
        std::is_move_assignable<gfx::power::GfxPowerState>::value,
        std::is_base_of<GfxObject, gfx::power::GfxPowerState>::value,
        gfx::power::GfxPowerState::SdlResource,
        prv::hasValueType<gfx::power::GfxPowerState>::value
    },
    // gfx::surface
    {
        gfx::surface::GfxSurface::ClassName,
        sizeof(gfx::surface::GfxSurface),
        prv::hasSdlTypeNested<gfx::surface::GfxSurface>::value,
        prv::hasSdlTypePtrNested<gfx::surface::GfxSurface>::value,
        std::is_abstract<gfx::surface::GfxSurface>::value,
        std::is_polymorphic<gfx::surface::GfxSurface>::value,
        std::is_move_constructible<gfx::surface::GfxSurface>::value,
        std::is_move_assignable<gfx::surface::GfxSurface>::value,
        std::is_base_of<GfxObject, gfx::surface::GfxSurface>::value,
        gfx::surface::GfxSurface::SdlResource,
        prv::hasValueType<gfx::surface::GfxSurface>::value
    },
    {
        gfx::surface::GfxSurfaceFlags::ClassName,
        sizeof(gfx::surface::GfxSurfaceFlags),
        prv::hasSdlTypeNested<gfx::surface::GfxSurfaceFlags>::value,
        prv::hasSdlTypePtrNested<gfx::surface::GfxSurfaceFlags>::value,
        std::is_abstract<gfx::surface::GfxSurfaceFlags>::value,
        std::is_polymorphic<gfx::surface::GfxSurfaceFlags>::value,
        std::is_move_constructible<gfx::surface::GfxSurfaceFlags>::value,
        std::is_move_assignable<gfx::surface::GfxSurfaceFlags>::value,
        std::is_base_of<GfxObject, gfx::surface::GfxSurfaceFlags>::value,
        gfx::surface::GfxSurfaceFlags::SdlResource,
        prv::hasValueType<gfx::surface::GfxSurfaceFlags>::value
    },
    // gfx::bgi
    {
        gfx::bgi::GfxAngle::ClassName,
        sizeof(gfx::bgi::GfxAngle),
        prv::hasSdlTypeNested<gfx::bgi::GfxAngle>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::GfxAngle>::value,
        std::is_abstract<gfx::bgi::GfxAngle>::value,
        std::is_polymorphic<gfx::bgi::GfxAngle>::value,
        std::is_move_constructible<gfx::bgi::GfxAngle>::value,
        std::is_move_assignable<gfx::bgi::GfxAngle>::value,
        std::is_base_of<GfxObject, gfx::bgi::GfxAngle>::value,
        gfx::bgi::GfxAngle::SdlResource,
        prv::hasValueType<gfx::bgi::GfxAngle>::value
    },
    {
        gfx::bgi::GfxCanvas::ClassName,
        sizeof(gfx::bgi::GfxCanvas),
        prv::hasSdlTypeNested<gfx::bgi::GfxCanvas>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::GfxCanvas>::value,
        std::is_abstract<gfx::bgi::GfxCanvas>::value,
        std::is_polymorphic<gfx::bgi::GfxCanvas>::value,
        std::is_move_constructible<gfx::bgi::GfxCanvas>::value,
        std::is_move_assignable<gfx::bgi::GfxCanvas>::value,
        std::is_base_of<GfxObject, gfx::bgi::GfxCanvas>::value,
        gfx::bgi::GfxCanvas::SdlResource,
        prv::hasValueType<gfx::bgi::GfxCanvas>::value
    },
    {
        gfx::bgi::GfxCanvasBgi::ClassName,
        sizeof(gfx::bgi::GfxCanvasBgi),
        prv::hasSdlTypeNested<gfx::bgi::GfxCanvasBgi>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::GfxCanvasBgi>::value,
        std::is_abstract<gfx::bgi::GfxCanvasBgi>::value,
        std::is_polymorphic<gfx::bgi::GfxCanvasBgi>::value,
        std::is_move_constructible<gfx::bgi::GfxCanvasBgi>::value,
        std::is_move_assignable<gfx::bgi::GfxCanvasBgi>::value,
        std::is_base_of<GfxObject, gfx::bgi::GfxCanvasBgi>::value,
        gfx::bgi::GfxCanvasBgi::SdlResource,
        prv::hasValueType<gfx::bgi::GfxCanvasBgi>::value
    },
    {
        gfx::bgi::GfxRadius::ClassName,
        sizeof(gfx::bgi::GfxRadius),
        prv::hasSdlTypeNested<gfx::bgi::GfxRadius>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::GfxRadius>::value,
        std::is_abstract<gfx::bgi::GfxRadius>::value,
        std::is_polymorphic<gfx::bgi::GfxRadius>::value,
        std::is_move_constructible<gfx::bgi::GfxRadius>::value,
        std::is_move_assignable<gfx::bgi::GfxRadius>::value,
        std::is_base_of<GfxObject, gfx::bgi::GfxRadius>::value,
        gfx::bgi::GfxRadius::SdlResource,
        prv::hasValueType<gfx::bgi::GfxRadius>::value
    },
    {
        gfx::bgi::GfxString::ClassName,
        sizeof(gfx::bgi::GfxString),
        prv::hasSdlTypeNested<gfx::bgi::GfxString>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::GfxString>::value,
        std::is_abstract<gfx::bgi::GfxString>::value,
        std::is_polymorphic<gfx::bgi::GfxString>::value,
        std::is_move_constructible<gfx::bgi::GfxString>::value,
        std::is_move_assignable<gfx::bgi::GfxString>::value,
        std::is_base_of<GfxObject, gfx::bgi::GfxString>::value,
        gfx::bgi::GfxString::SdlResource,
        prv::hasValueType<gfx::bgi::GfxString>::value
    },
    // gfx::bgi::fnt
    {
        gfx::bgi::fnt::GfxBitmapFont::ClassName,
        sizeof(gfx::bgi::fnt::GfxBitmapFont),
        prv::hasSdlTypeNested<gfx::bgi::fnt::GfxBitmapFont>::value,
        prv::hasSdlTypePtrNested<gfx::bgi::fnt::GfxBitmapFont>::value,
        std::is_abstract<gfx::bgi::fnt::GfxBitmapFont>::value,
        std::is_polymorphic<gfx::bgi::fnt::GfxBitmapFont>::value,
        std::is_move_constructible<gfx::bgi::fnt::GfxBitmapFont>::value,
        std::is_move_assignable<gfx::bgi::fnt::GfxBitmapFont>::value,
        std::is_base_of<GfxObject, gfx::bgi::fnt::GfxBitmapFont>::value,
        gfx::bgi::fnt::GfxBitmapFont::SdlResource,
        prv::hasValueType<gfx::bgi::fnt::GfxBitmapFont>::value
    },
    // gfx::tf
    {
        gfx::ttf::GfxTtfFont::ClassName,
        sizeof(gfx::ttf::GfxTtfFont),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfFont>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFont>::value,
        std::is_abstract<gfx::ttf::GfxTtfFont>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfFont>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfFont>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfFont>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfFont>::value,
        gfx::ttf::GfxTtfFont::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfFont>::value
    },  // 2017.05.17
    {
        gfx::ttf::GfxTtfInitQuit::ClassName,
        sizeof(gfx::ttf::GfxTtfInitQuit),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfInitQuit>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfInitQuit>::value,
        std::is_abstract<gfx::ttf::GfxTtfInitQuit>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfInitQuit>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfInitQuit>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfInitQuit>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfInitQuit>::value,
        gfx::ttf::GfxTtfInitQuit::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfInitQuit>::value
    },  // 2017.05.17
    {
        gfx::ttf::GfxTtfGetVersion::ClassName,
        sizeof(gfx::ttf::GfxTtfGetVersion),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfGetVersion>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfGetVersion>::value,
        std::is_abstract<gfx::ttf::GfxTtfGetVersion>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfGetVersion>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfGetVersion>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfGetVersion>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfGetVersion>::value,
        gfx::ttf::GfxTtfGetVersion::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfGetVersion>::value
    },  // 2017.05.18
    {
        gfx::ttf::GfxTtfFontStyle::ClassName,
        sizeof(gfx::ttf::GfxTtfFontStyle),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontStyle>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontStyle>::value,
        std::is_abstract<gfx::ttf::GfxTtfFontStyle>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfFontStyle>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfFontStyle>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfFontStyle>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfFontStyle>::value,
        gfx::ttf::GfxTtfFontStyle::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfFontStyle>::value
    },  // 2017.05.18
    {
        gfx::ttf::GfxTtfFontHinting::ClassName,
        sizeof(gfx::ttf::GfxTtfFontHinting),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontHinting>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontHinting>::value,
        std::is_abstract<gfx::ttf::GfxTtfFontHinting>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfFontHinting>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfFontHinting>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfFontHinting>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfFontHinting>::value,
        gfx::ttf::GfxTtfFontHinting::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfFontHinting>::value
    },  // 2017.05.18
    {
        gfx::ttf::GfxTtfFontRenderer::ClassName,
        sizeof(gfx::ttf::GfxTtfFontRenderer),
        prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontRenderer>::value,
        prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontRenderer>::value,
        std::is_abstract<gfx::ttf::GfxTtfFontRenderer>::value,
        std::is_polymorphic<gfx::ttf::GfxTtfFontRenderer>::value,
        std::is_move_constructible<gfx::ttf::GfxTtfFontRenderer>::value,
        std::is_move_assignable<gfx::ttf::GfxTtfFontRenderer>::value,
        std::is_base_of<GfxObject, gfx::ttf::GfxTtfFontRenderer>::value,
        gfx::ttf::GfxTtfFontRenderer::SdlResource,
        prv::hasValueType<gfx::ttf::GfxTtfFontRenderer>::value
    },  // 2017.05.19
    // gfx::xtra
    {
        gfx::xtra::GfxFontInfo::ClassName,
        sizeof(gfx::xtra::GfxFontInfo),
        prv::hasSdlTypeNested<gfx::xtra::GfxFontInfo>::value,
        prv::hasSdlTypePtrNested<gfx::xtra::GfxFontInfo>::value,
        std::is_abstract<gfx::xtra::GfxFontInfo>::value,
        std::is_polymorphic<gfx::xtra::GfxFontInfo>::value,
        std::is_move_constructible<gfx::xtra::GfxFontInfo>::value,
        std::is_move_assignable<gfx::xtra::GfxFontInfo>::value,
        std::is_base_of<GfxObject, gfx::xtra::GfxFontInfo>::value,
        gfx::xtra::GfxFontInfo::SdlResource,
        prv::hasValueType<gfx::xtra::GfxFontInfo>::value
    },  // 2017.05.19
    {
        gfx::xtra::GfxControlledSurface::ClassName,
        sizeof(gfx::xtra::GfxControlledSurface),
        prv::hasSdlTypeNested<gfx::xtra::GfxControlledSurface>::value,
        prv::hasSdlTypePtrNested<gfx::xtra::GfxControlledSurface>::value,
        std::is_abstract<gfx::xtra::GfxControlledSurface>::value,
        std::is_polymorphic<gfx::xtra::GfxControlledSurface>::value,
        std::is_move_constructible<gfx::xtra::GfxControlledSurface>::value,
        std::is_move_assignable<gfx::xtra::GfxControlledSurface>::value,
        std::is_base_of<GfxObject, gfx::xtra::GfxControlledSurface>::value,
        gfx::xtra::GfxControlledSurface::SdlResource,
        prv::hasValueType<gfx::xtra::GfxControlledSurface>::value
    },
    {
        gfx::xtra::GfxGammaRamp::ClassName,
        sizeof(gfx::xtra::GfxGammaRamp),
        prv::hasSdlTypeNested<gfx::xtra::GfxGammaRamp>::value,
        prv::hasSdlTypePtrNested<gfx::xtra::GfxGammaRamp>::value,
        std::is_abstract<gfx::xtra::GfxGammaRamp>::value,
        std::is_polymorphic<gfx::xtra::GfxGammaRamp>::value,
        std::is_move_constructible<gfx::xtra::GfxGammaRamp>::value,
        std::is_move_assignable<gfx::xtra::GfxGammaRamp>::value,
        std::is_base_of<GfxObject, gfx::xtra::GfxGammaRamp>::value,
        gfx::xtra::GfxGammaRamp::SdlResource,
        prv::hasValueType<gfx::xtra::GfxGammaRamp>::value
    },  // 2017.06.01
    // gfx::log
    {
        gfx::log::GfxLogPriority::ClassName,
        sizeof(gfx::log::GfxLogPriority),
        prv::hasSdlTypeNested<gfx::log::GfxLogPriority>::value,
        prv::hasSdlTypePtrNested<gfx::log::GfxLogPriority>::value,
        std::is_abstract<gfx::log::GfxLogPriority>::value,
        std::is_polymorphic<gfx::log::GfxLogPriority>::value,
        std::is_move_constructible<gfx::log::GfxLogPriority>::value,
        std::is_move_assignable<gfx::log::GfxLogPriority>::value,
        std::is_base_of<GfxObject, gfx::log::GfxLogPriority>::value,
        gfx::log::GfxLogPriority::SdlResource,
        prv::hasValueType<gfx::log::GfxLogPriority>::value
    },  // 2017.06.07
    {
        gfx::log::GfxLogCategory::ClassName,
        sizeof(gfx::log::GfxLogCategory),
        prv::hasSdlTypeNested<gfx::log::GfxLogCategory>::value,
        prv::hasSdlTypePtrNested<gfx::log::GfxLogCategory>::value,
        std::is_abstract<gfx::log::GfxLogCategory>::value,
        std::is_polymorphic<gfx::log::GfxLogCategory>::value,
        std::is_move_constructible<gfx::log::GfxLogCategory>::value,
        std::is_move_assignable<gfx::log::GfxLogCategory>::value,
        std::is_base_of<GfxObject, gfx::log::GfxLogCategory>::value,
        gfx::log::GfxLogCategory::SdlResource,
        prv::hasValueType<gfx::log::GfxLogCategory>::value
    },  // 2017.06.07
    {
        gfx::log::GfxLog::ClassName,
        sizeof(gfx::log::GfxLog),
        prv::hasSdlTypeNested<gfx::log::GfxLog>::value,
        prv::hasSdlTypePtrNested<gfx::log::GfxLog>::value,
        std::is_abstract<gfx::log::GfxLog>::value,
        std::is_polymorphic<gfx::log::GfxLog>::value,
        std::is_move_constructible<gfx::log::GfxLog>::value,
        std::is_move_assignable<gfx::log::GfxLog>::value,
        std::is_base_of<GfxObject, gfx::log::GfxLog>::value,
        gfx::log::GfxLog::SdlResource,
        prv::hasValueType<gfx::log::GfxLog>::value
    },  // 2017.06.07
    {
        gfx::log::GfxLogOutputFunction::ClassName,
        sizeof(gfx::log::GfxLogOutputFunction),
        prv::hasSdlTypeNested<gfx::log::GfxLogOutputFunction>::value,
        prv::hasSdlTypePtrNested<gfx::log::GfxLogOutputFunction>::value,
        std::is_abstract<gfx::log::GfxLogOutputFunction>::value,
        std::is_polymorphic<gfx::log::GfxLogOutputFunction>::value,
        std::is_move_constructible<gfx::log::GfxLogOutputFunction>::value,
        std::is_move_assignable<gfx::log::GfxLogOutputFunction>::value,
        std::is_base_of<GfxObject, gfx::log::GfxLogOutputFunction>::value,
        gfx::log::GfxLogOutputFunction::SdlResource,
        prv::hasValueType<gfx::log::GfxLogOutputFunction>::value
    },  // 2017.06.09
    // gfx::render
    {
        gfx::render::GfxGetRendererInfo::ClassName,
        sizeof(gfx::render::GfxGetRendererInfo),
        prv::hasSdlTypeNested<gfx::render::GfxGetRendererInfo>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxGetRendererInfo>::value,
        std::is_abstract<gfx::render::GfxGetRendererInfo>::value,
        std::is_polymorphic<gfx::render::GfxGetRendererInfo>::value,
        std::is_move_constructible<gfx::render::GfxGetRendererInfo>::value,
        std::is_move_assignable<gfx::render::GfxGetRendererInfo>::value,
        std::is_base_of<GfxObject, gfx::render::GfxGetRendererInfo>::value,
        gfx::render::GfxGetRendererInfo::SdlResource,
        prv::hasValueType<gfx::render::GfxGetRendererInfo>::value
    },
    {
        gfx::render::GfxRenderer::ClassName,
        sizeof(gfx::render::GfxRenderer),
        prv::hasSdlTypeNested<gfx::render::GfxRenderer>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxRenderer>::value,
        std::is_abstract<gfx::render::GfxRenderer>::value,
        std::is_polymorphic<gfx::render::GfxRenderer>::value,
        std::is_move_constructible<gfx::render::GfxRenderer>::value,
        std::is_move_assignable<gfx::render::GfxRenderer>::value,
        std::is_base_of<GfxObject, gfx::render::GfxRenderer>::value,
        gfx::render::GfxRenderer::SdlResource,
        prv::hasValueType<gfx::render::GfxRenderer>::value
    },
    {
        gfx::render::GfxRendererFlags::ClassName,
        sizeof(gfx::render::GfxRendererFlags),
        prv::hasSdlTypeNested<gfx::render::GfxRendererFlags>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxRendererFlags>::value,
        std::is_abstract<gfx::render::GfxRendererFlags>::value,
        std::is_polymorphic<gfx::render::GfxRendererFlags>::value,
        std::is_move_constructible<gfx::render::GfxRendererFlags>::value,
        std::is_move_assignable<gfx::render::GfxRendererFlags>::value,
        std::is_base_of<GfxObject, gfx::render::GfxRendererFlags>::value,
        gfx::render::GfxRendererFlags::SdlResource,
        prv::hasValueType<gfx::render::GfxRendererFlags>::value
    },
    {
        gfx::render::GfxRendererFlip::ClassName,
        sizeof(gfx::render::GfxRendererFlip),
        prv::hasSdlTypeNested<gfx::render::GfxRendererFlip>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxRendererFlip>::value,
        std::is_abstract<gfx::render::GfxRendererFlip>::value,
        std::is_polymorphic<gfx::render::GfxRendererFlip>::value,
        std::is_move_constructible<gfx::render::GfxRendererFlip>::value,
        std::is_move_assignable<gfx::render::GfxRendererFlip>::value,
        std::is_base_of<GfxObject, gfx::render::GfxRendererFlip>::value,
        gfx::render::GfxRendererFlip::SdlResource,
        prv::hasValueType<gfx::render::GfxRendererFlip>::value
    },
    {
        gfx::render::GfxRendererInfo::ClassName,
        sizeof(gfx::render::GfxRendererInfo),
        prv::hasSdlTypeNested<gfx::render::GfxRendererInfo>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxRendererInfo>::value,
        std::is_abstract<gfx::render::GfxRendererInfo>::value,
        std::is_polymorphic<gfx::render::GfxRendererInfo>::value,
        std::is_move_constructible<gfx::render::GfxRendererInfo>::value,
        std::is_move_assignable<gfx::render::GfxRendererInfo>::value,
        std::is_base_of<GfxObject, gfx::render::GfxRendererInfo>::value,
        gfx::render::GfxRendererInfo::SdlResource,
        prv::hasValueType<gfx::render::GfxRendererInfo>::value
    },
    {
        gfx::render::GfxTexture::ClassName,
        sizeof(gfx::render::GfxTexture),
        prv::hasSdlTypeNested<gfx::render::GfxTexture>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxTexture>::value,
        std::is_abstract<gfx::render::GfxTexture>::value,
        std::is_polymorphic<gfx::render::GfxTexture>::value,
        std::is_move_constructible<gfx::render::GfxTexture>::value,
        std::is_move_assignable<gfx::render::GfxTexture>::value,
        std::is_base_of<GfxObject, gfx::render::GfxTexture>::value,
        gfx::render::GfxTexture::SdlResource,
        prv::hasValueType<gfx::render::GfxTexture>::value
    },
    {
        gfx::render::GfxTextureAccess::ClassName,
        sizeof(gfx::render::GfxTextureAccess),
        prv::hasSdlTypeNested<gfx::render::GfxTextureAccess>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxTextureAccess>::value,
        std::is_abstract<gfx::render::GfxTextureAccess>::value,
        std::is_polymorphic<gfx::render::GfxTextureAccess>::value,
        std::is_move_constructible<gfx::render::GfxTextureAccess>::value,
        std::is_move_assignable<gfx::render::GfxTextureAccess>::value,
        std::is_base_of<GfxObject, gfx::render::GfxTextureAccess>::value,
        gfx::render::GfxTextureAccess::SdlResource,
        prv::hasValueType<gfx::render::GfxTextureAccess>::value
    },
    {
        gfx::render::GfxTextureModulate::ClassName,
        sizeof(gfx::render::GfxTextureModulate),
        prv::hasSdlTypeNested<gfx::render::GfxTextureModulate>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxTextureModulate>::value,
        std::is_abstract<gfx::render::GfxTextureModulate>::value,
        std::is_polymorphic<gfx::render::GfxTextureModulate>::value,
        std::is_move_constructible<gfx::render::GfxTextureModulate>::value,
        std::is_move_assignable<gfx::render::GfxTextureModulate>::value,
        std::is_base_of<GfxObject, gfx::render::GfxTextureModulate>::value,
        gfx::render::GfxTextureModulate::SdlResource,
        prv::hasValueType<gfx::render::GfxTextureModulate>::value
    },
    {
        gfx::render::GfxTextureFormats::ClassName,
        sizeof(gfx::render::GfxTextureFormats),
        prv::hasSdlTypeNested<gfx::render::GfxTextureFormats>::value,
        prv::hasSdlTypePtrNested<gfx::render::GfxTextureFormats>::value,
        std::is_abstract<gfx::render::GfxTextureFormats>::value,
        std::is_polymorphic<gfx::render::GfxTextureFormats>::value,
        std::is_move_constructible<gfx::render::GfxTextureFormats>::value,
        std::is_move_assignable<gfx::render::GfxTextureFormats>::value,
        std::is_base_of<GfxObject, gfx::render::GfxTextureFormats>::value,
        gfx::render::GfxTextureFormats::SdlResource,
        prv::hasValueType<gfx::render::GfxTextureFormats>::value
    },  // 2017.06.02
    //  gfx::hints
    {
        gfx::hints::GfxHintPriority::ClassName,
        sizeof(gfx::hints::GfxHintPriority),
        prv::hasSdlTypeNested<gfx::hints::GfxHintPriority>::value,
        prv::hasSdlTypePtrNested<gfx::hints::GfxHintPriority>::value,
        std::is_abstract<gfx::hints::GfxHintPriority>::value,
        std::is_polymorphic<gfx::hints::GfxHintPriority>::value,
        std::is_move_constructible<gfx::hints::GfxHintPriority>::value,
        std::is_move_assignable<gfx::hints::GfxHintPriority>::value,
        std::is_base_of<GfxObject, gfx::hints::GfxHintPriority>::value,
        gfx::hints::GfxHintPriority::SdlResource,
        prv::hasValueType<gfx::hints::GfxHintPriority>::value
    },  // 2017.06.16
    {
        gfx::hints::GfxHints::ClassName,
        sizeof(gfx::hints::GfxHints),
        prv::hasSdlTypeNested<gfx::hints::GfxHints>::value,
        prv::hasSdlTypePtrNested<gfx::hints::GfxHints>::value,
        std::is_abstract<gfx::hints::GfxHints>::value,
        std::is_polymorphic<gfx::hints::GfxHints>::value,
        std::is_move_constructible<gfx::hints::GfxHints>::value,
        std::is_move_assignable<gfx::hints::GfxHints>::value,
        std::is_base_of<GfxObject, gfx::hints::GfxHints>::value,
        gfx::hints::GfxHints::SdlResource,
        prv::hasValueType<gfx::hints::GfxHints>::value
    },  // 2017.06.16
    {
        gfx::hints::GfxHintCallback::ClassName,
        sizeof(gfx::hints::GfxHintCallback),
        prv::hasSdlTypeNested<gfx::hints::GfxHintCallback>::value,
        prv::hasSdlTypePtrNested<gfx::hints::GfxHintCallback>::value,
        std::is_abstract<gfx::hints::GfxHintCallback>::value,
        std::is_polymorphic<gfx::hints::GfxHintCallback>::value,
        std::is_move_constructible<gfx::hints::GfxHintCallback>::value,
        std::is_move_assignable<gfx::hints::GfxHintCallback>::value,
        std::is_base_of<GfxObject, gfx::hints::GfxHintCallback>::value,
        gfx::hints::GfxHintCallback::SdlResource,
        prv::hasValueType<gfx::hints::GfxHintCallback>::value
    }  // 2017.06.16
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

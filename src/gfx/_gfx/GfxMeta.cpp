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

}  // namespace prv

const struct GfxMeta::ClassInfo GfxMeta::classInfoArray_[] =
{
    // gfx::bits
    {
      gfx::bits::GfxBits::ClassName,
      sizeof(gfx::bits::GfxBits),
      prv::hasSdlTypeNested<gfx::bits::GfxBits>::value,
      prv::hasSdlTypePtrNested<gfx::bits::GfxBits>::value
    },
    // gfx::blendmode
    {
      gfx::blendmode::GfxBlendMode::ClassName,
      sizeof(gfx::blendmode::GfxBlendMode),
      prv::hasSdlTypeNested<gfx::blendmode::GfxBlendMode>::value,
      prv::hasSdlTypePtrNested<gfx::blendmode::GfxBlendMode>::value
    },
    // gfx
    {
      gfx::GfxBool::ClassName,
      sizeof(gfx::GfxBool),
      prv::hasSdlTypeNested<gfx::GfxBool>::value,
      prv::hasSdlTypePtrNested<gfx::GfxBool>::value
    },
    // gfx::clipboard
    {
      gfx::clipboard::GfxClipboard::ClassName,
      sizeof(gfx::clipboard::GfxClipboard),
      prv::hasSdlTypeNested<gfx::clipboard::GfxClipboard>::value,
      prv::hasSdlTypePtrNested<gfx::clipboard::GfxClipboard>::value
    },
    // gfx::pixels
    {
      gfx::pixels::GfxColor::ClassName,
      sizeof(gfx::pixels::GfxColor),
      prv::hasSdlTypeNested<gfx::pixels::GfxColor>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxColor>::value
    },
    {
      gfx::pixels::GfxPalette::ClassName,
      sizeof(gfx::pixels::GfxPalette),
      prv::hasSdlTypeNested<gfx::pixels::GfxPalette>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPalette>::value
    },
    {
      gfx::pixels::GfxPixelFormat::ClassName,
      sizeof(gfx::pixels::GfxPixelFormat),
      prv::hasSdlTypeNested<gfx::pixels::GfxPixelFormat>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelFormat>::value
    },
    {
      gfx::pixels::GfxPixelType::ClassName,
      sizeof(gfx::pixels::GfxPixelType),
      prv::hasSdlTypeNested<gfx::pixels::GfxPixelType>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelType>::value
    },  // 2017.05.30
    {
      gfx::pixels::GfxBitmapOrder::ClassName,
      sizeof(gfx::pixels::GfxBitmapOrder),
      prv::hasSdlTypeNested<gfx::pixels::GfxBitmapOrder>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxBitmapOrder>::value
    },  // 2017.05.30
    {
      gfx::pixels::GfxPackedOrder::ClassName,
      sizeof(gfx::pixels::GfxPackedOrder),
      prv::hasSdlTypeNested<gfx::pixels::GfxPackedOrder>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPackedOrder>::value
    },  // 2017.05.30
    {
      gfx::pixels::GfxArrayOrder::ClassName,
      sizeof(gfx::pixels::GfxArrayOrder),
      prv::hasSdlTypeNested<gfx::pixels::GfxArrayOrder>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxArrayOrder>::value
    },  // 2017.05.30
    {
      gfx::pixels::GfxPackedLayout::ClassName,
      sizeof(gfx::pixels::GfxPackedLayout),
      prv::hasSdlTypeNested<gfx::pixels::GfxPackedLayout>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPackedLayout>::value
    },  // 2017.05.30
    {
      gfx::pixels::GfxPixelFormatEnum::ClassName,
      sizeof(gfx::pixels::GfxPixelFormatEnum),
      prv::hasSdlTypeNested<gfx::pixels::GfxPixelFormatEnum>::value,
      prv::hasSdlTypePtrNested<gfx::pixels::GfxPixelFormatEnum>::value
    },  // 2017.05.30
    // gfx::cpuinfo
    {
      gfx::cpuinfo::GfxCpuInfo::ClassName,
      sizeof(gfx::cpuinfo::GfxCpuInfo),
      prv::hasSdlTypeNested<gfx::cpuinfo::GfxCpuInfo>::value,
      prv::hasSdlTypePtrNested<gfx::cpuinfo::GfxCpuInfo>::value
    },
    // gfx::video
    {
      gfx::video::GfxDisplayMode::ClassName,
      sizeof(gfx::video::GfxDisplayMode),
      prv::hasSdlTypeNested<gfx::video::GfxDisplayMode>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxDisplayMode>::value
    },
    {
      gfx::video::GfxScreenSaver::ClassName,
      sizeof(gfx::video::GfxScreenSaver),
      prv::hasSdlTypeNested<gfx::video::GfxScreenSaver>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxScreenSaver>::value
    },
    {
      gfx::video::GfxVideo::ClassName,
      sizeof(gfx::video::GfxVideo),
      prv::hasSdlTypeNested<gfx::video::GfxVideo>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxVideo>::value
    },
    {
      gfx::video::GfxWindow::ClassName,
      sizeof(gfx::video::GfxWindow),
      prv::hasSdlTypeNested<gfx::video::GfxWindow>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxWindow>::value
    },
    {
      gfx::video::GfxWindowEventID::ClassName,
      sizeof(gfx::video::GfxWindowEventID),
      prv::hasSdlTypeNested<gfx::video::GfxWindowEventID>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxWindowEventID>::value
    },
    {
      gfx::video::GfxWindowFlags::ClassName,
      sizeof(gfx::video::GfxWindowFlags),
      prv::hasSdlTypeNested<gfx::video::GfxWindowFlags>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxWindowFlags>::value
    },
    {
      gfx::video::GfxWindowPosition::ClassName,
      sizeof(gfx::video::GfxWindowPosition),
      prv::hasSdlTypeNested<gfx::video::GfxWindowPosition>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxWindowPosition>::value
    },
    {
      gfx::video::GfxHitTestResult::ClassName,
      sizeof(gfx::video::GfxHitTestResult),
      prv::hasSdlTypeNested<gfx::video::GfxHitTestResult>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxHitTestResult>::value
    },  // 2017.05.31
    {
      gfx::video::GfxHitTest::ClassName,
      sizeof(gfx::video::GfxHitTest),
      prv::hasSdlTypeNested<gfx::video::GfxHitTest>::value,
      prv::hasSdlTypePtrNested<gfx::video::GfxHitTest>::value
    },  // 2017.06.02
    // gfx::endian
    {
      gfx::endian::GfxEndian::ClassName,
      sizeof(gfx::endian::GfxEndian),
      prv::hasSdlTypeNested<gfx::endian::GfxEndian>::value,
      prv::hasSdlTypePtrNested<gfx::endian::GfxEndian>::value
    },
    // gfx::error
    {
      gfx::error::GfxGetError::ClassName,
      sizeof(gfx::error::GfxGetError),
      prv::hasSdlTypeNested<gfx::error::GfxGetError>::value,
      prv::hasSdlTypePtrNested<gfx::error::GfxGetError>::value
    },
    {
      gfx::error::GfxError::ClassName,
      sizeof(gfx::error::GfxError),
      prv::hasSdlTypeNested<gfx::error::GfxError>::value,
      prv::hasSdlTypePtrNested<gfx::error::GfxError>::value
    },  // 2017.06.03
    // gfx::filesystem
    {
      gfx::filesystem::GfxFileSystem::ClassName,
      sizeof(gfx::filesystem::GfxFileSystem),
      prv::hasSdlTypeNested<gfx::filesystem::GfxFileSystem>::value,
      prv::hasSdlTypePtrNested<gfx::filesystem::GfxFileSystem>::value
    },
    // gfx::version
    {
      gfx::version::GfxGetVersion::ClassName,
      sizeof(gfx::version::GfxGetVersion),
      prv::hasSdlTypeNested<gfx::version::GfxGetVersion>::value,
      prv::hasSdlTypePtrNested<gfx::version::GfxGetVersion>::value
    },
    {
      gfx::version::GfxVersion::ClassName,
      sizeof(gfx::version::GfxVersion),
      prv::hasSdlTypeNested<gfx::version::GfxVersion>::value,
      prv::hasSdlTypePtrNested<gfx::version::GfxVersion>::value
    },
    // gfx::initquit
    {
      gfx::initquit::GfxInitQuit::ClassName,
      sizeof(gfx::initquit::GfxInitQuit),
      prv::hasSdlTypeNested<gfx::initquit::GfxInitQuit>::value,
      prv::hasSdlTypePtrNested<gfx::initquit::GfxInitQuit>::value
    },
    {
      gfx::initquit::GfxInitFlags::ClassName,
      sizeof(gfx::initquit::GfxInitFlags),
      prv::hasSdlTypeNested<gfx::initquit::GfxInitFlags>::value,
      prv::hasSdlTypePtrNested<gfx::initquit::GfxInitFlags>::value
    },  // 2017.05.17
    // gfx::loadso
    {
      gfx::loadso::GfxLoadSo::ClassName,
      sizeof(gfx::loadso::GfxLoadSo),
      prv::hasSdlTypeNested<gfx::loadso::GfxLoadSo>::value,
      prv::hasSdlTypePtrNested<gfx::loadso::GfxLoadSo>::value
    },
    // gfx::msgbox
    {
      gfx::msgbox::GfxMessageBox::ClassName,
      sizeof(gfx::msgbox::GfxMessageBox),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBox>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBox>::value
    },
    {
      gfx::msgbox::GfxMessageBoxButtonData::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxButtonData),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxButtonData>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxButtonData>::value
    },
    {
      gfx::msgbox::GfxMessageBoxButtonFlags::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxButtonFlags),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxButtonFlags>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxButtonFlags>::value
    },
    {
      gfx::msgbox::GfxMessageBoxColor::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxColor),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxColor>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxColor>::value
    },
    {
      gfx::msgbox::GfxMessageBoxColorScheme::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxColorScheme),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxColorScheme>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxColorScheme>::value
    },
    {
      gfx::msgbox::GfxMessageBoxData::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxData),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxData>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxData>::value
    },
    {
      gfx::msgbox::GfxMessageBoxFlags::ClassName,
      sizeof(gfx::msgbox::GfxMessageBoxFlags),
      prv::hasSdlTypeNested<gfx::msgbox::GfxMessageBoxFlags>::value,
      prv::hasSdlTypePtrNested<gfx::msgbox::GfxMessageBoxFlags>::value
    },
    // gfx::platform
    {
      gfx::platform::GfxPlatform::ClassName,
      sizeof(gfx::platform::GfxPlatform),
      prv::hasSdlTypeNested<gfx::platform::GfxPlatform>::value,
      prv::hasSdlTypePtrNested<gfx::platform::GfxPlatform>::value
    },
    // gfx::rect
    {
      gfx::rect::GfxPoint::ClassName,
      sizeof(gfx::rect::GfxPoint),
      prv::hasSdlTypeNested<gfx::rect::GfxPoint>::value,
      prv::hasSdlTypePtrNested<gfx::rect::GfxPoint>::value
    },
    {
      gfx::rect::GfxRect::ClassName,
      sizeof(gfx::rect::GfxRect),
      prv::hasSdlTypeNested<gfx::rect::GfxRect>::value,
      prv::hasSdlTypePtrNested<gfx::rect::GfxRect>::value
    },
    // gfx::power
    {
      gfx::power::GfxPowerInfo::ClassName,
      sizeof(gfx::power::GfxPowerInfo),
      prv::hasSdlTypeNested<gfx::power::GfxPowerInfo>::value,
      prv::hasSdlTypePtrNested<gfx::power::GfxPowerInfo>::value
    },
    {
      gfx::power::GfxPowerState::ClassName,
      sizeof(gfx::power::GfxPowerState),
      prv::hasSdlTypeNested<gfx::power::GfxPowerState>::value,
      prv::hasSdlTypePtrNested<gfx::power::GfxPowerState>::value
    },
    // gfx::surface
    {
      gfx::surface::GfxSurface::ClassName,
      sizeof(gfx::surface::GfxSurface),
      prv::hasSdlTypeNested<gfx::surface::GfxSurface>::value,
      prv::hasSdlTypePtrNested<gfx::surface::GfxSurface>::value
    },
    {
      gfx::surface::GfxSurfaceFlags::ClassName,
      sizeof(gfx::surface::GfxSurfaceFlags),
      prv::hasSdlTypeNested<gfx::surface::GfxSurfaceFlags>::value,
      prv::hasSdlTypePtrNested<gfx::surface::GfxSurfaceFlags>::value
    },
    // gfx::bgi
    {
      gfx::bgi::GfxAngle::ClassName,
      sizeof(gfx::bgi::GfxAngle),
      prv::hasSdlTypeNested<gfx::bgi::GfxAngle>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::GfxAngle>::value
    },
    {
      gfx::bgi::GfxCanvas::ClassName,
      sizeof(gfx::bgi::GfxCanvas),
      prv::hasSdlTypeNested<gfx::bgi::GfxCanvas>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::GfxCanvas>::value
    },
    {
      gfx::bgi::GfxCanvasBgi::ClassName,
      sizeof(gfx::bgi::GfxCanvasBgi),
      prv::hasSdlTypeNested<gfx::bgi::GfxCanvasBgi>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::GfxCanvasBgi>::value
    },
    {
      gfx::bgi::GfxRadius::ClassName,
      sizeof(gfx::bgi::GfxRadius),
      prv::hasSdlTypeNested<gfx::bgi::GfxRadius>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::GfxRadius>::value
    },
    {
      gfx::bgi::GfxString::ClassName,
      sizeof(gfx::bgi::GfxString),
      prv::hasSdlTypeNested<gfx::bgi::GfxString>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::GfxString>::value
    },
    // gfx::bgi::fnt
    {
      gfx::bgi::fnt::GfxBitmapFont::ClassName,
      sizeof(gfx::bgi::fnt::GfxBitmapFont),
      prv::hasSdlTypeNested<gfx::bgi::fnt::GfxBitmapFont>::value,
      prv::hasSdlTypePtrNested<gfx::bgi::fnt::GfxBitmapFont>::value
    },
    // gfx::tf
    {
      gfx::ttf::GfxTtfFont::ClassName,
      sizeof(gfx::ttf::GfxTtfFont),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfFont>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFont>::value
    },  // 2017.05.17
    {
      gfx::ttf::GfxTtfInitQuit::ClassName,
      sizeof(gfx::ttf::GfxTtfInitQuit),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfInitQuit>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfInitQuit>::value
    },  // 2017.05.17
    {
      gfx::ttf::GfxTtfGetVersion::ClassName,
      sizeof(gfx::ttf::GfxTtfGetVersion),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfGetVersion>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfGetVersion>::value
    },  // 2017.05.18
    {
      gfx::ttf::GfxTtfFontStyle::ClassName,
      sizeof(gfx::ttf::GfxTtfFontStyle),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontStyle>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontStyle>::value
    },  // 2017.05.18
    {
      gfx::ttf::GfxTtfFontHinting::ClassName,
      sizeof(gfx::ttf::GfxTtfFontHinting),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontHinting>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontHinting>::value
    },  // 2017.05.18
    {
      gfx::ttf::GfxTtfFontRenderer::ClassName,
      sizeof(gfx::ttf::GfxTtfFontRenderer),
      prv::hasSdlTypeNested<gfx::ttf::GfxTtfFontRenderer>::value,
      prv::hasSdlTypePtrNested<gfx::ttf::GfxTtfFontRenderer>::value
    },  // 2017.05.19
    // gfx::xtra
    {
      gfx::xtra::GfxFontInfo::ClassName,
      sizeof(gfx::xtra::GfxFontInfo),
      prv::hasSdlTypeNested<gfx::xtra::GfxFontInfo>::value,
      prv::hasSdlTypePtrNested<gfx::xtra::GfxFontInfo>::value
    },  // 2017.05.19
    {
      gfx::xtra::GfxControlledSurface::ClassName,
      sizeof(gfx::xtra::GfxControlledSurface),
      prv::hasSdlTypeNested<gfx::xtra::GfxControlledSurface>::value,
      prv::hasSdlTypePtrNested<gfx::xtra::GfxControlledSurface>::value
    },
    {
      gfx::xtra::GfxGammaRamp::ClassName,
      sizeof(gfx::xtra::GfxGammaRamp),
      prv::hasSdlTypeNested<gfx::xtra::GfxGammaRamp>::value,
      prv::hasSdlTypePtrNested<gfx::xtra::GfxGammaRamp>::value
    },  // 2017.06.01
    // gfx::log
    {
      gfx::log::GfxLogPriority::ClassName,
      sizeof(gfx::log::GfxLogPriority),
      prv::hasSdlTypeNested<gfx::log::GfxLogPriority>::value,
      prv::hasSdlTypePtrNested<gfx::log::GfxLogPriority>::value
    },  // 2017.06.07
    {
      gfx::log::GfxLogCategory::ClassName,
      sizeof(gfx::log::GfxLogCategory),
      prv::hasSdlTypeNested<gfx::log::GfxLogCategory>::value,
      prv::hasSdlTypePtrNested<gfx::log::GfxLogCategory>::value
    },  // 2017.06.07
    {
      gfx::log::GfxLog::ClassName,
      sizeof(gfx::log::GfxLog),
      prv::hasSdlTypeNested<gfx::log::GfxLog>::value,
      prv::hasSdlTypePtrNested<gfx::log::GfxLog>::value
    },  // 2017.06.07
    {
      gfx::log::GfxLogOutputFunction::ClassName,
      sizeof(gfx::log::GfxLogOutputFunction),
      prv::hasSdlTypeNested<gfx::log::GfxLogOutputFunction>::value,
      prv::hasSdlTypePtrNested<gfx::log::GfxLogOutputFunction>::value
    },  // 2017.06.09
    // gfx::render
    {
      gfx::render::GfxGetRendererInfo::ClassName,
      sizeof(gfx::render::GfxGetRendererInfo),
      prv::hasSdlTypeNested<gfx::render::GfxGetRendererInfo>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxGetRendererInfo>::value
    },
    {
      gfx::render::GfxRenderer::ClassName,
      sizeof(gfx::render::GfxRenderer),
      prv::hasSdlTypeNested<gfx::render::GfxRenderer>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxRenderer>::value
    },
    {
      gfx::render::GfxRendererFlags::ClassName,
      sizeof(gfx::render::GfxRendererFlags),
      prv::hasSdlTypeNested<gfx::render::GfxRendererFlags>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxRendererFlags>::value
    },
    {
      gfx::render::GfxRendererFlip::ClassName,
      sizeof(gfx::render::GfxRendererFlip),
      prv::hasSdlTypeNested<gfx::render::GfxRendererFlip>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxRendererFlip>::value
    },
    {
      gfx::render::GfxRendererInfo::ClassName,
      sizeof(gfx::render::GfxRendererInfo),
      prv::hasSdlTypeNested<gfx::render::GfxRendererInfo>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxRendererInfo>::value
    },
    {
      gfx::render::GfxTexture::ClassName,
      sizeof(gfx::render::GfxTexture),
      prv::hasSdlTypeNested<gfx::render::GfxTexture>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxTexture>::value
    },
    {
      gfx::render::GfxTextureAccess::ClassName,
      sizeof(gfx::render::GfxTextureAccess),
      prv::hasSdlTypeNested<gfx::render::GfxTextureAccess>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxTextureAccess>::value
    },
    {
      gfx::render::GfxTextureModulate::ClassName,
      sizeof(gfx::render::GfxTextureModulate),
      prv::hasSdlTypeNested<gfx::render::GfxTextureModulate>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxTextureModulate>::value
    },
    {
      gfx::render::GfxTextureFormats::ClassName,
      sizeof(gfx::render::GfxTextureFormats),
      prv::hasSdlTypeNested<gfx::render::GfxTextureFormats>::value,
      prv::hasSdlTypePtrNested<gfx::render::GfxTextureFormats>::value
    }  // 2017.06.02
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
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */

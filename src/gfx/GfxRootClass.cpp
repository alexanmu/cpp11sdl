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
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

#include "GfxBits.hpp"
#include "GfxBlendMode.hpp"
#include "GfxBool.hpp"
#include "GfxClipboard.hpp"
#include "GfxColor.hpp"
#include "GfxCpuInfo.hpp"
#include "GfxDisplayMode.hpp"
#include "GfxEndian.hpp"
#include "GfxError.hpp"
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
#include "GfxCanvasBgiData.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxBgiFontConstants.hpp"
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

namespace gfx
{

int32_t GfxRootClass::i32InstanceCounter_ = 0;

const struct GfxRootClass::stClassInfo GfxRootClass::astClassInfo[] =
{
    { gfx::GfxBits::ClassName, sizeof(gfx::GfxBits) },
    { gfx::GfxBlendMode::ClassName, sizeof(gfx::GfxBlendMode) },
    { gfx::GfxBool::ClassName, sizeof(gfx::GfxBool) },
    { gfx::GfxClipboard::ClassName, sizeof(gfx::GfxClipboard) },
    { gfx::GfxColor::ClassName, sizeof(gfx::GfxColor) },
    { gfx::GfxCpuInfo::ClassName, sizeof(gfx::GfxCpuInfo) },
    { gfx::GfxDisplayMode::ClassName, sizeof(gfx::GfxDisplayMode) },
    { gfx::GfxEndian::ClassName, sizeof(gfx::GfxEndian) },
    { gfx::GfxError::ClassName, sizeof(gfx::GfxError) },
    { gfx::GfxFileSystem::ClassName, sizeof(gfx::GfxFileSystem) },
    { gfx::GfxGetRendererInfo::ClassName, sizeof(gfx::GfxGetRendererInfo) },
    { gfx::GfxGetVersion::ClassName, sizeof(gfx::GfxGetVersion) },
    { gfx::GfxInitQuit::ClassName, sizeof(gfx::GfxInitQuit) },
    { gfx::GfxLoadSo::ClassName, sizeof(gfx::GfxLoadSo) },
    { gfx::GfxMessageBox::ClassName, sizeof(gfx::GfxMessageBox) },
    { gfx::GfxMessageBoxButtonData::ClassName, sizeof(gfx::GfxMessageBoxButtonData) },
    { gfx::GfxMessageBoxButtonFlags::ClassName, sizeof(gfx::GfxMessageBoxButtonFlags) },
    { gfx::GfxMessageBoxColor::ClassName, sizeof(gfx::GfxMessageBoxColor) },
    { gfx::GfxMessageBoxColorScheme::ClassName, sizeof(gfx::GfxMessageBoxColorScheme) },
    { gfx::GfxMessageBoxData::ClassName, sizeof(gfx::GfxMessageBoxData) },
    { gfx::GfxMessageBoxFlags::ClassName, sizeof(gfx::GfxMessageBoxFlags) },
    { gfx::pixels::GfxPalette::ClassName, sizeof(gfx::pixels::GfxPalette) },
    { gfx::pixels::GfxPixelFormat::ClassName, sizeof(gfx::pixels::GfxPixelFormat) },
    { gfx::GfxPlatform::ClassName, sizeof(gfx::GfxPlatform) },
    { gfx::GfxPoint::ClassName, sizeof(gfx::GfxPoint) },
    { gfx::GfxPowerInfo::ClassName, sizeof(gfx::GfxPowerInfo) },
    { gfx::GfxPowerState::ClassName, sizeof(gfx::GfxPowerState) },
    { gfx::GfxRect::ClassName, sizeof(gfx::GfxRect) },
    { gfx::GfxRenderer::ClassName, sizeof(gfx::GfxRenderer) },
    { gfx::GfxRendererFlags::ClassName, sizeof(gfx::GfxRendererFlags) },
    { gfx::GfxRendererFlip::ClassName, sizeof(gfx::GfxRendererFlip) },
    { gfx::GfxRendererInfo::ClassName, sizeof(gfx::GfxRendererInfo) },
    { gfx::GfxScreenSaver::ClassName, sizeof(gfx::GfxScreenSaver) },
    { gfx::GfxSurface::ClassName, sizeof(gfx::GfxSurface) },
    { gfx::GfxSurfaceFlags::ClassName, sizeof(gfx::GfxSurfaceFlags) },
    { gfx::GfxTexture::ClassName, sizeof(gfx::GfxTexture) },
    { gfx::GfxTextureAccess::ClassName, sizeof(gfx::GfxTextureAccess) },
    { gfx::GfxTextureModulate::ClassName, sizeof(gfx::GfxTextureModulate) },
    { gfx::GfxVersion::ClassName, sizeof(gfx::GfxVersion) },
    { gfx::GfxVideo::ClassName, sizeof(gfx::GfxVideo) },
    { gfx::GfxWindow::ClassName, sizeof(gfx::GfxWindow) },
    { gfx::GfxWindowEventID::ClassName, sizeof(gfx::GfxWindowEventID) },
    { gfx::GfxWindowFlags::ClassName, sizeof(gfx::GfxWindowFlags) },
    { gfx::GfxWindowPosition::ClassName, sizeof(gfx::GfxWindowPosition) },
    { gfx::bgi::GfxAngle::ClassName, sizeof(gfx::bgi::GfxAngle) },
    { gfx::bgi::fnt::GfxBitmapFont::ClassName, sizeof(gfx::bgi::fnt::GfxBitmapFont) },
    { gfx::bgi::GfxCanvas::ClassName, sizeof(gfx::bgi::GfxCanvas) },
    { gfx::bgi::GfxCanvasBgi::ClassName, sizeof(gfx::bgi::GfxCanvasBgi) },
    { gfx::bgi::GfxCanvasBgiData::ClassName, sizeof(gfx::bgi::GfxCanvasBgiData) },
    { gfx::bgi::GfxBgiConstants::ClassName, sizeof(gfx::bgi::GfxBgiConstants) },
    { gfx::bgi::fnt::GfxBgiFontConstants::ClassName, sizeof(gfx::bgi::fnt::GfxBgiFontConstants) },
    { gfx::bgi::GfxRadius::ClassName, sizeof(gfx::bgi::GfxRadius) },
    { gfx::bgi::GfxString::ClassName, sizeof(gfx::bgi::GfxString) },
    { gfx::GfxInitFlags::ClassName, sizeof(gfx::GfxInitFlags) },  // 2017.05.17
    { gfx::ttf::GfxTtfFont::ClassName, sizeof(gfx::ttf::GfxTtfFont) },  // 2017.05.17
    { gfx::ttf::GfxTtfInitQuit::ClassName, sizeof(gfx::ttf::GfxTtfInitQuit) },  // 2017.05.17
    { gfx::ttf::GfxTtfGetVersion::ClassName, sizeof(gfx::ttf::GfxTtfGetVersion) },  // 2017.05.18
    { gfx::ttf::GfxTtfFontStyle::ClassName, sizeof(gfx::ttf::GfxTtfFontStyle) },  // 2017.05.18
    { gfx::ttf::GfxTtfFontHinting::ClassName, sizeof(gfx::ttf::GfxTtfFontHinting) },  // 2017.05.18
    { gfx::ttf::GfxTtfFontRenderer::ClassName, sizeof(gfx::ttf::GfxTtfFontRenderer) },  // 2017.05.19
    { gfx::supp::GfxFontInfo::ClassName, sizeof(gfx::supp::GfxFontInfo) },  // 2017.05.19
    { gfx::supp::GfxControlledSurface::ClassName, sizeof(gfx::supp::GfxControlledSurface) },
    { gfx::pixels::GfxPixelType::ClassName, sizeof(gfx::pixels::GfxPixelType) }  // 2017.05.30
};

const int32_t GfxRootClass::i32ClassNamesCount = sizeof(GfxRootClass::astClassInfo) /
                                                sizeof(GfxRootClass::astClassInfo[0]);

GfxRootClass::GfxRootClass()
{
    GfxRootClass::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
    strClassName_ = "$init$";
}

GfxRootClass::GfxRootClass(const std::string& strClassName) : strClassName_(strClassName)
{
    assert(strClassName.length() > 0);

    GfxRootClass::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
}

GfxRootClass::GfxRootClass(const GfxRootClass& other)
{
    GfxRootClass::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
    strClassName_ = "$cpctor$" + other.strClassName_;
}

GfxRootClass::GfxRootClass(GfxRootClass&& other)
{
    GfxRootClass::i32InstanceCounter_ += 1;
    i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
    strClassName_ = "$mvctor$" + other.strClassName_;
    // Delete other's data
    other.i32InstanceId_ = -1;
    other.strClassName_ = "$null$";
}

GfxRootClass::~GfxRootClass()
{
    strClassName_ = "$null$";
    i32InstanceId_ = -1;
}

GfxRootClass& GfxRootClass::operator=(const GfxRootClass& other)
{
    if (this != &other)
    {
        GfxRootClass::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
        strClassName_ = "$cpoprt$" + other.strClassName_;
    }
    return *this;
}

GfxRootClass& GfxRootClass::operator=(GfxRootClass&& other)
{
    if (this != &other)
    {
        GfxRootClass::i32InstanceCounter_ += 1;
        i32InstanceId_ = GfxRootClass::i32InstanceCounter_;
        strClassName_ = "$mvoprt$" + other.strClassName_;
        // Delete other's data
        other.i32InstanceId_ = -1;
        other.strClassName_ = "$null$";
    }
    return *this;
}

bool GfxRootClass::operator==(const GfxRootClass& other) const
{
    return ((i32InstanceId_ == other.i32InstanceId_) && (strClassName_ == other.strClassName_));
}

GfxRootClass::operator bool() const
{
    return true;
}

std::string const& GfxRootClass::getClassName(void) const
{
    return strClassName_;
}

int32_t GfxRootClass::getInstanceId(void) const
{
    return i32InstanceId_;
}

}  // namespace gfx

/* EOF */

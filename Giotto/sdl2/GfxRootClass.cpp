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

namespace gfx
{

int GfxRootClass::intInstanceCounter_ = 0;

const char* GfxRootClass::astrClassNames[] =
{
    gfx::GfxBits::ClassName,
    gfx::GfxBlendMode::ClassName,
    gfx::GfxBool::ClassName,
    gfx::GfxClipboard::ClassName,
    gfx::GfxColor::ClassName,
    gfx::GfxCpuInfo::ClassName,
    gfx::GfxDisplayMode::ClassName,
    gfx::GfxEndian::ClassName,
    gfx::GfxError::ClassName,
    gfx::GfxFileSystem::ClassName,
    gfx::GfxGetRendererInfo::ClassName,
    gfx::GfxGetVersion::ClassName,
    gfx::GfxInitQuit::ClassName,
    gfx::GfxLoadSo::ClassName,
    gfx::GfxMessageBox::ClassName,
    gfx::GfxMessageBoxButtonData::ClassName,
    gfx::GfxMessageBoxButtonFlags::ClassName,
    gfx::GfxMessageBoxColor::ClassName,
    gfx::GfxMessageBoxColorScheme::ClassName,
    gfx::GfxMessageBoxData::ClassName,
    gfx::GfxMessageBoxFlags::ClassName,
    gfx::GfxPalette::ClassName,
    gfx::GfxPixelFormat::ClassName,
    gfx::GfxPlatform::ClassName,
    gfx::GfxPoint::ClassName,
    gfx::GfxPowerInfo::ClassName,
    gfx::GfxPowerState::ClassName,
    gfx::GfxRect::ClassName,
    gfx::GfxRenderer::ClassName,
    gfx::GfxRendererFlags::ClassName,
    gfx::GfxRendererFlip::ClassName,
    gfx::GfxRendererInfo::ClassName,
    gfx::GfxScreenSaver::ClassName,
    gfx::GfxSurface::ClassName,
    gfx::GfxSurfaceFlags::ClassName,
    gfx::GfxTexture::ClassName,
    gfx::GfxTextureAccess::ClassName,
    gfx::GfxTextureModulate::ClassName,
    gfx::GfxVersion::ClassName,
    gfx::GfxVideo::ClassName,
    gfx::GfxWindow::ClassName,
    gfx::GfxWindowEventID::ClassName,
    gfx::GfxWindowFlags::ClassName,
    gfx::GfxWindowPosition::ClassName,
    gfx::bgi::GfxAngle::ClassName,
    gfx::bgi::fnt::GfxBitmapFont::ClassName,
    gfx::bgi::GfxCanvas::ClassName,
    gfx::bgi::GfxCanvasBgi::ClassName,
    gfx::bgi::GfxCanvasBgiData::ClassName,
    gfx::bgi::GfxBgiConstants::ClassName,
    gfx::bgi::fnt::GfxBgiFontConstants::ClassName,
    gfx::bgi::GfxRadius::ClassName,
    gfx::bgi::GfxString::ClassName,
    gfx::GfxInitFlags::ClassName,  // 2017.05.17
    gfx::ttf::GfxTtfFont::ClassName,  // 2017.05.17
    gfx::ttf::GfxTtfInitQuit::ClassName    // 2017.05.17
};

const int GfxRootClass::intClassNamesCount = sizeof(GfxRootClass::astrClassNames) /
                                                sizeof(GfxRootClass::astrClassNames[0]);

GfxRootClass::GfxRootClass()
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$init$";
}

GfxRootClass::GfxRootClass(const std::string& strClassName) : strClassName_(strClassName)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
}

GfxRootClass::GfxRootClass(const GfxRootClass& other)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$cpctor$" + other.strClassName_;
}

GfxRootClass::GfxRootClass(GfxRootClass&& other)
{
    GfxRootClass::intInstanceCounter_ += 1;
    intInstanceId_ = GfxRootClass::intInstanceCounter_;
    strClassName_ = "$mvctor$" + other.strClassName_;
    // Delete other's data
    other.intInstanceId_ = -1;
    other.strClassName_ = "$null$";
}

GfxRootClass::~GfxRootClass()
{
    strClassName_ = "$null$";
    intInstanceId_ = -1;
}

GfxRootClass& GfxRootClass::operator=(const GfxRootClass& other)
{
    if (this != &other)
    {
        GfxRootClass::intInstanceCounter_ += 1;
        intInstanceId_ = GfxRootClass::intInstanceCounter_;
        strClassName_ = "$cpoprt$" + other.strClassName_;
    }
    return *this;
}

GfxRootClass& GfxRootClass::operator=(GfxRootClass&& other)
{
    if (this != &other)
    {
        GfxRootClass::intInstanceCounter_ += 1;
        intInstanceId_ = GfxRootClass::intInstanceCounter_;
        strClassName_ = "$mvoprt$" + other.strClassName_;
        // Delete other's data
        other.intInstanceId_ = -1;
        other.strClassName_ = "$null$";
    }
    return *this;
}

bool GfxRootClass::operator==(const GfxRootClass& other)
{
    return ((intInstanceId_ == other.intInstanceId_) && (strClassName_ == other.strClassName_));
}

std::string GfxRootClass::getClassName(void) const
{
    return strClassName_;
}

}  // namespace gfx

/* EOF */

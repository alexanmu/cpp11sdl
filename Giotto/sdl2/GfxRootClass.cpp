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
#include "GfxRadius.hpp"
#include "GfxString.hpp"

int GfxRootClass::intInstanceCounter_ = 0;

const std::string GfxRootClass::astrClassNames[] =
{
    GfxBits::ClassName,
    GfxBlendMode::ClassName,
    GfxBool::ClassName,
    GfxClipboard::ClassName,
    GfxColor::ClassName,
    GfxCpuInfo::ClassName,
    GfxDisplayMode::ClassName,
    GfxEndian::ClassName,
    GfxError::ClassName,
    GfxFileSystem::ClassName,
    GfxGetRendererInfo::ClassName,
    GfxGetVersion::ClassName,
    GfxInitQuit::ClassName,
    GfxLoadSo::ClassName,
    GfxMessageBox::ClassName,
    GfxMessageBoxButtonData::ClassName,
    GfxMessageBoxButtonFlags::ClassName,
    GfxMessageBoxColor::ClassName,
    GfxMessageBoxColorScheme::ClassName,
    GfxMessageBoxData::ClassName,
    GfxMessageBoxFlags::ClassName,
    GfxPalette::ClassName,
    GfxPixelFormat::ClassName,
    GfxPlatform::ClassName,
    GfxPoint::ClassName,
    GfxPowerInfo::ClassName,
    GfxPowerState::ClassName,
    GfxRect::ClassName,
    GfxRenderer::ClassName,
    GfxRendererFlags::ClassName,
    GfxRendererFlip::ClassName,
    GfxRendererInfo::ClassName,
    GfxScreenSaver::ClassName,
    GfxSurface::ClassName,
    GfxSurfaceFlags::ClassName,
    GfxTexture::ClassName,
    GfxTextureAccess::ClassName,
    GfxTextureModulate::ClassName,
    GfxVersion::ClassName,
    GfxVideo::ClassName,
    GfxWindow::ClassName,
    GfxWindowEventID::ClassName,
    GfxWindowFlags::ClassName,
    GfxWindowPosition::ClassName,
    bgi::GfxAngle::ClassName,
    bgi::GfxBitmapFont::ClassName,
    bgi::GfxCanvas::ClassName,
    bgi::GfxCanvasBgi::ClassName,
    bgi::GfxCanvasBgiData::ClassName,
    bgi::GfxBgiConstants::ClassName,
    bgi::GfxRadius::ClassName,
    bgi::GfxString::ClassName
};

const int GfxRootClass::intClassNamesCount = sizeof(GfxRootClass::astrClassNames) / sizeof(GfxRootClass::astrClassNames[0]);

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

/* EOF */

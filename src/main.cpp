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

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <memory>
#include <cstring>
#include <vector>

#include "GfxInitQuit.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GfxSurface.hpp"
#include "GfxTexture.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxCanvas.hpp"
#include "GfxMessageBox.hpp"
#include "GfxCpuInfo.hpp"
#include "GfxPlatform.hpp"
#include "GfxPowerInfo.hpp"
#include "GfxScreenSaver.hpp"
#include "GfxVideo.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxVersion.hpp"
#include "GfxGetVersion.hpp"
#include "GfxFileSystem.hpp"
#include "GfxBits.hpp"
#include "GfxClipboard.hpp"
#include "GfxEndian.hpp"
#include "GfxLoadSo.hpp"
#include "GfxGetError.hpp"
#include "GfxRendererInfo.hpp"
#include "GfxGetRendererInfo.hpp"
#include "GfxRendererFlags.hpp"
#include "GfxPalette.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxPixelFormatEnum.hpp"

#define WIN_W 1280
#define WIN_H 800
#define __base_path "data"

void at_exit_callback(void);

void MsgBox(gfx::video::GfxWindow const& win)
{
    gfx::platform::GfxPlatform plat;
    plat.queryPlatform();
    gfx::power::GfxPowerInfo pinfo;
    pinfo.queryPowerInfo();

    gfx::msgbox::GfxMessageBoxFlags flags { gfx::msgbox::GfxMessageBoxFlags::ValueType::flagInformation };
    std::string title = "Title";
    std::string message = pinfo.getAsString();
    int numbuttons = 4;
    std::string btn1 = "1 " + plat.getPlatform();
    gfx::msgbox::GfxMessageBoxButtonData buttons[4] {
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                    gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::noneDefault), 1, btn1),
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                    gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::escKeyDefault), 2, "Button2"),
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                    gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::returnKeyDefault), 3, "Button3"),
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                    gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::noneDefault), 4, "4 Test")
    };
    gfx::msgbox::GfxMessageBoxColor c[5] = {
        gfx::msgbox::GfxMessageBoxColor(255, 0, 0),
        gfx::msgbox::GfxMessageBoxColor(250, 220, 190),
        gfx::msgbox::GfxMessageBoxColor(192, 92, 9),
        gfx::msgbox::GfxMessageBoxColor(50, 100, 200),
        gfx::msgbox::GfxMessageBoxColor(255, 255, 255)
    };
    gfx::msgbox::GfxMessageBoxColorScheme colorScheme(c);
    colorScheme.setColor(gfx::msgbox::GfxMessageBoxColorType(
                            gfx::msgbox::GfxMessageBoxColorType::ValueType::colorBackground),
                         gfx::msgbox::GfxMessageBoxColor(
                                            gfx::bgi::kColorDarkGray().getRed(),
                                            gfx::bgi::kColorDarkGray().getGreen(),
                                            gfx::bgi::kColorDarkGray().getBlue()));

    gfx::msgbox::GfxMessageBoxData m(flags, const_cast<gfx::video::GfxWindow *>(&win), title, message, numbuttons,
                                        buttons, colorScheme);
    // GfxMessageBoxData m(flags,win,title,message,numbuttons,buttons);

    gfx::msgbox::GfxMessageBox g(m);
    int r = g.showModal();

    std::string rez;

    gfx::bits::GfxBits b;
    rez = "R=" + std::to_string((b.mostSignificantBitIndex32(r) << 8) | (r & 0x00FF));

    gfx::cpuinfo::GfxCpuInfo cinfo;
    cinfo.queryCpuInfo();
    gfx::msgbox::GfxMessageBox k(gfx::msgbox::GfxMessageBoxFlags(gfx::msgbox::GfxMessageBoxFlags::ValueType::flagError),
                         rez, cinfo.getAsString(), win);
    k.showModal();

    gfx::clipboard::GfxClipboard clipb;
    clipb.setClipboardText(cinfo.getAsString());
}

void BeforeInit(void)
{
    std::cout << "BeforeInit()" << std::endl;

    gfx::video::GfxVideo v;

    std::cout << "v.getNumVideoDrivers()=" << v.getNumVideoDrivers() << '\n';
    for (int i = 0; i < v.getNumVideoDrivers(); i++)
    {
        std::cout << "v.getVideoDriver(i)=" << v.getVideoDriver(i) << '\n';
    }
    gfx::version::GfxGetVersion gv;
    gfx::version::GfxVersion ver;

    gv.getVersion(&ver);
    std::cout << "ver.getAsString()=" << ver.getAsString() << '\n';
    std::cout << "gv.getRevision()=" << gv.getRevision() << '\n';
    std::cout << "gv.getRevisionNumber()=" << gv.getRevisionNumber() << '\n';

    gfx::filesystem::GfxFileSystem fs;

    std::cout << "fs.getBasePath()=" << fs.getBasePath() << '\n';
    std::cout << std::endl;
}

void AfterInit(void)
{
    std::cout << "AfterInit()" << std::endl;

    gfx::video::GfxVideo v;

    std::cout << "v.getCurrentVideoDriver()=" << v.getCurrentVideoDriver() << '\n';
    std::cout << "v.getNumVideoDisplays()=" << v.getNumVideoDisplays() << '\n';
    for (int i = 0; i < v.getNumVideoDisplays(); i++)
    {
        std::cout << "v.getDisplayName(i)=" << v.getDisplayName(i) << '\n';
        float d, h, v1;
        v.getDisplayDPI(i, &d, &h, &v1);
        std::cout << "v.getDisplayDPI(i).ddpi=" << d << '\n';
        std::cout << "v.getNumDisplayModes(i)=" << v.getNumDisplayModes(i) << '\n';
        std::unique_ptr<gfx::video::GfxDisplayMode> dm = v.getCurrentDisplayMode(i);
        std::cout << "dm.get()->getFormat()=" << "0x" << std::uppercase << std::setfill('0') <<
                    std::setw(8) << std::hex << dm.get()->getFormat() << std::dec << '\n';
        std::cout << "dm.get()->getFormat()=" << dm.get()->getFormat() << '\n';
        std::cout << "dm.get()->getWidth()=" << dm.get()->getWidth() << '\n';
        std::cout << "dm.get()->getHeight()=" << dm.get()->getHeight() << '\n';
        std::cout << "dm.get()->getRefreshRate()=" << dm.get()->getRefreshRate() << "Hz" << '\n';

        gfx::endian::GfxEndian e;

        std::cout << "e.swapFloatBE(d)=" << e.swapFloatBE(d) << '\n';
    }
    gfx::render::GfxGetRendererInfo gri;
    gfx::render::GfxRendererInfo * ri = nullptr;

    std::cout << "gri.getNumRenderDrivers()=" << gri.getNumRenderDrivers() << '\n';
    for (int i = 0; i < gri.getNumRenderDrivers(); i++)
    {
        ri = gri.getRenderDriverInfo(i);
        std::cout << "ri.getName()=" << ri->getName() << '\n';
        std::cout << "ri.getFlags()=" << ri->getFlags().getAsSdlType() << '\n';
        std::cout << "ri.getMaxTextureWidth()=" << ri->getMaxTextureWidth() << '\n';
        std::cout << "ri.getMaxTextureHeight()=" << ri->getMaxTextureHeight() << '\n';
        std::cout << "ri.getNumTextureFormats()=" << ri->getNumTextureFormats() << '\n';
        for (uint32_t j = 0; j < ri->getNumTextureFormats(); j++)
        {
            std::cout << "ri.getTextureFormats()[j]=" << ri->getTextureFormats()[j] << '\n';
        }
        gfx::render::GfxRendererFlags rf = ri->getFlags();
        std::cout << "rf.isUnknown()=" << rf.isUnknown() << '\n';
        std::cout << "rf.isSoftware()=" << rf.isSoftware() << '\n';
        std::cout << "rf.isAccelerated()=" << rf.isAccelerated() << '\n';
        std::cout << "rf.getPresentVSync()=" << rf.getPresentVSync() << '\n';
        std::cout << "rf.getTargetTexture()=" << rf.getTargetTexture() << '\n';
    }
    delete ri;
    std::cout << std::endl;
}

void AfterDeInit(void)
{
    std::cout << "AfterDeInit()" << std::endl;

    // We expect this to fail
    gfx::loadso::GfxLoadSo lso("whatever.so");
    void * f;

    f = lso.loadFunction("whatever_function");
    if (f == nullptr)
    {
        std::cout << "lso.loadFunction(\"whatever_function\")=" << "nullptr" << '\n';
        std::cout << "err.getError()=" << gfx::error::GfxGetError::getErrorObject().get() << '\n';
    }
    std::cout << std::endl;
}

void bmpSurfaceInfo(gfx::surface::GfxSurface* bmps)
{
    gfx::pixels::GfxPixelFormat fmt;
    gfx::pixels::GfxPixelFormatEnum fmten;
    std::vector<gfx::pixels::GfxColor> vec;
    int32_t bpp;
    uint32_t redMask;
    uint32_t greenMask;
    uint32_t blueMask;
    uint32_t alphaMask;

    fmten = bmps->getPixelFormat();
    fmt = gfx::pixels::GfxPixelFormat(fmten);
    std::cout << "fmt->getFormat()=" << fmt.getFormat().getAsSdlType() << '\n';
    // palette goes here
    std::cout << "fmt->getBitsPerPixel()=" << static_cast<int>(fmt.bitsPerPixel()) << '\n';
    std::cout << "fmt->getBytesPerPixel()=" << static_cast<int>(fmt.bytesPerPixel()) << '\n';
    fmt.pixelFormatEnumToMasks(&bpp, &redMask, &greenMask, &blueMask, &alphaMask);
    std::cout << "fmt->getRmask()=" << redMask << '\n';
    std::cout << "fmt->getGmask()=" << greenMask << '\n';
    std::cout << "fmt->getBmask()=" << blueMask<< '\n';
    std::cout << "fmt->getAmask()=" << alphaMask << '\n';
}

void inc(int* a)
{
    if ((*a + 4) > 255)
    {
        *a = 255;
    }
    else
    {
        *a += 4;
    }
}

void dec(int* a)
{
    if ((*a - 4) < 0)
    {
        *a = 0;
    }
    else
    {
        *a -= 4;
    }
}

void _doStuff(void)
{
    BeforeInit();
    gfx::initquit::GfxInitFlags iflags;

    iflags.setVideo();
    iflags.setEvents();
    gfx::initquit::GfxInitQuit iq(iflags);
    AfterInit();
    std::cout << "_doStuff()" << std::endl;
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init failed\n";
        return;
    }
    gfx::video::GfxWindowFlags wf(gfx::video::GfxWindowFlags::ValueType::windowFlagResizable);
    gfx::video::GfxWindow win("Window title",
                        gfx::video::GfxWindowPosition(gfx::video::GfxWindowPosition::ValueType::positionCentered),
                        gfx::video::GfxWindowPosition(gfx::video::GfxWindowPosition::ValueType::positionCentered),
                        WIN_W,
                        WIN_H,
                        wf);
    MsgBox(win);

    gfx::render::GfxRendererFlags rflags;
    rflags.setSoftware();
    gfx::render::GfxRenderer rend(win, rflags);

    gfx::render::GfxRendererInfo * ri;
    ri = rend.getRendererInfo();
    std::cout << "ri.getName()=" << ri->getName() << '\n';
    std::cout << "ri.getFlags()=" << ri->getFlags().getAsSdlType() << '\n';
    std::cout << "ri.getMaxTextureWidth()=" << ri->getMaxTextureWidth() << '\n';
    std::cout << "ri.getMaxTextureHeight()=" << ri->getMaxTextureHeight() << '\n';
    std::cout << "ri.getNumTextureFormats()=" << ri->getNumTextureFormats() << '\n';

    if (ri->getNumTextureFormats() > 0)
    {
        gfx::render::GfxTextureFormats gtf;

        gtf = ri->getTextureFormats();
        for (uint32_t i = 0; i < ri->getNumTextureFormats(); i++)
        {
            gfx::pixels::GfxPixelFormat gpf { gfx::pixels::GfxPixelFormatEnum(gtf[i]) };
            std::cout << "gpf.getPixelFormatName()=" << gpf.getPixelFormatName() << '\n';
        }
    }
    delete ri;

    gfx::surface::GfxSurface sbitmap("sbitmap", std::string(__base_path) + std::string("/Image2.bmp"));
    bmpSurfaceInfo(&sbitmap);

    gfx::surface::GfxSurface surfcanvas("surfcanvas", gfx::surface::GfxSurfaceFlags(), WIN_W, WIN_H, 32,
                                        gfx::pixels::GfxPixelFormatEnum(
                                                gfx::pixels::GfxPixelFormatEnum::ValueType::pixelFormatARGB8888));

    int32_t c = 0;
    for (int32_t i = 0; i < WIN_W; i++)
    {
        for (int32_t j = 480; j < WIN_H; j++)
        {
            surfcanvas.putPixel(i, j, gfx::bgi::kGetColorByIndex(
                        static_cast<gfx::bgi::GfxColorIndex>(c)));
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == gfx::bgi::kNumColors) c = 0;
        }
    }

    gfx::bgi::GfxCanvas cv(surfcanvas);
    // Circle
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::green));
    cv.Circle(gfx::rect::GfxPoint(480, 240), gfx::bgi::GfxRadius(230));
    // Arc
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::red));
    cv.Arc(gfx::rect::GfxPoint(480, 240), gfx::bgi::GfxAngle(60), gfx::bgi::GfxAngle(300),
           gfx::bgi::GfxRadius(239));
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::pixels::GfxColor(50, 100, 200).getColor()));
    cv.OutTextXY(gfx::rect::GfxPoint(360, 232), gfx::bgi::GfxText("SDL_bgi"));
    // Bar
    cv.SetFillStyle(gfx::bgi::GfxFillStyles(), gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::lightMagenta));
    cv.Bar(gfx::rect::GfxPoint(480, 0), gfx::rect::GfxPoint(960, 240));
    // Bar
    cv.SetFillStyle(gfx::bgi::GfxFillStyles(), gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::red));
    cv.Bar(gfx::rect::GfxRect(10, 10, 20, 20));
    // Rectangle
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::green));
    cv.Rectangle(gfx::rect::GfxPoint(20, 20), gfx::rect::GfxPoint(30, 30));
    // Rectangle
    cv.SetColor(gfx::bgi::GfxColors2(gfx::pixels::GfxColor(128, 128, 128).getColor()));
    cv.Rectangle(gfx::rect::GfxRect(30, 30, 40, 40));
    // Line
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::yellow));
    cv.Line(gfx::rect::GfxPoint(10, 10), gfx::rect::GfxPoint(40, 40));
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::pixels::GfxColor(150, 100, 200).getColor()));
    cv.OutTextXY(gfx::rect::GfxPoint(50, 50),
               gfx::bgi::GfxText("The quick brown fox jumped over the lazy dog 0123456789!"));

    std::string fontMsg = "The quick brown fox jumped over the laxy dog 0123456789!";
    for (int32_t i = 0; i < gfx::bgi::fnt::kNumFonts; i++)
    {
        int32_t x = 30;
        int32_t y = 60 + i * 16;
        int32_t r = 210 - i * 10;
        int32_t g = 200 + i * 5;
        int32_t b = 20 + i * 10;
        cv.SetColor(gfx::bgi::GfxColors2(gfx::pixels::GfxColor(r, g, b).getColor()));
        cv.OutTextXY(gfx::rect::GfxPoint(x, y), gfx::bgi::GfxText(fontMsg),
                     gfx::bgi::fnt::kGetFontByIndex(
                                                    static_cast<gfx::bgi::fnt::GfxFontIndex>(i)));
    }

    // Bar
    cv.SetFillStyle(gfx::bgi::GfxFillStyles(), gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::lightGray));
    cv.Bar(gfx::rect::GfxPoint(600, 100), gfx::rect::GfxPoint(800, 200));
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::white));
    cv.OutTextXY(gfx::rect::GfxPoint(620, 120), gfx::bgi::GfxText("3D Text, custom font"),
                 gfx::bgi::fnt::kFontScript());
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::black));
    cv.OutTextXY(gfx::rect::GfxPoint(621, 121), gfx::bgi::GfxText("3D Text, custom font"),
                 gfx::bgi::fnt::kFontScript());
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::white));
    cv.OutTextXY(gfx::rect::GfxPoint(620, 140), gfx::bgi::GfxText("3D Text, SDL_bgi font"));
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::black));
    cv.OutTextXY(gfx::rect::GfxPoint(621, 141), gfx::bgi::GfxText("3D Text, SDL_bgi font"));

    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::green));
    cv.OutTextXY(gfx::rect::GfxPoint(1010, 120), gfx::bgi::GfxText("WIN_W=" + std::to_string(WIN_W)),
                 gfx::bgi::fnt::kFontAntique());
    // OutTextXY
    cv.SetColor(gfx::bgi::GfxColors2(gfx::bgi::GfxColors2::lightGray));
    cv.OutTextXY(gfx::rect::GfxPoint(1010, 150), gfx::bgi::GfxText("WIN_H=" + std::to_string(WIN_H)),
                 gfx::bgi::fnt::kFontWacky());
    c = 0;
    for (int32_t i = 0; i < WIN_W; i++)
    {
        for (int32_t j = 240; j < 480; j++)
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;

            r = gfx::bgi::kGetColorByIndex(
                    static_cast<gfx::bgi::GfxColorIndex>(c)).getRed();
            g = gfx::bgi::kGetColorByIndex(
                    static_cast<gfx::bgi::GfxColorIndex>(c)).getGreen();
            b = gfx::bgi::kGetColorByIndex(
                    static_cast<gfx::bgi::GfxColorIndex>(c)).getBlue();
            gfx::bgi::GfxColors2 c = gfx::bgi::GfxColors2(gfx::pixels::GfxColor(r, g, b, 224).getColor());
            cv.PutPixel(gfx::rect::GfxPoint(i, j), c);
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == gfx::bgi::kNumColors) c = 0;
        }
    }

    gfx::surface::GfxSurface colors_surf("colors_surf", gfx::surface::GfxSurfaceFlags(), WIN_W, WIN_H, 32,
                                         gfx::pixels::GfxPixelFormatEnum(
                                            gfx::pixels::GfxPixelFormatEnum::ValueType::pixelFormatARGB8888));
    gfx::rect::GfxRect rt;

    gfx::sdl2::SDL_Event e;
    bool quit = false;
    int32_t r1 = gfx::bgi::kColorDarkGray().getRed();
    int32_t g1 = gfx::bgi::kColorDarkGray().getGreen();
    int32_t b1 = gfx::bgi::kColorDarkGray().getBlue();
    int32_t a1 = 0;

    gfx::video::GfxScreenSaver ss;
    if (ss.isScreenSaverEnabled() == false)
    {
        ss.enableScreenSaver();
    }
    std::srand(static_cast<unsigned int>(time(0)));
    while (!quit)
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == gfx::sdl2::SDL_QUIT)
                quit = true;
            if (e.type == gfx::sdl2::SDL_KEYDOWN) {
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_Q)
                    inc(&r1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_A)
                    dec(&r1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_W)
                    inc(&g1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_S)
                    dec(&g1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_E)
                    inc(&b1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_D)
                    dec(&b1);
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_Z)
                { r1 = 0; g1 = 0; b1 = 0; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_X)
                { r1 = 128; g1 = 128; b1 = 128; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_C)
                { r1 = 255; g1 = 255; b1 = 255; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_K)
                { r1 = 137; g1 = 6; b1 = 71; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_U)
                { r1 = 113; g1 = 194; b1 = 4; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_O)
                { r1 = 237; g1 = 249; b1 = 75; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_M)
                { r1 = 128; g1 = 64; b1 = 128; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_N)
                {
                    r1 = std::rand() % 255;
                    g1 = std::rand() % 255;
                    b1 = std::rand() % 255;
                }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_H)
                { r1 = 128; g1 = 138; b1 = 43; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_I)
                { r1 = 42; g1 = 0; b1 = 46; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_T)
                { r1 = 125; g1 = 251; b1 = 1; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_J)
                { r1 = 42; g1 = 0; b1 = 46; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_Y)
                { r1 = 156; g1 = 54; b1 = 78; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_P)
                { r1 = 50; g1 = 100; b1 = 200; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_1)
                { inc(&a1); }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_2)
                { dec(&a1); }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_L)
                { r1 = 208; g1 = 8; b1 = 232; }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_8)
                { inc(&r1); inc(&g1); inc(&b1); }
                if (e.key.keysym.scancode == gfx::sdl2::SDL_SCANCODE_9)
                { dec(&r1); dec(&g1); dec(&b1); }
            }

            int rp = r1 * 100 / 255;
            int gp = g1 * 100 / 255;
            int bp = b1 * 100 / 255;
            std::string str_title;

            str_title = "[R(" + std::to_string(r1) + ")";
            for (int i = 0; i < rp / 10; i++)
            {
                str_title += "=";
            }
            for (int i = rp / 10; i < 10; i++)
            {
                str_title += ".";
            }
            str_title += "][G(" + std::to_string(g1) + ")";
            for (int i = 0; i < gp / 10; i++)
            {
                str_title += "=";
            }
            for (int i = gp / 10; i < 10; i++)
            {
                str_title += ".";
            }
            str_title += "][B(" + std::to_string(b1) + ")";
            for (int i = 0; i < bp / 10; i++)
            {
                str_title += "=";
            }
            for (int i = bp / 10; i < 10; i++)
            {
                str_title += ".";
            }
            str_title += "][A(" + std::to_string(a1) +")]";
            win.setWindowTitle(str_title);
            surfcanvas.blitSurface(sbitmap, gfx::rect::GfxRect(0, 0, sbitmap.getWidth(), sbitmap.getHeight()),
                                   gfx::rect::GfxRect(160, 640, WIN_W, WIN_H));
            gfx::render::GfxTexture canvas_tex(&rend, surfcanvas);
            canvas_tex.setBlendMode(gfx::blendmode::GfxBlendMode::ValueType::blendNone);

            rt.setX(0);
            rt.setY(0);
            rt.setWidth(WIN_W);
            rt.setHeight(480);
            colors_surf.fillRect(rt, gfx::pixels::GfxColor(r1, g1, b1, a1));
            rt.setX(WIN_W / 2);
            colors_surf.fillRect(rt, gfx::pixels::GfxColor(255-r1, 255-g1, 255-b1, a1));

            gfx::render::GfxTexture colors_tex(&rend, colors_surf);
            colors_tex.setBlendMode(gfx::blendmode::GfxBlendMode::ValueType::blendBlend);

            rend.renderCopy(canvas_tex);
            rend.renderCopy(colors_tex);
            rend.renderPresent();
        }
        gfx::sdl2::SDL_Delay(25);
    }
    sbitmap.~GfxSurface();  // This call should not be made explicitly. Results in a second call
                            // to ~GfxSurface() when variable sbitmap goes out of scope.
    AfterDeInit();
    // register exit handler
    std::atexit(at_exit_callback);
}

void _doPlay(void)
{
    std::cout << "Moved to play!" << std::endl;
}

#include "GApplication.hpp"
#include "GDemoForm.hpp"

void _doGApp(void)
{
    gto::gobj::GApplication gApp(GVarName(gApp));
    GDemoForm * demoForm = new GDemoForm("GDemoForm");

    gApp.setMainForm(demoForm);
    gApp.loadAppConfiguration();
    gApp.run();

    delete demoForm;
    // register exit handler
    std::atexit(at_exit_callback);
}

void at_exit_callback(void)
{
    // print runtime meta-info
    gfx::_gfx::GfxRuntimeMeta::getInstance().printToStream(std::cout) << std::endl;
}

int main(int argc, const char * argv[])
{
    int action = 0;

    if (argc == 2)
    {
        if (std::strcmp(argv[1], "play") == 0)
        {
            action = 0;
        }
        if (std::strcmp(argv[1], "sdl") == 0)
        {
            action = 1;
        }
        if (std::strcmp(argv[1], "giotto") == 0)
        {
            action = 2;
        }
    }

    switch (action)
    {
        case 0:
            _doPlay();
            break;
        case 1:
            _doStuff();
            break;
        case 2:
            _doGApp();
            break;
        default:
            break;
    }
    return 0;
}

/* EOF */

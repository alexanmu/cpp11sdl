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

#include "GfxInitQuit.hpp"
#include "Playground.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GfxSurface.hpp"
#include "GfxTexture.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxCanvas.hpp"
#include "platform/Linux.h"
#include "platform/macOS.h"
#include "platform/Windows.h"
#include "GfxMessageBox.hpp"
#include "GfxCpuInfo.hpp"
#include "GfxPlatform.hpp"
#include "GfxPowerInfo.hpp"
#include "GfxScreenSaver.hpp"
#include "GfxVideo.hpp"

void MsgBox(GfxWindow const& win)
{
    GfxPlatform plat;
    plat.queryPlatform();
    GfxPowerInfo pinfo;
    pinfo.queryPowerInfo();

    GfxMessageBoxFlags flags { GfxMessageBoxFlags::GfxMessageBoxFlagsValues::flagInformation };
    std::string title = "Title";
    std::string message = pinfo.getAsString();
    int numbuttons = 4;
    GfxMessageBoxButtonData buttons[4] = {
        {GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::noneDefault,1,plat.getPlatform()},
        {GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::escKeyDefault,2,"Button2"},
        {GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::returnKeyDefault,3,"Button3"},
        {GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::returnKeyDefault,3,"Test"}
    };
    GfxMessageBoxColor c[5] = { {255,0,0}, {250,220,190}, {192,92,9}, {50,100,200}, {255,255,255} };
    GfxMessageBoxColorScheme colorScheme(c);

    GfxMessageBoxData m(flags,win,title,message,numbuttons,buttons,colorScheme);
    //GfxMessageBoxData m(flags,win,title,message,numbuttons,buttons);

    GfxMessageBox g(m);
    int r = g.showModal();

    std::string rez;

    rez = "R=" + std::to_string(r);
    /*SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             rez.c_str(),
                             "File is missing. Please reinstall the program.",
                             NULL);*/
    GfxCpuInfo cinfo;
    cinfo.queryCpuInfo();
    GfxMessageBox k(GfxMessageBoxFlags(GfxMessageBoxFlags::GfxMessageBoxFlagsValues::flagError),
                    rez,cinfo.getAsString(),win);
    k.showModal();
}

void BeforeInit(void)
{
    GfxVideo v;

    std::cout << "v.getNumVideoDrivers()=" << v.getNumVideoDrivers() << '\n';
    for(int i = 0; i < v.getNumVideoDrivers(); i++)
    {
        std::cout << "v.getVideoDriver(i)=" << v.getVideoDriver(i) << '\n';
    }
}

void AfterInit(void)
{
    GfxVideo v;

    std::cout << "v.getCurrentVideoDriver()=" << v.getCurrentVideoDriver() << '\n';
    std::cout << "v.getNumVideoDisplays()=" << v.getNumVideoDisplays() << '\n';
    for(int i = 0; i < v.getNumVideoDisplays(); i++)
    {
        std::cout << "v.getDisplayName(i)=" << v.getDisplayName(i) << '\n';
        float d,h,v1;
        v.getDisplayDPI(i,&d,&h,&v1);
        std::cout << "v.getDisplayDPI(i).ddpi=" << d << '\n';
        std::cout << "v.getNumDisplayModes(i)=" << v.getNumDisplayModes(i) << '\n';
        std::unique_ptr<GfxDisplayMode> dm = v.getCurrentDisplayMode(i);
        std::cout << "dm.get()->getFormat()=" << std::hex << dm.get()->getFormat() << std::dec << '\n';
        std::cout << "dm.get()->getWidth()=" << dm.get()->getWidth() << '\n';
        std::cout << "dm.get()->getHeight()=" << dm.get()->getHeight() << '\n';
        std::cout << "dm.get()->getRefreshRate()=" << dm.get()->getRefreshRate() << "Hz" << '\n';
    }
    std::cout << std::endl;
}

void inc(int* a)
{
    if ((*a + 4) > 255) *a = 255;
    else *a += 4;
}

void dec(int* a)
{
    if((*a - 4) < 0) *a = 0;
    else *a -= 4;
}

void _doStuff(void)
{
    BeforeInit();
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    AfterInit();
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init failed\n";
        return;
    }
    GfxWindow w("Window title",WIN_W,WIN_H);
    MsgBox(w);
    GfxRenderer r(w);
    GfxSurface sbi(std::string(__base_path) + std::string("/Image2.bmp"));

    GfxSurface sb(WIN_W,WIN_H);

    int c = 0;
    for(int i = 0; i < WIN_W; i++)
    {
        for (int j = 480; j < WIN_H; j++)
        {
            sb.putPixel(i,j,GfxBgiConstants::vgaGetColorByIndex(static_cast<GfxBgiConstants::GfxVga16ColorIndex>(c)));
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == GfxBgiConstants::vgaNumColors) c = 0;
        }
    }

    GfxCanvas cv(sb);
    cv.Circle(GfxPoint(480,240),GfxRadius(230),GfxBgiConstants::vgaGreen());
    auto color = GfxBgiConstants::vgaRed();
    cv.Arc(GfxPoint(480,240),GfxAngle(60),GfxAngle(300),GfxRadius(239),color);
    cv.OutText(GfxPoint(360,232),GfxString("SDL_bgi"),GfxColor(50,100,200));
    cv.Bar(GfxPoint(480,0),GfxPoint(960,240),GfxBgiConstants::vgaLightRed());
    cv.Bar(GfxRect(10,10,20,20),GfxBgiConstants::vgaRed());
    cv.Rect(GfxPoint(20,20),GfxPoint(30,30),GfxBgiConstants::vgaGreen());
    cv.Rect(GfxRect(30,30,40,40),GfxColor(128,128,128));
    cv.Line(GfxPoint(10,10),GfxPoint(40,40),GfxBgiConstants::vgaYellow());
    cv.OutText(GfxPoint(50,50),GfxString("The quick brown fox jumped over the lazy dog 0123456789!"),GfxColor(150,100,200));

    std::string fontMsg = "The quick brown fox jumped over the laxy dog 0123456789!";
    for( int i = 0; i < GfxBgiConstants::fntNumFonts; i++)
    {
        int x = 30;
        int y = 60 + i * 16;
        int r = 210 - i * 10;
        int g = 200 + i * 5;
        int b = 20 + i * 10;
        cv.OutText(GfxPoint(x,y),GfxString(fontMsg),
                    GfxColor(r,g,b),GfxBgiConstants::fntGetFontByIndex(static_cast<GfxBgiConstants::GfxFontIndex>(i)));
    }


    cv.Bar(GfxPoint(600,100),GfxPoint(800,200),GfxBgiConstants::vgaLightGray());
    cv.OutText(GfxPoint(620,120),GfxString("3D Text, custom font"),GfxBgiConstants::vgaWhite(),GfxBgiConstants::fntScript());
    cv.OutText(GfxPoint(621,121),GfxString("3D Text, custom font"),GfxBgiConstants::vgaBlack(),GfxBgiConstants::fntScript());
    cv.OutText(GfxPoint(620,140),GfxString("3D Text, SDL_bgi font"),GfxBgiConstants::vgaWhite());
    cv.OutText(GfxPoint(621,141),GfxString("3D Text, SDL_bgi font"),GfxBgiConstants::vgaBlack());


    c = 0;
    for(int i = 0; i < WIN_W; i++)
    {
        for (int j = 240; j < 480; j++)
        {
            cv.PutPixel(GfxPoint(i,j),GfxBgiConstants::vgaGetColorByIndex(static_cast<GfxBgiConstants::GfxVga16ColorIndex>(c)));
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == GfxBgiConstants::vgaNumColors) c = 0;
        }
    }

    GfxSurface s(WIN_W,WIN_H);
    GfxRect rt;

    SDL_Event e;
    bool quit = false;
    int r1 = GfxBgiConstants::vgaDarkGray().getRed();
    int g1 = GfxBgiConstants::vgaDarkGray().getGreen();
    int b1 = GfxBgiConstants::vgaDarkGray().getBlue();
    int a1 = 0;

    GfxScreenSaver ss;
    if (ss.isScreenSaverEnabled() == false)
    {
        ss.enableScreenSaver();
    }
    std::srand(static_cast<unsigned int>(time(0)));
    while(!quit)
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.scancode == SDL_SCANCODE_Q)
                    inc(&r1);
                if (e.key.keysym.scancode == SDL_SCANCODE_A)
                    dec(&r1);
                if (e.key.keysym.scancode == SDL_SCANCODE_W)
                    inc(&g1);
                if (e.key.keysym.scancode == SDL_SCANCODE_S)
                    dec(&g1);
                if (e.key.keysym.scancode == SDL_SCANCODE_E)
                    inc(&b1);
                if (e.key.keysym.scancode == SDL_SCANCODE_D)
                    dec(&b1);
                if (e.key.keysym.scancode == SDL_SCANCODE_Z)
                { r1 = 0; g1 = 0; b1 = 0; }
                if (e.key.keysym.scancode == SDL_SCANCODE_X)
                { r1 = 128; g1 = 128; b1 = 128; }
                if (e.key.keysym.scancode == SDL_SCANCODE_C)
                { r1 = 255; g1 = 255; b1 = 255; }
                if (e.key.keysym.scancode == SDL_SCANCODE_K)
                { r1 = 137; g1 = 6; b1 = 71; }
                if (e.key.keysym.scancode == SDL_SCANCODE_U)
                { r1 = 113; g1 = 194; b1 = 4; }
                if (e.key.keysym.scancode == SDL_SCANCODE_O)
                { r1 = 237; g1 = 249; b1 = 75; }
                if (e.key.keysym.scancode == SDL_SCANCODE_M)
                { r1 = 128; g1 = 64; b1 = 128; }
                if (e.key.keysym.scancode == SDL_SCANCODE_N)
                { r1 = std::rand() % 255; g1 = std::rand() % 255; b1 = std::rand() % 255; }
                if (e.key.keysym.scancode == SDL_SCANCODE_H)
                { r1 = 128; g1 = 138; b1 = 43; }
                if (e.key.keysym.scancode == SDL_SCANCODE_I)
                { r1 = 42; g1 = 0; b1 = 46; }
                if (e.key.keysym.scancode == SDL_SCANCODE_T)
                { r1 = 125; g1 = 251; b1 = 1; }
                if (e.key.keysym.scancode == SDL_SCANCODE_J)
                { r1 = 42; g1 = 0; b1 = 46; }
                if (e.key.keysym.scancode == SDL_SCANCODE_Y)
                { r1 = 156; g1 = 54; b1 = 78; }
                if (e.key.keysym.scancode == SDL_SCANCODE_P)
                { r1 = 50; g1 = 100; b1 = 200; }
                if (e.key.keysym.scancode == SDL_SCANCODE_1)
                { inc(&a1); }
                if (e.key.keysym.scancode == SDL_SCANCODE_2)
                { dec(&a1); }
                if (e.key.keysym.scancode == SDL_SCANCODE_L)
                { r1 = 208; g1 = 8; b1 = 232; }
                if (e.key.keysym.scancode == SDL_SCANCODE_8)
                { inc(&r1); inc(&g1); inc(&b1); }
                if (e.key.keysym.scancode == SDL_SCANCODE_9)
                { dec(&r1); dec(&g1); dec(&b1); }
            }

            int rp = r1 * 100 / 255;
            int gp = g1 * 100 / 255;
            int bp = b1 * 100 / 255;
            std::string s2;

            s2 = "[R(" + std::to_string(r1) + ")";
            for(int i = 0; i < rp / 10; i++)
            {
                s2 += "=";
            }
            for(int i = rp / 10; i < 10; i++)
            {
                s2 += ".";
            }
            s2 += "][G(" + std::to_string(g1) + ")";
            for(int i = 0; i < gp / 10; i++)
            {
                s2 += "=";
            }
            for(int i = gp / 10; i < 10; i++)
            {
                s2 += ".";
            }
            s2 += "][B(" + std::to_string(b1) + ")";
            for(int i = 0; i < bp / 10; i++)
            {
                s2 += "=";
            }
            for(int i = bp / 10; i < 10; i++)
            {
                s2 += ".";
            }
            s2 += "][A(" + std::to_string(a1) +")]";
            w.setTitle(s2);
            GfxTexture tb(&r,sb);
            tb.setBlendMode(GfxBlendMode::GfxBlendModeValues::blendNone);

            rt.setX(0);
            rt.setY(0);
            rt.setWidth(WIN_W);
            rt.setHeight(480);
            s.fillRect(rt,GfxColor(r1,g1,b1,a1));
            rt.setX(480);
            s.fillRect(rt,GfxColor(255-r1,255-g1,255-b1,a1));

            GfxTexture t(&r,s);
            t.setBlendMode(GfxBlendMode::GfxBlendModeValues::blendBlend);

            r.renderCopy(tb);
            r.renderCopy(t);
            r.renderPresent();
        }
        SDL_Delay(25);
    }

}

#ifdef __windows_machine
int WinMain(int argc, const char * argv[])
#else
int main(int argc, const char * argv[])
#endif
{
    _doStuff();
    //Playground p;
    //p._doBenchmark();
    //p._doFonts();

    return 0;
}

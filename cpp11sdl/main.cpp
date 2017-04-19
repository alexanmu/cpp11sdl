/*
  CPP11SDL
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

#include "GfxInitQuit.hpp"
#include "Playground.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GfxSurface.hpp"
#include "GfxTexture.hpp"
#include "GfxConstants.hpp"
#include "GfxCanvas.hpp"
#include "Linux.h"
#include "macOS.h"

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

void _DoStuff(void)
{
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
    {
        std::cout << "Init failed\n";
        return;
    }
    
    GfxWindow w("Window title",WIN_W,WIN_H);
    GfxRenderer r(w);
    GfxSurface sbi(std::string(__base_path) + std::string("/Image2.bmp"));
    
    GfxSurface sb(WIN_W,WIN_H);
    
    int c = 0;
    for(int i = 0; i < WIN_W; i++)
    {
        for (int j = 480; j < WIN_H; j++)
        {
            sb.putPixel(i,j,GfxConstants::vga16GetColorByIndex(c));
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == 16) c = 0;
        }
    }
    
    GfxCanvas cv(sb);
    cv.Circle(GfxPoint(WIN_H,240),GfxRadius(230),GfxConstants::vga16Green());
    cv.Arc(GfxPoint(WIN_H,240),GfxAngle(60),GfxAngle(300),GfxRadius(239),GfxConstants::vga16Red());
    cv.OutText(GfxPoint(360,232),GfxString("Diana!"),GfxColor(50,100,200));
    cv.Bar(GfxPoint(WIN_H,0),GfxPoint(WIN_W,240),GfxConstants::vga16LightRed());
    cv.Bar(GfxRect(10,10,20,20),GfxConstants::vga16Red());
    cv.Rect(GfxPoint(20,20),GfxPoint(30,30),GfxConstants::vga16Green());
    cv.Rect(GfxRect(30,30,40,40),GfxColor(128,128,128));
    cv.Line(GfxPoint(10,10),GfxPoint(40,40),GfxConstants::vga16Yellow());
    cv.OutText(GfxPoint(50,50),GfxString("The quick brown fox jumped over the lazy dog 0123456789!"),GfxColor(210,210,20),GfxConstants::std8x16Font());
    cv.OutText(GfxPoint(70,70),GfxString("The quick brown fox jumped over the lazy dog 0123456789!"),GfxColor(150,100,200));


    cv.Bar(GfxPoint(100,100),GfxPoint(300,200),GfxConstants::vga16LightGray());
    cv.OutText(GfxPoint(120,120),GfxString("3D Text, custom font"),GfxConstants::vga16White(),GfxConstants::std8x16Font());
    cv.OutText(GfxPoint(121,121),GfxString("3D Text, custom font"),GfxConstants::vga16Black(),GfxConstants::std8x16Font());
    cv.OutText(GfxPoint(120,140),GfxString("3D Text, BGI_sdl font"),GfxConstants::vga16White());
    cv.OutText(GfxPoint(121,141),GfxString("3D Text, BGI_sdl font"),GfxConstants::vga16Black());


    c = 0;
    for(int i = 0; i < WIN_W; i++)
    {
        for (int j = 240; j < 480; j++)
        {
            cv.PutPixel(GfxPoint(i,j),GfxConstants::vga16GetColorByIndex(static_cast<GfxConstants::GfxVga16ColorIndex>(c)));
        }
        if (((i + 1) % 60) == 0)
        {
            c += 1;
            if (c == 16) c = 0;
        }
    }
    
    GfxSurface s(WIN_W,WIN_H);
    GfxRect rt;

    SDL_Event e;
    bool quit = false;
    int r1 = GfxConstants::vga16DarkGray().getRed();
    int g1 = GfxConstants::vga16DarkGray().getGreen();
    int b1 = GfxConstants::vga16DarkGray().getBlue();
    int a1 = 0;

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
            //rt.setX(WIN_H);
            //s.fillRect(rt,GfxColor(255-r1,255-g1,255-b1,a1));

            GfxTexture t(&r,s);
            t.setBlendMode(GfxBlendMode::GfxBlendModeValues::blendBlend);
            
            r.renderCopy(tb);
            r.renderCopy(t);
            r.renderPresent();
        }
        SDL_Delay(25);
    }

}

int main(int argc, const char * argv[])
{
    _DoStuff();
    //Playground p;
    //p.Play();

    return 0;
}

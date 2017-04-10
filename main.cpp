//
//  main.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include <iostream>
#include <string>

#include "GfxInitQuit.hpp"
#include "Playground.hpp"
#include "GfxWindow.hpp"
#include "GfxRenderer.hpp"
#include "GfxSurface.hpp"
#include "GfxTexture.hpp"
#include "GfxConstants.hpp"

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
    GfxWindow w("Window title",960,480);
    GfxRenderer r(w);
    GfxSurface sb("/Users/georgeoros/Documents/Dev/Files/Image2.bmp");
    
    GfxSurface s(960,480);
    GfxRect rt;

    SDL_Event e;
    bool quit = false;
    int r1 = 128,g1 = 128,b1 = 128;
    std::string str;
    int a1 = 208;

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
            }

            str = std::to_string(r1) + ":" + std::to_string(g1) + ":" + std::to_string(b1) + "-" + std::to_string(a1);
            w.setTitle(str);
            
            rt.setX(0);
            rt.setY(0);
            rt.setWidth(480);
            rt.setHeight(240);
            s.fillRect(rt,GfxColor(r1,g1,b1,a1));
            rt.setX(481);
            s.fillRect(rt,GfxColor(255-r1,255-g1,255-b1,a1));
            GfxTexture t(&r,s);
            t.setBlendMode(GfxBlendMode::GfxBlendModeValues::blendBlend);
        
            GfxTexture tb(&r,sb);
            tb.setBlendMode(GfxBlendMode::GfxBlendModeValues::blendNone);
            
            r.renderCopy(tb);
            r.renderCopy(t);
            r.renderPresent();
        }
        SDL_Delay(25);
    }

}

int main(int argc, const char * argv[]) {
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
        std::cout << "Init failed\n";
    else
    {
        std::cout << "Doing stuff\n";
        Playground p;
        p.Play();
        _DoStuff();
    }
    return 0;
}

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

#include "BgiDemo.hpp"

/***************************************************** BGI Demo *****************************************************/
#include <cstdint>
#include <string>
#include <iostream>
#include <random>
#include <functional>

#include "GfxInitQuit.hpp"
#include "GfxInitFlags.hpp"
#include "GfxWindow.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxControlledSurface.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxCanvas.hpp"
#include "GfxPixelFormatEnum.hpp"
#include "GfxPixelFormat.hpp"
#include "GfxEventType.hpp"
#include "GfxKeyboardEvent.hpp"
#include "GfxKeyboard.hpp"
#include "GfxScancode.hpp"
#include "GfxWindowEvent.hpp"
#include "GfxWindowEventID.hpp"

#include "GfxColors2.hpp"
#include "GfxPoint.hpp"
#include "GfxRect.hpp"
#include "GfxFillStyles.hpp"
#include "GfxText.hpp"

using namespace gfx::initquit;
using namespace gfx::video;
using namespace gfx::xtra;
using namespace gfx::surface;
using namespace gfx::pixels;
using namespace gfx::bgi;
using namespace gfx::events;
using namespace gfx::keyboard;
using namespace gfx::scancode;
using namespace gfx::bgi;
using namespace gfx::rect;

class BorlandGraphicsInterfaceDemo
{
public:
    BorlandGraphicsInterfaceDemo();
    ~BorlandGraphicsInterfaceDemo();

    void doDemo(void);
private:
    void setUpWindow(void);
    bool setUpSurface(void);
    void setUpCanvas(void);
    void eventLoop(void);

    bool drawColors(void);
    bool drawText(void);
    bool drawRoundShapes(void);
    bool drawVerticalAndZoomText(void);
    bool drawLineStyle(void);
    bool drawGetPutImage(void);
    bool drawWaitForQuit(void);

    void demoStateMachine(void);

    void processWindowEvent(GfxWindowEventID const& ev);

    GfxInitQuit * iqptr_;
    GfxWindow * winptr_;
    GfxControlledSurface csurf_;
    GfxCanvas * canvas_;

    int32_t demoStep_;
    int32_t waitForQuitStep_;

    static const std::string winTitle_;
    int32_t winWidth_ = 640;
    int32_t winHeight_ = 480;
};

const std::string BorlandGraphicsInterfaceDemo::winTitle_ = "BGI Demo";

BorlandGraphicsInterfaceDemo::BorlandGraphicsInterfaceDemo()
{
    GfxInitFlags initFlags;

    iqptr_ = nullptr;
    initFlags.setVideo();
    initFlags.setEvents();
    iqptr_ = new GfxInitQuit(initFlags);
    winptr_ = nullptr;
    canvas_ = nullptr;
    demoStep_ = 0;
    waitForQuitStep_ = 0;
}

BorlandGraphicsInterfaceDemo::~BorlandGraphicsInterfaceDemo()
{
    if (canvas_ != nullptr)
    {
        delete canvas_;
    }
    csurf_.freeSurface();
    if (winptr_ != nullptr)
    {
        delete winptr_;
    }
    if (iqptr_ != nullptr)
    {
        delete iqptr_;
    }
}

void BorlandGraphicsInterfaceDemo::doDemo(void)
{
    setUpWindow();
    if (setUpSurface() == true)
    {
        std::cout << "Starting demo" << std::endl;
    }
    else
    {
        std::cout << "Canvas requires 24/32bit surface. Exiting ..." << std::endl;
        return;
    }
    setUpCanvas();
    eventLoop();
}

void BorlandGraphicsInterfaceDemo::setUpWindow(void)
{
    GfxWindowFlags winflags;

    std::cout << "Create window [" << winTitle_ << "], width " << winWidth_ << " pixels, height ";
    std::cout << winHeight_ << " pixels" << std::endl;
    winflags.setResizable();
    winflags.setMouseFocus();
    winptr_ = new GfxWindow(winTitle_, winWidth_, winHeight_, winflags);
}

bool BorlandGraphicsInterfaceDemo::setUpSurface(void)
{
    GfxSurfaceFlags sflags;
    GfxPixelFormatEnum pixfmt;
    GfxPixelFormat * pix;
    uint32_t bpp;
    uint32_t bypp;

    std::cout << "Get window surface. Attributes:" << std::endl;
    csurf_.createSurface(*winptr_);
    // Surface flags
    sflags = csurf_().getSurfaceFlags();
    std::cout << "Software surface: " << std::boolalpha << sflags.isSwSurface() << std::noboolalpha << std::endl;
    std::cout << "Pre-allocated:    " << std::boolalpha << sflags.isPreAlloc() << std::noboolalpha << std::endl;
    std::cout << "RLE accelerated:  " << std::boolalpha << sflags.isRLEAccel() << std::noboolalpha << std::endl;
    std::cout << "Don't free:       " << std::boolalpha << sflags.isDontFree() << std::noboolalpha << std::endl;
    // Check pixel format of surface
    std::cout << "Window surface pixel format. Attributes:" << std::endl;
    pixfmt = csurf_().getPixelFormat();
    std::cout << "Pixel format code: " << pixfmt.getAsSdlType() << std::endl;
    pix = new GfxPixelFormat(pixfmt);
    std::cout << "Format name:       " << pix->getPixelFormatName() << std::endl;
    std::cout << "Bits per pixel:    " << pix->bitsPerPixel() << std::endl;
    std::cout << "Bytes per pixel:   " << pix->bytesPerPixel() << std::endl;
    std::cout << "Indexed:           " << std::boolalpha << pix->isPixelFormatIndexed() << std::noboolalpha << std::endl;
    std::cout << "Packed:            " << std::boolalpha << pix->isPixelFormatPacked() << std::noboolalpha << std::endl;
    std::cout << "Array:             " << std::boolalpha << pix->isPixelFormatArray() << std::noboolalpha << std::endl;
    std::cout << "Alpha:             " << std::boolalpha << pix->isPixelFormatAlpha() << std::noboolalpha << std::endl;
    std::cout << "FourCC:            " << std::boolalpha << pix->isPixelFormatFourCC() << std::noboolalpha << std::endl;
    bpp = pix->bitsPerPixel();
    bypp = pix->bytesPerPixel();
    delete pix;
    if (((bpp == 32) || (bpp == 24)) &&
        ((bypp == 4) || (bypp == 3)))
    {
        return true;
    }
    return false;
}

void BorlandGraphicsInterfaceDemo::setUpCanvas(void)
{
    canvas_ = new GfxCanvas(csurf_());
}

void BorlandGraphicsInterfaceDemo::eventLoop(void)
{
    gfx::sdl2::SDL_Event e;
    bool quit = false;

    GfxKeyboard kdb;

    std::cout << "Start event loop; press <Q> to exit" << std::endl;
    while (!quit)
    {
        if (SDL_PollEvent(&e))
        {
            GfxEventType evType(e.type);

            if (evType.isQuit())
            {
                std::cout << "Quit" << std::endl;
                quit = true;
            }
            if (evType.isKeyUp())
            {
                GfxKeyboardEvent evKbd(e.key);

                std::cout << "Key pressed: " << kdb.getKeyName(evKbd.getKeysym().getKeyCode()) << std::endl;
                if (evKbd.getKeysym().getScanCode().getValue() == GfxScancode::ValueType::kScanCodeQ)
                {
                    quit = true;
                }
            }
            if (evType.isWindowEvent())
            {
                GfxWindowEvent evWin(e.window);

                processWindowEvent(evWin.getWindowEventID());
            }
        }
        gfx::sdl2::SDL_Delay(25);
        demoStateMachine();
        winptr_->updateWindowSurface();
    }
}

void BorlandGraphicsInterfaceDemo::processWindowEvent(GfxWindowEventID const& ev)
{
    if (ev.isSizeChanged())
    {
        if (canvas_ != nullptr)
        {
            delete canvas_;
        }
        csurf_.freeSurface();
        std::cout << "Size changed" << std::endl;
        int32_t w = winptr_->getWidth();
        int32_t h = winptr_->getHeight();
        std::cout << "New width " << w << ", new height " << h << " pixels" << std::endl;
        if (setUpSurface() == true)
        {
            std::cout << "Starting demo" << std::endl;
        }
        else
        {
            std::cout << "Canvas requires 24/32bit surface. Exiting ..." << std::endl;
            return;
        }
        setUpCanvas();
    }
}

bool BorlandGraphicsInterfaceDemo::drawColors(void)
{
    std::cout << "Draw colors ..." << std::endl;

    int32_t step = winHeight_ / GfxColors2::numColors;
    int32_t y = 0;
    const uint32_t clrs[] = {
        GfxColors2::black,
        GfxColors2::blue,
        GfxColors2::green,
        GfxColors2::cyan,
        GfxColors2::red,
        GfxColors2::magenta,
        GfxColors2::brown,
        GfxColors2::lightGray,
        GfxColors2::darkGray,
        GfxColors2::lightBlue,
        GfxColors2::lightGreen,
        GfxColors2::lightCyan,
        GfxColors2::lightRed,
        GfxColors2::lightMagenta,
        GfxColors2::yellow,
        GfxColors2::white
    };
    for (int32_t index = 0; index < GfxColors2::numColors; index++)
    {
        canvas_->SetFillStyle(GfxFillStyles(), GfxColors2(clrs[index]));
        canvas_->Bar(GfxRect(0, y, winWidth_, y + step));
        y += step;
    }
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawText(void)
{
    std::cout << "Draw text ..." << std::endl;

    int32_t step = winHeight_ / GfxColors2::numColors;
    int32_t y = 0;
    GfxColors2 pixclr;
    int32_t text_x;
    int32_t text_y;
    GfxText text;
    GfxColors2 text_color;

    text.setValue("The quick brown fox jumped over the lazy dog 0123456789!");
    for (int32_t index = 0; index < GfxColors2::numColors; index++)
    {
        pixclr = canvas_->GetPixel(GfxPoint(1, y + 1));
        if (pixclr.isCustomColor() == true)
        {
            text_color = GfxColors2(GfxColors2::white);
        }
        else
        {
            text_color = GfxColors2(0xFF000000 | (~(pixclr.getValue() & 0x00FFFFFF)));
        }
        canvas_->SetColor(text_color);
        text_x = winWidth_ / 2 - canvas_->TextWidth(text) / 2;
        text_y = y + step / 2 - canvas_->TextHeight(text) / 2;
        canvas_->OutTextXY(GfxPoint(text_x, text_y),text);
        y += step;
    }
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawRoundShapes(void)
{
    std::cout << "Draw round shapes ..." << std::endl;

    GfxPoint center(winWidth_ / 2, winHeight_ / 2);

    canvas_->SetColor(GfxColors2(GfxColors2::blue));
    canvas_->Arc(center,GfxAngle(120),GfxAngle(240),GfxRadius(200));
    canvas_->Circle(center, GfxRadius(190));
    canvas_->Ellipse(center, GfxAngle(90), GfxAngle(270), GfxRadius(80), GfxRadius(170));
    canvas_->SetFillStyle(GfxFillStyles(GfxFillStyles::ValueType::xHatchFill), GfxColors2(GfxColors2::red));
    canvas_->FillEllipse(center, GfxRadius(30), GfxRadius(90));
    center.setX(10);
    canvas_->PieSlice(center, GfxAngle(30), GfxAngle(330), GfxRadius(90));
    canvas_->Sector(center, GfxAngle(40), GfxAngle(340), GfxRadius(100), GfxRadius(30));
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawVerticalAndZoomText(void)
{
    std::cout << "Draw vertical and zoom text ..." << std::endl;

    int32_t text_x;
    int32_t text_y;
    GfxText text("Draw vertical and zoom text");

    canvas_->SetColor(GfxColors2(GfxColors2::darkGray));
    canvas_->SetTextStyle(GfxFonts(GfxFonts::ValueType::defaultFont),
                          GfxDirection(GfxDirection::ValueType::verticalDirection),
                          2);
    text_x = winWidth_ - 25 - canvas_->TextHeight(text) / 2;
    text_y = winHeight_ / 2 + canvas_->TextWidth(text) / 2;
    canvas_->MoveTo(GfxPoint(text_x, text_y));
    canvas_->OutText(text);
    canvas_->SetColor(GfxColors2(GfxColors2::red));
    canvas_->SetTextStyle(GfxFonts(GfxFonts::ValueType::defaultFont),
                          GfxDirection(GfxDirection::ValueType::horizontalDirection),
                          1);
    canvas_->OutTextXY(GfxPoint(10, text_y - 10), GfxText("TexW=" + std::to_string(canvas_->TextWidth(text) )));
    canvas_->OutTextXY(GfxPoint(10, text_y + 10), GfxText("TexH=" + std::to_string(canvas_->TextHeight(text) )));
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawLineStyle(void)
{
    std::cout << "Draw line style ..." << std::endl;

    canvas_->SetColor(GfxColors2(GfxColors2::lightGray));
    canvas_->SetLineStyle(GfxLineStyle(GfxLineStyle::ValueType::dashedLine),
                          GfxFillStyles(GfxFillStyles::ValueType::solidFill),
                          GfxLineThickness(GfxLineThickness::ValueType::thickWidth));
    canvas_->Rectangle(GfxPoint(20,20), GfxPoint(100,100));
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawGetPutImage(void)
{
    std::cout << "Draw get/put image ..." << std::endl;

    char * buffer;
    int32_t imagesize;

    imagesize = canvas_->ImageSize(GfxPoint(20,20), GfxPoint(100,100));
    buffer = new char[imagesize];
    canvas_->GetImage(GfxPoint(20,20), GfxPoint(100,100), buffer);
    canvas_->PutImage(GfxPoint(101,101), buffer, GfxDrawingMode(GfxDrawingMode::ValueType::copyPut));
    delete[] buffer;
    return true;
}

bool BorlandGraphicsInterfaceDemo::drawWaitForQuit(void)
{
    decltype(canvas_->GetPixel(GfxPoint(0, 0))) pixel;
    int32_t new_pixel;

    switch (waitForQuitStep_)
    {
        case 0:
            std::cout << "Draw wait for quit ..." << std::endl;
            waitForQuitStep_ = 1;
            break;
        case 1:
            for (int i = 0; i < winWidth_; i++)
            {
                for (int j = 0; j < winHeight_; j++)
                {
                    pixel = canvas_->GetPixel(GfxPoint(i, j));
                    new_pixel = 0xFF000000 | (~(pixel.getValue() & 0x00FFFFFF));
                    canvas_->PutPixel(GfxPoint(i, j), GfxColors2(new_pixel));
                }
            }
            waitForQuitStep_ = 2;
            break;
        default:
            // Should never be here
            waitForQuitStep_ += 1;
            if (waitForQuitStep_ == 21)
            {
                waitForQuitStep_ = 1;
            }
            break;
    }
    return true;
}

void BorlandGraphicsInterfaceDemo::demoStateMachine(void)
{
    switch (demoStep_)
    {
        case 0:
            // Just inited; continue with step 1
            demoStep_ = 1;
            break;
        case 1:
            if (drawColors() == true)
            {
                demoStep_ = 2;
            }
            break;
        case 2:
            if (drawText() == true)
            {
                demoStep_ = 3;
            }
        case 3:
            if (drawRoundShapes() == true)
            {
                demoStep_ = 4;
            }
        case 4:
            if (drawVerticalAndZoomText() == true)
            {
                demoStep_ = 5;
            }
        case 5:
            if (drawLineStyle() == true)
            {
                demoStep_ = 6;
            }
        case 6:
            if (drawGetPutImage() == true)
            {
                demoStep_ = 7;
            }
        case 7:
            if (drawWaitForQuit() == true)
            {
                // stay here
                demoStep_ = 7;
            }
        default:
            // Should never be here
            demoStep_ = 7;
            break;
    }
}

void _doBgiDemo(void)
{
    BorlandGraphicsInterfaceDemo b;

    b.doDemo();
}

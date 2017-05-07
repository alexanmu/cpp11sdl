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

  Portions of this code are based on SDL_bgi. See http://libxgi.sourceforge.net/
*/

#ifndef GfxBgi_hpp
#define GfxBgi_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxCanvasBgiData.hpp"

class GfxCanvasBgi : public GfxRootClass
{
public:
    static const std::string ClassName;

    enum class bgiFonts : int
    {
        DEFAULT_FONT =     0,  // 8x8
        TRIPLEX_FONT =     1,  // all other fonts are not implemented
        SMALL_FONT =       2,
        SANSSERIF_FONT =   3,
        GOTHIC_FONT =      4,
        BIG_FONT =         5,
        SCRIPT_FONT =      6,
        SIMPLEX_FONT =     7,
        TRIPLEX_SCR_FONT = 8,
        COMPLEX_FONT =     9,
        EUROPEAN_FONT =    10,
        BOLD_FONT =        11,
    };

    enum class bgiDirection : int
    {
        HORIZ_DIR =      0,
        VERT_DIR =       1
    };

    enum class bgiTextJustification : int
    {
        LEFT_TEXT =      0,
        CENTER_TEXT =    1,
        RIGHT_TEXT =     2,
        BOTTOM_TEXT =    0,
        TOP_TEXT =       2
    };

    enum class bgiColors : int
    {
        BLACK =           0,
        BLUE =            1,
        GREEN =           2,
        CYAN =            3,
        RED =             4,
        MAGENTA =         5,
        BROWN =           6,
        LIGHTGRAY =       7,
        DARKGRAY =        8,
        LIGHTBLUE =       9,
        LIGHTGREEN =     10,
        LIGHTCYAN =      11,
        LIGHTRED =       12,
        LIGHTMAGENTA =   13,
        YELLOW =         14,
        WHITE =          15,
        CUSTOM_FG =      16,
        CUSTOM_BG =      17,
        CUSTOM_FILL =    18
    };

    enum class bgiLineThickness : int
    {
        NORM_WIDTH =      1,
        THICK_WIDTH =     3
    };

    enum class bgiLineStyle : int
    {
        SOLID_LINE =      0,
        DOTTED_LINE =     1,
        CENTER_LINE =     2,
        DASHED_LINE =     3,
        USERBIT_LINE =    4
    };

    enum class bgiDrawingMode : int
    {
        COPY_PUT  =       0,
        XOR_PUT =         1,
        OR_PUT =          2,
        AND_PUT =         3,
        NOT_PUT =         4
    };

    enum class bgiFillStyles : int
    {
        EMPTY_FILL =      0,
        SOLID_FILL =      1,
        LINE_FILL =       2,
        LTSLASH_FILL =    3,
        SLASH_FILL =      4,
        BKSLASH_FILL =    5,
        LTBKSLASH_FILL =  6,
        HATCH_FILL =      7,
        XHATCH_FILL =     8,
        INTERLEAVE_FILL = 9,
        WIDE_DOT_FILL =   10,
        CLOSE_DOT_FILL =  11,
        USER_FILL =       12
    };

    struct arccoordstype
    {
        int x;
        int y;
        int xstart;
        int ystart;
        int xend;
        int yend;
    };

    struct fillsettingstype
    {
        bgiFillStyles pattern;
        bgiColors color;
    };

    struct linesettingstype
    {
        bgiLineStyle linestyle;
        bgiFillStyles upattern;
        bgiLineThickness thickness;
    };

    struct palettetype
    {
        unsigned char size;
        signed char colors[GfxCanvasBgiData::kMaxColors + 1];
    };

    struct textsettingstype
    {
        bgiFonts font;
        bgiDirection direction;
        int charsize;
        bgiTextJustification horiz;
        bgiTextJustification vert;
    };

    struct viewporttype
    {
        int left;
        int top;
        int right;
        int bottom;
        bool clip;
    };

    GfxCanvasBgi();

    GfxCanvasBgi(const GfxCanvasBgi&) = delete;
    GfxCanvasBgi(GfxCanvasBgi&&) = delete;

    GfxCanvasBgi& operator=(const GfxCanvasBgi&) = delete;
    GfxCanvasBgi& operator=(GfxCanvasBgi&&) = delete;

    void setCanvas(const uint32_t* ptr, const int maxx, const int maxy);
    void setCustomForegroundColor(const uint32_t color);
    void setCustomBackgroundColor(const uint32_t color);
    void setCustomFillColor(const uint32_t color);
    void setCustomFont(const uint8_t* fontBitmapData, const uint8_t fontWidth, const uint8_t fontHeight);
    void setDefaultFont(void);

    void arc(int x, int y, int stangle, int endangle, int radius);
    void bar3d(int left, int top, int right, int bottom, int depth, int topflag);
    void bar(int left, int top, int right, int bottom);
    void circle(int x, int y, int radius);
    void cleardevice(void);
    void clearviewport(void);
    void drawpoly(int numpoints, int * polypoints);
    void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
    void fillellipse(int x, int y, int xradius, int yradius);
    void fillpoly(int numpoints, int * polypoints);
    void floodfill(int x, int y, bgiColors border);
    void freeimage(void * bitmap);
    void getarccoords(struct arccoordstype * arccoords);
    bgiColors getbkcolor(void);
    bgiColors getcolor(void);
    struct palettetype *getdefaultpalette(void);
    void getfillpattern(char * pattern);
    void getfillsettings(struct fillsettingstype * fillinfo);
    void getimage(int left, int top, int right, int bottom, void * bitmap);
    void getlinesettings(struct linesettingstype * lineinfo);
    int getmaxcolor(void);
    int getmaxx(void);
    int getmaxy(void);
    void getpalette(struct palettetype *);
    int getpalettesize(struct palettetype *);
    unsigned int getpixel(int x, int y);
    void gettextsettings(struct textsettingstype *);
    void getviewsettings(struct viewporttype *);
    int getx(void);
    int gety(void);
    void graphdefaults(void);
    unsigned imagesize(int, int, int, int);
    void line(int, int, int, int);
    void linerel(int dx, int dy);
    void lineto(int x, int y);
    void moverel(int, int);
    void moveto(int, int);
    void outtext(char *);
    void outtextxy(int, int, char *);
    void pieslice(int, int, int, int, int);
    void _putpixel(int, int);
    void putimage(int, int, void *, bgiDrawingMode);
    void putpixel(int, int, int);
    void rectangle(int, int, int, int);
    void sector(int, int, int, int, int, int);
    void setallpalette(struct palettetype *);
    void setbkcolor(bgiColors);
    void setcolor(bgiColors);
    void setfillpattern(uint8_t* upattern, bgiColors color);
    void setfillstyle(bgiFillStyles pattern, bgiColors color);
    void setlinestyle(bgiLineStyle linestyle, bgiFillStyles upattern, bgiLineThickness thickness);
    void setpalette(int, int);
    void settextjustify(bgiTextJustification, bgiTextJustification);
    void settextstyle(int, bgiDirection, int);
    void setusercharsize(int, int, int, int);
    void setviewport(int, int, int, int, int);
    void setwritemode(bgiDrawingMode);
    int textheight(char *);
    int textwidth(char *);
private:
    void initpalette(void);
    void putpixel_copy(int, int, uint32_t);
    void putpixel_xor(int, int, uint32_t);
    void putpixel_and(int, int, uint32_t);
    void putpixel_or(int, int, uint32_t);
    void putpixel_not(int, int, uint32_t);
    void ff_putpixel(int x, int);
    uint32_t getpixel_raw(int, int);
    void line_copy(int, int, int, int);
    void line_xor(int, int, int, int);
    void line_and(int, int, int, int);
    void line_or(int, int, int, int);
    void line_not(int, int, int, int);
    void line_fill(int, int, int, int);
    void _floodfill(int, int, bgiColors);
    int  is_in_range(int, int, int);
    void swap_if_greater(int *, int *);
    void circle_bresenham(int, int, int);
    int  octant(int, int);
    void _ellipse(int, int, int, int);
    void drawchar(unsigned char ch);
    void _bar(int left, int top, int right, int bottom);

    // pixel data of active and visual pages
    uint32_t* bgi_activepage;

    // This is how we draw stuff on the screen. Pixels pointed to by
    // bgi_activepage (a pointer to pixel data in the active surface)
    // are modified by functions like putpixel_copy(); bgi_texture is
    // updated with the new bgi_activepage contents; bgi_texture is then
    // copied to bgi_renderer, and finally bgi_renderer is made present.

    uint32_t palette[1 + GfxCanvasBgiData::kMaxColors + 3];  // all colors

    bgiColors bgi_fg_color = bgiColors::WHITE;    // index of BGI foreground color
    bgiColors bgi_bg_color = bgiColors::BLACK;    // index of BGI background color
    bgiColors bgi_fill_color = bgiColors::WHITE;  // index of BGI fill color

    int bgi_font_width = 8;     // default font width and height
    int bgi_font_height = 8;
    int bgi_cp_x = 0;           // current position
    int bgi_cp_y = 0;
    int bgi_maxx;               // screen size
    int bgi_maxy;

    bgiDrawingMode bgi_writemode;          // plotting method (COPY_PUT, XOR_PUT...)

    float bgi_font_mag_x = 1.0;  // font magnification
    float bgi_font_mag_y = 1.0;

    struct arccoordstype bgi_last_arc;
    struct fillsettingstype bgi_fill_style;
    struct linesettingstype bgi_line_style;
    struct textsettingstype bgi_txt_style;
    struct viewporttype vp;
    struct palettetype pal;

    // pointer to font array. Should I add more (ugly) bitmap fonts?
    const uint8_t *fontptr = GfxCanvasBgiData::gfxPrimitivesFontdata;
};  // class GfxCanvasBgi


#endif /* GfxBgi_hpp */

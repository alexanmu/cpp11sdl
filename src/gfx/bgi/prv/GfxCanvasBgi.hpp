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

#include "GfxObject.hpp"
#include "GfxBgiConstants.hpp"

namespace gfx
{

namespace bgi
{

namespace prv
{

class GfxCanvasBgi final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    static const int32_t kMaxColors = 15;

    enum bgiFonts
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

    enum bgiDirection : int
    {
        HORIZ_DIR =      0,
        VERT_DIR =       1
    };

    enum bgiTextJustification : int
    {
        LEFT_TEXT =      0,
        CENTER_TEXT =    1,
        RIGHT_TEXT =     2,
        BOTTOM_TEXT =    0,
        TOP_TEXT =       2
    };

    enum bgiColors : int
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

    enum bgiLineThickness : int
    {
        NORM_WIDTH =      1,
        THICK_WIDTH =     3
    };

    enum bgiLineStyle : int
    {
        SOLID_LINE =      0,
        DOTTED_LINE =     1,
        CENTER_LINE =     2,
        DASHED_LINE =     3,
        USERBIT_LINE =    4
    };

    enum bgiDrawingMode : int
    {
        COPY_PUT  =       0,
        XOR_PUT =         1,
        OR_PUT =          2,
        AND_PUT =         3,
        NOT_PUT =         4
    };

    enum bgiFillStyles : int
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
        signed char colors[kMaxColors + 1];
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

    GfxCanvasBgi(GfxCanvasBgi const&) = delete;
    GfxCanvasBgi(GfxCanvasBgi&&) = delete;

    GfxCanvasBgi& operator=(GfxCanvasBgi const&) = delete;
    GfxCanvasBgi& operator=(GfxCanvasBgi&&) = delete;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setCanvas(const uint32_t * ptr, const int32_t maxx, const int32_t maxy) noexcept;
    void setCustomForegroundColor(const uint32_t color) noexcept;
    uint32_t getCustomForegroundColor(void) const noexcept;
    void setCustomBackgroundColor(const uint32_t color) noexcept;
    uint32_t getCustomBackgroundColor(void) const noexcept;
    void setCustomFillColor(const uint32_t color) noexcept;
    uint32_t getCustomFillColor(void) const noexcept;
    void setCustomFont(const uint8_t * fontBitmapData, const uint8_t fontWidth, const uint8_t fontHeight) noexcept;
    void setDefaultFont(void) noexcept;

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
    struct palettetype * getdefaultpalette(void);
    void getfillpattern(char * pattern);
    void getfillsettings(struct fillsettingstype * fillinfo);
    void getimage(int left, int top, int right, int bottom, void * bitmap);
    void getlinesettings(struct linesettingstype * lineinfo);
    int getmaxcolor(void);
    int getmaxx(void);
    int getmaxy(void);
    void getpalette(struct palettetype * palette);
    int getpalettesize(void);
    unsigned int getpixel(int x, int y);
    void gettextsettings(struct textsettingstype * texttypeinfo);
    void getviewsettings(struct viewporttype * viewport);
    int getx(void);
    int gety(void);
    void graphdefaults(void);
    unsigned imagesize(int left, int top, int right, int bottom);
    void line(int x1, int y1, int x2, int y2);
    void linerel(int dx, int dy);
    void lineto(int x, int y);
    void moverel(int dx, int dy);
    void moveto(int x, int y);
    void outtext(char * textstring);
    void outtextxy(int x, int y, char * textstring);
    void pieslice(int x, int y, int stangle, int endangle, int radius);
    void _putpixel(int x, int y);
    void putimage(int left, int top, void * bitmap, bgiDrawingMode op);
    void putpixel(int x, int y, int color);
    void rectangle(int x1, int y1, int x2, int y2);
    void sector(int x, int y, int stangle, int endangle, int xradius, int yradius);
    void setallpalette(struct palettetype *palette);
    void setbkcolor(bgiColors col);
    void setcolor(bgiColors col);
    void setfillpattern(uint8_t * upattern, bgiColors color);
    void setfillstyle(bgiFillStyles pattern, bgiColors color);
    void setlinestyle(bgiLineStyle linestyle, bgiFillStyles upattern, bgiLineThickness thickness);
    void setpalette(int colornum, int color);
    void settextjustify(bgiTextJustification horiz, bgiTextJustification vert);
    void settextstyle(int font, bgiDirection direction, int charsize);
    void setusercharsize(int multx, int divx, int multy, int divy);
    void setviewport(int left, int top, int right, int bottom, int clip);
    void setwritemode(bgiDrawingMode mode);
    int textheight(char * textstring);
    int textwidth(char * textstring);
private:
    void initpalette(void);
    void putpixel_copy(int x, int y, uint32_t pixel);
    void putpixel_xor(int x, int y, uint32_t pixel);
    void putpixel_and(int x, int y, uint32_t pixel);
    void putpixel_or(int x, int y, uint32_t pixel);
    void putpixel_not(int x, int y, uint32_t pixel);
    void ff_putpixel(int x, int y);
    uint32_t getpixel_raw(int x, int y);
    void line_copy(int x1, int y1, int x2, int y2);
    void line_xor(int x1, int y1, int x2, int y2);
    void line_and(int x1, int y1, int x2, int y2);
    void line_or(int x1, int y1, int x2, int y2);
    void line_not(int x1, int y1, int x2, int y2);
    void line_fill(int x1, int y1, int x2, int y2);
    void _floodfill(int x, int y, bgiColors border);
    int  is_in_range(int x, int x1, int x2);
    void swap_if_greater(int * x1, int * x2);
    void circle_bresenham(int x, int y, int radius);
    int  octant(int x, int y);
    void _ellipse(int cx, int cy, int xradius, int yradius);
    void drawchar(unsigned char ch);
    void _bar(int left, int top, int right, int bottom);

    // pixel data of active and visual pages
    uint32_t * bgi_activepage;

    // This is how we draw stuff on the screen. Pixels pointed to by
    // bgi_activepage (a pointer to pixel data in the active surface)
    // are modified by functions like putpixel_copy(); bgi_texture is
    // updated with the new bgi_activepage contents; bgi_texture is then
    // copied to bgi_renderer, and finally bgi_renderer is made present.

    uint32_t bgi_palette[1 + kMaxColors + 3];  // all colors
    uint16_t bgi_line_patterns[1 + static_cast<int>(bgiLineStyle::USERBIT_LINE)];
    uint8_t bgi_fill_patterns[1 + static_cast<int>(bgiFillStyles::USER_FILL)][8];

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
    struct viewporttype bgi_vp;
    struct palettetype bgi_pal;

    static const uint32_t bgi_default_palette[1 + GfxCanvasBgi::kMaxColors];
    static const uint16_t bgi_default_line_patterns[static_cast<int>(bgiLineStyle::USERBIT_LINE)];
    static const uint8_t bgi_default_fill_patterns[static_cast<int>(bgiFillStyles::USER_FILL)][8];

    // pointer to font array. Should I add more (ugly) bitmap fonts?
    static const uint8_t * bgi_fontptr;
};  // class GfxCanvasBgi

}  // namespace prv

}  // namespace bgi

}  // namespace gfx

#endif /* GfxBgi_hpp */

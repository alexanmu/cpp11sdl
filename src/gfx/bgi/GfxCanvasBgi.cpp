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

#include <cassert>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

const char GfxCanvasBgi::ClassName[] = "GfxCanvasBgi";

GfxCanvasBgi::GfxCanvasBgi() : GfxRootClass(ClassName)
{
    bgi_activepage = nullptr;
    bgi_maxx = -1;
    bgi_maxy = -1;
}

GfxCanvasBgi::operator bool() const
{
    return (bgi_activepage != nullptr);
}

void GfxCanvasBgi::setCanvas(const uint32_t* ptr, const int maxx, const int maxy)
{
    assert(ptr != nullptr);
    assert(maxx > 0);
    assert(maxy > 0);

    graphdefaults();
    bgi_activepage = const_cast<uint32_t *>(ptr);    // active (= being drawn on) page; may be hidden
    bgi_maxx = maxx - 1;
    bgi_maxy = maxy - 1;
}

void GfxCanvasBgi::setCustomForegroundColor(const uint32_t color)
{
    palette[static_cast<int>(bgiColors::CUSTOM_FG)] = color;
    bgi_fg_color = bgiColors::CUSTOM_FG;
}

void GfxCanvasBgi::setCustomBackgroundColor(const uint32_t color)
{
    palette[static_cast<int>(bgiColors::CUSTOM_BG)] = color;
    bgi_bg_color = bgiColors::CUSTOM_BG;
}

void GfxCanvasBgi::setCustomFillColor(const uint32_t color)
{
    palette[static_cast<int>(bgiColors::CUSTOM_FILL)] = color;
    bgi_fill_style.color = GfxCanvasBgi::bgiColors::CUSTOM_FILL;
}

void GfxCanvasBgi::setCustomFont(const uint8_t* fontBitmapData, const uint8_t fontWidth, const uint8_t fontHeight)
{
    assert(fontBitmapData != nullptr);
    assert(fontWidth % 8 == 0);
    assert(fontHeight % 8 == 0);

    bgi_font_width = fontWidth;
    bgi_font_height = fontHeight;
    fontptr = fontBitmapData;
}

void GfxCanvasBgi::setDefaultFont(void)
{
    bgi_font_width = 8;
    bgi_font_height = 8;
    fontptr = GfxCanvasBgiData::gfxPrimitivesFontdata;
}

// -----

int GfxCanvasBgi::is_in_range(int x, int x1, int x2)
{
    return ((x >= x1) && (x <= x2));
}

// -----

#define PI_CONV (3.1415926 / 180.0)

void GfxCanvasBgi::arc(int x, int y, int stangle, int endangle, int radius)
{
    // Draws a circular arc centered at (x, y), with a radius
    // given by radius, traveling from stangle to endangle.

    // Quick and dirty for now, Bresenham-based later (maybe)
    int angle;

    if (0 == radius)
    {
        return;
    }

    if (endangle < stangle)
    {
        endangle += 360;
    }

    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (radius * std::cos(stangle * PI_CONV));
    bgi_last_arc.ystart = y - (radius * std::sin(stangle * PI_CONV));
    bgi_last_arc.xend = x + (radius * std::cos(endangle * PI_CONV));
    bgi_last_arc.yend = y - (radius * std::sin(endangle * PI_CONV));

    for (angle = stangle; angle < endangle; angle++)
    {
        line(x + std::floor(0.5 + (radius * std::cos(angle * PI_CONV))),
                y - std::floor(0.5 + (radius * std::sin(angle * PI_CONV))),
                x + std::floor(0.5 + (radius * std::cos((angle + 1) * PI_CONV))),
                y - std::floor(0.5 + (radius * std::sin((angle + 1) * PI_CONV))));
    }
}  // arc ()

// -----

void GfxCanvasBgi::bar3d(int left, int top, int right, int bottom, int depth, int topflag)
{
    // Draws a three-dimensional, filled-in rectangle (bar), using
    // the current fill colour and fill pattern.
    bgiColors tmp;
    bgiColors tmpcolor;

    tmp = bgi_fg_color;

    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else  // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }

    setcolor(tmpcolor);  // fill
    bar(left, top, right, bottom);
    setcolor(tmp);  // outline
    if (depth > 0)
    {
        line(left, top, left + depth, top - depth);
        line(left + depth, top - depth, right + depth, top - depth);
        line(right, top, right + depth, top - depth);
        line(right, bottom, right + depth, bottom - depth);
        line(right + depth, bottom - depth, right + depth, top - depth);
    }
    rectangle(left, top, right, bottom);

    // topflag - what should I do with it?
    assert(topflag == 0);
}  // bar3d ()

// -----

void GfxCanvasBgi::bar(int left, int top, int right, int bottom)
{
    // Draws a filled-in rectangle (bar), using the current fill colour
    // and fill pattern.
    int y;
    bgiLineThickness tmpthickness;
    bgiColors tmp;
    bgiColors tmpcolor;

    tmp = bgi_fg_color;

    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else  // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }

    setcolor(tmpcolor);
    tmpthickness = bgi_line_style.thickness;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;

    if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
    {
        for (y = top; y <= bottom; y++)
        {
            line(left, y, right, y);
        }
    }
    else
    {
        for (y = top; y <= bottom; y++)
        {
            line_fill(left, y, right, y);
        }
    }

    setcolor(tmp);
    bgi_line_style.thickness = tmpthickness;
}  // bar ()

// -----

void GfxCanvasBgi::circle_bresenham(int x, int y, int radius)
{
    // Draws a circle of the given radius at (x, y).
    // Adapted from:
    // http://members.chello.at/easyfilter/bresenham.html

    int xx = -radius;
    int yy = 0;
    int err = 2 - 2 * radius;

    do
    {
        _putpixel(x - xx, y + yy);  //  I  quadrant
        _putpixel(x - yy, y - xx);  //  II quadrant
        _putpixel(x + xx, y - yy);  //  III quadrant
        _putpixel(x + yy, y + xx);  //  IV quadrant
        radius = err;

        if (radius <= yy)
        {
            yy += 1;
            err += yy * 2 + 1;
        }

        if ((radius > xx) || (err > yy))
        {
            xx += 1;
            err += xx * 2 + 1;
        }
    }
    while (xx < 0);  // NOLINT(whitespace/empty_loop_body)
}  // circle_bresenham ();

// -----

void GfxCanvasBgi::circle(int x, int y, int radius)
{
    // Draws a circle of the given radius at (x, y).

    // the Bresenham algorithm draws a better-looking circle

    if (bgiLineThickness::NORM_WIDTH == bgi_line_style.thickness)
    {
        circle_bresenham(x, y, radius);
    }
    else
    {
        arc(x, y, 0, 360, radius);
    }
}  // circle ();

// -----

void GfxCanvasBgi::cleardevice(void)
{
    // Clears the graphics screen, filling it with the current
    // background color.
    int x;
    int y;

    bgi_cp_x = 0;
    bgi_cp_y = 0;
    for (x = 0; x < bgi_maxx + 1; x++)
    {
        for (y = 0; y < bgi_maxy + 1; y++)
        {
            bgi_activepage[y * (bgi_maxx + 1) + x] = palette[static_cast<int>(bgi_bg_color)];
        }
    }
}  // cleardevice ()

// -----

void GfxCanvasBgi::clearviewport(void)
{
    // Clears the viewport, filling it with the current
    // background color.
    int x;
    int y;

    bgi_cp_x = bgi_cp_y = 0;

    for (x = vp.left; x < vp.right + 1; x++)
    {
        for (y = vp.top; y < vp.bottom + 1; y++)
        {
            bgi_activepage[y * (bgi_maxx + 1) + x] = palette[static_cast<int>(bgi_bg_color)];
        }
    }
}  // clearviewport ()

// -----

void GfxCanvasBgi::drawpoly(int numpoints, int *polypoints)
{
    // Draws a polygon of numpoints vertices.
    int n;

    for (n = 0; n < numpoints - 1; n++)
    {
        line(polypoints[2*n], polypoints[2*n + 1],
                polypoints[2*n + 2], polypoints[2*n + 3]);
    }
    // close the polygon
    line(polypoints[2*n], polypoints[2*n + 1],
            polypoints[0], polypoints[1]);
}  // drawpoly ()

// -----

void GfxCanvasBgi::swap_if_greater(int *x1, int *x2)
{
    int tmp;

    if (*x1 > *x2)
    {
        tmp = *x1;
        *x1 = *x2;
        *x2 = tmp;
    }
}  // swap_if_greater ()

// -----

void GfxCanvasBgi::ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius)
{
    // Draws an elliptical arc centered at (x, y), with axes given by
    // xradius and yradius, traveling from stangle to endangle.

    // Bresenham-based if complete
    int angle;

    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }

    if (endangle < stangle)
    {
        endangle += 360;
    }

    // draw complete ellipse
    if (0 == stangle && 360 == endangle)
    {
        _ellipse(x, y, xradius, yradius);
        return;
    }

    // needed?
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;

    for (angle = stangle; angle < endangle; angle++)
    {
        line(x + (xradius * std::cos(angle * PI_CONV)),
                y - (yradius * std::sin(angle * PI_CONV)),
                x + (xradius * std::cos((angle + 1) * PI_CONV)),
                y - (yradius * std::sin((angle + 1) * PI_CONV)));
    }
}  // ellipse ()

// -----

// Yeah, replicated code. The thing is, I can't catch the bug.

void GfxCanvasBgi::_ellipse(int cx, int cy, int xradius, int yradius)
{
    // from "A Fast Bresenham Type Algorithm For Drawing Ellipses"
    // by John Kennedy
    int x;
    int y;
    int xchange;
    int ychange;
    int ellipseerror;
    int TwoASquare;
    int TwoBSquare;
    int StoppingX;
    int StoppingY;

    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }

    TwoASquare = 2 * xradius * xradius;
    TwoBSquare = 2 * yradius * yradius;
    x = xradius;
    y = 0;
    xchange = yradius * yradius * (1 - 2 * xradius);
    ychange = xradius * xradius;
    ellipseerror = 0;
    StoppingX = TwoBSquare * xradius;
    StoppingY = 0;

    while (StoppingX >= StoppingY)
    {
        // 1st set of points, y' > -1

        // normally, I'd put the line_fill () code here; but
        // the outline gets overdrawn, can't find out why.
        _putpixel(cx + x, cy - y);
        _putpixel(cx - x, cy - y);
        _putpixel(cx - x, cy + y);
        _putpixel(cx + x, cy + y);
        y++;
        StoppingY += TwoASquare;
        ellipseerror += ychange;
        ychange +=TwoASquare;

        if ((2 * ellipseerror + xchange) > 0 )
        {
            x--;
            StoppingX -= TwoBSquare;
            ellipseerror +=xchange;
            xchange += TwoBSquare;
        }
    }  // while

    // 1st point set is done; start the 2nd set of points

    x = 0;
    y = yradius;
    xchange = yradius*yradius;
    ychange = xradius*xradius*(1 - 2 * yradius);
    ellipseerror = 0;
    StoppingX = 0;
    StoppingY = TwoASquare*yradius;

    while (StoppingX <= StoppingY )
    {
        // 2nd set of points, y' < -1

        _putpixel(cx + x, cy - y);
        _putpixel(cx - x, cy - y);
        _putpixel(cx - x, cy + y);
        _putpixel(cx + x, cy + y);
        x++;
        StoppingX += TwoBSquare;
        ellipseerror += xchange;
        xchange +=TwoBSquare;
        if ((2 * ellipseerror + ychange) > 0) {
            y--;
            StoppingY -= TwoASquare;
            ellipseerror += ychange;
            ychange +=TwoASquare;
        }
    }
}  // _ellipse ()

// -----

void GfxCanvasBgi::fillellipse(int cx, int cy, int xradius, int yradius)
{
    // Draws an ellipse centered at (x, y), with axes given by
    // xradius and yradius, and fills it using the current fill color
    // and fill pattern.

    // from "A Fast Bresenham Type Algorithm For Drawing Ellipses"
    // by John Kennedy

    int x;
    int y;
    int xchange;
    int ychange;
    int ellipseerror;
    int TwoASquare;
    int TwoBSquare;
    int StoppingX;
    int StoppingY;

    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }

    TwoASquare = 2 * xradius * xradius;
    TwoBSquare = 2 * yradius * yradius;
    x = xradius;
    y = 0;
    xchange = yradius * yradius * (1 - 2 * xradius);
    ychange = xradius * xradius;
    ellipseerror = 0;
    StoppingX = TwoBSquare * xradius;
    StoppingY = 0;

    while (StoppingX >= StoppingY)
    {
        // 1st set of points, y' > -1

        line_fill(cx + x, cy - y, cx - x, cy - y);
        line_fill(cx - x, cy + y, cx + x, cy + y);
        y++;
        StoppingY += TwoASquare;
        ellipseerror += ychange;
        ychange +=TwoASquare;

        if ((2 * ellipseerror + xchange) > 0 )
        {
            x--;
            StoppingX -= TwoBSquare;
            ellipseerror +=xchange;
            xchange += TwoBSquare;
        }
    }  // while

    // 1st point set is done; start the 2nd set of points

    x = 0;
    y = yradius;
    xchange = yradius * yradius;
    ychange = xradius * xradius * (1 - 2 * yradius);
    ellipseerror = 0;
    StoppingX = 0;
    StoppingY = TwoASquare * yradius;

    while (StoppingX <= StoppingY)
    {
        // 2nd set of points, y' < -1

        line_fill(cx + x, cy - y, cx - x, cy - y);
        line_fill(cx - x, cy + y, cx + x, cy + y);
        x++;
        StoppingX += TwoBSquare;
        ellipseerror += xchange;
        xchange +=TwoBSquare;
        if ((2 * ellipseerror + ychange) > 0)
        {
            y--;
            StoppingY -= TwoASquare;
            ellipseerror += ychange;
            ychange +=TwoASquare;
        }
    }

    // outline

    _ellipse(cx, cy, xradius, yradius);
}  // _ellipse ()

// -----

// helper function for fillpoly ()

static int intcmp(const void *n1, const void *n2)
{
    return (*(const int *) n1) - (*(const int *) n2);
}

// -----

// the following function was adapted from the public domain
// code by Darel Rex Finley,
// http://alienryderflex.com/polygon_fill/

void GfxCanvasBgi::fillpoly(int numpoints, int *polypoints)
{
    // Draws a polygon of numpoints vertices and fills it using the
    // current fill color.
    int nodes;      // number of nodes
    int* nodeX;     // array of nodes
    int ymin;
    int ymax;
    int pixelY;
    int i;
    int j;
    bgiColors tmp;
    bgiColors tmpcolor;

    nodeX = static_cast<int *>(std::calloc(sizeof(int), numpoints));
    if (NULL == nodeX) {
        /* fprintf (stderr, "Can't allocate memory for fillpoly()\n"); */
        return;
    }

    tmp = bgi_fg_color;
    if (bgiFillStyles::EMPTY_FILL == bgi_fill_style.pattern)
    {
        tmpcolor = bgi_bg_color;
    }
    else  // all other styles
    {
        tmpcolor = bgi_fill_style.color;
    }

    setcolor(tmpcolor);

    // find Y maxima

    ymin = ymax = polypoints[1];

    for (i = 0; i < 2 * numpoints; i += 2)
    {
        if (polypoints[i + 1] < ymin)
        {
            ymin = polypoints[i + 1];
        }
        if (polypoints[i + 1] > ymax)
        {
            ymax = polypoints[i + 1];
        }
    }

    //  Loop through the rows of the image.
    for (pixelY = ymin; pixelY < ymax; pixelY++)
    {
        //  Build a list of nodes.
        nodes = 0;
        j = 2 * numpoints - 2;

        for (i = 0; i < 2 * numpoints; i += 2)
        {
            if (
                (static_cast<float>(polypoints[i + 1]) < static_cast<float>(pixelY) &&
                    static_cast<float>(polypoints[j + 1]) >= static_cast<float>(pixelY)) ||
                (static_cast<float>(polypoints[j + 1]) < static_cast<float>(pixelY) &&
                    static_cast<float>(polypoints[i + 1]) >= static_cast<float>(pixelY)))
            {
                nodeX[nodes++] = static_cast<int>(
                    (
                        polypoints[i] + (pixelY - static_cast<float>(polypoints[i + 1])
                    )
                        /
                    (
                        static_cast<float>(polypoints[j + 1]) - static_cast<float>(polypoints[i + 1])
                    )
                        *
                    (polypoints[j] - polypoints[i])));
            }
            j = i;
        }

        // sort the nodes
        qsort(nodeX, nodes, sizeof (int), intcmp);

        // fill the pixels between node pairs.
        for (i = 0; i < nodes; i += 2)
        {
            if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
            {
                line(nodeX[i], pixelY, nodeX[i + 1], pixelY);
            }
            else
            {
                line_fill(nodeX[i], pixelY, nodeX[i + 1], pixelY);
            }
        }
    }  //   for pixelY

    setcolor(tmp);
    drawpoly(numpoints, polypoints);

    free(nodeX);
}  // fillpoly ()

// -----

void GfxCanvasBgi::ff_putpixel(int x, int y)
{
    // similar to putpixel (), but uses fill patterns

    x += vp.left;
    y += vp.top;

    // if the corresponding bit in the pattern is 1
    if ( (GfxCanvasBgiData::fill_patterns[static_cast<int>(bgi_fill_style.pattern)][y % 8] >> x % 8) & 1)
    {
        putpixel_copy(x, y, palette[static_cast<int>(bgi_fill_style.color)]);
    }
    else
    {
        putpixel_copy(x, y, palette[static_cast<int>(bgi_bg_color)]);
    }
}  // ff_putpixel ()

// -----

// the following code is adapted from "A Seed Fill Algorithm"
// by Paul Heckbert, "Graphics Gems", Academic Press, 1990

// Filled horizontal segment of scanline y for xl<=x<=xr.
// Parent segment was on line y-dy. dy=1 or -1

typedef struct {
    int y;
    int xl;
    int xr;
    int dy;
} Segment;

// max depth of stack - was 10000

#define STACKSIZE 2000

Segment stack[STACKSIZE];
Segment* sp = stack;  // stack of filled segments

// the following functions were implemented as unreadable macros

static inline void ff_push(int y, int xl, int xr, int dy, int bottom, int top)
{
    // push new segment on stack
    if ((sp < stack + STACKSIZE) && (y + dy >= 0) && ((y + dy) <= (bottom - top)) )
    {
        sp->y = y;
        sp->xl = xl;
        sp->xr = xr;
        sp->dy = dy;
        sp++;
    }
}

// -----

static inline void ff_pop(int *y, int *xl, int *xr, int *dy)
{
    // pop segment off stack
    sp--;
    *dy = sp->dy;
    *y = sp->y + *dy;
    *xl = sp->xl;
    *xr = sp->xr;
}

// -----

// fill: set the pixel at (x,y) and all of its 4-connected neighbors
// with the same pixel value to the new pixel value nv.
// A 4-connected neighbor is a pixel above, below, left, or right of a pixel.

void GfxCanvasBgi::_floodfill(int x, int y, bgiColors border)
{
    // Fills an enclosed area, containing the x and y points bounded by
    // the border color. The area is filled using the current fill color.

    int start;
    int x1;
    int x2;
    int dy = 0;
    unsigned int oldcol;

    oldcol = getpixel(x, y);
    ff_push(y, x, x, 1, vp.bottom, vp.top);           // needed in some cases
    ff_push(y + 1, x, x, -1, vp.bottom, vp.top);      // seed segment (popped 1st)

    while (sp > stack)
    {
        // pop segment off stack and fill a neighboring scan line

        ff_pop(&y, &x1, &x2, &dy);

        // segment of scan line y-dy for x1<=x<=x2 was previously filled,
        // now explore adjacent pixels in scan line y

        for (x = x1; (x >= 0) && (getpixel(x, y) == oldcol); x--)
        {
            ff_putpixel(x, y);
        }

        if (x >= x1)
        {
            for (x++; (x <= x2) && (getpixel(x, y) == static_cast<uint32_t>(border)); x++)
            {
                continue;
            }
            start = x;
            if (x > x2)
            {
                continue;
            }
        }
        else
        {
            start = x + 1;
            if (start < x1)
            {
                ff_push(y, start, x1 - 1, -dy, vp.bottom , vp.top);    // leak on left?
            }
            x = x1 + 1;
        }
        do
        {
            for (x1 = x; (x <= vp.right) && (getpixel(x, y) != static_cast<uint32_t>(border)); x++)
            {
                ff_putpixel(x, y);
            }
            ff_push(y, start, x - 1, dy, vp.bottom , vp.top);
            if (x > x2 + 1)
            {
                ff_push(y, x2 + 1, x - 1, -dy, vp.bottom, vp.top);    // leak on right?
            }
            for (x++; (x <= x2) && (getpixel(x, y) == static_cast<uint32_t>(border)); x++)
            {
                continue;
            }
            start = x;
        }
        while (x <= x2);  // NOLINT(whitespace/empty_loop_body)
    }  // while
}  // floodfill ()

// -----

#define random(range) (std::rand() % (range))

void GfxCanvasBgi::floodfill(int x, int y, bgiColors border)
{
    bgiColors oldcol;
    int found;
    bgiFillStyles tmp_pattern;
    bgiColors tmp_color;

    oldcol = static_cast<bgiColors>(getpixel(x, y));

    // the way the above implementation of floodfill works,
    // the fill colour must be different than the border colour
    // and the current shape's background color.

    if ((oldcol == border) || (oldcol == bgi_fill_style.color) ||
        (x < 0) || (x > vp.right - vp.left) ||  // out of viewport/window?
        (y < 0) || (y > vp.bottom - vp.top))
    {
        return;
    }

    // special case for fill patterns. The background colour can't be
    // the same in the area to be filled and in the fill pattern.

    if (bgiFillStyles::SOLID_FILL == bgi_fill_style.pattern)
    {
        _floodfill(x, y, border);
        return;
    }
    else
    {  // fill patterns
        if (bgi_bg_color == oldcol)
        {
            // solid fill first...
            tmp_pattern = bgi_fill_style.pattern;
            bgi_fill_style.pattern = bgiFillStyles::SOLID_FILL;
            tmp_color = bgi_fill_style.color;
            // find a suitable temporary fill colour; it must be different
            // than the border and the background
            found = false;
            while (!found)
            {
                bgi_fill_style.color = static_cast<bgiColors>(static_cast<int>(bgiColors::BLUE) +
                                        random(static_cast<int>(bgiColors::WHITE)));
                if ((oldcol != bgi_fill_style.color) &&
                    (border != bgi_fill_style.color))
                {
                    found = true;
                }
            }
            _floodfill(x, y, border);
            // ...then pattern fill
            bgi_fill_style.pattern = tmp_pattern;
            bgi_fill_style.color = tmp_color;
            _floodfill(x, y, border);
        }
        else
        {
            _floodfill(x, y, border);
        }
    }
}  // floodfill ()

// -----

void GfxCanvasBgi::freeimage(void * bitmap)
{
    /* Caller manages memory */
    assert(bitmap != nullptr);
}

// -----

void GfxCanvasBgi::getarccoords(struct arccoordstype *arccoords)
{
    // Gets the coordinates of the last call to arc(), filling the
    // arccoords structure.

    arccoords->x = bgi_last_arc.x;
    arccoords->y = bgi_last_arc.y;
    arccoords->xstart = bgi_last_arc.xstart;
    arccoords->ystart = bgi_last_arc.ystart;
    arccoords->xend = bgi_last_arc.xend;
    arccoords->yend = bgi_last_arc.yend;
}  // getarccoords ()

// -----

GfxCanvasBgi::bgiColors GfxCanvasBgi::getbkcolor(void)
{
    // Returns the current background color.

    return bgi_bg_color;
}  // getbkcolor ()

// -----

GfxCanvasBgi::bgiColors GfxCanvasBgi::getcolor(void)
{
    // Returns the current drawing (foreground) color.

    return bgi_fg_color;
}  // getcolor ()

// -----

struct GfxCanvasBgi::palettetype *GfxCanvasBgi::getdefaultpalette(void)
{
    return &pal;
}  // getdefaultpalette ()

// -----

void GfxCanvasBgi::getfillpattern(char *pattern)
{
    // Copies the user-defined fill pattern, as set by setfillpattern,
    // into the 8-byte area pointed to by pattern.
    int i;

    for (i = 0; i < 8; i++)
    {
        pattern[i] = static_cast<char>(GfxCanvasBgiData::fill_patterns[
                            static_cast<int>(bgiFillStyles::USER_FILL)][i]);
    }
}  // getfillpattern ()

// -----

void GfxCanvasBgi::getfillsettings(struct fillsettingstype *fillinfo)
{
    // Fills the fillsettingstype structure pointed to by fillinfo
    // with information about the current fill pattern and fill color.

    fillinfo->pattern = bgi_fill_style.pattern;
    fillinfo->color = bgi_fill_color;
}  // getfillsettings ()

// -----

void GfxCanvasBgi::getimage(int left, int top, int right, int bottom, void *bitmap)
{
    // Copies a bit image of the specified region into the memory
    // pointed by bitmap.

    uint32_t bitmap_w;
    uint32_t bitmap_h;
    uint32_t* tmp;
    int i = 2;
    int x;
    int y;

    // bitmap has already been malloc()'ed by the user.
    tmp = static_cast<uint32_t *>(bitmap);
    bitmap_w = right - left + 1;
    bitmap_h = bottom - top + 1;

    // copy width and height to the beginning of bitmap
    std::memcpy(tmp, &bitmap_w, sizeof(uint32_t));
    std::memcpy(tmp + 1, &bitmap_h, sizeof(uint32_t));

    // copy image to bitmap
    for (y = (top + vp.top); y <= (bottom + vp.top); y++)
    {
        for (x = (left + vp.left); x <= (right + vp.left); x++)
        {
            tmp [i++] = getpixel_raw(x, y);
        }
    }
}  // getimage ()

// -----

void GfxCanvasBgi::getlinesettings(struct linesettingstype *lineinfo)
{
    // Fills the linesettingstype structure pointed by lineinfo with
    // information about the current line style, pattern, and thickness.

    lineinfo->linestyle = bgi_line_style.linestyle;
    lineinfo->upattern = bgi_line_style.upattern;
    lineinfo->thickness = bgi_line_style.thickness;
}  // getlinesettings ();

// -----

int GfxCanvasBgi::getmaxcolor(void)
{
    // Returns the maximum color value available (MAXCOLORS).

    return GfxCanvasBgiData::kMaxColors;
}  // getmaxcolor ()

// -----

int GfxCanvasBgi::getmaxx()
{
    // Returns the maximum x screen coordinate.

    return bgi_maxx;
}  // getmaxx ()

// -----

int GfxCanvasBgi::getmaxy()
{
    // Returns the maximum y screen coordinate.

    return bgi_maxy;
}  // getmaxy ()

// -----

void GfxCanvasBgi::getpalette(struct palettetype *palette)
{
    // Fills the palettetype structure pointed by palette with
    // information about the current palette’s size and colors.
    int i;

    for (i = 0; i <= GfxCanvasBgiData::kMaxColors; i++)
    {
        palette->colors[i] = pal.colors[i];
    }
}  // getpalette ()

// -----

int GfxCanvasBgi::getpalettesize(struct palettetype *palette)
{
    // Returns the size of the palette.
    assert(palette != nullptr);

    return (1 + GfxCanvasBgiData::kMaxColors);
}  // getpalettesize ()

// -----

uint32_t GfxCanvasBgi::getpixel_raw(int x, int y)
{
    return bgi_activepage[y * (bgi_maxx + 1) + x];
}  // getpixel_raw ()

// -----

unsigned int GfxCanvasBgi::getpixel(int x, int y)
{
    // Returns the color of the pixel located at (x, y).

    int col;
    uint32_t tmp;

    x += vp.left;
    y += vp.top;

    // out of screen?
    if (!is_in_range(x, 0, bgi_maxx) &&
        !is_in_range(y, 0, bgi_maxy))
    {
        return static_cast<int>(bgi_bg_color);
    }

    tmp = getpixel_raw(x, y);

    // now find the colour

    for (col = static_cast<int>(bgiColors::BLACK); col < (static_cast<int>(bgiColors::WHITE) + 1); col++)
    {
        if (tmp == palette[col])
        {
            return static_cast<int>(col);
        }
    }

    // if it's not a BGI color, just return the 0xAARRGGBB value
    return tmp;
}  // getpixel ()

// -----

void GfxCanvasBgi::gettextsettings(struct textsettingstype *texttypeinfo)
{
    // Fills the textsettingstype structure pointed to by texttypeinfo
    // with information about the current text font, direction, size,
    // and justification.

    texttypeinfo->font = bgi_txt_style.font;
    texttypeinfo->direction = bgi_txt_style.direction;
    texttypeinfo->charsize = bgi_txt_style.charsize;
    texttypeinfo->horiz = bgi_txt_style.horiz;
    texttypeinfo->vert = bgi_txt_style.vert;
}  // gettextsettings ()

// -----

void GfxCanvasBgi::getviewsettings(struct viewporttype *viewport)
{
    // Fills the viewporttype structure pointed to by viewport with
    // information about the current viewport.

    viewport->left = vp.left;
    viewport->top = vp.top;
    viewport->right = vp.right;
    viewport->bottom = vp.bottom;
    viewport->clip = vp.clip;
}  // getviewsettings ()

// -----

int GfxCanvasBgi::getx(void)
{
    // Returns the current viewport’s x coordinate.

    return bgi_cp_x;
}  // getx ()

// -----

int GfxCanvasBgi::gety(void)
{
    // Returns the current viewport’s y coordinate.

    return bgi_cp_y;
}  // gety ()

// -----

void GfxCanvasBgi::graphdefaults(void)
{
    // Resets all graphics settings to their defaults.

    int i;

    initpalette();

    // initialise the graphics writing mode
    bgi_writemode = bgiDrawingMode::COPY_PUT;

    // initialise the viewport
    vp.left = 0;
    vp.top = 0;

    vp.right = bgi_maxx;
    vp.bottom = bgi_maxy;
    vp.clip = false;

    // initialise the CP
    bgi_cp_x = 0;
    bgi_cp_y = 0;

    // initialise the text settings
    bgi_txt_style.font = bgiFonts::DEFAULT_FONT;
    bgi_txt_style.direction = bgiDirection::HORIZ_DIR;
    bgi_txt_style.charsize = 1;
    bgi_txt_style.horiz = bgiTextJustification::LEFT_TEXT;
    bgi_txt_style.vert = bgiTextJustification::TOP_TEXT;

    // initialise the fill settings
    bgi_fill_style.pattern =  bgiFillStyles::SOLID_FILL;
    bgi_fill_style.color = bgiColors::WHITE;

    // initialise the line settings
    bgi_line_style.linestyle = bgiLineStyle::SOLID_LINE;
    bgi_line_style.upattern = bgiFillStyles::SOLID_FILL;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;

    // initialise the palette
    pal.size = 1 + GfxCanvasBgiData::kMaxColors;
    for (i = 0; i < (GfxCanvasBgiData::kMaxColors + 1); i++)
    {
        pal.colors[i] = i;
    }
}  // graphdefaults ()

// -----

unsigned GfxCanvasBgi::imagesize(int left, int top, int right, int bottom)
{
    // Returns the size in bytes of the memory area required to store
    // a bit image.

    return (2 * sizeof(uint32_t) +  // witdth, height
            (right - left + 1) * (bottom - top + 1) * sizeof(uint32_t));
}  // imagesize ()

// -----

void GfxCanvasBgi::initpalette(void)
{
    int i;

    for (i = static_cast<int>(bgiColors::BLACK); i < (static_cast<int>(bgiColors::WHITE) + 1); i++)
    {
        palette[i] = GfxCanvasBgiData::bgi_palette[i];
    }
}  // initpalette ()

// -----

// Bresenham's line algorithm routines that implement logical
// operations: copy, xor, and, or, not.

void GfxCanvasBgi::line_copy(int x1, int y1, int x2, int y2)
{
    int counter = 0;  // # of pixel plotted
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        // plot the pixel only if the corresponding bit
        // in the current pattern is set to 1

        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_copy(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((GfxCanvasBgiData::line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_copy(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }

        counter++;

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_copy ()

// -----

void GfxCanvasBgi::line_xor(int x1, int y1, int x2, int y2)
{
    int counter = 0;  // # of pixel plotted
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_xor(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((GfxCanvasBgiData::line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_xor(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }

        counter++;

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_xor ()

// -----

void GfxCanvasBgi::line_and(int x1, int y1, int x2, int y2)
{
    int counter = 0;  // # of pixel plotted
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    for (;;)
    {
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_and(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((GfxCanvasBgiData::line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_and(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }

        counter++;

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_and ()

// -----

void GfxCanvasBgi::line_or(int x1, int y1, int x2, int y2)
{
    int counter = 0;  // # of pixel plotted
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_or(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((GfxCanvasBgiData::line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_or(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }

        counter++;

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_or ()

// -----

void GfxCanvasBgi::line_not(int x1, int y1, int x2, int y2)
{
    int counter = 0;  // # of pixel plotted
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        if (bgiLineStyle::SOLID_LINE == bgi_line_style.linestyle)
        {
            putpixel_not(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
        }
        else
        {
            if ((GfxCanvasBgiData::line_patterns[static_cast<int>(bgi_line_style.linestyle)] >> counter % 16) & 1)
            {
                putpixel_not(x1, y1, palette[static_cast<int>(bgi_fg_color)]);
            }
        }

        counter++;

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_not ()

// -----

void GfxCanvasBgi::line_fill(int x1, int y1, int x2, int y2)
{
    // line routin used for filling

    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        ff_putpixel(x1, y1);

        if ((x1 == x2) && (y1 == y2))
        {
            break;
        }
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }  // for
}  // line_fill ()

// -----

int GfxCanvasBgi::octant(int x, int y)
{
    // returns the octant where x, y lies.

    if (x >= 0)
    {  // octants 1, 2, 7, 8
        if (y >= 0)
        {
            return (x > y) ? 1 : 2;
        }
        else
        {
            return (x > -y) ? 8 : 7;
        }
    }  // if (x > 0)
    else
    {  // x < 0; 3, 4, 5, 6
        if (y >= 0)
        {
            return (-x > y) ? 4 : 3;
        }
        else
        {
            return (-x > -y) ? 5 : 6;
        }
    }  // else
}  // octant()

// -----

void GfxCanvasBgi::line(int x1, int y1, int x2, int y2)
{
    // Draws a line between two specified points.

    int oct;

    // viewport
    x1 += vp.left;
    y1 += vp.top;
    x2 += vp.left;
    y2 += vp.top;

    switch (bgi_writemode)
    {
        case bgiDrawingMode::COPY_PUT:
            line_copy(x1, y1, x2, y2);
            break;
        case bgiDrawingMode::AND_PUT:
            line_and(x1, y1, x2, y2);
            break;
        case bgiDrawingMode::XOR_PUT:
            line_xor(x1, y1, x2, y2);
            break;
        case bgiDrawingMode::OR_PUT:
            line_or(x1, y1, x2, y2);
            break;
        case bgiDrawingMode::NOT_PUT:
            line_not(x1, y1, x2, y2);
            break;
    }  // switch

    if (bgiLineThickness::THICK_WIDTH == bgi_line_style.thickness)
    {
        oct = octant(x2 - x1, y1 - y2);

        switch (oct)
        {  // draw thick line
            case 1:
            case 4:
            case 5:
            case 8:
                switch (bgi_writemode) {
                    case bgiDrawingMode::COPY_PUT:
                        line_copy(x1, y1 - 1, x2, y2 - 1);
                        line_copy(x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::AND_PUT:
                        line_and(x1, y1 - 1, x2, y2 - 1);
                        line_and(x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::XOR_PUT:
                        line_xor(x1, y1 - 1, x2, y2 - 1);
                        line_xor(x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::OR_PUT:
                        line_or(x1, y1 - 1, x2, y2 - 1);
                        line_or(x1, y1 + 1, x2, y2 + 1);
                        break;
                    case bgiDrawingMode::NOT_PUT:
                        line_not(x1, y1 - 1, x2, y2 - 1);
                        line_not(x1, y1 + 1, x2, y2 + 1);
                        break;
                }  // switch
                break;
            case 2:
            case 3:
            case 6:
            case 7:
                switch (bgi_writemode) {
                    case bgiDrawingMode::COPY_PUT:
                        line_copy(x1 - 1, y1, x2 - 1, y2);
                        line_copy(x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::AND_PUT:
                        line_and(x1 - 1, y1, x2 - 1, y2);
                        line_and(x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::XOR_PUT:
                        line_xor(x1 - 1, y1, x2 - 1, y2);
                        line_xor(x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::OR_PUT:
                        line_or(x1 - 1, y1, x2 - 1, y2);
                        line_or(x1 + 1, y1, x2 + 1, y2);
                        break;
                    case bgiDrawingMode::NOT_PUT:
                        line_not(x1 - 1, y1, x2 - 1, y2);
                        line_not(x1 + 1, y1, x2 + 1, y2);
                        break;
                }  // switch
                break;
        }  // switch
    }  // if (THICK_WIDTH...)
}  // line ()

// -----

void GfxCanvasBgi::linerel(int dx, int dy)
{
    // Draws a line from the CP to a point that is (dx,dy)
    // pixels from the CP.

    line(bgi_cp_x, bgi_cp_y, bgi_cp_x + dx, bgi_cp_y + dy);
    bgi_cp_x += dx;
    bgi_cp_y += dy;
}  // linerel ()

// -----

void GfxCanvasBgi::lineto(int x, int y)
{
    // Draws a line from the CP to (x, y), then moves the CP to (dx, dy).

    line(bgi_cp_x, bgi_cp_y, x, y);
    bgi_cp_x = x;
    bgi_cp_y = y;
}  // lineto ()

void GfxCanvasBgi::moverel(int dx, int dy)
{
    // Moves the CP by (dx, dy) pixels.

    bgi_cp_x += dx;
    bgi_cp_y += dy;
}  // moverel ()

// -----

void GfxCanvasBgi::moveto(int x, int y)
{
    // Moves the CP to the position (x, y), relative to the viewport.

    bgi_cp_x = x;
    bgi_cp_y = y;
}  // moveto ()

// -----

void GfxCanvasBgi::_bar(int left, int top, int right, int bottom)
{
    // service routine
    int y;
    bgiColors tmp;

    // like bar (), but uses bgi_fg_color

    tmp = bgi_fg_color;
    // setcolor (bgi_fg_color);
    for (y = top; y <= bottom; y++)
    {
        line(left, y, right, y);
    }

    setcolor(tmp);
}  // _bar ()

// -----

void GfxCanvasBgi::drawchar(unsigned char ch)
{
    // used by outtextxy ()

    unsigned char i;
    unsigned char j;
    unsigned char k;
    int x;
    int y;
    bgiColors tmp;

    tmp = bgi_bg_color;
    bgi_bg_color = bgi_fg_color;  // for bar ()
    setcolor(bgi_bg_color);

    // for each of the 8 bytes that make up the font

    for (i = 0; i < bgi_font_height; i++)
    {
        k = fontptr[bgi_font_height*ch + i];

        // scan horizontal line
        for (j = 0; j < bgi_font_width; j++)
        {
            if ( (k << j) & 0x80)
            {  // bit set to 1
                if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
                {
                    x = bgi_cp_x + j * bgi_font_mag_x;
                    y = bgi_cp_y + i * bgi_font_mag_y;
                    // putpixel (x, y, bgi_fg_color);
                    _bar(x, y, x + bgi_font_mag_x - 1, y + bgi_font_mag_y - 1);
                }
                else
                {
                    x = bgi_cp_x + i * bgi_font_mag_y;
                    y = bgi_cp_y - j * bgi_font_mag_x;
                    // putpixel (bgi_cp_x + i, bgi_cp_y - j, bgi_fg_color);
                    _bar(x, y, x + bgi_font_mag_x - 1, y + bgi_font_mag_y - 1);
                }
            }
        }
    }

    if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
    {
        bgi_cp_x += bgi_font_width * bgi_font_mag_x;
    }
    else
    {
        bgi_cp_y -= bgi_font_height * bgi_font_mag_y;
    }

    bgi_bg_color = tmp;
}  // drawchar ()

// -----

void GfxCanvasBgi::outtext(char *textstring)
{
    // Outputs textstring at the CP.

    outtextxy(bgi_cp_x, bgi_cp_y, textstring);
    if  (
         (bgiDirection::HORIZ_DIR == bgi_txt_style.direction) &&
         (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz)
        )
    {
        bgi_cp_x += textwidth(textstring);
    }
}  // outtext ()

// -----

void GfxCanvasBgi::outtextxy(int x, int y, char *textstring)
{
    // Outputs textstring at (x, y).

    int i;
    int x1 = 0;
    int y1 = 0;
    int tw;
    int th;

    bgiLineThickness tmp;

    tw = textwidth(textstring);
    if (0 == tw)
    {
        return;
    }

    th = textheight(textstring);

    if (bgiDirection::HORIZ_DIR == bgi_txt_style.direction)
    {
        if (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz)
        {
            x1 = x;
        }

        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.horiz)
        {
            x1 = x - tw / 2;
        }

        if (bgiTextJustification::RIGHT_TEXT == bgi_txt_style.horiz)
        {
            x1 = x - tw;
        }

        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.vert)
        {
            y1 = y - th / 2;
        }

        if (bgiTextJustification::TOP_TEXT == bgi_txt_style.vert)
        {
            y1 = y;
        }

        if (bgiTextJustification::BOTTOM_TEXT == bgi_txt_style.vert)
        {
            y1 = y - th;
        }
    }
    else
    {  // VERT_DIR
        if (bgiTextJustification::LEFT_TEXT == bgi_txt_style.horiz)
        {
            y1 = y;
        }

        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.horiz)
        {
            y1 = y + tw / 2;
        }

        if (bgiTextJustification::RIGHT_TEXT == bgi_txt_style.horiz)
        {
            y1 = y + tw;
        }

        if (bgiTextJustification::CENTER_TEXT == bgi_txt_style.vert)
        {
            x1 = x - th / 2;
        }

        if (bgiTextJustification::TOP_TEXT == bgi_txt_style.vert)
        {
            x1 = x;
        }

        if (bgiTextJustification::BOTTOM_TEXT == bgi_txt_style.vert)
        {
            x1 = x - th;
        }
    }  // VERT_DIR

    moveto(x1, y1);

    // if THICK_WIDTH, fallback to NORM_WIDTH
    tmp = bgi_line_style.thickness;
    bgi_line_style.thickness = bgiLineThickness::NORM_WIDTH;

    for (i = 0; i < static_cast<int>(std::strlen(textstring)); i++)
    {
        drawchar(textstring[i]);
    }

    bgi_line_style.thickness = tmp;
}  // outtextxy ()

// -----

void GfxCanvasBgi::pieslice(int x, int y, int stangle, int endangle, int radius)
{
    // Draws and fills a pie slice centered at (x, y), with a radius
    // given by radius, traveling from stangle to endangle.

    // quick and dirty for now, Bresenham-based later.
    int angle;

    if ((0 == radius) || (stangle == endangle))
    {
        return;
    }

    if (endangle < stangle)
    {
        endangle += 360;
    }

    if (0 == radius)
    {
        return;
    }

    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (radius * std::cos(stangle * PI_CONV));
    bgi_last_arc.ystart = y - (radius * std::sin(stangle * PI_CONV));
    bgi_last_arc.xend = x + (radius * std::cos(endangle * PI_CONV));
    bgi_last_arc.yend = y - (radius * std::sin(endangle * PI_CONV));

    for (angle = stangle; angle < endangle; angle++)
    {
        line(x + (radius * std::cos(angle * PI_CONV)),
                y - (radius * std::sin(angle * PI_CONV)),
                x + (radius * std::cos((angle + 1) * PI_CONV)),
                y - (radius * std::sin((angle + 1) * PI_CONV)));
    }
    line(x, y, bgi_last_arc.xstart, bgi_last_arc.ystart);
    line(x, y, bgi_last_arc.xend, bgi_last_arc.yend);

    angle = (stangle + endangle) / 2;
    floodfill(x + (radius * std::cos(angle * PI_CONV)) / 2,
                y - (radius * std::sin(angle * PI_CONV)) / 2,
                bgi_fg_color);
}  // arc ()

// -----

void GfxCanvasBgi::putimage(int left, int top, void *bitmap, bgiDrawingMode op)
{
    // Puts the bit image pointed to by bitmap onto the screen.

    uint32_t bitmap_w;
    uint32_t bitmap_h;
    uint32_t* tmp;
    int i = 2;
    int x;
    int y;

    tmp = reinterpret_cast<uint32_t *>(bitmap);

    // get width and height info from bitmap
    std::memcpy(&bitmap_w, tmp, sizeof(uint32_t));
    std::memcpy(&bitmap_h, tmp + 1, sizeof(uint32_t));

    // put bitmap to the screen
    for (y = (top + vp.top); y < static_cast<int>((top + vp.top + bitmap_h)); y++)
    {
        for (x = (left + vp.left); x < static_cast<int>((left + vp.left + bitmap_w)); x++)
        {
            switch (op)
            {
                case bgiDrawingMode::COPY_PUT:
                    putpixel_copy(x, y, tmp[i++]);
                    break;
                case bgiDrawingMode::AND_PUT:
                    putpixel_and(x, y, tmp[i++]);
                    break;
                case bgiDrawingMode::XOR_PUT:
                    putpixel_xor(x, y, tmp[i++]);
                    break;
                case bgiDrawingMode::OR_PUT:
                    putpixel_or(x, y, tmp[i++]);
                    break;
                case bgiDrawingMode::NOT_PUT:
                    putpixel_not(x, y, tmp[i++]);
                    break;
            }  // switch
        }
    }
}  // putimage ()

// -----

void GfxCanvasBgi::_putpixel(int x, int y)
{
    // line putpixel (), but not updated

    // viewport range is taken care of by this function only,
    // since all others use it to draw.

    x += vp.left;
    y += vp.top;

    switch (bgi_writemode)
    {
        case bgiDrawingMode::XOR_PUT:
            putpixel_xor(x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
        case bgiDrawingMode::AND_PUT:
            putpixel_and(x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
        case bgiDrawingMode::OR_PUT:
            putpixel_or(x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
        case bgiDrawingMode::NOT_PUT:
            putpixel_not(x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
        default:
        case bgiDrawingMode::COPY_PUT:
            putpixel_copy(x, y, palette[static_cast<int>(bgi_fg_color)]);
            break;
    }  // switch
}  // _putpixel ()

// -----

void GfxCanvasBgi::putpixel_copy(int x, int y, uint32_t pixel)
{
    // plain putpixel - no logical operations

    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }

    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }

    bgi_activepage[y * (bgi_maxx + 1) + x] = pixel;

    // we could use the native function:
    // SDL_RenderDrawPoint (bgi_renderer, x, y);
    // but strangely it's slower
}  // putpixel_copy ()

// -----

void GfxCanvasBgi::putpixel_xor(int x, int y, uint32_t pixel)
{
    // XOR'ed putpixel

    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }

    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }

    bgi_activepage[y * (bgi_maxx + 1) + x] ^= (pixel & 0x00ffffff);
}  // putpixel_xor ()

// -----

void GfxCanvasBgi::putpixel_and(int x, int y, uint32_t pixel)
{
    // AND-ed putpixel

    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }

    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }

    bgi_activepage[y * (bgi_maxx + 1) + x] &= (pixel & 0x00ffffff);
}  // putpixel_and ()

// -----

void GfxCanvasBgi::putpixel_or(int x, int y, uint32_t pixel)
{
    // OR-ed putpixel
    uint32_t pix = pixel & 0x00ffffff;

    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }

    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }

    bgi_activepage[y * (bgi_maxx + 1) + x] |= pix;
}  // putpixel_or ()

// -----

void GfxCanvasBgi::putpixel_not(int x, int y, uint32_t pixel)
{
    // NOT-ed putpixel
    assert(pixel < 0x00FFFFFF);

    // out of range?
    if ((x < 0) || (x > bgi_maxx) || (y < 0) || (y > bgi_maxy))
    {
        return;
    }

    if (true == vp.clip)
    {
        if (x < vp.left || x > vp.right || y < vp.top || y > vp.bottom)
        {
            return;
        }
    }

    // !!!BUG???
    bgi_activepage[y * (bgi_maxx + 1) + x] = ~bgi_activepage [y * (bgi_maxx + 1) + x];
}  // putpixel_not ()

// -----

void GfxCanvasBgi::putpixel(int x, int y, int color)
{
    // Plots a point at (x,y) in the color defined by color.
    int tmpcolor;

    x += vp.left;
    y += vp.top;

    // clip
    if (true == vp.clip)
    {
        if ((x < vp.left) || (x > vp.right) || (y < vp.top) || (y > vp.bottom))
        {
            return;
        }
    }

    tmpcolor = color;

    switch (bgi_writemode)
    {
        case bgiDrawingMode::XOR_PUT:
            putpixel_xor(x, y, palette[tmpcolor]);
            break;
        case bgiDrawingMode::AND_PUT:
            putpixel_and(x, y, palette[tmpcolor]);
            break;
        case bgiDrawingMode::OR_PUT:
            putpixel_or(x, y, palette[tmpcolor]);
            break;
        case bgiDrawingMode::NOT_PUT:
            putpixel_not(x, y, palette[tmpcolor]);
            break;
        default:
        case bgiDrawingMode::COPY_PUT:
            putpixel_copy(x, y, palette[tmpcolor]);
       }  // switch
}  // putpixel ()

// -----

void GfxCanvasBgi::rectangle(int x1, int y1, int x2, int y2)
{
    // Draws a rectangle delimited by (left,top) and (right,bottom).

    line(x1, y1, x2, y1);
    line(x2, y1, x2, y2);
    line(x2, y2, x1, y2);
    line(x1, y2, x1, y1);
}  // rectangle ()

// -----

void GfxCanvasBgi::sector(int x, int y, int stangle, int endangle, int xradius, int yradius)
{
    // Draws and fills an elliptical pie slice centered at (x, y),
    // horizontal and vertical radii given by xradius and yradius,
    // traveling from stangle to endangle.

    // quick and dirty for now, Bresenham-based later.
    int angle;
    bgiColors tmpcolor;

    if ((0 == xradius) && (0 == yradius))
    {
        return;
    }

    if (endangle < stangle)
    {
        endangle += 360;
    }

    // really needed?
    bgi_last_arc.x = x;
    bgi_last_arc.y = y;
    bgi_last_arc.xstart = x + (xradius * std::cos(stangle * PI_CONV));
    bgi_last_arc.ystart = y - (yradius * std::sin(stangle * PI_CONV));
    bgi_last_arc.xend = x + (xradius * std::cos(endangle * PI_CONV));
    bgi_last_arc.yend = y - (yradius * std::sin(endangle * PI_CONV));

    for (angle = stangle; angle < endangle; angle++)
    {
        line(x + (xradius * std::cos(angle * PI_CONV)),
            y - (yradius * std::sin(angle * PI_CONV)),
            x + (xradius * std::cos((angle + 1) * PI_CONV)),
            y - (yradius * std::sin((angle + 1) * PI_CONV)));
    }
    line(x, y, bgi_last_arc.xstart, bgi_last_arc.ystart);
    line(x, y, bgi_last_arc.xend, bgi_last_arc.yend);

    tmpcolor = bgi_fg_color;
    setcolor(bgi_fill_style.color);
    angle = (stangle + endangle) / 2;
    // find a point within the sector
    floodfill(x + (xradius * std::cos(angle * PI_CONV)) / 2,
                y - (yradius * std::sin(angle * PI_CONV)) / 2,
                tmpcolor);
}  // sector ()

// -----

void GfxCanvasBgi::setallpalette(struct palettetype *palette)
{
    // Sets the current palette to the values given in palette.
    int i;

    for (i = 0; i <= GfxCanvasBgiData::kMaxColors; i++)
    {
        if (palette->colors[i] != -1)
        {
            setpalette(i, palette->colors[i]);
        }
    }
}  // setallpalette ()

// -----

void GfxCanvasBgi::setbkcolor(bgiColors col)
{
    bgi_bg_color = col;
}  // setbkcolor ()

// -----

void GfxCanvasBgi::setcolor(bgiColors col)
{
    bgi_fg_color = col;
}  // setcolor ()

// -----

void GfxCanvasBgi::setfillpattern(uint8_t *upattern, bgiColors color)
{
    // Sets a user-defined fill pattern.
    int i;

    for (i = 0; i < 8; i++)
    {
        GfxCanvasBgiData::fill_patterns[static_cast<int>(bgiFillStyles::USER_FILL)][i] = *upattern;
        upattern += 1;
    }

    bgi_fill_style.color = color;
    bgi_fill_style.pattern = bgiFillStyles::USER_FILL;
}  // setfillpattern ()

// -----

void GfxCanvasBgi::setfillstyle(bgiFillStyles pattern, bgiColors color)
{
    // Sets the fill pattern and fill color.

    bgi_fill_style.pattern = pattern;
    bgi_fill_style.color = color;
}  // setfillstyle ()

// -----

void GfxCanvasBgi::setlinestyle(bgiLineStyle linestyle, bgiFillStyles upattern, bgiLineThickness thickness)
{
    // Sets the line width and style for all lines drawn by line(),
    // lineto(), rectangle(), drawpoly(), etc.

    bgi_line_style.linestyle = linestyle;
    GfxCanvasBgiData::line_patterns[static_cast<int>(bgiLineStyle::USERBIT_LINE)] = static_cast<uint16_t>(upattern);
    bgi_line_style.upattern = upattern;
    bgi_line_style.thickness = thickness;
}  // setlinestyle ()

// -----

void GfxCanvasBgi::setpalette(int colornum, int color)
{
    // Changes the standard palette colornum to color.

    palette[colornum] = GfxCanvasBgiData::bgi_palette[color];
}  // setpalette ()

// -----

void GfxCanvasBgi::settextjustify(bgiTextJustification horiz, bgiTextJustification vert)
{
    // Sets text justification.

    bgi_txt_style.horiz = horiz;
    bgi_txt_style.vert = vert;
}  // settextjustify ()

// -----

void GfxCanvasBgi::settextstyle(int font, bgiDirection direction, int charsize)
{
    // Sets the text font (only DEFAULT FONT is actually available),
    // the direction in which text is displayed (HORIZ DIR, VERT DIR),
    // and the size of the characters.

    if (bgiDirection::VERT_DIR == direction)
    {
        bgi_txt_style.direction = bgiDirection::VERT_DIR;
    }
    else
    {
        bgi_txt_style.direction = bgiDirection::HORIZ_DIR;
    }
    bgi_txt_style.charsize = bgi_font_mag_x = bgi_font_mag_y = charsize;
    // avoid compiler warning
    assert(font >= 0);
}  // settextstyle ()

// -----

void GfxCanvasBgi::setusercharsize(int multx, int divx, int multy, int divy)
{
    // Lets the user change the character width and height.

    bgi_font_mag_x = static_cast<float>(multx) / static_cast<float>(divx);
    bgi_font_mag_y = static_cast<float>(multy) / static_cast<float>(divy);
}  // setusercharsize ()

// -----

void GfxCanvasBgi::setviewport(int left, int top, int right, int bottom, int clip)
{
    // Sets the current viewport for graphics output.

    if ((left < 0) || (right > bgi_maxx) || (top < 0) || (bottom > bgi_maxy))
    {
        return;
    }

    vp.left = left;
    vp.top = top;
    vp.right = right;
    vp.bottom = bottom;
    vp.clip = clip;
    bgi_cp_x = 0;
    bgi_cp_y = 0;
}  // setviewport ()

// -----

void GfxCanvasBgi::setwritemode(bgiDrawingMode mode)
{
    // Sets the writing mode for line drawing. mode can be COPY PUT,
    // XOR PUT, OR PUT, AND PUT, and NOT PUT.

    bgi_writemode = mode;
}  // setwritemode ()

// -----

int GfxCanvasBgi::textheight(char *textstring)
{
    // Returns the height in pixels of a string.
    // avoid compiler warning
    assert(textstring != nullptr);;

    return bgi_font_mag_y * bgi_font_height;
}  // textheight ()

// -----

int GfxCanvasBgi::textwidth(char *textstring)
{
    // Returns the height in pixels of a string.

    return (std::strlen (textstring) * bgi_font_width * bgi_font_mag_x);
}  // textwidth ()

// --- end of file SDL_bgi.c

}  // namespace bgi

}  // namespace gfx

/* EOF */

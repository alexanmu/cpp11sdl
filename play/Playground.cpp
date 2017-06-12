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

#include <cassert>
#include "Playground.hpp"

/******************************************************* Benchmark *******************************************************/
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <cstring>
#include <cfloat>

#define SZ_X 16384
#define SZ_Y 16384
#define EXEC_CNT 10

#define BYTE_PATTERN 0x11223344

double Playground::Algo0(std::uint32_t * ptr)
{
    int i;
    int j;

    auto start = std::chrono::high_resolution_clock::now();
    for (i = 0; i < SZ_Y; i++)
    {
        for (j = 0; j < SZ_X; j++)
        {
            ptr[i * SZ_Y + j] = BYTE_PATTERN;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != BYTE_PATTERN)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

double Playground::Algo1(std::uint32_t * ptr)
{
    uint32_t i;
    uint32_t j;

    std::uint32_t max = SZ_X * SZ_Y;
    if (max % 16 != 0)
    {
        std::cout << "Loop unroll trebuie facut calumea daca max % 16 != 0!";
    }
    i = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while (i < max)
    {
        *(ptr + i + 0) = BYTE_PATTERN;
        *(ptr + i + 1) = BYTE_PATTERN;
        *(ptr + i + 2) = BYTE_PATTERN;
        *(ptr + i + 3) = BYTE_PATTERN;
        *(ptr + i + 4) = BYTE_PATTERN;
        *(ptr + i + 5) = BYTE_PATTERN;
        *(ptr + i + 6) = BYTE_PATTERN;
        *(ptr + i + 7) = BYTE_PATTERN;
        *(ptr + i + 8) = BYTE_PATTERN;
        *(ptr + i + 9) = BYTE_PATTERN;
        *(ptr + i + 10) = BYTE_PATTERN;
        *(ptr + i + 11) = BYTE_PATTERN;
        *(ptr + i + 12) = BYTE_PATTERN;
        *(ptr + i + 13) = BYTE_PATTERN;
        *(ptr + i + 14) = BYTE_PATTERN;
        *(ptr + i + 15) = BYTE_PATTERN;
        i += 16;
    }
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != BYTE_PATTERN)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

double Playground::Algo2(uint32_t * ptr)
{
    int i;
    int j;

    auto start = std::chrono::high_resolution_clock::now();
    std::memset(ptr, 0x11, SZ_X * SZ_Y * sizeof(uint32_t));
    auto end = std::chrono::high_resolution_clock::now();
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != 0x11111111)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}

#include <thread>

// #pragma GCC push_options
// #pragma GCC optimize("Ofast")
void Algo3Part(uint64_t * ptr, uint64_t * endptr, const uint64_t bp)
{
    while (ptr < endptr )
    {
        *(ptr + 0) = bp;
        *(ptr + 1) = bp;
        *(ptr + 2) = bp;
        *(ptr + 3) = bp;
        *(ptr + 4) = bp;
        *(ptr + 5) = bp;
        *(ptr + 6) = bp;
        *(ptr + 7) = bp;
        ptr += 8;
    }
}

double Playground::Algo3(uint32_t * ptr)
{
    std::uint64_t bp = (std::uint64_t)BYTE_PATTERN << (std::uint64_t)32 | (std::uint64_t)BYTE_PATTERN;
    std::uint64_t max64 = SZ_X * SZ_Y / 2;
    std::uint64_t m = max64 / 4;

    std::uint64_t* p1 = (std::uint64_t*)ptr;
    std::uint64_t* e1 = (std::uint64_t*)(p1 + m);
    std::uint64_t* p2 = (std::uint64_t*)e1;
    std::uint64_t* e2 = (std::uint64_t*)(e1 + m);
    std::uint64_t* p3 = (std::uint64_t*)e2;
    std::uint64_t* e3 = (std::uint64_t*)(e2 + m);
    std::uint64_t* p4 = (std::uint64_t*)e3;
    std::uint64_t* e4 = (std::uint64_t*)(e3 + m);

    std::thread t1;
    std::thread t2;
    std::thread t3;

    auto start = std::chrono::high_resolution_clock::now();
    t1 = std::thread(Algo3Part, p1, e1, bp);
    t2 = std::thread(Algo3Part, p2, e2, bp);
    t3 = std::thread(Algo3Part, p3, e3, bp);
    Algo3Part(p4, e4, bp);
    t1.join();
    t2.join();
    t3.join();
    auto end = std::chrono::high_resolution_clock::now();
    //
    int i;
    int j;
    i = SZ_Y - 1;
    j = SZ_X - 1;
    if (ptr[i * SZ_Y + j] != BYTE_PATTERN)
    {
        std::cout << "Error!" << std::endl;
    }
    return std::chrono::duration<double>(end - start).count();
}
// #pragma GCC pop_options

void Playground::DoAlgo(const int algo_index)
{
    int k;
    double diff[EXEC_CNT];
    std::uint32_t* ptr;
    int step_new;
    int step_old = 0;
    void * buff;
    size_t buffsize;
    double (Playground::*algo_ptr)(uint32_t*);

    switch (algo_index)
    {
        case 0:
            std::cout << "Algo0 selected - standard Matrix" << std::endl;
            algo_ptr = &Playground::Algo0;
            break;
        case 1:
            std::cout << "Algo1 selected - liniar; manual loop unroll" << std::endl;
            algo_ptr = &Playground::Algo1;
            break;
        case 2:
            std::cout << "Algo2 selected - memset" << std::endl;
            algo_ptr = &Playground::Algo2;
            break;
        case 3:
            std::cout << "Algo3 selected - 64 bit pointers" << std::endl;
            algo_ptr = &Playground::Algo3;
            break;
        default:
            std::cout << "Wrong algo index" << std::endl;
            return;
            break;
    }
    buffsize = SZ_X * SZ_Y * sizeof(uint32_t);

    std::cout << ((buffsize / 1024.0) / 1024.0) << "MB dataset" << std::endl;
    buff = std::malloc(buffsize);
    if (buff == NULL)
    {
        std::cout << "malloc fail!" << std::endl;
        exit(1);
    }

    ptr = (std::uint32_t *)buff;

    (void)((this)->*(algo_ptr))(ptr);
    for (k = 0; k < EXEC_CNT; k++)
    {
        step_new = (k * 100) / EXEC_CNT;
        if (step_new != step_old)
        {
            if (step_new % 5 == 0) std::cout << ".";
            std::cout.flush();
            step_old = step_new;
        }
        diff[k] = ((this)->*(algo_ptr))(ptr);
        std::memset(buff, 0, buffsize);
    }
    std::cout << " done." << std::endl;
    double sum = 0.0;
    double min = DBL_MAX;
    double max = DBL_MIN;
    int min_index = -1;
    int max_index = -1;
    for (k = 0; k < EXEC_CNT; k++)
    {
        sum += diff[k];
        if (diff[k] < min)
        {
            min = diff[k];
            min_index = k;
        }
        if (diff[k] > max)
        {
            max = diff[k];
            max_index = k;
        }
    }
    double avg = sum / EXEC_CNT;
    std::cout << "Done in " << sum << "sec. " << EXEC_CNT << " runs" << std::endl;
    std::cout << "Average of " << avg << "sec" << std::endl;
    std::cout << "Min " << min << "sec. Run " << min_index << std::endl;
    std::cout << "Max " << max << "sec. Run " << max_index << std::endl;
    double bytes_written = static_cast<double>(EXEC_CNT) * static_cast<double>(SZ_X) *
                    static_cast<double>(SZ_Y) * static_cast<double>(sizeof(uint32_t));
    double bw = (((bytes_written / sum) / 1024.0) / 1024.0 / 1024.0);
    std::cout << "Bandwidth=" << bw << " GB/sec" << std::endl;
    std::free(buff);
}

void Playground::_doBenchmark(void)
{
    std::cout << "****************************************" << std::endl;
    DoAlgo(0);
    std::cout << "****************************************" << std::endl;
    DoAlgo(1);
    std::cout << "****************************************" << std::endl;
    DoAlgo(2);
    std::cout << "****************************************" << std::endl;
    DoAlgo(3);
}

/******************************************************* Fonts *******************************************************/
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cstdint>
#include <iterator>

#include <dirent.h>

std::vector<std::string> Playground::FindAllFiles(std::string const& bpath)
{
    std::vector<std::string> files;

    DIR *d;
    struct dirent *dir;
    d = opendir(bpath.c_str());
    if (d)
    {
        dir = readdir(d);
        while (dir != NULL)
        {
            if (std::strcmp(dir->d_name, ".") && std::strcmp(dir->d_name, ".."))
            {
                files.push_back(dir->d_name);
            }
            dir = readdir(d);
        }
    }
    return files;
}

std::string Playground::ToHexStr(uint8_t c)
{
    char hchars[17] = "0123456789ABCDEF";
    char s[5];

    s[0] = '0';
    s[1] = 'x';
    s[2] = hchars[(c & 0xF0) >> 4];
    s[3] = hchars[c & 0x0F];
    s[4] = '\0';

    return std::string(s);
}

void Playground::ProcessBuffer(std::string const& buffname, uint8_t * buff)
{
    std::ofstream hpp(buffname + ".hpp", std::ofstream::out | std::ofstream::trunc);

    hpp << "/*\n";
    hpp << "  Giotto\n";
    hpp << "  Copyright (C) 2017 George Oros\n";
    hpp << "\n";
    hpp << "  This software is provided 'as-is', without any express or implied\n";
    hpp << "  warranty.  In no event will the authors be held liable for any damages\n";
    hpp << "  arising from the use of this software.\n";
    hpp << "\n";
    hpp << "  Permission is granted to anyone to use this software for any purpose,\n";
    hpp << "  including commercial applications, and to alter it and redistribute it\n";
    hpp << "  freely, subject to the following restrictions:\n";
    hpp << "\n";
    hpp << "  1. The origin of this software must not be misrepresented; you must not\n";
    hpp << "     claim that you wrote the original software. If you use this software\n";
    hpp << "     in a product, an acknowledgment in the product documentation would be\n";
    hpp << "     appreciated but is not required.\n";
    hpp << "  2. Altered source versions must be plainly marked as such, and must not be\n";
    hpp << "     misrepresented as being the original software.\n";
    hpp << "  3. This notice may not be removed or altered from any source distribution.\n";
    hpp << "\n";
    hpp << "  See copyright notice at http://lidsdl.org/license.php\n";
    hpp << "*/\n";
    hpp << "\n";
    hpp << "#ifndef __" + buffname + "_hpp__\n";
    hpp << "#define __" + buffname + "_hpp__\n";
    hpp << '\n';
    hpp << "const uint8_t GfxBgiConstants::" << buffname << "Data_[16 * 256] = {" << '\n';
    for (int i = 0; i < 256; i++)
    {
        hpp << "    ";
        for (int j = 0; j < 15; j++)
        {
            hpp << ToHexStr(buff[i * 16 + j]) << ", ";
        }
        hpp << ToHexStr(buff[i * 16 + 15]);
        if (i < 255)
        {
            hpp << ",";
            hpp << '\n';
        }
    }
    hpp << '\n';
    hpp << "};" << "\n\n";
    hpp << "#endif  // __" + buffname + "_hpp__\n";
    hpp.close();
}

std::string Playground::GetFntName(std::string const& fullname)
{
    std::size_t n;
    std::string fname;
    std::string name;
    std::string ext;

    n = fullname.rfind("/");
    fname =  fullname.substr(n + 1);
    n = fname.rfind(".");
    ext = fname.substr(n + 1);
    name = fname.substr(0, n);
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    name[0] = std::toupper(name[0]);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext + name;
}

void Playground::ProcessFNTfile(std::string const& fullname)
{
    std::ifstream inf(fullname, std::ifstream::ate | std::ifstream::binary);
    std::ifstream::pos_type fsize = inf.tellg();
    std::string name;

    name = GetFntName(fullname);

    if (fsize != 4096)
    {
        inf.close();
        return;
    }
    uint8_t buff[4096];
    std::memset(buff, 0, sizeof(buff));

    inf.clear();
    inf.seekg(0);
    inf.read(reinterpret_cast<char *>(&buff[0]), fsize);
    ProcessBuffer(name, &buff[0]);
    inf.close();
}

void Playground::_doFonts(void)
{
    std::cout << "_DoCreateArray()" << std::endl;

    std::string bpath = "/var/fpwork/goros/cpp11work/tool_v4/Files";
    std::vector<std::string> files;
    std::vector<std::string> fntfiles;

    files = FindAllFiles(bpath + "/");
    for (auto it : files)
    {
        std::size_t n = it.rfind(".");

        if (n != std::string::npos)
        {
            std::string tmp = it.substr(n + 1);
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
            if (tmp == "FNT")
            {
                fntfiles.push_back(it);
            }
        }
    }
    for (auto it : fntfiles)
    {
        std::string fullname = bpath + "/" + it;

        std::cout << "Processing file " << GetFntName(fullname) << '\n';
        ProcessFNTfile(fullname);
    }
    std::cout << "Done!" << std::endl;
}

/***************************************************** Palette (SDL) *****************************************************/
#include <iomanip>
#include <sstream>

#include "Linux.h"
#include "macOS.h"
#include "GfxSdlHeader.hpp"

// http://stackoverflow.com/questions/5100718/integer-to-hex-string-in-c
template <typename T>
std::string Playground::IntToHexStr(T value)
{
    std::stringstream stream;

    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) <<\
            std::hex << static_cast<int>(value);
    return stream.str();
}

void Playground::printSdlPalette(void * palptr, const bool printclrs)
{
    gfx::sdl2::SDL_Palette *pal;
    gfx::sdl2::SDL_Color* clr;

    pal = reinterpret_cast<gfx::sdl2::SDL_Palette *>(palptr);
    std::cout << "pal->ncolors=" << pal->ncolors << '\n';
    clr = pal->colors;
    if (clr == nullptr)
    {
        std::cout << "pal->colors=nullptr" << '\n';
    }
    else
    {
        if (printclrs == true)
        {
            for (int i = 0; i < pal->ncolors; i++)
            {
                std::cout << "r=" << static_cast<int>(clr->r) <<\
                        " g=" << static_cast<int>(clr->g) <<\
                        " b=" << static_cast<int>(clr->b) <<\
                        " a=" << static_cast<int>(clr->a) << '\n';
                clr += 1;
            }
        }
        else
        {
            std::cout << "pal->colors=" << IntToHexStr<uint64_t>(reinterpret_cast<uint64_t>(pal->colors)) << '\n';
        }
    }
    std::cout << "pal->version=" << pal->version << '\n';
    std::cout << "pal->refcount=" << pal->refcount << '\n';
    std::cout << std::endl;
}

void Playground::printSdlPixFormat(void * pixfmtptr)
{
    gfx::sdl2::SDL_PixelFormat* pix;

    if (pixfmtptr == nullptr)
    {
        std::cout << "pixfmtptr=nullptr" << '\n';
        return;
    }
    pix = reinterpret_cast<gfx::sdl2::SDL_PixelFormat *>(pixfmtptr);
    std::cout << "pix->format=" << IntToHexStr<uint32_t>(pix->format) << '\n';
    if (pix->palette == nullptr)
    {
        std::cout << "pix->palette=nullptr" << '\n';
    }
    else
    {
        printSdlPalette(pix->palette, true);
    }
    std::cout << "pix->BitsPerPixel=" << static_cast<int>(pix->BitsPerPixel) << '\n';
    std::cout << "pix->BytesPerPixel=" << static_cast<int>(pix->BytesPerPixel) << '\n';
    std::cout << "pix->Rmask=" << IntToHexStr<uint32_t>(pix->Rmask) << '\n';
    std::cout << "pix->Gmask=" << IntToHexStr<uint32_t>(pix->Gmask) << '\n';
    std::cout << "pix->Bmask=" << IntToHexStr<uint32_t>(pix->Bmask)<< '\n';
    std::cout << "pix->Amask=" << IntToHexStr<uint32_t>(pix->Amask) << '\n';
    std::cout << "pix->Rloss=" << IntToHexStr<uint8_t>(pix->Rloss) << '\n';
    std::cout << "pix->Gloss=" << IntToHexStr<uint8_t>(pix->Gloss) << '\n';
    std::cout << "pix->Bloss=" << IntToHexStr<uint8_t>(pix->Bloss)<< '\n';
    std::cout << "pix->Aloss=" << IntToHexStr<uint8_t>(pix->Aloss) << '\n';
    std::cout << "pix->Rshift=" << IntToHexStr<uint8_t>(pix->Rshift) << '\n';
    std::cout << "pix->Gshift=" << IntToHexStr<uint8_t>(pix->Gshift) << '\n';
    std::cout << "pix->Bshift=" << IntToHexStr<uint8_t>(pix->Bshift)<< '\n';
    std::cout << "pix->Ashift=" << IntToHexStr<uint8_t>(pix->Ashift) << '\n';
    std::cout << "pix->refcount=" << IntToHexStr<int>(pix->refcount) << '\n';
    std::cout << "pix->next=" << IntToHexStr<uint64_t>((uint64_t)pix->next) << '\n';
    std::cout << std::endl;
}

void Playground::_doPaletteSdl(void)
{
    std::cout << "TestPalette" << '\n';
    gfx::sdl2::SDL_Palette* pal;

    /* Part 1 */
    pal = gfx::sdl2::SDL_AllocPalette(2);
    printSdlPalette(pal, false);
    for (int i = 0; i < pal->ncolors; i++)
    {
        gfx::sdl2::SDL_Color c;
        c.r = i + 1;
        c.g = i + 1;
        c.b = i + 1;
        c.a = 255 - i - 1;
        SDL_SetPaletteColors(pal, &c, i, 1);
    }
    printSdlPalette(pal, false);
    /* Part 2 */
    gfx::sdl2::SDL_PixelFormat* pix;

    pix = SDL_AllocFormat(gfx::sdl2::SDL_PIXELFORMAT_RGB332);
    if (SDL_SetPixelFormatPalette(pix, pal) != 0)
    {
        std::cout << gfx::sdl2::SDL_GetError() << '\n';
    }
    printSdlPixFormat(pix);

    std::cout << "SDL_GetPixelFormatName(...)=" << gfx::sdl2::SDL_GetPixelFormatName(pix->format) << '\n';
    /* Free stuff */
    SDL_FreePalette(pal);
    SDL_FreeFormat(pix);
    std::cout << "Done!" << std::endl;
}

/***************************************************** Palette (GFX) *****************************************************/
#include "GfxPalette.hpp"
#include "GfxPixelFormat.hpp"

void Playground::_doPaletteGfx(void)
{
    gfx::pixels::GfxPalette g1;
    gfx::pixels::GfxPalette g2(16);
    gfx::sdl2::SDL_Palette* pal = gfx::sdl2::SDL_AllocPalette(256);
    gfx::pixels::GfxPalette g3(pal);
    gfx::sdl2::SDL_FreePalette(pal);
    std::vector<gfx::pixels::GfxColor> vec { { 0xFF, 0xFE, 0xFD }, { 0xFC, 0xFB, 0xFA }, { 0xF9, 0xF8, 0xF7 }, { 0xF6, 0xF5, 0xF4} };
    gfx::pixels::GfxPalette g4(vec);
    
    printSdlPalette(g1.getAsSdlTypePtr(), false);
    printSdlPalette(g2.getAsSdlTypePtr(), false);
    printSdlPalette(g3.getAsSdlTypePtr(), true);
    printSdlPalette(g4.getAsSdlTypePtr(), false);
    
    gfx::pixels::GfxPixelFormat pf1;
    gfx::sdl2::SDL_PixelFormat* pix = gfx::sdl2::SDL_AllocFormat(gfx::sdl2::SDL_PIXELFORMAT_INDEX8);
    gfx::pixels::GfxPixelFormat pf2(pix->format);
    SDL_FreeFormat(pix);
    gfx::pixels::GfxPixelFormat pf3(static_cast<gfx::pixels::GfxPixelFormatEnum>(gfx::sdl2::SDL_PIXELFORMAT_RGB24));
    
    std::cout << "pf1.getFormatAsString()=" << pf1.getPixelFormatName() << '\n';
    std::cout << "pf2.getFormatAsString()=" << pf2.getPixelFormatName() << '\n';
    std::cout << "pf3.getFormatAsString()=" << pf3.getPixelFormatName() << '\n';
    std::cout << "SDL_GetPixelFormatName(...)=" << gfx::sdl2::SDL_GetPixelFormatName(gfx::sdl2::SDL_PIXELFORMAT_INDEX8) << '\n';
}

/***************************************************** CCallback *****************************************************/

#include <iostream>

// http://stackoverflow.com/question/9568150/what-is-a-c-delegate
template <class T>
class CCallback
{
public:
    typedef void (T::*fn)(int anArg);

    CCallback(T& trg, fn op) : m_rTarget(trg), m_Operation(op)
    {
    }

    void Execute(int in)
    {
        (m_rTarget.*m_Operation)(in);
    }

    void operator()(int in)
    {
        (m_rTarget.*m_Operation)(in);
    }
private:
    CCallback() = delete;
    CCallback(CCallback const&) = delete;

    T& m_rTarget;
    fn m_Operation;
};

class A
{
public:
    virtual void Fn(int i)
    {
        std::cout << "i=" << i << std::endl;
    }
};

void Playground::_doCallback(void)
{
    A a;
    CCallback<A> cbk(a, &A::Fn);
    cbk.Execute(3);
    cbk(3);
}

/***************************************************** Component *****************************************************/
#include "GComponent.hpp"

using gto::gobj::GComponent;

void Playground::_doComponent(void)
{
    GComponent* c = new GComponent(GVarName(c), nullptr);

    GComponent* c1 = new GComponent(GVarName(c1), c);
    GComponent* c2 = new GComponent(GVarName(c2), c);
    GComponent* c3 = new GComponent(GVarName(c3), c);
    GComponent* c4 = new GComponent(GVarName(c4), c);

    std::cout << "c1->hasParent()=" << c1->hasParent() << '\n';
    std::cout << "c2->hasParent()=" << c2->hasParent() << '\n';
    std::cout << "c3->hasParent()=" << c3->hasParent() << '\n';
    std::cout << "c4->hasParent()=" << c4->hasParent() << '\n';

    c->insertComponent(c1);
    c->insertComponent(c2);
    c->insertComponent(c3);
    c->insertComponent(c4);

    //c->removeComponent(c2);

    GComponent* c5 = c->findComponent(GVarName(c2));
    if (c5 != nullptr)
    {
        std::cout << "c5->getVName()=" << c5->getVName() << '\n';
    }
    else
    {
        std::cout << "Name not found" << '\n';
    }

    GComponent* t = new GComponent(GVarName(t), c);
    GComponent* ti[10];

    for (int i = 0; i < 10; i++)
    {
        ti[i] = new GComponent(GVarName(ti) + std::to_string(i), t);
        t->insertComponent(ti[i]);
    }

    c->insertComponent(t);

    delete c;

    std::cout << "Done!" << std::endl;
}

/******************************************************* FSO *******************************************************/
#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"
#include "GFileObject.hpp"

using gto::util::GFileSystemObject;
using gto::util::GFolderObject;
using gto::util::GFileObject;

void Playground::_doFSO(void)
{
    GFileSystemObject fso;
    GFolderObject * fo = fso.getFolder(fso._getWorkingDirectory());

    std::cout << "pwd=" << fso._getWorkingDirectory() << std::endl;
    if (fo != nullptr)
    {
        gto::util::GFilesCollection fcoll;
        std::string lastfile;

        fcoll = fo->getFilesCollection();
        for (auto& it : fcoll)
        {
            std::string fn;
            std::string path;

            path = fso._getFilePath(it.getFileSpec());
            fn = fso.getFileName(it.getFileSpec());
            std::cout << it.getFileSpec() << "<>" << fn << "<>" << path << std::endl;
            lastfile = it.getFileSpec();
        }
        gto::util::GFileObject fileo(lastfile);

        std::cout << fileo.getFileName() << std::endl;
        std::cout << fileo.getFilePath() << std::endl;
        std::cout << fileo.getFileSpec() << std::endl;
        std::cout << fileo.getAttributesAsString() << std::endl;
        std::cout << fileo.getDateTimeCreated() << std::endl;
        delete fo;
    }
}

/******************************************************* Meta *******************************************************/
#include "GfxMeta.hpp"
#include "GfxRuntimeMeta.hpp"

#include "GfxColor.hpp"
#include "GfxRect.hpp"

void Playground::_doRuntimeMeta(void)
{
    gfx::rect::GfxPoint pt1;
    gfx::rect::GfxRect rect1;

    gfx::_gfx::GfxRuntimeMeta& rmeta = gfx::_gfx::GfxRuntimeMeta::getInstance();

    std::cout << "rmeta.getClassCount()=" << rmeta.getClassCount() << std::endl;
    for (int32_t index = 0; index < rmeta.getClassCount(); index++)
    {
        auto cinfo = rmeta.getClassInfo(index);
        std::cout << "cinfo.objectInstanceCount_=" << cinfo.objectInstanceCount_ << std::endl;
        std::cout << "cinfo.firstInstanceId_=" << cinfo.firstInstanceId_ << std::endl;
        std::cout << "cinfo.lastInstanceId_=" << cinfo.lastInstanceId_ << std::endl;
    }
    // force scope for variable rect2
    {
        gfx::rect::GfxRect rect2 = rect1;
        rmeta.printToStream(std::cout) << std::endl;
    }
    gfx::pixels::GfxArrayOrder ao1;
    gfx::pixels::GfxArrayOrder ao2;
    gfx::pixels::GfxArrayOrder ao3;

    ao3.~GfxArrayOrder();
    rmeta.printToStream(std::cout) << std::endl;
}

void Playground::_doMeta(void)
{
    gfx::_gfx::GfxMeta meta;
    gfx::_gfx::GfxMeta::ClassInfo classInfo;

	for (int32_t index = 0; index < meta.getClassCount(); index++)
	{
	    classInfo = meta.getClassInfo(index);
	    std::cout << "Name=" << classInfo.className_ << "\t\t";
	    std::cout << "Size[bytes]=" << classInfo.size_ << '\t';
	    std::cout << "hasSdlType=" << classInfo.hasSdlType_ << '\t';
	    std::cout << "hasSdlTypePtr=" << classInfo.hasSdlTypePtr_ << '\t';
        std::cout << "isAbstract<>=" << classInfo.isAbstract_ << '\t';
        std::cout << "isPolym<>=" << classInfo.isPolymorphic_ << '\t';
        std::cout << "isMoveCtor<>=" << classInfo.isMoveConstructible_ << '\t';
        std::cout << "isMoveAssign<>=" << classInfo.isMoveAssignable_ << '\t';
        std::cout << "isGfxObjChild<>=" << classInfo.isDerivedFromGfxObject_ << '\t';
        std::cout << "sdlResource=" << classInfo.sdlResource_ << '\t';
        std::cout << "hasValueType<>=" << classInfo.hasValueType_ << '\n';
	}
    std::cout << std::endl;
}

/******************************************************* log *******************************************************/
#include "GfxLog.hpp"
#include "GfxLogCategory.hpp"
#include "GfxLogPriority.hpp"
#include "GfxLogOutputFunction.hpp"

namespace prv
{
    class LogOutFunc : public gfx::log::GfxLogOutputFunction
    {
    public:
        LogOutFunc() : GfxLogOutputFunction()
        {
            // nothing to do
        }
        virtual void operator()(void* userdata,gfx::log::GfxLogCategory const& cat,
                        gfx::log::GfxLogPriority const& prio, std::string const& message) const noexcept
        {
            assert(userdata != nullptr);
            assert(cat);
            assert(prio);

            std::cout << "<" << message << ">" << std::endl;
        }
    };
}

void Playground::_doLog(void)
{
    gfx::log::GfxLog log;
    prv::LogOutFunc lofunc;
    char ch = 'c';
    char * usrdata = &ch;

    using gfx::log::GfxLogCategory;
    using gfx::log::GfxLogPriority;

    // test Get
    prv::LogOutFunc * tst_lofuncptr = nullptr;
    void * tst_userdata = nullptr;
    tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction(&tst_userdata));
    if (tst_lofuncptr == nullptr)
    {
        std::cout << "nullptr; as expected" << std::endl;
    }

    log.setPriority(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityVerbose));
    log.log("char=%c", 'a');
    log.log("value=%d", 128);
    log.log("float1=%f float2=%f", 1.5, 2.6);
    log.log("str=%s char=%c int=%d", "string", ';', 5);
    // Set new output function
    log.logSetOutputFunction(&lofunc, static_cast<void *>(usrdata));
    // test new output function
    tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction(&tst_userdata));
    if (tst_lofuncptr == nullptr)
    {
        std::cout << "nullptr; NOT expected!" << std::endl;
    }
    else
    {
        std::cout << "I'm ok!" << std::endl;
        if (tst_lofuncptr == &lofunc)
        {
            std::cout << "equal" << std::endl;
        }
        else
        {
            std::cout << "NOT Equal!" << std::endl;
        }
    }
    log.logVerbose(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "verbose=0x%x", 127);
    log.logDebug(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "debug=0x%x", 127);
    log.logInfo(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "info=0x%x", 127);
    log.logWarn(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "warn=0x%x", 127);
    log.logError(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "error=0x%x", 127);
    log.logCritical(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "critical=0x%x", 127);
    // Try to stop own logging function
    try
    {
        log.logSetOutputFunction(nullptr, static_cast<void *>(usrdata));
    }
    catch (std::runtime_error ex)
    {
        std::cout << "Exception: " << ex.what() << "; as expected" << std::endl;
    }
    log.logMessage(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityCritical),
                    "logMessage=%s",":-)");
}

/******************************************************* main *******************************************************/
void Playground::_doPlayground(void)
{
    //_doBenchmark();
    //_doFonts();
    //_doPaletteSdl();
    //_doPaletteGfx();
    //_doCallback();
    //_doComponent();
    //_doFSO();
    //_doRuntimeMeta();
    _doMeta();
    //_doLog();
}

int main(int argc, char *argv[])
{
    Playground p;

    assert(argc == 1);
    assert(argv != nullptr);
    p._doPlayground();
    return 0;
}

/* EOF */

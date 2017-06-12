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

#ifndef Playground_hpp
#define Playground_hpp

#include <cstdint>
#include <string>
#include <vector>

class Playground
{
public:
    void _doPlayground(void);
protected:
    void _doBenchmark(void);
    void _doFonts(void);
    void _doPaletteSdl(void);
    void _doPaletteGfx(void);
    void _doCallback(void);
    void _doComponent(void);
    void _doFSO(void);
    void _doRuntimeMeta(void);
    void _doMeta(void);
    void _doLog(void);
private:
    void DoAlgo(int algo_index);

    double Algo0(std::uint32_t * ptr);
    double Algo1(std::uint32_t * ptr);
    double Algo2(std::uint32_t * ptr);
    double Algo3(std::uint32_t * ptr);

    std::vector<std::string> FindAllFiles(std::string const& bpath);
    std::string ToHexStr(uint8_t c);
    void ProcessBuffer(std::string const& buffname, uint8_t * buff);
    std::string GetFntName(std::string const& fullname);
    void ProcessFNTfile(std::string const& fullname);

    void printSdlPalette(void * palptr, bool const printclrs);
    void printSdlPixFormat(void * pixptr);
    template <typename T> std::string IntToHexStr(T value);
};

#endif /* Playground_hpp */

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

#include "Fonts.hpp"

/******************************************************* Fonts *******************************************************/
#include <dirent.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <cstdint>
#include <iterator>
#include <cstring>

static std::vector<std::string> FindAllFiles(std::string const& bpath)
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

static std::string ToHexStr(uint8_t c)
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

static void ProcessBuffer(std::string const& buffname, uint8_t * buff)
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

static std::string GetFntName(std::string const& fullname)
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

static void ProcessFNTfile(std::string const& fullname)
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

void _doFonts(void)
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

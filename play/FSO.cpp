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

#include "FSO.hpp"

/******************************************************* FSO *******************************************************/
#include <iostream>

#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"
#include "GFileObject.hpp"

using gto::fso::GFileSystemObject;
using gto::fso::GFolderObject;
using gto::fso::GFileObject;

void _doFSO(void)
{
    GFileSystemObject fso;
    GFolderObject * fo = fso.getFolder(fso._getWorkingDirectory());

    std::cout << "pwd=" << fso._getWorkingDirectory() << std::endl;
    if (fo != nullptr)
    {
        gto::fso::GFilesCollection fcoll;
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
        gto::fso::GFileObject fileo(lastfile);

        std::cout << fileo.getFileName() << std::endl;
        std::cout << fileo.getFilePath() << std::endl;
        std::cout << fileo.getFileSpec() << std::endl;
        std::cout << fileo.getAttributesAsString() << std::endl;
        std::cout << fileo.getDateTimeCreated() << std::endl;
        delete fo;
    }
}

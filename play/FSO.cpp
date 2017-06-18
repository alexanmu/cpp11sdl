#include "FSO.hpp"

/******************************************************* FSO *******************************************************/
#include <iostream>

#include "GFileSystemObject.hpp"
#include "GFolderObject.hpp"
#include "GFileObject.hpp"

using gto::util::GFileSystemObject;
using gto::util::GFolderObject;
using gto::util::GFileObject;

void _doFSO(void)
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

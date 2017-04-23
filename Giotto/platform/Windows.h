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

#ifndef Windows_h
#define Windows_h

// Defines taken from https://sourceforge.net/p/predef/wiki/Compilers/

#undef __NOK
#undef __OK

#if (defined(__MINGW32__) || defined(__MINGW64__))
#error __MINGW[32/64]__ not supported yet!
#define __NOK
#endif // __MINGW32__

#ifdef __BORLANDC__
#define __BORLANDC__ not supported yet!
#define __NOK
#endif // __BORLANDC__

#ifdef _MSC_VER
#error _MSC_VER not supported yet!
#define __NOK
#endif // _MSC_VER


/* Windows specific stuff */
#if defined(__OK) && !defined(__NOK)

#define __windows_machine
#define __base_path "c:\users\goros\Pictures"
#define WIN_W 960
#define WIN_H 480

#endif // defined(__OK) && !defined(__NOK)

#endif /* Windows_h */

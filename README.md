# Giotto
C++11 Graphics Library based on SDL2 (https://www.libsdl.org/) version 2.0.8!

Basic design approach is "everything is an object".

Namespace gfx (located in src/gfx) contains wrappers for many SDL types/functions. There is a 1-to-1 mapping between SDL headers and a corresponding namespace within gfx (e.g. SDL_video.h wrappers are available in namespace gfx::video - src/gfx/video).

Components:
  - 'gfx' namespace: wrapper objects for SDL
  - 'gto' namespace: GUI

Supported platforms:
  - RedHat Enterprise Linux Server Release 6.7
  - macOS X 10.11 El Capitan
  - macOS 10.12 Sierra
  - macOS 10.13 High Sierra

Supported compilers:
  - GNU gcc 6.1.0a-2
  - clang-802.0.41
  - clang-802.0.42
  - clang-902.0.39.2

Supported IDEs:
  - Apple Xcode 8.3.2
  - Apple Xcode 8.3.3
  - Apple Xcode 9.4.1

Licensed under the zlib licence (http://zlib.net/zlib_license.html).

External code attributions:
- GfxCanvasBgi class based on code from here: http://libxbgi.sourceforge.net/ (SDL_bgi).
- Google Test/Google Mock (https://github.com/google/googletest)
- prettyprint.hpp (https://github.com/louisdx/cxx-prettyprint/blob/master/prettyprint.hpp) Copyright Louis Delacroix; licensed under BOOST (http://www.boost.org/LICENSE_1_0.txt); 
- Added some bitmap fonts I found many years ago on the internet. See ./Giotto/bgi/fntNAME.hpp files. All are based on binary files with the filename NAME.fnt and where converted to C++ header files by code in Playground.cpp. If you think there is a copyright issue at play please message me asap; I do not remember the original authors/copyright.
- SFINAE code in GfxMeta based on https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error

Small demo app available. See main.cpp

Special note for macOS users with Xcode: following configuration must be set in Xcode for the built-in build system to be compatible with the makefile:
*File -> Project Settings... -> Derived Data "Project-relative Location"; and path set to "../build/DerivedData"*

---eof---

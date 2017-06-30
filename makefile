# Giotto
# Copyright (C) 2017 George Oros
# 
# This software is provided 'as-is', without any express or implied
# warranty.  In no event will the authors be held liable for any damages
# arising from the use of this software.
# 
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
# 
# 1. The origin of this software must not be misrepresented; you must not
# claim that you wrote the original software. If you use this software
# in a product, an acknowledgment in the product documentation would be
# appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
# misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.
# 
# See copyright notice at http://lidsdl.org/license.php

# Detect OS
ifeq ($(OS), Windows_NT)
 HOSTOS:=WinNT
else
 UNAME_S:=$(shell uname -s)
 ifeq ($(UNAME_S),Darwin)
  HOSTOS:=macOS
 else
  ifeq ($(UNAME_S),Linux)
   HOSTOS:=Linux
  else
   $(error OS not supported)
  endif
 endif
endif

ifeq ($(HOSTOS), WinNT)
 $(error Windows not supported yet!)
endif

# Commands
MKDIR:=mkdir
RM:=rm -f

# Folders
BINDIR:=bin
BUILDDIR:=build
LINTBUILDDIR=$(BUILDDIR)/lint
INCLUDEDIR:=include
LIBDIR:=lib
PLAYDIR:=play
SRCDIR:=src
TESTDIR:=test
TOOLSDIR:=tools

# Names
EXE:=tool
SRCEXT:=cpp
HDREXT:=hpp
OBJEXT=o
TARGET:=$(BINDIR)/$(EXE)
CPPLINT:=cpplint.sh
LINTEXT=lnt
DEPSEXT=d

# Debug
DEBUG:=-g -ggdb -gdwarf-3

# Compiler/linker
ifeq ($(HOSTOS),macOS)
 CXX:=clang++
else
 CXX:=g++
endif
CXXFLAGS_LINUX:=-std=c++11 -Wall -Wextra -Werror -Wno-terminate $(DEBUG)
CXXFLAGS_MACOS:=-std=c++11 -Wall -Wextra -Werror $(DEBUG)
CXXLINK_LINUX:=-static-libstdc++ -lpthread -lrt -lm -ldl -lz $(DEBUG)
CXXLINK_MACOS_HELPER=$(shell echo ~)
CXXLINK_MACOS:=-lpthread -lm -ldl -lz -F$(CXXLINK_MACOS_HELPER)/Library/Frameworks -framework SDL2 -framework SDL2_ttf $(DEBUG)

ifeq ($(HOSTOS),macOS)
 CXXFLAGS:=$(CXXFLAGS_MACOS)
 CXXLINK:=$(CXXLINK_MACOS)
else
 CXXFLAGS:=$(CXXFLAGS_LINUX)
 CXXLINK:=$(CXXLINK_LINUX)
endif

# External libraries
LIBS_LINUX:=$(LIBDIR)/linux/libSDL2.a $(LIBDIR)/linux/libSDL2_ttf.a $(LIBDIR)/linux/libfreetype.a
LIBS_MACOS:=

ifeq ($(HOSTOS),macOS)
 LIBS:=$(LIBS_MACOS)
else
 LIBS:=$(LIBS_LINUX)
endif

# Folders
FOLDERS:=$(shell find $(SRCDIR) -type d)

# VPATH
VPATH=$(subst ' ',:,$(FOLDERS))

# Sources
SOURCES:=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
HEADERS:=$(shell find $(SRCDIR) -type f -name *.$(HDREXT))

# Objects
OBJECTSWITHSRCPATH:=$(patsubst $(SRCDIR)/%,%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS:=$(foreach owp,$(OBJECTSWITHSRCPATH),$(BUILDDIR)/$(notdir $(owp)))

# Includes
INC:=-I$(INCLUDEDIR) -I$(INCLUDEDIR)/sdl2 -I$(INCLUDEDIR)/sdl2_ttf $(patsubst %,-I%,$(FOLDERS))

# Dependencies
DEPS=$(OBJECTS:%.$(OBJEXT)=%.$(DEPSEXT))

######################################## 1st rule ########################################
empty:
	@echo "Please specify a command!"

######################################## Folders ########################################
make-folders:
	@-$(MKDIR) -p $(BINDIR)
	@-$(MKDIR) -p $(BUILDDIR)
	@-$(MKDIR) -p $(LINTBUILDDIR)

######################################## Tool ########################################
-include $(DEPS)

$(TARGET) : $(OBJECTS) $(LIBS)
	$(CXX) $(CXXLINK) -o $(TARGET) $^

$(BUILDDIR)/%.$(OBJEXT) : %.$(SRCEXT)
	$(CXX) $(CXXFLAGS) $(INC) -MMD -c -o $@ $<

tool: make-folders $(TARGET)

clean:
	-$(RM) $(BUILDDIR)/*.$(OBJEXT)
	-$(RM) $(BUILDDIR)/*.$(DEPSEXT)
	-$(RM) $(TARGET)

######################################## Test ########################################
-include $(BUILDDIR)/test.$(DEPSEXT)

OBJECTS_FOR_TEST:=$(filter-out %main.o,$(OBJECTS))
ifeq ($(HOSTOS),macOS)
 LIBS_FOR_TEST:=$(LIBDIR)/macos/gtest_main.a $(LIBDIR)/macos/gmock_main.a
else
 LIBS_FOR_TEST:=$(LIBDIR)/linux/gtest_main.a $(LIBDIR)/linux/gmock_main.a
endif
INC_FOR_TEST:=-I$(INCLUDEDIR)/googletest -I$(INCLUDEDIR)/googlemock

$(BUILDDIR)/test.$(OBJEXT) : $(TESTDIR)/test.$(SRCEXT)
	$(CXX) $(CXXFLAGS) $(INC) $(INC_FOR_TEST) -MMD -c -o $@ $<

$(BINDIR)/test: $(OBJECTS_FOR_TEST) $(BUILDDIR)/test.$(OBJEXT) $(LIBS) $(LIBS_FOR_TEST)
	$(CXX) $(CXXLINK) -o $@ $^

test: make-folders $(BINDIR)/test

clean-test:
	-$(RM) $(BINDIR)/test
	-$(RM) $(BUILDDIR)/test.$(OBJEXT)
	-$(RM) $(BUILDDIR)/test.$(DEPSEXT)

######################################## Play ########################################
OBJECTS_FOR_PLAY:=$(filter-out %main.o,$(OBJECTS))
DEPS_FOR_PLAY:=$(shell find $(PLAYDIR) -type f -name *.$(SRCEXT))
DEPS_FOR_PLAY+=$(shell find $(PLAYDIR) -type f -name *.$(HDREXT))

CPPS_FOR_PLAY:=$(shell find $(PLAYDIR) -type f -name *.$(SRCEXT))

$(BINDIR)/play: $(DEPS_FOR_PLAY) $(OBJECTS_FOR_PLAY) 
	$(CXX) $(CXXFLAGS) $(CXXLINK) -o $(BINDIR)/play $(CPPS_FOR_PLAY) $(INC) $(OBJECTS_FOR_PLAY) $(LIBS)

play : make-folders $(BINDIR)/play

clean-play:
	-$(RM) $(BINDIR)/play

######################################## Lint ########################################
LINTCPPWITHSRCPATH:=$(patsubst $(SRCDIR)/%,%,$(SOURCES:.$(SRCEXT)=.$(SRCEXT).$(LINTEXT)))
LINTCPP:=$(foreach lwp,$(LINTCPPWITHSRCPATH),$(LINTBUILDDIR)/$(notdir $(lwp)))
LINTHPPWITHSRCPATH:=$(patsubst $(SRCDIR)/%,%,$(HEADERS:.$(HDREXT)=.$(HDREXT).$(LINTEXT)))
LINTHPP:=$(foreach lwp,$(LINTHPPWITHSRCPATH),$(LINTBUILDDIR)/$(notdir $(lwp)))

$(LINTBUILDDIR)/%.$(SRCEXT).$(LINTEXT) : %.$(SRCEXT)
	$(TOOLSDIR)/$(CPPLINT) $< 2>$@

$(LINTBUILDDIR)/%.$(HDREXT).$(LINTEXT) : %.$(HDREXT)
	$(TOOLSDIR)/$(CPPLINT) $< 2>$@

lint: make-folders $(LINTCPP) $(LINTHPP)

clean-lint:
	-$(RM) $(LINTBUILDDIR)/*.$(SRCEXT).$(LINTEXT)
	-$(RM) $(LINTBUILDDIR)/*.$(HDREXT).$(LINTEXT)

######################################## Valgrind ########################################
VALGRIND_BIN=valgrind
VALGRIND_PARAMS:=--leak-check=full --show-leak-kinds=all --demangle=yes
VALGRIND_TOOL_CMD_LINE:=giotto
VALGRIND_TARGET:=$(TARGET)

ifeq ($(HOSTOS),macOS)
valgrind:
	@echo "valgrind not supported on Darwin/macOS"
else
 ifeq ($(HOSTOS),WinNT)
 valgrind:
	@echo "valgrind not supported on Windows"
 else
 valgrind: make-folders $(TARGET)
	$(VALGRIND_BIN) $(VALGRIND_PARAMS) --suppressions=$(TOOLSDIR)/suppress_sdl.supp $(VALGRIND_TARGET) $(VALGRIND_TOOL_CMD_LINE)
 endif
endif

######################################## All ########################################
all : clean clean-test clean-lint lint tool test

clean-all: clean clean-play clean-test clean-lint
	-$(RM) -rf $(BUILDDIR)/DerivedData

.PHONY:
	empty clean test clean-test play clean-play lint clean-lint valgrind all clean-all

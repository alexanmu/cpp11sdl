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

######################################## Globals ########################################
# Commands
MKDIR:=mkdir
RM:=rm

# Folders
g_BINDIR:=bin
g_BUILDDIR:=build
g_INCLUDEDIR:=include
g_LIBDIR:=lib
g_PLAYDIR:=play
g_SRCDIR:=src
g_TESTDIR:=test
g_TOOLSDIR:=tools

# Names
g_SRCEXT:=cpp
g_HDREXT:=hpp
g_OBJEXT=o
g_LINTEXT=lnt
g_DEPSEXT=d

######################################## Compiler/Linker ########################################

# Debug
DEBUG:=-DDEBUG -O0 -g -ggdb -gdwarf-3
RELEASE:=-O3

CXXFLAGS_LINUX:=-std=c++11 -Wall -Wextra -Werror -Wno-error=cpp -fPIC $(DEBUG)
CXXFLAGS_MACOS:=-std=c++11 -Wall -Wextra -Werror -Wno-error=\#warnings -fPIC $(DEBUG)

CXXLINK_LINUX:=-static-libstdc++ -lpthread -lrt -lm -ldl -lz $(DEBUG)
CXXLINK_MACOS_HELPER=$(shell echo ~)
CXXLINK_MACOS:=-lpthread -lm -ldl -lz -F$(CXXLINK_MACOS_HELPER)/Library/Frameworks -framework SDL2 -framework SDL2_ttf $(DEBUG)

LIBS_LINUX:=$(g_LIBDIR)/linux/libSDL2.a $(g_LIBDIR)/linux/libSDL2_ttf.a $(g_LIBDIR)/linux/libfreetype.a
LIBS_MACOS:=

INCFOLDERS_LINUX:=-I$(g_INCLUDEDIR) -I$(g_INCLUDEDIR)/sdl2 -I$(g_INCLUDEDIR)/sdl2_ttf
INCFOLDERS_MACOS:=-I$(g_INCLUDEDIR) -I$(g_INCLUDEDIR)/sdl2 -I$(g_INCLUDEDIR)/sdl2_ttf

ARFLAGS_LINUX:=rcs
ARFLAGS_MACOS:=rcs

ifeq ($(HOSTOS),macOS)
CXX:=clang++
CXXFLAGS:=$(CXXFLAGS_MACOS)
CXXLINK:=$(CXXLINK_MACOS)
CXXLIBS:=$(LIBS_MACOS)
AR:=ar
ARFLAGS:=$(ARFLAGS_MACOS)
INCFOLDERS:=$(INCFOLDERS_MACOS)
else
CXX:=g++
CXXFLAGS:=$(CXXFLAGS_LINUX)
CXXLINK:=$(CXXLINK_LINUX)
CXXLIBS:=$(LIBS_LINUX)
AR:=ar
ARFLAGS:=$(ARFLAGS_LINUX)
INCFOLDERS:=$(INCFOLDERS_LINUX)
endif

CPPLINT:=$(g_TOOLSDIR)/cpplint.sh

######################################## Folders ########################################
firstRule:
		@-$(MKDIR) -p $(g_BINDIR)
		@-$(MKDIR) -p $(g_BUILDDIR)
		@-$(MKDIR) -p $(BUILDDIR_GFX)
		@-$(MKDIR) -p $(BUILDDIR_GTO)
		@-$(MKDIR) -p $(BUILDDIR_TOOL)
		@-$(MKDIR) -p $(BUILDDIR_PLAY)
		@-$(MKDIR) -p $(BUILDDIR_TEST)

######################################## GFX ########################################
SRCDIR_GFX:=$(g_SRCDIR)/gfx
BUILDDIR_GFX:=$(g_BUILDDIR)/gfx
EXE_STATIC_GFX:=$(BUILDDIR_GFX)/libGFX.a

SOURCES_GFX:=$(shell find $(SRCDIR_GFX) -type f -name *.$(g_SRCEXT))
HEADERS_GFX:=$(shell find $(SRCDIR_GFX) -type f -name *.$(g_HDREXT))
OBJECTSWITHSRCPATH_GFX:=$(patsubst $(SRCDIR_GFX)/%,%,$(SOURCES_GFX:.$(g_SRCEXT)=.$(g_OBJEXT)))
OBJECTS_GFX:=$(foreach owp,$(OBJECTSWITHSRCPATH_GFX),$(BUILDDIR_GFX)/$(notdir $(owp)))
DEPS_GFX:=$(foreach owp,$(OBJECTS_GFX),$(basename $(owp)).$(g_DEPSEXT))
FOLDERS_GFX:=$(shell find $(SRCDIR_GFX) -type d)
INC_GFX:=$(patsubst %,-I%,$(FOLDERS_GFX))
LINTS_CPP_GFX:=$(foreach owp,$(OBJECTS_GFX),$(basename $(owp)).$(g_SRCEXT).$(g_LINTEXT))
LINTS_HPP_GFX:=$(foreach owp,$(OBJECTS_GFX),$(basename $(owp)).$(g_HDREXT).$(g_LINTEXT))

VPATH:=$(FOLDERS_GFX)

-include $(DEPS_GFX)

$(BUILDDIR_GFX)/%.$(g_OBJEXT) : %.$(g_SRCEXT)
		$(CXX) $(CXXFLAGS) $(INCFOLDERS) $(INC_GFX) -MMD -c -o $@ $<

$(BUILDDIR_GFX)/%.$(g_SRCEXT).$(g_LINTEXT) : %.$(g_SRCEXT)
		$(CPPLINT) $< 2>$@

$(BUILDDIR_GFX)/%.$(g_HDREXT).$(g_LINTEXT) : %.$(g_HDREXT)
		$(CPPLINT) $< 2>$@

$(EXE_STATIC_GFX) : $(OBJECTS_GFX)
		$(AR) $(ARFLAGS) $(EXE_STATIC_GFX) $^

linkStaticGfx: $(EXE_STATIC_GFX)

lintGfx: $(LINTS_CPP_GFX) $(LINTS_HPP_GFX)

objectsGfx: $(OBJECTS_GFX)

cleanGfx:
		-$(RM) -f $(OBJECTS_GFX)
		-$(RM) -f $(DEPS_GFX)
		-$(RM) -f $(EXE_STATIC_GFX)

cleanLintGfx:
		-$(RM) -f $(LINTS_CPP_GFX)
		-$(RM) -f $(LINTS_HPP_GFX)

gfx: firstRule $(EXE_STATIC_GFX)

######################################## GTO ########################################
SRCDIR_GTO:=$(g_SRCDIR)/gto
BUILDDIR_GTO:=$(g_BUILDDIR)/gto
EXE_STATIC_GTO:=$(BUILDDIR_GTO)/libGTO.a

SOURCES_GTO:=$(shell find $(SRCDIR_GTO) -type f -name *.$(g_SRCEXT))
HEADERS_GTO:=$(shell find $(SRCDIR_GTO) -type f -name *.$(g_HDREXT))
OBJECTSWITHSRCPATH_GTO:=$(patsubst $(SRCDIR_GTO)/%,%,$(SOURCES_GTO:.$(g_SRCEXT)=.$(g_OBJEXT)))
OBJECTS_GTO:=$(foreach owp,$(OBJECTSWITHSRCPATH_GTO),$(BUILDDIR_GTO)/$(notdir $(owp)))
DEPS_GTO:=$(foreach owp,$(OBJECTS_GTO),$(basename $(owp)).$(g_DEPSEXT))
FOLDERS_GTO:=$(shell find $(SRCDIR_GTO) -type d)
INC_GTO:=$(patsubst %,-I%,$(FOLDERS_GTO))
LINTS_CPP_GTO:=$(foreach owp,$(OBJECTS_GTO),$(basename $(owp)).$(g_SRCEXT).$(g_LINTEXT))
LINTS_HPP_GTO:=$(foreach owp,$(OBJECTS_GTO),$(basename $(owp)).$(g_HDREXT).$(g_LINTEXT))

VPATH+=$(FOLDERS_GTO)

INC_GTO+=$(INC_GFX)

-include $(DEPS_GTO)

$(BUILDDIR_GTO)/%.$(g_OBJEXT) : %.$(g_SRCEXT)
		$(CXX) $(CXXFLAGS) $(INCFOLDERS) $(INC_GTO) -MMD -c -o $@ $<

$(BUILDDIR_GTO)/%.$(g_SRCEXT).$(g_LINTEXT) : %.$(g_SRCEXT)
		$(CPPLINT) $< 2>$@

$(BUILDDIR_GTO)/%.$(g_HDREXT).$(g_LINTEXT) : %.$(g_HDREXT)
		$(CPPLINT) $< 2>$@

$(EXE_STATIC_GTO) : $(OBJECTS_GTO)
		$(AR) $(ARFLAGS) $(EXE_STATIC_GTO) $^

linkStaticGto: $(EXE_STATIC_GTO)

lintGto: $(LINTS_CPP_GTO) $(LINTS_HPP_GTO)

objectsGto: $(OBJECTS_GTO)

cleanGto:
		-$(RM) -f $(OBJECTS_GTO)
		-$(RM) -f $(DEPS_GTO)
		-$(RM) -f $(EXE_STATIC_GTO)

cleanLintGto:
		-$(RM) -f $(LINTS_CPP_GTO)
		-$(RM) -f $(LINTS_HPP_GTO)

gto: firstRule $(EXE_STATIC_GTO)

######################################## TOOL ########################################
SRCDIR_TOOL:=$(g_SRCDIR)
BUILDDIR_TOOL:=$(g_BUILDDIR)/tool
EXE_STATIC_TOOL:=$(g_BINDIR)/tool

SOURCES_TOOL:=$(g_SRCDIR)/main.cpp $(g_SRCDIR)/GDemoForm.cpp
HEADERS_TOOL:=$(g_SRCDIR)/GDemoForm.hpp
OBJECTSWITHSRCPATH_TOOL:=$(patsubst $(g_SRCDIR)/%,%,$(SOURCES_TOOL:.$(g_SRCEXT)=.$(g_OBJEXT)))
OBJECTS_TOOL:=$(foreach owp,$(OBJECTSWITHSRCPATH_TOOL),$(BUILDDIR_TOOL)/$(notdir $(owp)))
DEPS_TOOL:=$(foreach owp,$(OBJECTS_TOOL),$(basename $(owp)).$(g_DEPSEXT))
FOLDERS_TOOL:=$(SRCDIR_TOOL)
INC_TOOL:=-I$(SRCDIR_TOOL)
LINTS_CPP_TOOL:=$(BUILDDIR_TOOL)/main.cpp.lnt $(BUILDDIR_TOOL)/GDemoForm.cpp.lnt
LINTS_HPP_TOOL:=$(BUILDDIR_TOOL)/GDemoForm.hpp.lnt

VPATH+=$(FOLDERS_TOOL)

INC_TOOL+=$(INC_GFX)
INC_TOOL+=$(INC_GTO)
 
-include $(DEPS_GFX)
-include $(DEPS_GTO)
-include $(DEPS_TOOL)

$(BUILDDIR_TOOL)/%.$(g_OBJEXT) : %.$(g_SRCEXT)
		$(CXX) $(CXXFLAGS) $(INCFOLDERS) $(INC_TOOL) -MMD -c -o $@ $<

$(BUILDDIR_TOOL)/%.$(g_SRCEXT).$(g_LINTEXT) : %.$(g_SRCEXT)
		$(CPPLINT) $< 2>$@

$(BUILDDIR_TOOL)/%.$(g_HDREXT).$(g_LINTEXT) : %.$(g_HDREXT)
		$(CPPLINT) $< 2>$@

$(EXE_STATIC_TOOL) : $(OBJECTS_TOOL) $(EXE_STATIC_GTO) $(EXE_STATIC_GFX)
		$(CXX) $(CXXLINK) -o $(EXE_STATIC_TOOL) $^ $(CXXLIBS)
 
linkStaticTool: $(EXE_STATIC_TOOL)

lintTool: $(LINTS_CPP_TOOL) $(LINTS_HPP_TOOL)

objectsTool: $(OBJECTS_TOOL)

cleanTool:
		-$(RM) -f $(OBJECTS_TOOL)
		-$(RM) -f $(DEPS_TOOL)
		-$(RM) -f $(EXE_STATIC_TOOL)

cleanLintTool:
		-$(RM) -f $(LINTS_CPP_TOOL)
		-$(RM) -f $(LINTS_HPP_TOOL)

tool: firstRule $(EXE_STATIC_TOOL)

######################################## PLAY ########################################
SRCDIR_PLAY:=$(g_PLAYDIR)
BUILDDIR_PLAY:=$(g_BUILDDIR)/play
EXE_STATIC_PLAY:=$(g_BINDIR)/play

SOURCES_PLAY:=$(shell find $(SRCDIR_PLAY) -type f -name *.$(g_SRCEXT))
HEADERS_PLAY:=$(shell find $(SRCDIR_PLAY) -type f -name *.$(g_HDREXT))
OBJECTSWITHSRCPATH_PLAY:=$(patsubst $(SRCDIR_PLAY)/%,%,$(SOURCES_PLAY:.$(g_SRCEXT)=.$(g_OBJEXT)))
OBJECTS_PLAY:=$(foreach owp,$(OBJECTSWITHSRCPATH_PLAY),$(BUILDDIR_PLAY)/$(notdir $(owp)))
DEPS_PLAY:=$(foreach owp,$(OBJECTS_PLAY),$(basename $(owp)).$(g_DEPSEXT))
FOLDERS_PLAY:=$(SRCDIR_PLAY)
INC_PLAY:=-I$(SRCDIR_PLAY)
LINTS_CPP_PLAY:=$(foreach owp,$(OBJECTS_PLAY),$(basename $(owp)).$(g_SRCEXT).$(g_LINTEXT))
LINTS_HPP_PLAY:=$(foreach owp,$(OBJECTS_PLAY),$(basename $(owp)).$(g_HDREXT).$(g_LINTEXT))

VPATH+=$(FOLDERS_PLAY)

INC_PLAY+=$(INC_GFX)
INC_PLAY+=$(INC_GTO)

-include $(DEPS_PLAY)

$(BUILDDIR_PLAY)/%.$(g_OBJEXT) : %.$(g_SRCEXT)
		$(CXX) $(CXXFLAGS) $(INCFOLDERS) $(INC_PLAY) -MMD -c -o $@ $<

$(BUILDDIR_PLAY)/%.$(g_SRCEXT).$(g_LINTEXT) : %.$(g_SRCEXT)
		$(CPPLINT) $< 2>$@

$(BUILDDIR_PLAY)/%.$(g_HDREXT).$(g_LINTEXT) : %.$(g_HDREXT)
		$(CPPLINT) $< 2>$@

$(EXE_STATIC_PLAY) : $(OBJECTS_PLAY) $(EXE_STATIC_GTO) $(EXE_STATIC_GFX)
		$(CXX) $(CXXLINK) -o $(EXE_STATIC_PLAY) $^ $(CXXLIBS)

linkStaticPlay: $(EXE_STATIC_PLAY)

lintPlay: $(LINTS_CPP_PLAY) $(LINTS_HPP_PLAY)

objectsPlay: $(OBJECTS_PLAY)

cleanPlay:
		-$(RM) -f $(OBJECTS_PLAY)
		-$(RM) -f $(DEPS_PLAY)
		-$(RM) -f $(EXE_STATIC_PLAY)

cleanLintPlay:
		-$(RM) -f $(LINTS_CPP_PLAY)
		-$(RM) -f $(LINTS_HPP_PLAY)

play: firstRule $(EXE_STATIC_PLAY)

######################################## PLAY ########################################
SRCDIR_TEST:=$(g_TESTDIR)
BUILDDIR_TEST:=$(g_BUILDDIR)/test
EXE_STATIC_TEST:=$(g_BINDIR)/test

SOURCES_TEST:=$(shell find $(SRCDIR_TEST) -type f -name *.$(g_SRCEXT))
HEADERS_TEST:=$(shell find $(SRCDIR_TEST) -type f -name *.$(g_HDREXT))
OBJECTSWITHSRCPATH_TEST:=$(patsubst $(SRCDIR_TEST)/%,%,$(SOURCES_TEST:.$(g_SRCEXT)=.$(g_OBJEXT)))
OBJECTS_TEST:=$(foreach owp,$(OBJECTSWITHSRCPATH_TEST),$(BUILDDIR_TEST)/$(notdir $(owp)))
DEPS_TEST:=$(foreach owp,$(OBJECTS_TEST),$(basename $(owp)).$(g_DEPSEXT))
FOLDERS_TEST:=$(SRCDIR_TEST)
INC_TEST:=-I$(SRCDIR_TEST) -I$(g_INCLUDEDIR)/googletest -I$(g_INCLUDEDIR)/googlemock

ifeq ($(HOSTOS),macOS)
LIBS_TEST:=$(g_LIBDIR)/macos/gtest_main.a $(g_LIBDIR)/macos/gmock_main.a
else
LIBS_TEST:=$(g_LIBDIR)/linux/gtest_main.a $(g_LIBDIR)/linux/gmock_main.a
endif

VPATH+=$(FOLDERS_TEST)

INC_TEST+=$(INC_GFX)
INC_TEST+=$(INC_GTO)

-include $(DEPS_TEST)

$(BUILDDIR_TEST)/%.$(g_OBJEXT) : %.$(g_SRCEXT)
		$(CXX) $(CXXFLAGS) $(INCFOLDERS) $(INC_TEST) -MMD -c -o $@ $<

$(EXE_STATIC_TEST) : $(OBJECTS_TEST) $(EXE_STATIC_GTO) $(EXE_STATIC_GFX)
		$(CXX) $(CXXLINK) -o $(EXE_STATIC_TEST) $^ $(CXXLIBS) $(LIBS_TEST)

linkStaticTest: $(EXE_STATIC_TEST)

objectsTest: $(OBJECTS_TEST)

cleanTest:
		-$(RM) -f $(OBJECTS_TEST)
		-$(RM) -f $(DEPS_TEST)
		-$(RM) -f $(EXE_STATIC_TEST)
 
test: firstRule $(EXE_STATIC_TEST)

######################################## Valgrind ########################################
VALGRIND_BIN=valgrind
VALGRIND_PARAMS:=--leak-check=full --show-leak-kinds=all --demangle=yes
VALGRIND_TARGET:=bin/play
VALGRIND_TARGET_CMD_LINE:=bgidemo

ifeq ($(HOSTOS),macOS)
valgrind:
		@echo "valgrind not supported on Darwin/macOS"
else
ifeq ($(HOSTOS),WinNT)
valgrind:
		@echo "valgrind not supported on Windows"
else
valgrind: firstRule $(VALGRIND_TARGET)
		$(VALGRIND_BIN) $(VALGRIND_PARAMS) --suppressions=$(g_TOOLSDIR)/suppress_sdl.supp $(VALGRIND_TARGET) $(VALGRIND_TARGET_CMD_LINE)
endif
endif

######################################## All ########################################
all: firstRule tool play test

lint: firstRule lintGfx lintGto lintTool lintPlay

clean: firstRule cleanGfx cleanGto cleanTool cleanPlay cleanTest

clean-lint: firstRule cleanLintGfx cleanLintGto cleanLintTool cleanLintPlay

clean-all: firstRule clean clean-lint

.PHONY:
		linkStaticGfx lintGfx objectsGfx cleanGfx cleanLintGfx gfx
		linkStaticGto lintGto objectsGto cleanGto cleanLintGto gto
		linkStaticTool lintTool objectsTool cleanTool cleanLintTool tool
		linkStaticPlay lintPlay objectsPlay cleanPlay cleanLintPlay play
		linkStaticTest objectsTest cleanTest test
		firstRule all lint clean clean-lint clean-all valgrind

.SUFFIXES:

/*
  CPP11SDL
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

#ifndef GfxCanvasValues_hpp
#define GfxCanvasValues_hpp

#include <string>

#include "GfxRootClass.hpp"

class GfxRadius final : public GfxRootClass
{
public:
	typedef uint16_t GfxValueType;

	GfxRadius();
	GfxRadius(GfxValueType value);
	GfxRadius(const GfxRadius& other);
	GfxRadius(GfxRadius&& other);

	GfxRadius& operator=(const GfxRadius& other);
	GfxRadius& operator=(GfxRadius&& other);

	bool operator==(const GfxRadius& other);
	bool operator>(const GfxRadius& other);
	bool operator<(const GfxRadius& other);

	GfxValueType getValue() const;
private:
	GfxValueType value_;
};

class GfxAngle final : public GfxRootClass
{
public:
	typedef int GfxValueType;

	GfxAngle();
	GfxAngle(GfxValueType value);
	GfxAngle(const GfxAngle& other);
	GfxAngle(GfxAngle&& other);

	GfxAngle& operator=(const GfxAngle& other);
	GfxAngle& operator=(GfxAngle&& other);

	bool operator==(const GfxAngle& other);
	bool operator>(const GfxAngle& other);
	bool operator<(const GfxAngle& other);

	GfxValueType getValue() const;
private:
	GfxValueType value_;
};

class GfxString final : public GfxRootClass
{
public:
	typedef std::string GfxValueType;

	GfxString();
	GfxString(GfxValueType value);
	GfxString(const GfxString& other);
	GfxString(GfxString&& other);

	GfxString& operator=(const GfxString& other);
	GfxString& operator=(GfxString&& other);

	bool operator==(const GfxString& other);
	bool operator>(const GfxString& other);
	bool operator<(const GfxString& other);

	GfxValueType getValue() const;
private:
	GfxValueType value_;
};

#endif // GfxCanvasValues_hpp
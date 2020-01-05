/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#ifndef GWindowObject_hpp
#define GWindowObject_hpp

#include <string>

#include "GComponent.hpp"
#include "GfxCanvas.hpp"
#include "GfxWindow.hpp"
#include "GfxSurface.hpp"

namespace gto
{

namespace gobj
{

class GForm : public GComponent
{
public:
    explicit GForm(const std::string& vname);
    explicit GForm(const std::string& vname, const std::string& title);

    GForm() = delete;
    GForm(const GForm&) = delete;
    GForm(GForm&&) = delete;

    GForm& operator=(const GForm&) = delete;
    GForm& operator=(GForm&&) = delete;

    virtual ~GForm();

    virtual void setTitle(const std::string& title);
    virtual void create(void);
    virtual void close(void);

    virtual void loadResources(void);
    virtual void run(void);

    virtual void draw(void);

    gfx::bgi::GfxCanvas * getCanvas(void);
protected:
    gfx::video::GfxWindow * window_;

    const int32_t kDefaultFormWidth = 1280;
    const int32_t kDefaultFormHeight = 800;
private:
    std::string formName_;
    std::string title_;
    gfx::bgi::GfxCanvas * canvas_;
    bool canvasInUse_;
};

}  // namespace gobj

}  // namespace gto

#endif /* GWindowObject_hpp */

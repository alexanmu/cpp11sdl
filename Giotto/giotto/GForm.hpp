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

#ifndef GWindowObject_hpp
#define GWindowObject_hpp

#include <memory>
#include <string>

#include "GObject.hpp"
#include "GfxCanvas.hpp"

#include "GfxWindow.hpp"

class GForm : public GObject
{
public:
    GForm();
    GForm(const std::string& title);

    void setFormTitle(const std::string& title);
    void createForm(void);
    void closeForm(void);

    void drawForm(void);

    std::shared_ptr<GfxCanvas> getFormCanvas(void);
private:
    std::shared_ptr<GfxWindow> window_;
    std::string title_;
    
    std::shared_ptr<GfxCanvas> canvas_;
    bool canvasInUse_;
};

#endif /* GWindowObject_hpp */

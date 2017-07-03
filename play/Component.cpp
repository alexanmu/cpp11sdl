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

#include "Component.hpp"

/***************************************************** Component *****************************************************/
#include <iostream>

#include "GComponent.hpp"

using gto::gobj::GComponent;

void _doComponent(void)
{
    GComponent* c = new GComponent(GVarName(c), nullptr);

    GComponent* c1 = new GComponent(GVarName(c1), c);
    GComponent* c2 = new GComponent(GVarName(c2), c);
    GComponent* c3 = new GComponent(GVarName(c3), c);
    GComponent* c4 = new GComponent(GVarName(c4), c);

    std::cout << "c1->hasParent()=" << c1->hasParent() << '\n';
    std::cout << "c2->hasParent()=" << c2->hasParent() << '\n';
    std::cout << "c3->hasParent()=" << c3->hasParent() << '\n';
    std::cout << "c4->hasParent()=" << c4->hasParent() << '\n';

    c->insertComponent(c1);
    c->insertComponent(c2);
    c->insertComponent(c3);
    c->insertComponent(c4);

    // c->removeComponent(c2);

    GComponent* c5 = c->findComponent(GVarName(c2));
    if (c5 != nullptr)
    {
        std::cout << "c5->getVName()=" << c5->getVName() << '\n';
    }
    else
    {
        std::cout << "Name not found" << '\n';
    }

    GComponent* t = new GComponent(GVarName(t), c);
    GComponent* ti[10];

    for (int i = 0; i < 10; i++)
    {
        ti[i] = new GComponent(GVarName(ti) + std::to_string(i), t);
        t->insertComponent(ti[i]);
    }

    c->insertComponent(t);

    delete c;

    std::cout << "Done!" << std::endl;
}

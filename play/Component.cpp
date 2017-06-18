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

    //c->removeComponent(c2);

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

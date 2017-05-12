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

#include <string>
#include <algorithm>

#include "GComponent.hpp"

namespace giotto
{

namespace objects
{

GComponent::GComponent(std::string const& name, GComponent* owner) : GObject(name)
{
    tag_ = 0;
    owner_ = owner;
    componentCount_ = 0;
    components_.reserve(4);
}

GComponent::~GComponent()
{
    if (componentCount_ > 0)
    {
        for (auto& c : components_)
        {
            delete c;
        }
    }
}

GComponent* GComponent::getParentComponent(void) const noexcept
{
    return owner_;
}

bool GComponent::hasParent(void) const noexcept
{
    return (owner_ != nullptr);
}

bool GComponent::equals(GObject * object)
{
    return (this == object);
}

void GComponent::insertComponent(GComponent * const component) throw(std::invalid_argument)
{
    if (components_.size() > 0)
    {
        if (findComponent(component->getName()) != nullptr)
        {
            throw std::invalid_argument("Component name is not unique");
        }
    }
    componentCount_ += 1;
    components_.push_back(component);
}

void GComponent::removeComponent(GComponent * const component) throw(std::invalid_argument)
{
    auto pos = std::find(components_.begin(), components_.end(), component);;
    if (pos != components_.end())
    {
        components_.erase(pos);
        componentCount_ -= 1;
    }
    else
    {
        throw std::invalid_argument("Component not found in container");
    }
}

GComponent* GComponent::findComponent(const std::string& name)
{
    auto pos = std::find_if(components_.begin(), components_.end(),
            [=](GComponent * const c)
                {
                    return (c->getName() == name);
                });
    if (pos != components_.end())
    {
        return *pos;
    }
    return nullptr;
}

uint64_t GComponent::getTag(void) const noexcept
{
    return tag_;
}

void GComponent::setTag(uint64_t tag) noexcept
{
    tag_ = tag;
}

}  // namespace objects

}  // namespace giotto

/* EOF */

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

#ifndef GComponent_hpp
#define GComponent_hpp

#include <stdexcept>
#include <cstdint>
#include <vector>
#include <string>

#include "GObject.hpp"

namespace giotto
{

namespace objects
{

#define GVarName(x) (#x)

class GComponent : public GObject
{
public:
    GComponent() = delete;

    GComponent(GComponent const& other) = delete;
    GComponent(GComponent&& other) = delete;

    GComponent& operator=(GComponent const& other) = delete;
    GComponent& operator=(GComponent&& other) = delete;

    explicit GComponent(std::string const& vname, GComponent* owner);
    virtual ~GComponent();

    GComponent* getParentComponent(void) const noexcept;
    bool hasParent(void) const noexcept;

    bool equals(GObject * object);

    void insertComponent(GComponent * const component) throw(std::runtime_error);
    void removeComponent(GComponent * const component) throw(std::runtime_error);
    GComponent* findComponent(const std::string& name);

    uint64_t getTag(void) const noexcept;
    void setTag(uint64_t tag) noexcept;

    std::string const& getName(void) const;
protected:
    std::string vname_;
    uint64_t tag_;
    GComponent* owner_;

    uint32_t componentCount_;
    std::vector<GComponent *> components_;
};

}  // namespace objects

}  // namespace giotto

#endif /* GComponent_hpp */

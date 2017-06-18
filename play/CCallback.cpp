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

#include "CCallback.hpp"

/***************************************************** CCallback *****************************************************/
#include <iostream>

// http://stackoverflow.com/question/9568150/what-is-a-c-delegate
template <class T>
class CCallback
{
public:
    typedef void (T::*fn)(int anArg);

    CCallback(T& trg, fn op) : m_rTarget(trg), m_Operation(op)
    {
    }

    void Execute(int in)
    {
        (m_rTarget.*m_Operation)(in);
    }

    void operator()(int in)
    {
        (m_rTarget.*m_Operation)(in);
    }
private:
    CCallback() = delete;
    CCallback(CCallback const&) = delete;

    T& m_rTarget;
    fn m_Operation;
};

class A
{
public:
    virtual void Fn(int i)
    {
        std::cout << "i=" << i << std::endl;
    }
};

void _doCallback(void)
{
    A a;
    CCallback<A> cbk(a, &A::Fn);
    cbk.Execute(3);
    cbk(3);
}
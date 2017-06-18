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
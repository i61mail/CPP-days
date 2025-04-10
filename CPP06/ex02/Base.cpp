#include "Base.hpp"

Base::~Base()
{
    // std::cout << "Base destructor called" << std::endl;
}

A::A()
{
    // std::cout << "A constructor called" << std::endl;
}

A::~A()
{
    // std::cout << "A destructor called" << std::endl;
}

B::B()
{
    // std::cout << "B constructor called" << std::endl;
}

B::~B()
{
    // std::cout << "B destructor called" << std::endl;
}

C::C()
{
    // std::cout << "C constructor called" << std::endl;
}

C::~C()
{
    // std::cout << "C destructor called" << std::endl;
}

Base *generate(void)
{
    srand(time(0));
    int random = rand() % 100;
    if (random <= 33)
        return new A();
    else if (random >= 34 && random <= 66)
        return new B();
    else
        return new C();
}

Base *identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
    return p;
}

Base *identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type A" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not type A" << std::endl;
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type B" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type C" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    return &p;
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}
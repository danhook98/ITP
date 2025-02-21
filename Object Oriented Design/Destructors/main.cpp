#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() override { std::cout << "Derived Destructor" << std::endl; }
};

class A
{
public:
    A() { std::cout << "A Constructor" << std::endl; }
    ~A() { std::cout << "A Destructor" << std::endl; }
};

class B
{
public:
    B() { std::cout << "B Constructor" << std::endl; }
    ~B() { std::cout << "B Destructor" << std::endl; }
};

class C : public A, public B
{
public:
    C() { std::cout << "C Constructor" << std::endl; }
    ~C() { std::cout << "C Destructor" << std::endl; }
};

int main()
{
    //Derived d;

    C c;

    return 0;
}
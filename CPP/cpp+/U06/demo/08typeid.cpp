#include <typeinfo>
#include <iostream>

class A
{
};

int main()
{
    A a{};

    auto &t1 = typeid(a);
    if (typeid(A) == t1)
    {
        std::cout << t1.name() << std::endl;
    }
    return 0;
}
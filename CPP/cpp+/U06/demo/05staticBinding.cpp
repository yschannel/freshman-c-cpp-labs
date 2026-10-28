#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void show() { cout << "Base show" << endl; } // 加上 virtual
};

class Derived : public Base
{
public:
    void show() override { cout << "Derived show" << endl; }
};

int main()
{
    Base *ptr = new Derived();
    ptr->show();
    // 结果：输出 "Derived show"
    // 原因：动态联编。程序运行时发现 ptr 指向的实际对象是 Derived，
    // 于是通过虚函数表（vtable）找到了 Derived::show() 并调用。
    return 0;
}
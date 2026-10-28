#include <iostream>

// 1. 使用 final 关键字声明一个不能被继承的类
class Base final{
public:
    Base() {
        std::cout << "Base 类的构造函数被调用" << std::endl;
    }

    void sayHello() const {
        std::cout << "你好，我是一个 final 类！" << std::endl;
    }
};

// 2. 【错误示范】尝试继承一个 final 类
// 下面的代码会导致编译错误，就像你看到的那样
// class Derived : public Base {}; 

int main() {
    // 3. 【正确用法】final 类可以正常创建对象
    Base myObject;
    myObject.sayHello();

    return 0;
}
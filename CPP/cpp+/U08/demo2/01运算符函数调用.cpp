#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include <windows.h> // 引入 Windows API

// 打印辅助函数
void print(const std::string &s)
{
    std::cout << ">>> " << s << std::endl;
}

class Demo
{
private:
    int value;

public:
    Demo(int v = 0) : value(v)
    {
    }

    bool operator!() const
    {
        print("!a (Member): 逻辑非运算");
        return value == 0;
    }

    Demo operator+(const Demo &other) const
    {
        print("a+b (Member): 加法运算");
        return Demo(this->value + other.value);
    }

    Demo &operator=(const Demo &other)
    {
        print("a=b (Member): 赋值运算");
        if (this != &other)
        {
            this->value = other.value;
        }
        return *this;
    }

    void operator()(const std::string &msg)
    {
        print("a(b) (Member): 函数调用运算 -> " + msg);
    }

    int operator[](int index) const
    {
        print("a[b] (Member): 下标运算 (模拟返回value * index)");
        return value * index;
    }

    Demo *operator->()
    {
        print("a-> (Member): 成员访问运算");
        return this;
    }

    // int是哑元，用来区分前置++
    Demo operator++(int)
    {
        print("++a (Member): 后置自增");
        Demo temp = *this;
        this->value++;
        return temp; // 返回变之前的值
    }
    Demo operator++()
    {
        print("++a (Member): 前置自增");
        this->value++;
        return *this;
    }

    int getValue() const { return value; }
};

// 二元运算符
Demo operator+(const Demo &lhs, const Demo &rhs)
{
    print("a+b (Non-Member): 全局加法运算");
    return Demo(lhs.getValue() + rhs.getValue());
}

// 一元前缀
void operator*(const Demo &obj)
{
    print("*a (Non-Member): 全局解引用运算 (仅演示调用)");
}

int main()
{
    SetConsoleOutputCP(65001);

    print("=== 1. 一元前缀 (!) ===");
    Demo d1(10);
    bool b1 = !d1; // 调用 d1.operator!()
    std::cout << "Result: " << b1 << std::endl;

    // 全局一元示例 (假设我们重载了 *)
    *d1; // 调用 operator*(d1)

    print("\n=== 2. 二元运算符 (+) ===");
    Demo d2(20);
    Demo d3 = d1 + d2;
    // 如果成员和全局都存在，且匹配度一样，通常优先成员，或者报错二义性
    // 这里演示调用成员版本（因为参数类型完全匹配）

    print("\n=== 3. 赋值运算符 (=) ===");
    Demo d4;
    d4 = d3; // 调用 d4.operator=(d3)

    print("\n=== 4. 函数调用运算符 () ===");
    d1("Hello"); // 调用 d1.operator()("Hello")

    print("\n=== 5. 下标运算符 [] ===");
    int val = d1[5]; // 调用 d1.operator[](5)
    std::cout << "Index Value: " << val << std::endl;

    print("\n=== 6. 成员访问运算符 (->) ===");
    // d1 是对象，不是指针，但因为我们重载了 ->，它可以调用
    // 注意：这在实际开发中很少见，通常是智能指针重载这个
    int v = d1->getValue(); // 调用 d1.operator->()->getValue()
    std::cout << "Value via ->: " << v << std::endl;

    print("\n=== 7. 一元后缀运算符 (++) ===");
    d1++; // 调用 d1.operator++(0)
    ++d1; // 调用 d1.operator++()

    return 0;
}

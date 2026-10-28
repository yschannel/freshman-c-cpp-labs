#include <iostream>
#include <cmath>

class Vec2D
{
private:
    double x;
    double y;

public:
    Vec2D(double x = 0, double y = 0) : x(x), y(y) {}

    double magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    // 直接写函数名
    /*operator double() const
    {
        return magnitude();
    }
    */

    // 更安全的版本（防止意外的隐式转换）
    // 此时必须进行显示转换 d = v1 报错
    explicit operator double() const
    {
        return magnitude();
    }
};

int main()
{
    Vec2D v1(3, 4);

    // 1.隐式转换
    // double d = v1 + 5.1;
    double d = 5.1 + static_cast<double>(v1);
    std::cout << d << std::endl;

    // 2.显示转换
    double e = static_cast<double>(v1);
    std::cout << e << std::endl;

    // 3.直接赋值
    // double len = v1;
    double len = static_cast<double>(v1);
    std::cout << len << std::endl;

    return 0;
}
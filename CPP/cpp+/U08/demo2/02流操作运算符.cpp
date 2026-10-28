#include <iostream>
#include <istream>
#include <ostream>

class Vec2D
{
private:
    double x;
    double y;

public:
    Vec2D(double x = 0, double y = 0) : x(x), y(y) {}

    friend std::ostream &operator<<(std::ostream &os, const Vec2D &v);

    friend std::istream &operator>>(std::istream &is, Vec2D &v);
};
// 返回引用支持链式调用
std::ostream &operator<<(std::ostream &os, const Vec2D &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vec2D &v) // 这里没有const
{
    std::cout << "请输入 x 和 y 的值（用空格隔开）：";
    is >> v.x >> v.y;
    return is;
}

int main()
{
    Vec2D v1;
    std::cin >> v1;
    std::cout << "你输入的向量是：" << v1 << std::endl;
    return 0;
}
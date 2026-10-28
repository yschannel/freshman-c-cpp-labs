#include <iostream>

// TODO 1：说明为什么函数使用 T 之前，必须先在这一行声明 T。
template <typename T>
T maxValue(const T &left, const T &right)
{
    // TODO 2：把这个临时返回改成“返回较大值”的表达式。
    // 最终表达式只应要求 T 支持 operator>。
    return (right > left) ? right : left;
    //(void)right; // 让起始文件在补全前也保持无警告。
    // return left;
}
int main()
{
    std::cout << "int test    : " << maxValue(10, 4)
              << "  // 补全后期望 10\n";
    std::cout << "double test : " << maxValue(3.5, 8.0)
              << "  // 补全后期望 8\n";

    return 0;
}

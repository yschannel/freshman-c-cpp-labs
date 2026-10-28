#include <iostream>

// T 是类型参数。调用传入 int、double、char 或其他可比较类型时，
// 编译器会生成对应的具体 maxValue<T> 实例。
// 这个最小模板的约束：T 必须支持 operator>。
template <typename T>
T maxValue(const T& left, const T& right) {
    return (left > right) ? left : right;
}

int main() {
    std::cout << "int    : maxValue(7, 3) = " << maxValue(7, 3) << '\n';
    std::cout << "double : maxValue(2.5, 9.25) = "
              << maxValue(2.5, 9.25) << '\n';
    std::cout << "char   : maxValue('a', 'z') = "
              << maxValue('a', 'z') << '\n';

    return 0;
}

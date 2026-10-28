#include <iostream>

// 仅作为审核材料：这里故意不是推荐答案。
// 此处返回 T& 有风险，因为乘积被保存在局部对象中。

template <typename T>
T &multiply(T op1, T op2)
{
    T result = op1 * op2;
    return result;
}
/*
template <typename T>
T multiply(T op1, T op2)
{
    T result = op1 * op2;
    return result;
}
*/

// 学生修正说明区：
// 1. 返回类型：
// 2. 被返回对象的生命周期：
// 3. T 需要支持的操作：
//
// 可评估的安全签名候选：
// template <typename T>
// T multiply(T op1, T op2);

int main()
{
    std::cout << "D4 review target: T& multiply(T op1, T op2)\n";
    std::cout << "Example operands: 6 and 7, 2.5 and 4.0\n";
    std::cout << multiply(6, 7) << multiply(2.5, 4.0) << '\n';
    std::cout << "Question: after return, which object would T& refer to?\n";
    std::cout << "Evidence focus: return type, lifetime, operator* support.\n";

    return 0;
}

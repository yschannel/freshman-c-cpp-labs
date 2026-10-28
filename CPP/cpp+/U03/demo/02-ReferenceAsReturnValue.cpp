// Language: C++
 
#include <iostream>
 
// 安全示例：返回两个外部变量中较大者的“引用”。
// 设计意图：避免不必要拷贝，并允许调用端直接修改被选中的原变量。
int& max_ref(int& a, int& b) { return (a >= b) ? a : b; }
 
// 危险示例：返回局部变量引用（生命周期已结束）。
// 编译器通常会给警告：returning reference to local variable。
int& bad_ref() {
    int local = 42;
    return local;  // 未定义行为：local 离开函数即销毁。
}
 
int main() {
    int x = 7;
    int y = 12;
    
    std::cout << "修改前: x=" << x << ", y=" << y << "\n";
    max_ref(x, y) = 100;
    std::cout << "max_ref(x, y)=100 后: x=" << x << ", y=" << y << "\n";
    std::cout << "结论：被选中的较大值所在变量被直接改写。\n";
    
    // 易错点：不要用“这次跑起来没崩”证明 bad_ref 安全。
    // 这里不依赖其运行结果，只用于课堂说明和编译警告演示。
    // int& r = bad_ref();
    // std::cout << r << "\n";  // 不要这样做（未定义行为）。
    
    // 如何验证：
    // 1) 打开告警编译：clang++ -std=c++17 -Wall -Wextra ref_return_demo.cpp
    // 2) 观察 max_ref 的赋值是否改到 x 或 y；
    // 3) 关注 bad_ref 的编译器提示，而非运行侥幸结果。
    return 0;
}
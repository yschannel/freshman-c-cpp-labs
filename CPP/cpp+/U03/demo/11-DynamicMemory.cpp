// Language: C++
 
#include <iostream>
 
int main() {
    const int n = 5;
    
    // 1) 申请：new[] 为整型数组分配堆内存，责任转移给当前代码。
    int* p = new int[n];
    
    // 2) 使用：先赋值，再输出，确保“已初始化后再读”。
    for (int i = 0; i < n; ++i) {
        p[i] = (i + 1) * 10;
    }
    std::cout << "数组内容: ";
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i + 1 == n ? '\n' : ' ');
    }
    
    // 3) 释放：数组必须用 delete[] 配对释放。
    delete[] p;
    p = nullptr;  // 4) 释放后置空，降低悬空指针误用风险。
    
    // 错误示例（仅注释，不执行）：
    // delete p;   // 错配释放：new[] 必须对应 delete[]。
    // std::cout << p[0] << '\n';  // 释放后访问：未定义行为。
    
    // 如何验证：
    // 1) 观察释放前输出正常；
    // 2) 释放后不再解引用 p；
    // 3) 课堂口头判断：哪些写法会泄漏、哪些会悬空。
    return 0;
}

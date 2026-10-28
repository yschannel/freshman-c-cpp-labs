// Language: C++
 
#include <iostream>
 
int main() {
    // 对比 1：传统写法允许缩窄，3.14 会被截断成 3。
    int a = 3.14;
    std::cout << "int a = 3.14; -> a = " << a << "\n";
    
    // 对比 2：列表初始化会拒绝缩窄（编译期拦截）。
    // int b{3.14};  // 编译错误：narrowing conversion。
    
    // 数组列表初始化：元素和长度一目了然。
    int arr[3]{1, 2, 3};
    std::cout << "arr = ";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << (i == 2 ? '\n' : ' ');
    }
    
    // 字符数组初始化：会自动包含结尾 '\\0'。
    char s[] = "abc";
    std::cout << "s = \"" << s << "\", sizeof(s) = " << sizeof(s) << "\n";
    
    // 易错点：把“能编译”误当“安全”；a 的截断在运行前没有被阻止。
    // 如何验证：
    // 1) 保持 b 行注释时，程序可运行并看到 a 被截断；
    // 2) 取消 b 行注释，观察编译器在运行前阻止缩窄；
    // 3) 观察 sizeof(s) 是否为 4（含 '\\0'）。
    return 0;
}

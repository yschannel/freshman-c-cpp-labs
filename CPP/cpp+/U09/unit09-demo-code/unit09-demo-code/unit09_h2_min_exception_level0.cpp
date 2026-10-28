#include <iostream>

void f() {
    // 第一步 TODO: 在下一行写 throw 100;
    // 预测表列：抛出位置与抛出类型。
}

int main() {
    try {
        // 第二步 TODO: 在下一行写 f();
        std::cout << "This line will not execute.\n";
    } catch (int e) {
        // 第三步 TODO: 输出 "catch int: " 和 e。
        // 预测表列：命中 catch(int)。
    }

    // 预测表列：catch 处理后是否继续执行。
    std::cout << "Execution continues.\n";
    return 0;
}

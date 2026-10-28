#include <iostream>

void f() {
    // TODO 1 (H1 复习): throw 100;
    // 预测表：写出抛出类型 int。
}

int main() {
    try {
        // TODO 2 (H1 复习): f();
    } catch (int e) {
        // TODO 3 (H2 开始前完成): 输出 e。
        // 预测表：写出命中 catch(int)。
    }

    std::cout << "Execution continues.\n";
    return 0;
}

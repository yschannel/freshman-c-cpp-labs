#include <iostream>

void f() {
    // TODO 1: throw 100;
    // 预测表：失败发现位置=f，抛出类型=int。
}

int main() {
    try {
        // TODO 2: f();
        // 预测表：补全后，throw 使下面语句不执行。
        std::cout << "This line will not execute.\n";
    } catch (int e) {
        // TODO 3: std::cout << "catch int: " << e << '\n';
        // 预测表：throw int 的第一个匹配处理程序是 catch(int)。
    }

    // 预测表：异常已经被处理，程序从 catch 后继续。
    std::cout << "Execution continues.\n";
    return 0;
}

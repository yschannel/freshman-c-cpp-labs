#include <iostream>

void f(int mode) {
    if (mode == 0) {
        std::cout << "normal path\n";
    } else {
        // TODO: throw mode;
        // 预测表：mode=1 时抛出 int。
    }
}

int main() {
    const int modes[] = {0, 1};
    for (int mode : modes) {
        try {
            // TODO: 调用 f(mode)。
            std::cout << "after f\n";
        } catch (int e) {
            // TODO: 输出捕获到的 e。
            // 预测表：仅 mode=1 时第一个匹配 catch(int)。
        }
    }
    return 0;
}

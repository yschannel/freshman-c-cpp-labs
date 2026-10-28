#include <fstream>
#include <iostream>
#include <string>

int main() {
    {
        std::ifstream missing{"missing.json"};
        // fail() 对应失败判断：打开之后立刻检查。
        if (missing.fail()) {
            std::cout << "open missing.json failed\n";
        }
    }

    std::ifstream in{"x.json"};
    if (in.fail()) {
        std::cout << "open x.json failed\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::cout << "line: " << line << '\n';
    }

    // eof() 是读取后的末尾状态，不作为首选循环入口。
    std::cout << "after reading, eof = " << std::boolalpha << in.eof() << '\n';
    return 0;
}

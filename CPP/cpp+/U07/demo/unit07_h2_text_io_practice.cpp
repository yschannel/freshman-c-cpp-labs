#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    namespace fs = std::filesystem;

    fs::path input{"x.json"};
    std::ifstream in{input};
    // 这里是状态检测：先判断输入文件是否真的打开。
    if (in.fail()) {
        std::cerr << "cannot open " << input << '\n';
        return 1;
    }

    auto bytes = fs::exists(input) ? fs::file_size(input) : 0;

    std::ofstream out{"out.txt"};
    if (out.fail()) {
        std::cerr << "cannot open out.txt\n";
        return 1;
    }

    // 这里是格式化输出：写出人可读文本结果。
    out << "bytes = " << bytes << '\n';
    out << std::fixed << std::setprecision(3)
        << "MiB   = " << bytes / (1024.0 * 1024.0) << '\n';

    // 这里是文本读取粒度选择：本任务先保留整行。
    std::string line;
    while (std::getline(in, line)) {
        std::cout << "line: " << line << '\n';
    }

    return 0;
}

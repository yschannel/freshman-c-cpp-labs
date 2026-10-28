#include <filesystem>
#include <iostream>

int main() {
    namespace fs = std::filesystem;

    fs::path target{"x.json"};

    // 这是文件定位与属性检查，不是正式文本读取。
    std::cout << "current_path = " << fs::current_path() << '\n';
    std::cout << "target       = " << fs::absolute(target) << '\n';

    if (!fs::exists(target)) {
        std::cout << "file not found: " << target << '\n';
        return 1;
    }

    if (!fs::is_regular_file(target)) {
        std::cout << "not a regular file: " << target << '\n';
        return 1;
    }

    std::cout << "file_size   = " << fs::file_size(target) << " bytes\n";
    return 0;
}

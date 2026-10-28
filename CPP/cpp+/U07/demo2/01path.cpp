#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{

    std::cout << "Current path:" << fs::current_path() << std::endl;

    fs::path rel_path = "../test.txt"; // 上一级目录

    fs::path abs_path = fs::absolute(rel_path); // 转绝对
    std::cout << "tramsformed: " << abs_path << std::endl;

    fs::path base_dir = fs::current_path();
    fs::path file_name = "data.txt";
    fs::path full_path = base_dir / file_name;               // 拼接路径
    std::cout << "matched path: " << full_path << std::endl; // 系统 / 和 \\ 是兼容的

    std::cout << "---check abs path---\n";
    std::cout << "has filename? " << abs_path.has_filename() << std::endl;
    std::cout << "extension? " << abs_path.extension() << std::endl;
    std::cout << "is absolute? " << abs_path.is_absolute() << std::endl;
    std::cout << "has parent path? " << abs_path.has_parent_path() << std::endl;

    return 0;
}
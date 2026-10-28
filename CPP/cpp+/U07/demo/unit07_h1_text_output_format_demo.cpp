#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
    namespace fs = std::filesystem;

    fs::path input{"x.json"};
    fs::path output{"out.txt"};

    std::cout << fs::current_path() << '\n';

    if (!fs::exists(input))
    {
        std::cerr << "missing input: " << input << '\n';
        return 1;
    }

    const auto bytes = fs::file_size(input);
    const double gib = static_cast<double>(bytes) / (1024.0 * 1024.0 * 1024.0);

    std::ofstream out{output};
    if (out.fail())
    {
        std::cerr << "cannot open output\n";
        return 1;
    }

    // 格式化输出改变的是显示形式，而不是数值本身。
    out << "file: " << input << '\n';
    out << "bytes: " << bytes << '\n';
    out << std::fixed << std::setprecision(6);
    out << "GiB: " << std::setw(14) << std::setfill(' ') << gib << '\n';

    std::cout << "wrote " << output << '\n';
    return 0;
}
